#include <iostream>
#include <vector>

using namespace std;

/* Class Definition : Items */
/* Type :: 0:{Invalid}, 1:Weapon, 2:Armor, 3:Accessory */

class Weapon{
private:
	int type;
	int attack;

public:
	Weapon() {
		type = 1;
		attack = 0;
	}

	Weapon(int atk) {
		Weapon();

		attack = atk;
	}
};

class Armor {
private:
	int type;
	int defense;

public:
	Armor() {
		type = 2;
		defense = 0;
	}

	Armor(int def) {
		Armor();

		defense = def;
	}
};

class AccessoryOption {
private:
	int type;   // 0:{Invalid}, 1:HR, 2:RE, 3:CO, 4:EX, 5:DX, 6:HU, 7:CU

public:
	AccessoryOption() {
		type = 0;
	}

	AccessoryOption(int type) {
		this->type = type;
	}
};

class Accessory {
	int type;
	vector<AccessoryOption> options;

public:
	Accessory() {
		type = 3;
		options = vector<AccessoryOption>();
	}

	void addOption(AccessoryOption option) {
		options.push_back(option);
	}

	void clearOption() {
		options.clear();
	}

	vector<AccessoryOption> getOptions() {
		return options;
	}
};

union Item {
	Weapon weapon;
	Armor armor;
	Accessory accessory;
};


/* Class Definition : Map Objects */
/* Type :: 0:Blank, 1:Wall, 2:ItemBox, 3:Trap, 4:Monster */

class Blank {
private:
	int type;

public:
	Blank() {
		type = 0;
	}
};
class Wall {
private:
	int type;

public:
	Wall() {
		type = 1;
	}
};

class ItemBox {
private:
	int type;
	int equipment;   // 0:{Invalid}, 1:Weapon, 2:Armor, 3:Accessory
	bool open;

public:
	ItemBox() {
		type = 2;

		equipment = 0;
		open = false;
	}

	ItemBox(int item_type) {
		ItemBox();

		equipment = item_type;
	}
};

class Trap {
private:
	int type;

public:
	Trap() {
		type = 3;
	}
};

class Monster {
private:
	int type;
	bool boss;
	string name;
	int attack;
	int defense;
	int health;
	int max_health;
	int exp_reward;

public:
	Monster() {
		type = 4;

		boss = false;
		name = "";
		attack = 0;
		defense = 0;
		health = 0;
		max_health = 0;
		exp_reward = 0;
	}

	Monster(int atk, int def, int hp, int exp) {
		Monster();

		attack = atk;
		defense = def;
		health = hp;
		max_health = hp;
		exp_reward = exp;
	}

	void setBoss(bool is_boss) {
		boss = is_boss;
	}
};

union MapObject {
	Blank blank;

};
/* Class Definition : Base Settings */

class MapPosition {
private:
	MapObject object;

public:
	MapPosition() {
		object = MapObject();
	}

	MapPosition(MapObject map_object) {
		object = map_object;
	}

	bool hasObject() {
		if (object.getType() == 0) return false;
		else return true;
	}
};

class Map {
private:
	int width;
	int height;
	vector<vector<MapPosition>> grid;

public:
	Map() : width(1), height(1) {
		grid = vector<vector<MapPosition>>(1, vector<MapPosition>(1, MapPosition()));
	}

	Map(int width, int height) {
		this->width = width;
		this->height = height;
		grid = vector<vector<MapPosition>>(height, vector<MapPosition>(width, MapPosition()));
	}

	void setMapPosition(int x, int y, MapPosition info) {
		grid[y-1][x-1] = info;
	}

	MapPosition getMapPosition(int x, int y) {
		return grid[y-1][x-1];
	}
};

class Character {
private:
	int init_x;
	int init_y;
	int x;
	int y;

	int attack;
	int defense;
	int health;
	int max_health;
	int exp;


public:
	Character() {
		init_x = 0;
		init_y = 0;
		x = 0;
		y = 0;
		attack = 2;
		defense = 2;
		health = 20;
		max_health = 20;
		exp = 0;
	}

	Character(int init_x, int init_y) {
		Character();

		this->init_x = init_x;
		this->init_y = init_y;
	}
};


/* Main Routine */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Map game;
	Character player;

	int n, m;
	string act;

	cin >> n >> m;
	game = Map(m, n);

	for (int i=1 ; i<=n ; i++) {
		string s;
		cin >> s;

		for (int j=1 ; j<=m ; j++) {
			char c = s[j-1];
			MapPosition block;

			if (c == '@') {
				player = Character(j, i);
				block = MapPosition(MapObject());
			}

			if (c == '.') block = MapPosition(MapObject());
			else if (c == '#') block = MapPosition(Wall());
			else if (c == 'B') block = MapPosition(ItemBox());
			else if (c == '^') block = MapPosition(Trap());
			else if (c == '&') block = MapPosition(Monster());
			else if (c == 'M') {
				Monster object = Monster();
				object.setBoss(true);
				block = MapPosition(object);
			}
			else {
				cout << "[Error] Unknown Error Occured. (x=" << j << ", y=" << i << ")" << '\n';
				continue;
			}

			game.setMapPosition(j, i, block);
		}
	}

	cin >> act;


}