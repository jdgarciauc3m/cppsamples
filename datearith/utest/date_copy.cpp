#include "date.h"
#include <gtest/gtest.h>

TEST(date_copy, construct)
{
  using namespace datearith;
  date d{4,9,1969};
  date c{d};
  EXPECT_EQ(4, c.day());
  EXPECT_EQ(9, c.month());
  EXPECT_EQ(1969, c.year());
  EXPECT_EQ(4, d.day());
  EXPECT_EQ(9, d.month());
  EXPECT_EQ(1969, d.year());
}

TEST(date_copy, assign)
{
  using namespace datearith;
  date d{4,9,1969};
  date c;
  c = d;
  EXPECT_EQ(4, c.day());
  EXPECT_EQ(9, c.month());
  EXPECT_EQ(1969, c.year());
  EXPECT_EQ(4, d.day());
  EXPECT_EQ(9, d.month());
  EXPECT_EQ(1969, d.year());
}
