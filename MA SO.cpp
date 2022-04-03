#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> mangso;
bool cx[12];
int x[12];
vector<string> res;

void Try(int i, string s){
	for(int j = 1; j <= n; j++){
		s += to_string(j);
		if(s.size() == n){
			mangso.push_back(s);
		}
		else if(s.size() < n){
			Try(j, s);
		}
		s.pop_back();
	}
}

void solve(){
	string s = "";
	for(int i = 1; i <= n; i++){
		s += (char)(x[i] + 64);
	}
	// da co AB
	string tmp = s;
	for(auto x : mangso){
		tmp += x;
		res.push_back(tmp);
		tmp = s;
	}
}

void Tryhv(int i){
	for(int j = 1; j <= n; j++){
		if(cx[j] == false){
			cx[j] = true;
			x[i] = j;
			if(i == n){
				solve();
			}
			else Tryhv(i + 1);
			cx[j] = false;
		}
	}
}

void TC(){
	cin >> n;
	Try(1, "");
	memset(cx, false, sizeof(cx));
	Tryhv(1);
	for(auto x : res){
		cout << x << endl;
	}
	mangso.clear();
	res.clear();
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
