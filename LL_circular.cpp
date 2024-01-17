#include<iostream>

using namespace std;

class Node{

    public:

    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head , int data , int x)
{
    Node* node = new Node(data);
    if(head == NULL)
    {
        head = node;
        node->next = head;
    }

    else{
        Node* temp = head;

        while(true)
        {
            if(temp->data == x)
            {
                break;
            }

            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
    }
}

void print(Node* &head)
{
    cout<<head->data<<" ";

    Node* temp = head->next;

    while(temp != head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

void dlt(Node* &head , int x)
{
    if(head == NULL)
    {
        cout<<"Empty list"<<endl;
    }
    else
    {
        // if(x==head->data)
        // {
        //     Node* k = head;
        //     head = head->next;
        //     free(k);
        // }

        // else
        {
            Node* temp = head->next;
            while(temp!=head)
            {
                if(temp->next->data == x)
                {
                    break;
                }
                temp = temp->next;
            }

            Node* node = temp->next;
            temp->next = temp->next->next;
            if(node == head)
            {
                head = head->next;
            }
            free(node);
        }
    }
}

int main()
{
    Node* head = NULL;
    insert(head , 10 , 0);
    insert(head , 20 , 10);
    insert(head , 30 , 10);

    print(head);

    dlt(head , 10);

    print(head);
}