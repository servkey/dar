#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 67
#define DHCP_H
#define DHCP_CLIENT_PORT        68      
#define DHCP_SERVER_PORT        67

#define DHCP_XID_LEN		4
#define DHCP_SECS_LEN		2
#define DHCP_FLAGS_LEN		2

#define DHCP_MAXMAC		6
#define DHCP_CHADDR_LEN         10
#define DHCP_SNAME_LEN          64
#define DHCP_FILE_LEN           128
#define DHCP_OPTIONS_LEN        512
#define DHCP_MIN_OPTIONS_LEN    68
#define DHCP_MAXIP		4

struct dhcp_msg {
  unsigned char op;                       // Message opcode/type
  unsigned char htype;                    // Hardware addr type
  unsigned char hlen;                     // Hardware addr length
  unsigned char hops;                     // Number of relay agent hops from client
  unsigned char xid[DHCP_XID_LEN];         // Transaction ID
  unsigned char secs[DHCP_SECS_LEN];                    // Seconds since client started looking
  unsigned char flags[DHCP_FLAGS_LEN];                   // Flag bits
  struct in_addr ciaddr;                  // Client IP address (if already in use)
  struct in_addr yiaddr;                  // Client IP address (if already in use)
  struct in_addr siaddr;                  // Client IP address (if already in use)
  struct in_addr giaddr;                  // Client IP address (if already in use)
  unsigned char chaddr[DHCP_MAXMAC + DHCP_CHADDR_LEN];  // Client hardware address 
  char sname[DHCP_SNAME_LEN];             // Server name
  char file[DHCP_FILE_LEN];               // Boot filename
  unsigned char options[0];               // Optional parameters (actual length dependent on MTU).
};

void printNCharToHexStart(char values[], int numbytes, int startindex){
	int i;
	printf("0x");
	for (i = startindex; i < numbytes; i++){
		printf("%02x", values[i]);
	}
	printf("\n");
}

void printNCharToHex(char values[], int numbytes){
	int i;
	printf("0x");
	for (i = 0; i < numbytes; i++){
		printf("%02x", values[i]);
	}
	printf("\n");
}

void printCharToHex(char values[]){
	int i;
	printf("0x");
	for (i = 0; i < strlen(values); i++){
		printf("%02x", values[i]);
	}
	printf("\n");
}

int main (int argc, char *argv[]){
	int sin_len;
	struct dhcp_msg message;
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
		recvfrom(socket_descriptor, &message, sizeof(message), 0, (struct sockaddr *)&sin, &sin_len);
		int i = 0;
		printf("=========================\n");
		printf("OP: 0x%02x\n", message.op);
		printf("HTYPE:0x%02x \n", message.htype);
		printf("HLEN: 0x%02x\n", message.hlen);
		printf("HOPS: 0x%02x\n", message.hops);
		printf("XID: "); printNCharToHex(message.xid, DHCP_XID_LEN);
		printf("SECS: "); printNCharToHex(message.secs, DHCP_SECS_LEN);
		printf("FLAGS: "); printNCharToHex(message.flags, DHCP_FLAGS_LEN);
		printf("CIADDR: %s\n", inet_ntoa(message.ciaddr));
		printf("YIADDR: %s\n", inet_ntoa(message.yiaddr));
		printf("SIADDR: %s\n", inet_ntoa(message.siaddr));
		printf("GIADDR: %s\n", inet_ntoa(message.giaddr));

		printf("MACADD: %02x:%02x:%02x:%02x:%02x:%02x\n", message.chaddr[0], message.chaddr[1], message.chaddr[2], message.chaddr[3], message.chaddr[4], message.chaddr[5]);
		printf("HADDR: "); printNCharToHexStart(message.chaddr, 10, 6);
		printf("=========================\n");
	}
	close(socket_descriptor);
	return 0;	
}


