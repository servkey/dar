#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 6789

int main (int argc, char *argv[]){
	int sin_len;
	char message[256];
	int socket_descriptor;
	struct sockaddr_in sin;
	printf("Esperando datos de remitente\n");
	//Iniciar estructura de direcciones de socket para protocolos 
	memset(&(sin.sin_zero), '\0', 8);
 	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(PORT);
	sin_len = sizeof(sin);
	
	//Crea un socket UDP y unirlo al puerto
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	bind(socket_descriptor, (struct sockaddr *)&sin, sizeof(sin));
	
	//Ciclo donde se reciben datos
	while(1){
		recvfrom(socket_descriptor, message, sizeof(message), 0, (struct sockaddr *)&sin, &sin_len);
		printf("Respuesta del Servidor: %s\n", message);
		if (strncmp(message, "stop", 4) == 0)
		{
			printf("El remitente desea terminar la conexión\n");
			break;
		}
	}
	close(socket_descriptor);
	return 0;	
}
