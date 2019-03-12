/*************************************************************************
	> File Name: 201812-4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月11日 星期一 19时24分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
    int u, v, c;
    bool operator<(const Edge &obj) const {
        return this->c < obj.c;
    }
};

vector<Edge> arr;

#define MAX_N 50000
struct UnionSet {
    int fa[MAX_N + 5], cnt;
    UnionSet(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
        cnt = n;
    }
    int find(int x) {
        return (fa[x] = (x == fa[x] ? x : find(fa[x])));
    }
    int merge(int a, int b) {
        cnt -= (find(a) != find(b));
        fa[fa[a]] = fa[b];
    }
};

int main() {
    int n, m, ind;
    cin >> n >> m >> ind;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back(Edge(a, b, c));
    }
    sort(arr.begin(), arr.end());
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        u.merge(arr[i].u, arr[i].v);
        if (u.cnt > 1) continue;
        cout << arr[i].c << endl;
        break;
    }
    return 0;
}
