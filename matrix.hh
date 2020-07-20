#ifndef SHAPE_MATH_MATRIX_HH__GUARD
#define SHAPE_MATH_MATRIX_HH__GUARD

#include "vector.hh"
#include "helper.hh"

namespace shape
{

	template <class T, int R, int C> struct matrix { T data[R][C]; };

	//!
	//! MATRIX SPECIALIZATIONS
	//!

	template<class T>
	struct mat2 : matrix<T, 2, 2>
	{
		inline mat2(const vec2<T>&, const vec2<T>&);

		inline mat2();
		inline mat2(const T&, const T&, const T&, const T&);
		inline mat2(const T&);

		template<class U> inline mat2(const mat2<U>&);

		inline T const& a() const noexcept { return data[0][0]; }
		inline T const& b() const noexcept { return data[0][1]; }
		inline T const& c() const noexcept { return data[1][0]; }
		inline T const& d() const noexcept { return data[1][1]; }
		inline T& a() noexcept { return data[0][0]; }
		inline T& b() noexcept { return data[0][1]; }
		inline T& c() noexcept { return data[1][0]; }
		inline T& d() noexcept { return data[1][1]; }

		inline vec2<T const&> r0() const noexcept { return vec2<T const&>{ this->a(), this->b() }; }
		inline vec2<T const&> r1() const noexcept { return vec2<T const&>{ this->c(), this->d() }; }
		inline vec2<T const&> c0() const noexcept { return vec2<T const&>{ this->a(), this->c() }; }
		inline vec2<T const&> c1() const noexcept { return vec2<T const&>{ this->b(), this->d() }; }
		inline vec2<T&> r0() noexcept { return vec2<T&>{ this->a(), this->b() }; }
		inline vec2<T&> r1() noexcept { return vec2<T&>{ this->c(), this->d() }; }
		inline vec2<T&> c0() noexcept { return vec2<T&>{ this->a(), this->c() }; }
		inline vec2<T&> c1() noexcept { return vec2<T&>{ this->b(), this->d() }; }

		//!
		//!

		template<class U> inline mat2<T>& operator =(const mat2<U>&) noexcept;
	};

	template <class T>
	struct mat3 : matrix<T, 3, 3>
	{
		inline mat3(const vec3<T>&, const vec3<T>&, const vec3<T>&);		

		inline mat3();
		inline mat3(const T&, const T&, const T&,
					const T&, const T&, const T&,
					const T&, const T&, const T&);
		inline mat3(const T&);

		template<class U> inline mat3(const mat3<U>&);

		inline vec3<T const&> r0() const noexcept { return { data[0][0], data[0][1], data[0][2] }; }
		inline vec3<T const&> r1() const noexcept { return { data[1][0], data[1][1], data[1][2] }; }
		inline vec3<T const&> r2() const noexcept { return { data[2][0], data[2][1], data[2][2] }; }
		inline vec3<T const&> c0() const noexcept { return { data[0][0], data[1][0], data[2][0] }; }
		inline vec3<T const&> c1() const noexcept { return { data[0][1], data[1][1], data[2][1] }; }
		inline vec3<T const&> c2() const noexcept { return { data[0][2], data[1][2], data[2][2] }; }
		inline vec3<T&> r0() noexcept { return { data[0][0], data[0][1], data[0][2] }; }
		inline vec3<T&> r1() noexcept { return { data[1][0], data[1][1], data[1][2] }; }
		inline vec3<T&> r2() noexcept { return { data[2][0], data[2][1], data[2][2] }; }
		inline vec3<T&> c0() noexcept { return { data[0][0], data[1][0], data[2][0] }; }
		inline vec3<T&> c1() noexcept { return { data[0][1], data[1][1], data[2][1] }; }
		inline vec3<T&> c2() noexcept { return { data[0][2], data[1][2], data[2][2] }; }

		//!
		//!

		template<class U> inline mat3<T>& operator =(const mat3<U>&) noexcept;
	};

	template<class T>
	struct mat4 : matrix<T, 4, 4>
	{
		inline mat4(const vec4<T>&, const vec4<T>&, const vec4<T>&, const vec4<T>&);

