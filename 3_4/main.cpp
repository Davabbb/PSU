//https://contest.yandex.ru/contest/29755/run-report/53666761/

#include <iostream>
#include <cmath>

int BinarySearch (int* data, int find, int last, int first) {
    while (first < last) {
        int mid = (first + last) / 2;
        if (data[mid] == find) {
            return mid;
        } if (first == last - 1) {
            if (abs(find - data[first]) <= abs(data[last] - find)) {
                return mid;
            } else {
                return mid + 1;
            }
        } if (find > data[mid]) {
            first = mid;
        } else {
            last = mid;
        }
    }
    return first;
}


int main() {
    int n;
    std::cin >> n;
    int* data1 = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> data1[i];
    }

    int m;
    std::cin >> m;
    int* data2 = new int[m];
    for (int i = 0; i < m; i++) {
        std::cin >> data2[i];
    }

    for (int j = 0; j < m; j++) {
        int sm, count = 1, i = 1;
        while (i < n) {
            if (data1[i - 1] > data2[j]) {
                count = i - 1;
                break;
            } if (i > n) {
                count = n - 1;
                break;
            }
            i *= 2;
        }
        if (i > n - 1) {
            count = n - 1;
        }
        sm = count / 2;
        std::cout << BinarySearch(data1, data2[j], count, sm) << " ";
    }
    delete [] data1;
    delete [] data2;
    return 0;
}
