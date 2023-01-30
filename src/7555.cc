/* GNU Dependent */

#include <stdio.h>
#include <string.h>

int main() {
	int _case;
	int scenario = 1;
	int N;

	const char *place[4] = {"cinema", "cocktail bar", "disco", "stay at the Hacienda"};
	const char *friends[7] = {"Anne", "Bob", "Karin", "Charly", "Dave", "Edward", "Frank"};

	scanf("%d", &_case);
	getchar();
	N = _case;

	while (_case > 0) {
		_case--;

		bool attend[7] = {0,};
		int vote[7] = {0,};   // 1:cinema, 10:cocktail bar, 100:disco

		// Input Process
		char buffer[200];
		char _tmp[100];

		fgets(buffer, 200, stdin);
		buffer[strlen(buffer)-1] = 0;

		int index = 0;
		int length = 0;

		while (index != strlen(buffer)+1) {
			if (buffer[index]==32 || buffer[index]==0) {
				_tmp[length] = 0;
				length = 0;

				for (int i=0 ; i<7 ; i++) {
					if (strcmp(_tmp, friends[i]) == 0) {
						attend[i] = true;
						break;
					}
				}
			}
			else {
				_tmp[length] = buffer[index];
				length++;
			}

			index++;
		}

		// Solve
		if (attend[0]) vote[0] += 1;   // Anne
		if (attend[1]) {   // Bob
			if (attend[2]) vote[1] += 100;
			if (!attend[0] || attend[4] || attend[5]) vote[1] += 10;
		}
		if (attend[2]) {   // Karin
			if (attend[3]) vote[2] += 100;
			if (attend[0] && !attend[3]) vote[2] += 1;
			if (!attend[0] && !attend[3]) vote[2] += 10;
		}
		if (attend[3]) {   // Charly
			if (attend[0]) vote[3] += 1;
		}
		if (attend[4]);   // Dave
		if (attend[5]) {   // Edward
			if (attend[0] && !attend[3]) vote[5] += 10;
			else vote[5] += 1;
		}
		if (attend[6]) {   // Frank
			if (!attend[0] && !attend[1]) vote[6] += 1;
			if (attend[0]) vote[6] += 100;
		}

		int vote_result[3] = {0,};

		for (int i=0 ; i<7 ; i++) {
			if (vote[i] == 1) vote_result[0]++;
			if (vote[i] == 10) vote_result[1]++;
			if (vote[i] == 100) vote_result[2]++;
		}

		int result;

		result = (vote_result[0] > vote_result[1]) ? 0 : 1;
		result = (vote_result[result] > vote_result[2]) ? result : 2;
		for (int i=0 ; i<3 ; i++) {
			if (i == result) continue;
			if (vote_result[i] == vote_result[result]) {
				result = 3;
				break;
			}
		}

		// Output
		printf("Scenario #%d:\n%s", scenario, place[result]);
		if (scenario != N) printf("\n\n");
		scenario++;
	}

	return 0;
}