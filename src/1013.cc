#include <cstdio>
#include <cstring>

int match(char *sample) {
	if (strlen(sample) == 0) return true;
	if (strlen(sample) == 1) return false;

	if (sample[0] == '0') {
		if (sample[1] == '0') return false;
		if (match(sample+2)) return true;
	}
	
	if (sample[0] == '1') {
		if (strlen(sample) < 4) return false;

		if (sample[1] == '1') return false;
		if (sample[1]=='0' && sample[2]=='1') return false;

		int zero_chain_break = false;
		for (int i=3 ; i<strlen(sample) ; i++) {
			if (sample[i] == '1') {
				zero_chain_break = true;
				if (match(sample+i+1)) return true;
			}
			
			if (sample[i] == '0') {
				if (zero_chain_break) break;
				continue;
			}
		}
	}

	return false;
}

int main() {
	int _case;
	char received[200];

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%s", received);

		if (match(received)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}