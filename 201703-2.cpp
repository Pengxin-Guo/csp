/*************************************************************************
	> File Name: 201703-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月14日 星期四 11时02分44秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000

int arr[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, flag;
        cin >> a >> b;
        for (int j = 1; j <= n; j++) {
            if (arr[j] - a) continue;
            a = j;
            break;
        }
        flag = (b < 0 ? -1 : 1);
        while (a + flag <= n && a + flag >= 1 && b != 0) {
            swap(arr[a], arr[a + flag]);
            b -= flag;
            a += flag;
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
