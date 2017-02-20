#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <mutex>

template <typename T>
class queue {
public:
  queue() noexcept = default;

  bool empty() const noexcept { return 0 == vec_.size(); }

private:
  std::vector<T> vec_;
  mutable std::mutex mut_;
};

#endif
