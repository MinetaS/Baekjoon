#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Profile {
	string name;
	int age;
	int join;
};

Profile users[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for (int i=0 ; i<n ; i++) {
		cin >> users[i].age >> users[i].name;
		users[i].join = i+1;
	}

	std::sort(users, users+n, [](Profile arg0, Profile arg1) {return arg0.age<arg1.age || (arg0.age==arg1.age && arg0.join<arg1.join);});

	for (int i=0 ; i<n ; i++)
		cout << users[i].age << " "+users[i].name << '\n';

	return 0;
}