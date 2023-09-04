#pragma once
template<typename int N>
class Power_Of_3;


template<typename int N>
class Power_Of_3 {
public:
	enum {
		result = 3 * Power_Of_3<N - 1>::result
	};
};

template<>
class Power_Of_3<0> {
public:
	enum {
		result = 1
	};
};
template<typename int B, int N>
class B_raised_N;

template<typename int B,typename int N>
class B_raised_N {
public:
	enum {
		result = B* B_raised_N<B,N-1>::result
	};
};

template<typename int N>
class B_raised_N<1, N> {
public:
	enum {
		result = 1
	};
};

template<typename int B>
class B_raised_N<B, 0> {
public:
	enum {
		result = 1
	};
};
template <typename int N>
class FACT {
public:
	enum { result = N * FACT<N - 1>::result };
};

template<>
class FACT<2> {
public:
	enum { result = 2 };
};
