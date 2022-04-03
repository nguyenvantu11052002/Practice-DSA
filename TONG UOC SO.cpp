#include<bits/stdc++.h>

using namespace std;

int uoc[1000005] = {0};

void sanguoc(){
	for(int i = 1; i <= 1e6; i++){
		// 2i 3i 4i 5i;
		for(int j = 2 * i; j <= 1e6; j += i){ // nhung so nao co uoc la i thi tom het nao;  vi khong tinh chinh no nen j bat dau tu 2 * i;
			uoc[j] += i;  // bat dau tu i thi uoc[j = i] + ca i vao a ?;
		}
	}
}

void TC(){
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	for(int i = a; i <= b; i++){
		if(uoc[i] > i){
			cnt++;
		}
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t = 1;
	//cin >> t;
	sanguoc();
	while(t--){
		TC();
	}
	return 0;
}
