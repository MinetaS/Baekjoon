#include <cstdio>

int power[1000000];
int lp[1000000];
int rp[1000000];
int lpm=-1, rpm=-1;

int main() {
	int n;
	int red=0, blue=0;
	
	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", power+i);

		if (power[i] > lpm) lpm = power[i];
		lp[i] = lpm;
	}

	for (int i=n-1 ; i>=0 ; i--) {
		if (power[i] > rpm) rpm = power[i];
		rp[i] = rpm;
	}

	for (int i=0 ; i<n-1 ; i++) {
		if (lp[i] > rp[i+1]) red++;
		if (lp[i] < rp[i+1]) blue++;
	}

	if (red > blue) printf("R");
	else if (red < blue) printf("B");
	else printf("X");

	return 0;
}