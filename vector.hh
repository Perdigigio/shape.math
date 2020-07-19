#ifndef SHAPE_MATH_VECTOR_HH__GUARD
#define SHAPE_MATH_VECTOR_HH__GUARD

#include "helper.hh"

namespace shape
{
	template<class T, int N>
	struct vector
	{
		inline T const& operator[](int i) const { return data[i]; }
		inline T const& operator()(int i) const { return data[i]; }
		inline T& operator[](int i) { return data[i]; }
		inline T& operator()(int i) { return data[i]; }

		//!
		//!

		T data[N];
	};

	//!
	//! VECTOR SPECIALIZATIONS
	//!

	template<class T>
	struct vec2 : vector<T, 2>
	{
		inline vec2();
		inline vec2(const T&, const T&);
		inline vec2(const T&);

		//!
		//!

		inline T const& x() const noexcept { return data[0]; }
		inline T const& y() const noexcept { return data[1]; }
		inline T& x() noexcept { return data[0]; }
		inline T& y() noexcept { return data[1]; }
	};

	template<class T>
	struct vec3 : vector<T, 3>
	{
		vec3();
		vec3(const T&, const T&, const T&);
		vec3(const T&);

		//!
		//!

		inline T const& x() const noexcept { return data[0]; }
		inline T const& y() const noexcept { return data[1]; }
		inline T const& z() const noexcept { return data[2]; }
		inline T& x() noexcept { return data[0]; }
		inline T& y() noexcept { return data[1]; }
		inline T& z() noexcept { return data[2]; }
	};

	template<class T>
	struct vec4 : vector<T, 4>
	{
		vec4();
		vec4(const T&, const T&, const T&, const T&);
		vec4(const T&);

		//!
		//!

		inline T const& x() const noexcept { return data[0]; }
		inline T const& y() const noexcept { return data[1]; }
		inline T const& z() const noexcept { return data[2]; }
		inline T const& w() const noexcept { return data[3]; }
		inline T& x() noexcept { return data[0]; }
		inline T& y() noexcept { return data[1]; }
		inline T& z() noexcept { return data[2]; }
		inline T& w() noexcept { return data[3]; }
	};


	template<class T> inline T sum(vec2<T>);
	template<class T> inline T sum(vec3<T>);
	template<class T> inline T sum(vec4<T>);
	template<class T> inline T dot(vec2<T> a, vec2<T> b) { return sum(a * b); }
	template<class T> inline T dot(vec3<T> a, vec3<T> b) { return sum(a * b); }
	template<class T> inline T dot(vec4<T> a, vec4<T> b) { return sum(a * b); }

