#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <stdexcept> 

void runSortTask() {
    std::vector <int> numbers = { 20, 21, 1, 5, 19, 3, 9, 32, 1 };

    if (numbers.size() < 2) {
        std::cout << ">2 fatal" << std::endl;
        return;
    }
    
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // Вывод второго по величине (индекс 1, так как 0 - самый большой)
    std::cout << "second largest " << numbers[1] << std::endl;
}

int findMostFrequent(const std::vector<int>& arr) {
    // ДОБАВЛЕНО: проверка на пустоту
    if (arr.empty()) {
        throw std::invalid_argument("None");
    }

    std::unordered_map<int, int> frequency;

    for (int num : arr) {
        frequency[num]++;
    }

    int mostFrequentElement = arr[0];
    int maxCount = 0;

    for (const auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentElement = pair.first;
        }
    }

    return mostFrequentElement;
}


int main() {
    std::cout << "1" << std::endl;
    runSortTask();

    std::cout << "\n8" << std::endl;
    std::vector<int> data = { 1, 3, 2, 3, 4, 3, 1, 2, 2, 2, 5 };

    std::cout << "start ";
    for (int x : data) std::cout << x << " ";
    std::cout << "\n";

    
    try {
        int result = findMostFrequent(data);
        std::cout << "\nthe most common:   " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "fatal" << e.what() << std::endl;
    }

    return 0;
}