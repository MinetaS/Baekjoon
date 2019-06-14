#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void form(vector<char> &, int, int, int);

char set[15];
int l, charset;

int main() {
	scanf("%d %d\n", &l, &charset);

	for (int i=0 ; i<charset ; i++) {
		scanf("%c", set+i);
		if (i != charset-1) getchar();
	}

	sort(set, set+charset);
	form(*(new vector<char>), 0, 0, 0);

	return 0;
}

void form(vector<char> &_Str, int _Index, int c, int v) {
	if (_Str.size() == l) {
		if (c>=2 && v>=1) {
			for (int i=0 ; i<l ; i++) putc(_Str[i], stdout);
			putc('\n', stdout);
		}

		return;
	}

	for (int i=_Index ; i<charset ; i++) {
		char _c = set[i];
		_Str.push_back(_c);

		if (_c=='a' || _c=='e' || _c=='i' || _c=='o' || _c=='u') form(_Str, i+1, c, v+1);
		else form(_Str, i+1, c+1, v);

		_Str.pop_back();
	}
}