#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
bool check(string str) {
    stack<int> s;

    for (int i = 0;i < str.size();i++) {
        if (s.empty()) {
            s.push(str[i]);
        }
        else {
            if (s.top() == str[i]) {
                s.pop();
            }
            else {
                s.push(str[i]);
            }
        }
    }

    if (s.empty()) {
        return true;
    }
    else return false;
}
int main()
{
    int n;

    cin >> n;
    vector<string> v;
    for (int i = 0;i < n;i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    int cnt = 0;
    
    for (int i = 0;i < v.size();i++) {
        if (check(v[i])) cnt++;
    }


    cout << cnt;

    
    return 0;
}