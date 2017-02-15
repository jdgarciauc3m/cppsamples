#include "date.h"
#include <gtest/gtest.h>

TEST(date_init, defconstruct)
{
  using namespace datearith;
  date d;
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days0)
{
  using namespace datearith;
  date d{0};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days1)
{
  using namespace datearith;
  date d{1};
  EXPECT_EQ(2, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days30)
{
  using namespace datearith;
  date d{30};
  EXPECT_EQ(31, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days31)
{
  using namespace datearith;
  date d{31};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days58)
{
  using namespace datearith;
  date d{58};
  EXPECT_EQ(28, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days59)
{
  using namespace datearith;
  date d{59};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(3, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days364)
{
  using namespace datearith;
  date d{364};
  EXPECT_EQ(31, d.day());
  EXPECT_EQ(12, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, days365)
{
  using namespace datearith;
  date d{365};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1901, d.year());
}

TEST(date_init, days395)
{
  using namespace datearith;
  date d{395};
  EXPECT_EQ(31, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1901, d.year());
}

TEST(date_init, days396)
{
  using namespace datearith;
  date d{396};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(1901, d.year());
}

TEST(date_init, days4years)
{
  using namespace datearith;
  date d{365*4};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1904, d.year());
}

TEST(date_init, days4years58days)
{
  using namespace datearith;
  date d{365*4+58};
  EXPECT_EQ(28, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(1904, d.year());
}

TEST(date_init, days4years59days)
{
  using namespace datearith;
  date d{365*4+59};
  EXPECT_EQ(29, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(1904, d.year());
}

TEST(date_init, days4years60days)
{
  using namespace datearith;
  date d{365*4+60};
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(3, d.month());
  EXPECT_EQ(1904, d.year());
}
