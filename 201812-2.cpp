/*************************************************************************
	> File Name: 201812-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月10日 星期日 19时07分28秒
 ************************************************************************/

#include <iostream>
using namespace std;
long long n, r, y, g, T = 0;
   
void judge(long long T, int &k, int &t) {
    if (k == 0) return ;
    int total = r + g + y;
    switch (k) {
        case 1: T = T - (t + g + y) + total; break;
        case 2: T = T - t + total; break;
        case 3: T = T - (t + y) + total; break;
    }
    t = T % total;
    if (t < r) k = 1, t = r - t;
    else if (t < r + g) k = 3, t = g - (t - r);
    else k = 2, t = y - (t - r - g);
    return ;
}

int main() {
    cin >> r >> y >> g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, t;
        cin >> k >> t;
        judge(T, k, t);
        switch (k) {
            case 0: T += t; break;
            case 1: T += t; break;
            case 2: T += t + r; break;
            case 3: break;
        }
    }
    cout << T << endl;
    return 0;
}
