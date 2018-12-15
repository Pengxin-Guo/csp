/*************************************************************************
	> File Name: 201712-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月15日 星期六 18时26分22秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a;
    vector<int> arr;
    cin >> n;
    while (n--) cin >> a, arr.push_back(a);
    sort(arr.begin(), arr.end());
    int ans = arr[arr.size() - 1];
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i] - arr[i - 1];
        if (temp < ans) ans = temp;
    }
    cout << ans << endl;
    return 0;
}
