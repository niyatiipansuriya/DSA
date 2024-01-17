#include<iostream>

using namespace std;

class Node{

    public:

    int data;
    Node* next;

    Node(int data)
    {
        this->data=  data;
        this->next = NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insert(Node* &head , int data , int k)
{
    Node* node = new Node(data);
    if(k==0)
    {
        node->next = head;
        head = node;
    }

    else{
         Node* temp = head;

    for(int i=1 ; i<k ; i++)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
    }
}

void dlt(Node* &head , int k)
{   
    if(k==1)
    {
        Node* node = head;
        head = head->next;
        free(node);
    }

    else{
        
        Node* temp = head;

        for(int i=1 ; i<k-1 ; i++)
        {
            temp = temp->next;
        }

        Node* node = temp->next;
        temp->next = temp->next->next;
        free(node);
    }
}

int main()
{
    Node* head = new Node(10);

    insert(head , 20 , 0);
    insert(head , 50 , 2);

    print(head);
    cout<<endl<<endl;

    dlt(head , 3);

    print(head);
}