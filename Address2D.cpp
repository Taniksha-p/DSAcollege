// address_2d_array.cpp
#include <iostream>
using namespace std;

template<typename T>
T* calculateAddress(T* base, int row, int col, int i, int j, bool rowMajor) {
    if (rowMajor) {
        return base + (i * col + j);
    } else {
        return base + (j * row + i);
    }
}

int main() {
    int arr[3][4];
    int base = (int)&arr;
    int i = 2, j = 3;
    bool rowMajor = true;
    int* address = calculateAddress(arr[0], 3, 4, i, j, rowMajor);
    cout << "Address of element at (" << i << ", " << j << ") is: " << address << endl;
    return 0;
}
