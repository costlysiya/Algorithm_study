#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long Min, Max;
	cin >> Min >> Max;

	vector<bool>A(Max - Min +1); 


	for (long long i = 2; i*i <= Max; i++) {
		long long pow = i * i;
		long long start_index = Min / pow;
		if (Min % pow != 0) start_index++; 
		
		for (long long j = start_index; pow * j <= Max; j++) {
			A[(int)((j * pow) - Min)] = true; 
		}		
	}

	int cnt = 0;
	for (long long i = 0; i <= Max - Min; i++) {
		if (!A[i]) cnt++;
	}
	cout << cnt;
}