	template<class T> inline void add(vec2<T>&, const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline void sub(vec2<T>&, const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline void mul(vec2<T>&, const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline void div(vec2<T>&, const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline void add(vec3<T>&, const vec3<T>&, const vec3<T>&) noexcept;
	template<class T> inline void sub(vec3<T>&, const vec3<T>&, const vec3<T>&) noexcept;
	template<class T> inline void mul(vec3<T>&, const vec3<T>&, const vec3<T>&) noexcept;
	template<class T> inline void div(vec3<T>&, const vec3<T>&, const vec3<T>&) noexcept;	
	template<class T> inline void add(vec4<T>&, const vec4<T>&, const vec4<T>&) noexcept;
	template<class T> inline void sub(vec4<T>&, const vec4<T>&, const vec4<T>&) noexcept;
	template<class T> inline void mul(vec4<T>&, const vec4<T>&, const vec4<T>&) noexcept;
	template<class T> inline void div(vec4<T>&, const vec4<T>&, const vec4<T>&) noexcept;

	template<class T> inline void set(vec2<T>&, const T&) noexcept;
	template<class T> inline void set(vec3<T>&, const T&) noexcept;
	template<class T> inline void set(vec4<T>&, const T&) noexcept;

	template<class T, class U> inline vec2<T> vector_cast(const vec2<U>&) noexcept;
	template<class T, class U> inline vec3<T> vector_cast(const vec3<U>&) noexcept;
	template<class T, class U> inline vec4<T> vector_cast(const vec4<U>&) noexcept;

	//!
	//! VECTOR x VECTOR OPERATORS
	//!

	template<class T> inline vec2<T> operator+(vec2<T> a, vec2<T> b) noexcept { return a += b; }
	template<class T> inline vec2<T> operator-(vec2<T> a, vec2<T> b) noexcept { return a -= b; }
	template<class T> inline vec2<T> operator*(vec2<T> a, vec2<T> b) noexcept { return a *= b; }
	template<class T> inline vec2<T> operator/(vec2<T> a, vec2<T> b) noexcept { return a /= b; }
	template<class T> inline vec3<T> operator+(vec3<T> a, vec3<T> b) noexcept { return a += b; }
	template<class T> inline vec3<T> operator-(vec3<T> a, vec3<T> b) noexcept { return a -= b; }
	template<class T> inline vec3<T> operator*(vec3<T> a, vec3<T> b) noexcept { return a *= b; }
	template<class T> inline vec3<T> operator/(vec3<T> a, vec3<T> b) noexcept { return a /= b; }
	template<class T> inline vec4<T> operator+(vec4<T> a, vec4<T> b) noexcept { return a += b; }
	template<class T> inline vec4<T> operator-(vec4<T> a, vec4<T> b) noexcept { return a -= b; }
	template<class T> inline vec4<T> operator*(vec4<T> a, vec4<T> b) noexcept { return a *= b; }
	template<class T> inline vec4<T> operator/(vec4<T> a, vec4<T> b) noexcept { return a /= b; }

	//!
	//! ASSIGNMENTS OPERATORS
	//!

	template<class T> vec2<T>& operator+=(vec2<T>& a, vec2<T> b) noexcept { return add(a, a, b), a; }
	template<class T> vec2<T>& operator-=(vec2<T>& a, vec2<T> b) noexcept { return sub(a, a, b), a; }
	template<class T> vec2<T>& operator*=(vec2<T>& a, vec2<T> b) noexcept { return mul(a, a, b), a; }
	template<class T> vec2<T>& operator/=(vec2<T>& a, vec2<T> b) noexcept { return div(a, a, b), a; }
	template<class T> vec3<T>& operator+=(vec3<T>& a, vec3<T> b) noexcept { return add(a, a, b), a; }
	template<class T> vec3<T>& operator-=(vec3<T>& a, vec3<T> b) noexcept { return sub(a, a, b), a; }
	template<class T> vec3<T>& operator*=(vec3<T>& a, vec3<T> b) noexcept { return mul(a, a, b), a; }
	template<class T> vec3<T>& operator/=(vec3<T>& a, vec3<T> b) noexcept { return div(a, a, b), a; }	
	template<class T> vec4<T>& operator+=(vec4<T>& a, vec4<T> b) noexcept { return add(a, a, b), a; }
	template<class T> vec4<T>& operator-=(vec4<T>& a, vec4<T> b) noexcept { return sub(a, a, b), a; }
	template<class T> vec4<T>& operator*=(vec4<T>& a, vec4<T> b) noexcept { return mul(a, a, b), a; }
	template<class T> vec4<T>& operator/=(vec4<T>& a, vec4<T> b) noexcept { return div(a, a, b), a; }

	//!
	//! VECTOR2
	//!

	template<class T> vec2<T>::vec2()
	{
		this->x() = T();
		this->y() = T();
	}

	template<class T> vec2<T>::vec2(const T& x, const T& y)
	{
		this->x() = x;
		this->y() = y;
	}

	template<class T> vec2<T>::vec2(const T& s)
	{
		this->x() = s;
		this->y() = s;
	}

	//!
	//! VECTOR3
	//!

	template<class T> vec3<T>::vec3()
	{
		this->x() = T();
		this->y() = T();
		this->z() = T();
	}

	template<class T> vec3<T>::vec3(const T& x, const T& y, const T& z)
	{
		this->x() = x;
		this->y() = y;
		this->z() = z;
	}

	template<class T> vec3<T>::vec3(const T& s)
	{
		this->x() = s;
		this->y() = s;
		this->z() = s;
	}

	//!
	//! VECTOR4
	//!

	template<class T> vec4<T>::vec4()
	{
		this->x() = T();
		this->y() = T();
		this->z() = T();
		this->w() = T();
	}

	template<class T> vec4<T>::vec4(const T& x, const T& y, const T& z, const T& w)
	{
		this->x() = x;
		this->y() = y;
		this->z() = z;
		this->w() = w;
	}

	template<class T> vec4<T>::vec4(const T& s)
	{
		this->x() = s;
		this->y() = s;
		this->z() = s;
		this->w() = s;
	}

	//!
	//! IMPLEMENTATION
	//!

	template<class T, class U> vec2<T> vector_cast(const vec2<U>& v) noexcept { return vec2<T>{ v.x(), v.y() };	}
	template<class T, class U> vec2<T> vector_cast(const vec3<U>& v) noexcept { return vec3<T>{ v.x(), v.y(), v.z() }; }
	template<class T, class U> vec2<T> vector_cast(const vec4<U>& v) noexcept { return vec4<T>{ v.x(), v.y(), v.z(), v.w() }; }

	template<class T> T sum(vec2<T> v) { return v.x() + v.y(); }
	template<class T> T sum(vec3<T> v) { return v.x() + v.y() + v.z(); }
	template<class T> T sum(vec4<T> v) { return v.x() + v.y() + v.z() + v.w(); }

	template<class T> void add(vec2<T>& r, const vec2<T>& a, const vec2<T>& b) noexcept
	{
		r.x() = a.x() + b.x();
		r.y() = a.y() + b.y();
	}

	template<class T> void sub(vec2<T>& r, const vec2<T>& a, const vec2<T>& b) noexcept
	{
		r.x() = a.x() - b.x();
		r.y() = a.y() - b.y();
	}

	template<class T> void mul(vec2<T>& r, const vec2<T>& a, const vec2<T>& b) noexcept
	{
		r.x() = a.x() * b.x();
		r.y() = a.y() * b.y();
	}

	template<class T> void div(vec2<T>& r, const vec2<T>& a, const vec2<T>& b) noexcept
	{
		r.x() = a.x() / b.x();
		r.y() = a.y() / b.y();
	}

	template<class T> void add(vec3<T>& r, const vec3<T>& a, const vec3<T>& b) noexcept
	{
		r.x() = a.x() + b.x();
		r.y() = a.y() + b.y();
		r.z() = a.z() + b.z();
	}

	template<class T> void sub(vec3<T>& r, const vec3<T>& a, const vec3<T>& b) noexcept
	{
		r.x() = a.x() - b.x();
		r.y() = a.y() - b.y();
		r.z() = a.z() - b.z();
	}

	template<class T> void mul(vec3<T>& r, const vec3<T>& a, const vec3<T>& b) noexcept
	{
		r.x() = a.x() * b.x();
		r.y() = a.y() * b.y();
		r.z() = a.z() * b.z();
	}

	template<class T> void div(vec3<T>& r, const vec3<T>& a, const vec3<T>& b) noexcept
	{
		r.x() = a.x() / b.x();
		r.y() = a.y() / b.y();
		r.z() = a.z() / b.z();
	}

	template<class T> void add(vec4<T>& r, const vec4<T>& a, const vec4<T>& b) noexcept
	{
		r.x() = a.x() + b.x();
		r.y() = a.y() + b.y();
		r.z() = a.z() + b.z();
		r.w() = a.w() + b.w();
	}

	template<class T> void sub(vec4<T>& r, const vec4<T>& a, const vec4<T>& b) noexcept
	{
		r.x() = a.x() - b.x();
		r.y() = a.y() - b.y();
		r.z() = a.z() - b.z();
		r.w() = a.w() - b.w();
	}

	template<class T> void mul(vec4<T>& r, const vec4<T>& a, const vec4<T>& b) noexcept
	{
		r.x() = a.x() * b.x();
		r.y() = a.y() * b.y();
		r.z() = a.z() * b.z();
		r.w() = a.w() * b.w();
	}

	template<class T> void div(vec4<T>& r, const vec4<T>& a, const vec4<T>& b) noexcept
	{
		r.x() = a.x() / b.x();
		r.y() = a.y() / b.y();
		r.z() = a.z() / b.z();
		r.w() = a.w() / b.w();
	}

	template<class T> void set(vec2<T>& v, const T& s) noexcept { v = vec2<T>(s); }
	template<class T> void set(vec3<T>& v, const T& s) noexcept { v = vec3<T>(s); }
	template<class T> void set(vec4<T>& v, const T& s) noexcept { v = vec4<T>(s); }
}

#endif