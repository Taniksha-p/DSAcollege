// enhanced_sort.cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comp, int &swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comp, int &swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comp++;
            arr[j + 1] = arr[j];
            swaps++;
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comp, int &swaps) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
            swaps++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int comp = 0, swaps = 0;

    bubbleSort(arr1, n1, comp, swaps);
    cout << "Bubble Sort - Comparisons: " << comp << ", Swaps: " << swaps << endl;

    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    comp = 0, swaps = 0;

    insertionSort(arr2, n2, comp, swaps);
    cout << "Insertion Sort - Comparisons: " << comp << ", Swaps: " << swaps << endl;

    int arr3[] = {64, 25, 12, 22, 11};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    comp = 0, swaps = 0;

    selectionSort(arr3, n3, comp, swaps);
    cout << "Selection Sort - Comparisons: " << comp << ", Swaps: " << swaps << endl;

    return 0;
}
