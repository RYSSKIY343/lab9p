#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>

template <typename T>
void printContainer(const T& container) {
    for (const auto& i : container) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

void variant1() {
    std::vector<int> v = {10, 20, 30, 40, 50};
    std::cout << "Исходный вектор: ";
    printContainer(v);

    double avg = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
    int min = *std::min_element(v.begin(), v.end());
    std::replace_if(v.begin(), v.end(), [avg](int x) { return x > avg; }, min);
    std::cout << "После замены элементов, превосходящих среднее, на минимальный: ";
    printContainer(v);

    std::partial_sort(v.begin(), v.begin()+2, v.end(), std::greater<int>());
    v.erase(v.begin(), v.begin()+2);
    std::cout << "После удаления двух наибольших элементов: ";
    printContainer(v);

    std::sort(v.begin(), v.end());
    std::cout << "После сортировки по возрастанию: ";
    printContainer(v);
    std::cout << "Введите элемент для поиска:";
    int x;
    std::cin >> x;
    auto it = std::find(v.begin(), v.end(), x);
    if (it != v.end()) {
        std::cout << "Element found\n";
    } else {
        std::cout << "Element not found\n";
    }

    int max = *std::max_element(v.begin(), v.end());
    std::transform(v.begin(), v.end(), v.begin(), [max](int x) { return x / max; });
    std::cout << "После деления каждого элемента на максимальное значение: ";
    printContainer(v);
}

void variant2() {
    std::list<int> l = {0, -1, 2, 0, -3, 4};
    std::cout << "Исходный список: ";
    printContainer(l);

    std::replace(l.begin(), l.end(), 0, 1);
    std::cout << "После замены всех нулевых элементов на 1: ";
    printContainer(l);

    l.erase(l.begin(), std::next(l.begin(), 2));
    l.erase(std::prev(l.end(), 2), l.end());
    std::cout << "После удаления двух элементов из начала и конца списка: ";
    printContainer(l);

    l.sort();
    std::cout << "После сортировки по возрастанию: ";
    printContainer(l);

    int count = std::count_if(l.begin(), l.end(),  [](int x) { return x < 0; });
    std::cout << "Number of negative elements: " << count << '\n';

    std::transform(l.begin(), l.end(), l.begin(),  [](int x) { return x + 1; });
    std::cout << "После добавления 1 к каждому элементу: ";
    printContainer(l);
}

void variant3() {
    std::deque<int> d = {10, 20, 30, 40, 50};
    std::cout << "Исходный дек: ";
    printContainer(d);

    int min = *std::min_element(d.begin(), d.end());
    int max = *std::max_element(d.begin(), d.end());
    std::replace(d.begin(), d.end(), max, min);
    std::cout << "После замены максимального элемента на минимальный: ";
    printContainer(d);

    double avg = std::accumulate(d.begin(), d.end(), 0.0) / d.size();
    d.erase(std::remove_if(d.begin(), d.end(), [avg](int x) { return x < avg; }), d.end());
    std::cout << "После удаления всех элементов, меньших среднего арифметического: ";
    printContainer(d);

    std::sort(d.begin(), d.end(), std::greater<int>());
    std::cout << "После сортировки по убыванию: ";
    printContainer(d);

    int median;
    if (d.size() % 2 == 0) {
        median = (d[d.size()/2 - 1] + d[d.size()/2]) / 2;
    } else {
        median = d[d.size()/2];
    }
    std::cout << "Median: " << median << '\n';

    std::transform(d.begin(), d.end(), d.begin(),  [](int x) { return -x; });    std::cout << "После изменения знака каждого элемента: ";
    printContainer(d);
}

int main() {
    system("chcp 65001");
    int choice;
    std::cout << "Введите номер варианта (1, 2 или 3): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            variant1();
            break;
        case 2:
            variant2();
            break;
        case 3:
            variant3();
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, введите 1, 2 или 3.\n";
            break;
    }

    return 0;
}
