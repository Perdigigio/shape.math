#ifndef SHAPE_MATH_VECTOR_HH__GUARD
#define SHAPE_MATH_VECTOR_HH__GUARD

namespace shape
{
	template<class T, int N> struct vector
	{
		inline T* head() noexcept { return &data[0]; }
		inline T* tail() noexcept { return &data[N]; }
		inline T const* head() const noexcept { return &data[0]; }
		inline T const* tail() const noexcept { return &data[N]; }

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

		template<class U> inline vec2(const vec2<U>&);

		//!
		//!

		inline T const& x() const noexcept { return this->data[0]; }
		inline T const& y() const noexcept { return this->data[1]; }
		inline T& x() noexcept { return this->data[0]; }
		inline T& y() noexcept { return this->data[1]; }

		template<class U> inline vec2<T>& operator =(const vec2<U>&) noexcept;
	};

	template<class T>
	struct vec3 : vector<T, 3>
	{
		inline vec3();
		inline vec3(const T&, const T&, const T&);
		inline vec3(const T&);

		template<class U> inline vec3(const vec3<U>&);

		//!
		//!

		inline T const& x() const noexcept { return this->data[0]; }
		inline T const& y() const noexcept { return this->data[1]; }
		inline T const& z() const noexcept { return this->data[2]; }
		inline T& x() noexcept { return this->data[0]; }
		inline T& y() noexcept { return this->data[1]; }
		inline T& z() noexcept { return this->data[2]; }

		template<class U> inline vec3<T>& operator =(const vec3<U>&) noexcept;
	};

	template<class T>
	struct vec4 : vector<T, 4>
	{
		vec4();
		vec4(const T&, const T&, const T&, const T&);
		vec4(const T&);

		template<class U> inline vec4(const vec4<U>&);

		//!
		//!

		inline T const& x() const noexcept { return this->data[0]; }
		inline T const& y() const noexcept { return this->data[1]; }
		inline T const& z() const noexcept { return this->data[2]; }
		inline T const& w() const noexcept { return this->data[3]; }
		inline T& x() noexcept { return this->data[0]; }
		inline T& y() noexcept { return this->data[1]; }
		inline T& z() noexcept { return this->data[2]; }
		inline T& w() noexcept { return this->data[3]; }

		template<class U> inline vec4<T>& operator =(const vec4<U>&) noexcept;
	};

	template<class T> struct vec2<T&>
	{
		inline vec2(T& x, T& y) noexcept : _x(x), _y(y) {}

		inline T const& x() const noexcept { return _x; }
		inline T const& y() const noexcept { return _y; }
		inline T& x() noexcept { return _x; }
		inline T& y() noexcept { return _y; }

		inline vec2<T&>& operator +=(const vec2<T>&) noexcept;
		inline vec2<T&>& operator -=(const vec2<T>&) noexcept;
		inline vec2<T&>& operator *=(const vec2<T>&) noexcept;
		inline vec2<T&>& operator /=(const vec2<T>&) noexcept;

		inline vec2<T&>& operator =(const vec2<T>&) noexcept;
	private:
		T& _x;
		T& _y;
	};

	template<class T> struct vec3<T&>
	{
		inline vec3(T& x, T& y, T& z) noexcept : _x(x), _y(y), _z(z) {}

		inline T const& x() const noexcept { return _x; }
		inline T const& y() const noexcept { return _y; }
		inline T const& z() const noexcept { return _z; }
		inline T& x() noexcept { return _x; }
		inline T& y() noexcept { return _y; }
		inline T& z() noexcept { return _z; }

		inline vec3<T&>& operator +=(const vec3<T>&) noexcept;
		inline vec3<T&>& operator -=(const vec3<T>&) noexcept;
		inline vec3<T&>& operator *=(const vec3<T>&) noexcept;
		inline vec3<T&>& operator /=(const vec3<T>&) noexcept;

		inline vec3<T&>& operator =(const vec3<T>&) noexcept;
	private:
		T& _x;
		T& _y;
		T& _z;
	};

