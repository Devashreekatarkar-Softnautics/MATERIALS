#include "LinkedList.h"

/** 
  *@author Devashree Katarkar
  *@date 16/01/2024
  *@file LinkedList.c
  *@brief This is a static library implementing LinkedList data structure.It consist of 14 APIs performing various functions.
                                    
*/
void PrintNodes(void* linkedlist){

	/**
	  *@brief This function prints the data contained within the list.
	  *@return void 
	  *@param linkedlist The function expects the head node as the function arguement
	*/

	Node *ptr = (Node*)linkedlist;
	
	if((Node*)linkedlist == NULL){
		fprintf(stderr, "No elements in the list\n");
		return;
	}
	
	while(ptr != NULL){
	    printf("%d ",ptr->data);
	    ptr = ptr->link;
	}
	   
	printf("\n");     	
}

Node* initlist(void **linkedlist, uint32_t maxlinkedlistsize){
	/**
	  *@brief This function initializes the list and allocate memory to the nodes,meanwhile it also asks user input for data to be contained in the list
	  @return Node* it returns a pointer of type Node to update the value of the head pointer
	  @param **linkedlist This arguement expects the pointer address passed to the function as one of the parameter
	  @param maxlinkedlistsize This arguement specifies the number of nodes to be initialize.
	*/
    *linkedlist = (Node*)malloc(sizeof(Node));
    Node *current;
    int tempval;

    if(*linkedlist == NULL){
    	fprintf(stderr, "Memory allocation failed\n");
	exit(EXIT_FAILURE);
    }
    
    printf("Enter the data in node 1: ");
    scanf("%d",&tempval);
    ((Node*)(*linkedlist))->data = tempval;
    ((Node*)(*linkedlist))->link = NULL;

    Node* temp = (Node*)*linkedlist;

    for(uint32_t i = 1; i < maxlinkedlistsize; i++){
    	    int tempval;
	    current = (Node*)malloc(sizeof(Node)); 
	    temp->link = current;
	    printf("Enter the data in node %d: ",i+1);
	    scanf("%d",&tempval);
	    current->data=tempval;
	    current->link=NULL;
	    temp = current;
    }    
    return (Node*)(*linkedlist);
}

Node* insertNodeAtTop(void *linkedlist, int input){
	/**
	  *@brief The Purpose of this function is to insert a node at the top of the linkedlist.
	  *@return It returns the pointer to the user defined type node.
	  *@param *linkedlist The function expects head pointer as one of its parameter
	  *@param input This parameter asks for user input for the data to be entered in the top node
	*/

	if((Node*)linkedlist == NULL){
		printf("The list is empty");
		return NULL;
	}
	
	Node* ptr = (Node*)malloc(sizeof(Node));
	
	ptr->data = input;
	ptr->link = (Node*)linkedlist;
	linkedlist = ptr;	

	return (Node*)linkedlist;
}

Node* listInsertNodeAt(void *head, int pos, int input){
	/**
	  *@brief The Purpose of this function is to insert a node at the nth position of the linkedlist.
	  *@return It returns the pointer to the user defined type node.
	  *@param *head The function expects head pointer as one of its parameter
	  *@param pos It specifies the position at which the node has to be inserted
	  *@param input This parameter asks for user input for the data to be entered in the top node
	*/
	Node *traverseNode = (Node*)head;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return NULL;
	}
	
	int len = SizeOfList(head);
	
	if(pos<0){
		
		printf("The position value cannot be negative\nTry again\n");
		printf("Size of the list is: %d\n",len);
		return (Node*)head;
	}else if(pos >= (len+2) || pos == 0){
		printf("Invalid input position\n");
		return (Node*)head;
	}
	
	if(pos == 1){
		traverseNode = insertNodeAtTop(head,input);
		return traverseNode;
		
	}
	
	Node *insNode = (Node*)malloc(sizeof(Node));
	insNode->data = input;
	insNode->link = NULL;

	int compare = 1;
	while(compare != (pos-1)){
		traverseNode = traverseNode->link;
		compare++;
	}
	insNode->link = traverseNode->link;
	traverseNode->link = insNode;
	return (Node*)head;
}

int RetriveNodeFromTop(void *head){
	/**
	  *@brief The Purpose of this function is to retrive the value contained in the top node.
	  *@return int It returns an integer value.
	  *@param *head The function expects head pointer as one of its parameter
	  
	*/
	int number;
	Node *tmp = (Node*)head;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return 0;
	}
	number = tmp->data;
	return number;
}

int RetriveNodeFromP(void* head, int pos){
	/**
	  *@brief The Purpose of this function is to retrive the value contained at the nth node.
	  *@return int It returns an integer value.
	  *@param *head The function expects head pointer as one of its parameter.
	  *@param pos It specifies the position from which the user wants to retrive data
	*/
	Node* tmp = (Node*)head;
	int number;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return 0;
	}
	int len = SizeOfList(head);
	if(pos<0){
		printf("The position value cannot be negative\n");
		printf("Size of the list is: %d\n",len);
		return 0;
	}else if(pos > len || pos == 0){
		printf("Invalid input position\n");
		return 0;
	}
	
	if(pos == 1){
		number = RetriveNodeFromTop(head);
		return number;
	}
	int compare = 1;
	while(compare != pos){
		tmp = tmp->link;
		compare++;
	}
	number = tmp->data;
	return number;
}

