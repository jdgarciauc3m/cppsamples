#include "duration.h"

namespace datearith {

void duration::normalize() noexcept {
  months_ = (days_<365) ? (months_+days_/30) : months_;

  years_ = ((days_<365) ? years_ : (years_+days_/365)) +
           ((months_ >=12)?(months_/12):0);

  months_ %= (months_ >=12)?12:(months_+1);

  days_ = (days_<365) ? (days_%30) : (days_%365);
}

}
