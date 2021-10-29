//https://contest.yandex.ru/contest/29755/run-report/55651504/

#include <iostream>
#include <map>

int main() {
    int n;
    int quanity_number = 0;
    std::cin >> n;

    std::map <int, int> numbers;

    int data[10] {};
    int j = 0;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        if (numbers[num] == 0) {
            numbers[num] = 1;
            data[j] = num;
            j++;
            quanity_number += 1;
        } else {
            numbers[num] += 1;
        }
    }

    for (int i = 0; i < quanity_number; i++) {
        for (int z = 0; z < quanity_number - 1; z++) {
            if (numbers[data[z]] < numbers[data[z + 1]]) {
                int b = data[z];
                data[z] = data[z + 1];
                data[z + 1] = b;
            }
        }
    }

    for (int i = 0; i < quanity_number; i++) {
            data[i] = numbers[data[i]];
    }

    while (data[1] != 0) {
        data[0] = data[0] - 1;
        data[1] = data[1] - 1;

        int i = 1;
        while (data[i] < data[i + 1]) {
            std::swap(data[i], data[i + 1]);
            i++;
        }

        int z = 0;
        while (data[z] < data[z + 1]) {
            std::swap(data[z], data[z + 1]);
            z++;
        }
    }
    std::cout << data[0];
}
