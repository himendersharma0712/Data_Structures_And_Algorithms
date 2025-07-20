#include <iostream>
#include <iomanip>
using namespace std;



int shift_elements_left(){

    int arr[10] = {2,7,1,45,67,90,4,53,8,10};

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    int temp = arr[0];

    for(int i = 1; i < 10; i++){
        arr[i-1] = arr[i]; // every next element goes to the previous element's place
    }

    // finally place the last element at the end
    arr[9] = temp;

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    return 1;
}

void example_1(){

//  Write a program that scans a one-dimensional array from
//  left to right and compares all adjacent elements. Any two
//  adjacent elements arr[j] and arr[j+1] should be exchanged if
//  arr[j] is greater than arr[j+1]. This procedure will always place
//  the biggest element at the last position. Count the total
//  number of exchanges done.


int arr[5] = {34,10,2,99,1};

int temp = -1;
int exchanges = 0;

for(int j =0; j < 5; j++)
{
    cout << arr[j] << " ";
}

cout << endl;

for(int j =0; j < 4; j++)
{
    if(arr[j] > arr[j+1]){
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        exchanges++;
    }
}

for(int j =0; j < 5; j++)
{
    cout << arr[j] << " ";
}

cout << endl << "exchanges: " << exchanges;


}

void printPascal(int n) {
    int arr[50][50]; // adjust if u wanna go crazier

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    cout << "Pascal triangle:\n";
    for(int i = 0; i < n; i++) {
        cout << setw((n - i) * 2);
        for(int j = 0; j <= i; j++)
            cout << setw(5) << arr[i][j];
        cout << "\n";
    }
}


int main(){

    // shift_elements_left();

    example_1();

    printPascal(7);
}