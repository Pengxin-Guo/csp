/*************************************************************************
	> File Name: 201803-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月10日 星期一 17时10分35秒
 ************************************************************************/

// 本题模拟过程为一个一个小球模拟

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 100
#define MAX_L 1000

struct {
    int p, d;                                                    // p代表小球的位置, d代表小球的运动方向(1代表x轴正方向, -1代表x轴负方向)
} arr[MAX_N + 5];                                                // n个小球, 编号从1到n

int vis[MAX_L + 5];                                              // vis[i]存放的是第i个位置的小球编号

void pass_one_second(int n, int l) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        arr[i].p += arr[i].d;                                    // 小球移动一次
        if (arr[i].p == 0 || arr[i].p == l) arr[i].d = - arr[i].d;
        if (vis[arr[i].p]) {                                     // 如果arr[i].p这个位置有小球了, 即代表两个小球相撞了
            int j = vis[arr[i].p];
            arr[i].d = -arr[i].d;
            arr[j].d = -arr[j].d;
        }
        vis[arr[i].p] = i;
    }
    return ;
}

int main() {
    int n, l, t;
    cin >> n >> l >> t;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].p;
        arr[i].d = 1;
    }
    for (int i = 0; i < t; i++) {
        pass_one_second(n, l);                                   // 模拟n个小球移动t次位置
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << arr[i].p;
    }
    cout << endl;
    return 0;
}
