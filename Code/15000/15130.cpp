#include <cstdio>

int main() {
	int begin, end;
	int begin_index = -1;
	int end_index = -1;

	for (int t, i=0 ; i<10 ; i++) {
		scanf("%d", &t);
		if (t!=0 && begin_index==-1) {
			begin = t;
			begin_index = i;
		}
		else if (t != 0) {
			end = t;
			end_index = i;
		}
	}

	int d = (end-begin)/(end_index-begin_index);

	if (d*(end_index-begin_index) != end-begin) printf("-1");
	else for (int i=0 ; i<10 ; i++) printf("%d ", begin+d*(i-begin_index));

	return 0;
}