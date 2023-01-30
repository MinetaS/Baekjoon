#include <cstdio>
#include <vector>

int main() {
	int n;
	std::vector<bool> bracket;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		char str[51];
		bool is_vps = true;

		scanf("%s", str);
		bracket.clear();

		for (int d=0 ; str[d]!=0 ; d++) {
			if (str[d] == '(') bracket.push_back(true);
			if (str[d] == ')') {
				if (bracket.empty()) {
					is_vps = false;
					break;
				}

				bracket.pop_back();
			}
		}

		if (is_vps) is_vps = bracket.empty();

		if (is_vps) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}