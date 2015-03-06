#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h> 
#include <unistd.h>
//Puerto del servidor 
#define PORT 3490
//Conexiones pendientes
#define QC 10


 int main(int argc, char *argv[ ])
{
	struct sockaddr_in local;
	struct sockaddr_in origen;
	int sock_descriptor;
	int temp_sock_descriptor;
	int address_size;
	char buf[16384];
	int len;
		
	sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_descriptor == -1)
	{
		perror("Server - Error al crear socket");
		exit(1);
	}

	memset(&(local.sin_zero), '\0', 8);
 	local.sin_family = AF_INET;
	local.sin_addr.s_addr = INADDR_ANY;
	local.sin_port = htons(PORT); //Convertir entero a network bye

	if(bind(sock_descriptor, (struct sockaddr *)&local, sizeof(struct sockaddr)) == -1)
	{
		perror("Server-bind() error");
		exit(1);
	}
 
	if(listen(sock_descriptor, QC) == -1)
	{
		perror("Server-listen() error");
		exit(1);
	}	
	printf("Server-Escuchando conexiones...\n");

	//Aceptar conexiones...
	while(1)
	{
		address_size = sizeof(struct sockaddr_in);
		if((temp_sock_descriptor = accept(sock_descriptor, (struct sockaddr *)&origen, &address_size)) == -1)
		{
			perror("Server: accept() error");
			continue;
		}

		printf("Server Nuevo socket...\n");
		printf("Server - Conexión recibida de [%s]\n", inet_ntoa(origen.sin_addr));

		if (recv(temp_sock_descriptor, buf, 16384, 0) == -1)
		{
			perror("Server-recv()");
			exit(1);
		}
		
		printf("Recibiendo información del cliente: [%s] \n", buf);
		
		//Convertir a mayúsculas
		len = strlen(buf);
		int i = 0;
		for (i = 0; i < len; i++)
			buf[i] = toupper(buf[i]);

		printf("Enviando información al cliente [%s] \n", buf);
		if (send(temp_sock_descriptor, buf, len, 0) == -1){
			perror("Server-send()");
			exit(1);

		}
		close(temp_sock_descriptor);
	}	
	return 0;
}
