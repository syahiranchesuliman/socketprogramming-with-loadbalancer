#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc , char *argv[]_
{
	int sock;
	struct sockaddr_in server;
	char message[1000], server_reply[2000];

	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
	
		printf("Could not create socket");
	}
	puts("Socket created");

	server.sin_addr.s_addr = inet_addr("192.168.79.130");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	if(connect(sock, (struct sockaddr *)&server, sizeof(server)) <0)
	{
		perror("connect failed.Error");
		return 1;
	}
	puts("Connected\n");
	while(1)
	{
		printf("Enter message :");
		scanf("%s" , message);
	
		if( send(sock , message, strlen(message) ,0) <0))
		{
			puts("Send failed");
			return 1;
		}
		if( recv(sock , server_reply, 2000 , 0) <0)
		{
			puts("recv failed");
			break;
		}
		puts("Server reply :");
		puts(server_reply);
	}
	close(sock);
	return 0;
}