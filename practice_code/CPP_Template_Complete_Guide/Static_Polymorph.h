#pragma once
#include<iostream>
using namespace std;
class Rectangle {
public:
	void draw() {
		cout << "Rectangle draw" << endl;
	};
	int num_of_sides() {
		return 4;
	}
};
class Circle{
public:
	void draw() {
		cout << "Circle draw" << endl;
	};
	int num_of_sides() {
		return 1;
	}
};
template<typename T>
class Shape {
	T* ptr_;
public:
	//Shape(T* ptr) :ptr_(ptr) {};
	//void draw() {
	//	ptr->draw();
	//};
	//int num_of_sides() {
	//	ptr->num_of_sides();
	//};
};