#include "header.h"
#include <iostream>
#include <random>
namespace lem
{
	void connection_test()
	{
		std::cout << "Yeah, I m connected properly.";
	}

	int random(int min, int max, bool isDebugMode = false)//Stolen from Extention.h
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}

	/*int* make_mass(int x, int a, int b)
	{
		int* ptr = new int[x];
		for (int i = 0; i < x; ++i)
		{
			*(ptr + i) = random(a, b);
		}
		return ptr;
	}*/
	
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
		out.delta = date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;
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
		if (static_cast<int>(output.month) > 2) { output.year = C - 4716; }
		else { output.year = E - 4715; }
		return output;
	}

	bool operator > (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta > countJND(rhs).delta) { return true; }
		else { return false; }
	}

	bool operator < (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta < countJND(rhs).delta) { return true; }
		else { return false; }
	}

	TimeDelta operator ++ (TimeDelta& delta)
	{
		delta.delta += 1;
		return delta;
	}

	TimeDelta operator ++ (TimeDelta& delta, int)
	{
		TimeDelta output = delta;
		++delta.delta;
		return output;
	}

	TimeDelta operator -- (TimeDelta& delta)
	{
		delta.delta -= 1;
		return delta;
	}

	TimeDelta operator -- (TimeDelta& delta, int)
	{
		TimeDelta output = delta;
		--delta.delta;
		return output;
	}

	Date operator ++ (Date& delta)
	{
		TimeDelta x = countJND(delta);
		delta = Gregor(x++);
		return delta;
	}

	Date operator ++ (Date& delta, int)
	{
		Date output = delta;
		++delta;
		return output;
	}

	Date operator -- (Date& delta)
	{
		TimeDelta x = countJND(delta);
		delta = Gregor(x--);
		return delta;
	}

	Date operator -- (Date& delta, int)
	{
		Date output = delta;
		++delta;
		return output;
	}

	/*
		ћен€ет даты местами
	*/
	void swap(Date& lhs, Date& rhs)
	{
		Date buf=lhs;
		lhs = rhs;
		rhs = buf;
	}
	/*
		ћен€ет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs)
	{
		TimeDelta buf = lhs;
		lhs = rhs;
		rhs = buf;
	}
	/*
		¬озвращает ссылку на большую дату
	*/
	Date& max(Date& lhs, Date& rhs)
	{
		if (lhs > rhs) { return lhs; }
		else { return rhs; }
	}
	/*
		¬озвращает указатель на меньшую дату
	*/
	Date& min(Date& lhs, Date& rhs)
	{
		if (lhs > rhs) { return rhs; }
		else { return lhs; }
	}
	/*
		¬озвращает указатель на минимальную дату в переданном массиве дат
	*/
	Date& getMinDate(Date dates[], int size)
	{
		Date min=*dates;
		int n;
		for (int i = 0; i < size; ++i)
		{
			if (min > dates[i]) { min = dates[i]; n = i; }
		}
		return dates[n];
	}
	/*
		¬озвращает указатель на максимальную дату в переданном массиве дат
	*/
	Date& getMaxDate(Date dates[], int size)
	{
		Date max = *dates;
		int n;
		for (int i = 0; i < size; ++i)
		{
			if (max < dates[i]) { max = dates[i]; n = i; }
		}
		return dates[n];
	}
	/*
		—ортирует массив дат по указанному критерию
	*/
	}
