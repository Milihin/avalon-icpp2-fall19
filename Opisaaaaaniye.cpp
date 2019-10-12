#include "Date.h"







namespace ext {
	int Mounth12(Month mon) {
		switch (mon)
		{
		case ext::Month::January:
			return 1;
			break;
		case ext::Month::February:
			return 2;
			break;
		case ext::Month::March:
			return 3;
			break;
		case ext::Month::April:
			return 4;
			break;
		case ext::Month::May:
			return 5;
			break;
		case ext::Month::June:
			return 6;
			break;
		case ext::Month::July:
			return 7;
			break;
		case ext::Month::August:
			return 8;
			break;
		case ext::Month::September:
			return 9;
			break;
		case ext::Month::October:
			return 10;
			break;
		case ext::Month::Novemver:
			return 11;
			break;
		case ext::Month::December:
			return 12;
			break;
		default:
			return (int)"fuck";
			break;
		}



	}

	Date operator - (Date a, Date b) {
		Date per;
		b.day - a.day;
		Mounth12(b.month) - Mounth12(a.month);
		b.year - a.year;
	}


	TimeDelta countDistance(Date from, Date to) {

		return from - to;

	}







	
}


