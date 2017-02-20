#include "queue.h"
#include <gtest/gtest.h>

TEST(queue_init, defconstruct)
{
  queue<int> q;
  EXPECT_TRUE(q.empty());
}

