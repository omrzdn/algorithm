#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node *next;
};

class Queue {
public:
    Node * front = NULL;
    Node * rear = NULL;
    void enQueue(int Data){

        Node * newnode = new Node;
        newnode->data = Data;
        newnode->next = NULL;

        if (front == NULL){

            front = rear = newnode;
        }else{

            rear->next = newnode;
            rear = newnode;
        }
    };
    void deQueue(){

        if(rear == NULL){
        cout << "queue is empty now" <<endl;
        }else if (front == rear){

            Node * ptr = front;
            front = rear = NULL;
            delete(ptr);

        }else{

            Node * ptr = front;
            front = front->next;
            delete(ptr);
        }
    };
    int peek(){

         if(rear == NULL){
        cout << "queue is empty now" <<endl;
        return -1;
        }else
            return front->data;

    };
};
int main()
{
    Queue q;

    q.enQueue(8);
    q.enQueue(6);
    q.enQueue(5);
    q.enQueue(2);
    q.enQueue(74);
    cout << q.peek() << endl;

    q.deQueue();
    cout << q.peek() << endl;

    q.deQueue();
    cout << q.peek() << endl;

    return 0;
}
