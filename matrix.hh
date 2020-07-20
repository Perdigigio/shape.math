#ifndef SHAPE_MATH_MATRIX_HH__GUARD
#define SHAPE_MATH_MATRIX_HH__GUARD

#include "vector.hh"
#include "helper.hh"

namespace shape
{

	template <class T, int R, int C>
	struct matrix
	{
		//!
		//!

		T data[R][C];
	};

	template<class T>
	struct mat2 : matrix<T, 2, 2>
	{
		inline mat2();
		inline mat2(const T&, const T&, const T&, const T&);
		inline mat2(const T&);

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
	};

	template <class T>
	struct mat3 : matrix<T, 3, 3>
	{
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
	};

	template<class T>
	struct mat4 : matrix<T, 4, 4>
	{
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
	};

	template<class T> mat2<T> adjoint(const mat2<T>&) noexcept;
	template<class T> mat3<T> adjoint(const mat3<T>&) noexcept;
	template<class T> mat4<T> adjoint(const mat4<T>&) noexcept;
	template<class T> T determinant(const mat2<T>&) noexcept;
	template<class T> T determinant(const mat3<T>&) noexcept;
	template<class T> T determinant(const mat4<T>&) noexcept;
	template<class T> mat2<T> inverse(const mat2<T>&) noexcept;
	template<class T> mat3<T> inverse(const mat3<T>&) noexcept;
	template<class T> mat4<T> inverse(const mat4<T>&) noexcept;
	template<class T> T trace(const mat2<T>&) noexcept;
	template<class T> T trace(const mat3<T>&) noexcept;
	template<class T> T trace(const mat4<T>&) noexcept;
	template<class T> mat2<T> transpose(const mat2<T>&) noexcept;
	template<class T> mat3<T> transpose(const mat3<T>&) noexcept;
	template<class T> mat4<T> transpose(const mat4<T>&) noexcept;

	template<class T> void mul(mat2<T>&, const mat2<T>&, const mat2<T>&) noexcept;
	template<class T> void mul(vec2<T>&, const mat2<T>&, const vec2<T>&) noexcept;
	template<class T> void mul(mat3<T>&, const mat3<T>&, const mat3<T>&) noexcept;
	template<class T> void mul(vec3<T>&, const mat3<T>&, const vec3<T>&) noexcept;
	template<class T> void mul(mat4<T>&, const mat4<T>&, const mat4<T>&) noexcept;
	template<class T> void mul(vec4<T>&, const mat4<T>&, const vec4<T>&) noexcept;
	//!
	//! MATRIX
	//!

	template<class T> mat2<T>::mat2()
	{
		this->a() = T();
		this->b() = T();
		this->c() = T();
		this->d() = T();
	}

	template<class T> mat2<T>::mat2(const T& a, const T& b, const T& c, const T& d)
	{
		this->a() = a;
		this->b() = b;
		this->c() = c;
		this->d() = d;
	}

	template<class T> mat2<T>::mat2(const T& d)
	{
		this->a() = d;
		this->b() = T(0);
		this->c() = T(0);
		this->d() = d;
	}

	//!
	//!

	template<class T> void mul(mat2<T>& r, const mat2<T>& a, const mat2<T>& b) noexcept
	{
		vec2<T> r0 = vector_cast<T>(a.r0());
		vec2<T> r1 = vector_cast<T>(a.r1());
		vec2<T> c0 = vector_cast<T>(b.c0());
		vec2<T> c1 = vector_cast<T>(b.c1());

		//!
		//!

		r.r0() = { dot(r0, c0), dot(r0, c1) };
		r.r1() = { dot(r1, c0), dot(r1, c1) };
	}

	template<class T> void mul(vec2<T>& r, const mat2<T>& a, const vec2<T>& b) noexcept
	{
		r.x() = dot(vector_cast<T>(a.r0()), b);
		r.y() = dot(vector_cast<T>(a.r1()), b);
	}

	template<class T> void mul(mat3<T>& r, const mat3<T>& a, const mat3<T>& b) noexcept
	{
		vec2<T> r0 = vector_cast<T>(a.r0());
		vec2<T> r1 = vector_cast<T>(a.r1());
		vec2<T> r2 = vector_cast<T>(a.r2());
		vec2<T> c0 = vector_cast<T>(b.c0());
		vec2<T> c1 = vector_cast<T>(b.c1());
		vec2<T> c2 = vector_cast<T>(b.c2());

		//!
		//!

		r.r0() = { dot(r0, c0), dot(r0, c1), dot(r0, c2) };
		r.r1() = { dot(r1, c0), dot(r1, c1), dot(r1, c2) };
		r.r2() = { dot(r2, c0), dot(r2, c1), dot(r2, c2) };
	}

	template<class T> void mul(vec3<T>& r, const mat3<T>& a, const vec3<T>& b) noexcept
	{
		r.x() = dot(vector_cast<T>(a.r0()), b);
		r.y() = dot(vector_cast<T>(a.r1()), b);
		r.z() = dot(vector_cast<T>(a.r2()), b);
	}

	template<class T> void mul(mat4<T>& r, const mat4<T>& a, const mat4<T>& b) noexcept
	{
		vec2<T> r0 = vector_cast<T>(a.r0());
		vec2<T> r1 = vector_cast<T>(a.r1());
		vec2<T> r2 = vector_cast<T>(a.r2());
		vec2<T> r3 = vector_cast<T>(a.r3());
		vec2<T> c0 = vector_cast<T>(b.c0());
		vec2<T> c1 = vector_cast<T>(b.c1());
		vec2<T> c2 = vector_cast<T>(b.c2());
		vec2<T> c3 = vector_cast<T>(b.c3());

		//!
		//!

		r.r0() = { dot(r0, c0), dot(r0, c1), dot(r0, c2), dot(r0, c3) };
		r.r1() = { dot(r1, c0), dot(r1, c1), dot(r1, c2), dot(r1, c3) };
		r.r2() = { dot(r2, c0), dot(r2, c1), dot(r2, c2), dot(r2, c3) };
		r.r3() = { dot(r2, c0), dot(r2, c1), dot(r2, c2), dot(r3, c3) };
	}

	template<class T> void mul(vec4<T>& r, const mat4<T>& a, const vec4<T>& b) noexcept
	{
		r.x() = dot(vector_cast<T>(a.r0()), b);
		r.y() = dot(vector_cast<T>(a.r1()), b);
		r.z() = dot(vector_cast<T>(a.r2()), b);
		r.w() = dot(vector_cast<T>(a.r3()), b);
	}

} // namespace shape

#endif