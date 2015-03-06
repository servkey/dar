#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 6789

int main(int argc, char *argv[]){
	int socket_descriptor;
	int on = 1;
	int iter = 0;
	char buf[80];
	struct sockaddr_in address;
	//Inicia la estructura de direcciones de socket para los protocolos
	memset(&(address.sin_zero), '\0', 8);		
	address.sin_family = AF_INET;
//	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_addr.s_addr = inet_addr("255.255.255.255");
	address.sin_port = htons(PORT);
	//Crear socket UDP
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);

        if (setsockopt(socket_descriptor, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0)
        {
                perror("Error - BROADCAST setsockopt()");
                return 1;
        }

	//Enviar datos 
	for (iter = 0; iter <= 5; iter++){
		sprintf(buf, "Datos con # %d", iter);
		if (sendto(socket_descriptor, buf, sizeof(buf), 0, (struct sockaddr *) &address, sizeof(address)) == -1)
		{
			perror("Client - sendto");
			return 1;
		}
	}	
	//Enviar un mensaje de finalización


	sprintf(buf, "stop\n");
	sendto(socket_descriptor, buf, sizeof(buf), 0, (struct sockaddr *) &address, sizeof(address));
	close(socket_descriptor);
	printf("Mensaje enviado, terminando \n");
	return 0;
}

