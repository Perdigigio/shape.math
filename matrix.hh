#ifndef SHAPE_MATH_MATRIX_HH__GUARD
#define SHAPE_MATH_MATRIX_HH__GUARD

#include "vector.hh"

namespace shape
{

	template <class T, int R, int C> struct matrix
	{
		inline T* head() noexcept { return &data[0][0]; }
		inline T* tail() noexcept { return &data[R][0]; }
		inline T const* head() const noexcept { return &data[0][0]; }
		inline T const* tail() const noexcept { return &data[R][0]; }

		//!
		//!

		T data[R][C];
	};

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

		inline T const& a() const noexcept { return this->data[0][0]; }
		inline T const& b() const noexcept { return this->data[0][1]; }
		inline T const& c() const noexcept { return this->data[1][0]; }
		inline T const& d() const noexcept { return this->data[1][1]; }
		inline T& a() noexcept { return this->data[0][0]; }
		inline T& b() noexcept { return this->data[0][1]; }
		inline T& c() noexcept { return this->data[1][0]; }
		inline T& d() noexcept { return this->data[1][1]; }

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

		inline vec3<T const&> r0() const noexcept { return { this->data[0][0], this->data[0][1], this->data[0][2] }; }
		inline vec3<T const&> r1() const noexcept { return { this->data[1][0], this->data[1][1], this->data[1][2] }; }
		inline vec3<T const&> r2() const noexcept { return { this->data[2][0], this->data[2][1], this->data[2][2] }; }
		inline vec3<T const&> c0() const noexcept { return { this->data[0][0], this->data[1][0], this->data[2][0] }; }
		inline vec3<T const&> c1() const noexcept { return { this->data[0][1], this->data[1][1], this->data[2][1] }; }
		inline vec3<T const&> c2() const noexcept { return { this->data[0][2], this->data[1][2], this->data[2][2] }; }
		inline vec3<T&> r0() noexcept { return { this->data[0][0], this->data[0][1], this->data[0][2] }; }
		inline vec3<T&> r1() noexcept { return { this->data[1][0], this->data[1][1], this->data[1][2] }; }
		inline vec3<T&> r2() noexcept { return { this->data[2][0], this->data[2][1], this->data[2][2] }; }
		inline vec3<T&> c0() noexcept { return { this->data[0][0], this->data[1][0], this->data[2][0] }; }
		inline vec3<T&> c1() noexcept { return { this->data[0][1], this->data[1][1], this->data[2][1] }; }
		inline vec3<T&> c2() noexcept { return { this->data[0][2], this->data[1][2], this->data[2][2] }; }

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

		inline mat2<T const&> a() const noexcept { return { this->data[0][0], this->data[0][1], this->data[1][0], this->data[1][1] }; }
		inline mat2<T const&> b() const noexcept { return { this->data[0][2], this->data[0][3], this->data[1][2], this->data[1][3] }; }
		inline mat2<T const&> c() const noexcept { return { this->data[2][0], this->data[2][1], this->data[3][0], this->data[3][2] }; }
		inline mat2<T const&> d() const noexcept { return { this->data[2][2], this->data[2][3], this->data[3][2], this->data[3][3] }; }
		inline mat2<T&> a() noexcept { return { this->data[0][0], this->data[0][1], this->data[1][0], this->data[1][1] }; }
		inline mat2<T&> b() noexcept { return { this->data[0][2], this->data[0][3], this->data[1][2], this->data[1][3] }; }
		inline mat2<T&> c() noexcept { return { this->data[2][0], this->data[2][1], this->data[3][0], this->data[3][2] }; }
		inline mat2<T&> d() noexcept { return { this->data[2][2], this->data[2][3], this->data[3][2], this->data[3][3] }; }

