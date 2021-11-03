//https://contest.yandex.ru/contest/29755/run-report/55873670/

#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n = 0, ans = 0;
    std::priority_queue <int, std::vector<int>, std::greater<>> q;

    std::cin >> n;

    int otb = 0, pri = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> pri;
        std::cin >> otb;

        if (q.size() > ans) {
            ans = q.size();
        }

        while (!q.empty() and pri > q.top()) {
            q.pop();
        }

        q.push(otb);
    }

    if (q.size() > ans) {
        ans = q.size();
    }

    std::cout << ans;
    return 0;
}
