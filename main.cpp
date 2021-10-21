#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

int main() {
    int n, m;

    std::cin >> n;
    int* data1 = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> data1[i];
    }

    std::cin >> m;
    int* data2 = new int[m];
    int* answer = new int[m];

    std::map <int, int> ans;

    for (int i = 0; i < m; i++) {
        std::cin >> data2[i];
        answer[i] = data2[i];
    }
    std::sort(data2, data2 + m);

    int k = 0;
    for (int i = 0; i < m; i++) {
        int j = 0;
        while (abs(data1[j + k] - data2[i]) > abs(data1[j + k + 1] - data2[i])) {
            j++;
        }
        ans[data2[i]] = j + k;
        if (j != 0) {
            k += j - 1;
        }
    }
    for (int i = 0; i < m; i++) {
        std::cout << ans[answer[i]] << " ";
    }

    return 0;
}
