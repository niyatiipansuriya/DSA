#include<iostream>
#include"Stack_node.cpp"

using namespace std;

class Stack{

    public:

    int size;
    int top = -1;
    Node* head = NULL;

    Stack(int size)
    {
        this->size = size;
    }

    void push(int elem)
    {
        if(top >= size-1)
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            Node* node = new Node(elem);

            if(head == NULL)
            {
                head = node;
            }
            else
            {
                node->next = head;
                head = node;
            }
            top++;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Empty stack"<<endl;
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        top--;
    }

    int sizee()
    {
        if(top == -1)
        {
            return 0;
        }
        return top + 1;
    }

    int peak()
    {
        if(top == -1)
        {
            cout<<"Empty Stack"<<endl;
        }
        else{
            return head->data;
        }
    }
};

int main()
{
    Stack s(3);
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();

    cout<<s.sizee()<<endl;
}