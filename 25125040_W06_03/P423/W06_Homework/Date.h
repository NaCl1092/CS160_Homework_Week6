//Date.h
using namespace std;
#pragma once

/// @brief A date
/// @details A date consists of three data, respectively day, month, year
struct Date
{
    int day, month, year;
};


/// @brief Convert from the date to the number of days from 1/1/1970
/// @param d
/// @return
int toDays(Date d);

/// @brief Convert from the number of days to the date from 1/1/1970
/// @param n
/// @return
Date toDate(int n);

/// @brief Input the fraction from console
/// @param d
/// @return
void DInput(Date &d);

/// @brief Output the date to console
/// @param d
/// @return
void DOutput(Date d);

/// @brief Input the date from text file
/// @param d
/// @return
void DInputfile(std::ifstream &inp, Date &d);

/// @brief Output the date to text file
/// @param d
/// @return
void DOutputfile(std::ofstream &out, Date d);

/// @brief Compare two dates
/// @param a
/// @param b
/// @return
int compareDates(Date a, Date b);

/// @brief Compute the distance between two dates
/// @param a
/// @param b
/// @return
int DistDates(Date a, Date b);

/// @brief Increase a date by k day
/// @param d
/// @return
Date increaseDate(Date d, int k);

/// @brief Decrease a date by k day
/// @param d
/// @return
Date decreaseDate(Date d, int k);
