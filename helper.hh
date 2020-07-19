#ifndef SHAPE_MATH_HELPER_HH__GUARD
#define SHAPE_MATH_HELPER_HH__GUARD

#include "vector.hh"

namespace shape
{
	template<class T> struct vec2<T&>
	{
		inline explicit vec2(T& x, T& y) noexcept : _x(x), _y(y) {}

		inline T const& x() const noexcept { return _x; }
		inline T const& y() const noexcept { return _y; }
		inline T& x() noexcept { return _x; }
		inline T& y() noexcept { return _y; }

		vec2<T&>& operator =(const vec2<T>& o) noexcept;

	private:
		T& _x;
		T& _y;
	};

	template<class T> struct vec3<T&>
	{
		inline explicit vec3(T& x, T& y, T& z) noexcept : _x(x), _y(y), _z(z) {}

		inline T const& x() const noexcept { return _x; }
		inline T const& y() const noexcept { return _y; }
		inline T const& z() const noexcept { return _z; }
		inline T& x() noexcept { return _x; }
		inline T& y() noexcept { return _y; }
		inline T& z() noexcept { return _z; }

		vec3<T&>& operator =(const vec3<T>& o) noexcept;

	private:
		T& _x;
		T& _y;
		T& _z;
	};

	template<class T> struct vec4<T&>
	{
		inline explicit vec4(T& x, T& y, T& z, T& w) noexcept : _x(x), _y(y), _z(z), _w(w) {}

		inline T const& x() const noexcept { return _x; }
		inline T const& y() const noexcept { return _y; }
		inline T const& z() const noexcept { return _z; }
		inline T const& w() const noexcept { return _w; }
		inline T& x() noexcept { return _x; }
		inline T& y() noexcept { return _y; }
		inline T& z() noexcept { return _z; }
		inline T& w() noexcept { return _w; }

		inline vec4<T&>& operator =(const vec4<T>& o) noexcept;

	private:
		T& _x;
		T& _y;
		T& _z;
		T& _w;
	};

	//!
	//!

	template<class T> vec2<T&>& vec2<T&>::operator =(const vec2<T>& o) noexcept
	{
		_x = o.x();
		_y = o.y(); return *this;
	}

	template<class T> vec3<T&>& vec3<T&>::operator =(const vec3<T>& o) noexcept
	{
		_x = o.x();
		_y = o.y();
		_z = o.z(); return *this;
	}

	template<class T> vec4<T&>& vec4<T&>::operator =(const vec4<T>& o) noexcept
	{
		_x = o.x();
		_y = o.y();
		_z = o.z();
		_w = o.w(); return *this;
	}

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

} // namespace shape

#endif