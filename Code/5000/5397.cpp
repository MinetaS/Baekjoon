#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputs;
	string input;

	cin >> inputs;

	while (inputs > 0) {
		inputs--;
		deque<char> front;
		deque<char> back;

		cin >> input;

		for (char &c : input) {
			if (c == '<') {
				if (front.empty()) continue;

				back.push_back(front.back());
				front.pop_back();
				continue;
			}

			if (c == '>') {
				if (back.empty()) continue;

				front.push_back(back.back());
				back.pop_back();
				continue;
			}

			if (c == '-') {
				if (front.empty()) continue;
				
				front.pop_back();
				continue;
			}

			front.push_back(c);
		}

		string r_front(front.begin(), front.end());
		string r_back(back.begin(), back.end());
		reverse(r_back.begin(), r_back.end());

		cout << r_front << r_back << '\n';
	}

	return 0;
}