	template<class T> struct vec4<T&>
	{
		inline vec4(T& x, T& y, T& z, T& w) noexcept : _x(x), _y(y), _z(z), _w(w) {}

		inline T const& x() const noexcept { return _x; }
		inline T const& y() const noexcept { return _y; }
		inline T const& z() const noexcept { return _z; }
		inline T const& w() const noexcept { return _w; }
		inline T& x() noexcept { return _x; }
		inline T& y() noexcept { return _y; }
		inline T& z() noexcept { return _z; }
		inline T& w() noexcept { return _w; }

		inline vec4<T&>& operator +=(const vec4<T>&) noexcept;
		inline vec4<T&>& operator -=(const vec4<T>&) noexcept;
		inline vec4<T&>& operator *=(const vec4<T>&) noexcept;
		inline vec4<T&>& operator /=(const vec4<T>&) noexcept;

		inline vec4<T&>& operator =(const vec4<T>&) noexcept;

	private:
		T& _x;
		T& _y;
		T& _z;
		T& _w;
	};

	//!
	//! MATH OPERATORS
	//!

	template<class T> inline T sum(vec2<T>);
	template<class T> inline T sum(vec3<T>);
	template<class T> inline T sum(vec4<T>);
	template<class T> inline T dot(vec2<T> a, vec2<T> b) { return sum(a * b); }
	template<class T> inline T dot(vec3<T> a, vec3<T> b) { return sum(a * b); }
	template<class T> inline T dot(vec4<T> a, vec4<T> b) { return sum(a * b); }

