// address_3d_array.cpp
#include <iostream>
using namespace std;

template<typename T>
T* calculateAddress(T* base, int dim1, int dim2, int dim3, int i, int j, int k, bool rowMajor) {
    if (rowMajor) {
        return base + (i * dim2 * dim3 + j * dim3 + k);
    } else {
        return base + (k * dim1 * dim2 + j * dim1 + i);
    }
}

int main() {
    int arr[2][3][4];
    int base = (int)&arr;
    int i = 1, j = 2, k = 3;
    bool rowMajor = true;
    int* address = calculateAddress(arr[0][0], 2, 3, 4, i, j, k, rowMajor);
    cout << "Address of element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;
    return 0;
}
