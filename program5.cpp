#include <iostream>
#include <vector>
#include <algorithm>

int Main(){
    std::vector <int> numbers = {20, 21, 1, 5, 19, 3, 9, 32, 1};// сам список

    if (numbers.size() < 2){
        std::cout << "В списке меньше 2 элементов. Ошибка!" << std::endl;// проверка на требования к колличеству в массиве
        return 1;
    }
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());//сортировка от большего к меньшему
}