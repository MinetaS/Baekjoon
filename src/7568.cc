#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Profile {
	int weigh;
	int height;
	int rank;
};

int compare_profile(Profile &, Profile &);

int main() {
	int n, w, h;
	vector<Profile> people;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d %d", &w, &h);
		people.push_back({w, h, 0});
	}
	
	
	for (int i=0 ; i<n ; i++) {
		int r = 1;

		for (int j=0 ; j<n ; j++) {
			if (i == j) continue;
			if (compare_profile(people[i], people[j]) == -1) r++;
		}

		people[i].rank = r;
	}
	
	for (int i=0 ; i<n ; i++)
		printf("%d ", people[i].rank);

	return 0;
}

int compare_profile(Profile &arg0, Profile &arg1) {
	if (arg0.weigh>arg1.weigh && arg0.height>arg1.height) return 1;
	else if (arg0.weigh<arg1.weigh && arg0.height<arg1.height) return -1;
	else return 0;
}