/*************************************************************************
	> File Name: 201709-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月02日 星期六 19时57分32秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    if (n >= 50) {
        ans += (n / 50) * 7;
        n -= (n / 50) * 50;
    }
    if (n >= 30) {
        ans += (n / 30) * 4;
        n -= (n / 30) * 30;
    }
    ans += (n / 10);
    cout << ans << endl;
    return 0;
}
