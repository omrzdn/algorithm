#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Next, *Prev;

    Node(int data)
    {
        Data = data;
        Next = Prev = NULL;
    }
};

class LinkedList
{
    Node *Head, *Tail;
    int counter=0;

public:

    LinkedList()
    {
        Head = Tail = NULL;
    }

    void Add(int data){

        Node *newNode = new Node(data);

        if(Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->Next = newNode;
            newNode->Prev = Tail;
            Tail = newNode;
        }
        counter++;
        cout << counter << endl;
    }

    void Display()
    {
        Node *current = Head;

        while(current != NULL)
        {
            cout << current->Data << "\t";
            current = current ->Next;
        }
        cout << "\n";
    }

    void Delete(int data)
    {
        Node *pDelete = Search(data);

        if(pDelete == NULL)
            return;

        if(pDelete == Head)
        {
            if(pDelete == Tail)
            {
                Head = Tail = NULL;
            }
            else
            {
                Head = Head->Next;
                Head->Prev = NULL;
            }
        }
        else if(pDelete == Tail)
        {
            Tail = Tail->Prev;
            Tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next;
            pDelete->Next->Prev = pDelete->Prev;
        }

        delete pDelete;
    }

    void sort(){

        int nodeCtr;
        int ctr;
        int nodeDataCopy;
        Node *currentNode;
        Node *nextNode;

        for(nodeCtr = counter -2; nodeCtr >=0; nodeCtr--){

            currentNode = Head;
            nextNode = currentNode->Next;

            for(ctr=0; ctr <= nodeCtr; ctr++){

                if(currentNode->Data > nextNode->Data){

                    nodeDataCopy = currentNode->Data;
                    currentNode->Data = nextNode->Data;
                    nextNode->Data = nodeDataCopy;
                }

                currentNode = nextNode;
                nextNode = nextNode->Next;
            }
        }
    }

private:
    Node* Search(int data)
    {
        Node *current = Head;

        while(current != NULL)
        {
            if(current->Data == data)
            {
                return current;
            }

            current = current->Next;
        }

        return NULL;
    }
};


int main()
{
    LinkedList lnkdlst;

    lnkdlst.Add(3);
    lnkdlst.Add(11);
    lnkdlst.Add(5);
    lnkdlst.Add(1);
    lnkdlst.Add(9);
    cout << "\n******************" << endl;

    cout << "Nodes before sorting: \t"; lnkdlst.Display();

    lnkdlst.sort();
    cout << "Nodes After sorting : \t";lnkdlst.Display();

    return 0;
}
