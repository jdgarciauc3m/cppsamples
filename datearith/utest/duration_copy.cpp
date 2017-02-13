#include "duration.h"
#include <gtest/gtest.h>

TEST(duration_copy, construct)
{
  using namespace datearith;
  duration d{1,2,3};
  duration c{d};
  EXPECT_EQ(1, c.days());
  EXPECT_EQ(2, c.months());
  EXPECT_EQ(3, c.years());
  EXPECT_EQ(1, d.days());
  EXPECT_EQ(2, d.months());
  EXPECT_EQ(3, d.years());
}

TEST(duration_copy, assign)
{
  using namespace datearith;
  duration d{1,2,3};
  duration c{4,5,6};
  c = d;
  EXPECT_EQ(1, c.days());
  EXPECT_EQ(2, c.months());
  EXPECT_EQ(3, c.years());
  EXPECT_EQ(1, d.days());
  EXPECT_EQ(2, d.months());
  EXPECT_EQ(3, d.years());
}
