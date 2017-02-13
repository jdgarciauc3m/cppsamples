#include "date.h"
#include <gtest/gtest.h>

TEST(date_epoch, day0)
{
  using namespace datearith;
  date d{1,1,1900};
  EXPECT_EQ(0, d.days_from_epoch());
}

TEST(date_epoch, feb_1_1900)
{
  using namespace datearith;
  date d{1,2,1900};
  EXPECT_EQ(31, d.days_from_epoch());
}

TEST(date_epoch, dec_31_1900)
{
  using namespace datearith;
  date d{31,12,1900};
  EXPECT_EQ(364, d.days_from_epoch());
}

TEST(date_epoch, jan_1_1901)
{
  using namespace datearith;
  date d{1,1,1901};
  EXPECT_EQ(365, d.days_from_epoch());
}

TEST(date_epoch, jan_1_1904)
{
  using namespace datearith;
  date d{1,1,1904};
  EXPECT_EQ(365*4, d.days_from_epoch());
}

TEST(date_epoch, feb_28_1904)
{
  using namespace datearith;
  date d{28,2,1904};
  EXPECT_EQ(365*4+31+27, d.days_from_epoch());
}

TEST(date_epoch, feb_29_1904)
{
  using namespace datearith;
  date d{29,2,1904};
  EXPECT_EQ(365*4+31+28, d.days_from_epoch());
}

TEST(date_epoch, mar_1_1904)
{
  using namespace datearith;
  date d{1,3,1904};
  EXPECT_EQ(365*4+31+29, d.days_from_epoch());
}

TEST(date_epoch, jan_1_1905)
{
  using namespace datearith;
  date d{1,1,1905};
  EXPECT_EQ(365*5+1, d.days_from_epoch());
}

TEST(date_epoch, jan_1_2000)
{
  using namespace datearith;
  date d{1,1,2000};
  EXPECT_EQ(36500 + 24, d.days_from_epoch());
}

TEST(date_epoch, mar_1_2000)
{
  using namespace datearith;
  date d{1,3,2000};
  EXPECT_EQ(36500 + 24 + 31 + 29, d.days_from_epoch());
}
