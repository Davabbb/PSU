//https://contest.yandex.ru/contest/29755/run-report/53666242/

#include <iostream>

int main() {
    int N, A, B;
    int min = 2;
    std::cin >> N;
    while (N % min != 0) {
        min += 1;
    }
    B = (N / min) * (min - 1);
    A = N - B;
    std::cout << A << " " << B << std::endl;
    return 0;
}
