#include <cstdio>
#include <cstring>

void print_postorder(char *, char *, int);

int main() {
	char pre[27], in[27];

	while (scanf("%s %s", pre, in) != EOF) {
		print_postorder(pre, in, strlen(pre));
		printf("\n");
	}

	return 0;
}

void print_postorder(char *_Pre, char *_In, int _Size) {
	int r_index = -1;

	for (int i=0 ; i<_Size ; i++) {
		if (_In[i] == _Pre[0]) {
			r_index = i;
			break;
		}
	}

	if (r_index != 0) print_postorder(_Pre+1, _In, r_index);
	if (r_index != _Size-1) print_postorder(_Pre+r_index+1, _In+r_index+1, _Size-r_index-1);

	printf("%c", _Pre[0]);
}