/*************************************************************************
	> File Name: 201803-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年12月14日 星期五 20时16分23秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
    Node(const char *str) {
        this->str = str;
        this->type = 0;
        if (this->str == "<int>") {
            this->type = 1;
        } else if(this->str == "<str>") {
            this->type = 2;
        } else if (this->str == "<path>") {
            this->type = 3;
        }
    }
    string str;
    int type; // 0 normal, 1 <int>, 2 <str>, 3 <path> 
};

ostream &operator<<(ostream &out, vector<Node *> &obj) {
    for (int i = 0; i < obj.size(); i++) {
        out << "(" << obj[i]->str << ", " << obj[i]->type << ") ";
    }
    return out;
}

vector<Node *> getList(char *str) {
    vector<Node *> ret;
    ret.push_back(new Node("/"));
    str += 1;
    char *now = str;
    while (str[0]) {
        while (str[0] && str[0] != '/') str++;
        if (str[0] == '/') {
            str[0] = 0;
            ret.push_back(new Node(now));
            ret.push_back(new Node("/"));
            str++;
        } else {
            ret.push_back(new Node(now));
        }
        now = str;
    }
    return ret;
}

vector<vector<Node *> > rules;
vector<string> names;

void read_rules(int n) {
    char str[1000];
    while (n--) {
        cin >> str; // rule
        rules.push_back(getList(str));
        cin >> str; // name
        names.push_back(str);
    }
    return ;
}

int match_node(Node *x, Node *y) {
    switch (x->type) {
        case 0: return x->str == y->str;
        case 1: {
            for (int i = 0; i < y->str.size(); i++) {
                if (y->str[i] < '0' || y->str[i] > '9') return 0;
            }
            return 1;
        }
        case 2:
        case 3: return 1;
    }
    return 0;
}

int match(vector<Node *> &l1, vector<Node *> &l2) {
    if (l2.size() < l1.size()) return 0;
    for (int i = 0; i < l1.size(); i++) {
        if (match_node(l1[i], l2[i]) == 0) return 0;
        if (l1[i]->type == 3) return 1;
    }
    return l1.size() == l2.size();
}

void output(vector<Node *> &l1, vector<Node *> &l2) {
    for (int i = 0; i < l1.size(); i++) {
        if (l1[i]->type == 0) continue;
        cout << " ";
        if (l1[i]->type == 1) {
            int j = 0;
            while (l2[i]->str[j + 1] && l2[i]->str[j] == '0') ++j;
            while (j < l2[i]->str.size()) {
                cout << l2[i]->str[j++];
            }
            continue;
        }
        cout << l2[i]->str;
    }
    for (int i = l1.size(); i < l2.size(); i++) {
        cout << l2[i]->str;
    }
    cout << endl;
    return ;
}

void solve(int m, int n) {
    char str[1000];
    while (m--) {
        cin >> str;
        vector<Node *> temp = getList(str);
        int i = 0;
        while (i < n && match(rules[i], temp) == 0) ++i;
        if (i == n) {
            cout << "404" << endl;
        } else {
            cout << names[i];
            output(rules[i], temp);
        }
    }
    return ;
}

int main() {
    vector<Node *> ret;
    int n, m;
    cin >> n >> m;
    read_rules(n);
    solve(m, n);
    return 0;
}
