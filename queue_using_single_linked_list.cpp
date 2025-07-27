#include <iostream>
using namespace std;



class Node
{

    public:

        int info;

        Node * link;

        Node(int data)
        {
            info = data;
            link = nullptr;
        }

};


// Plan for implementation

// We use two pointers: front and rear 

// To enqueue we insert a node at the end of the list

// To dequeue we delete a node from the beginning of the list 


class Queue
{
    private:

        Node * front;
        Node * rear;

    public:

        Queue();

        bool isEmpty();

        void enqueue(int data);

        int dequeue();

        int peek();

        void display();

        int size();
};


Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

bool Queue::isEmpty()
{
    return (front == nullptr); // front and rear both point to same element which is null so we checkin only front
}

void Queue::enqueue(int data)
{
    Node * temp;

    temp = new Node(data);

    if(isEmpty()) // empty queue
    {
        front = temp; // add it to front as only one element present
    }

    else{
        rear->link = temp; // add it to the end of queue
    }

    rear = temp; // to set the rear to new node 

    // Hint: try drawing a node diagram for a queue using single linked list
}


int Queue::dequeue()
{
    Node * temp;

    int val;

    if(isEmpty())
    {
        throw("Queue is empty");
    }


    else
    {
        val = front->info; // capture the value of the front node

        temp = front; // capture front node

        front = front->link; // make the next node the front node

        delete temp; //  obliterate the former front node
    }

    return val;
}

int Queue::peek()
{
    if(isEmpty())
    {
        throw("Queue is empty");
    }

    return front->info; // just return the val of front node
}


void Queue::display()
{
    Node * ptr;

    if(!isEmpty())
    {
        ptr = front; // start at front node

        while(ptr != nullptr)
        {
            cout << ptr->info << endl;
            ptr = ptr->link;
        }
    }


    else
    {
        cout << "Queue is empty\n";
    }
}


int Queue::size()
{
    Node * ptr;

    int count = 0;

    ptr = front;

    while(ptr != nullptr)
    {
        count++;
        ptr = ptr->link;
    }

    return count;
}


int main(){

    Queue myQ;

    myQ.enqueue(12);
    myQ.enqueue(152);
    myQ.enqueue(1222);
    myQ.enqueue(1552);
    myQ.enqueue(122122);


    myQ.display();

    myQ.dequeue();
    myQ.dequeue();


    cout << "\nAfter dequeuing" << endl;

    myQ.display();

    cout << "\nQueue is size: " << myQ.size();

}
