#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>

int main()
{

	char str[100];
	int listen_fd,comm_fd;
	
	struct sockaddr_in servaddr;

	listen_fd = socket(AF_INET,SOCK_STREAM, 0);

	bzero( &servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(8888);
	
	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	listen(listen_fd, 10);

	comm_fd = accept(listen_fd, (struct sockaddr *) NULL,NULL);
	
		bzero(str, 100);

		read(comm_fd,str,100);
			int sockfd,n;

	char str1[100] ="enemy";
	char str2[100] ="friend";	

	if(strcmp(str,str1)==0)
	{
	
	sockfd=socket(AF_INET,SOCK_STREAM, 0);
	bzero(&servaddr,sizeof servaddr);

	servaddr.sin_family =AF_INET;
	servaddr.sin_port=htons(22333);

	inet_pton(AF_INET,"192.168.223.128", &(servaddr.sin_addr));
	
		connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	write(sockfd,str,strlen(str)+1);
	}

	else if(strcmp(str,str2)==0)
	{
	
	sockfd=socket(AF_INET,SOCK_STREAM, 0);
	bzero(&servaddr,sizeof servaddr);

	servaddr.sin_family= AF_INET;
	servaddr.sin_port=htons(22222);

	inet_pton(AF_INET,"192.168.223.131", &(servaddr.sin_addr));

		connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	write(sockfd,str,strlen(str)+1);
	}
}
