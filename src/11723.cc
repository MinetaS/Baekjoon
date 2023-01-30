#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int set[20] = {0,};
	int cmds;

	cin >> cmds;

	for (int i=0 ; i<cmds ; i++) {
		string cmd;
		int arg;

		cin >> cmd;

		if (cmd == "add") {
			cin >> arg;
			set[arg-1] = true;
			continue;
		}

		if (cmd == "remove") {
			cin >> arg;
			set[arg-1] = false;
			continue;
		}

		if (cmd == "check") {
			cin >> arg;
			cout << set[arg-1] << '\n';
			continue;
		}

		if (cmd == "toggle") {
			cin >> arg;
			set[arg-1] ^= 0x1;
			continue;
		}

		if (cmd == "all") {
			for (int i=0 ; i<20 ; i++)
				set[i] = true;
			continue;
		}

		if (cmd == "empty")	memset(set, 0, sizeof(set));
	}

	return 0;
}