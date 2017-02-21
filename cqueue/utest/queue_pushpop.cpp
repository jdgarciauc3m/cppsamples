#include "queue.h"
#include <gtest/gtest.h>

TEST(queue_nomt, push_pop)
{
  queue<int> q;
  q.push(3);
  auto x = q.pop();
  EXPECT_EQ(3,x);
  EXPECT_TRUE(q.empty());
}

TEST(queue_nomt, push_nopop)
{
  queue<int> q;
  q.push(3);
  EXPECT_FALSE(q.empty());
}

