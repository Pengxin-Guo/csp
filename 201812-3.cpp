/*************************************************************************
	> File Name: 201812-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月12日 星期二 10时25分59秒
 ************************************************************************/
// 模拟题中的数据一定要包装成结构体

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Range {
    Range() {
        b = e = k = 0;
        num[0] = num[1] = num[2] = num[3] = 0;
        next = NULL;
        prev = NULL;
    }
    void load(const char *str) {
        int i = 0, s = 0, temp = 0;
        while (str[i]) {
            switch (str[i]) {
                case '.' : {
                    num[s] = temp;
                    s += 1;
                    temp = 0;
                } break;
                case '/' : {
                    num[s] = temp;
                    s = 4;
                    temp = 0;
                } break;
                default : {
                    temp = temp * 10 + (str[i] - '0');
                }
            }
            i++;
        }
        if (s != 4) k = (s + 1) * 8, num[s] = temp;
        else k = temp;
        for (int i = 0; i < 4; i++) {
            b = b * 256 + num[i];
        }
        e = b + (1 << (32 - k)) - 1;
        return ;
    }
    void output() {
        for (int i = 0; i < 4; i++) {
            i == 0 || cout << ".";
            cout << num[i];
        }
        cout << "/" << k << endl;
        return ;
    }
    unsigned int b, e, k;
    int num[4];
    Range *next, *prev;
};

#define MAX_N 100000
Range arr[MAX_N + 5];

bool cmp(Range &a, Range &b) {
    if (a.b != b.b) return a.b < b.b;
    return a.e > b.e;
}

int main() {
    int n;
    char str[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        arr[i].load(str);
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0) arr[i].prev = arr + i - 1;
        if (i + 1 < n) arr[i].next = arr + i + 1;
    }
    Range head;
    head.next = arr;
    arr[0].prev = &head;
    for (Range *p = head.next; p->next; p = p->next) {
        if (p->e < p->next->e) continue;
        p->next = p->next->next;
        if (p->next) p->next->prev = p;
        p = p->prev;
    }
    for (Range *p = head.next; p->next; p = p->next) {
        if (p->e + 1 != p->next->b) continue;
        if (p->k != p->next->k) continue;
        if (p->b & (1 << (32 - p->k))) continue;
        p->e = p->next->e;
        p->k -= 1;
        p->next = p->next->next;
        if (p->next) p->next->prev = p;
        p = p->prev;
        if (p->prev) p = p->prev;
    }
    for (Range *p = head.next; p; p = p->next) {
        p->output();
    }
    return 0;
}
