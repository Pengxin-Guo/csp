/*************************************************************************
	> File Name: 201809-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月04日 星期二 21时05分23秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1000

int arr[MAX_N + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << (arr[i - 1] + arr[i] + arr[i + 1]) / (i == 1 || i == n ? 2 : 3);
    }
    cout << endl;
    return 0;
}
