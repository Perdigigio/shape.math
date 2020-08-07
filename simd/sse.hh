#ifndef SHAPE_MATH_SIMD_SSE_HH__GUARD
#define SHAPE_MATH_SIMD_SSE_HH__GUARD

#include "../vector.hh"
#include "../matrix.hh"

#include <immintrin.h>

namespace shape
{

	struct simd_vec4
	{
		inline simd_vec4() {}
		inline simd_vec4(__m128 data) : xyzw(data) {}

		//!
		//!

		__m128 xyzw;
	};

	struct simd_mat2
	{
		inline simd_mat2() {}
		inline simd_mat2(__m128 data) : abcd(data) {}


		//!
		//!

		__m128 abcd;
	};

	struct simd_mat4
	{
		inline simd_mat4() {}
		inline simd_mat4(simd_vec4 r0, simd_vec4 r1,simd_vec4 r2, simd_vec4 r3)
		{
			this->rows[0] = r0;
			this->rows[1] = r1;
			this->rows[2] = r2;
			this->rows[3] = r3;
		}

		//!
		//!

		simd_vec4 rows[4];
	};

	static inline simd_vec4 load(const vec4<float>&) noexcept;
	static inline simd_mat2 load(const mat2<float>&) noexcept;
	static inline simd_mat4 load(const mat4<float>&) noexcept;

	static inline void store(vec4<float>&, simd_vec4) noexcept;
	static inline void store(mat2<float>&, simd_mat2) noexcept;
	static inline void store(mat4<float>&, simd_mat4) noexcept;

	template<int f3, int f2, int f1, int f0> static inline __m128 shuffle(simd_vec4, simd_vec4) noexcept;
	template<int f3, int f2, int f1, int f0> static inline __m128 shuffle(simd_mat2, simd_mat2) noexcept;

	static inline simd_vec4 mix(simd_vec4, simd_vec4, simd_vec4) noexcept;
	static inline simd_vec4 add(simd_vec4, simd_vec4) noexcept;
	static inline simd_vec4 sub(simd_vec4, simd_vec4) noexcept;
	static inline simd_vec4 mul(simd_vec4, simd_vec4) noexcept;
	static inline simd_vec4 div(simd_vec4, simd_vec4) noexcept;
	static inline simd_vec4 dot(simd_vec4, simd_vec4) noexcept;
	static inline simd_vec4 sum(simd_vec4) noexcept;
	static inline simd_vec4 neg(simd_vec4) noexcept;

	static inline simd_mat2 add(simd_mat2, simd_mat2) noexcept;
	static inline simd_mat2 sub(simd_mat2, simd_mat2) noexcept;
	static inline simd_mat2 mul(simd_mat2, simd_mat2) noexcept;
	static inline simd_mat2 div(simd_mat2, simd_mat2) noexcept;
	static inline simd_mat2 mmm(simd_mat2, simd_mat2) noexcept; //! MAT2 x MAT2

	static inline simd_mat4 add(simd_mat4, simd_mat4) noexcept;
	static inline simd_mat4 sub(simd_mat4, simd_mat4) noexcept;
	static inline simd_mat4 mul(simd_mat4, simd_mat4) noexcept;
	static inline simd_mat4 div(simd_mat4, simd_mat4) noexcept;
	static inline simd_mat4 mmm(simd_mat4, simd_mat4) noexcept; //! MAT4 x MAT4
	static inline simd_vec4 mvm(simd_mat4, simd_vec4) noexcept; //! MAT4 x VEC4

	//!
	//!

