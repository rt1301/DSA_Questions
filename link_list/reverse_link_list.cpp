 #include <stdio.h>
#include <stdlib.h>
#include <iostream>

//creating structure
struct node
{
    /* data */
    int data;
    struct node *next;
};


struct node * reverse(struct node * head){
    struct node *nextNode, * currNode,*prevNode=0;
    currNode=nextNode=head;
    while (nextNode !=0)
    {
    
            nextNode = nextNode->next;
            currNode->next = prevNode;
            prevNode = currNode; 
            currNode=nextNode;
    }
       
    head = prevNode;
    return head;
    
 }

    

//disply list 
void display(struct node *head){
    struct node * tempt;
    //for printing list
    tempt = head;
    while(tempt!=0){
        // printf("%d\n",tempt->data);
        std::cout<<tempt->data<<"   "<<tempt->next<<"\n";
        tempt = tempt->next;
    }
}
int main(){
    //declaring pointers
    struct node *head,*newNode,*tempt;
    int choice = 1;
    head = 0;
    while (choice)
    {
        /* code */
         newNode = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&newNode->data);
    newNode->next = 0;

    if(head ==0){
        head = tempt =  newNode;
        }
    else{
        tempt->next = newNode;
        tempt = newNode; 
    }

    //0 to end adding and 1 for countinue
    printf("enter 1 or 0 : ");
    scanf("%d",&choice);
    }

  printf("Entered list : \n");
  display(head);
  
  
  head = reverse(head);
  std::cout<<"after reverse : ";
  display(head);
  return 0;
}

