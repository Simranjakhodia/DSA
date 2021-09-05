#include<stdio.h>
#include<stdlib.h>  // malloc is defined under this header
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};

void printMiddle(struct node* head)
{
    int count = 0;
    struct node* mid = head;

    while(head != NULL)
    {
        if(count & 1){
            mid = mid -> next ; cout <<"xyz"<<(count&1);
        }
        ++count ; 
        head = head->next ;    
    }

    if (mid != NULL )
        printf("The middle element is [%d]\n\n", mid->data); 
}

void push(struct node** head , int data)
{
    struct node* new_node = (struct node*)malloc( sizeof (struct node) );
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
     
}

void printList(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr  = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head = NULL;
    int i ;

    for(i = 5; i > 0 ; i--)
    {
        push(&head , i );
        printList(head);
        printMiddle(head); 
    }
    return 0;
}
