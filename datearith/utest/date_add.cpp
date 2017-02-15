#include "date.h"
#include <gtest/gtest.h>

TEST(date_add, add040969plus1)
{
  using namespace datearith;
  date d{4,9,1969};
  date r = d + duration{1,0,0};
  EXPECT_EQ(5, r.day());
  EXPECT_EQ(9, r.month());
  EXPECT_EQ(1969, r.year());
}

