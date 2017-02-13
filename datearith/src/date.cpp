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

}
