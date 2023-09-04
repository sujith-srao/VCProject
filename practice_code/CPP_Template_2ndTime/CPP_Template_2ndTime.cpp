// CPP_Template_2ndTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<valarray>
#include<string>
#include<vector>
#include<list>
#include<unordered_map>
#include<functional>
#include<locale>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<mutex>
#include<optional>
#include <functional>
#include<stack>
#include<any>
#include<future>
#include<thread>
#include<variant>
#include<unordered_set>
#include<cassert>
#include<chrono>
#include<array>

using namespace std;

template <typename T>
T max(T const& a, T const& b) {
    if (a > b)
        return a;
    else
        return b;
}

/*C++ 17 STL Cook book */
namespace CPP_17_STL_CookBook {
    namespace Sample {
        class Sam {
            
        public:
            string name_;
            Sam(string name):name_(name) {
                cout << __func__ << " constructor" << endl;
            }
            Sam(Sam const &rhs) {
                cout << __func__ << " copy constructor " << endl;
            }
            Sam(Sam&& m) : name_(std::move(m.name_)){
                cout << __func__<<" mv operator" << endl;
            }

        };
        void g(Sam&& s) {
            cout << __func__ << " inside g" << endl;
        }
        /*const Sam& getSam() {
            return (Sam());
        }*/
        void driver() {
            Sam s1("Hello");
            //Sam s2=s1;
            Sam s3(std::move(s1));

            cout << "s1 after move:" << s1.name_ << endl;
            cout << "s3 after move:" << s3.name_ << endl;
        }
    }

    //namespace MyStack {
    //    template<typename T,template <typename C> class Cont=std::deque>
    //    class Stack {
    //        Cont<T> elems;
    //    public:
    //        template<typename T2,template<typename C> class Cont2> 
    //        friend class Stack;
    //        template<typename T2,typename 
    //    };
    //    void driver() {
    //        MyStack::Stack<int, std::vector> ms;
    //        MyStack::Stack<int> ms1;

    //    }
    //}


    namespace Chapter_1 {
        pair<int, int> divide_reminder(int dividend, int divisor) {
            int rem = dividend % divisor;
            int quo = dividend / divisor;
            return make_pair(rem, quo);
        }
        struct employee{
            int id;
            string name;
        };
        int getCount() {
            return 5;
        }
        template <typename T>
        class addable {
            T val;
        public:
            addable(T v) : val{ v } {

            };
            template<typename U>
            T add(U x) {
                if constexpr (std::is_same_v<T, vector<U>>) {
                    
                    auto my_copy(val);
                    for (auto &it : my_copy) {
                        it +=  val;
                    }
                    return my_copy;
                }
                else {
                    val += x;
                    return val;
                }
                
            }
        };

        template <typename ... Ts>
        auto MySum(Ts ...ts) {
            return (ts + ...+0);
        }
        template<typename R,typename ... Ts>
        auto matches(const R& range, Ts ... ts) {
            return (std::count(begin(range), end(range), ts) + ...);
        }


        template<typename T,typename S>
        ostream& operator <<(ostream& rhs,std::pair<T,S> sp) {
            return rhs << "{" << sp.first << ", " << sp.second << "},";

        }
        template<typename T, typename S,typename R>
        ostream& operator <<(ostream& rhs, std::tuple<T, S,R> sp) {
            return rhs << "{" << std::get<0>(sp) << ", " <<std::get<1>(sp)<< ", " << std::get<2>(sp)<< "},";
        }

        template<typename Cont>
        void container_Printer(Cont c) {
            using my_iterator = typename Cont::iterator;
            my_iterator itBegin = c.begin();
            my_iterator itEnd   = c.end();
            using Container_Elem = typename Cont::value_type;

            for (; itBegin != itEnd; itBegin++) {
                cout << *itBegin << ", ";
            }
            cout << endl;
        }

        template<typename T,typename Cont=vector<T>> 
        int return_Count(T val, Cont c) {
            return count(c.begin(), c.end(), val);
        }

        template<typename Cont>
        Cont union_of_container(Cont c1, Cont c2) {
            Cont ret;
            using my_iterator = typename Cont::iterator;
            my_iterator it_c1_begin = c1.begin();
            my_iterator it_c1_end = c1.end();
            my_iterator it_c2_begin = c2.begin();
            my_iterator it_c2_end = c2.end();
            
            /*Copy first set completely*/
            for (; it_c1_begin != it_c1_end; it_c1_begin++) {
                    ret.push_back(*it_c1_begin);
            }

            for (; it_c2_begin != it_c2_end; it_c2_begin++) {
                auto pos = find(ret.begin(), ret.end(), *it_c2_begin);
                if (pos == ret.end())
                    ret.push_back(*it_c2_begin);
            }
            return ret;
        }

        template<typename Cont>
        Cont chopped(Cont cont,size_t len) {
            bool b_is_vector = std::is_same_v<Cont, vector<Cont::val_type>>;
            if (b_is_vector) {
                typename Cont::iterator begin = cont.begin();
                typename Cont::iterator end = cont.end();
                for (; len>0; begin++) {
                    len--;

                }
                cont.erase(begin, cont.end());
            }
            return cont;
        }

        void driver() {
            auto [rem, quo] = divide_reminder(45, 6);
            vector<employee> employees;
            for (auto [id, name] : employees) {
                cout << "id:" << id;
                cout << "name:" << name;
            }
            if (int i = 0; i = getCount()) {
                //doSomething
            }
            else {
                i = 10;
            }
            /*-------------Prints container contents-*/
            vector<int> vi{ 10,20,30,40,50 };
            list<double> lf{ 10.5,20.3,30.0,40.0,50.0 };
            array<float, 3> af{ 10.4,4.5,3.2 };
            container_Printer(vi);
            container_Printer(lf);
            container_Printer(af);
            vector<std::pair<string, int>> vpsi{ {"Hello",1},
                {"World",2} };
            container_Printer(vpsi); 
            vector<tuple<string, int, int>> vtsii{ {"Hello",1,1},
                                                  {"World",2,2} };
            container_Printer(vtsii);

            /*---------Union of containers---------------*/
            vector<int> vi2{ 10,20,30,40,50 };
            vector<int> vi3{ 40,50,60,70,80 };
            vector<int> ans = union_of_container(vi2, vi3);
            container_Printer(ans);
            
        }
    }
}
namespace DesignPattern_Practice{
    namespace Factory_Method {
        
        enum  CarBrands{
            BMW,
            Ford,
            GM,
            Chevrolet
        };
        class Car {
        public:
            virtual string getModel() = 0;
            virtual string getModelLaunchYear() = 0;
        };
        class CarManufacurer {
        public:

            virtual CarManufacurer* getCarFactory() = 0;

        };
        class BMW_factory :public CarManufacurer {
        public:
            enum CarModels {
                BMW1,
                BMW2,
                BMW3               
            };
            CarManufacurer* getCarFactory() override {
                return new BMW_factory;
            }
        };
        class Ford_factory :public CarManufacurer {
        public:
            CarManufacurer* getCarFactory() override {
                return new Ford_factory;
            }
        };

        class GM_factory :public CarManufacurer {
        public:
            CarManufacurer* getCarFactory() override {
                return new GM_factory;
            }
        };

        class Chevrolet_factory :public CarManufacurer {
        public:
            CarManufacurer* getCarFactory() override {
                return new Chevrolet_factory;
            }
        };
    }
}
int main()
{
    //CPP_17_STL_CookBook::Chapter_1::driver();
    CPP_17_STL_CookBook::Sample::driver();
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