	template<class T> inline vec2<T> add(const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline vec2<T> sub(const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline vec2<T> mul(const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline vec2<T> div(const vec2<T>&, const vec2<T>&) noexcept;
	template<class T> inline vec3<T> add(const vec3<T>&, const vec3<T>&) noexcept;
	template<class T> inline vec3<T> sub(const vec3<T>&, const vec3<T>&) noexcept;
	template<class T> inline vec3<T> mul(const vec3<T>&, const vec3<T>&) noexcept;
	template<class T> inline vec3<T> div(const vec3<T>&, const vec3<T>&) noexcept;	
	template<class T> inline vec4<T> add(const vec4<T>&, const vec4<T>&) noexcept;
	template<class T> inline vec4<T> sub(const vec4<T>&, const vec4<T>&) noexcept;
	template<class T> inline vec4<T> mul(const vec4<T>&, const vec4<T>&) noexcept;
	template<class T> inline vec4<T> div(const vec4<T>&, const vec4<T>&) noexcept;

	template<class T> inline void set(vec2<T>&, const T&) noexcept;
	template<class T> inline void set(vec3<T>&, const T&) noexcept;
	template<class T> inline void set(vec4<T>&, const T&) noexcept;

	template<class T, class U> inline vec2<T> vector_cast(const vec2<U>&) noexcept;
	template<class T, class U> inline vec3<T> vector_cast(const vec3<U>&) noexcept;
	template<class T, class U> inline vec4<T> vector_cast(const vec4<U>&) noexcept;

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

	template<class T>
	template<class U> vec2<T>::vec2(const vec2<U>& o)
	{
		this->x() = o.x();
		this->y() = o.y();
	}

	template<class T>
	template<class U> vec2<T>& vec2<T>::operator =(const vec2<U>& o) noexcept
	{
		this->x() = o.x();
		this->y() = o.y(); return *this;
	}

	template<class T> vec2<T&>& vec2<T&>::operator +=(const vec2<T>& v) noexcept
	{
		this->x() = this->x() + v.x();
		this->y() = this->y() + v.y(); return *this;
	}

	template<class T> vec2<T&>& vec2<T&>::operator -=(const vec2<T>& v) noexcept
	{
		this->x() = this->x() - v.x();
		this->y() = this->y() - v.y(); return *this;
	}

	template<class T> vec2<T&>& vec2<T&>::operator *=(const vec2<T>& v) noexcept
	{
		this->x() = this->x() * v.x();
		this->y() = this->y() * v.y(); return *this;
	}

	template<class T> vec2<T&>& vec2<T&>::operator /=(const vec2<T>& v) noexcept
	{
		this->x() = this->x() / v.x();
		this->y() = this->y() / v.y(); return *this;
	}

	template<class T> vec2<T&>& vec2<T&>::operator =(const vec2<T>& o) noexcept
	{
		_x = o.x();
		_y = o.y(); return *this;
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

	template<class T>
	template<class U> vec3<T>::vec3(const vec3<U>& o)
	{
		this->x() = o.x();
		this->y() = o.y();
		this->z() = o.z();
	}

	template<class T>
	template<class U> vec3<T>& vec3<T>::operator =(const vec3<U>& o) noexcept
	{
		this->x() = o.x();
		this->y() = o.y();
		this->z() = o.z(); return *this;
	}

	template<class T> vec3<T&>& vec3<T&>::operator +=(const vec3<T>& v) noexcept
	{
		this->x() = this->x() + v.x();
		this->y() = this->y() + v.y();
		this->z() = this->z() + v.z(); return *this;
	}

	template<class T> vec3<T&>& vec3<T&>::operator -=(const vec3<T>& v) noexcept
	{
		this->x() = this->x() - v.x();
		this->y() = this->y() - v.y();
		this->z() = this->z() - v.z(); return *this;
	}

	template<class T> vec3<T&>& vec3<T&>::operator *=(const vec3<T>& v) noexcept
	{
		this->x() = this->x() * v.x();
		this->y() = this->y() * v.y();
		this->x() = this->z() * v.z(); return *this;
	}

	template<class T> vec3<T&>& vec3<T&>::operator /=(const vec3<T>& v) noexcept
	{
		this->x() = this->x() / v.x();
		this->y() = this->y() / v.y();
		this->z() = this->z() / v.z(); return *this;
	}

	template<class T> vec3<T&>& vec3<T&>::operator =(const vec3<T>& o) noexcept
	{
		_x = o.x();
		_y = o.y();
		_z = o.z(); return *this;
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

	template<class T>
	template<class U> vec4<T>::vec4(const vec4<U>& o)
	{
		this->x() = o.x();
		this->y() = o.y();
		this->z() = o.z();
		this->w() = o.w();
	}

	template<class T>
	template<class U> vec4<T>& vec4<T>::operator =(const vec4<U>& o) noexcept
	{
		this->x() = o.x();
		this->y() = o.y();
		this->z() = o.z();
		this->w() = o.w(); return *this;
	}

	template<class T> vec4<T&>& vec4<T&>::operator +=(const vec4<T>& v) noexcept
	{
		this->x() = this->x() + v.x();
		this->y() = this->y() + v.y();
		this->z() = this->z() + v.z();
		this->w() = this->w() + v.w(); return *this;
	}

	template<class T> vec4<T&>& vec4<T&>::operator -=(const vec4<T>& v) noexcept
	{
		this->x() = this->x() - v.x();
		this->y() = this->y() - v.y();
		this->z() = this->z() - v.z();
		this->w() = this->w() - v.w(); return *this;
	}

	template<class T> vec4<T&>& vec4<T&>::operator *=(const vec4<T>& v) noexcept
	{
		this->x() = this->x() * v.x();
		this->y() = this->y() * v.y();
		this->x() = this->z() * v.z();
		this->w() = this->w() * v.w(); return *this;
	}

	template<class T> vec4<T&>& vec4<T&>::operator /=(const vec4<T>& v) noexcept
	{
		this->x() = this->x() / v.x();
		this->y() = this->y() / v.y();
		this->z() = this->z() / v.z();
		this->w() = this->w() / v.w(); return *this;
	}

	template<class T> vec4<T&>& vec4<T&>::operator =(const vec4<T>& o) noexcept
	{
		_x = o.x();
		_y = o.y();
		_z = o.z();
		_w = o.w(); return *this;
	}

	//!
	//! IMPLEMENTATION
	//!

	template<class T, class U> vec2<T> vector_cast(const vec2<U>& v) noexcept { return vec2<T>{ v }; }
	template<class T, class U> vec3<T> vector_cast(const vec3<U>& v) noexcept { return vec3<T>{ v }; }
	template<class T, class U> vec4<T> vector_cast(const vec4<U>& v) noexcept { return vec4<T>{ v }; }

	template<class T> T sum(vec2<T> v) { return v.x() + v.y(); }
	template<class T> T sum(vec3<T> v) { return v.x() + v.y() + v.z(); }
	template<class T> T sum(vec4<T> v) { return v.x() + v.y() + v.z() + v.w(); }

	template<class T> vec2<T> add(const vec2<T>& a, const vec2<T>& b) noexcept
	{
		T x = a.x() + b.x();
		T y = a.y() + b.y();

		//!
		//!

		return { x, y };
	}

	template<class T> vec2<T> sub(const vec2<T>& a, const vec2<T>& b) noexcept
	{
		T x = a.x() - b.x();
		T y = a.y() - b.y();

		//!
		//!

		return { x, y };
	}

	template<class T> vec2<T> mul(const vec2<T>& a, const vec2<T>& b) noexcept
	{
		T x = a.x() * b.x();
		T y = a.y() * b.y();

		//!
		//!

		return { x, y };
	}

	template<class T> vec2<T> div(const vec2<T>& a, const vec2<T>& b) noexcept
	{
		T x = a.x() / b.x();
		T y = a.y() / b.y();

		//!
		//!

		return { x, y };
	}

	template<class T> vec3<T> add(const vec3<T>& a, const vec3<T>& b) noexcept
	{
		T x = a.x() + b.x();
		T y = a.y() + b.y();
		T z = a.z() + b.z();

		//!
		//!

		return { x, y, z };
	}

	template<class T> vec3<T> sub(const vec3<T>& a, const vec3<T>& b) noexcept
	{
		T x = a.x() - b.x();
		T y = a.y() - b.y();
		T z = a.z() - b.z();

		//!
		//!

		return { x, y, z };
	}

	template<class T> vec3<T> mul(const vec3<T>& a, const vec3<T>& b) noexcept
	{
		T x = a.x() * b.x();
		T y = a.y() * b.y();
		T z = a.z() * b.z();

		//!
		//!

		return { x, y, z };
	}

	template<class T> vec3<T> div(const vec3<T>& a, const vec3<T>& b) noexcept
	{
		T x = a.x() / b.x();
		T y = a.y() / b.y();
		T z = a.z() / b.z();

		//!
		//!

		return { x, y, z };
	}

	template<class T> vec4<T> add(const vec4<T>& a, const vec4<T>& b) noexcept
	{
		T x = a.x() + b.x();
		T y = a.y() + b.y();
		T z = a.z() + b.z();
		T w = a.w() + b.w();

		//!
		//!

		return { x, y, z, w };
	}

	template<class T> vec4<T> sub(const vec4<T>& a, const vec4<T>& b) noexcept
	{
		T x = a.x() - b.x();
		T y = a.y() - b.y();
		T z = a.z() - b.z();
		T w = a.w() - b.w();

		//!
		//!

		return { x, y, z, w };
	}

	template<class T> vec4<T> mul(const vec4<T>& a, const vec4<T>& b) noexcept
	{
		T x = a.x() * b.x();
		T y = a.y() * b.y();
		T z = a.z() * b.z();
		T w = a.w() * b.w();

		//!
		//!

		return { x, y, z, w };
	}

	template<class T> vec4<T> div(const vec4<T>& a, const vec4<T>& b) noexcept
	{
		T x = a.x() / b.x();
		T y = a.y() / b.y();
		T z = a.z() / b.z();
		T w = a.w() / b.w();

		//!
		//!

		return { x, y, z, w };
	}

	template<class T> void set(vec2<T>& v, const T& s) noexcept { v = vec2<T>(s); }
	template<class T> void set(vec3<T>& v, const T& s) noexcept { v = vec3<T>(s); }
	template<class T> void set(vec4<T>& v, const T& s) noexcept { v = vec4<T>(s); }
}

#endif