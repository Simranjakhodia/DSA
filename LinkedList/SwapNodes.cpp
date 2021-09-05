#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    class Node *next;
};

void swapNodes(Node** head , int x , int y)
{
    if( x == y )
     return ;
    
    Node *prevX = NULL , *currX = *head;
    while (currX && currX -> data != x){
        prevX = currX;
        currX = currX->next;
    } 
    
    Node *prevY = NULL , *currY = *head;
    while (currY && currY -> data != y){
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL || currY == NULL)
        return;

    if(prevX != NULL)
        prevX -> next = currY;
    else
        *head = currY;

    if(prevY != NULL)  
        prevY -> next = currX;          
    else
        *head = currX;

    Node *temp = currY->next;
    currY -> next = currX -> next;
    currX -> next = temp;    
    
}

void swap(Node*& a , Node*& b)
{
    Node* temp = a;
    a = b;
    b = temp;
}

void swapNodes_another( Node** head , int x , int y)
{
    if(x == y)
        return;

    Node **a = NULL , **b = NULL;

    while (*head){

        if((*head) -> data == x)
            a = head;

        else if ((*head) -> data == y)
            b = head;

        (head) = &((*head) -> next);      
    }

    if ( a && b ){
        swap ( *a, *b);
        swap ( (*a) -> next , (*b) -> next );
    }
}
void push(Node** head , int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    *head = newNode;
}

void printList(Node* node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
        node = node -> next;
    }
}

int main()
{
    Node* start = NULL;

    push( &start , 7);
    push( &start , 6);
    push( &start , 5);
    push( &start , 4);
    push( &start , 3);
    push( &start , 2);
    push( &start , 1);

    cout << "Linked List before calling swapNodes() ";
    printList(start);
    swapNodes_another(&start , 4 , 3);

    cout << "Linked List after calling swapNodes() ";
    printList(start);
    return 0;
}