#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    // Настройка локализации для корректного вывода русского текста
    std::setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите размерность массива N: ";
    std::cin >> n;

    if (n <= 2) {
        std::cout << "Между элементами ничего не может находиться при N <= 2." << std::endl;
        return 0;
    }

    std::vector<int> A(n);
    std::cout << "Введите " << n << " элементов массива через пробел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    // 1. Поиск индексов минимального и максимального элементов
    int min_idx = 0;
    int max_idx = 0;

    for (int i = 1; i < n; ++i) {
        if (A[i] < A[min_idx]) {
            min_idx = i;
        }
        if (A[i] > A[max_idx]) {
            max_idx = i;
        }
    }

    // 2. Определение левой и правой границ диапазона
    int start = std::min(min_idx, max_idx);
    int end = std::max(min_idx, max_idx);

    // 3. Подсчет суммы отрицательных элементов строго между ними
    int negative_sum = 0;
    for (int i = start + 1; i < end; ++i) {
        if (A[i] < 0) {
            negative_sum += A[i];
        }
    }

    // Вывод результатов
    std::cout << "\nИндекс минимального элемента: " << min_idx << " (значение: " << A[min_idx] << ")" << std::endl;
    std::cout << "Индекс максимального элемента: " << max_idx << " (значение: " << A[max_idx] << ")" << std::endl;
    std::cout << "Сумма отрицательных элементов между ними: " << negative_sum << std::endl;

    return 0;
}
