#include <cstdio>>
#include <vector>

#define LF 10

using namespace std;

int main() {
	const char *cmp = ":cat:";
	int emoji, end_flag, t;

	emoji = false;
	end_flag = false;
	t = 0;

	while (true) {
		char c = getchar();

		if (c == LF) {
			if (end_flag) break;

			if (emoji) printf("YES\n");
			else printf("NO\n");

			emoji = false;
			end_flag = true;
			t = 0;
		}

		end_flag = false;

		if (emoji) continue;
		if (c == cmp[t]) {
			if (t == 4) emoji = true;
			else t++;
		}
	}

	return 0;
}