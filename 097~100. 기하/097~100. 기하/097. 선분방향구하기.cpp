#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<int> x(4);
	vector<int> y(4);
	
	for (int i = 1; i <= 3; i++) {
		cin >> x[i] >> y[i];
	}

	int ccw = (x[1] * y[2] + x[2] * y[3] + x[3] * y[1]) - (x[1] * y[3] + x[3] * y[2] + x[2] * y[1]);

	if (ccw > 0) cout << 1;
	else if (ccw == 0) cout << 0;
	else cout << -1;


	return 0;
}