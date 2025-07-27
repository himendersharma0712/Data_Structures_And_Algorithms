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


class Stack
{
    private:
        Node *top;

    public:
        Stack();
        bool isEmpty();
        void push(int data);
        int pop();
        int peek();
        void display();
        int size();

};


Stack::Stack()
{
    top = nullptr; // empty stack
}

bool Stack::isEmpty()
{
    return (top == nullptr); //check if top is null
}


void Stack::push(int data)
{
    Node * temp = new Node(data);

    if(!isEmpty())
    {
        temp->link = top; // point to the first node 
        top = temp;
    }

    else{
    top = temp; // else top was empty so top points to the new node
    }
}


int Stack::pop()
{
    Node * temp;

    int val;

    if(isEmpty())
    {
        throw("Stack is empty!");
    }

    else
    {
        val = top->info; // get the value of the top tray of the stack 
        temp = top; // catch the first tray in temp
        top = top->link; // point the top tray to the tray below
        delete temp; 
    }

    return val;

}


int Stack::peek()
{
    if(isEmpty())
    {
        throw("Stack is empty");
    }

    return top->info; // return the value of the top
}



void Stack::display()
{
    Node * ptr;

    if(!isEmpty())
    {
        ptr = top; // start from top

        while (ptr != nullptr)
        {
            cout << ptr->info << endl;
            ptr = ptr->link; // for traversing below the stack
        }
        
    }

    else
    {
        throw("Stack is empty");
    }
}


int Stack::size()
{
    Node * ptr;

    int count = 0;

    ptr = top;

    while(ptr != nullptr)
    {
        count++;
        ptr = ptr->link;
    }

    return count;
}



int main(){


    Stack mystack;

    
    // mystack.display(); // throws exception


    
    mystack.push(1);
    mystack.push(15);
    mystack.push(156);
    mystack.push(5);
    mystack.push(189);
    

    mystack.pop();

    mystack.display();

    cout << "peeking 🔍 found: " << mystack.peek();

    cout << "\nThe size of stack is " << mystack.size();

}