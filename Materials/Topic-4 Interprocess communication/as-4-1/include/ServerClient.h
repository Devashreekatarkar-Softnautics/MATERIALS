#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/select.h>
#include <ctype.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void* ServerFile(void*);
int ReadFile(int);


