#include <gtest/gtest.h>

#include "../vector.hh"
#include "../helper.hh"

static inline bool is_zero(float a) { return std::abs(a) < FLT_EPSILON; }

namespace shape
{
	bool operator ==(const vec2<float>& a, const vec2<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const vec3<float>& a, const vec3<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
	bool operator ==(const vec4<float>& a, const vec4<float>& b) { return shape::all(shape::sub(a, b), is_zero); }
}

TEST(vec2, vector_ops)
{
	shape::vec2<float> a = { 2.f, 3.f };
	shape::vec2<float> b = { 1.f, 1.f };

	ASSERT_EQ(shape::add(a, b), (shape::vec2<float>{ 3.f, 4.f }));
	ASSERT_EQ(shape::sub(a, b), (shape::vec2<float>{ 1.f, 2.f }));
	ASSERT_EQ(shape::mul(a, b), (shape::vec2<float>{ 2.f, 3.f }));
	ASSERT_EQ(shape::div(a, b), (shape::vec2<float>{ 2.f, 3.f }));
	ASSERT_EQ(a + b, (shape::vec2<float>{ 3.f, 4.f }));
	ASSERT_EQ(a - b, (shape::vec2<float>{ 1.f, 2.f }));
	ASSERT_EQ(a * b, (shape::vec2<float>{ 2.f, 3.f }));
	ASSERT_EQ(a / b, (shape::vec2<float>{ 2.f, 3.f }));
}

TEST(vec3, vector_ops)
{
	shape::vec3<float> a = { 2.f, 3.f, 4.f };
	shape::vec3<float> b = { 1.f, 1.f, 1.f };

	ASSERT_EQ(shape::add(a, b), (shape::vec3<float>{ 3.f, 4.f, 5.f }));
	ASSERT_EQ(shape::sub(a, b), (shape::vec3<float>{ 1.f, 2.f, 3.f }));
	ASSERT_EQ(shape::mul(a, b), (shape::vec3<float>{ 2.f, 3.f, 4.f }));
	ASSERT_EQ(shape::div(a, b), (shape::vec3<float>{ 2.f, 3.f, 4.f }));
	ASSERT_EQ(a + b, (shape::vec3<float>{ 3.f, 4.f, 5.f }));
	ASSERT_EQ(a - b, (shape::vec3<float>{ 1.f, 2.f, 3.f }));
	ASSERT_EQ(a * b, (shape::vec3<float>{ 2.f, 3.f, 4.f }));
	ASSERT_EQ(a / b, (shape::vec3<float>{ 2.f, 3.f, 4.f }));
}

TEST(vec4, vector_ops)
{
	shape::vec4<float> a = { 2.f, 3.f, 4.f, 5.f };
	shape::vec4<float> b = { 1.f, 1.f, 1.f, 1.f };

	ASSERT_EQ(shape::add(a, b), (shape::vec4<float>{ 3.f, 4.f, 5.f, 6.f }));
	ASSERT_EQ(shape::sub(a, b), (shape::vec4<float>{ 1.f, 2.f, 3.f, 4.f }));
	ASSERT_EQ(shape::mul(a, b), (shape::vec4<float>{ 2.f, 3.f, 4.f, 5.f }));
	ASSERT_EQ(shape::div(a, b), (shape::vec4<float>{ 2.f, 3.f, 4.f, 5.f }));
	ASSERT_EQ(a + b, (shape::vec4<float>{ 3.f, 4.f, 5.f, 6.f }));
	ASSERT_EQ(a - b, (shape::vec4<float>{ 1.f, 2.f, 3.f, 4.f }));
	ASSERT_EQ(a * b, (shape::vec4<float>{ 2.f, 3.f, 4.f, 5.f }));
	ASSERT_EQ(a / b, (shape::vec4<float>{ 2.f, 3.f, 4.f, 5.f }));
}

TEST(vec2, scalar_ops)
{
	shape::vec2<float> a = { 2.f, 3.f };
	shape::vec2<float> b = { 1.f, 1.f };

	ASSERT_TRUE(is_zero(shape::dot(a, b) - 5.f));
	ASSERT_TRUE(is_zero(shape::dot(b, a) - 5.f));
	ASSERT_TRUE(is_zero(shape::sum(a) - 5.f));
	ASSERT_TRUE(is_zero(shape::sum(b) - 2.f));
}

TEST(vec3, scalar_ops)
{
	shape::vec3<float> a = { 2.f, 3.f, 4.f };
	shape::vec3<float> b = { 1.f, 1.f, 1.f };

	ASSERT_TRUE(is_zero(shape::dot(a, b) - 9.f));
	ASSERT_TRUE(is_zero(shape::dot(b, a) - 9.f));
	ASSERT_TRUE(is_zero(shape::sum(a) - 9.f));
	ASSERT_TRUE(is_zero(shape::sum(b) - 3.f));
}

TEST(vec4, scalar_ops)
{
	shape::vec4<float> a = { 2.f, 3.f, 4.f, 5.f };
	shape::vec4<float> b = { 1.f, 1.f, 1.f, 1.f };

	ASSERT_TRUE(is_zero(shape::dot(a, b) - 14.f));
	ASSERT_TRUE(is_zero(shape::dot(b, a) - 14.f));
	ASSERT_TRUE(is_zero(shape::sum(a) - 14.f));
	ASSERT_TRUE(is_zero(shape::sum(b) -  4.f));
}