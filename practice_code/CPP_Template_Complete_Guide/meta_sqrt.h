#pragma once
template<typename int N,typename int LO, typename int HI>
class SQRT;

template<typename int N,typename int LO=1,typename int HI=N>
class SQRT {
public:
	enum {mid=(LO+HI+1)/2};
	enum {result = N<(mid*mid)? SQRT<N,LO,mid>::result:SQRT<N,mid+1,HI>::result  };
};

template<typename int N,int M>
class SQRT<N, M, M> {
public:
	enum {result=M};
};

template<typename int N,typename int LO=1, typename int HI=N>
class SQRT_IMPRVD {

};

