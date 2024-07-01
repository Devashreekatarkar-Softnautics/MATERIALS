#include "LinkedList.h"

void PrintMenu(){
	printf("\nThe menu\n------------------------------------------------------------------\n");
	printf("A: To initialize the list\nB: To insert the node at the top\nC: To insert the node at the nth location\n");
	printf("D: To retrive the node from top\nE: To retrieve the node from the specific location\nF: To delete the top node\n");
	printf("G: To delete the nth node\nH: To print the linked list\nI: To delete the whole linked list\n");
	printf("J: To check if the list is empty or not\nK: To remove the node with specific value\nL: To sort the list\n");
	printf("M: To evaluate the size of the list\nN: To Return the position of the node with specific value\nQ: quit\n");
	printf("------------------------------------------------------------------\n");
}

int main(){

    uint32_t NumofNodes;
    int DataAtTop;
    int DataAtNode;
    int RetrivedValue;
    int RetrivedValueP;
    uint32_t Postion;
    char input;
    int PP;
    int num;
    int SomeVar;
    int value;
    int P;
    bool state = true;
    static Node* head;    
    int size;
    
    while(state){
    	    PrintMenu();
    	    printf("Enter the choice: ");
	    scanf(" %c",&input);

    	switch(input){
    		case 'A':
			printf("Enter the number of Nodes: ");
			scanf("%d",&NumofNodes);
			head = initlist((void**)&head, NumofNodes);
			//PrintNodes((void*)head);
			break;

		case 'B':
			printf("Enter the data to insert at the top node: ");
			scanf("%d", &DataAtTop);
			head = insertNodeAtTop((void*)head,DataAtTop);
			//PrintNodes((void*)head);
			break;

		case 'C':
			printf("Enter the position: ");
			scanf("%d",&Postion);
			printf("Enter the data: ");
			scanf("%d",&DataAtNode);
			head = listInsertNodeAt((void*)head,Postion,DataAtNode);
			//PrintNodes((void*)head);
			break;

		case 'D':
			//printf("Retriving node from the top\n");
			RetrivedValue = RetriveNodeFromTop((void*)head);
			printf("The value contained in the top node is: %d\n",RetrivedValue);
			break;

		case 'E':
			//printf("Retriving the node from nth position\n");
			printf("Enter the Position of the node from where you want to retrive the data\n");
   			scanf("%d",&Postion);
			RetrivedValueP = RetriveNodeFromP((void*)head,Postion);
			if(RetrivedValueP != 0){
				printf("The value contained in the %d node of the list is: %d\n",Postion,RetrivedValueP);		
			}
			break;

		case 'F':
			//printf("Deleting the Top node of the list\n");
			head = RemoveTopNode((void*)head);
			//PrintNodes((void*)head);
			break;

		case 'G':
			//printf("Deleting the nth node\n");
			printf("Enter the position: ");
			scanf("%d",&PP);
			head = RemoveNNode((void*)head,PP);
			//PrintNodes((void*)head);
			break;

		case 'H':
			//printf("The list is as follows\n");
			PrintNodes((void*)head);
			break;

		case 'I':
			printf("Deleting the whole linkedlist\n");
			head = DelList((void*)head);
			printf("The whole linkedlist has been deleted\n");
			break;

		case 'J':
			//printf("Checking if the list is empty or not...\n");
			num = CheckList((void*)head);
			if(num == 0)
				printf("List is empty\n");
			else
				printf("List is not empty\n");
			break;
		case 'K':
			//printf("Removing node with specific value\n");
			printf("Enter the data input: ");
			scanf("%d",&SomeVar);
			head = RemoveNValue((void*)head,SomeVar);
			//PrintNodes((void*)head);
			break;
			
		case 'L':
			//printf("The sortlist func\n");
			SortList((void*)head);
			//PrintNodes((void*)head);
			break;
			
		case 'M':
			//printf("size of the list func\n");
			size = SizeOfList((void*)head);
			if(size != 0){
				printf("The size if the list is: %d\n",size);
			}
			break;
			
		case 'N': 
			//printf("Return position of the node containing the value N\n");
			printf("Enter the data value: ");
			scanf("%d",&value);
			P = RetPVal((void*)head,value);
			if(P != 0){
				printf("The position of the data in the list is: %d\n",P);
			}
			break;
			
		case 'Q':
			printf("Quit\n");
			head = DelList((void*)head);
			state = false;
			break;

		default:
			printf("Usage: Linked List\n");
			break;

    	}	
    }

}

