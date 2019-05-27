#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;

		cin >> s;

		if (s == "end") break;

		size_t len = s.length();
		bool accept = true;
		bool v_ap = false;
		int consonant = 0;
		int vowel = 0;
		char prev_char = 0;

		for (char &c : s) {
			if (is_vowel(c)) {
				v_ap = true;
				consonant = 0;
				vowel++;
			}
			else {
				consonant++;
				vowel = 0;
			}

			if (vowel==3 || consonant==3) {
				cout << "<" << s << "> is not acceptable." << '\n';
				accept = false;
				break;
			}

			if (c!='e' && c!='o' && prev_char==c) {
				cout << "<" << s << "> is not acceptable." << '\n';
				accept = false;
				break;
			}

			prev_char = c;
		}

		if (accept) {
			if (!v_ap) cout << "<" << s << "> is not acceptable." << '\n';
			else cout << "<" << s << "> is acceptable." << '\n';
		}
	}

	return 0;
}

bool is_vowel(char character) {
	if (character=='a' || character=='e' || character=='i' || character=='o' || character=='u') return true;
	return false;
}