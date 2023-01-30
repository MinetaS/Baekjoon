#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	int win, lose, goal;
	unordered_map<string, int> data;

	cin >> n >> p;
	cin >> win >> lose >> goal;

	for (int i=0 ; i<p ; i++) {
		string s, t;

		cin >> s >> t;

		if (t == "W") data[s] = win;
		else data[s] = -lose;
	}

	int rating = 0;

	for (int i=0 ; i<n ; i++) {
		string s;

		cin >> s;

		if (data.find(s) != data.end()) rating += data[s];
		else rating -= lose;
		if (rating < 0) rating = 0;
		if (rating >= goal) break;
	}

	if (rating >= goal) cout << "I AM NOT IRONMAN!!";
	else cout << "I AM IRONMAN!!";

	return 0;
}