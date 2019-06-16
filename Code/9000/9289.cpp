#include <cstdio>

int main() {
	constexpr char morse[79] = "0ET*IA*NM****SU*RW****DK*GO*************HV*F*****L**PJ*************BX*CY****ZQ";
	int _case;

	scanf("%d\n", &_case);

	for (int _c_index=0 ; _c_index<_case ; _c_index++) {
		char buf[5];

		printf("Case %d: ", _c_index+1);

		for (int i=0 ; i<5 ; i++) {
			int character = 0;

			scanf("%s", buf);

			for (int j=0 ; buf[j]!=0 ; j++) {
				if (buf[j] == '.') character = character*3+1;
				if (buf[j] == '-') character = character*3+2;
			}

			printf("%c", morse[character]);
		}

		printf("\n");
	}

	return 0;
}