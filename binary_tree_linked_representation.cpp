#include <iostream>
using namespace std;



// Node: each element in a tree

// Edge: line connecting two nodes

// Parent Node: direct predecessor of a node

// Child Node: direct successor of a node

// Root Node: topmost node with no parent

// Leaf Node: node with no children

// Level: distance from root (root is level 0)

// Height: total number of levels in the tree

// Siblings: nodes sharing the same parent

// Path: route from one node to another

// Ancestor: a node on the path to a descendant

// Descendant: a node under another node in the tree

// Subtree: part of the tree starting from any node

// Degree: number of children a node has

// Degree of Tree: highest degree among all nodes

// Forest: set of separate trees formed by removing root Nodes in the binary tree


class Node
{
public:
    char info;

    Node *lchild; // left child node

    Node *rchild; // right child node

    Node(char data)
    {
        info = data;
        lchild = nullptr;
        rchild = nullptr;
    }
};

// for all leaf nodes, there are no children nodes hence, left and right
// node ptrs are nullptrs

// if a node has only a left child , then rchild is nullptr and vice versa.

// To access the nodes of the tree, we will maintain a data
//  member pointer in the class of binary tree, that will point to
//  the root node of the tree

class BinaryTree
{
private:

    Node *root;

    // traversal methods
    void preorder(Node *ptr);

    void postorder(Node *ptr);

    void inorder(Node *ptr);

    int height(Node *ptr);

    void display(Node *ptr, int level);

    Node *construct(char *in, char *pre, int num);

    Node *construct_1(char *in, char *post, int num);

public:

    BinaryTree();
    ~BinaryTree();

    bool isEmpty();
    void createTree();

    void preorder();
    void inorder();
    void postorder();
    void levelOrder();

    int height();

    void nrecPreorder();
    void nrecInorder();
    void nrecPostorder();

    void construct(char *in, char *pre);
    void construct1(char *in, char *post);

    void display();
};


void BinaryTree::createTree()
{
    root = new Node('P');

    root->lchild = new Node('Q');
    root->rchild = new Node('R');

    root->lchild->lchild = new Node('A');
    root->lchild->rchild = new Node('B');

    root->rchild->rchild = new Node('F');

    //    Q <- P -> R
    //      A <-  Q -> B
    //      NULL  <-  R -> F
}

BinaryTree::BinaryTree()
{
    root = nullptr; // root node is null
}


// Every traversal consists of :
// visiting the root
// visiting the left subtree
// visiting the right subtree

// Hence, there are 3! ways of traversing. 

// but if we follow convention of traversing the Left subtree before right
// We are left with only 3, namely:
// Preorder (NLR)
// Inorder (LNR)
// Postorder (LRN)

// where L = left subtree, R = right subtree, N = root node


//  If we implement
//  them recursively, then an implicit stack is used, and if we
//  implement them non-recursively then we have to use an
//  explicit stack.


// NLR
void BinaryTree::preorder(Node * ptr)
{
    if(ptr == nullptr)
    {
        return;
    }

    cout << ptr->info << " "; // root node

    preorder(ptr->lchild); // left child

    preorder(ptr->rchild); // right child
}


// LNR
void BinaryTree::inorder(Node * ptr)
{
    if(ptr == nullptr)
    {
        return;
    }

    inorder(ptr->lchild);

    cout << ptr->info << " ";

    inorder(ptr->rchild); 

}


// LRN
void BinaryTree::postorder(Node * ptr)
{
    if(ptr == nullptr)
    {
        return;
    }

    postorder(ptr->lchild);

    postorder(ptr->rchild); 

    cout << ptr->info << " ";

}

// these private functions will be used by the public ones
void BinaryTree::preorder()
{
    preorder(root);

    cout << "\n";
}

void BinaryTree::inorder()
{
    inorder(root);

    cout << "\n";
}

void BinaryTree::postorder()
{
    postorder(root);

    cout << "\n";
}

BinaryTree::~BinaryTree()
{
    
}

int main(){

    BinaryTree tree;

    tree.createTree();

    tree.preorder();
}