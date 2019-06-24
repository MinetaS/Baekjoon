#include <cstdio>

struct Date {
	int year;
	int month;
	int day;

	Date() : year(0), month(0), day(0) {}
	Date(int _Val1, int _Val2, int _Val3) : year(_Val1), month(_Val2), day(_Val3) {}

	Date operator -(const Date _Val) const {
		return Date(year-_Val.year, month-_Val.month, day-_Val.day);
	}
};

int main() {
	int y1, m1, d1;
	int y2, m2, d2;

	scanf("%d %d %d\n%d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);

	Date res = Date(y2, m2, d2)-Date(y1, m1, d1);
	int r = y2-y1 - ((res.month == 0) ? ((res.day >= 0) ? 0 : 1) : res.month<0);

	printf("%d\n%d\n%d", r, y2-y1+1, y2-y1);

	return 0;
}