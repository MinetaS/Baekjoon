#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
	int n;
	int freq[26];
	int max_freq, max_char;
	bool dup;

	scanf("%d\n", &n);

	for (int i=0 ; i<n ; i++) {
		int c;
		memset(freq, 0, sizeof(freq));
		max_freq = 0;
		max_char = -1;
		dup = false;

		while ((c=getchar()) != 10) {
			if (!isalpha(c)) continue;
			
			freq[c-97]++;

			if (freq[c-97] == max_freq) dup = true;
			else if (freq[c-97] > max_freq) {
				max_freq = freq[c-97];
				max_char = c;
				dup = false;
			}
		}

		if (dup) printf("?\n");
		else printf("%c\n", max_char);
	}

	return 0;
}