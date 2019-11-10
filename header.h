#pragma once
namespace lem
{
	void connection_test();

	//int* make_mass(int x, int a=0, int b=0);

	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum class Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	enum class SortBy
	{
		Date,
		Season
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};
	TimeDelta operator ++ (TimeDelta& delta);
	TimeDelta operator ++ (TimeDelta& delta, int);

	TimeDelta operator -- (TimeDelta& delta);
	TimeDelta operator -- (TimeDelta& delta, int);

	Date operator ++ (Date& delta);
	Date operator ++ (Date& delta, int);

	Date operator -- (Date& delta);
	Date operator -- (Date& delta, int);

	/*
		ћен€ет даты местами
	*/
	void swap(Date& lhs, Date& rhs);

	/*
		ћен€ет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs);

	/*
		¬озвращает ссылку на большую дату
	*/
	Date& max(Date& lhs, Date& rhs);

	/*
		¬озвращает указатель на меньшую дату
	*/
	Date& min(Date& lhs, Date& rhs);

	/*
		¬озвращает указатель на минимальную дату в переданном массиве дат
	*/
	Date& getMinDate(Date dates[], int size);

	/*
		¬озвращает указатель на максимальную дату в переданном массиве дат
	*/
	Date& getMaxDate(Date dates[], int size);

	/*
		—ортирует массив дат по указанному критерию
	*/
	void sort(Date dates[], SortBy sortBy = SortBy::Date);
}