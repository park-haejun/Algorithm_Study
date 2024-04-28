#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std;
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int result = 0;
void bfs(vector<vector<int>> map) {
    queue<pair<int, int>> q;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (map[i][j] == 2) q.push({ i,j });
        }
    }
    while (!q.empty()) {
        pair<int,int> cur = q.front(); 
        q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (map[nx][ny] == 0) {
                map[nx][ny] = 2;
                q.push({ nx,ny });
            }
        }
    }


    int cnt = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (map[i][j] == 0) cnt++;
        }
    }
    
    if (result < cnt) result = cnt;

}
void dfs(vector<vector<int>> map, int cnt) {
    if (cnt == 3) {
        bfs(map);
        return;
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                dfs(map, cnt+1);
                map[i][j] = 0;
            }
        }
    }
    return ;
}
int main()
{
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int x;
            cin >> x;
            map[i][j] = x;
        }
    }

    dfs(map,0);

    cout << result;

    return 0;
}