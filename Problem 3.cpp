#include<bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int front;
    int rear;
    int len;
    int *arr;
    int max_size;
    Queue(int size)
    {
        if (size <= 0)
        {
            max_size = 50;
        }
        else
            max_size = size;

        front = 0;
        rear =max_size -1;
        len=0;
        arr = new int[max_size];
    }
    bool isEmpty()
    {
        return len == 0;
    }
    bool isFull()
    {
        return len == max_size;
    }
    void add(int element)
    {
        if (isFull())
        {
            cout<<"no avalible place in queue\n";
        }
        else
        {
            rear = (rear +1) % max_size;
            arr[rear] = element;
            len++;
        }
    }
    int deleteElement()
    {
        int x = getfront();
        if (isEmpty())
        {
            cout<<"queue is empty\n";
        }
        else
        {

            front = (1+front)%max_size;
            len--;
            return x;
        }
    }
    int getfront()
    {
        return arr[front];
    }
    int getrear()
    {
        return arr[rear];
    }
    void display()
    {
        if (isEmpty())
        {
            cout<<"empty queue\n";
        }
        else
        {
            cout<<"queue:  "<<"[ ";
            for (int i = front; i != rear + 1; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<" ]"<<endl;

        }


    }
};

class Stack
{
private:
    Queue q;

public:
    Stack() : q(25){}
    bool empty()
    {
        return q.isEmpty();
    }
    int top()
    {
        return (q.isEmpty()) ? -1 : q.getrear();
    }
    void push(int item)
    {
        q.add(item);
    }
    void pop()
    {
        if (q.isEmpty())
        {
            cout<<"is empty \n";
        }
        else


            for (int i = 0; i < q.len; i++)
            {
                int x = q.deleteElement();
                if (i != q.len)
                    q.add(x);
            }
    }
    void print(){

        if (q.isEmpty())
        {
            cout<<"empty queue\n";
        }
        else
        {
            cout<<"Stack:  "<<"[ ";
            for (int i = q.rear; i >=q.front ; i--)
            {
                cout<<q.arr[i]<<" ";
            }
            cout<<" ]"<<endl;

        }

    }
};

int main()
{
    Stack s;
    s.push(8);
    s.push(7);
    s.push(15);
    s.push(17);
    s.push(25);
    s.push(55);
    s.print();
    cout << "TOP= "<<s.top() << endl;
    s.pop();
    s.print();
    cout << "TOP= "<<s.top() << endl;
    s.push(30);
    s.print();
    cout <<"TOP= "<< s.top() << endl;
    return 0;
}
//
