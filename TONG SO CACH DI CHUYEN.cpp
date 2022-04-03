#include<bits/stdc++.h>

using namespace std;

int n, k;
int m = 1e9 + 7;
long long dp[100005];

void TC(){
	cin >> n >> k;
	long long sum = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= k; i++){
		dp[i] = sum + 1;
		dp[i] %= m;
		sum += dp[i];
		sum %= m;
	}
	for(int i = k + 1; i <= n; i++){
		for(int j = i - 1; j >= i - k; j--){
			dp[i] += dp[j];
			dp[i] %= m;
		}
	}
	cout << dp[n] << endl;
}

int main(){	
	int t = 1;
	cin >> t;
	while(t--){
		TC();
	}
	return 0;
}
