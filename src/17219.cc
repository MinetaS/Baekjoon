#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	unordered_map<string, string> pw_set;

	cin >> n >> m;

	for (int i=0 ; i<n ; i++) {
		string site, pw;

		cin >> site >> pw;
		pw_set[site] = pw;
	}

	for (int i=0 ; i<m ; i++) {
		string site;

		cin >> site;
		cout << pw_set[site] << '\n';
	}

	return 0;
}