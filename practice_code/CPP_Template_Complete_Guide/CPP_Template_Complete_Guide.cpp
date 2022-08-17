// CPP_Template_Complete_Guide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<deque>
#include<stack>
#include<algorithm>
#include<list>
#include<array>
using namespace std;
template <typename T,typename CONT>
void fillCont(CONT &cont, T const& val) {
    typename CONT::iterator pos(cont.begin());
    typename CONT::iterator end(cont.end());
    while (pos != end) {
        *pos = val;
        pos++;
    }
}
template <typename CONT>
typename CONT::value_type my_median(CONT &cont) {
    typename CONT::iterator it(cont.begin());
    typename CONT::iterator itEnd(cont.end());
    sort(it, itEnd);
    int n = cont.size();
    typename CONT::value_type const& val = cont.at(n / 2);
    return val;
}

enum MyEnum {
    one=1,
    two=2
};
template <typename T, MyEnum e=one>
class MyArray {
public:
    
    MyArray<T,e> operator=(MyArray<T,e>& rhs) {

    };

    template <typename MyEnum e1>
    MyArray<T, e> operator=(MyArray<T, e1>& rhs) {
        return *this;
    };
    template <typename T2,typename MyEnum me>
    MyArray<T, e> operator=(MyArray<T2, me>& rhs) {
        return *this;
    };
};
template<typename T,typename CONT=std::vector<T>>
class MyStack {
    
public:
    CONT cont;
    template<typename T2,typename CONT2>
    MyStack<T, CONT> operator=(MyStack<T2, CONT2> const& rhs) {
        typename CONT2::const_iterator it(rhs.cont.begin());
        typename CONT2::const_iterator itEnd(rhs.cont.end());
        typename CONT::iterator itLeft(cont.begin());

        for (; it != itEnd; it++) {
            *itLeft = *it;
            itLeft++;
        }
        return *this;
    };
    void push(T const& val) {
        cont.push_back(val);
    }

    template<typename T2>
    void push(T2 const& val) {
        T& tt = static_cast<T&>(val);
        cont.push_back(tt);
    }
};
template <typename T>
void Init(T* ptr) {
    *ptr = T();
}
class MyClass {
    int x;
public:
    MyClass() :x(0) {};
};
/*Function which reverses any given containers*/
template <typename CONT>
void reverseContainer(CONT& cont) {
    typename CONT::iterator itSrc(cont.begin());
    typename CONT::iterator itDest(cont.end()-1);
    while (itDest > itSrc) {
        typename CONT::iterator temp = itSrc;
        *itSrc = *itDest;
        //*itDest = 

    }
}
class Base{

};
class Dervied1 :public Base {
};
class Dervied2:public Base {
};

template <typename dstT,typename srcT>
dstT my_cast(srcT& src) {
    return src;
}

//template <typename T>
//void printColl_v(std::vector<T>& vi) {
//    cout << "printColl for vector" << endl;
//}

namespace CPP_8_3_1_2 {
    typedef char RT1 ;
    template<typename T> RT1 test(typename T::X tx) {
        return NULL;
    }

    template<typename X>
    class MyClass {
        X x;
        int*p=0;
    };

    void driver() {
        int a;
        list<int> ad;
        list<list<int>> lst;
        //test(a);
        MyClass<int> mc;
        //test(mc);
    }
}
namespace CH_15_1 {
    class My {

    };
    template<typename T>
    class AccumulationTrait;

    template<>
    class AccumulationTrait<char> {
    public:
        typedef int AccumTrait;
        static AccumTrait zero;
    };

    template<>
    class AccumulationTrait<float> {
    public:
        typedef float AccumTrait;
    };

    template<>
    class AccumulationTrait<double> {
    public:
        typedef double AccumTrait;
    };
    template<>
    class AccumulationTrait<int> {
    public:
        typedef int AccumTrait;
    };

    template<typename T>
    class SumPolicy;
    template<typename T>
    class SumPolicy {
    public:
        static void accumulate(T const& val, typename AccumulationTrait<T>::AccumTrait &total ) {
            total += val;
        }
    };

    template<typename T>
    class MultPolicy;

    template<typename T>
    class MultPolicy {
    public:
        static void accumulate(T const& val, typename AccumulationTrait<T>::AccumTrait &total) {
            total *= val;
        }
    };

    template<typename T, typename Policy = SumPolicy<T>>
    static typename AccumulationTrait<T>::AccumTrait accum(T* beg, T* end) {
        static typename AccumulationTrait<T>::AccumTrait total = AccumulationTrait<T>::AccumTrait();
        for (; beg != end; beg++) {
            Policy::accumulate(*beg, total);
        }
        return total;
    }

    void driver() {
        //vector<int> vi = { 1,2,3,4,5 };
        //int sum = accum<int, MultPolicy<int>>(&vi[0], &vi[4]);
        int num[] = { 1,2,3,4,5 };
        accum<int,MultPolicy<int>>(&num[0], &num[5]);
    }


}
namespace CH_15_2 {
    
