#include<stdio.h>
int Monthday(int, int); 
int Weekday(int, int);

int main()
{
	int year, month, i, day;
	printf("input the year and month<YYYY-MM>:");
	scanf_s("%d-%d", &year, &month);
	printf("\t\t\t%d-%d\n", year, month);
	printf("Sun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n");

	for (i = 0; i < Weekday(year, month); i++)
		printf("\t");

	for (day = 1; day <= Monthday(year, month); day++) {
		printf("%d\t", day);
		if (i == 6) {
			printf("\n");
			i = -1;
		}
		i++;
	}

	return 0;
}

int Weekday(int year, int month)
{
	int yeardays, monthdays, days, i, weekdays;
	yeardays = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	monthdays = 0;
	for (i = 1; i < month; i++)
		monthdays = monthdays + Monthday(year, i);
	days = yeardays + monthdays;
	weekdays = (days + 1) % 7;
	return weekdays;
}

int Monthday(int year, int month)
{
	switch (month) {
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31; break;
	case 4:case 6:case 9:case 11:
		return 30; break;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return 29;
		else
			return 28; break;
	}
}