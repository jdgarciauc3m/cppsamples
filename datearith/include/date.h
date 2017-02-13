#ifndef DATEARITH_DATE_H
#define DATEARITH_DATE_H

namespace datearith {

struct invalid_date {};

class date {
public:
  date() noexcept = default;
  date(int d, int m, int y);

  date(const date &) noexcept = default;
  date & operator=(const date &) noexcept = default;

  date(date &&) noexcept = default;
  date & operator=(date &&) noexcept = default;

  int day() const noexcept { return day_; }
  int month() const noexcept { return month_; }
  int year() const noexcept { return year_; }

private:
  int day_{1};
  int month_{1};
  int year_{1900};
};

}

#endif
