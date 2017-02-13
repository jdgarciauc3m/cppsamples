#include "date.h"
#include <gtest/gtest.h>

TEST(date_move, construct)
{
  using namespace datearith;
  date d{4,9,1969};
  date c{std::move(d)};
  EXPECT_EQ(4, c.day());
  EXPECT_EQ(9, c.month());
  EXPECT_EQ(1969, c.year());
}

TEST(date_move, assign)
{
  using namespace datearith;
  date d{4,9,1969};
  date c;
  c = std::move(d);
  EXPECT_EQ(4, c.day());
  EXPECT_EQ(9, c.month());
  EXPECT_EQ(1969, c.year());
}
