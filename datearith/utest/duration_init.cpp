#include "duration.h"
#include <gtest/gtest.h>

TEST(duration_init, init1)
{
  using namespace datearith;
  duration d{1,2,3};
  EXPECT_EQ(1, d.days());
  EXPECT_EQ(2, d.months());
  EXPECT_EQ(3, d.years());
}

TEST(duration_init, norm1)
{
  using namespace datearith;
  duration d{366, 0, 1};
  EXPECT_EQ(1, d.days());
  EXPECT_EQ(0, d.months());
  EXPECT_EQ(2, d.years());
}

TEST(duration_init, norm2)
{
  using namespace datearith;
  duration d{366, 11, 1};
  EXPECT_EQ(1, d.days());
  EXPECT_EQ(11, d.months());
  EXPECT_EQ(2, d.years());
}

TEST(duration_init, norm3)
{
  using namespace datearith;
  duration d{364, 1, 1};
  EXPECT_EQ(4, d.days());
  EXPECT_EQ(1, d.months());
  EXPECT_EQ(2, d.years());
}

TEST(duration_init, norm4)
{
  using namespace datearith;
  duration d{63, 1, 1};
  EXPECT_EQ(3, d.days());
  EXPECT_EQ(3, d.months());
  EXPECT_EQ(1, d.years());
}

TEST(duration_init, norm5)
{
  using namespace datearith;
  duration d{25, 12, 1};
  EXPECT_EQ(25, d.days());
  EXPECT_EQ(0, d.months());
  EXPECT_EQ(2, d.years());
}

TEST(duration_init, norm6)
{
  using namespace datearith;
  duration d{25, 13, 1};
  EXPECT_EQ(25, d.days());
  EXPECT_EQ(1, d.months());
  EXPECT_EQ(2, d.years());
}

TEST(duration_init, norm7)
{
  using namespace datearith;
  duration d{25, 25, 1};
  EXPECT_EQ(25, d.days());
  EXPECT_EQ(1, d.months());
  EXPECT_EQ(3, d.years());
}

