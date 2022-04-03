#include<bits/stdc++.h>

using namespace std;
char a[1005][1005];
int n, m;
bool cx[1005][1005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j){
	cx[i][j] = true;
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 0 && i1 <= n - 1 && j1 >= 0 && j1 <= m - 1 && a[i1][j1] == '#' && cx[i1][j1] == false){
			dfs(i1, j1);
		}
	}
}

void TC(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	memset(cx, false, sizeof(cx));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(cx[i][j] == false && a[i][j] == '#'){
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t = 1;
	//cin >> t;
	while(t--){
		TC();
	}
	return 0;
}
