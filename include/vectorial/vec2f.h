#ifndef VECTORIAL_VEC_H

#ifndef VECTORIAL_SIMD4F_H
  #include "vectorial/simd4f.h"
#endif



namespace vectorial {
    

    class vec2f {
    public:

        simd4f value;
    
        inline vec2f() {}
        inline vec2f(const simd4f& v) : value(v) {}
        inline vec2f(float x, float y) : value( simd4f_create(x,y,0,0) ) {}
        inline vec2f(const float *ary) : value( simd4f_uload2(ary) ) { }
            
        inline float x() const { return simd4f_get_x(value); }
        inline float y() const { return simd4f_get_y(value); }

        inline void load(const float *ary) { value = simd4f_uload2(ary); }
        inline void store(float *ary) const { simd4f_ustore2(value, ary); }
    
        enum { elements = 2 };


    };


    vectorial_inline vec2f operator+(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_add(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator-(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_sub(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator*(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_mul(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator/(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_div(lhs.value, rhs.value) );
    }



    vectorial_inline vec2f operator+(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_add(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator-(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_sub(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator*(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_mul(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator/(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_div(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator+(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_add(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec2f operator-(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_sub(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec2f operator*(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_mul(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec2f operator/(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_div(simd4f_splat(lhs), rhs.value) );
    }



    vectorial_inline float dot(const vec2f& lhs, const vec2f& rhs) {
        return simd4f_get_x( simd4f_dot2(lhs.value, rhs.value) );
    }

    
    vectorial_inline float length(const vec2f& v) {
        return simd4f_get_x( simd4f_length2(v.value) );
    }

    vectorial_inline float length_squared(const vec2f& v) {
        return simd4f_get_x( simd4f_length2_squared(v.value) );
    }

    vectorial_inline vec2f normalize(const vec2f& v) {
        return vec2f( simd4f_normalize2(v.value) );
    }


}



#ifdef VECTORIAL_OSTREAM
#include <ostream>

static std::ostream& operator<<(std::ostream& os, const vectorial::vec2f& v) {
    os << "[ " << v.x() << ", "
               << v.y() << " ]";
    return os;
}
#endif




#endif