    template <typename T>
    class TypeSize {
    public:
        static size_t const Size = sizeof(T);
    };
    template<typename C>
    class T {
    public:
        typedef typename C::value_type Type;
    };
    
    template<typename C>
    typename C::value_type sum_of_elem(C coll) {

    }
    template<typename COLL>
    void printTypeName(COLL const& coll) {
        //cout << "Type in container" << (ElementT<COLL>::Type).name();
    }
    void driver() {
        vector<int> vi;
        
    }
}
namespace CPP_15_2_4_Promotraits {
    template<bool C,typename T1,typename T2>
    class IFTHENELSE;

    template<typename T1, typename T2>
    class IFTHENELSE<true,T1,T2>{
    public:
        typedef T1 ResultT;
    };

    template<typename T1,typename T2>
    class IFTHENELSE<false, T1, T2> {
    public:
        typedef T2 ResultT;
    };

    template <class T1,class T2>
    class PromoTrait {
    public:
        typedef typename IFTHENELSE < (sizeof(T1)>sizeof(T2)), T1, T2 > ::ResultT FinalResultType;

    };

    template<typename T>
    class PromoTrait<T,T> {
    public:
        typedef T FinalResulType;
    };

}
namespace CPP_15_3_4 {

}
namespace CheckClass {
    template <typename T> 
    class IsClassT {
    public:
        //typedef char One;
        //typedef struct {char a[2] } Two;
        //template<typename C> static One test<C>(int C::*);
        //template<typename C> static Two test<C>(...);
        //enum {Yes = (sizeof(IsClassT<T>::test<T>(0))==One) };
        //enum { No = !Yes; };
    };
}
namespace CPP15_3_1 {
    template <bool C,typename T1,typename T2>
    class IFTHENELSE;

    template <typename T1, typename T2>
    class IFTHENELSE<true, T1, T2> {
    public:
        typedef T1 Type;
    };

    template <typename T1, typename T2>
    class IFTHENELSE<false, T1, T2> {
    public:
        typedef T2 Type;
    };

    template<typename T>
    class Array {

    };

    template <typename T>
    class RParam {
    public:
        typedef typename IFTHENELSE < (sizeof(T)>(2 * sizeof(void*))), T const&, T > ::Type ResultType;
    };

    template<typename T>
    class RParam<Array<T>> {
    public:
        typedef Array<T> const& ResultType;
    };

    void driver() {
    }
}
namespace CPP15_2_4{
    template <typename T, int N>
    std::array<T, N> operator+(std::array<T, N>& lhs, std::array<T, N>& rhs);

    /*template <typename T, int N>
    std::array<T, N> operator+(std::array<T, N>& lhs, std::array<T, N>& rhs) {
        typename std::array<T, N>::iterator pos(lhs.begin());
        typename std::array<T, N>::iterator end(lhs.end());
        
        typename std::array<T, N>::iterator pos_r(lhs.begin());
        typename std::array<T, N>::iterator end_r(lhs.end());

        std::array<T, N> res;
        typename std::array<T, N>::iterator pos_res(lhs.begin());
        typename std::array<T, N>::iterator end_res(lhs.end());

        while (pos != end) {
            *pos_res = *pos + *pos_r;
            pos++;
            pos_r++;
            pos_res++;
        }
        return res;
    }*/
    class MyClass {
        int n_;
    public:
        MyClass(int n) :n_(n) {

        };
        MyClass& operator+(MyClass const& rhs) {
            n_ = n_ + rhs.n_;
        };
    };
    void driver() {
        std::array<int, 5> a1{ 1,2,3,4,5 };
        std::array<int, 5> a2{ 10,20,30,40,50 };
        std::array<int, 5> a3 = a1 + a2;
        std::array<float, 5> f1{ 1,2,3,4,5 };
        std::array<float, 5> f2{ 10,20,30,40,50 };
        std::array<float, 5> f3 = f1 + f2;
        std::array<MyClass, 5> m1{ 1,2,3,4,5 };
        std::array<MyClass, 5> m2{ 10,20,30,40,50 };
        std::array<MyClass, 5> m3 = m1 + m2;

    }

   
}

namespace CH_10 {
    class Sample {
    public:
        Sample(int x)  {};
    };
    void f1(Sample s) {

    }
    void f2() {
        
        using X = int;
        X a=5;
        typedef char CH_ARRAY[10];
        CH_ARRAY b;
        f1(12);
        typedef int ROWS[5];
        ROWS col[10];
        col[0][0] = 5;
    }
}
namespace Sample_My_Smart_Ptr
{
    template <typename T>
    class MySmart_Ptr {
        T* _ptr;
    public:
        MySmart_Ptr() :_ptr(nullptr) {};
        MySmart_Ptr(MySmart_Ptr& rhs) :_ptr(rhs._ptr) {
            rhs._ptr = nullptr;
        };
        explicit MySmart_Ptr(T* ptr) {
            _ptr = ptr;
        }
        MySmart_Ptr& operator=(MySmart_Ptr& rhs) {
            _ptr = rhs._ptr;
            rhs._ptr = nullptr;
            return *this;
        }
        T& operator*() {
            return *_ptr;
        }
        T operator->() {
            return _ptr;
        }
        
    };
    void func() {
        MySmart_Ptr<int> a1(new int);
        MySmart_Ptr<int> a2(a1);
        a1 = a2;
        *a1 = (*a1) * (*a2);
        int a = 5;
        *a1 = *a1 * a;
        
    }
}
namespace CH_15 {

}
namespace CH_9_3 {

