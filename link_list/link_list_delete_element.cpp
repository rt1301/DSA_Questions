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

 //delete starting node 
 struct node * deleteFromStart(struct node * head) 
    {   struct node * tempt;

        tempt = head;
        head = head->next;

        free(tempt);
        return head;
   }

//delete starting node 
 void deleteFromEnd(struct node * head) 
    {   struct node * tempt,*prevNode;
         //for printing list
        tempt = head;
        while(tempt->next !=0){
            prevNode = tempt;
            tempt = tempt->next;
   
        }
        if(tempt == head){
                head = 0;
            }
            else{
                prevNode->next = 0;
            }
            free(tempt);
    }

 struct node * deleteFromAnyPosition(struct node * head ,int position){
     struct node * deleteNode, * prevNode;int i =1;
     deleteNode = head;

     //for handeling first node
     if (position == 1){
         deleteNode = head;
         head  = head->next;
     }

     else{
        while(i != position){
         prevNode = deleteNode;
         deleteNode = deleteNode ->next;
         i++;
        }
        std::cout<<prevNode->data;
        prevNode->next = deleteNode->next;
     }
    free(deleteNode);
    return head;
    
 }

    //delete at any position


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
    int choice = 1,deletePosition;
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


  std::cout<<"enter postion to delete : ";
  std::cin>>deletePosition;
  head = deleteFromAnyPosition(head, deletePosition);
  display(head);
  return 0;
}

