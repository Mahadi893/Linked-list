#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue{
    Node*head;
    Node*tail;
    public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int val) // insert data at the end
    {
       Node*newNode = new Node(val); 
       if(empty())
       {
          head = tail = newNode;
       }
       else{
          tail->next=newNode;
          tail=newNode;
       }
    }
    void pop() // delete data from the front
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node*temp = head;
        head = head->next;
        delete temp;
    }
    int front() // get the front data
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    bool empty() // check if the queue is empty if yes return true else false
    {
        return head == NULL;
    }
};

int main()
{
   Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
