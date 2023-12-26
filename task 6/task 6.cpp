#include <iostream>
#include <vector>
#include <Windows.h>

double findAverageExcludeRange(const std::vector<int>& arr, int K, int L) {
    if (K < 1 || L > arr.size() || K > L) {
        std::cout << "Некоректний діапазон K і L" << std::endl;
        return 0.0;
    }

    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (i < K - 1 || i > L - 1) {
            sum += arr[i];
            count++;
        }
    }

    if (count == 0) {
        std::cout << "У вказаному діапазоні немає елементів для обчислення середнього" << std::endl;
        return 0.0;
    }

    return static_cast<double>(sum) / count;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int K = 3;
    int L = 7;

    double average = findAverageExcludeRange(array, K, L);
    std::cout << "Середнє арифметичне, крім елементів від " << K << " до " << L << ": " << average << std::endl;

    return 0;
}