    template <typename T>
    class MyClass {
    public:
        struct X{
            int a;
        };
        X x;
    };
    template<typename T>
    class EvilClass {
        MyClass<T> mc;
    public:
        void fun() {
            int p = 5;
            //p = mc.x.a* p;
        };
    };
    template<>
    class MyClass<void> {
        typedef int x;
    };
    void func() {
        EvilClass<void> ec;
        ec.fun();
    }

}
template <typename T>
    void printColl_d(std::deque<T>& di) {
    cout << "printColl for deque" << endl;
    di.clear();
}
typedef char RT1;
typedef struct { char a[2]; } RT2;
template <typename T> 
RT1 test(typename T::X t) {}


template <typename T>
RT2 test(...) {}

template<typename COLL>
void printColl(COLL col) {
    typename COLL::const_iterator pos(col.begin());
    typename COLL::const_iterator end(col.end());
    while (pos != end) {
        cout << *pos << "\t";
        pos++;
    }
    cout << endl;
}

template <typename COLL, typename FUNC >
void callFunc(COLL& obj, FUNC* fptr) {
    
    fptr(obj);
}

void callFunc_driver() {
    vector<int> vi{ 1,2,3,4,5 };
    deque<int> di{ 1,2,3,4,5 };
    
    callFunc(vi,&printColl<vector<int>>);
    callFunc(di,&printColl<deque<int>>);
}
namespace OVERFLOW_SAMPLE {
    char add(int n,char *arr) {
        char t = arr[0];
        int sum = arr[0];
        
        for (int i = 1; i < n; i++) {
            t = t + arr[i];
            sum = sum + (arr[i]);
        }
        return t;
    }

    void driver() {
        vector<char> vc{ 'a','b','c','d','r' };
        cout << add(vc.size(), vc.data());
    }

}
namespace GET_MAX_OF_CONTAINER {
    template <typename COLL>
    typename COLL::value_type max_elem(COLL coll) {
        typename COLL::iterator pos(coll.begin());
        typename COLL::iterator end(coll.end());
        typename COLL::value_type cur_max = *pos;
        pos++;
        while (pos != end) {
            if (*pos > cur_max) {
                cur_max = *pos;
            }
            pos++;
        }
        return cur_max;
    }
    template <typename COLL,typename max_comparator>
    typename COLL::value_type max_elem(COLL coll) {
        typename COLL::iterator pos(coll.begin());
        typename COLL::iterator end(coll.end());
        typename COLL::value_type cur_max = *pos;
        pos++;
        while (pos != end) {
            cur_max = max_comparator(*pos, cur_max);
            pos++;
        }
        return cur_max;
    }
    
    void driver() {
        vector<int> vi{ 1,2,3,4,5 };
        deque<int> di{ 1,2,3,4,5 };
        cout<<"max elem of vector"<<max_elem(vi)<<endl;
        cout<<"max elem of deque"<<max_elem(di)<<endl;
        typedef struct { char arr[3]; }type24;
        type24 a={'a','b','c'};
        
    }

}

template<template <typename T> typename T2>
void f2() {
    double d = 3;
    double d2 = my_cast<double>('a');
}
template<template <typename T> typename T2> 
void df() {
    Base* bp = new Base;;
    Base* dp1 = new Dervied1;
    Base* dp2 = new Dervied2;
    //func(bp,dp1);
}
class C {};
//struct C{};
//union C{};
int C = 0;
int main()
{
    OVERFLOW_SAMPLE::driver();
    return 0;
    int i;
    Init(&i);
    MyClass mc;
    Init(&mc);
    vector<int> vi2;
    my_median(vi2);
    list<int> li2;

    //int med = median<std::vector<int>,std::allocator<int>>(vi2);
    MyStack<int> ms;
    MyStack<double, std::deque<double>> mfd;
    MyStack<int, std::vector<int>> mvd;
    mfd.push(2.5);
    mfd.push(3.5);
    mvd = mfd;
    std::cout << "Hello World!\n";
    vector<int> vi{ 1,2,3,4 };
    MyArray<int, MyEnum::one> mo;
    MyArray<int, MyEnum::two> mt;
    MyArray<float, MyEnum::one> fo;
    mo = mt;
    mo = fo;
    fillCont(vi, 5);
    deque<int> di{ 10,20,30,40 };
    fillCont(di, 50);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
