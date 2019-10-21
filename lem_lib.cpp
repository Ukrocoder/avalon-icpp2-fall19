#include <iostream>
#include <random>
#include "Main_Header.h"
#include <exception>
namespace lem
{
void bubble_sort(TimeDelta* ptr, int size)
{
	int buffer;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if ((ptr + i)->delta <  (ptr + i + 1)->delta)
			{
				buffer = (ptr + i)->delta;
				(ptr + i)->delta = (ptr + i + 1)->delta;
				(ptr + i + 1)->delta = buffer;
				flag = true;
			}
		}
	}
}
	int GetRandomValue(int min, int max, bool isDebugMode=false)//Stolen from Extention.h
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}
	Month month(int x)// It seems that static_cast<Month> does it properly.
	{
		switch (x)
		{
		case 1:
			return Month::January;
			break;
		case 2:
			return Month::February;
			break;
		case 3:
			return Month::March;
			break;
		case 4:
			return Month::April;
			break;
		case 5:
			return Month::May;
			break;
		case 6:
			return Month::June;
			break;
		case 7:
			return Month::July;
			break;
		case 8:
			return Month::August;
			break;
		case 9:
			return Month::September;
			break;
		case 10:
			return Month::October;
			break;
		case 11:
			return Month::Novemver;
			break;
		case 12:
			return Month::December;
			break;
		}
	}
	TimeDelta countJND(Date date)
	{
		TimeDelta out;
		int a = (14 - static_cast<int>(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = static_cast<int>(date.month) + (12 * a) - 3;
		out.delta =  date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;
		return out;
	}
	Date Gregor(TimeDelta x)
	{
		Date output;
		bool flag = false;
		if (x.delta < 0) { x.delta *= 1; flag = true; }
		int A, B, C, D, E;
		if (x.delta < 2299161) { A = x.delta; }
		else { A = static_cast<int>((A = x.delta + 1 + static_cast<int>((x.delta - 1867216.25) / 36524.25) - static_cast<int>(static_cast<int>((x.delta - 1867216.25) / 36524.25) / 4))); }
		B = A + 1524;
		C = static_cast<int>((B - 122.1F) / 365.25F);
		D = static_cast<int>(365.25F * C);
		E = static_cast<int>((B - D) / 30.6001F);
		output.day = B - D - static_cast<int>(30.6001F * E);
		if (flag) { output.day *= -1; }
		if (E > 14) { output.month = month(E - 1); }
		else { output.month = static_cast<Month>(E - 13); }
		if (static_cast<int>(output.month) > 2) { output.year=C - 4716; }
		else { output.year = E - 4715; }
		return output;
	}
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta out;
		out.delta = countJND(to).delta - countJND(from).delta;
		return out;
	}
	bool correct_date(Date x)
	{
		bool flag=true;
		//if ((y % 400 == 0) || (y % 100 !=0 && y % 4 == 0))
		switch (static_cast<int>(x.month))
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (x.day > 31)
			{
				flag = false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (x.day > 30)
			{
				flag = false;
			}
			break;
		case 2:
			if ((x.year % 400 == 0) || (x.year % 100 != 0 && x.year % 4 == 0))
			{
				if (x.day > 29)
				{
					flag = false;
				}
			}
			else
			{
				if (x.day > 28)
				{
					flag = false;
				}
			}
			break;
		default: 
			flag = false;
		}
		return flag;
	}

	Date* make_mass(int x)
	{
		Date* mass = new Date[x];
		for (int i = 0; i < x; ++i)
		{
			while (!correct_date(mass[i]))
			{
				mass[i].day = GetRandomValue(1, 31);
				mass[i].month = static_cast<Month>(GetRandomValue(1, 12));
				mass[i].year = GetRandomValue(2000, 2019);
			}
		}
		return mass;
	}
	void string_month(Month m)
	{
		switch (m)
		{
		case Month::December:
			std::cout << "December";
			break;
		case Month::January:
			std::cout << "January";
			break;
		case Month::February:
			std::cout << "February";
			break;
		case Month::March:
			std::cout << "March";
			break;
		case Month::April:
			std::cout << "April";
			break;
		case Month::May:
			std::cout << "May";
			break;
		case Month::June:
			std::cout << "June";
			break;
		case Month::July:
			std::cout << "July";
			break;
		case Month::August:
			std::cout << "August";
			break;
		case Month::September:
			std::cout << "September";
			break;
		case Month::October:
			std::cout << "October";
			break;
		case Month::Novemver:
			std::cout << "Novemver";
			break;
		}
	}
	Season getSeason(Date date)
	{
		Month x = date.month;
		return getSeason(x);
	}
	Season getSeason(Month month)
	{
		switch (month)
		{
		case Month::December:
		case Month::January:
		case Month::February:
			return Season::Winter;
			break;
		case Month::March:
		case Month::April:
		case Month::May:
			return Season::Spring;
			break;
		case Month::June:
		case Month::July:
		case Month::August:
			return Season::Summer;
			break;
		case Month::September:
		case Month::October:
		case Month::Novemver:
			return Season::Autumn;
			break;
		}
	}
	//====================================================================
	void print(Date data, DateFormat format)
	{

		std::cout << data.day << ' ';
		if (format == MonthAsInt) { std::cout << static_cast<int>(data.month) << ' '; }
		else if(format == MonthAsInt){string_month(data.month); }
		else { throw std::exception( "Invalid print  format"); }
		std::cout<< data.year;
	}
	//====================================================================
	void print(Month month, DateFormat format)
	{
		std::cout << static_cast<int>(month)<< std::endl;
	}
	//====================================================================
	void print(TimeDelta delta)
	{
	std::cout << delta.delta << std::endl;
	}
	//====================================================================
	bool operator == (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta == countJND(rhs).delta) { return true; }
		else { return false; }
	}
	//====================================================================
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
	//====================================================================
	bool operator < (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta < countJND(rhs).delta) { return true; }
		else { return false; }
	}
	//====================================================================
	bool operator <= (const Date lhs, const Date rhs)
	{
		return !(lhs > rhs);
	}
	//====================================================================
	bool operator > (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta > countJND(rhs).delta) { return true; }
		else { return false; }
	}
	//====================================================================
	bool operator >= (const Date lhs, const Date rhs)
	{
		return !(lhs<rhs);
	}
	//====================================================================
	Date operator + (const Date date, const TimeDelta delta)
	{
		Date output;
		return Gregor(countJND(date) + delta);
	}
	//====================================================================
	Date operator + (const TimeDelta delta, const Date date)
	{
		return(date + delta);
	}
	//====================================================================
	TimeDelta operator + (const TimeDelta delta, const TimeDelta date)
	{
		TimeDelta output;
		output.delta = delta.delta + date.delta;
		return output;
	}
	//====================================================================
	Date operator - (const Date date, const TimeDelta delta)
	{
		Date output;
		output = Gregor(countJND(date) - delta);
		return output;
	}
	//====================================================================
	Date operator - (const TimeDelta delta, const Date date)
	{
		return((date - delta));//JND form  * (-1) and then to the gregorian 
	}
	//====================================================================
	TimeDelta operator - (const TimeDelta delta, const TimeDelta date)
	{
		TimeDelta output;
		output.delta = delta.delta - date.delta;
		return output;
	}
	//====================================================================
	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta output;
		output.delta = delta.delta * multiplier;
		return output;
	}
	//====================================================================
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		return(delta * multiplier);
	}
	//====================================================================
	TimeDelta operator / (const TimeDelta delta, int multiplier)
	{
	    TimeDelta output;
		output.delta= delta.delta / multiplier;
		return output;
	}
	//====================================================================
	TimeDelta operator / (int multiplier, const TimeDelta delta)
	{
		return(delta / multiplier);
	}
}