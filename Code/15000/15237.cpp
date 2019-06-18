#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Frequency {
	int n;
	int begin;
	int freq;
};

int main() {
	int n;
	vector<Frequency> freq;

	scanf("%d %*d", &n);

	for (int t, i=0 ; i<n ; i++) {
		int size = freq.size();
		int j;

		scanf("%d", &t);

		for (j=0 ; j<size ; j++)
			if (freq[j].n == t) break;
		
		if (j == size) freq.push_back({t, i, 1});
		else freq[j].freq++;
	}

	sort(freq.begin(), freq.end(), [](Frequency &_Left, Frequency &_Right) {return (_Left.freq == _Right.freq) ? (_Left.begin < _Right.begin) : (_Left.freq > _Right.freq);});
	
	for (Frequency &f : freq)
		for (int i=0 ; i<f.freq ; i++) printf("%d ", f.n);

	return 0;
}