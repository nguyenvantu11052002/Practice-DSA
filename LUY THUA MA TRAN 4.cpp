#include<bits/stdc++.h>

using namespace std;
int n, k;
int m = 1e9 + 7;

struct matran{
	long long x[15][15];
};

matran operator*(matran a, matran b){
	matran c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c.x[i][j] = 0;
			for(int k = 0; k < n; k++){
				c.x[i][j] += (a.x[i][k] * b.x[k][j]) % m;
				c.x[i][j] %= m;
			}
		}
	}
	return c;
}

matran mul(matran a, int b){
	if(b == 1) return a;
	matran c = mul(a, b/2);
	if(b % 2){
		return c * c * a;
	}
	return c * c;
}

void TC(){
	cin >> n >> k;
	matran a;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a.x[i][j];
		}
	}
	matran res = mul(a, k);
	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += res.x[0][i];
		ans %= m;
	}
	cout << ans << endl;
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
