#include<bits/stdc++.h>

using namespace std;

int n, a[10][10];
bool cx[10][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char ds[4] = {'R', 'L', 'U', 'D'};
vector<string> v;

void Try(int i, int j, string s){
	cx[i][j] = true;
	if(i == 0 && j == 0 && a[i][j] == 0){
		return;
	}
	if(i == n - 1 && j == n - 1){
		v.push_back(s);
		return;
	}
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 0 && i1 <= n - 1 && j1 >= 0 && j1 <= n - 1 && a[i1][j1] == 1 && cx[i1][j1] == false){
			Try(i1, j1, s + ds[k]);
			cx[i1][j1] = false;
		}
	}
}

void TC(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	memset(cx, false, sizeof(cx));
	Try(0, 0, "");
	if(v.size() == 0){
		cout << -1 << endl;
	}
	else{
		cout << v.size() << " ";
		sort(v.begin(), v.end());
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
	}
	v.clear();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t = 1;
	cin >> t;
	while(t--){
		TC();
	}
	return 0;
}
