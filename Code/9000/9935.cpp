#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str, explode;
	vector<char> store;

	cin >> str;
	cin >> explode;

	store.reserve(1000000);
	int explode_len = explode.size();

	for (char &c : str) {
		bool triggered = false;
		store.push_back(c);

		do {
			if (store.empty()) break;

			vector<char>::iterator it = store.end();
			bool remove = true;

			triggered = false;
			it--;

			for (int i=0 ; i<explode_len ; i++) {
				if (*it != explode[explode_len-i-1]) {
					remove = false;
					break;
				}

				if (it == store.begin()) {
					if (i != explode_len-1) remove = false;
					break;
				}

				it--;
			}

			if (remove) {
				for (int i=0 ; i<explode_len ; i++)
					store.pop_back();

				triggered = true;
			}
		} while (triggered);
	}

	if (store.empty()) cout << "FRULA";
	else {
		string res(store.begin(), store.end());
		cout << res;
	}

	return 0;
}