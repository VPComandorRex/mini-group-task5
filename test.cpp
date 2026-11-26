#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

 
void runSortTask() {
    std::vector <int> numbers = { 20, 21, 1, 5, 19, 3, 9, 32, 1 };

    if (numbers.size() < 2) {
        std::cout << ">2 fatal" << std::endl;
        return;
    }
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    std::cout << "sorted: ";
    for (int x : numbers) std::cout << x << " ";
    std::cout << std::endl;
}
 
int findMostFrequent(const std::vector<int>& arr) {
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
    std::cout << "1 sort" << std::endl;
    runSortTask();

    // ДОБАВЛЕНО: вторая задача
    std::cout << "\nthe most common" << std::endl;
    std::vector<int> data = { 1, 3, 2, 3, 4, 3, 1, 2, 2, 2, 5 };

    std::cout << "start";
    for (int x : data) std::cout << x << " ";
    std::cout << "\n";

    int result = findMostFrequent(data);
    std::cout << "the most common: " << result << std::endl;

    return 0;
}