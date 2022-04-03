#include<bits/stdc++.h>

using namespace std;

int x[10], cx[10];
int n, k, res;
string s[15];

int chuyenso(string s){
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		sum = sum * 10 + (s[i] - '0');
	}
	return sum;
}

void solve(){
	vector<int> a;
	for(int i = 1; i <= n; i++){
		string tmp = "";
		for(int j = 1; j <= k; j++){
			tmp += s[i][x[j]];
		}
		a.push_back(chuyenso(tmp));
	}
	sort(a.begin(), a.end());
	int res1 = a[a.size() - 1] - a[0];
	res = min(res, res1);
}

void Try(int i){
	for(int j = 1; j <= k; j++){
		if(cx[j] == false){
			cx[j] = true;
			x[i] = j;
			if(i == k){
				solve();
			}
			else Try(i + 1);
			cx[j] = false;
		}
	}
}

void TC(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++){
		s[i] = " " + s[i];
	}
	memset(cx, false, sizeof(cx));
	res = INT_MAX;
	Try(1);
	cout << res << endl;
}

int main(){	
	int t = 1;
	//cin >> t;
	while(t--){
		TC();
	}
	return 0;
}
