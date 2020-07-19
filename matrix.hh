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
		
	};

	template<class T>
	struct mat4 : matrix<T, 4, 4>
	{
	};

	template<class T> vec2<T const&> row(const mat2<T>&, int) noexcept;
	template<class T> vec3<T const&> row(const mat3<T>&, int) noexcept;
	template<class T> vec4<T const&> row(const mat4<T>&, int) noexcept;
	template<class T> vec2<T const&> column(const mat2<T>&, int) noexcept;
	template<class T> vec3<T const&> column(const mat3<T>&, int) noexcept;
	template<class T> vec4<T const&> column(const mat4<T>&, int) noexcept;
	template<class T> vec2<T&> row(mat2<T>&, int) noexcept;
	template<class T> vec3<T&> row(mat3<T>&, int) noexcept;
	template<class T> vec4<T&> row(mat4<T>&, int) noexcept;
	template<class T> vec2<T&> column(mat2<T>&, int) noexcept;
	template<class T> vec3<T&> column(mat3<T>&, int) noexcept;
	template<class T> vec4<T&> column(mat4<T>&, int) noexcept;

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

} // namespace shape

#endif