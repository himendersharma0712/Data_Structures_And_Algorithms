#include <iostream>

using namespace std;







void min_max_array(){

    int arr[10] = {23,45,6,7,43,2,3,1,2,8};

    int min, max;

    min = max = arr[0];

    for(int i = 1; i < 10; i++){
        
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];
    }

    cout << "Minimum : " << min << "  Maximum: " << max;
}


void reverse_array(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i= 0; i < 10; i++){
        cout << arr[i] << "..";
    }

    cout << endl;

    int i , j, temp;

    // swapping elements
    for(i=0,j=9; i<j; i++, j--){    // 0 < 9, 1 < 8, 2 < 7, 3 < 6, 4 < 5
        temp = arr[i];              // loop runs 5 times and reverses the array
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int i= 0; i < 10; i++){
        cout << arr[i] << "..";
    }


}

void square_arr(int arr[]){

    for(int i = 0; i < 3; i++){
        arr[i] = arr[i] * arr[i];
    }
}


void add_matrices(){

    int A [3][3] = {{1,2,3}, {3,2,1}, {1,0,1}};
    int B [3][3] = {{1,23,3}, {3,3,1}, {1,0,1}};
    int C [3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int input[][2], int output[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            output[j][i] = input[i][j];
        }
    }
}


void mul_matrices(){

    int A[3][2] = {{1,2},{2,3},{3,2}};
    int B[2][3] = {{1,2,3}, {3,4,5}};

    int C[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            C[i][j] = 0;

            for(int k = 0; k < 2; k++) // k is the number of elements to be multiplied ... here 2 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){

    // declaring array
    int arr[5];

    // reading into array
    // for(int i = 0; i < 5; i++){
    //     cin >> arr[i];
    // }

    int arr_new[5] = {1,2,3,5,7};

    // displaying array elements
    // for(int i = 0; i < 5; i++){
    //     cout << arr_new[i] << " ";
    // }

    int a[3] = {1,2,3};
    int b[3] = {11,22,33};

    // copying an array 
    for(int i = 0; i < 3; i++){
        b[i] = a[i];
    }


    // min_max_array();


    // reverse_array();


    // square_arr(a);

    // for(int i = 0; i < 3; i++){
    //     cout << a[i] << "..";
    // }


    // add_matrices();

    mul_matrices();

}




