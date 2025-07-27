#include <iostream>
using namespace std;

//  the doubly linked list or
//  two-way list, in which each node has two pointers. One of
//  these pointers points to the next node and the other points
//  to the previous node.


class Node
{
    public:

    int info;

    Node * prev;

    Node * next;

    Node(int data)
    {
        info = data;
        prev = nullptr;
        next = nullptr;
    }
};

// prev is a pointer that will contain the address of the
//  previous node and next will contain the address of the next
//  node in the list. 

// So, we can move in both directions at any
//  time. The next pointer of last node and prev pointer of first
//  node are NULL.


class DoublyLinkedList
{
    private:
        Node * start;

    public:

        DoublyLinkedList();
        DoublyLinkedList(DoublyLinkedList &list);
        DoublyLinkedList &operator=(DoublyLinkedList &list);
        ~DoublyLinkedList();

        bool isEmpty();
        void display();
        int size();
        int find(int data);

        // Insertion 
        void insertAtBeginning(int data);
        void insertAtEnd(int data);
        void insertBefore(int data, int nodeData);
        void insertAfter(int data, int nodeData);
        void insertAtPosition(int data, int position);

        // Deletion
        void deleteAtBeginning();
        void deleteAtEnd();
        void deleteNode(int nodeData);
        void deleteAtPosition(int position);

        // reversal 
        void reverse();
};



//  Traversal of a doubly linked list
//  Searching an element
//  Insertion of an element
//  Deletion of an element
//  Creation of a doubly linked list
//  Reversal of a doubly linked list


bool DoublyLinkedList::isEmpty()
{
    return (start == nullptr);
}


void DoublyLinkedList::display()
{

    Node * ptr;

    if(!isEmpty())
    {
        ptr = start;

        while(ptr != nullptr)
        {
        cout << ptr->info << endl;
        ptr = ptr->next;
        }
    }

    else
    {
        cout << "list is empty" << endl;
    }

}


int DoublyLinkedList::size()
{
    Node * ptr;

    int count = 0; 

    ptr = start;

    while(ptr != nullptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}



void DoublyLinkedList::insertAtBeginning(int data)
{

    Node * temp;

    temp = new Node(data);

    if(!isEmpty())
    {
        temp->next = start; // temp points next to first node
        start->prev = temp; // a prev link from first node to new node
    }

    start = temp; // new node's address is given to start

}


void DoublyLinkedList::deleteAtBeginning()
{

    Node * temp;

    if(isEmpty())
    {
        cout << "List is empty\n";
    }

    else
    {
        temp = start; // temp points to first node using start

        if(start->next == nullptr) // if we have only one node
        {
            start = nullptr; // start is null now
        }

        else
        {
            start = start->next; // start points to the next node 
            start->prev = nullptr; // prev is null coz now this next node is the first node
        } 

        delete temp;
    }
}