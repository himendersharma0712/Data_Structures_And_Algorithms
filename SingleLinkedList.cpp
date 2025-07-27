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
    
    if(!isEmpty()){ // start should not be null for insertion
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



// Insertion before a node
void SingleLinkedList::insertBefore(int new_data, int nodeData){
    Node *ptr, *temp;

    ptr = start; // ptr points to start which points to first node

    if(isEmpty()){
        cout << "list is empty\n"; // if list is empty
    }

    else if (ptr->info == nodeData){ // nodeData is in first node

        temp = new Node(new_data);
        temp->link = ptr; // temp linked to the first node
        start = temp; // start points to temp

        // start -> temp(new node) -> null
    }

    else{

        while(ptr->link != nullptr){

        if(ptr->link->info == nodeData){ // compare the data value of the node 
                                        // before which we need to insert the new node
            temp = new Node(new_data);
            temp->link = ptr->link; // point the new node to the node before which this new node will be inserted
            ptr->link = temp; // the node previous to the desired node points to the new temp node
            break;

            // node 1 -> new node -> desired node
        }

        ptr = ptr->link; // traversal

        }
    }

    if(ptr->link == nullptr){
        cout << "Item " << nodeData << " is not in the list.\n";
    }

}



// Insertion in between two nodes
void SingleLinkedList::insertAtPosition(int data, int position){
    Node * ptr, *temp;

    if(position == 1){
        temp = new Node(data);
        temp->link = start; // temp points to the node which start was pointing to
        start = temp; // start points to temp now i.e. temp is the new start
    } // finally its insertion at head


    else{

        ptr = start; // ptr points to first node

        int index = 1;

        while (ptr != nullptr && index < position-1)
        {
            ptr = ptr->link; // traversal from node to node
            index++; // counting nodes' index
        }


        if(ptr != nullptr && position > 0)
        {
            temp = new Node(data);
            temp->link = ptr->link;
            ptr->link = temp;
        }

        else
        {
            cout<< "Item cannot be inserted at position :" << position << endl;
        }
    }
}



void SingleLinkedList::deleteAtBeginning(){

    Node * temp;

    if(isEmpty()){
        cout << "List is empty" << endl;
    }

    else{

        temp = start; // temp points to first node which was pointed to by start
        start = start->link; // now start points to the next node as start->link gives the first node's link to second
        delete temp; // we delete the first node
    }
}


void SingleLinkedList::deleteNode(int nodeData)
{

    Node  *ptr, *temp;

    ptr = start;

    if(isEmpty()){
        cout << "List is Empty 💀" << endl;
    }

    else if (ptr->info == nodeData) // start points to the node which is to be deleted i.e.
    {                               // the first node in this case
        temp = ptr; // capture first node in ptr
        start = ptr->link; // start points to the node next to first node
        delete temp; 
    }

    else
    {
        while (ptr->link != nullptr)
        {
            if(ptr->link->info == nodeData){ // stop if you find the node before the desired node
                break;   // ptr->link->info means the value stored by next node
            }

            ptr = ptr->link; // traversal ofc

        }

        if(ptr->link == nullptr){
            cout << nodeData << " not found in the list 😖"<<endl;
        }

        else
        {
            temp = ptr->link; // point to the next node which is the node to be deleted
            ptr->link = ptr->link->link; // the node which we stopped at points to the node next to the deleted node
            delete temp; 
        }
        
    }

}



