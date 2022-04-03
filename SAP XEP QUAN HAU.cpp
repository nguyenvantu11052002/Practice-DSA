#include<bits/stdc++.h>

using namespace std;
int a[10][10];
bool cx[10][10];
bool cheo1[20]; // i - j + n; 1 2n - 1;
bool cheo2[20]; // i + j; 2 2n;
bool hang[10], cot[10];
int res, ans;
int dem = 1;

void Try(int i){
	for(int j = 1; j <= 8; j++){
		if(cx[i][j] == false && cheo1[i - j + 8] == false && cheo2[i + j] == false && hang[i] == false && cot[j] == false){
			cx[i][j] = true;
			cheo1[i - j + 8] = true;
			cheo2[i + j] = true;
			hang[i] = true;
			cot[j] = true;
			res += a[i][j];
			if(i == 8){
				ans = max(ans, res);
			}
			else Try(i + 1);
			cx[i][j] = false;
			cheo1[i - j + 8] = false;
			cheo2[i + j] = false;
			hang[i] = false;
			cot[j] = false;
			res -= a[i][j];
		}
	}
}

void TC(){
	for(int i = 1; i <= 8; i++){
		for(int j = 1; j <= 8; j++){
			cin >> a[i][j];
		}
	}
	cout << "Test " << dem << ": ";
	dem++;
	res = 0;
	ans = 0;
	memset(cx, false, sizeof(cx));
	memset(cheo1, false, sizeof(cheo1));
	memset(cheo2, false, sizeof(cheo2));
	memset(hang, false, sizeof(hang));
	memset(cot, false, sizeof(cot));
	Try(1);
	cout << ans << endl;
}

int main(){	
	int t = 1;
	cin >> t;
	while(t--){
		TC();
	}
	return 0;
}
