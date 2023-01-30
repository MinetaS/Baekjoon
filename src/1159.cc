#include <cstdio>

int main() {
	int n;
	char str[31];
	
	scanf("%d", &n);
	
	bool resign = true;
	int vorname[26] = {0,};

	for (int i=0 ; i<n ; i++) {
		scanf("%s", str);
		if (++vorname[str[0]-97] == 5) resign = false;
	}

	if (resign) printf("PREDAJA");
	else for (int i=0 ; i<26 ; i++)
		if (vorname[i] >= 5) printf("%c", i+97);

	return 0;
}