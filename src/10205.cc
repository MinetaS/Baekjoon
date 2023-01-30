#include <cstdio>

int main() {
	int _case;
	int set = 1;
	int end_set;

	scanf("%d", &_case);
	end_set = _case;
	
	while (_case > 0) {
		_case--;

		int head;
		char act[101];

		scanf("%d", &head);
		scanf("%s", act);

		for (int i=0 ; act[i]!=0 ; i++) {
			if (act[i] == 'c') head++;
			else head--;
		}

		printf("Data Set %d:\n%d", set, head);
		if (set != end_set) printf("\n\n");

		set++;
	}

	return 0;
}