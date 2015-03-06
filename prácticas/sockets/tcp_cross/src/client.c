/*** client.c ***/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Puerto a conectar
#define PORT 3490
// ńumero máximo de bytes a transmitir 
#define MAXDATASIZE 16384
char * host_name = "127.0.0.1"; //Local host

int main(int argc, char *argv[])
{
	char buf[MAXDATASIZE];
   	char message[256];
	int sock_descriptor, numbytes;
	struct hostent *server_hostname;
    	struct sockaddr_in server;

	char *str = "Cadena del Cliente";
	// Incluir argumente: hostname o ip
   	 if(argc != 2)
    	{
       		 fprintf(stderr, "Usar: %s hostname\n", argv[0]);
	       	 exit(1);
   	 }
         // Obtener información del host
   	if((server_hostname = gethostbyname(argv[1])) == NULL)
    	{
       		perror("error - gethostbyname()");
	        exit(1);
	 }
	else	
       		printf("El host remoto es: %s\n", argv[1]);
     
	
	if((sock_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    	{
       		perror("error - socket()");
       		exit(1);
   	}
	else
	        printf("Client-The socket() sock_descriptor is OK...\n");

    	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
    	server.sin_addr = *((struct in_addr *)(server_hostname->h_addr_list[0]));
	memset(&(server.sin_zero), '\0', 8);

   	printf("Conectando a servidor %s:[%d]\n", argv[1], PORT);
	if(connect(sock_descriptor, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
   	{
       		perror("error - connect()");
		exit(1);
	}
	else
		printf("Client-The connect() is OK...\n");

	printf("Enviando mensaje al servidor %s...\n", str);

	if (send(sock_descriptor, str, strlen(str), 0) == -1)
	{
		perror("error - Client-send()");
		exit(1);
	}
	printf("Mensaje enviado...");

	if((numbytes = recv(sock_descriptor, buf, MAXDATASIZE-1, 0)) == -1)
	{
	        perror("error - recv()");
	        exit(1);
	}
	else
	        printf("Información recibida OK...\n");

	buf[numbytes] = '\0';
	printf("Información recibida del servidor: %s\n", buf);

	close(sock_descriptor);
	return 0;
}

