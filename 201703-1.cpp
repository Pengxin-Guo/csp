/*************************************************************************
	> File Name: 201703-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月05日 星期二 20时39分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, k, a, sum = 0, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        if (sum >= k) {
            ans += 1;
            sum = 0;
        }
    }
    ans += (sum != 0);
    cout << ans << endl;
    return 0;
}
