#include "ServerClient.h"

char temp[10000];
char buffer[10000] = {0};

int ReadFile(int socket) {
	FILE* file;
	file = fopen("new.txt", "r");

	if (!file) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	FILE* filee = fopen("out.txt", "w");
	if (!filee) {
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	ssize_t filebytes;
	while((filebytes = fread(buffer,1,MAX_BUFFER_SIZE, file)) > 0 ){
		buffer[filebytes] = '\0';
		//printf("%d\n",filebytes);
		send(socket, buffer,strlen(buffer),0);
		read(socket, temp, MAX_BUFFER_SIZE);
		fprintf(filee, "%s", temp);
	}
	//printf("%d\n",filebytes);

	fclose(file);
	fclose(filee);  
	return 0;
}


int main(int argc, char *argv[]) {

	struct sockaddr_in server_addr;
	int client_socket;
	if(argc < 2){
		printf("Usage: ./client <IP_ADDR> \n");
		exit(EXIT_FAILURE);
	}


	// Create socket
	if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Client socket created successfully\n");
	printf("client ID: %d\n",client_socket);

	// Configure server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
		perror("Invalid address/ Address not supported");
		exit(EXIT_FAILURE);
	}

	// Connect to the server
	if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
		perror("Connection failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Connection to Server: success\n");
	ReadFile(client_socket);
	close(client_socket);
	printf("File Received successfully\n");
	return 0;
}

