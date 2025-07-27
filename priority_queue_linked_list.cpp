

// In a priority queue, every element of the queue has some priority, 
// and it is processed based on this priority.


//  There are two ways of implementing a priority queue:

//  Through queue: In this case, insertion is simple because
//  the element is simply added at the rear end as usual. For
//  performing deletion, first the element with highest
//  priority is searched and then deleted.


//  Through sorted list: In this case, insertion is costly
//  because the element is inserted at the proper place in
//  the list based on its priority. Here, deletion is easier
//  since the element with the highest priority will always
//  be in the beginning of the list.


#include <iostream>
using namespace std;


class Node
{
    public:
        int info;
        int priority;
        Node * link;

        Node(int data, int priority)
        {
            info = data;
            this->priority = priority;
            link = nullptr;
        }
};

class PriorityQueue
{
    private:

    Node * front;

    public:

        PriorityQueue();
        bool isEmpty();
        void enqueue(int data, int priority);
        int dequeue();
        int peek();
        void display();
        int size();
};



PriorityQueue::PriorityQueue()
{
    front = nullptr; //  front will be nullptr in the beginning
}


void PriorityQueue::enqueue(int data, int priority)
{
    Node *temp, *ptr;

    temp = new Node(data,priority);


    // first we check if the queue is empty OR 
    // if the new element has a higher priority than the front element
    // then it becomes the new front element
    if( isEmpty() || (priority < (front->priority)))
    {
        temp->link = front; // link temp to node pointed to by front 
        front = temp; // front becomes temp 
    }

    else{
        ptr = front;
        
        // searching for the element/node with priority lower than our given element
        // like 4 is greater than 3 but 3 is higher priority and 4 is lower.
        // also we end up with the node before the low priority node we found coz of ptr->link 
        while (ptr->link != nullptr && ptr->link->priority <= priority)
        {
            ptr = ptr->link; // traversal
        }

        // after findin an element of priority lower than given element

        temp->link = ptr->link; // point to next node which is lower in priority than our node
        ptr->link = temp; // the node previous to the low priority node found is pointed to our new node now
        // this puts in the queue appropriately

    }


}

