#pragma once

template <typename T1,typename T2>
class Duos {
	T1 a_;
	T2 b_;
	
public:
	enum { N = 2 };
	typedef T2 ResultT;


	/*nth type of Duos is n-1th Duos 2nd type*/
	//template<int N,typename T1,typename T2>
	//typedef Duos<T1,

	inline Duos() : a_(T1()), b_(T2()) {
	};

	inline Duos(T1 const& a, T2 const& b) : a_(a), b_(b) {
	};

	inline Duos(Duos<T1,T2> const& rhs) : a_(rhs.a_), b_(rhs.b_) {
	};

	inline Duos<T1, T2>& operator=(Duos<T1, T2> const& rhs) {
		a_ = rhs.a_;
		b_ = rhs.b_;
	};
	
	template<typename U1,typename U2>
	inline Duos<T1, T2>& operator=(Duos<U1, U2> const& rhs) {
		a_ = rhs.a_;
		b_ = rhs.b_;
	};

	
	/*return the type of nth elem of Duos */
	inline T1& val1() {
		return a_;
	};
	inline T1 const& val1() const {
		return a_;
	};

	inline T2& val2() {
		return b_;
	};

	inline T2 const& val2() const {
		return b_;
	};
};

template <int N,typename T>
class DuoT {
public:
	typedef void ResultT;
};

template <typename T1, typename T2>
class DuoT<1,Duos<T1,T2>> {
public:
	typedef T1 ResultT;
};

template <typename T1, typename T2>
class DuoT<2, Duos<T1, T2>> {
public:
	typedef T2 ResultT;
};

template <int N, typename T1, typename T2, typename T3>
class DuoT<N, Duos<T1, Duos<T2,T3>>> {
public:
	typedef typename DuoT<N-1,Duos<T2,T3>>::ResulT ResultT;
};

template<int N,typename T1,typename T2,typename T3>
inline typename DuoT<N, Duos<T1, Duos<T2, T3>>>::ResultT val() {

}


template <typename T1, typename T2, typename T3>
class DuoT<1, Duos<T1, Duos<T2, T3>>> {
public:
	typedef typename T1 ResultT;
};

template <typename T1, typename T2, typename T3>
class DuoT<2, Duos<T1, Duos<T2, T3>>> {
public:
	typedef typename T2 ResultT;
};

template<typename T1, typename T2>
inline Duos<T1, T2> make_duo(T1 const& a, T2 const& b) {
	return Duos<T1,T2>(a, b);
}

template<typename T1,typename T2>
inline bool operator==(Duos<T1, T2> const& lhs, Duos<T1, T2> const& rhs) {
	return lhs.val1() == rhs.val1() && lhs.val2() == rhs.val2();
}

template<typename T1, typename T2,
		 typename U1, typename U2>
inline bool operator==(Duos<T1, T2> const& lhs, Duos<U1, U2> const& rhs) {
	return lhs.val1() == rhs.val1() && lhs.val2() == rhs.val2();
}

template<typename T1, typename T2>
inline bool operator!=(Duos<T1, T2> const& lhs, Duos<T1, T2> const& rhs) {
	return lhs.val1() != rhs.val1() && lhs.val2() != rhs.val2();
}

template<typename T1, typename T2,
	typename U1, typename U2>
inline bool operator!=(Duos<T1, T2> const& lhs, Duos<U1, U2> const& rhs) {
	return lhs.val1() != rhs.val1() && lhs.val2() != rhs.val2();
}

template<int N, typename T>
class DuoVal;

template< typename A, typename B>
class DuoVal<1, Duos<A, B>> {
public:
	static A get(Duos<A, B>& d) {
		return d.val1();
	};
};

template< typename A, typename B>
class DuoVal<2, Duos<A, B>> {
public:
	static B get(Duos<A, B>& d) {
		return d.val2();
	};
};

//template< int N,typename A, typename B>
//class DuoVal< Duos<A, B>> {
//public:
//	static B get(Duos<A, B>& d) {
//		return d.val2();
//	};
//};



template<int N,typename T1,typename T2>
inline typename DuoT<N, Duos<T1, T2>>::ResultT val(Duos<T1, T2>& d) {
	return DuoVal<N, T1, T2>::get(d);
}

