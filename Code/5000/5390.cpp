#include <cstdio>
#include <vector>

using namespace std;

vector<int> inverse_permutation(const vector<int> &);

int main() {
	int _case;
	
	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n;
		vector<int> sample1;
		vector<int> sample2;
		vector<int> sample2_inverse;

		int begin_index = 0;
		int max = 0;

		scanf("%d", &n);
		sample1 = vector<int>(n);
		sample2 = vector<int>(n);

		for (int i=0 ; i<n ; i++) scanf("%d", &sample1[i]);
		for (int i=0 ; i<n ; i++) scanf("%d", &sample2[i]);
		sample2_inverse = inverse_permutation(sample2);

		for (int i=0 ; i<n ; i++) {
			if (sample2_inverse[sample1[i]-1] > max) max = sample2_inverse[sample1[i]-1];
			if (max == i+1) {
				printf("%d-%d ", begin_index+1, i+1);
				begin_index = i+1;
			}
		}

		printf("\n");
	}

	return 0;
}

vector<int> inverse_permutation(const vector<int> &_Src) {
	int v1 = _Src.size();
	vector<int> v2(_Src.size());

	for (int i=0 ; i<v1 ; i++) {
		if (_Src[i] > v1) return *(new vector<int>);
		v2[_Src[i]-1] = i+1;
	}

	return v2;
}