#pragma once
template<typename T>
class RefCountedPtr {
	/*typedef struct  {
		int ref_count_;
		T* ptr_;
	} Data;

	static Data *dp;
public:
	RefCountedPtr(T* ptr) :ptr_(ptr) {
		ref_count_++;
	};
	RefCountedPtr(RefCountedPtr<T> const& rhs) {
		ref_count_++;
	};
	RefCountedPtr<T>& operator=(RefCountedPtr<T> const& rhs) {
		if (*this == rhs)
			return *this;

		ref_count_--;
		if (ref_count_ == 0) {
			delete ptr_;
		}
		rhs.ref_count_++;
		ptr_ = rhs.ptr_;
		return *this;
	};
	
	T* operator->() {
		return ptr_;
	};

	T& operator*() {
		return *ptr_;
	};


	~RefCountedPtr() {
		ref_count_--;
		if (ref_count_ == 0) {
			delete ptr_;
		}
	};*/




};
