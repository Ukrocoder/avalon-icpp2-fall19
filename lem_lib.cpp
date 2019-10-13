#include <iostream>
#include <random>
#include "Main_Header.h"
namespace lem
{
	int GetRandomValue(int min, int max, bool isDebugMode)//Stolen from Extention.h
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}
	TimeDelta countJND(Date date)
	{
		TimeDelta out;
		return out;
	}
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta out;
		out.delta = countJND(to).delta - countJND(from).delta;
		return out;
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
	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		std::cout <<data.day<<' '<< static_cast<int>(data.month) << data.year << std::endl;
	}
	//====================================================================
	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		std::cout << static_cast<int>(month)<< std::endl;
	//====================================================================
	}
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
	bool operator > (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta > countJND(rhs).delta) { return true; }
		else { return false; }
	}
	bool operator >= (const Date lhs, const Date rhs)
	{
		return !(lhs<rhs);
	}
	Date operator + (const Date date, const TimeDelta delta)
	{
	
	}
	Date operator + (const TimeDelta delta, const Date date)
	{
		return(date + delta);
	}
	TimeDelta operator + (const TimeDelta delta, const TimeDelta date)
	{

	}
	Date operator - (const Date date, const TimeDelta delta)
	{

	}
	Date operator - (const TimeDelta delta, const Date date)
	{
		return(date - delta);//JND form  * (-1) and then to the gregorian 
	}
	TimeDelta operator - (const TimeDelta delta, const TimeDelta date)
	{

	}
	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{

	}
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{

	}
	TimeDelta operator / (const TimeDelta delta, int multiplier)
	{

	}
	TimeDelta operator / (int multiplier, const TimeDelta delta)
	{

	}
}