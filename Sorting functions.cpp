#include <iostream>
#include <ctime>

void selectionSort(int arr[], const int size);
void insertionSort(int arr[], const int size);
void bubbleSort(int arr[], const int size);
void swapNumbers(int& num1, int& num2);
void printArray(const int arr[], const int size);

int main()
{
    srand(time(0));
    const int ARRAY_SIZE = 6;
    int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    printArray(arr, ARRAY_SIZE);
    //selectionSort(arr, ARRAY_SIZE);
    //insertionSort(arr, ARRAY_SIZE);
    bubbleSort(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);

}

void selectionSort(int arr[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minElement = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < minElement) {
                minElement = arr[j];
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapNumbers(arr[i], arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], const int size) {
    int keyElement;
    for (int i = 1; i < size; i++) {
        keyElement = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > keyElement) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = keyElement;
    }
}

void bubbleSort(int arr[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapNumbers(arr[j], arr[j + 1]);
            }
        }
    }
}

void swapNumbers(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void printArray(const int arr[], const int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
