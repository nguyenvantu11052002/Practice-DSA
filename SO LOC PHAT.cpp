#include<bits/stdc++.h>

using namespace std;

int n, x[15];
vector<string> v;

void solve(){
	string s = "";
	for(int i = 1; i <= n; i++){
		if(x[i]){
			s += to_string(8);
		}
		else s += to_string(6);
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
	cout << v.size() << endl;
	for(auto x : v){
		cout << x << " ";
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
