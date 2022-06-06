#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int len;
    int *arr;
    int max_size;
public:
    Queue(){
        max_size = 101;
        front = 0;
        rear =max_size -1;
        len=0;
        arr = new int[max_size];

    }
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
int calculate_time(vector <int> &vec ,int k){
    Queue q;
    int tmp;
    int time =0;
    for (int i = 0; i < vec.size(); i++)
    {
        q.add(vec[i]);
    }
    q.display();
    cout<<"we want time of position: "<<k<<"\n";
    while (vec[k]>0)
    {
        cout<<"Iteration: ";
        for ( int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > 0)
            {
                tmp = q.deleteElement();
                tmp--;
                cout<<tmp<<" ";
                vec[i] = tmp;
                time++;

            }
            if (vec[i] > 0)
            {
                q.add(vec[i]);

            }
        }
        cout<<endl;
    }
    return time;

}
int main(){
    vector <int> tickets1 = {2,3,2};
    cout<<"Time of test case 1 = "<<calculate_time(tickets1,2)<<"\n________________________________________________\n\n";
    vector <int> tickets2 = {5,1,1,1};
    cout<<"Time of test case 2 = "<< calculate_time(tickets2,0)<<"\n________________________________________________\n\n";
    vector <int> tickets3 = {5,4,3,2};
    cout<<"Time of test case 3 = "<<calculate_time(tickets3,1)<<"\n________________________________________________\n\n";
    vector <int> tickets4 = {55,10,15,25,5};
    cout<<"Time of test case 3 = "<<calculate_time(tickets4,4)<<"\n_____________________________________________\n\n";
    return 0;
}