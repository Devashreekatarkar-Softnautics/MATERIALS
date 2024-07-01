#include "ServerClient.h"

char buffer[MAX_BUFFER_SIZE+1] = {0};
char temp[MAX_BUFFER_SIZE+1] = {0};
int PortN;

void* ServerFile(void* socket) {
	int j = 0;
	ssize_t bytes;
	int c_socket = *((int*)socket);
	

	while((bytes = read(c_socket, buffer, MAX_BUFFER_SIZE))>0){
		j = 0;
		buffer[bytes] = '\0';
		for (int i = 0; i < strlen(buffer) && (buffer != '\0'); i++) {
			temp[j] = toupper(buffer[i]);
			j++;
		}
		temp[j] = '\0';
		send(c_socket, temp, MAX_BUFFER_SIZE, 0);
	}
	return NULL;
}


int main(int argc, char* argv[]){

	if(argc < 3){
		printf("Usage: ./server <System-IP> <Port No.>\n");
		printf("use port number 8080\n");
		return 0;
	}
	
	int Port = atoi(argv[2]);
	if(Port != 8080){
		printf("Use port 8080\n");
		exit(EXIT_FAILURE);
	}
	


	int server_socket, new_socket;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size = sizeof(client_addr);
	const char* hostname = argv[1];

	// Create socket
	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	printf("ServerSocket created\n");
	printf("Server ID: %d\n",server_socket);

	// Configure server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));

	//Converting human readable IP to binary form 
	if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
		perror("Invalid address/ Address not supported");
		exit(EXIT_FAILURE);
	}

	// Bind the socket
	if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Bind Successful\n");

	// Listen for incoming connections
	if (listen(server_socket, 10) == -1){
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}
	printf("Server listening\n");
	pthread_t client_threads[10];

	int client_count = 0;
	fd_set ReadClients;
	struct timeval Timeout;
	Timeout.tv_sec = 30;

	do{
		FD_ZERO(&ReadClients);
		FD_SET(server_socket,&ReadClients);
		int TimeCheck = select(server_socket+1,&ReadClients,NULL,NULL,&Timeout);
		if(TimeCheck == -1){
			perror("timeout error\n");
			exit(EXIT_FAILURE);
		}
		if(TimeCheck > 0){
			if(FD_ISSET(server_socket,&ReadClients)){
				if((new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size)) == -1){
					perror("Accept failed");
					exit(EXIT_FAILURE);
				}
				Timeout.tv_sec = 30;
				if(client_count < 10){
					pthread_create(&client_threads[client_count],NULL,&ServerFile,(void*)&new_socket);
					client_count++;
					printf("client connected %d\n",client_count);
				}else{
					printf("Maximum number of connections reached\n");
					break;
				
				}
			}
			}else{
				printf("No incoming client detected, server closing\n");
				break;
			}
		}while(1);

		for(int i=0;i<client_count;i++){
			pthread_join(client_threads[i],NULL);
			close(new_socket);
		}

		close(server_socket);
		return 0;

	}

