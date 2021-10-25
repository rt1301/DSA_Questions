#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//creating structure
struct node
{
    /* data */
    struct node *prev;
    int data;
    struct node *next;
};


//add new element
struct node * AddToAnyPosition(struct node * head ,int value, int position){
    
     struct node * addNode,*newNode, * temptNode;int i =1;
     newNode = (struct node *) malloc(sizeof(struct node));
     newNode->data = value;
     //if the head is zero
     addNode = head;
     if (position == 1){
         temptNode = head;
         head = newNode;
         head->next  = temptNode;
     }
     else{
        while(i != position){
         temptNode = addNode;
         addNode = addNode ->next;
         i++;
        }
        newNode->next = addNode;
        temptNode->next = newNode;
     }
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
    int choice = 1,addPosition,value;
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


  std::cout<<"enter postion to add : ";
  std::cin>>addPosition;
  std::cout<<"enter value to add : ";
  std::cin>>value;
  head = AddToAnyPosition(head,value, addPosition);
  display(head);
  return 0;
}

