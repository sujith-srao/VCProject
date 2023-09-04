#pragma once
template <typename T>
class CompoundType {
public:
	enum {
		IsArrT=0,IsRefT=0,IsPtrT=0,
		IsMemType=0
	};
	typedef T BaseT;
	typedef T BottomT;
	typedef CompoundT<void> ClassT;
};
template<typename T>
class CompoundType<T&> {
public:
	enum {
		IsArrT = 0, IsRefT = 1, IsPtrT = 0,
		IsMemType = 0
	};
	typedef T BaseT;
	typedef typename CompoundType<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};
template<typename T>
class CompoundType<T*> {
public:
	enum {
		IsArrT = 0, IsRefT = 0, IsPtrT = 1,
		IsMemType = 0
	};
	typedef T BaseT;
	typedef typename CompoundType<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};
template<typename T,typename int N>
class CompoundType<T[N]> {
public:
	enum {
		IsArrT = 1, IsRefT = 0, IsPtrT = 1,
		IsMemType = 0
	};
	typedef T BaseT;
	typedef typename CompoundType<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};
template <typename T>
class YES_NO {
public:
	typedef char One;
	typedef struct { char a[2] } Two;

	template<typename U> static One test<U>(...);
	template<typename U> static Two test<U>(U (*)[1]);

	enum {Yes=sizeof(YES_NO::test<T>(0))==1 };
	enum {No=!Yes};
};
