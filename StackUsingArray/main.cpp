#include <iostream>

using namespace std;

class Stack
{
    int *arr;
    int size, top;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void Push(int data)
    {
        if(top < size -1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack is full";
        }
    }

    int Pop(int &data)
    {
        if(!IsEmpty())
        {
            data = arr[top];
            top--;

            return 1;
        }
        else
        {
            return 0;
        }
    }

    int Peek()
    {

    }

    int IsEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack stk(9);

    stk.Push(3);
    stk.Push(5);
    stk.Push(7);
    stk.Push(9);
    int data;

    int result = stk.Pop(data);

    if(result == 1)
    {
        cout << data;
    }
    else
    {
        cout << "Stack is empty";
    }

    return 0;
}
