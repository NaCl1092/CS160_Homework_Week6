//Date.cpp
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

#include "Date.h"

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days(int m, int y)
{
    if (m == 2)
    {
        if (isLeap(y)) return 29;
        return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

//Set the point at 1/1/1970
int toDays(Date d)
{
    int res = 0;
    if (d.year >= 1970)
    {
        for (int i = 1970; i < d.year; ++i)
        {
            if (isLeap(i)) res += 366;
            else res += 365;
        }
    }
    else
    {
        for (int i = d.year; i < 1970; ++i)
        {
            if (isLeap(i)) res -= 366;
            else res -= 365;
        }
    }
    for (int i = 1; i < d.month; ++i)
    {
        res += days(i, d.year);
    }
    res += d.day - 1;
    return res;
}

Date toDate(int n)
{
    Date d;
    d.year = 1970;
    int daysYear = isLeap(d.year) ? 366 : 365;
    while (n >= daysYear)
    {
        n -= daysYear;
        d.year++;
        daysYear = isLeap(d.year) ? 366 : 365;
    }
    d.month = 1;
    int daysMonth = days(d.month, d.year);
    while (n >= daysMonth)
    {
        n -= daysMonth;
        d.month++;
        daysMonth = days(d.month, d.year);
    }
    d.day = n + 1;
    return d;
}

void DInput(Date &d)
{
    cin >> d.day >> d.month >> d.year;
}

void DOutput(Date d)
{
    cout << d.day << "/" << d.month << "/" << d.year << '\n';
}

void DInputfile(std::ifstream &inp, Date &d)
{
    inp >> d.day >> d.month >> d.year;
}

void DOutputfile(std::ofstream &out, Date d)
{
    out << d.day << "/" << d.month << "/" << d.year << '\n';
}

int compareDates(Date a, Date b)
{
    int day_1 = toDays(a), day_2 = toDays(b);
    if (day_1 > day_2) return 1;
    else if (day_1 < day_2) return 2;
    else return 0;
}

int DistDates(Date a, Date b)
{
    int ans = toDays(a) - toDays(b);
    if (ans < 0) return -ans;
    return ans;
}

Date increaseDate(Date d, int k)
{
    return toDate(toDays(d) + k);
}

Date decreaseDate(Date d, int k)
{
    return toDate(toDays(d) - k);
}
