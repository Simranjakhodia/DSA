/* MT2 PUSH COSTLY
*/
#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
    int curr_size;

    public:
    Stack()
    {
        curr_size = 0 ;
    }
    void push(int x)
    {
        curr_size++;
        q2.push(x);

        // push all the remaining elements in q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue <int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;    
    }
    int top()
    {
        if(q1.empty())
            return -1;
        return q1.front();    
    }
    int size()
    {
        return curr_size;
    }
};

/*
MT-2 POP COSTLY
*/

#include<iostream>
#include <queue>
using namespace std;

class Stack{

 
    queue <int> q1, q2;
    int size_a ;

      public: 
        Stack()
        {
            size_a = 0;
        } 

        int size()
        {
            return size_a;
        }

        void pop()
        {
            if(q1.empty())
                return;

            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }    

            q1.pop();
            size_a--;

            queue <int> q = q1;
            q1 = q2;
            q2 = q;
        }

        void push(int x)
        {
            q1.push(x);
            size_a++;
        }

        int top()
        {
            if(q1.empty())
            return -1;

            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            q2.push(temp);

            queue<int> q = q1;
            q1 = q2;
            q2 = q;
            return temp;
        }

        
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size() << endl;
    return 0;
}


// https://www.geeksforgeeks.org/implement-stack-using-queue/