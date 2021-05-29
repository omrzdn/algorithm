#include <iostream>

using namespace std;

class Queue
{
    int *arr;
    int size, front, rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void EnQueue(int data)
    {
        if(IsFull())
        {
            cout << "Queue is full";
            return;
        }

        rear++;
        arr[rear] = data;

        if(IsEmpty())
        {
            front++;
        }
    }

    int DeQueue(int &data)
    {
        if(IsEmpty())
        {
            return 0;
        }
        else
        {
            data = arr[front];
            Shift();
        }
    }

    int IsEmpty()
    {
        return front == -1 || (front > rear);
    }

    int IsFull()
    {
        return rear == size - 1;
    }

private:
    void Shift()
    {
        for(int i =0; i<rear; i++){

            arr[i] = arr[i+1];
        }
        rear--;
    }
};

int main()
{
    Queue que(5);
    que.EnQueue(5);
    que.EnQueue(7);
    que.EnQueue(71);


    int data;
    que.DeQueue(data);

    cout << data <<endl;
    return 0;
}
