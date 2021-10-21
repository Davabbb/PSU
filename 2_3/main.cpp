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
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j + k - 1 < m; j++) {
            if (data1[i] + data2[m - k - j] == find) {
                count += 1;
                k += j;
                break;
            }
        }
    }
    std::cout << count;
    return 0;
}

