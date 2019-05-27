#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	queue<int> q;

	string _tmp;
	getline(cin, _tmp);
	n = stoi(_tmp);

	for (int i=0 ; i<n ; i++) {
		string cmd;
		size_t pos;

		getline(cin, cmd);

		if ((pos=cmd.find("push")) != cmd.npos) {
			int arg = stoi(cmd.substr(pos+4, cmd.npos));
			q.push(arg);
			continue;
		}
		if ((pos=cmd.find("pop")) != cmd.npos) {
			if (q.empty()) cout << -1 << '\n';
			else {
				int front = q.front();
				q.pop();
				cout << front << '\n';
			}

			continue;
		}
		if ((pos=cmd.find("size")) != cmd.npos) {
			cout << q.size() << '\n';
			continue;
		}
		if ((pos=cmd.find("empty")) != cmd.npos) {
			cout << q.empty() << '\n';
			continue;
		}
		if ((pos=cmd.find("front")) != cmd.npos) {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';

			continue;
		}
		if ((pos=cmd.find("back")) != cmd.npos) {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';

			continue;
		}
	}

	return 0;
}