	simd_vec4 load(const vec4<float>& v) noexcept { return _mm_loadu_ps(v.head()); }
	simd_mat2 load(const mat2<float>& m) noexcept { return _mm_loadu_ps(m.head()); }
	simd_mat4 load(const mat4<float>& m) noexcept
	{
		const simd_vec4 r0 = load(m.r0());
		const simd_vec4 r1 = load(m.r1());
		const simd_vec4 r2 = load(m.r2());
		const simd_vec4 r3 = load(m.r3());

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	void store(vec4<float>& dst, simd_vec4 src) noexcept { _mm_storeu_ps(dst.head(), src.xyzw); }
	void store(mat2<float>& dst, simd_mat2 src) noexcept { _mm_storeu_ps(dst.head(), src.abcd); }
	void store(mat4<float>& dst, simd_mat4 src) noexcept
	{
		_mm_storeu_ps(dst.head() + 0x00, src.rows[0].xyzw);
		_mm_storeu_ps(dst.head() + 0x10, src.rows[1].xyzw);
		_mm_storeu_ps(dst.head() + 0x20, src.rows[2].xyzw);
		_mm_storeu_ps(dst.head() + 0x30, src.rows[3].xyzw);
	}

	template<int f3, int f2, int f1, int f0> __m128 shuffle(simd_vec4 a, simd_vec4 b) noexcept
	{
		//!
		//!

		return _mm_shuffle_ps(a.xyzw, b.xyzw, _MM_SHUFFLE(f3, f2, f1, f0));
	}

	template<int f3, int f2, int f1, int f0> __m128 shuffle(simd_mat2 a, simd_mat2 b) noexcept
	{
		//!
		//!

		return _mm_shuffle_ps(a.abcd, b.abcd, _MM_SHUFFLE(f3, f2, f1, f0));
	}

	//!
	//! VECTOR4
	//!

	simd_vec4 mix(simd_vec4 a, simd_vec4 b, simd_vec4 c) noexcept
	{
		simd_vec4 v0 = mul(a, c);
		simd_vec4 v1 = mul(b, sub(_mm_set1_ps(1.f), c));

		//!
		//!

		return add(v0, v1);
	}

	simd_vec4 add(simd_vec4 a, simd_vec4 b) noexcept { return _mm_add_ps(a.xyzw, b.xyzw); }
	simd_vec4 sub(simd_vec4 a, simd_vec4 b) noexcept { return _mm_sub_ps(a.xyzw, b.xyzw); }
	simd_vec4 mul(simd_vec4 a, simd_vec4 b) noexcept { return _mm_mul_ps(a.xyzw, b.xyzw); }
	simd_vec4 div(simd_vec4 a, simd_vec4 b) noexcept { return _mm_div_ps(a.xyzw, b.xyzw); }

	simd_vec4 dot(simd_vec4 a, simd_vec4 b) noexcept
	{
		//!
		//!

		return sum(mul(a, b));
	}

	simd_vec4 sum(simd_vec4 v) noexcept
	{
		__m128 v0 = v.xyzw;
		__m128 v1 = _mm_shuffle_ps(v0, v0, _MM_SHUFFLE(2, 2, 0, 0)); //! xxzz
		__m128 v2 = _mm_shuffle_ps(v0, v0, _MM_SHUFFLE(3, 3, 1, 1)); //! yyww
		__m128 v3 = _mm_add_ps(v1, v2);
		__m128 v4 = _mm_shuffle_ps(v3, v3, _MM_SHUFFLE(2, 2, 0, 0)); //! xxzz
		__m128 v5 = _mm_shuffle_ps(v3, v3, _MM_SHUFFLE(3, 3, 1, 1)); //! yyww
		__m128 v5 = _mm_add_ps(v4, v5);

		//!
		//!

		return v5;
	}

	simd_vec4 neg(simd_vec4 v) noexcept
	{
		return sub(_mm_setzero_ps(), v);
	}

	//!
	//! MATRIX2
	//!

	simd_mat2 add(simd_mat2 a, simd_mat2 b) noexcept { return _mm_add_ps(a.abcd, a.abcd); }
	simd_mat2 sub(simd_mat2 a, simd_mat2 b) noexcept { return _mm_sub_ps(a.abcd, a.abcd); }
	simd_mat2 mul(simd_mat2 a, simd_mat2 b) noexcept { return _mm_mul_ps(a.abcd, a.abcd); }
	simd_mat2 div(simd_mat2 a, simd_mat2 b) noexcept { return _mm_div_ps(a.abcd, a.abcd); }

	simd_mat2 mmm(simd_mat2 a, simd_mat2 b) noexcept
	{
		__m128 v0 = _mm_shuffle_ps(a.abcd, a.abcd, _MM_SHUFFLE(2, 2, 0, 0)); //! aacc
		__m128 v1 = _mm_shuffle_ps(a.abcd, a.abcd, _MM_SHUFFLE(3, 3, 1, 1)); //! bbdd
		__m128 v2 = _mm_shuffle_ps(b.abcd, b.abcd, _MM_SHUFFLE(1, 0, 1, 0)); //! efef
		__m128 v3 = _mm_shuffle_ps(b.abcd, b.abcd, _MM_SHUFFLE(3, 2, 3, 2)); //! ghgh
		__m128 v4 = _mm_mul_ps(v0, v2); //! ae af ce cf
		__m128 v5 = _mm_mul_ps(v1, v3); //! bg bh dg dh

		//!
		//!

		return _mm_add_ps(v4, v5);
	}

	//!
	//! MATRIX4
	//!

	simd_mat4 add(simd_mat4 a, simd_mat4 b) noexcept
	{
		simd_vec4 r0 = add(a.rows[0], b.rows[0]);
		simd_vec4 r1 = add(a.rows[1], b.rows[1]);
		simd_vec4 r2 = add(a.rows[2], b.rows[2]);
		simd_vec4 r3 = add(a.rows[3], b.rows[3]);

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	simd_mat4 sub(simd_mat4 a, simd_mat4 b) noexcept
	{
		simd_vec4 r0 = sub(a.rows[0], b.rows[0]);
		simd_vec4 r1 = sub(a.rows[1], b.rows[1]);
		simd_vec4 r2 = sub(a.rows[2], b.rows[2]);
		simd_vec4 r3 = sub(a.rows[3], b.rows[3]);

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	simd_mat4 mul(simd_mat4 a, simd_mat4 b) noexcept
	{
		simd_vec4 r0 = mul(a.rows[0], b.rows[0]);
		simd_vec4 r1 = mul(a.rows[1], b.rows[1]);
		simd_vec4 r2 = mul(a.rows[2], b.rows[2]);
		simd_vec4 r3 = mul(a.rows[3], b.rows[3]);

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	simd_mat4 div(simd_mat4 a, simd_mat4 b) noexcept
	{
		simd_vec4 r0 = div(a.rows[0], b.rows[0]);
		simd_vec4 r1 = div(a.rows[1], b.rows[1]);
		simd_vec4 r2 = div(a.rows[2], b.rows[2]);
		simd_vec4 r3 = div(a.rows[3], b.rows[3]);

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	simd_mat4 mmm(simd_mat4 a, simd_mat4 b) noexcept
	{
		simd_mat2 A = shuffle<1, 0, 1, 0>(a.rows[0], a.rows[1]);
		simd_mat2 B = shuffle<3, 2, 3, 2>(a.rows[0], a.rows[1]);
		simd_mat2 C = shuffle<1, 0, 1, 0>(a.rows[2], a.rows[3]);
		simd_mat2 D = shuffle<3, 2, 3, 2>(a.rows[2], a.rows[3]);
		simd_mat2 E = shuffle<1, 0, 1, 0>(b.rows[0], b.rows[1]);
		simd_mat2 F = shuffle<3, 2, 3, 2>(b.rows[0], b.rows[1]);
		simd_mat2 G = shuffle<1, 0, 1, 0>(b.rows[2], b.rows[3]);
		simd_mat2 H = shuffle<3, 2, 3, 2>(b.rows[2], b.rows[3]);

		simd_mat2 ul = add(mul(A, E), mul(B, G));
		simd_mat2 ur = add(mul(A, F), mul(B, H));
		simd_mat2 ll = add(mul(C, E), mul(D, G));
		simd_mat2 lr = add(mul(C, F), mul(D, H));

		//!
		//! REFORM ROWS
		//!

		simd_vec4 r0 = shuffle<1, 0, 1, 0>(ul, ur);
		simd_vec4 r1 = shuffle<3, 2, 3, 2>(ul, ur);
		simd_vec4 r2 = shuffle<1, 0, 1, 0>(ll, lr);
		simd_vec4 r3 = shuffle<3, 2, 3, 2>(ll, lr);

		//!
		//!

		return { r0, r1, r2, r3 };
	}

	simd_vec4 mvm(simd_mat4 m, simd_vec4 v) noexcept
	{
		simd_vec4 r0 = dot(m.rows[0], v);
		simd_vec4 r1 = dot(m.rows[1], v);
		simd_vec4 r2 = dot(m.rows[2], v);
		simd_vec4 r3 = dot(m.rows[3], v);
		
		simd_vec4 v0 = mix(r0, r1, _mm_set_ps(0, 0, 0, 1));
		simd_vec4 v1 = mix(r2, r3, _mm_set_ps(0, 1, 0, 0));

		//!
		//!

		return shuffle<3, 2, 1, 0>(v0, v1);
	}

} // namespace shape

#endif