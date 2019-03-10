/*************************************************************************
	> File Name: 201812-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月10日 星期日 18时54分01秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, r, g, y, sum = 0;
    cin >> r >> y >> g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, t;
        cin >> k >> t;
        switch (k) {
            case 0: sum += t; break;
            case 1: sum += t; break;
            case 2: sum += t + r; break;
            case 3: break;
        }
    }
    cout << sum << endl;
    return 0;
}