Node* RemoveTopNode(void* head){
	/**
	  *@brief The Purpose of this function is to delete the top node of the linked list.
	  *@return Node* It returns the updated head pointer
	  *@param *head The function expects head pointer as one of its parameter
	  
	*/
	Node* temp = (Node*)head;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return 0;
	}
	
	head = temp->link;
	free(temp);
	temp = NULL;
	return (Node*)head;
}

Node* RemoveNNode(void* head, int pos){
	/**
	  *@brief The Purpose of this function is to delete the nth node of the linked list.
	  *@return Node* It returns the updated head pointer
	  *@param *head The function expects head pointer as one of its parameter
	  *@param pos It specifies the position of the node user wishes to delete.
	*/
	Node* prev = (Node*)head;
	Node* curr = (Node*)head;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return 0;
	}
	int len = SizeOfList(head);
	if(pos<0){
		printf("The position value cannot be negative\n");
		printf("Size of the list is: %d\n",len);
		return (Node*)head;
	}
	

	if(pos > len || pos == 0){
		printf("Invalid input position\n");
		return (Node*)head;
	}
	
	

	if(pos == 1){
		head = curr->link;
		free(curr);
		curr = NULL;
		return (Node*)head;

	}else{
		int comp = 1;
		
		while(comp != pos){
			prev = curr;
			curr = curr->link;
			comp++;
		}

		prev->link = curr->link;
		free(curr);
		curr = NULL;

		return (Node*)head;
	}
}

Node* DelList(void* head){
	/**
	  *@brief The Purpose of this function is to delete the whole linked list.
	  *@return Node* It returns the head pointer pointing to NULL.
	  *@param *head The function expects head pointer as one of its parameter.
	*/
	Node *temp = (Node*)head;
	
	if((Node*)head == NULL){
		printf("The list is already empty...\n");
		return 0;
	}
	
	while(temp != NULL){
		temp = temp->link;
		free(head);
		head = temp;
	}
	head = NULL;
	return (Node*)head;
}

int CheckList(void *head){
	/**
	  *@brief The Purpose of this function is to check if the list is empty or not.
	  *@return int It returns an integer to indicate the status of the list,i.e., 1 for a non-empty list & 0 for an empty list
	  *@param *head The function expects head pointer as one of its parameter
	  
	*/
	if ((Node*)head == NULL)
		return 0;
	else
		return 1;
}

int SizeOfList(void *head){
	/**
	  *@brief The Purpose of this function is to return the size of the list.
	  *@return int It returns the integer value indicating the size of the size
	  *@param *head The function expects head pointer as one of its parameter
	  
	*/
	Node *temp = (Node*)head;
	int count = 0;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return 0;
	}
	
	while(temp != NULL){
		count++;
		temp = temp->link;
	}
	return count;
}

Node* RemoveNValue(void *head, int data){
	/**
	  *@brief The Purpose of this function is to remove the node contained with some specific value.
	  *@return Node* It returns the updated head pointer
	  *@param *head The function expects head pointer as one of its parameter
	  *@param data It takes the data value of the specific node to remove that node
	  
	*/
	Node *temp = (Node*)head;
	Node *prev = (Node*)head;
	Node *somenode = (Node*)head;
	int check = 0;
	int StoreVal;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return NULL;
	}
	
	while(somenode != NULL){
	
		StoreVal = temp->data;
		if(StoreVal == data){
			if(check == 0){
				head = RemoveTopNode(head);
				return (Node*)head;			
			}
			prev->link = temp->link;
			free(temp);
			temp = NULL;
			break;
		}
		check++;
		prev = temp;
		temp = temp->link;
		somenode = somenode->link;
	}
	return (Node*)head;
	
}

int RetPVal(void* head, int val){
	/**
	  *@brief The Purpose of this function is to return the position of the 'N' value present in the list.
	  *@return int It returns the integer value indicating the position.
	  *@param *head The function expects head pointer as one of its parameter
	  *@param val The second parameter of the function specifies the data value
	  
	*/
	Node *tmp = (Node*)head;
	//Node *prev = (Node*)head;

	int StoreVal;
	int count = 0;
	
	if((Node*)head == NULL){
		printf("The list is empty...\n");
		return 0;
	}
	
	while(tmp != NULL){
		StoreVal = tmp->data;
		count++;
		if(StoreVal == val){
			return count;
		}
		tmp = tmp->link;
	}
	printf("The data is not there in the list\n");
	return 0;
}

void SortList(void* head){
	/**
	  *@brief The Purpose of this function is to sort the linked list in ascending order.
	  *@return void It return nothing
	  *@param *head The function expects head pointer as one of its parameter
	  
	*/
	if((Node*)head == NULL){
		printf("The list is empty, Nothing to sort\n");
		return;
	}
	int GetSize = SizeOfList(head);
	for(int i=0;i<GetSize;i++){
		Node* current = (Node*)head;
		Node* next = current->link;
		for(int j=0;j<GetSize-i-1;j++){
			if(current->data > next->data){
				int s;
				s = current->data;
				current->data = next->data;
				next->data = s;
			}
			current = current->link;
			next = next->link;
		}
	}
}


