#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int hash_t;

hash_t get_hash(string &);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	hash_t hash[25];

	int count = 0;
	vector<hash_t> min_req;

	cin >> n;

	for (int i=0 ; i<n ; i++) {
		string s;

		cin >> s;
		hash[i] = get_hash(s);
	}

	for (int i=0 ; i<(1<<n) ; i++) {
		bool prev = false;

		for (hash_t &m : min_req) {
			if ((m & i) == m) {
				count++;
				prev = true;
				break;
			}
		}

		if (prev) continue;

		hash_t check = 0;

		for (int j=0 ; j<n ; j++) {
			if ((i & (1<<j)) != 0) check |= hash[j];
			if (check == (1<<26)-1) {
				count++;
				break;
			}
		}

	}

	cout << count;

	return 0;
}

hash_t get_hash(string &s) {
	hash_t ret = 0;

	for (char &c : s)
		ret |= 1<<(c-97);
	
	return ret;
}