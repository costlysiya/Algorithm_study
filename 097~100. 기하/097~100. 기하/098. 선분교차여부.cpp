#include <iostream>
#include <cmath>
using namespace std;

int CCW(long x1, long x2, long x3, long y1, long y2, long y3) {
	long ccw = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1);
	if (ccw == 0) return 0;
	if (ccw > 0) return 1;
	else return -1;
}

bool is_over(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
	if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2)) {
		return true;
	}
	return false;
}

int main() {
	long x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;


	int ABccw1 = CCW(x1, x2, x3, y1, y2, y3);
	int ABccw2 = CCW(x1, x2, x4, y1, y2, y4);
	int CDccw1 = CCW(x3, x4, x1, y3, y4, y1);
	int CDccw2 = CCW(x3, x4, x2, y3, y4, y2);

	if (ABccw1*ABccw2 == 0 && CDccw1*CDccw2 == 0) {
		cout << (is_over(x1, x2, x3, x4, y1, y2, y3, y4));
	}
	else if (ABccw1 * ABccw2 <= 0 && CDccw1 * CDccw2 <= 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}