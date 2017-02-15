#include "date.h"
#include <gtest/gtest.h>

TEST(date_substract, simple) 
{
  using namespace datearith;
  date d1{4,9,1969};
  date d2{6,9,1969};
  auto r = d2 - d1;
  EXPECT_EQ(2, r.days());
  EXPECT_EQ(0, r.months());
  EXPECT_EQ(0, r.years());
}

