#include "date.h"

#include <iostream>
using namespace std;

namespace datearith {

namespace {

  bool is_leap(int y) noexcept {
    return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
  }

  int max_days(int month, int year) noexcept {
    static int days[] = {
      31, 28, 31, 30,
      31, 30, 31, 31,
      30, 31, 30, 31
    };
    int r = days[month-1];
    if (2==month && is_leap(year)) r++;
    return r;
  }

  int days_current_year(int month, int year) noexcept {
    int r = 0;
    for (int i=1;i<month;++i) {
      r += max_days(i,year);
    } 
    return r;
  }

  int days_in_year(int year) noexcept {
    return (is_leap(year))?366:365;
  }
}

date::date(int d, int m, int y) :
  day_{d},
  month_{m},
  year_{y}
{
  if (year_<1900 || year_ > 2200) throw invalid_date{};
  if (1 > month_ || month_ > 12) throw invalid_date{};
  if (day_ < 1) throw invalid_date{};
  if (day_ > max_days(month_,year_)) throw invalid_date{};
}

date::date(int days)
{
  year_ = 1900;

  for (int delta = days_in_year(year_); days >= delta; delta = days_in_year(year_)) {
    days -= delta;
    year_++;
  }


  month_ = 1;
  for (int delta=max_days(month_,year_); days >= delta; delta = max_days(month_,year_)) {
    days -= delta;
    month_++;
  }
  
  day_ = days +1;
}

int date::days_from_epoch() const noexcept {
  int d = (year_ - 1900) * 365;

  // Leap years from 1900 to year before
  int nleaps = (year_ - 1900) / 4;
  if (year_ > 2100) nleaps--;
  if (year_ >= 2200) nleaps--;
  if (is_leap(year_)) nleaps--;

  d += nleaps;
  
  d += days_current_year(month_, year_);

  d += day_-1;

  return d;
}

date operator+(date d, duration delta) {
  int days = d.days_from_epoch() + delta.as_days();
  return date{days};
}

duration operator-(date d1, date d2) {
  return duration{d1.days_from_epoch() - d2.days_from_epoch(), 0, 0};
}

}
