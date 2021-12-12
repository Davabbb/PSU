//https://contest.yandex.ru/contest/29755/run-report/55433917/

#include <iostream>

int main() {
    int n, m, find;
    int count = 0;

    std::cin >> n;
    int* data1 = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> data1[i];
    }

    std::cin >> m;
    int* data2 = new int[m];

    for (int i = 0; i < m; i++) {
        std::cin >> data2[i];
    }

    std::cin >> find;

    int count1 = 0, count2 = m - 1;
    int old_count2 = count2;
    for (int i = 0; i < n + m; i++) {
        if (data1[count1] + data2[count2] == find) {
            count += 1;
            count1 += 1;
            count2 -= 1;
            old_count2 = count2;
            continue;
        } else if (data1[count1] + data2[count2] < find) {
            count1 += 1;
            count2 = old_count2;
        } else if (data1[count1] + data2[count2] > find) {
            count2 -= 1;
        } if ((count1 == n) || (count2 == -1)) {
            break;
        }
    }

    std::cout << count;
    return 0;
}
