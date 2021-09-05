#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void rotate(Node**head , int k)
{
    if (k<1)
        return;
    
    Node *tail = *head;
    while(tail->next){
        tail = tail->next;
    }
    Node *temp = *head;
    *head = (*head)->next;
    tail->next = temp;
    temp->next = NULL;
    k--;
    if(k>0)
    rotate(head , k);
    else
    return;

}

void insert(Node **head , int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    if(*head)
    {
        node->next = (*head);
        (*head) = node;
    }
    else
        *head = node;
}
void print(Node *head)
{
    while(head){
        cout<< head->data << "-> ";
        head = head->next;
    }
    cout <<endl;
}

int main()
{
    Node*head = NULL;
    int a[] = {10 , 20 , 30 , 40 , 50 ,60};
    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]); i++ ){
        insert(&head , a[i] );
    }
    print(head);
    rotate(&head , 4);
    print(head);    
    return 0;
}