#include <iostream>
#include <vector>
using namespace std;

long GCD(long a, long b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

vector<long> Execute(long a, long b) {
	vector<long> ret(2);
	if (b == 0) {
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}
	long q = a / b;
	long r = a % b;

	vector<long> v = Execute(b, r); //이전 것
	ret[0] = v[1];
	ret[1] = v[0] - v[1] * q;
	//cout << ret[0] << " " << ret[1] << endl;
	return ret; //계산 한 X, Y 리턴
}

int main() {
	long A, B, C;
	cin >> A >> B >> C;

	long c = GCD(A, B);

	if (C % c != 0) {
		cout << -1;
	}
	else {
		vector<long>ans = Execute(A, B);
		C = C / c;
		ans[0] *= C;
		ans[1] *= C;

		cout << ans[0] << " " << ans[1];
	}
}