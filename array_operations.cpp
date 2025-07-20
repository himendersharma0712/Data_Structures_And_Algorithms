// Traversal
// Search
// Insertion
// Deletion


#include <iostream>
using namespace std;


int main(){

    int arr[10] = {1,3,5,6,7,8,9,34,76,43};


    // traversal 
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    cout << endl;


// Search

//  Searching refers to finding an element in an array. For
//  searching the element, we first traverse the array and
//  while traversing, we compare each element of array with
//  the given element.


// Is 3,5,7, in array??

int arr2[3] = {3,5,7};

for(int i = 0; i < 10; i++){
    for(int j = 0; j < 3; j++){
        if(arr[i]==arr[j]){ // for each iteration of outer loop , it compares it to all 3 elements that need to be found
            cout << "\nFound " << arr[j] << "\n";
        }
    }
}

cout << endl << endl;

// Insertion 

//  Insertion into an array may be possible in two ways:
//  1. Insertion at the end
//  2. Insertion in between


// Case - 1

// In the first case, we have to set the array index to the total
//  number of elements and then insert the element. After
//  insertion, increase the total number of elements by 1.

int arr3[5] = {1,2};
int num_elem = 2;
int element;

cout << "Insert element at the end: ";
cin >> element;

// inserted the element at position 3 or index 2
arr3[num_elem] = element;
num_elem++;

for(int i = 0; i < num_elem; i++){
    cout << arr3[i] << " ";
}


// Case - 2
// we need to move each element one step to the right starting 
// from the end of the array up to the position
//  where we want to insert the new value 

// We're adding a new value at index 'pos' in an array with 'n' elements
// So we start at index 'n' (the next empty spot) and shift everything one step to the right
// We stop shifting when we reach the index right *after* the insertion point
// This creates a gap at 'pos' so we can insert the new value safely

int arr4[10] = {2,3,7,8,10,23};
int num_ele = 6;
int insert_at = 2;

int value = 4;

for(int i = num_ele; i > insert_at; i--) {
    arr4[i] = arr4[i - 1];  // move each element to the right
}

arr4[insert_at] = value;  // insert the new element at the desired position
num_ele++;  // update the size

cout << endl;

for(int i = 0; i < num_ele; i++)
{
    cout << arr4[i] << " ";
}


// Deletion 

//  Deletion from an array is possible in two ways:
//  1. Deletion of the last element
//  2. Deletion in between

int arr5[10] = {1,2,7,8,9,10};
int n = 6;
int del_elem = 10;

int pos = -1;

for(int i = 0; i < n; i++){
    if(arr5[i]==del_elem){
        pos = i;
        break;
    }
}

if(pos != -1){// which means we found the element

    for(int i = pos; i < n-1; i++){ // startin from the delete pos  // endin at one step left of last element
        arr5[i] = arr[i+1];       // start shifting/copying elements from right to left
    }

}

}

// The advantage of an array data structure is that:-

//  we can easily compute the address of the array through index and
//  also access the array element through index.

//  The disadvantage of the array is that:- 

//  we have to keep the total number of elements and array size. 

//  We cannot take elements more than the array size because 
//  array size is fixed. 

//  It also requires much processing in insertion and
//  deletion because of shifting of array elements.