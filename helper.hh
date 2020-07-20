#ifndef SHAPE_MATH_HELPER_HH__GUARD
#define SHAPE_MATH_HELPER_HH__GUARD

#include "vector.hh"

namespace shape
{


	



	//!
	//!

	template<class T, class U> vec2<T&>& operator +=(vec2<T&>& a, const vec2<U>& b) { return a = vector_cast<T>(a) + b; }
	template<class T, class U> vec2<T&>& operator -=(vec2<T&>& a, const vec2<U>& b) { return a = vector_cast<T>(a) - b; }
	template<class T, class U> vec2<T&>& operator /=(vec2<T&>& a, const vec2<U>& b) { return a = vector_cast<T>(a) / b; }
	template<class T, class U> vec2<T&>& operator *=(vec2<T&>& a, const vec2<U>& b) { return a = vector_cast<T>(a) * vector_cast<T>(b); }

	template<class T, class U> vec3<T&>& operator +=(vec3<T&>& a, const vec3<U>& b) { return a = vector_cast<T>(a) + b; }
	template<class T, class U> vec3<T&>& operator -=(vec3<T&>& a, const vec3<U>& b) { return a = vector_cast<T>(a) - b; }
	template<class T, class U> vec3<T&>& operator /=(vec3<T&>& a, const vec3<U>& b) { return a = vector_cast<T>(a) / b; }
	template<class T, class U> vec3<T&>& operator *=(vec3<T&>& a, const vec3<U>& b) { return a = vector_cast<T>(a) * b; }

	template<class T, class U> vec4<T&>& operator +=(vec4<T&>& a, const vec4<U>& b) { return a = vector_cast<T>(a) + b; }
	template<class T, class U> vec4<T&>& operator -=(vec4<T&>& a, const vec4<U>& b) { return a = vector_cast<T>(a) - b; }
	template<class T, class U> vec4<T&>& operator /=(vec4<T&>& a, const vec4<U>& b) { return a = vector_cast<T>(a) / b; }
	template<class T, class U> vec4<T&>& operator *=(vec4<T&>& a, const vec4<U>& b) { return a = vector_cast<T>(a) * b; }

	//!
	//!


} // namespace shape

#endif