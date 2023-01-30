#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> stack;

	string _tmp;
	getline(cin, _tmp);
	n = stoi(_tmp);

	for (int i=0 ; i<n ; i++) {
		string cmd;
		size_t pos;

		getline(cin, cmd);

		if ((pos=cmd.find("push")) != cmd.npos) {
			int arg = stoi(cmd.substr(pos+4, cmd.npos));
			stack.push_back(arg);
			continue;
		}
		if ((pos=cmd.find("pop")) != cmd.npos) {
			if (stack.empty()) cout << -1 << '\n';
			else {
				int top = stack.back();
				stack.pop_back();
				cout << top << '\n';
			}

			continue;
		}
		if ((pos=cmd.find("size")) != cmd.npos) {
			cout << stack.size() << '\n';
			continue;
		}
		if ((pos=cmd.find("empty")) != cmd.npos) {
			cout << stack.empty() << '\n';
			continue;
		}
		if ((pos=cmd.find("top")) != cmd.npos) {
			if (stack.empty()) cout << -1 << '\n';
			else cout << stack.back() << '\n';

			continue;
		}
	}

	return 0;
}