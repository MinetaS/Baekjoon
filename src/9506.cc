#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void init_primes(vector <int> &, int);
int sum_factor(int, const vector<int> &);

int main() {
	vector<int> primes;
	vector<int> factors;
	int n;

	primes.reserve(78500);
	init_primes(primes, 100000);

	while (true) {
		scanf("%d", &n);

		if (n == -1) break;

		factors.clear();

		if (sum_factor(n, primes)-n == n) {
			for (int i=1 ; i*i<=n ; i++) {
				if (n%i == 0) {
					factors.push_back(i);
					factors.push_back(n/i);
				}
			}

			sort(factors.begin(), factors.end());

			printf("%d = 1", n);
			for (int i=1 ; i<factors.size()-1 ; i++) printf(" + %d", factors[i]);
			printf("\n");
		}
		else printf("%d is NOT perfect.\n", n);
	}

	return 0;
}

void init_primes(vector<int> &_Ref, int _Max_Val) {
	bool *pt = new bool[_Max_Val+1];

	memset(pt, 1, (_Max_Val+1)*sizeof(bool));
	pt[0] = false;
	pt[1] = false;

	for (int i=2 ; i<=_Max_Val ; i++) {
		if (!pt[i]) continue;
		_Ref.push_back(i);

		for (int j=2*i ; j<=_Max_Val ; j+=i) pt[j] = false;
	}

	delete[] pt;
}

int sum_factor(int _Val, const vector<int> &_Prime) {
	int ret = 1;

	for (int p : _Prime) {
		if (p*p > _Val) break;

		int r = 1;
		int s = 1;

		while (_Val%p == 0) {
			_Val /= p;
			r *= p;
			s += r;
		}

		ret *= s;
	}

	if (_Val >= 2) ret *= _Val+1;

	return ret;
}