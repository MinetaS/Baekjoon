#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Character {
	char c;
	int s;
};

int main() {
	int words;
	vector<Character> value;

	scanf("%d", &words);

	for (int i=0 ; i<words ; i++) {
		char word[9];
		int len;
		int mp = 1;

		scanf("%s", word);
		len = strlen(word);

		for (int f, j=len-1 ; j>=0 ; j--) {
			for (f=0 ; f<value.size() ; f++)
				if (value[f].c == word[j]) break;

			if (f == value.size()) value.push_back({word[j], mp});
			else value[f].s += mp;

			mp *= 10;
		}
	}

	sort(value.begin(), value.end(), [](const Character &_Left, const Character &_Right) {return _Left.s > _Right.s;});

	int sum = 0;

	for (int i=0 ; i<value.size() ; i++) sum += (9-i)*value[i].s;

	printf("%d", sum);

	return 0;
}