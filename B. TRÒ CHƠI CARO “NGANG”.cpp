#include<bits/stdc++.h>

using namespace std;
int n, x[25], scx;
char c;
// O- 0, X - 1;
vector<string> v;

bool check(){
	int demktcan = 0, demktcl = 0;
	int maxktcan = 0, maxktcl = 0;
	for(int i = 1; i <= n; i++){
		if(x[i] == scx){
			demktcl = 0;
			demktcan++;
			maxktcan = max(maxktcan, demktcan); // dem ki tu can;
		}
		else{
			demktcan = 0;
			demktcl++;
			maxktcl = max(demktcl, maxktcl); // dem ki tu con lai
		}
	}
	if(maxktcan < 5) return false;
	return maxktcan > maxktcl;
}

void solve(){
	string s = "";
	for(int i = 1; i <= n; i++){
		if(x[i]){
			s += "X";
		}
		else s += "O";
	}
	v.push_back(s);
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i == n){
			if(check()){
				solve();
			}
		}
		else Try(i + 1);
	}
}

void TC(){
	cin >> n >> c;
	if(c == 'X'){
		scx = 1;
	}
	else scx = 0;
	Try(1);
	sort(v.begin(), v.end());
	for(auto x : v){
		cout << x << endl;
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
