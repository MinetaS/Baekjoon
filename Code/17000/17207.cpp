#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a[5][5];
	int b[5][5];
	int w[5][5];
	int s[5];

	string name[5] = {string("Inseo"), string("Junsuk"), string("Jungwoo"), string("Jinwoo"), string("Youngki")};
	int min = 99999999;
	int index = -1;

	for (int i=0 ; i<5 ; i++)
		for (int j=0 ; j<5 ; j++)
			scanf("%d", &a[i][j]);

	for (int i=0 ; i<5 ; i++)
		for (int j=0 ; j<5 ; j++)
			scanf("%d", &b[i][j]);

	for (int i=0 ; i<5 ; i++) {
		for (int j=0 ; j<5 ; j++) {
			w[i][j] = 0;

			for (int p=0 ; p<5 ; p++)
				w[i][j] += a[i][p]*b[p][j];
		}
	}

	for (int i=0 ; i<5 ; i++) {
		s[i] = 0;

		for (int j=0 ; j<5 ; j++)
			s[i] += w[i][j];
	}

	for (int i=0 ; i<5 ; i++) {
		if (s[i] < min) {
			min = s[i];
			index = i;
		}
		else if (s[i] == min)
			if (!lexicographical_compare(name[i].begin(), name[i].end(), name[index].begin(), name[index].end())) index = i;
	}

	printf("%s", name[index].c_str());

	return 0;
}