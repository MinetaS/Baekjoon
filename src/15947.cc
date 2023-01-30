#include <cstdio>
#include <string>

using namespace std;

int main() {
	const string text[14] = {"baby", "sukhwan", "*", "*", "very", "cute", "*", "*", "in", "bed", "*", "*", "baby", "sukhwan"};
	int n;

	scanf("%d", &n);
	
	if (text[(n-1)%14] != "*") printf("%s", text[(n-1)%14].c_str());
	else {
		if (n & 1) {
			if (n/14 >= 3) printf("tu+ru*%d", n/14+2);
			else {
				printf("tu");
				for (int i=0 ; i<n/14+2 ; i++) printf("%s", "ru");
			}
		}
		else {
			if (n/14 >= 4) printf("tu+ru*%d", n/14+1);
			else {
				printf("tu");
				for (int i=0 ; i<n/14+1 ; i++) printf("%s", "ru");
			}
		}
	}

	return 0;
}