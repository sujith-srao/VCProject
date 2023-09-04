#pragma once
#include<tuple>

/*“write a struct ‘Reverse’ which can reverse the template arguments of any std::tuple so that

static_assert(
std::is_same_v<typename Reverse<std::tuple<int, bool, double>>::Type, std::tuple<double, bool, int>>);
is satisfied”*/

template<typename bool,typename T1,typename T2>
class IF_THEN_ELSE;

template<typename T1, typename T2>
class IF_THEN_ELSE<true, T1, T2> {
public:
	typedef T1 BaseT;
};

template<typename T1, typename T2>
class IF_THEN_ELSE<false, T1, T2> {
public:
	typedef T2 BaseT;
};

//template<typename T>
//class Rev_checker {
//public:
//	typedef  T BaseT;
//};


template<typename T>
class RecType {
public:

};

//template<typename T>
//class Rev_Base {
//public:
//	typedef typename T::_This_type FirstT;
//	typedef typename T::_Rest SecondT;
//};

