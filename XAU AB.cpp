#include<bits/stdc++.h>

using namespace std;

int n, x[15];
vector<string> v;

void solve(){
	string s = "";
	for(int i = 1; i <= n; i++){
		if(x[i]){
			s += "B";
		}
		else s += "A";
	}
	v.push_back(s);
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i == n){
			solve();
		}
		else Try(i + 1);
	}
}

void TC(){
	cin >> n;
	Try(1);
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		if(i != v.size() - 1) cout << ",";
	}
	cout << endl;
	v.clear();
}

int main(){	
	int t = 1;
	cin >> t;
	while(t--){
		TC();
	}
	return 0;
}
