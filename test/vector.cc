#ifndef CATCH_CONFIG_MAIN
#	define CATCH_CONFIG_MAIN
#endif

#include "catch2.hh"

#include <math/vector.hh>
#include <math/matrix.hh>
#include <math/helper.hh>

static inline bool almost(float a) { return std::abs(a) < FLT_EPSILON; }

namespace shape
{
	bool operator ==(const vec2<float>& a, const vec2<float>& b) { return shape::all(shape::sub(a, b), almost); }
	bool operator ==(const vec3<float>& a, const vec3<float>& b) { return shape::all(shape::sub(a, b), almost); }
	bool operator ==(const vec4<float>& a, const vec4<float>& b) { return shape::all(shape::sub(a, b), almost); }
	bool operator ==(const mat2<float>& a, const mat2<float>& b) { return shape::all(shape::sub(a, b), almost); }
	bool operator ==(const mat3<float>& a, const mat3<float>& b) { return shape::all(shape::sub(a, b), almost); }
	bool operator ==(const mat4<float>& a, const mat4<float>& b) { return shape::all(shape::sub(a, b), almost); }
}

TEST_CASE("Matrix simple decomposition", "[operations]")
{
	SECTION("mat2")
	{
		shape::mat2<float> m =
		{
			1.f, 2.f,
			3.f, 4.f
		};

		REQUIRE(m.r0() == shape::vec2<float>{ 1.f, 2.f });
		REQUIRE(m.r1() == shape::vec2<float>{ 3.f, 4.f });
		REQUIRE(m.c0() == shape::vec2<float>{ 1.f, 3.f });
		REQUIRE(m.c1() == shape::vec2<float>{ 2.f, 4.f });
	}

	SECTION("mat3")
	{
		shape::mat3<float> m =
		{
			1.f, 2.f, 3.f,
			4.f, 5.f, 6.f,
			7.f, 8.f, 9.f
		};

		REQUIRE(m.r0() == shape::vec3<float>{ 1.f, 2.f, 3.f });
		REQUIRE(m.r1() == shape::vec3<float>{ 4.f, 5.f, 6.f });
		REQUIRE(m.r2() == shape::vec3<float>{ 7.f, 8.f, 9.f });
		REQUIRE(m.c0() == shape::vec3<float>{ 1.f, 4.f, 7.f });
		REQUIRE(m.c1() == shape::vec3<float>{ 2.f, 5.f, 8.f });
		REQUIRE(m.c2() == shape::vec3<float>{ 3.f, 6.f, 9.f });
	}

	SECTION("mat4")
	{
		shape::mat4<float> m =
		{
			1.f, 2.f, 3.f, 0.f,
			4.f, 5.f, 6.f, 0.f,
			7.f, 8.f, 9.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		};

		REQUIRE(m.r0() == shape::vec4<float>{ 1.f, 2.f, 3.f, 0.f });
		REQUIRE(m.r1() == shape::vec4<float>{ 4.f, 5.f, 6.f, 0.f });
		REQUIRE(m.r2() == shape::vec4<float>{ 7.f, 8.f, 9.f, 0.f });
		REQUIRE(m.r3() == shape::vec4<float>{ 0.f, 0.f, 0.f, 1.f });
		REQUIRE(m.c0() == shape::vec4<float>{ 1.f, 4.f, 7.f, 0.f });
		REQUIRE(m.c1() == shape::vec4<float>{ 2.f, 5.f, 8.f, 0.f });
		REQUIRE(m.c2() == shape::vec4<float>{ 3.f, 6.f, 9.f, 0.f });
		REQUIRE(m.c3() == shape::vec4<float>{ 0.f, 0.f, 0.f, 1.f });
	}
}

TEST_CASE("Matrix simple math operations on diagonal matrix", "[operations]")
{
	SECTION("mat2")
	{
		shape::mat2<float> a = { 2.f };
		shape::mat2<float> b = { 1.f };

		REQUIRE(shape::add(a, b) == shape::mat2<float>{ 3.f });
		REQUIRE(shape::sub(a, b) == shape::mat2<float>{ 1.f });
		REQUIRE(shape::mul(a, b) == shape::mat2<float>{ 2.f });
		REQUIRE(shape::mmm(a, b) == shape::mat2<float>{ 2.f });
	}

	SECTION("mat3")
	{
		shape::mat3<float> a = { 2.f };
		shape::mat3<float> b = { 1.f };

		REQUIRE(shape::add(a, b) == shape::mat3<float>{ 3.f });
		REQUIRE(shape::sub(a, b) == shape::mat3<float>{ 1.f });
		REQUIRE(shape::mul(a, b) == shape::mat3<float>{ 2.f });
		REQUIRE(shape::mmm(a, b) == shape::mat3<float>{ 2.f });
	}

	SECTION("mat4")
	{
		shape::mat4<float> a = { 2.f };
		shape::mat4<float> b = { 1.f };

		REQUIRE(shape::add(a, b) == shape::mat4<float>{ 3.f });
		REQUIRE(shape::sub(a, b) == shape::mat4<float>{ 1.f });
		REQUIRE(shape::mul(a, b) == shape::mat4<float>{ 2.f });
		REQUIRE(shape::mmm(a, b) == shape::mat4<float>{ 2.f });
	}
}