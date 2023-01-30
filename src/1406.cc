#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string init;
	int commands;

	cin >> init;
	cin >> commands;
	
	list<char> editor(init.begin(), init.end());
	auto pos = editor.end();

	for (int i=0 ; i<commands ; i++) {
		char command;

		cin >> command;

		if (command == 'L') {
			if (pos != editor.begin()) pos--;
			continue;
		}

		if (command == 'D') {
			if (pos != editor.end()) pos++;
			continue;
		}

		if (command == 'B') {
			if (pos != editor.begin()) pos = editor.erase(--pos);
			continue;
		}

		if (command == 'P') {
			char letter;
			cin >> letter;

			editor.insert(pos, letter);
		}
	}

	for (char &c : editor)
		cout << c;

	return 0;
}