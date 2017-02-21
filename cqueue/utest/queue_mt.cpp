#include "queue.h"
#include <thread>
#include <gtest/gtest.h>

TEST(queue_mt, push_pop)
{
  queue<int> q;
  std::thread prod{[&] {
    q.push(3);
  }};
  std::thread cons{[&] {
    auto x = q.pop();
    EXPECT_EQ(3,x);
  }};

  prod.join();
  cons.join();

  EXPECT_TRUE(q.empty());
}

TEST(queue_mt, dpush_pop)
{
  using namespace std::chrono;
  queue<int> q;
  std::thread prod{[&] {
    std::this_thread::sleep_for(500ms);
    q.push(3);
  }};
  std::thread cons{[&] {
    std::this_thread::sleep_for(100ms);
    auto x = q.pop();
    EXPECT_EQ(3,x);
  }};

  prod.join();
  cons.join();

  EXPECT_TRUE(q.empty());
}

TEST(queue_mt, push_dpop)
{
  using namespace std::chrono;
  queue<int> q;
  std::thread prod{[&] {
    std::this_thread::sleep_for(100ms);
    q.push(3);
  }};
  std::thread cons{[&] {
    std::this_thread::sleep_for(500ms);
    auto x = q.pop();
    EXPECT_EQ(3,x);
  }};

  prod.join();
  cons.join();

  EXPECT_TRUE(q.empty());
}

