#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int m[3][3] = {{0 , 1 , 0} , {0 , 0 , 0} , {0 , 1 , 0}};

    stack<int> s;

    for(int i=0 ; i<3 ; i++)
    {
        s.push(i);
    }

    while(s.size()!=1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(m[a][b]==1 && m[b][a]==0)
        {
            s.push(b);
        }
        if(m[b][a]==1 && m[a][b]==0)
        {
            s.push(a);
        }
    }

    cout<<s.top();
}