#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;

    cin >> n;
    cin >> m;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    
    int cnt = 0;
    vector<bool> visited(v.size(), false);
    int start = 0;
    int end = v.size()-1;

    while (start < end) {
        if (v[start] + v[end] == m) {
            cnt++;
            start++;
            end--;
        }
        else if (v[start] + v[end] < m) {
            start++;
        }
        else {
           end--;
        }
    }
    cout << cnt;
    return 0;
}