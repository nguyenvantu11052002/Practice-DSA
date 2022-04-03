#include<bits/stdc++.h>

using namespace std;

int n, a[25];
vector<int> b;
vector<string> v;

void solve(){
	string s = "";
	for(int i = 0; i < b.size(); i++){
		s += to_string(b[i]) + " ";
	}
	v.push_back(s);
}

void Try(int i){
	for(int j = i + 1; j <= n; j++){
		if(a[j] > a[i]){
			b.push_back(a[j]);
			if(b.size() >= 2){
				solve();
			}
			Try(j);
			b.pop_back();
		}
	}
}

void TC(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	Try(0);
	sort(v.begin(), v.end());
	for(auto x : v){
		cout << x << endl;
	}
	v.clear();
	b.clear();
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
