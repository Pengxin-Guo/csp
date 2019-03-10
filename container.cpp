/*************************************************************************
	> File Name: container.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月10日 星期日 17时06分34秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    vector<int> arr;
    //cout << arr.size() << endl;
    for (int i = 2; i <= 11; i++) {
        arr.push_back(rand() % 100);
    }
    //cout << arr.size() << endl;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    map<string, int> arr2;
    arr2["hello"] = 2;
    arr2["world"] = 3;
    arr2["harbin"] = 56;
    arr2["beijing"] = 48;
    /*
    //c++ 11标准
    for (auto x : arr2) {
      cout << x.first << " " << x.second << endl;
    }
    */
    for (map<string, int>::iterator it = arr2.begin(); it != arr2.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    string temp;
    cin >> temp;
    if (arr2.find(temp) == arr2.end()) {
        cout << "not found " << temp << endl;
    } else {
        cout << "found " << temp << " in arr2 = " << arr2[temp] << endl;
    }
    
    set<int> ss;
    int n;
    while ((cin >> n) && n) {
        ss.insert(n);
    }
    for (set<int>::iterator it = ss.begin(); it != ss.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << ss.size() << endl;
    while (ss.size()) {
        cout << *(ss.begin()) << " ";
        ss.erase(ss.begin());
    }
    cout << endl;
    cout << ss.size() << endl;
    return 0;
}
