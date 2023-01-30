#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int disposition(int, int, int);

int sector, cover;
int area1[10001];
int area2[10001];
int cache[10001][3];

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &sector, &cover);
		
		for (int i=0 ; i<sector ; i++)
			scanf("%d", area1+i);

		for (int i=0 ; i<sector ; i++)
			scanf("%d", area2+i);
		
		if (sector == 1) {
			if (area1[0]+area2[0] <= cover) printf("1\n");
			else printf("2\n");
			continue;
		}

		int result = 987654321;
		area1[sector] = area1[sector-1];
		area2[sector] = area2[sector-1];
		
		bool f1 = area1[0]+area1[sector-1] <= cover;
		bool f2 = area2[0]+area2[sector-1] <= cover;

		if (f1 && f2) {
			memset(cache, -1, sizeof(cache));
			result = min(disposition(1, 0, sector-1)+2, result);
		}
		if (f1) {
			memset(cache, -1, sizeof(cache));
			area1[sector-1] = 0;
			result = min(disposition(0, 1, sector)+1, result);
			area1[sector-1] = area1[sector];
		}
		if (f2) {
			memset(cache, -1, sizeof(cache));
			area2[sector-1] = 0;
			result = min(disposition(0, 2, sector)+1, result);
			area2[sector-1] = area2[sector];
		}

		memset(cache, -1, sizeof(cache));
		result = min(disposition(0, 0, sector), result);

		printf("%d\n", result);
	}
	
	return 0;
}

int disposition(int pos, int current, int end) {
	int ret = 987654321;

	if (pos >= end) return 0;
	if (cache[pos][current] != -1) return cache[pos][current];

	bool cover0 = (current==0) && (area1[pos]+area2[pos]<=cover);
	bool cover1 = (current!=1) && (area1[pos]+area1[pos+1]<=cover);
	bool cover2 = (current!=2) && (area2[pos]+area2[pos+1]<=cover);

	if (pos == end-1) {
		cover1 = false;
		cover2 = false;
	}

	if (cover0) ret = min(disposition(pos+1, 0, end)+1, ret);
	if (cover1 && cover2) ret = min(disposition(pos+2, 0, end)+2, ret);
	else {
		if (cover1) ret = min(disposition(pos+1, 1, end)+1+((current==0) ? 1 : 0), ret);
		if (cover2) ret = min(disposition(pos+1, 2, end)+1+((current==0) ? 1 : 0), ret);
	}

	int ag = 0;
	if (current!=1 && area1[pos]!=0) ag += 1;
	if (current!=2 && area2[pos]!=0) ag += 1;

	ret = min(disposition(pos+1, 0, end)+ag, ret);

	return cache[pos][current] = ret;
}