/*************************************************************************
	> File Name: 201803-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月10日 星期一 16时54分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int temp, now = 0, total = 0;
    for (cin >> temp; temp; cin >> temp) {
        if (temp == 1) now = 1;
        else if (temp == 2) {
            if (now == 0 || now == 1) now = 2;
            else now += 2;
        } 
        total += now;
    }
    cout << total << endl;
    return 0;
}
