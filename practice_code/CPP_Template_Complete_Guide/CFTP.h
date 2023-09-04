#pragma once
template<typename T>
class ObjectCounter;

class C:private ObjectCounter<C> {
};

template<typename T>
class ObjectCounter {  
	static int count;
protected:
	ObjectCounter() {
		ObjectCounter<T>::count++;
	};
	ObjectCounter(ObjectCounter<T> const& rhs) {
		ObjectCounter<T>::count++;
	};
	~ObjectCounter() {
		ObjectCounter<T>::count--;
	};
public:
	size_t live() {
		return ObjectCounter<T>::count;
	}
};
int ObjectCounter<C>::count = 0;