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

TEST(date_init, valid)
{
  using namespace datearith;
  date d{20,7,1969}; // First man on Moon
  EXPECT_EQ(20, d.day());
  EXPECT_EQ(7, d.month());
  EXPECT_EQ(1969, d.year());
}

TEST(date_init, first_valid)
{
  using namespace datearith;
  date d{1,1,1900}; 
  EXPECT_EQ(1, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(1900, d.year());
}

TEST(date_init, last_valid)
{
  using namespace datearith;
  date d{31,12,2200}; 
  EXPECT_EQ(31, d.day());
  EXPECT_EQ(12, d.month());
  EXPECT_EQ(2200, d.year());
}

TEST(date_init, invalid_low)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(31,12,1889);
    },
    invalid_date
  );
}

TEST(date_init, invalid_high)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(1,1,2201);
    },
    invalid_date
  );
}

TEST(date_init, valid_january)
{
  using namespace datearith;
  date d{31,1,2017};
  EXPECT_EQ(31, d.day());
  EXPECT_EQ(1, d.month());
  EXPECT_EQ(2017, d.year());
}

TEST(date_init, invalid_january)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(32,1,2017);
    },
    invalid_date
  );
}

TEST(date_init, valid_april)
{
  using namespace datearith;
  date d{30,4,2017};
  EXPECT_EQ(30, d.day());
  EXPECT_EQ(4, d.month());
  EXPECT_EQ(2017, d.year());
}

TEST(date_init, invalid_april)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(31,4,2017);
    },
    invalid_date
  );
}

TEST(date_init, valid_feb_nonleap)
{
  using namespace datearith;
  date d{28, 2, 2017};
  EXPECT_EQ(28, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(2017, d.year());
}

TEST(date_init, invalid_feb_nonleap)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(29, 2, 2017);
    },
    invalid_date
  );
}

TEST(date_init, valid_feb_regular_leap)
{
  using namespace datearith;
  date d{28, 2, 2004};
  EXPECT_EQ(28, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(2004, d.year());
}

TEST(date_init, valid_feb2_regular_leap)
{
  using namespace datearith;
  date d{29, 2, 2004};
  EXPECT_EQ(29, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(2004, d.year());
}

TEST(date_init, invalid_feb_regular_leap)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(30, 2, 2004);
    },
    invalid_date
  );
}

TEST(date_init, valid_feb_century_non_leap)
{
  using namespace datearith;
  date d{28, 2, 2100};
  EXPECT_EQ(28, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(2100, d.year());
}

TEST(date_init, valid_feb2_century_non_leap)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(29, 2, 2100);
    },
    invalid_date
  );
}

TEST(date_init, invalid_feb_century_non_leap)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(30, 2, 2100);
    },
    invalid_date
  );
}

TEST(date_init, valid_feb_century_leap)
{
  using namespace datearith;
  date d{28, 2, 2000};
  EXPECT_EQ(28, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(2000, d.year());
}

TEST(date_init, valid_feb2_century_leap)
{
  using namespace datearith;
  date d{29, 2, 2000};
  EXPECT_EQ(29, d.day());
  EXPECT_EQ(2, d.month());
  EXPECT_EQ(2000, d.year());
}

TEST(date_init, invalid_feb_century_leap)
{
  using namespace datearith;
  EXPECT_THROW({
      date d(30, 2, 2000);
    },
    invalid_date
  );
}