		inline vec4<T const&> r0() const noexcept { return { this->data[0][0], this->data[0][1], this->data[0][2], this->data[0][3] }; }
		inline vec4<T const&> r1() const noexcept { return { this->data[1][0], this->data[1][1], this->data[1][2], this->data[1][3] }; }
		inline vec4<T const&> r2() const noexcept { return { this->data[2][0], this->data[2][1], this->data[2][2], this->data[2][3] }; }
		inline vec4<T const&> r3() const noexcept { return { this->data[3][0], this->data[3][1], this->data[3][2], this->data[3][3] }; }
		inline vec4<T const&> c0() const noexcept { return { this->data[0][0], this->data[1][0], this->data[2][0], this->data[3][0] }; }
		inline vec4<T const&> c1() const noexcept { return { this->data[0][1], this->data[1][1], this->data[2][1], this->data[3][1] }; }
		inline vec4<T const&> c2() const noexcept { return { this->data[0][2], this->data[1][2], this->data[2][2], this->data[3][2] }; }
		inline vec4<T const&> c3() const noexcept { return { this->data[0][3], this->data[1][3], this->data[2][3], this->data[3][3] }; }
		inline vec4<T&> r0() noexcept { return { this->data[0][0], this->data[0][1], this->data[0][2], this->data[0][3] }; }
		inline vec4<T&> r1() noexcept { return { this->data[1][0], this->data[1][1], this->data[1][2], this->data[1][3] }; }
		inline vec4<T&> r2() noexcept { return { this->data[2][0], this->data[2][1], this->data[2][2], this->data[2][3] }; }
		inline vec4<T&> r3() noexcept { return { this->data[3][0], this->data[3][1], this->data[3][2], this->data[3][3] }; }
		inline vec4<T&> c0() noexcept { return { this->data[0][0], this->data[1][0], this->data[2][0], this->data[3][0] }; }
		inline vec4<T&> c1() noexcept { return { this->data[0][1], this->data[1][1], this->data[2][1], this->data[3][1] }; }
		inline vec4<T&> c2() noexcept { return { this->data[0][2], this->data[1][2], this->data[2][2], this->data[3][2] }; }
		inline vec4<T&> c3() noexcept { return { this->data[0][3], this->data[1][3], this->data[2][3], this->data[3][3] }; }

		//!
		//!

