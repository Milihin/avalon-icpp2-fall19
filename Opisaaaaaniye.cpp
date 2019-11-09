#include "Date.h"
#include <cmath>
#include "stdio.h"
#include <string>



namespace ext {
	std::string strMonth12(Month mon) {
		switch (mon)
		{
		case ext::Month::January:
			return "January";
			break;
		case ext::Month::February:
			return "February";
			break;
		case ext::Month::March:
			return "March";
			break;
		case ext::Month::April:
			return "April";
			break;
		case ext::Month::May:
			return "May";
			break;
		case ext::Month::June:
			return "June";
			break;
		case ext::Month::July:
			return "July";
			break;
		case ext::Month::August:
			return "August";
			break;
		case ext::Month::September:
			return "September";
			break;
		case ext::Month::October:
			return "October";
			break;
		case ext::Month::Novemver:
			return "Novemver";
			break;
		case ext::Month::December:
			return "December";
			break;
		default:
			return "f";
			break;
		}
	}
	int intMonth12(Month mon) {
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
			return (int)"f*ck";
			break;
		}
	}
	Date DateToNormal(Date inpp)
	{
		int temp, monthtemp = 0;
		if (inpp.day > 365) {
			temp = inpp.day / 365;
			inpp.day = inpp.day % 366;
			monthtemp = temp + intMonth12(inpp.month);
			if (monthtemp > 12) {
				inpp.year = inpp.year + static_cast<int>(monthtemp / 12);
				inpp.month = static_cast<Month>(monthtemp % 12);
			}
		}
	}
	Date RJND(TimeDelta delta) {
		Date outpp;
		int a = delta.delta + 32044;
		int b = ((4 * a) + 3) / 146097;
		int c = a - ((146097 * b) / 4);
		int d = ((4 * c) + 3) / 1461;
		int e = c - ((1461 * d) / 4);
		int m = ((5 * e) + 2) / 153;
		outpp.day = e - ((153 * m + 2) / 5) + 1;
		outpp.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		outpp.year = (100 * b) + d - 4800 + (m / 10);
		return outpp;
	}
	TimeDelta countJND(Date date)
	{
		int a = (14 - intMonth12(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = intMonth12(date.month) + 12 * a - 3;
		TimeDelta outpp;
		outpp.delta = (date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045);
		return outpp;
	}
	Date operator - (Date a, Date b) {
		Date per;
		b.day - a.day;
		intMonth12(b.month) - intMonth12(a.month);
		b.year - a.year;
	}
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta outpp, a = countJND(to), b = countJND(from);
		outpp.delta = a.delta - b.delta;
		return outpp;

	}
	void print(Date data, DateFormat format)
	{
		std::cout << data.year << " ";
		print(data.month, format);
		std::cout << data.day;
	}
	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsInt)
		{
			std::cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{
			std::cout << strMonth12(month);
			std::cout << " ";
		}
		else
		{
			throw "ya pishu etot code in 3 hours of nochi, i ya ponatiya haven't chto zdes' write";
		}
	}
	void print(TimeDelta delta)
	{
		std::cout << delta.delta << std::endl;
	}
	Season getSeason(Date date)
	{
		return getSeason(date.month);
	}
	Season getSeason(Month month)
	{
		int monint = static_cast<int>(month);
		if ((monint == 12) || (monint == 1) || (monint == 2))
		{
			return Season::Winter;
		}
		if ((monint > 2) && (monint < 6))
		{
			return Season::Spring;
		}
		if ((monint > 5) && (monint < 9))
		{
			return Season::Summer;
		}
		if ((monint > 8) && (monint < 12))
		{
			return Season::Autumn;
		}
	}
	bool  operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
	bool operator < (const Date lhs, const Date rhs)
	{
		if (lhs.year < rhs.year) {
			return true;
		}
		else if (lhs.year > rhs.year) {
			return false;
		}
		else {
			if (lhs.month < rhs.month) {
				return true;
			}
			else if (lhs.month > rhs.month) {
				return false;
			}
			else {
				if (lhs.day < rhs.day) {
					return true;
				}
				else if (lhs.day > rhs.day) {
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		return(lhs == rhs) || (lhs < rhs);
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		if (lhs.year > rhs.year) {
			return true;
		}
		else if (lhs.year < rhs.year) {
			return false;
		}
		else {
			if (lhs.month > rhs.month) {
				return true;
			}
			else if (lhs.month < rhs.month) {
				return false;
			}
			else {
				if (lhs.day > rhs.day) {
					return true;
				}
				else if (lhs.day < rhs.day) {
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
	bool operator >= (const Date lhs, const Date rhs)
	{
		return (lhs == rhs) || (lhs > rhs);
	}
	Date operator + (const Date date, const TimeDelta delta)
	{
		Date temp = date;
		temp.day = date.day + delta.delta;
		return DateToNormal(temp);
	}
	Date operator + (const TimeDelta delta, const Date date)
	{
		Date temp = date;
		temp.day = date.day + delta.delta;
		return DateToNormal(temp);
	}
	TimeDelta operator + (const TimeDelta delta, const TimeDelta date)
	{
		Date outpp;
		outpp.day = delta.delta + date.delta;
		return countJND(outpp);
	}
	Date operator - (const Date date, const TimeDelta delta)
	{
		Date temp = date;
		temp.day = date.day - delta.delta;
		return DateToNormal(temp);
	}
	Date operator - (const TimeDelta delta, const Date date) 
	{
		Date temp;
		TimeDelta tempp = countJND(date);

		temp.day = delta.delta - tempp.delta;
		return DateToNormal(temp);
	}
	Date operator - (const TimeDelta delta, const Date date) 
	{
		TimeDelta one = countJND(date);
		return RJND(one - delta);
	}
	Date operator - (Date a, Date b) {
		Date per;
		b.day - a.day;
		abs(intMonth12(b.month) - intMonth12(a.month));
		b.year - a.year;
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) 
	{
		TimeDelta one;
		one.delta = lhs.delta - rhs.delta;
		return one;
	}
	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta one;
		one.delta = (delta.delta * multiplier);
		return one;
	}
	TimeDelta operator / (const TimeDelta delta, int multiplier) {
		TimeDelta one;
		one.delta = (delta.delta / multiplier);
		return one;
	}
	TimeDelta operator ++ (TimeDelta& delta)
	{
		++delta.delta;
		return delta;
	}
	TimeDelta operator ++ (TimeDelta& delta, int)
	{
		TimeDelta temp = delta;
		++delta.delta;
		return temp;
	}
	TimeDelta operator -- (TimeDelta& delta)
	{
		--delta.delta;
		return delta;
	}
	TimeDelta operator -- (TimeDelta& delta, int)
	{

		TimeDelta temp = delta;
		--delta.delta;
		return temp;
	}
	Date operator ++ (Date& delta)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator ++ (Date& delta, int)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator -- (Date& delta)
	{
		delta.day--;
		delta.year--;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) - 1);
		return delta;
	}
	Date operator -- (Date& delta, int)
	{
		delta.day--;
		delta.year--;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) - 1);
		return delta;
	}
	TimeDelta countDistance(Date from, Date to) {
		Date tempp;
		tempp = to - from;
		TimeDelta outpp = { ((tempp.day + (intMonth12(tempp.month) * 30) + (tempp.year * 365))) };
		return outpp;
	}
	void swap(Date& lhs, Date& rhs) {
		Date swap;
		swap = lhs;
		lhs = rhs;
		rhs = swap;
	}
	void swap(TimeDelta& lhs, TimeDelta& rhs) {
		TimeDelta swap = lhs;
		lhs = rhs;
		rhs = swap;
	}
	Date& max(Date& lhs,  Date& rhs) {
		return lhs > rhs ? lhs : rhs;


		if (lhs.year > rhs.year) {
			return lhs;
		}
		else if (lhs.year < rhs.year) {
			return rhs;
		}
		else {
			if (lhs.month > rhs.month) {
				return lhs;
			}
			else if (lhs.month < rhs.month) {
				return rhs;
			}
			else {
				if (lhs.day > rhs.day) {
					return lhs;
				}
				else if (lhs.day < rhs.day) {
					return rhs;
				}
				else {
					return rhs;
				}
			}
		}
	}
	Date& min(Date& lhs,  Date& rhs) {

		if (lhs.year > rhs.year) {
			return rhs;
		}
		else if (lhs.year < rhs.year) {
			return lhs;
		}
		else {
			if (lhs.month > rhs.month) {
				return rhs;
			}
			else if (lhs.month < rhs.month) {
				return lhs;
			}
			else {
				if (lhs.day > rhs.day) {
					return rhs;
				}
				else if (lhs.day < rhs.day) {
					return lhs;
				}
				else {
					return rhs;
				}

			}
		}
	}

	Date& getMinDate(Date dates[], int size) {
		Date * minn = &dates[0];
		for (int i = 0; i < size; i++) {
			if (*minn > dates[i]) {
				minn = &dates[i];
			}
		}
		return *minn;
	}

	Date& getManDate(Date dates[], int size) {
		Date *  miax = &dates[0];
		for (int i = 0; i < size; i++) {
			if (*miax < dates[i]) {
				miax = &dates[i];
			}
		}
		return *miax;
	}
	void sort(Date dates[], int size, SortBy sortBy = SortBy::Date) {
		Date temp;
		bool stopper = false;
		if (sortBy == SortBy::Season) {
			for (int i = 0; i < size - 1; i++) {
				if (stopper) {
					stopper = false;
					i = 0;
				}
				if (getSeason(dates[i]) > getSeason(dates[i + 1])) {
					stopper = true;
					temp = dates[i];
					dates[i] = dates[i + 1];
					dates[i + 1] = temp;
				}
			}
		}
		else if (sortBy == SortBy::Date) {
			for (int i = 0; i < size - 1; i++) {
				if (stopper) {
					stopper = false;
					i = 0;
				}
				if (dates[i] > dates[i + 1]) {
					stopper = true;
					temp = dates[i];
					dates[i] = dates[i + 1];
					dates[i + 1] = temp;
				}
			}
		}
		else {
			throw "f*ck";
		}

	}


		Date* tryFillDate(int year, int month, int day)
		{
			Date * TF3 = new Date();
			TF3->day = day;
			TF3->month = static_cast<Month>(month);
			TF3->year = year;
			if (TF3 == DateToNormal(TF3)) {
				return TF3;
			}
			else {
				return nullptr;
			}
		}




	}
}