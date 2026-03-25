#include <iostream>
using namespace std;

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;        // root
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move max to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}