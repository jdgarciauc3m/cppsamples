#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <mutex>
#include <condition_variable>

template <typename T>
class queue {
public:
  queue() noexcept = default;

  void push(const T & x) noexcept {
    std::unique_lock<std::mutex> l{mut_};
    vec_.push_back(x);
    if (vec_.size() == 1) {
      l.unlock();
      not_empty_.notify_one();
    }
  }

  T pop() noexcept {
    std::unique_lock<std::mutex> l{mut_};
    not_empty_.wait(l, [this] { return !vec_.empty(); });
    auto r = vec_.front();
    vec_.erase(vec_.begin());
    return r;
  }
    
  bool empty() const noexcept { 
    std::lock_guard<std::mutex> l{mut_};
    return 0 == vec_.size(); 
  }

private:
  std::vector<T> vec_;
  mutable std::mutex mut_;
  mutable std::condition_variable not_empty_;
};

#endif
