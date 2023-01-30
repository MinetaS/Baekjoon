#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	double s = 0.0;
	int ts = 0;

	cin >> n;

	for (int i=0 ; i<n ; i++) {
		int score;
		string t, grade;

		cin >> t >> score >> grade;
		
		ts += score;
		if (grade == "A+") s += score*4.3;
		if (grade == "A0") s += score*4.0;
		if (grade == "A-") s += score*3.7;
		if (grade == "B+") s += score*3.3;
		if (grade == "B0") s += score*3.0;
		if (grade == "B-") s += score*2.7;
		if (grade == "C+") s += score*2.3;
		if (grade == "C0") s += score*2.0;
		if (grade == "C-") s += score*1.7;
		if (grade == "D+") s += score*1.3;
		if (grade == "D0") s += score*1.0;
		if (grade == "D-") s += score*0.7;
	}

	cout << fixed;
	cout.precision(2);
	cout << round(100*s/ts)/100;

	return 0;
}