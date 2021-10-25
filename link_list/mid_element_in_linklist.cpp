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

//mid element function 
struct node * midElem(struct node * head){
    struct node *slow ,*fast;
    slow=fast=head;
    
    while(fast->next !=0){
        if(fast->next->next == 0){
            fast = fast->next;
        }
        else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow;
}

bool isPalindrome(struct node * head){
    struct node *mid,*rvrHead,*head1=head;
    bool res = true;
    mid  = midElem(head);
    rvrHead = reverse(mid->next);
    // std::cout<<"reverse : "<<rvrHead->next->data<<std::endl;
    while(rvrHead != 0){
        if(rvrHead->data == head1->data){
            std::cout<<rvrHead->data<<" "<<head1->data<<std::endl;
            rvrHead = rvrHead->next;
            head1 = head1->next;
        }
        else{
            res= false;
            break;
        }
    }
    return res;
}

int main(){
    //declaring pointers
    struct node *head,*newNode,*tempt, *mid;
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
    
    std::cout<<isPalindrome(head)<<std::endl;
    return 0;
}

