#ifndef SHAPE_MATH_HELPER_HH__GUARD
#define SHAPE_MATH_HELPER_HH__GUARD

#include "vector.hh"
#include "matrix.hh"

namespace shape
{
	template<class T, class F> inline bool any(const vec2<T>&, F) noexcept;
	template<class T, class F> inline bool any(const vec3<T>&, F) noexcept;
	template<class T, class F> inline bool any(const vec4<T>&, F) noexcept;
	template<class T, class F> inline bool all(const vec2<T>&, F) noexcept;
	template<class T, class F> inline bool all(const vec3<T>&, F) noexcept;
	template<class T, class F> inline bool all(const vec4<T>&, F) noexcept;

	template<class T, class F> inline bool any(const mat2<T>&, F) noexcept;
	template<class T, class F> inline bool any(const mat3<T>&, F) noexcept;
	template<class T, class F> inline bool any(const mat4<T>&, F) noexcept;
	template<class T, class F> inline bool all(const mat2<T>&, F) noexcept;
	template<class T, class F> inline bool all(const mat3<T>&, F) noexcept;
	template<class T, class F> inline bool all(const mat4<T>&, F) noexcept;

	template<class T, class F> inline void broadcast(vec2<T>&, F) noexcept;
	template<class T, class F> inline void broadcast(vec3<T>&, F) noexcept;
	template<class T, class F> inline void broadcast(vec4<T>&, F) noexcept;
	template<class T, class F> inline void broadcast(mat2<T>&, F) noexcept;
	template<class T, class F> inline void broadcast(mat3<T>&, F) noexcept;
	template<class T, class F> inline void broadcast(mat4<T>&, F) noexcept;

	//!
	//! VECTOR x VECTOR OPERATORS
	//!

	template<class T> inline vec2<T> operator +(const vec2<T>& a, const vec2<T>& b) noexcept { return add(a, b); }
	template<class T> inline vec3<T> operator +(const vec3<T>& a, const vec3<T>& b) noexcept { return add(a, b); }
	template<class T> inline vec4<T> operator +(const vec4<T>& a, const vec4<T>& b) noexcept { return add(a, b); }
	template<class T> inline vec2<T> operator -(const vec2<T>& a, const vec2<T>& b) noexcept { return sub(a, b); }
	template<class T> inline vec3<T> operator -(const vec3<T>& a, const vec3<T>& b) noexcept { return sub(a, b); }
	template<class T> inline vec4<T> operator -(const vec4<T>& a, const vec4<T>& b) noexcept { return sub(a, b); }
	template<class T> inline vec2<T> operator *(const vec2<T>& a, const vec2<T>& b) noexcept { return mul(a, b); }
	template<class T> inline vec3<T> operator *(const vec3<T>& a, const vec3<T>& b) noexcept { return mul(a, b); }
	template<class T> inline vec4<T> operator *(const vec4<T>& a, const vec4<T>& b) noexcept { return mul(a, b); }
	template<class T> inline vec2<T> operator /(const vec2<T>& a, const vec2<T>& b) noexcept { return div(a, b); }
	template<class T> inline vec3<T> operator /(const vec3<T>& a, const vec3<T>& b) noexcept { return div(a, b); }
	template<class T> inline vec4<T> operator /(const vec4<T>& a, const vec4<T>& b) noexcept { return div(a, b); }

