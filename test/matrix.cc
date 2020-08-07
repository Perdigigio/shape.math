#include <gtest/gtest.h>

#include "../vector.hh"
#include "../matrix.hh"
#include "../helper.hh"

static inline bool is_zero(float a) { return std::abs(a) < FLT_EPSILON; }

namespace shape
{
	bool operator ==(const vec2<float>& a, const vec2<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const vec3<float>& a, const vec3<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const vec4<float>& a, const vec4<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const mat2<float>& a, const mat2<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const mat3<float>& a, const mat3<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const mat4<float>& a, const mat4<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
}

TEST(mat2, getters)
{
	shape::mat2<float> m =
	{
		1.f, 2.f,
		3.f, 4.f
	};

	ASSERT_EQ(m.r0(), (shape::vec2<float>{ 1.f, 2.f }));
	ASSERT_EQ(m.r1(), (shape::vec2<float>{ 3.f, 4.f }));
	ASSERT_EQ(m.c0(), (shape::vec2<float>{ 1.f, 3.f }));
	ASSERT_EQ(m.c1(), (shape::vec2<float>{ 2.f, 4.f }));
}


TEST(mat3, getters)
{
	shape::mat3<float> m =
	{
		1.f, 2.f, 3.f,
		4.f, 5.f, 6.f,
		7.f, 8.f, 9.f
	};

	ASSERT_EQ(m.r0(), (shape::vec3<float>{ 1.f, 2.f, 3.f }));
	ASSERT_EQ(m.r1(), (shape::vec3<float>{ 4.f, 5.f, 6.f }));
	ASSERT_EQ(m.r2(), (shape::vec3<float>{ 7.f, 8.f, 9.f }));
	ASSERT_EQ(m.c0(), (shape::vec3<float>{ 1.f, 4.f, 7.f }));
	ASSERT_EQ(m.c1(), (shape::vec3<float>{ 2.f, 5.f, 8.f }));
	ASSERT_EQ(m.c2(), (shape::vec3<float>{ 3.f, 6.f, 9.f }));
}

TEST(mat4, getters)
{
	shape::mat4<float> m =
	{
		1.f, 2.f, 3.f, 0.f,
		4.f, 5.f, 6.f, 0.f,
		7.f, 8.f, 9.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	};

	ASSERT_EQ(m.r0(), (shape::vec4<float>{ 1.f, 2.f, 3.f, 0.f }));
	ASSERT_EQ(m.r1(), (shape::vec4<float>{ 4.f, 5.f, 6.f, 0.f }));
	ASSERT_EQ(m.r2(), (shape::vec4<float>{ 7.f, 8.f, 9.f, 0.f }));
	ASSERT_EQ(m.r3(), (shape::vec4<float>{ 0.f, 0.f, 0.f, 1.f }));
	ASSERT_EQ(m.c0(), (shape::vec4<float>{ 1.f, 4.f, 7.f, 0.f }));
	ASSERT_EQ(m.c1(), (shape::vec4<float>{ 2.f, 5.f, 8.f, 0.f }));
	ASSERT_EQ(m.c2(), (shape::vec4<float>{ 3.f, 6.f, 9.f, 0.f }));
	ASSERT_EQ(m.c3(), (shape::vec4<float>{ 0.f, 0.f, 0.f, 1.f }));
}

TEST(mat2, math_ops)
{
	shape::mat2<float> a = { 2.f };
	shape::mat2<float> b = { 1.f };

	ASSERT_EQ(shape::add(a, b), (shape::mat2<float>{ 3.f }));
	ASSERT_EQ(shape::sub(a, b), (shape::mat2<float>{ 1.f }));
	ASSERT_EQ(shape::mul(a, b), (shape::mat2<float>{ 2.f }));
	ASSERT_EQ(shape::mmm(a, b), (shape::mat2<float>{ 2.f }));
}

TEST(mat3, math_ops)
{
	shape::mat3<float> a = { 2.f };
	shape::mat3<float> b = { 1.f };

	ASSERT_EQ(shape::add(a, b), (shape::mat3<float>{ 3.f }));
	ASSERT_EQ(shape::sub(a, b), (shape::mat3<float>{ 1.f }));
	ASSERT_EQ(shape::mul(a, b), (shape::mat3<float>{ 2.f }));
	ASSERT_EQ(shape::mmm(a, b), (shape::mat3<float>{ 2.f }));
}

TEST(mat4, math_ops)
{
	shape::mat4<float> a = { 2.f };
	shape::mat4<float> b = { 1.f };

	ASSERT_EQ(shape::add(a, b), (shape::mat4<float>{ 3.f }));
	ASSERT_EQ(shape::sub(a, b), (shape::mat4<float>{ 1.f }));
	ASSERT_EQ(shape::mul(a, b), (shape::mat4<float>{ 2.f }));
	ASSERT_EQ(shape::mmm(a, b), (shape::mat4<float>{ 2.f }));
}