/*************************************************************************
	> File Name: 201712-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月15日 星期六 18时35分51秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int out_queue(int x, int k) {
    return x % k == 0 || x % 10 == k;
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    int cnt = 1, last;
    while (!q.empty()) {
        last = q.front();
        if (!out_queue(cnt++, k)) q.push(last);
        q.pop();
    }
    cout << last << endl;
    return 0;
}
