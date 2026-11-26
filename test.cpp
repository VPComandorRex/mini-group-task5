#include <iostream>
#include <vector>
#include <stdexcept>

//#1 Сортировка слиянием
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

//#2 Быстрая сортировка
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

//#3 Бинарный поиск
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void runBinarySearch() {
    std::vector<int> sortedData = { 3, 9, 10, 27, 38, 43, 82 };
    int target = 27;
    int result = binarySearch(sortedData, target);
    if (result != -1)
        std::cout << "Element " << target << " found at index: " << result << std::endl;
    else
        std::cout << "Element " << target << " not found." << std::endl;
}

//#4 Матрицы
using Matrix = std::vector<std::vector<int>>;

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row) std::cout << val << "\t";
        std::cout << std::endl;
    }
}

Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int rows = A.size(), cols = A[0].size();
    Matrix C(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtractMatrices(const Matrix& A, const Matrix& B) {
    int rows = A.size(), cols = A[0].size();
    Matrix C(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int rowsA = A.size(), colsA = A[0].size();
    int rowsB = B.size(), colsB = B[0].size();
    if (colsA != rowsB) throw std::invalid_argument("Incompatible matrix sizes!");
    Matrix C(rowsA, std::vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            for (int k = 0; k < colsA; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

void runMatrixDemo() {
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {5, 6}, {7, 8} };
    std::cout << "Matrix A:" << std::endl; printMatrix(A);
    std::cout << "Matrix B:" << std::endl; printMatrix(B);
    std::cout << "\nA + B:" << std::endl; printMatrix(addMatrices(A, B));
    std::cout << "\nA - B:" << std::endl; printMatrix(subtractMatrices(A, B));
    std::cout << "\nA * B:" << std::endl; printMatrix(multiplyMatrices(A, B));
}

//Единственный main()
int main() {
    std::cout << "=== 1. Merge Sort ===" << std::endl;
    runMergeSort();
    std::cout << "\n=== 2. Quick Sort ===" << std::endl;
    runQuickSort();
    std::cout << "\n=== 3. Binary Search ===" << std::endl;
    runBinarySearch();
    std::cout << "\n=== 4. Matrix Operations ===" << std::endl;
    runMatrixDemo();
    return 0;
}