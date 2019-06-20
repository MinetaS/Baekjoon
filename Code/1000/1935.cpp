#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int n;
	int value[26];
	char expr[101];
	
	scanf("%d", &n);
	scanf("%s", expr);
	for (int i=0 ; i<n ; i++) scanf("%d", value+i);
	
	deque<long double> q;
	int result = 0;

	for (int i=0 ; expr[i]!=0 ; i++) {
		if (expr[i]>=65 && expr[i]<=90) q.push_back((long double)value[expr[i]-65]);
		else {
			long double rop = q.back();
			q.pop_back();
			long double lop = q.back();
			q.pop_back();

			switch (expr[i]) {
			case '+':
				q.push_back(lop+rop);
				break;

			case '-':
				q.push_back(lop-rop);
				break;

			case '*':
				q.push_back(lop*rop);
				break;

			case '/':
				q.push_back(lop/rop);
				break;
			}
		}
	}

	printf("%.2Lf", q.back());

	return 0;
}