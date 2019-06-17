#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string sample[6] = {"Give you up", "Let you down", "Run around and desert you", "Make you cry", "Say goodbye", "Tell a lie and hurt you"};
	string text;
	int i;

	getline(cin, text);

	for (i=0 ; i<6 ; i++) {
		if (sample[i] == text) {
			printf("NO");
			break;
		}
	}

	if (i == 6) printf("YES");

	return 0;
}