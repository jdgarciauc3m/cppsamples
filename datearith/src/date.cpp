#include "date.h"

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

//date date::operator+(duration delta) {
/*
  int days = days_from_epoch() + delta.as_days();
  
  year_ = 1900;
  while (days >= 
  year_ = result / 365;
  days -= year_ * 365;
  nmonth_ = 0;
  int days_current_month = max_days(nmonth_+1, year_);
  while (days >= days_current_month) {
    days -= days_current_month;
    nmont_++;
    days_current_month = max_days(nmonth_+1, year_);
  }
  day_ = days;
*/
//}


}
