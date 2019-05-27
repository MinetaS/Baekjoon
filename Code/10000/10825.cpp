#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Grade {
	string name;
	int kor;
	int eng;
	int math;
};

bool comparator(Grade &, Grade &);

Grade students[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for (int i=0 ; i<n ; i++)
		cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;

	sort(students, students+n, comparator);

	for (int i=0 ; i<n ; i++)
		cout << students[i].name << '\n';

	return 0;
}

bool comparator(Grade &arg0, Grade &arg1) {
	if (arg0.kor > arg1.kor) return true;
	if (arg0.kor < arg1.kor) return false;
	if (arg0.eng < arg1.eng) return true;
	if (arg0.eng > arg1.eng) return false;
	if (arg0.math > arg1.math) return true;
	if (arg0.math < arg1.math) return false;
	if (arg0.name < arg1.name) return true;
	return false;
}