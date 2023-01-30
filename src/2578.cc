#include <cstdio>
#include <cstring>

class BingoBoard {
private:
	bool fastmap[25];

public:
	int map[25];

	BingoBoard() {
		memset(fastmap, 0, sizeof(fastmap));
	}

	void mark(int _Val) {
		for (int i=0 ; i<25 ; i++) {
			if (map[i] == _Val) {
				fastmap[i] = true;
				return;
			}
		}
	}

	bool check() {
		int c = 0;

		if (fastmap[0] && fastmap[5] && fastmap[10] && fastmap[15] && fastmap[20]) c++;
		if (fastmap[1] && fastmap[6] && fastmap[11] && fastmap[16] && fastmap[21]) c++;
		if (fastmap[2] && fastmap[7] && fastmap[12] && fastmap[17] && fastmap[22]) c++;
		if (fastmap[3] && fastmap[8] && fastmap[13] && fastmap[18] && fastmap[23]) c++;
		if (fastmap[4] && fastmap[9] && fastmap[14] && fastmap[19] && fastmap[24]) c++;
		if (fastmap[0] && fastmap[1] && fastmap[2] && fastmap[3] && fastmap[4]) c++;
		if (fastmap[5] && fastmap[6] && fastmap[7] && fastmap[8] && fastmap[9]) c++;
		if (fastmap[10] && fastmap[11] && fastmap[12] && fastmap[13] && fastmap[14]) c++;
		if (fastmap[15] && fastmap[16] && fastmap[17] && fastmap[18] && fastmap[19]) c++;
		if (fastmap[20] && fastmap[21] && fastmap[22] && fastmap[23] && fastmap[24]) c++;
		if (fastmap[0] && fastmap[6] && fastmap[12] && fastmap[18] && fastmap[24]) c++;
		if (fastmap[4] && fastmap[8] && fastmap[12] && fastmap[16] && fastmap[20]) c++;

		if (c >= 3) return true;
		else return false;
	}
};

int main() {
	BingoBoard board;

	for (int i=0 ; i<25 ; i++) scanf("%d", &board.map[i]);

	for (int i=0, t ; i<25 ; i++) {
		scanf("%d", &t);
		board.mark(t);
		if (board.check()) {
			printf("%d", i+1);
			break;
		}
	}

	return 0;
}