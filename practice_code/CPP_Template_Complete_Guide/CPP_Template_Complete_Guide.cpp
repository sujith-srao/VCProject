// CPP_Template_Complete_Guide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<deque>
#include<stack>
#include<algorithm>
#include<list>
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
namespace CH_10 {
    class Sample {
    public:
        Sample(int x)  {};
    };
    void f1(Sample s) {

    }
    void f2() {
        typedef int X;
        X a=5;
        typedef char CH[10];
        CH a={};
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
namespace CH_9_3 {

    template <typename T>
    class MyClass {
    public:
        struct X{
        int a
        };
        X x;
    };
    template<typename T>
    class EvilClass {
        MyClass<T> mc;
    public:
        void fun() {
            int p = 5;
            p = mc.x.a* p;
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

template <typename T, typename FUNC >
void callFunc(T& obj, FUNC* fptr) {
    
    fptr<typename T::value_type>(obj);
}

void callFunc_driver() {
    vector<int> vi{ 1,2,3,4,5 };
    deque<int> di{ 1,2,3,4,5 };
    callFunc(vi,&printColl_v);
    callFunc(di,&printColl_d);
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
    callFunc_driver();
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
