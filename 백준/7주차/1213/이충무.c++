#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    string str;

    cin >> str;


    vector<bool> visited(str.size(), false);

    vector<char> start;

    for (int i = 0;i < str.size()-1;i++) {
        for (int j = i + 1;j < str.size();j++) {
            if (str[i] == str[j] && !visited[i] && !visited[j]) {
                start.push_back(str[i]);
                visited[i] = true;
                visited[j] = true;
            }
        }
    }
    sort(start.begin(), start.end());
    int cnt = 0;
    int idx = -1;
    for (int i = 0;i < str.size();i++) {
        if (!visited[i]) {
            idx = i;
            cnt++;
        }
    }
    

    if ((str.size()%2 == 0 && cnt > 0) || cnt >= 2) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    string result;
    for (int i = 0;i < start.size();i++) {
        result += start[i];
    }

    if (str.size() % 2 == 1) {
        result += str[idx];
    }

    for (int i = 0;i < start.size();i++) {
        result += start[start.size()-1-i];
    }
    cout << result;
    return 0;
}