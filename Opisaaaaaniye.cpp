#include "Date.h"
#include <cmath>
#include <iostream>
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
	//необходимая функция, реализует нормализацию
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
		return lhs.day < rhs.day
			&& lhs.month < rhs.month
			&& lhs.year < rhs.year;
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		return(lhs == rhs) || (lhs < rhs);
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		return lhs.day > rhs.day
			&& lhs.month > rhs.month
			&& lhs.year > rhs.year;
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
	Date operator + (const TimeDelta delta, const TimeDelta date) 
	{
		Date outpp;
		outpp.day = delta.delta + date.delta;
		return DateToNormal(outpp);
	}
	Date operator - (const Date date, const TimeDelta delta) 
	{
		Date temp = date;
		temp.day = date.day - delta.delta;
		return DateToNormal(temp);
	}
	Date operator - (const TimeDelta delta, const Date date) {
		Date temp;
		TimeDelta tempp = countJND(date);

		temp.day = delta.delta - tempp.delta;
		return DateToNormal(temp);
	}
	Date operator - (const TimeDelta delta, const TimeDelta date) 
	{




	}



	
}


