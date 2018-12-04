/*************************************************************************
	> File Name: 201809-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月04日 星期二 21时16分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 2000

struct Data {
    int b, e;
};

struct Data arr[MAX_N + 5];

int count (Data &x, Data &y) {
    int a = x.b > y.b ? x.b : y.b;
    int b = x.e < y.e ? x.e : y.e;
    if (b < a) return 0;
    return b - a;
}

int main() {
    int n, ans = 0;
    Data temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].b >> arr[i].e;
    }
    for (int i = 0; i < n; i++) {
        cin >> temp.b >> temp.e;
        for (int j = 0; j < n; j++) {
            ans += count(arr[j], temp);
        }
    }
    cout << ans << endl;
    return 0;
}
