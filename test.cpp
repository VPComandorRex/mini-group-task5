#include <iostream>
#include <vector>

// #1 Сортировка слиянием 
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void runMergeSort() {
    std::vector<int> data = { 38, 27, 43, 3, 9, 82, 10 };
    mergeSort(data, 0, data.size() - 1);
    std::cout << "Merge Sort: ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;
}

// #2 Быстрая сортировка 
void swapVals(int& a, int& b) { int temp = a; a = b; b = temp; }

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { i++; swapVals(arr[i], arr[j]); }
    }
    swapVals(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void runQuickSort() {
    std::vector<int> data = { 38, 27, 43, 3, 9, 82, 10 };
    quickSort(data, 0, data.size() - 1);
    std::cout << "Quick Sort: ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;
}

//Единственный main() 
int main() {
    std::cout << "1. Merge Sort" << std::endl;
    runMergeSort();
    std::cout << "\n2. Quick Sort " << std::endl;
    runQuickSort();
    return 0;
}