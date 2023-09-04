#pragma once
template<typename bool, typename T1, typename T2>
class IFTHENELSE;

template<typename T1, typename T2>
class IFTHENELSE<true, T1, T2> {
public:
    typedef T1 Type;
};

template<typename T1, typename T2>
class IFTHENELSE<false, T1, T2> {
public:
    typedef T2 Type;
};

template<typename T>
class RParamTrait {
public:
    typedef typename IFTHENELSE <(sizeof(T) >= 2 * sizeof(void*)), T const&, T>::Type RType;
};