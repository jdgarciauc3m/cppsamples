#include <iostream>
#include "date.h"

void print(const std::string & str, datearith::date d) {
  using namespace std;
  cout << str;
  cout << d.day() << "/";
  cout << d.month() << "/";
  cout << d.year() << "\n";
}

int main() {
  using namespace datearith;
 
  date a{1,3,2017};

  print("a=",a);

  return 0;
}
