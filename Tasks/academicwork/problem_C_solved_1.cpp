#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAXN 555
bool gra[MAXN][MAXN], vis[MAXN];
int cx[MAXN], cy[MAXN];
string dis[MAXN], like[MAXN];
int n, m, p, catnum, dognum;

bool dfs(int u) {
	int ans = 0;
	for (int i = 0; i < p; i++) {
		if (gra[u][i] && !vis[i]) {
			vis[i] = 1;
			if (cy[i] == -1 || dfs(cy[i])) {
				cy[i] = u;
				cx[u] = i;
				return 1;
			}
		}
	}
	return false;
}

void solve() {
	int res = 0;
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	for (int i = 0; i < p; i++) {
		if (cx[i] == -1) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i))
				res++;
			
		}
	}
	printf("%d\n", p - res / 2);
}

int main() {
	while (scanf("%d %d %d", & n, & m, & p) != EOF) {
		memset(gra, 0, sizeof(gra));
		for (int i = 0; i < p; i++)
			cin >> like[i] >> dis[i];
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				if (i != j && !like[i].compare(dis[j]) || !dis[i].compare(like[j]))
					gra[i][j] = gra[j][i] = 1;
			}
		}
		solve();
	}
	return 0;
}