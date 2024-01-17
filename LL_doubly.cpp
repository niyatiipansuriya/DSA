#include<iostream>

using namespace std;

class Node{

    public:

    int data;
    Node* next;
    Node* prv;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prv = NULL;
    }
};

void insert(Node* &head , int k , int data)
{
    Node* node = new Node(data);

    if(k==0)
    {
        node->next = head;
        head->prv = node;
        head = node;
    }

    else{
        Node* temp = head;

        for(int i=1 ; i<k-1 ; i++)
        {
            temp = temp->next;
        }
        temp->next->prv = node;
        node->next = temp->next;
        temp->next = node;
        node->prv = temp;
    }
}

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

void dlt(Node* &head , int k)
{
    if(k == 1)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    else{
        Node* temp = head;
        for(int i=1 ; i<k-1 ; i++)
        {
            temp = temp->next;
        }

        Node* node = temp->next;
        temp->next = temp->next->next;
        temp->next->prv = temp;
        free(node);
    }
}

int main()
{
    Node* head = new Node(10);
    insert(head , 0 , 20);
    insert(head , 1 , 30);

    print(head);

    dlt(head , 2);

    print(head);
}