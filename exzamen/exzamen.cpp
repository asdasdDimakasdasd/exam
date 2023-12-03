#include <iostream>
#include <climits>

int findMaxIndex(const int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    const int size = 10; 

    int arr[size];

    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Елемент " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    int maxIndex = findMaxIndex(arr, size);
    std::cout << "Номер максимального елемента: " << maxIndex << std::endl;

    int firstZeroIndex = -1, secondZeroIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }

    int product = 1;
    if (firstZeroIndex != -1 && secondZeroIndex != -1) {
        for (int i = firstZeroIndex + 1; i < secondZeroIndex; ++i) {
            product *= arr[i];
        }
        std::cout << "Добуток елементів між першим і другим нульовими елементами: " << product << std::endl;
    }
    else {
        std::cout << "У масиві немає двох нульових елементів для обчислення добутку.\n";
    }

    int transformedArr[size];
    int j = 0;
    for (int i = 1; i < size; i += 2) {
        transformedArr[j++] = arr[i];
    }
    for (int i = 0; i < size; i += 2) {
        transformedArr[j++] = arr[i];
    }

    std::cout << "Перетворений масив:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << transformedArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
