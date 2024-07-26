#include <bits/stdc++.h>

using namespace std;

int a[501][501], n;
bool visited[501][501];
int X[4] = { -1, 1,  0, 0 };
int Y[4] = {  0, 0, -1, 1 };

void dfs(int x, int y, int m) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i)
        if (1 <= x+X[i] && x+X[i] <= n && 1 <= y+Y[i] && y+Y[i] <= n && !visited[x+X[i]][y+Y[i]] && abs(a[x][y]-a[x+X[i]][y+Y[i]]) <= m)
            dfs(x+X[i], y+Y[i], m);
}

bool f(int m) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            visited[i][j] = false;
    dfs(1, 1, m);
    return visited[n][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    int l = 0, r = 1e6, res = -1;
    while (l <= r) {
        int m = (l+r)/2;
        if (f(m)) r = m-1, res = m;
        else l = m+1;
    }
    cout << res;
	return 0;
}