		inline mat4();
		inline mat4(const T&, const T&, const T&, const T&,
					const T&, const T&, const T&, const T&,
					const T&, const T&, const T&, const T&,
					const T&, const T&, const T&, const T&);
		inline mat4(const T&);

		template<class U> inline mat4(const mat4<U>&);

		inline mat2<T const&> a() const noexcept { return { data[0][0], data[0][1], data[1][0], data[1][2] }; }
		inline mat2<T const&> b() const noexcept { return { data[0][2], data[0][3], data[1][2], data[1][3] }; }
		inline mat2<T const&> c() const noexcept { return { data[2][0], data[2][1], data[3][0], data[3][2] }; }
		inline mat2<T const&> d() const noexcept { return { data[2][2], data[2][3], data[3][2], data[3][3] }; }
		inline mat2<T&> a() noexcept { return { data[0][0], data[0][1], data[1][0], data[1][2] }; }
		inline mat2<T&> b() noexcept { return { data[0][2], data[0][3], data[1][2], data[1][3] }; }
		inline mat2<T&> c() noexcept { return { data[2][0], data[2][1], data[3][0], data[3][2] }; }
		inline mat2<T&> d() noexcept { return { data[2][2], data[2][3], data[3][2], data[3][3] }; }

		inline vec4<T const&> r0() const noexcept { return { data[0][0], data[0][1], data[0][2], data[0][3] }; }
		inline vec4<T const&> r1() const noexcept { return { data[1][0], data[1][1], data[1][2], data[1][3] }; }
		inline vec4<T const&> r2() const noexcept { return { data[2][0], data[2][1], data[2][2], data[2][3] }; }
		inline vec4<T const&> r3() const noexcept { return { data[3][0], data[3][1], data[3][2], data[3][3] }; }
		inline vec4<T const&> c0() const noexcept { return { data[0][0], data[1][0], data[2][0], data[3][0] }; }
		inline vec4<T const&> c1() const noexcept { return { data[0][1], data[1][1], data[2][1], data[3][1] }; }
		inline vec4<T const&> c2() const noexcept { return { data[0][2], data[1][2], data[2][2], data[3][2] }; }
		inline vec4<T const&> c3() const noexcept { return { data[0][3], data[1][3], data[2][3], data[3][3] }; }
		inline vec4<T&> r0() noexcept { return { data[0][0], data[0][1], data[0][2], data[0][3] }; }
		inline vec4<T&> r1() noexcept { return { data[1][0], data[1][1], data[1][2], data[1][3] }; }
		inline vec4<T&> r2() noexcept { return { data[2][0], data[2][1], data[2][2], data[2][3] }; }
		inline vec4<T&> r3() noexcept { return { data[3][0], data[3][1], data[3][2], data[3][3] }; }
		inline vec4<T&> c0() noexcept { return { data[0][0], data[1][0], data[2][0], data[3][0] }; }
		inline vec4<T&> c1() noexcept { return { data[0][1], data[1][1], data[2][1], data[3][1] }; }
		inline vec4<T&> c2() noexcept { return { data[0][2], data[1][2], data[2][2], data[3][2] }; }
		inline vec4<T&> c3() noexcept { return { data[0][3], data[1][3], data[2][3], data[3][3] }; }

		//!
		//!

		template<class U> inline mat4<T>& operator =(const mat4<U>&) noexcept;
	};

	template<class T> struct mat2<T&>
	{
		inline mat2(T& a, T& b, T& c, T& d) noexcept : _a(a), _b(b), _c(c), _d(d) {}

		inline T const& a() const noexcept { return _a; }
		inline T const& b() const noexcept { return _b; }
		inline T const& c() const noexcept { return _c; }
		inline T const& d() const noexcept { return _d; }
		inline T& a() noexcept { return _a; }
		inline T& b() noexcept { return _b; }
		inline T& c() noexcept { return _c; }
		inline T& d() noexcept { return _d; }

		inline vec2<T const&> r0() const noexcept { return vec2<T const&>{ this->a(), this->b() }; }
		inline vec2<T const&> r1() const noexcept { return vec2<T const&>{ this->c(), this->d() }; }
		inline vec2<T const&> c0() const noexcept { return vec2<T const&>{ this->a(), this->c() }; }
		inline vec2<T const&> c1() const noexcept { return vec2<T const&>{ this->b(), this->d() }; }
		inline vec2<T&> r0() noexcept { return vec2<T&>{ this->a(), this->b() }; }
		inline vec2<T&> r1() noexcept { return vec2<T&>{ this->c(), this->d() }; }
		inline vec2<T&> c0() noexcept { return vec2<T&>{ this->a(), this->c() }; }
		inline vec2<T&> c1() noexcept { return vec2<T&>{ this->b(), this->d() }; }

		inline mat2<T&>& operator =(const mat2<T>&) noexcept;

		vec2<T&> _r0;
		vec2<T&> _r1;
	};

