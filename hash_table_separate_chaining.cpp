#include <iostream>
#include <string>
using namespace std;


// Hash Table is a data structure that stores key-value pairs using an array and a hash function to determine the index (bucket) for each key.

// Hash Function maps a key to an integer index in the array; for example, index = key % tableSize.

// In separate chaining, each array index holds a linked list to handle collisions (when multiple keys hash to the same index).

// When inserting or searching, we hash the key to find the right list (bucket), then traverse that list to locate the key.

// This technique offers average-case O(1) time complexity for insert, search, and delete, assuming a good hash function and low collision rate.


static const int maxSize = 11;


// Employee class key-value pair
class Employee{
    int id;
    string name;

    public:

    Employee(): id(0),name("") {}
    Employee(int i, string n): id(i), name(n) {}
    int getEmployeeId() const {return id;}

    friend ostream& operator<<(ostream& os, const Employee& e)
    {
        os << "[" << e.id << ", " << e.name << "]";
        return os;
    }

};


// node for chaining
class Node{

public:
    Employee info;
    Node * link;

    Node(Employee data){
        info = data;
        link = nullptr;
    }
};

// for actual chain of nodes
class SingleLinkedList{

    private:
        Node * start;

    public:
        SingleLinkedList();
        ~SingleLinkedList();
        bool isEmpty();
        void display();
        Node * search(int key);
        void insertAtBeginning(Employee data);
        bool deleteNode(int key);
};

SingleLinkedList::SingleLinkedList()
{
    start = nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
    Node * ptr;
    while(start != nullptr)
    {
        ptr = start->link; // ptr points to second node
        delete start; // first node deleted
        start = ptr; // start points to second node
    }
}


bool SingleLinkedList::isEmpty(){
    return start==nullptr;
}

void SingleLinkedList::display()
{
    Node * ptr = start;

    if(!isEmpty())
    {
        while(ptr!=nullptr)
        {
            cout << ptr->info << "-->";
            ptr = ptr->link;
        }

        cout << "NULL\n";
    }

    else{
        cout << "List is Empty\n";
    }
}


Node * SingleLinkedList::search(int key)
{
    Node * ptr = start;
    while(ptr != nullptr)
    {   // if key matches employee id then return the ptr to that employee
        if(ptr->info.getEmployeeId() == key)
            return ptr;
        ptr = ptr->link; // for traversal 
    }

    return nullptr;
}


void SingleLinkedList::insertAtBeginning(Employee data)
{
    Node * temp = new Node(data);
    if(!isEmpty())
    {
        temp->link = start;
    }
    start = temp;

}


bool SingleLinkedList::deleteNode(int key)
{
    Node* ptr = start;
    Node* temp;

    if (isEmpty())
        return false;

    if (ptr->info.getEmployeeId() == key) {
        temp = ptr;
        start = ptr->link;
        delete temp;
        return true;
    }

    while (ptr->link != NULL) {
        if (ptr->link->info.getEmployeeId() == key)
            break;
        ptr = ptr->link;
    }

    if (ptr->link == NULL)
        return false;

    temp = ptr->link;
    ptr->link = ptr->link->link;
    delete temp;
    return true;
}


// HashTable

class HashTable{

    private:
        SingleLinkedList * arr; // array of SingleLinkedLists
        int m; // table size
        int n; // no of records
        int hash(int key);
    
    public:
        HashTable();
        ~HashTable();
        void insert(Employee emp);
        bool search(int key);
        void del(int key);
        void display();
};



HashTable::HashTable()
{
    m = maxSize;
    n = 0;
    arr = new SingleLinkedList[m];
}


HashTable::~HashTable()
{
    delete[] arr;
}

// hash function to hash items
int HashTable::hash(int key)
{
    return key % m;
}


bool HashTable::search(int key)
{
    int h = hash(key); // calculate hash value for key
    Node * ptr = arr[h].search(key); // make a ptr to the object to be found
    if(ptr!=nullptr)
    {
        cout << "Found: " << ptr->info << "\n";
        return true;
    }
    return false;
}

void HashTable::insert(Employee emp)
{
    int key = emp.getEmployeeId();
    int h = hash(key);
    if(search(key))
    {
        cout << "Duplicate key\n";
        return;
    }
    // new value at an empty hash place , so insert at beginning
    arr[h].insertAtBeginning(emp); 
    n++; // no of records + 1
}

void HashTable::del(int key)
{
    int h = hash(key);

    if(arr[h].deleteNode(key))
    {
        n--;
    }

    else{
        cout << "Key " << key << " not found\n";
    }
}


void HashTable::display()
{
    for(int i = 0; i < m ; i++)
    {
        cout << "[" << i << "] --> ";
        if(!arr[i].isEmpty())
        {
            arr[i].display();
        }
        else{
            cout << "___\n";
        }
    }
}


int main()
{
    HashTable table;
    table.insert(Employee(15, "Bob"));
    table.insert(Employee(21,"Mary"));
    table.insert(Employee(1,"Astor"));
    table.insert(Employee(212,"Dean"));
    table.insert(Employee(31,"Sam"));
    table.insert(Employee(27,"John"));


    table.display();

    cout << (table.search(15) ? "Key found" : "Key not found") << "\n";
    table.del(15);
    cout << (table.search(15) ? "Key found" : "Key not found") << "\n";

    table.display();

    return 0;
}