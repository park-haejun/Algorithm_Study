#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;

string a[100004];
int main()
{
    int n;

    cin >> n;

    stack<int> s;
    vector<int> arr;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0;i < n;i++) {
        int x = arr[n -1 - i];
        while (!s.empty() && s.top() <= x) {
            s.pop();
        }
        
        if (s.empty()) {
            v.push_back(-1);
        }
        else {
            v.push_back(s.top());
        }
        
        s.push(x);
    }


    for (int i = 0;i < n;i++) {
        cout << v[v.size() - 1 - i] << " ";
    }

    
    return 0;
}