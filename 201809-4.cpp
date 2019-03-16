/*************************************************************************
	> File Name: 201809-4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月16日 星期六 09时31分58秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 300
int n;
int a[MAX_N + 5];
int b[MAX_N + 5];
int vis[MAX_N + 5][MAX_N + 5][MAX_N + 5];
bool flag = false;

void output() {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << a[i];
    }
    cout << endl;
    return ;
}

void dfs(int i, int cur, int pre) {
    if (vis[i][cur][pre]) return ;
    if (flag) return ;
    vis[i][cur][pre] = 1;
    a[i] = cur;
    if (i == n) {
        if ((a[n - 1] + a[n]) / 2 == b[n]) {
            flag = true;
            output();
        }
        return ;
    }
    int next = 3 * b[i] - pre - cur;
    for (int k = 0; k < 3; k++) {
        if (next + k > 0) {
            dfs(i + 1, next + k, cur);
        }
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int e = 1; e <= 2 * b[1]; e++) {
        a[1] = e;
        // 当a[1]确定下来的时候, a[2]有两种答案: 2 * b[1] - a[1], 2 * b[1] - a[1] + 1;
        dfs(2, 2 * b[1] - a[1], a[1]);
        if (!flag) dfs(2, 2 * b[1] - a[1] + 1, a[1]);
        else break;
    }
    return 0;
}
