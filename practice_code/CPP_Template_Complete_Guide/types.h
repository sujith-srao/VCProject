#pragma once
template <typename T> 
class IFTHENELSE {
public:
	enum { result = 0 };
};


#define MK_ISFUNDA(X) \
template<> \
class IFTHENELSE<X> { \
public: \
	enum { result = 1 }; \
};

template<typename T>
class IFTHENELSE<T*> {
public:
	enum {result =0};
};

template<typename T>
class IsFunda {
public:
	enum { Yes = IFTHENELSE<T>::result };
	enum { No = !Yes };
};
template <int N1,int N2>
class MyMult {
public:
	typedef enum {
		result=N1*N2
	};
};


MK_ISFUNDA(bool)
MK_ISFUNDA(int)
MK_ISFUNDA(wchar_t)


