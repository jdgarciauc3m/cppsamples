#ifndef DATEARITH_DURATION_H
#define DATEARITH_DURATION_H

namespace datearith {

class duration {
public:
  duration(int d, int m, int y) noexcept 
    : days_{d}, months_{m}, years_{y}
  {
    normalize();
  }

  duration(const duration &) noexcept = default;
  duration & operator=(const duration &) noexcept = default;

  duration(duration &&) noexcept = default;
  duration & operator=(duration &&) noexcept = default;

  int days() const noexcept { return days_; }
  int months() const noexcept { return months_; }
  int years() const noexcept { return years_; }

  int as_days() const noexcept { return years_ * 365 + months_ * 30 + days_; }

private:
  void normalize() noexcept;

private:
  int days_;
  int months_;
  int years_;
};

}

#endif