	template<class T> T determinant(const mat2<T>&) noexcept;
	template<class T> T determinant(const mat3<T>&) noexcept;
	template<class T> T determinant(const mat4<T>&) noexcept;
	template<class T> T trace(const mat2<T>&) noexcept;
	template<class T> T trace(const mat3<T>&) noexcept;
	template<class T> T trace(const mat4<T>&) noexcept;

	template<class T> mat2<T> adj(const mat2<T>&) noexcept;
	template<class T> mat3<T> adj(const mat3<T>&) noexcept;
	template<class T> mat4<T> adj(const mat4<T>&) noexcept;
	template<class T> mat2<T> inv(const mat2<T>&) noexcept;
	template<class T> mat3<T> inv(const mat3<T>&) noexcept;
	template<class T> mat4<T> inv(const mat4<T>&) noexcept;
	template<class T> mat2<T> transpose(const mat2<T>&) noexcept;
	template<class T> mat3<T> transpose(const mat3<T>&) noexcept;
	template<class T> mat4<T> transpose(const mat4<T>&) noexcept;

	template<class T> mat2<T> mul(const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> mat3<T> mul(const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> mat4<T> mul(const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> vec2<T> mul(const mat2<T>&, const vec2<T>&) noexcept;
	template<class T> vec3<T> mul(const mat3<T>&, const vec3<T>&) noexcept;
	template<class T> vec4<T> mul(const mat4<T>&, const vec4<T>&) noexcept;

	//!
	//! MATRIX2
	//!

	template<class T> mat2<T>::mat2(const vec2<T>& r0, const vec2<T>& r1)
	{
		this->r0() = r0;
		this->r1() = r1;
	}

	template<class T> mat2<T>::mat2()
	{
		this->r0() = vec2<T>{};
		this->r1() = vec2<T>{};
	}

	template<class T> mat2<T>::mat2(const T& a, const T& b, const T& c, const T& d)
	{
		this->r0() = vec2<T>{ a, b };
		this->r1() = vec2<T>{ c, d };
	}

	template<class T> mat2<T>::mat2(const T& d)
	{
		this->r0() = vec2<T>{ d, 0 };
		this->r1() = vec2<T>{ 0, d };
	}

	template<class T>
	template<class U> mat2<T>::mat2(const mat2<U>& o)
	{
		this->r0() = vector_cast<T>(o.r0());
		this->r1() = vector_cast<T>(o.r1());
	}

	template<class T>
	template<class U> mat2<T>& mat2<T>::operator =(const mat2<U>& m) noexcept
	{
		this->r0() = vector_cast<T>(m.r0());
		this->r1() = vector_cast<T>(m.r1());

		//!
		//!

		return *this;
	}

	template<class T> mat2<T&>& mat2<T&>::operator =(const mat2<T>& o) noexcept
	{
		_a = o.a();
		_b = o.b();
		_c = o.c();
		_d = o.d(); return *this;
	}

	//!
	//! MATRIX3
	//!

	template<class T> mat3<T>::mat3(const vec3<T>& r0, const vec3<T>& r1, const vec3<T>& r2)
	{
		this->r0() = r0;
		this->r1() = r1;
		this->r2() = r2;
	}

	template<class T> mat3<T>::mat3()
	{
		this->r0() = vec3<T>();
		this->r1() = vec3<T>();
		this->r2() = vec3<T>();
	}

	template<class T> mat3<T>::mat3(
		const T& _11, const T& _12, const T& _13,
		const T& _21, const T& _22, const T& _23,
		const T& _31, const T& _32, const T& _33)
	{
		this->r0() = vec3<T>{ _11, _12, _13 };
		this->r1() = vec3<T>{ _21, _22, _23 };
		this->r2() = vec3<T>{ _31, _32, _33 };
	}

	template<class T> mat3<T>::mat3(const T& d)
	{
		this->r0() = vec3<T>{ d, 0, 0 };
		this->r1() = vec3<T>{ 0, d, 0 };
		this->r2() = vec3<T>{ 0, 0, d };
	}

	template<class T>
	template<class U> mat3<T>::mat3(const mat3<U>& o)
	{
		this->r0() = vector_cast<T>(o.r0());
		this->r1() = vector_cast<T>(o.r1());
		this->r2() = vector_cast<T>(o.r2());
	}

	template<class T>
	template<class U> mat3<T>& mat3<T>::operator =(const mat3<U>& m) noexcept
	{
		this->r0() = vector_cast<T>(m.r0());
		this->r1() = vector_cast<T>(m.r1());
		this->r3() = vector_cast<T>(m.r3());

		//!
		//!

		return *this;
	}

	//!
	//! MATRIX4
	//!

	template<class T> mat4<T>::mat4(const vec4<T>& r0, const vec4<T>& r1, const vec4<T>& r2, const vec4<T>& r3)
	{
		this->r0() = r0;
		this->r1() = r1;
		this->r2() = r2;
		this->r3() = r3;
	}

	template<class T> mat4<T>::mat4()
	{
		this->r0() = vec4<T>();
		this->r1() = vec4<T>();
		this->r2() = vec4<T>();
		this->r3() = vec4<T>();
	}

	template<class T> mat4<T>::mat4(
		const T& _11, const T& _12, const T& _13, const T& _14,
		const T& _21, const T& _22, const T& _23, const T& _24,
		const T& _31, const T& _32, const T& _33, const T& _34,
		const T& _41, const T& _42, const T& _43, const T& _44)
	{
		this->r0() = vec4<T>{ _11, _12, _13, _14 };
		this->r1() = vec4<T>{ _21, _22, _23, _24 };
		this->r2() = vec4<T>{ _31, _32, _33, _34 };
		this->r3() = vec4<T>{ _41, _42, _43, _44 };
	}

	template<class T> mat4<T>::mat4(const T& d)
	{
		this->r0() = vec4<T>{ d, 0, 0, 0 };
		this->r1() = vec4<T>{ 0, d, 0, 0 };
		this->r2() = vec4<T>{ 0, 0, d, 0 };
		this->r3() = vec4<T>{ 0, 0, 0, d };
	}

	template<class T>
	template<class U> mat4<T>::mat4(const mat4<U>& o)
	{
		this->r0() = vector_cast<T>(o.r0());
		this->r1() = vector_cast<T>(o.r1());
		this->r2() = vector_cast<T>(o.r2());
		this->r3() = vector_cast<T>(o.r3());
	}

	template<class T>
	template<class U> mat4<T>& mat4<T>::operator =(const mat4<U>& m) noexcept
	{
		this->r0() = vector_cast<T>(m.r0());
		this->r1() = vector_cast<T>(m.r1());
		this->r3() = vector_cast<T>(m.r3());
		this->r4() = vector_cast<T>(m.r4());

		//!
		//!

		return *this;
	}
	//!
	//!

	template<class T> mat2<T> mul(const mat2<T>& a, const mat2<T>& b) noexcept
	{
		vec2<T> r0 = vector_cast<T>(a.r0());
		vec2<T> r1 = vector_cast<T>(a.r1());
		vec2<T> c0 = vector_cast<T>(b.c0());
		vec2<T> c1 = vector_cast<T>(b.c1());

		vec2<T> v0 = { dot(r0, c0), dot(r0, c1) };
		vec2<T> v1 = { dot(r1, c0), dot(r1, c1) };

		//!
		//!

		return { v0, v1 };
	}

	template<class T> mat3<T> mul(const mat3<T>& a, const mat3<T>& b) noexcept
	{
		vec3<T> r0 = vector_cast<T>(a.r0());
		vec3<T> r1 = vector_cast<T>(a.r1());
		vec3<T> r2 = vector_cast<T>(a.r2());
		vec3<T> c0 = vector_cast<T>(b.c0());
		vec3<T> c1 = vector_cast<T>(b.c1());
		vec3<T> c2 = vector_cast<T>(b.c2());

		vec3<T> v0 = { dot(r0, c0), dot(r0, c1), dot(r0, c2) };
		vec3<T> v1 = { dot(r1, c0), dot(r1, c1), dot(r1, c2) };
		vec3<T> v2 = { dot(r2, c0), dot(r2, c1), dot(r2, c2) };

		//!
		//!

		return { v0, v1, v2 };
	}

	template<class T> mat4<T> mul(const mat4<T>& a, const mat4<T>& b) noexcept
	{
		vec2<T> r0 = vector_cast<T>(a.r0());
		vec2<T> r1 = vector_cast<T>(a.r1());
		vec2<T> r2 = vector_cast<T>(a.r2());
		vec2<T> r3 = vector_cast<T>(a.r3());
		vec2<T> c0 = vector_cast<T>(b.c0());
		vec2<T> c1 = vector_cast<T>(b.c1());
		vec2<T> c2 = vector_cast<T>(b.c2());
		vec2<T> c3 = vector_cast<T>(b.c3());

		vec4<T> v0 = { dot(r0, c0), dot(r0, c1), dot(r0, c2), dot(r0, c3) };
		vec4<T> v1 = { dot(r1, c0), dot(r1, c1), dot(r1, c2), dot(r1, c3) };
		vec4<T> v2 = { dot(r2, c0), dot(r2, c1), dot(r2, c2), dot(r2, c3) };
		vec4<T> v3 = { dot(r2, c0), dot(r2, c1), dot(r2, c2), dot(r3, c3) };

		//!
		//!

		return { v0, v1, v2, v3 };
	}


	template<class T> void mul(vec2<T>& r, const mat2<T>& a, const vec2<T>& b) noexcept
	{
		T x = dot(vector_cast<T>(a.r0()), b);
		T y = dot(vector_cast<T>(a.r1()), b);
		
		//!
		//!

		return { x, y };
	}


	template<class T> vec3<T> mul(const mat3<T>& a, const vec3<T>& b) noexcept
	{
		T x = dot(vector_cast<T>(a.r0()), b);
		T y = dot(vector_cast<T>(a.r1()), b);
		T z = dot(vector_cast<T>(a.r2()), b);

		//!
		//!

		return { x, y, z };
	}



	template<class T> vec4<T> mul(const mat4<T>& a, const vec4<T>& b) noexcept
	{
		T x = dot(vector_cast<T>(a.r0()), b);
		T y = dot(vector_cast<T>(a.r1()), b);
		T z = dot(vector_cast<T>(a.r2()), b);
		T w = dot(vector_cast<T>(a.r3()), b);

		//!
		//!

		return { x, y, z, w };
	}

	template<class T> T trace(const mat2<T>& m) noexcept
	{
		return	m.r0().x() +
				m.r1().y();
	}

	template<class T> T trace(const mat3<T>& m) noexcept
	{
		return	m.r0().x() +
				m.r1().y() +
				m.r2().z();
	}

	template<class T> T trace(const mat4<T>& m) noexcept
	{
		return	m.r0().x() +
				m.r1().y() +
				m.r2().z() +
				m.r3().w();
	}

	template<class T> mat2<T> transpose(const mat2<T>& m) noexcept
	{
		vec2<T> c0 = vector_cast<T>(m.c0());
		vec2<T> c1 = vector_cast<T>(m.c1());

		//!
		//!

		return { c0, c1 };
	}

	template<class T> mat3<T> transpose(const mat3<T>& m) noexcept
	{
		vec3<T> c0 = vector_cast<T>(m.c0());
		vec3<T> c1 = vector_cast<T>(m.c1());
		vec3<T> c2 = vector_cast<T>(m.c2());

		//!
		//!
		
		return { c0, c1, c2 };
	}

	template<class T> mat4<T>& transpose(const mat4<T>& m) noexcept
	{
		vec4<T> c0 = vector_cast<T>(m.c0());
		vec4<T> c1 = vector_cast<T>(m.c1());
		vec4<T> c2 = vector_cast<T>(m.c2());
		vec4<T> c3 = vector_cast<T>(m.c3());

		//!
		//!

		return { c0, c1, c2, c3 };
	}

} // namespace shape

#endif