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
int vis[MAX_N + 5][300];
bool flag = false;

void output() {
    for (int i = 0; i < n; i++) {
        i == 0 || cout << " ";
        cout << a[i];
    }
    cout << endl;
    return ;
}

void dfs(int num, int ind) {
    //cout << "ind = " << ind << " num = " << num << endl;
    if (flag) {
        return ;
    }
    a[ind] = num;
    if (ind == 1) {
        if (((a[0] + a[1]) >> 1) != b[0]) return ;
    }
    if (ind == n - 1) {
        if (((a[n - 1] + a[n - 2]) >> 1) == b[n - 1]) {
            flag = true;
            output();
        }
        return ;
    }
    if (ind > 1 && ind < n - 1) {
        if ((a[ind - 2] + a[ind - 1] + a[ind]) / 3 != b[ind - 1]) return ;
    }
    for (int i = 1; i <= 3 * b[ind]; i++) {
        if (vis[ind + 1][i]) continue;
        vis[ind + 1][i] = 1;
        dfs(i, ind + 1);
        vis[ind + 1][i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= 2 * b[0] && !flag; i++) {
        dfs(i, 0);
    }
    return 0;
}
