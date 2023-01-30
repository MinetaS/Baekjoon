#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> set;
	int begin, end;

	for (int i=0 ; i<20 ; i++)
		set.push_back(i+1);

	for (int i=0 ; i<10 ; i++) {
		scanf("%d %d", &begin, &end);
		reverse(set.begin()+begin-1, set.begin()+end);
	}

	for (int &e : set)
		printf("%d ", e);

	return 0;
}