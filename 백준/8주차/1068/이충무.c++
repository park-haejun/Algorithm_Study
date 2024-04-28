#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std;
int result=0;
void dfs(vector<vector<int>> tree,int cur,vector<bool> visited,int del) {
    visited[cur] = true;

    if (tree[cur].size()==0 || (tree[cur].size()==1 && tree[cur][0] == del)) {
        result++;
        return;
    }


    for (int i = 0;i < tree[cur].size();i++) {
        int next = tree[cur][i];
        if (!visited[next]) {
            dfs(tree, next,visited,del);
        }
        
    }

    return;
}
int main()
{
    int n;
    cin >> n;
    int root=-1;

    vector<vector<int>> tree(n, vector<int>());
    vector<bool> visited(n, false);
    for (int i = 0;i < n;i++) {
        int parent;
        
        cin >> parent;

        if (parent == -1) {
            root = i;
            continue;
        }

        tree[parent].push_back(i);
    }

    int del;
    cin >> del;

    if (del == root) {
        cout << 0;
    }
    else {
        visited[del] = true;
        dfs(tree,root,visited,del);
        cout << result;
    }

    return 0;
}