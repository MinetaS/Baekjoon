#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<int> _deque;
	int n;
	
	cin >> n;

	for (int i=0 ; i<n ; i++) {
		string cmd;
		int arg;

		cin >> cmd;

		if (cmd == "push_front") {
			cin >> arg;
			_deque.push_front(arg);
			continue;
		}

		if (cmd == "push_back") {
			cin >> arg;
			_deque.push_back(arg);
			continue;
		}

		if (cmd == "pop_front") {
			if (_deque.empty()) cout << -1 << '\n';
			else {
				cout << _deque.front() << '\n';
				_deque.pop_front();
			}
			continue;
		}

		if (cmd == "pop_back") {
			if (_deque.empty()) cout << -1 << '\n';
			else {
				cout << _deque.back() << '\n';
				_deque.pop_back();
			}
			continue;
		}

		if (cmd == "size") {
			cout << _deque.size() << '\n';
			continue;
		}

		if (cmd == "empty") {
			cout << _deque.empty() << '\n';
			continue;
		}

		if (cmd == "front") {
			if (_deque.empty()) cout << -1 << '\n';
			else cout << _deque.front() << '\n';
			continue;
		}

		if (cmd == "back") {
			if (_deque.empty()) cout << -1 << '\n';
			else cout << _deque.back() << '\n';
			continue;
		}
	}
	
	return 0;
}