		template<class U> inline mat4<T>& operator =(const mat4<U>&) noexcept;
	};

	template<class T> struct mat2<T&>
	{
		inline mat2(T& a, T& b, T& c, T& d) noexcept : data(a, b, c, d) {}

		inline T const& a() const noexcept { return data.x(); }
		inline T const& b() const noexcept { return data.y(); }
		inline T const& c() const noexcept { return data.z(); }
		inline T const& d() const noexcept { return data.w(); }
		inline T& a() noexcept { return data.x(); }
		inline T& b() noexcept { return data.y(); }
		inline T& c() noexcept { return data.z(); }
		inline T& d() noexcept { return data.w(); }

		inline vec2<T const&> r0() const noexcept { return vec2<T const&>{ this->a(), this->b() }; }
		inline vec2<T const&> r1() const noexcept { return vec2<T const&>{ this->c(), this->d() }; }
		inline vec2<T const&> c0() const noexcept { return vec2<T const&>{ this->a(), this->c() }; }
		inline vec2<T const&> c1() const noexcept { return vec2<T const&>{ this->b(), this->d() }; }
		inline vec2<T&> r0() noexcept { return vec2<T&>{ this->a(), this->b() }; }
		inline vec2<T&> r1() noexcept { return vec2<T&>{ this->c(), this->d() }; }
		inline vec2<T&> c0() noexcept { return vec2<T&>{ this->a(), this->c() }; }
		inline vec2<T&> c1() noexcept { return vec2<T&>{ this->b(), this->d() }; }

		inline mat2<T&>& operator =(const mat2<T>&) noexcept;

	private:
		vec4<T&> data;
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

	template<class T> mat2<T> add(const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> mat3<T> add(const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> mat4<T> add(const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> mat2<T> sub(const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> mat3<T> sub(const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> mat4<T> sub(const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> mat2<T> mul(const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> mat3<T> mul(const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> mat4<T> mul(const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> mat2<T> div(const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> mat3<T> div(const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> mat4<T> div(const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> mat2<T> mmm(const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> mat3<T> mmm(const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> mat4<T> mmm(const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> vec2<T> mvm(const mat2<T>&, const vec2<T>&) noexcept;
	template<class T> vec3<T> mvm(const mat3<T>&, const vec3<T>&) noexcept;
	template<class T> vec4<T> mvm(const mat4<T>&, const vec4<T>&) noexcept;

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
		this->r0() = o.r0();
		this->r1() = o.r1();
	}

	template<class T>
	template<class U> mat2<T>& mat2<T>::operator =(const mat2<U>& m) noexcept
	{
		this->r0() = m.r0();
		this->r1() = m.r1();

		//!
		//!

		return *this;
	}

	template<class T> mat2<T&>& mat2<T&>::operator =(const mat2<T>& o) noexcept
	{
		return (data = o.data, *this);
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
		this->r0() = o.r0();
		this->r1() = o.r1();
		this->r2() = o.r2();
	}

	template<class T>
	template<class U> mat3<T>& mat3<T>::operator =(const mat3<U>& m) noexcept
	{
		this->r0() = m.r0();
		this->r1() = m.r1();
		this->r3() = m.r3();

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
		this->r0() = o.r0();
		this->r1() = o.r1();
		this->r2() = o.r2();
		this->r3() = o.r3();
	}

	template<class T>
	template<class U> mat4<T>& mat4<T>::operator =(const mat4<U>& m) noexcept
	{
		this->r0() = m.r0();
		this->r1() = m.r1();
		this->r3() = m.r3();
		this->r4() = m.r4();

		//!
		//!

		return *this;
	}
	//!
	//!

	template<class T> T determinant(const mat2<T>& m) noexcept
	{
		//!
		//!

		return m.a() * m.d() - m.b() * m.c();
	}


	template<class T> T determinant(const mat3<T>& m) noexcept
	{
		//!
		//! SARRUS RULE
		//!

		return
			m.c0().x() * m.c1().y() * m.c2().z() +
			m.c1().x() * m.c2().y() * m.c0().z() +
			m.c2().x() * m.c0().y() * m.c1().z() -
			m.c1().x() * m.c0().y() * m.c2().z() -
			m.c0().x() * m.c2().y() * m.c1().z() -
			m.c2().x() * m.c1().y() * m.c0().z();
	}

	template<class T> T determinant(const mat4<T>& m) noexcept
	{
		mat2<T> a = m.a();
		mat2<T> b = m.b();
		mat2<T> c = m.c();
		mat2<T> d = m.d();

		mat2<T> AD = mul(a, d);
		mat2<T> BC = mul(b, c);

		//!
		//!

		return determinant(AD - BC);
	}

	template<class T> mat2<T> add(const mat2<T>& a, const mat2<T>& b) noexcept
	{
		vec2<T> ar0 = a.r0();
		vec2<T> br0 = b.r0();
		vec2<T> ar1 = a.r1();
		vec2<T> br1 = b.r1();

		//!
		//!

		vec2<T> v0 = ar0 + br0;
		vec2<T> v1 = ar1 + br1;

		//!
		//!

		return { v0, v1 };
	}

	template<class T> mat3<T> add(const mat3<T>& a, const mat3<T>& b) noexcept
	{
		vec3<T> ar0 = a.r0();
		vec3<T> br0 = b.r0();
		vec3<T> ar1 = a.r1();
		vec3<T> br1 = b.r1();
		vec3<T> ar2 = a.r2();
		vec3<T> br2 = b.r2();

		//!
		//!

		vec3<T> v0 = ar0 + br0;
		vec3<T> v1 = ar1 + br1;
		vec3<T> v2 = ar2 + br2;

		//!
		//!

		return { v0, v1, v2 };
	}

	template<class T> mat4<T> add(const mat4<T>& a, const mat4<T>& b) noexcept
	{
		vec4<T> ar0 = a.r0();
		vec4<T> br0 = b.r0();
		vec4<T> ar1 = a.r1();
		vec4<T> br1 = b.r1();
		vec4<T> ar2 = a.r2();
		vec4<T> br2 = b.r2();
		vec4<T> ar3 = a.r3();
		vec4<T> br3 = b.r3();

		//!
		//!

		vec4<T> v0 = ar0 + br0;
		vec4<T> v1 = ar1 + br1;
		vec4<T> v2 = ar2 + br2;
		vec4<T> v3 = ar3 + br3;

		//!
		//!

		return { v0, v1, v2, v3 };
	}

	template<class T> mat2<T> sub(const mat2<T>& a, const mat2<T>& b) noexcept
	{
		vec2<T> ar0 = a.r0();
		vec2<T> br0 = b.r0();
		vec2<T> ar1 = a.r1();
		vec2<T> br1 = b.r1();

		//!
		//!

		vec2<T> v0 = ar0 - br0;
		vec2<T> v1 = ar1 - br1;

		//!
		//!

		return { v0, v1 };
	}

	template<class T> mat3<T> sub(const mat3<T>& a, const mat3<T>& b) noexcept
	{
		vec3<T> ar0 = a.r0();
		vec3<T> br0 = b.r0();
		vec3<T> ar1 = a.r1();
		vec3<T> br1 = b.r1();
		vec3<T> ar2 = a.r2();
		vec3<T> br2 = b.r2();

		//!
		//!

		vec3<T> v0 = ar0 - br0;
		vec3<T> v1 = ar1 - br1;
		vec3<T> v2 = ar2 - br2;

		//!
		//!

		return { v0, v1, v2 };
	}

	template<class T> mat4<T> sub(const mat4<T>& a, const mat4<T>& b) noexcept
	{
		vec4<T> ar0 = a.r0();
		vec4<T> br0 = b.r0();
		vec4<T> ar1 = a.r1();
		vec4<T> br1 = b.r1();
		vec4<T> ar2 = a.r2();
		vec4<T> br2 = b.r2();
		vec4<T> ar3 = a.r3();
		vec4<T> br3 = b.r3();

		//!
		//!

		vec4<T> v0 = ar0 - br0;
		vec4<T> v1 = ar1 - br1;
		vec4<T> v2 = ar2 - br2;
		vec4<T> v3 = ar3 - br3;

		//!
		//!

		return { v0, v1, v2, v3 };
	}

	template<class T> mat2<T> mul(const mat2<T>& a, const mat2<T>& b) noexcept
	{
		vec2<T> r0 = mul<T>(a.r0(), b.r0());
		vec2<T> r1 = mul<T>(a.r1(), b.r1());

		//!
		//!

		return { r0, r1 };
	}

	template<class T> mat3<T> mul(const mat3<T>& a, const mat3<T>& b) noexcept
	{
		vec3<T> r0 = mul<T>(a.r0(), b.r0());
		vec3<T> r1 = mul<T>(a.r1(), b.r1());
		vec3<T> r2 = mul<T>(a.r2(), b.r2());

		//!
		//!

		return { r0, r1, r2 };
	}

	template<class T> mat4<T> mul(const mat4<T>& a, const mat4<T>& b) noexcept
	{
		vec4<T> r0 = mul<T>(a.r0(), b.r0());
		vec4<T> r1 = mul<T>(a.r1(), b.r1());
		vec4<T> r2 = mul<T>(a.r2(), b.r2());
		vec4<T> r3 = mul<T>(a.r3(), b.r3());

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	template<class T> mat2<T> div(const mat2<T>& a, const mat2<T>& b) noexcept
	{
		vec2<T> r0 = div<T>(a.r0(), b.r0());
		vec2<T> r1 = div<T>(a.r1(), b.r1());

		//!
		//!

		return { r0, r1 };
	}

	template<class T> mat3<T> div(const mat3<T>& a, const mat3<T>& b) noexcept
	{
		vec3<T> r0 = div<T>(a.r0(), b.r0());
		vec3<T> r1 = div<T>(a.r1(), b.r1());
		vec3<T> r2 = div<T>(a.r2(), b.r2());

		//!
		//!

		return { r0, r1, r2 };
	}

	template<class T> mat4<T> div(const mat4<T>& a, const mat4<T>& b) noexcept
	{
		vec4<T> r0 = div<T>(a.r0(), b.r0());
		vec4<T> r1 = div<T>(a.r1(), b.r1());
		vec4<T> r2 = div<T>(a.r2(), b.r2());
		vec4<T> r3 = div<T>(a.r3(), b.r3());

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	template<class T> mat2<T> mmm(const mat2<T>& a, const mat2<T>& b) noexcept
	{
		const vec2<T> r0 = a.r0();
		const vec2<T> r1 = a.r1();
		const vec2<T> c0 = b.c0();
		const vec2<T> c1 = b.c1();

		vec2<T> v0 = { dot(r0, c0), dot(r0, c1) };
		vec2<T> v1 = { dot(r1, c0), dot(r1, c1) };

		//!
		//!

		return { v0, v1 };
	}

	template<class T> mat3<T> mmm(const mat3<T>& a, const mat3<T>& b) noexcept
	{
		const vec3<T> r0 = a.r0();
		const vec3<T> r1 = a.r1();
		const vec3<T> r2 = a.r2();
		const vec3<T> c0 = b.c0();
		const vec3<T> c1 = b.c1();
		const vec3<T> c2 = b.c2();

		vec3<T> v0 = { dot(r0, c0), dot(r0, c1), dot(r0, c2) };
		vec3<T> v1 = { dot(r1, c0), dot(r1, c1), dot(r1, c2) };
		vec3<T> v2 = { dot(r2, c0), dot(r2, c1), dot(r2, c2) };

		//!
		//!

		return { v0, v1, v2 };
	}

	template<class T> mat4<T> mmm(const mat4<T>& a, const mat4<T>& b) noexcept
	{
		const vec4<T> r0 = a.r0();
		const vec4<T> r1 = a.r1();
		const vec4<T> r2 = a.r2();
		const vec4<T> r3 = a.r3();
		const vec4<T> c0 = b.c0();
		const vec4<T> c1 = b.c1();
		const vec4<T> c2 = b.c2();
		const vec4<T> c3 = b.c3();

		vec4<T> v0 = { dot(r0, c0), dot(r0, c1), dot(r0, c2), dot(r0, c3) };
		vec4<T> v1 = { dot(r1, c0), dot(r1, c1), dot(r1, c2), dot(r1, c3) };
		vec4<T> v2 = { dot(r2, c0), dot(r2, c1), dot(r2, c2), dot(r2, c3) };
		vec4<T> v3 = { dot(r2, c0), dot(r2, c1), dot(r2, c2), dot(r3, c3) };

		//!
		//!

		return { v0, v1, v2, v3 };
	}


	template<class T> vec2<T> mvm(const mat2<T>& a, const vec2<T>& b) noexcept
	{
		T x = dot<T>(a.r0(), b);
		T y = dot<T>(a.r1(), b);
		
		//!
		//!

		return { x, y };
	}


	template<class T> vec3<T> mvm(const mat3<T>& a, const vec3<T>& b) noexcept
	{
		T x = dot<T>(a.r0(), b);
		T y = dot<T>(a.r1(), b);
		T z = dot<T>(a.r2(), b);

		//!
		//!

		return { x, y, z };
	}



	template<class T> vec4<T> mvm(const mat4<T>& a, const vec4<T>& b) noexcept
	{
		T x = dot<T>(a.r0(), b);
		T y = dot<T>(a.r1(), b);
		T z = dot<T>(a.r2(), b);
		T w = dot<T>(a.r3(), b);

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