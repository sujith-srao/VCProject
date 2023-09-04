#pragma once
template <typename T>
class Holder {
	T* ptr_;
public:
	Holder(T* ptr) :ptr_(ptr) {};
	Holder(Holder<T>& rhs) {
		ptr_ = rhs.ptr_;
		delete ptr_;
	};
	Holder(Holder<T>& rhs) {
		ptr_ = rhs.ptr_;
		delete ptr_;
	};
	Holder<T>& operator=(Holder<T>& rhs) {
		if (*this == rhs)
			return *this;
		T* temp_ptr = nullptr;
		temp_ptr = rhs.ptr_;
		rhs.ptr_ = ptr_;
		ptr_ = temp_ptr;
		return *this;
	};
	T* operator->() {
		return ptr_;
	};
	T& operator*() {
		return *ptr_;
	}
	
};