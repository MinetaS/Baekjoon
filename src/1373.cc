#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	string result;
	int i=0, t=0;

	cin >> str;
	reverse(str.begin(), str.end());

	int l = str.length();

	while (true) {
		if (i == l) break;
		
		t += (str[i]-48) << (i%3);
		
		if (i%3 == 2) {
			result.push_back(t+48);
			t = 0;
		}

		i++;
	}

	if (t!=0 || result.empty()) result.push_back(t+48);
	reverse(result.begin(), result.end());
	
	cout << result;

	return 0;
}