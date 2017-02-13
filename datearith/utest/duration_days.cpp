#include "duration.h"
#include <gtest/gtest.h>

TEST(duration_days, days_10) 
{
  using namespace datearith;
  duration d{10, 0, 0};
  EXPECT_EQ(10, d.as_days());
}

TEST(duration_days, days_30) 
{
  using namespace datearith;
  duration d{30, 0, 0};
  EXPECT_EQ(30, d.as_days());
}

TEST(duration_days, days_40) 
{
  using namespace datearith;
  duration d{40, 0, 0};
  EXPECT_EQ(40, d.as_days());
}

TEST(duration_days, days_100) 
{
  using namespace datearith;
  duration d{100, 0, 0};
  EXPECT_EQ(100, d.as_days());
}

TEST(duration_days, days_1_months_1) 
{
  using namespace datearith;
  duration d{1,1,0};
  EXPECT_EQ(31, d.as_days());
}

TEST(duration_days, days_2_months_3)
{
  using namespace datearith;
  duration d{2,3,0};
  EXPECT_EQ(92, d.as_days());
}

TEST(duration_days, full_01) 
{
  using namespace datearith;
  duration d{2,0,1};
  EXPECT_EQ(367, d.as_days());
}

TEST(duration_days, full_02)
{
  using namespace datearith;
  duration d{3,2,1};
  EXPECT_EQ(428, d.as_days());
}

