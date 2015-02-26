#pragma once

enum Month
{
	January, February, March, April, May, June, July, August, September, October, November, December
};

class Transaction
{
private:
	Month month;
	int day;
	int year;
	int withAmt;
	int depAmt;

public:
	Transaction(int month, int day, int year, int withAmt, int depAmt)
	{
		this->month = static_cast<Month>(month);
		this->day = day;
		this->year = year;
		this->withAmt = withAmt;
		this->depAmt = depAmt;
	}

	Month getMonth(void)
	{
		return month;
	}

	int getDay(void)
	{
		return day;
	}

	int getYear(void)
	{
		return year;
	}

	int getWithAmt(void)
	{
		return withAmt;
	}

	int getDepAmt(void)
	{
		return depAmt;
	}
};