	template<class T> inline vec2<T> operator *(T a, const vec2<T>& b) noexcept { return mul(vec2<T>(a), b); }
	template<class T> inline vec3<T> operator *(T a, const vec3<T>& b) noexcept { return mul(vec3<T>(a), b); }
	template<class T> inline vec4<T> operator *(T a, const vec4<T>& b) noexcept { return mul(vec4<T>(a), b); }
	template<class T> inline vec2<T> operator /(T a, const vec2<T>& b) noexcept { return div(vec2<T>(a), b); }
	template<class T> inline vec3<T> operator /(T a, const vec3<T>& b) noexcept { return div(vec3<T>(a), b); }
	template<class T> inline vec4<T> operator /(T a, const vec4<T>& b) noexcept { return div(vec4<T>(a), b); }
	template<class T> inline vec2<T> operator *(const vec2<T>& a, T b) noexcept { return mul(a, vec2<T>(b)); }
	template<class T> inline vec3<T> operator *(const vec3<T>& a, T b) noexcept { return mul(a, vec3<T>(b)); }
	template<class T> inline vec4<T> operator *(const vec4<T>& a, T b) noexcept { return mul(a, vec4<T>(b)); }
	template<class T> inline vec2<T> operator /(const vec2<T>& a, T b) noexcept { return div(a, vec2<T>(b)); }
	template<class T> inline vec3<T> operator /(const vec3<T>& a, T b) noexcept { return div(a, vec3<T>(b)); }
	template<class T> inline vec4<T> operator /(const vec4<T>& a, T b) noexcept { return div(a, vec4<T>(b)); }

	//!
	//! VECTOR ASSIGNMENTS OPERATORS
	//!

	template<class T> inline vec2<T>& operator +=(vec2<T>& a, const vec2<T>& b) noexcept { return add(a, b); }
	template<class T> inline vec3<T>& operator +=(vec3<T>& a, const vec3<T>& b) noexcept { return add(a, b); }
	template<class T> inline vec4<T>& operator +=(vec4<T>& a, const vec4<T>& b) noexcept { return add(a, b); }
	template<class T> inline vec2<T>& operator -=(vec2<T>& a, const vec2<T>& b) noexcept { return sub(a, b); }
	template<class T> inline vec3<T>& operator -=(vec3<T>& a, const vec3<T>& b) noexcept { return sub(a, b); }
	template<class T> inline vec4<T>& operator -=(vec4<T>& a, const vec4<T>& b) noexcept { return sub(a, b); }
	template<class T> inline vec2<T>& operator *=(vec2<T>& a, const vec2<T>& b) noexcept { return mul(a, b); }
	template<class T> inline vec3<T>& operator *=(vec3<T>& a, const vec3<T>& b) noexcept { return mul(a, b); }
	template<class T> inline vec4<T>& operator *=(vec4<T>& a, const vec4<T>& b) noexcept { return mul(a, b); }
	template<class T> inline vec3<T>& operator /=(vec3<T>& a, const vec3<T>& b) noexcept { return div(a, b); }
	template<class T> inline vec2<T>& operator /=(vec2<T>& a, const vec2<T>& b) noexcept { return div(a, b); }
	template<class T> inline vec4<T>& operator /=(vec4<T>& a, const vec4<T>& b) noexcept { return div(a, b); }

	//!
	//! MATRIX x MATRIX OPERATORS
	//!

	template<class T> inline mat2<T> operator +(const mat2<T>& a, const mat2<T>& b) noexcept { return add(a, b); }
	template<class T> inline mat3<T> operator +(const mat3<T>& a, const mat3<T>& b) noexcept { return add(a, b); }
	template<class T> inline mat4<T> operator +(const mat4<T>& a, const mat4<T>& b) noexcept { return add(a, b); }
	template<class T> inline mat2<T> operator -(const mat2<T>& a, const mat2<T>& b) noexcept { return sub(a, b); }
	template<class T> inline mat3<T> operator -(const mat3<T>& a, const mat3<T>& b) noexcept { return sub(a, b); }
	template<class T> inline mat4<T> operator -(const mat4<T>& a, const mat4<T>& b) noexcept { return sub(a, b); }
	template<class T> inline mat2<T> operator *(const mat2<T>& a, const mat2<T>& b) noexcept { return mul(a, b); }
	template<class T> inline mat3<T> operator *(const mat3<T>& a, const mat3<T>& b) noexcept { return mul(a, b); }
	template<class T> inline mat4<T> operator *(const mat4<T>& a, const mat4<T>& b) noexcept { return mul(a, b); }
	template<class T> inline mat2<T> operator /(const mat2<T>& a, const mat2<T>& b) noexcept { return div(a, b); }
	template<class T> inline mat3<T> operator /(const mat3<T>& a, const mat3<T>& b) noexcept { return div(a, b); }
	template<class T> inline mat4<T> operator /(const mat4<T>& a, const mat4<T>& b) noexcept { return div(a, b); }

