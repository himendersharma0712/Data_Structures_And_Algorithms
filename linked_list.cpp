#include <iostream>
using namespace std;

struct node{

    string name;
    node * next;
};

typedef node * node_ptr;

void insert_node_at_head(node_ptr & head, string name){

    node_ptr temp;
    temp = new node;
    temp->name = name;
    temp->next = head;
    head = temp;
}


int main(){

    node_ptr headnode = new node;
    headnode->name = "Ashley";
    headnode->next = nullptr;

    insert_node_at_head(headnode,"Max");
    insert_node_at_head(headnode,"Sax");
    insert_node_at_head(headnode,"Fax");
    insert_node_at_head(headnode,"Tax");

    node_ptr tmp;
    tmp = headnode;

    while(tmp != nullptr){
        cout << tmp->name << endl;
        tmp = tmp->next;
    }


}