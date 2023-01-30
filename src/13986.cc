#include <cstdio>
#include <algorithm>

using namespace std;

class PhysicMap {
private:
	int **_Map;
	int _Width;
	int _Height;

public:
	PhysicMap() : _Width(1), _Height(1) {
		_Map = new int *;
		_Map[0] = new int;
		_Map[0][0] = 0;
	}

	PhysicMap(int width, int height) : _Width(width), _Height(height) {
		_Map = new int *[height];
		for (int i=0 ; i<height ; i++) {
			_Map[i] = new int[width];
			for (int j=0 ; j<width ; j++) _Map[i][j] = 0;
		}
	}

	~PhysicMap() {
		for (int i=0 ; i<_Height ; i++) delete[] _Map[i];
		delete[] _Map;
	}
	
	char at(int _x, int _y) {
		switch (_Map[_y][_x]) {
		case 0: return '.';
		case 1: return 'o';
		case 2: return '#';
		}

		return '?';
	}

	void place(int _Object, int _x, int _y) {
		_Map[_y][_x] = _Object;
	}

	void set_gravity(int _x, int _y) {
		if (_Map[_y][_x] != 1) return;

		int y = _y;
		
		while (y!=_Height-1 && _Map[y+1][_x]==0) {
			swap(_Map[y][_x], _Map[y+1][_x]);
			y++;
		}
	}
};

int main() {
	int w, h;

	scanf("%d %d", &h, &w);
	PhysicMap map(w, h);

	for (int i=0 ; i<h ; i++) {
		char buf[51];

		scanf("%s", buf);

		for (int j=0 ; j<w ; j++) {
			if (buf[j] == '.') map.place(0, j, i);
			if (buf[j] == 'o') map.place(1, j, i);
			if (buf[j] == '#') map.place(2, j, i);
		}
	}

	for (int i=h-1 ; i>=0 ; i--)
		for (int j=0 ; j<w ; j++) map.set_gravity(j, i);

	for (int i=0 ; i<h ; i++) {
		for (int j=0 ; j<w ; j++) printf("%c", map.at(j, i));
		printf("\n");
	}

	return 0;
}