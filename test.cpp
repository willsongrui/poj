#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <memory.h>
using namespace std;
int main(int argc,char* argv[])
{
	int connectionNum=500;
	if(argc==2)
	{
		connectionNum=atoi(argv[1]);

	}
	sockaddr_in server;
	bzero(&server,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(14800);
	server.sin_addr.s_addr = inet_addr("117.27.156.87");
	int sockfd[connectionNum+1];
	int error=0;
	for(int i=1;i<=connectionNum;i++)
	{
		cout<<"Connecting "<<i<<endl;
		sockfd[i] = socket(AF_INET,SOCK_STREAM,0);
		int flag = fcntl(sockfd[i], F_GETFL, 0);
		flag = flag|O_NONBLOCK;
		fcntl(sockfd[i],F_SETFL,flag);
		int result = connect(sockfd[i],(sockaddr*)&server,sizeof(server));
		if(result<0)
		{
			//error++;
			//cout<<i<<" connection failed"<<endl;
		}
		
	}
	int epoll_fd = epoll_create(9999);
	epoll_event event,events[9999];

	for(int i=1;i<=connectionNum;i++)
	{
		event.data.fd = sockfd[i];
		event.events = EPOLLIN|EPOLLOUT;
		epoll_ctl(epoll_fd,EPOLL_CTL_ADD,sockfd[i],&event);
	}
	int success=0;
	char buf[3000];
	int last_success=0;
	bool con[9999];
	memset(con,0,sizeof(con));
	while(true)
	{
		int active_n=epoll_wait(epoll_fd,events,9999,120);
		//cout<<"Active_n: "<<active_n<<endl;
		for(int i=0;i<active_n;i++)
		{
			epoll_event ev = events[i];
			if(ev.events & EPOLLERR)
			{	socklen_t errlen=sizeof(error);
				int error=0;
				getsockopt(ev.data.fd,SOL_SOCKET,SO_ERROR,(void*)&error,&errlen);
				cout<<strerror(error)<<endl;
				cout<<ev.data.fd<<" error"<<endl;
				error++;
			}
			if(ev.events & EPOLLIN)
			{
				int len = recv(ev.data.fd,buf,sizeof(buf),0);
				//cout<<"IN"<<endl;
				if(len==0)
				{
					epoll_ctl(epoll_fd,EPOLL_CTL_DEL,ev.data.fd,NULL);
					close(ev.data.fd);
				}

			}
			if(ev.events & EPOLLOUT)
			{
				//cout<<ev.data.fd<<"Connected"<<endl;
				if(con[ev.data.fd]==false)
				{	
					success++;
					con[ev.data.fd]=true;
				}
				

			}
		}
		
		if(last_success!=success)
		{
			cout<<"SUCCESS: "<<success<<endl;
			for(int i=1;i<9999;i++)
			{
				if(con[i]==true)
					cout<<i<<" ";
			}
			cout<<endl;
			last_success=success;
		}
		
	}
	cout<<"TOTAL: "<<connectionNum<<endl;
	cout<<"SUCCESS: "<<success<<endl;
	cout<<"ERROR: "<<error<<endl;
	return 0;
}