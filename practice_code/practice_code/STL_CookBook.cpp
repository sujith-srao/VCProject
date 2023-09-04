#include "pch.h"
#include "STL_CookBook.h"
#include<tuple>
#include<iostream>
#include<vector>
#include<memory>

using namespace std;
namespace STL_Cookbook {

	namespace Chapter_1 {
		std::pair<int, int> divide(int divisor, int dividend) {
			int rem = divisor % dividend;
			int quo = divisor / dividend;
			auto ans = std::make_pair(rem, quo);
			return ans;
		}

		template<typename T>
		void quick_remove_at(std::vector<T> arr, int val) {
			auto it = find(arr.begin(), arr.end(), val);
			if (it != arr.end()) {
				;
			}
		}

		void driver() {
			auto [rem, quo] = divide(10, 3);
			cout << "answer to 10/3=" << rem << quo << endl;


		}

	}

	namespace Chapter_4 {
		void driver() {
			auto f1 = []() { return 1; };
			auto f2 = []() { return 2; };
			auto plus = [](auto a, auto b) {return a + b; };
			int x = 0;
			auto incrementer = [&x]() {x++; };
			auto plus_ten = [=](int x) {return plus(10, x); };

		}
	}
	namespace Uniq_ptr_example {
		class Sample {
		public:
			string _name;
			Sample(string name) :_name(name) {
				cout << "CTOR" << _name << endl;;
			}
			~Sample()  {
				cout << "DTOR" << _name<< endl;;
			}
		};
		void f(unique_ptr<Sample> f) {
			cout << "Processing" << f->_name<< endl;;
		}

		void f1(shared_ptr<Sample> f) {
			cout << "Processing Shared PTR " << f->_name << f.use_count() << endl;

		}

		void driver() {
			{
				unique_ptr<Sample> f1(new Sample("foo"));
				unique_ptr<Sample> f2(new Sample("bar"));
			}
			unique_ptr<Sample> f3(new Sample("foo1"));
			unique_ptr<Sample> f4(new Sample("foo2"));
			f(move(f3));
			cout << "F returned" << endl;


			shared_ptr<Sample> s1(make_shared<Sample>("Shared 1"));
			{
				shared_ptr<Sample> s2(s1);
				shared_ptr<Sample> s3;
				s3 = s1;
				cout << "In the scope Shared pointer use count" << s1.use_count() << endl;;
			}
			cout << "Outside Shared pointer use count" << s1.use_count() << endl;;
			f1(s1);
			cout << "After f1 use count" << s1.use_count() << endl;;
			

		}
	}

	namespace Lambda_Functions_Sample {
		int twice(int i) {
			return 2 * i;
		}
		int thrice(int i) {
			return 3 * i;
		}
		int add(int a, int b) {
			return a + b;
		}
		template<typename T,typename ...Ts>
		auto concat(T t, Ts ...ts) {
			if (sizeof...(ts) > 0) {
				return [=](auto ...parameters) {
					t(concat(ts...)(parameters...));
				};
			}
			else {
				return [=](auto ...parameters) {
					t(parameters...);
				};
			}
		}

		template<typename T>
		void print(T t) {
			cout << t << endl;
		}

		template<typename T,typename ...Ts>
		void print(T t, Ts ...ts) {
			if (sizeof ...(ts)) {
				cout << t << endl;
				print(ts...);
			}
			else {
				print(t);
			}
		}
		
		bool starts_with(string s) {
			return s.find("a") == 0;
		}

		bool ends_with(string s) {
			return s.find("z") == s.length() - 1;
		}

		/*template<typename T,typename ...Ts>
		bool my_OR(T t, Ts ...ts) {
			if (sizeof ...(ts)>2) {
				return my
			}
		}*/

		void driver() {
			print(10, "string", 4.5);
		}
	}

}



void STL_CookBook_driver() {
	STL_Cookbook::Uniq_ptr_example::driver();
	STL_Cookbook::Lambda_Functions_Sample::driver();
}
