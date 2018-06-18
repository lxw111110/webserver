/*************************************************************************
	> File Name: ../src/server/server.c
	> Author:L
	> Mail:731278512@qq.com
	> Created Time: 2018年06月18日 星期一 12时05分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<pthread.h>
int main(int argc,char *argv[])
{
	int clientfd=0,serverfd=0;
	int remoteaddr_len=0;
	struct sockaddr_in remoteaddr;
	struct sockaddr_in localaddr;
	char recvbuf[1500]={0};
	int recvlen=0;

	printf("%d\r\n",argc);
	localaddr.sin_family=AF_INET;
	localaddr.sin_addr.s_addr=INADDR_ANY;
	localaddr.sin_port=htons(atoi(argv[1]));	
	printf("0X%X\r\n",htons(atoi(argv[1])));
	serverfd = socket(AF_INET,SOCK_STREAM,0);
	if(serverfd<0)
	{
		printf("socket error\r\n");
		return -1;
	}
	if(bind(serverfd,(struct sockaddr *)&localaddr,sizeof(struct sockaddr))<0)
	{
		printf("bind error\r\n");
		return -1;
	}
	if(listen(serverfd,1)<0)
	{
		printf("listen error\r\n");
		return -1;
	}
	while(1)
	{
		clientfd=accept(serverfd,(struct sockaddr *)&remoteaddr,&remoteaddr_len);
		if(clientfd<=0)
		{
			printf("accept error\r\n");
			return 0;
		}
		while(1)
		{
			recvlen=recv(clientfd,recvbuf,sizeof(recvbuf),0);
			if(recvlen>0)
			{
				send(clientfd,recvbuf,recvlen,0);
			}
			else
			{
				close(clientfd);
				break;
			}
		}
	}
	return 0;

}
