#include<iostream>

using namespace std;

class stack{
    public:

    int top;
    int size;
    int arr[];

    stack(int size)
    {
        this->size = size;
        arr[size];
        top = -1;
    }

    void push(int elem)
    {
        if(top >= size-1)
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            top++;
            arr[top] = elem;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Empty stack"<<endl;
        }
        else
        {
            top--;
        }
    }

    bool empty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }

    int sizee()
    {
        if(top < 0)
        {
            return 0;
        }
        return top+1;
    }
    
    int peak()
    {
        if(top == -1)
        {
            cout<<"Empty stack";
        }
        else{
            return arr[top];
        }
    }
};

int main()
{
    stack s(5);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.pop();

    cout<<s.sizee();
}