	//!
	//!

	template<class T, class F> bool any(const vec2<T>& v, F f) noexcept
	{
		return
			f(v.x()) ||
			f(v.y());
	}

	template<class T, class F> bool any(const vec3<T>& v, F f) noexcept
	{
		return
			f(v.x()) ||
			f(v.y()) ||
			f(v.z());
	}

	template<class T, class F> bool any(const vec4<T>& v, F f) noexcept
	{
		return
			f(v.x()) ||
			f(v.y()) ||
			f(v.z()) ||
			f(v.w());
	}

	template<class T, class F> bool all(const vec2<T>& v, F f) noexcept
	{
		return
			f(v.x()) &&
			f(v.y());
	}

	template<class T, class F> bool all(const vec3<T>& v, F f) noexcept
	{
		return
			f(v.x()) &&
			f(v.y()) &&
			f(v.z());
	}

	template<class T, class F> bool all(const vec4<T>& v, F f) noexcept
	{
		return
			f(v.x()) &&
			f(v.y()) &&
			f(v.z()) &&
			f(v.w());
	}

	template<class T, class F> bool any(const mat2<T>& m, F f) noexcept
	{
		return
			any(m.r0(), f) ||
			any(m.r1(), f);
	}

	template<class T, class F> bool any(const mat3<T>& m, F f) noexcept
	{
		return
			any(m.r0(), f) ||
			any(m.r1(), f) ||
			any(m.r2(), f);
	}

	template<class T, class F> bool any(const mat4<T>& m, F f) noexcept
	{
		return
			any(m.r0(), f) ||
			any(m.r1(), f) ||
			any(m.r2(), f) ||
			any(m.r3(), f);
	}

	template<class T, class F> bool all(const mat2<T>& m, F f) noexcept
	{
		return
			all(m.r0(), f) &&
			all(m.r1(), f);
	}

	template<class T, class F> bool all(const mat3<T>& m, F f) noexcept
	{
		return
			all(m.r0(), f) &&
			all(m.r1(), f) &&
			all(m.r2(), f);
	}

	template<class T, class F> bool all(const mat4<T>& m, F f) noexcept
	{
		return
			any(m.r0(), f) &&
			any(m.r1(), f) &&
			any(m.r2(), f) &&
			any(m.r3(), f);
	}


	template<class T, class F> void broadcast(vec2<T>& v, F f) noexcept
	{
		v.x() = f(v.x());
		v.y() = f(v.y());
	}

	template<class T, class F> void broadcast(vec3<T>& v, F f) noexcept
	{
		v.x() = f(v.x());
		v.y() = f(v.y());
		v.z() = f(v.z());
	}

	template<class T, class F> void broadcast(vec4<T>& v, F f) noexcept
	{
		v.x() = f(v.x());
		v.y() = f(v.y());
		v.z() = f(v.z());
		v.w() = f(v.w());
	}

	template<class T, class F> void broadcast(mat2<T>& m, F f) noexcept
	{
		broadcast(m.r0(), f);
		broadcast(m.r1(), f);
	}

	template<class T, class F> void broadcast(mat3<T>& m, F f) noexcept
	{
		broadcast(m.r0(), f);
		broadcast(m.r1(), f);
		broadcast(m.r2(), f);
	}

	template<class T, class F> void broadcast(mat4<T>& m, F f) noexcept
	{
		broadcast(m.r0(), f);
		broadcast(m.r1(), f);
		broadcast(m.r2(), f);
		broadcast(m.r3(), f);
	}

} // namespace shape

#endif