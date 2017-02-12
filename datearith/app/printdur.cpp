#include <iostream>
#include "duration.h"

void print(const std::string & str, datearith::duration d) {
  using namespace std;
  cout << str;
  cout << d.days() << " days, ";
  cout << d.months() << " months, ";
  cout << d.years() << " years\n";
}

int main() {
  using namespace datearith;

  duration d1{1,2,3}; // 1 day, 2 months, 3 years
  duration d2{366, 0, 1}; // 1 day, 2 years

  print("d1=", d1);
  print("d2=", d2);

  return 0;
}
