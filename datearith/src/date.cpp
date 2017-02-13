#include "date.h"

namespace datearith {

namespace {

  bool is_leap(int y) {
    return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
  }

  int max_days(int month, int year) {
    switch (month) {
      case 1: case 3: case 5: case 7:
      case 8: case 10: case 12:
        return 31;
      case 4: case 6: case 9: case 11:
        return 30;
      case 2:
        return is_leap(year)?29:28;
    }
    return 0;
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
