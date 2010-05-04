#ifndef VECTORIAL_SIMD4F_H
#define VECTORIAL_SIMD4F_H

#ifndef VECTORIAL_CONFIG_H
  #include "vectorial/config.h"
#endif


#ifdef VECTORIAL_SCALAR
    #include "simd4f_scalar.h"
#elif defined(VECTORIAL_SSE)
    #include "simd4f_sse.h"
#elif defined(VECTORIAL_GNU)
    #include "simd4f_gnu.h"
#elif defined(VECTORIAL_NEON)
    #include "simd4f_neon.h"
#else
    #error No implementation defined
#endif

#include "simd4f_common.h"



#ifdef __cplusplus

    #ifdef VECTORIAL_OSTREAM
        #include <ostream>

        static std::ostream& operator<<(std::ostream& os, const simd4f& v) {
            os << "simd4f(" << simd4f_get_x(v) << ", "
                       << simd4f_get_y(v) << ", "
                       << simd4f_get_z(v) << ", "
                       << simd4f_get_w(v) << ")";
            return os;
        }
    #endif

#endif




#endif

