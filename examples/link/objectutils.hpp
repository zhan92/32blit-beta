#include <stdint.h>
#include <string>

#include "../object.h"

#ifndef TSR_OBJECTUTILS_H
#define TSR_OBJECTUTILS_H

using std::string;

using namespace tsr;

namespace tsr {
  namespace utils {

    class ObjectUtils {
    public:
      static object *load(string file);
    };

  }
}

#endif