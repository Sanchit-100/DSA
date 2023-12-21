#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int max_size, curr_size, front, rear;

public:
    
    queue(int given_size = 5)
    {
        arr=new int[given_size];
        max_size=given_size;
        curr_size = 0;
        front = 0;
        rear = max_size - 1;
    }

    bool empty()
    {
        return curr_size == 0;
    }

    bool full()
    {
        return curr_size == max_size;
    }
    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % max_size;
            arr[rear] = data;
            curr_size++;
        }
    }

    int front_ele()
    {
        return arr[front];
    }

    void pop()
    {
        front = (front + 1) % max_size;
        curr_size--;
    }
};

int main()
{
    queue Q;
    for(int i=0;i<6;i++){
        Q.push(i);
    }

    Q.pop();
    Q.push(10);
    Q.push(11);
    while(!Q.empty()){
        cout<<Q.front_ele()<<" ";
        Q.pop();
    }
    Q.pop();
    return 0;
}