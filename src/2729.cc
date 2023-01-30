#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int _case;

	cin >> _case;

	while (_case--) {
		string num1, num2;
		string result;

		cin >> num1 >> num2;

		int cut;

		if ((cut=num1.find('1')) == string::npos) num1 = "0";
		else num1 = num1.substr(cut);
		if ((cut=num2.find('1')) == string::npos) num2 = "0";
		else num2 = num2.substr(cut);

		int len1 = num1.length();
		int len2 = num2.length();

		if (len1 < len2) {
			num1.swap(num2);
			swap(len1, len2);
		}

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for (int i=0 ; i<len1 ; i++) {
			if (i >= len2) result.push_back(num1[i]);
			else result.push_back(num1[i]+num2[i]-48);
		}

		for (int i=0 ; i<result.size()-1 ; i++) {
			if (result[i] > '1') {
				result[i] -= 2;
				result[i+1]++;
			}
		}

		if (result[result.size()-1] > '1') {
			result[result.size()-1] -= 2;
			result.push_back('1');
		}

		reverse(result.begin(), result.end());

		cout << result << '\n';
	}

	return 0;
}