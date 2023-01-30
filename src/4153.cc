#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int edge[3];

		scanf("%d %d %d", edge, edge+1, edge+2);
		sort(edge, edge+3);
		
		if ((edge[0] | edge[1] | edge[2]) == 0) break;
		if (edge[0]*edge[0]+edge[1]*edge[1] == edge[2]*edge[2]) printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}