#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *link;

    Node(int data)
    {
        info = data;
        link = NULL;
    }
};

class SingleLinkedList
{

private:
    Node *start;

public:
    SingleLinkedList();

    SingleLinkedList(const SingleLinkedList &list);

    ~SingleLinkedList();

    bool isEmpty();

    void display();

    int size();

    int find(int data);

    // Insertion operations
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertBefore(int data, int nodeData);
    void insertAfter(int data, int nodeData);
    void insertAtPosition(int data, int position);
    void insertInEmpty(int data);

    // Deletion operations
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteNode(int nodeData);
    void deleteAtPosition(int position);
};


// Operations to be performed on linked list:- 
// traversal
// searching
// insertion
// deletion
// creation
// reversal 

SingleLinkedList::SingleLinkedList(){
    start = nullptr; // start will point to null because no elements at declaration
}

bool SingleLinkedList::isEmpty(){
    return(start==nullptr); // if start is null, list is empty
}


// traversal of a linked list
void SingleLinkedList::display(){

    Node * ptr; // using it for traversal

    if(!isEmpty()){ // if start is not null 
        ptr = start; // point to start
        while(ptr != nullptr){
            cout << ptr->info << endl;  
            ptr = ptr->link; // keep assigning to next link till it is null
        }
    }

    else{
        cout << "List is empty";
    }
}


// Note: Do not think of using start for moving forward. If we use start = start->link,
//  instead of ptr = ptr->link, then we will lose start and
//  that is the only means of accessing our list.


// searching

int SingleLinkedList::find(int nodeData){

    Node * ptr = start; // start from first node

    int position = 0;

    while(ptr != nullptr){
        position++;

        if(ptr->info == nodeData){
            return position; // if data found then return
        }

        ptr = ptr->link; // for traversal
    }

    return 0;
}


// Insertion in a Linked List :-
//  Insertion at the beginning.
//  Insertion in an empty list.
//  Insertion at the end.
//  Insertion in between the list nodes


void SingleLinkedList::insertAtBeginning(int data){

    Node * temp; // temp node 
    temp = new Node(data); // add data to node
    
    if(!isEmpty){ // start should not be null for insertion
        temp->link = start; // temp points to the first node
        start = temp; // start points to temp
    }
}

void SingleLinkedList::insertInEmpty(int data){

    Node * temp = new Node(data);
    if(start == nullptr){ // if start points to no node
        start = temp; // point start to this new node
        temp->link = nullptr; // point the link to null, because now more nodes
    }
}


void SingleLinkedList::insertAtEnd(int data){

    Node * temp, *ptr;

    temp = new Node(data); // creating a new node

    if(isEmpty()){ // if list is empty
        start = temp; // make start point to first node
    }

    else{

        ptr = start; // traversal ptr points to start 

        while(ptr->link != nullptr){ // when a node has a nullptr link exit the loop
            ptr = ptr->link;         // coz you found the last node
        }

        ptr->link = temp; // make the last node point to ur new node
    }
}


// Insertion after a node 
void SingleLinkedList::insertAfter(int new_data, int nodeData){
    Node *ptr, *temp;

    ptr = start; // ptr points to start which points to first node

    if(isEmpty()){
        cout << "list is empty\n"; // if list is empty
    }

    else{

        while(ptr != nullptr){ // if ptr is not a nullptr

            if(ptr->info == nodeData){ // find the node using the data

                temp = new Node(new_data); // create a new node
                temp->link = ptr->link; // make this new pointer point to the node after the node we found
                ptr->link = temp; // make the found ptr point to the temp ptr we created
                break; // now temp node is in between the found node and the next node
            }

            ptr = ptr->link; // for traversing and finding the desired node after which a new node is to be inserted
        }

        if(ptr == nullptr){ // if start is null 
            cout << "Item " << nodeData << "is not in the list\n";
        }
    }
}
