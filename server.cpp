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
#include <stdio.h>
using namespace std;
void setnonblocking(int fd)
{
	int flag = fcntl(fd,F_GETFL,0);
    flag = flag|O_NONBLOCK;
    fcntl(fd,F_SETFL,flag);

}

int main()
{
	int  listenfd, connfd;
    int  serverPort = 16888;
    int listenq = 1024;
    pid_t   childpid;
    char buf[3000];
    socklen_t socklen;
    
    struct sockaddr_in cliaddr,servaddr;
    socklen = sizeof(cliaddr);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(serverPort);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket error");
        return -1;
    }
    int flag = fcntl(listenfd,F_GETFL,0);
    flag = flag|O_NONBLOCK;
    fcntl(listenfd,F_SETFL,flag);
    if (bind(listenfd, (struct sockaddr *) &servaddr, socklen) < 0) {
        perror("bind error");
        return -1;
    }
    listen(listenfd,listenq);
	int epoll_fd = epoll_create(9999);
	epoll_event event,events[9999];
	event.events = EPOLLIN;
	event.data.fd=listenfd;
	epoll_ctl(epoll_fd,EPOLL_CTL_ADD,listenfd,&event);
	int success=0;
	while(true)
	{
		int num=epoll_wait(epoll_fd,events,9999,-1);
		for(int i=0;i<num;i++)
		{
			if(events[i].data.fd==listenfd)
			{
				int conn = accept(listenfd,(struct sockaddr *)&cliaddr,&socklen);
				setnonblocking(conn);
				epoll_event ev;
				ev.events = EPOLLIN;
				ev.data.fd = conn;
				epoll_ctl(epoll_fd,EPOLL_CTL_ADD,conn,&ev);
				cout<<"SUCCESS: "<<success++<<endl;
			}
		}
	}
	return 0;

}