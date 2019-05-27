#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct KeyboardInput {
	int index;
	int time;
	char character;
};

bool compare(KeyboardInput &, KeyboardInput &);

int main() {
	int n, m;
	vector<KeyboardInput> inputs;

	scanf("%d %d", &n, &m);
	inputs.reserve(1000000);

	for (int i=0 ; i<m ; i++) {
		int a, b;
		char c;

		scanf("%d %d %c", &a, &b, &c);
		inputs.push_back({a, b, c});
	}

	sort(inputs.begin(), inputs.end(), compare);

	for (KeyboardInput &input : inputs)
		printf("%c", input.character);

	return 0;
}

bool compare(KeyboardInput &arg0, KeyboardInput &arg1) {
	if (arg0.time < arg1.time) return true;
	if (arg0.time == arg1.time)
		if (arg0.index < arg1.index) return true;

	return false;
}