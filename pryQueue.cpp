#include <iostream>
#include <vector>
#include <ostream>
#include <string>
using namespace std;
template <class T>
class Node
{
public:
    int priority;
    T info;
    Node* next;
    Node() { next = NULL; }
};
template <class T>
class PriorityQueue 
{
private:
    Node<T>*frst;

public:
    PriorityQueue()
    {
        frst = NULL;
    }

    void insert(int item, int pri)
    {
        Node<T>* temp, * que;
        temp = new Node<T>();
        temp->info = item;
        temp->priority = pri;
        if (frst == NULL || pri < frst->priority)
        {
            temp->next = frst;
            frst = temp;
        }
        else
        {
            que = frst;
            while (que->next != NULL && que->next->priority <= pri)
                que = que->next;
            temp->next = que->next;
            que->next = temp;
        }
    }
    int getHighestPriority()
    {
        return (frst->info);
    }
    void deleteHighestPriority()
    {
        Node<T>* temp;
        temp = frst->next;
        frst = temp;
    }
    void print() {
        Node<T>* Temp = frst;
        while (Temp != NULL) {
            cout << Temp->info << " ";
            Temp = Temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue<int>a;
    a.insert(5,1);
    a.insert(87, 5);
    a.insert(4, 2);
    a.insert(10, 4);
    a.print();

    PriorityQueue<double>b;

    b.insert(5.2, 1);
    b.insert(87.1, 5);
    b.insert(4.9, 2);
    b.insert(10.8, 4);
    b.print();


    a.deleteHighestPriority();
    a.print();

    cout<<a.getHighestPriority();


    return(0);
}