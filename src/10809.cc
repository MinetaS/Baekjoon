#include <stdio.h>
#include <string.h>

int main() {
	char str[101];
	int alphabets[26];
	
	memset(alphabets, -1, sizeof(alphabets));

	scanf("%s", str);

	for (int i=0 ; str[i]!=0 ; i++)
		if (alphabets[str[i]-97]==-1) alphabets[str[i]-97] = i;

	for (int i=0 ; i<26 ; i++)
		printf("%d ", alphabets[i]);

	return 0;
}