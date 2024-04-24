#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		Array<T>& operator+=(const T&);
		Array<T>& operator-=(const T&);
		const T& operator[](int index) const;
		T& operator[](int index);

		int getSize() const;
		bool isFull() const;

		void clear();
	
	private:
		int numElements;
		T* elements;
	
};

template <typename T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

template <typename T>
Array<T>::~Array(){
	delete [] elements;
}

template <typename T>
Array<T>& Array<T>::operator+=(const T& s){
	if (numElements >= MAX_ARR)   return *this;
  	elements[numElements++] = s;
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(const T& s){
	int index = 0;
	while (index < numElements){
		if (s == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

template <typename T>
int Array<T>::getSize() const{
	return numElements;
}

template <typename T>
bool Array<T>::isFull() const {
	return numElements >= MAX_ARR;
}

template <typename T>
const T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
void Array<T>::clear(){
	
    // delete[] elements;
    // elements = nullptr;
    numElements = 0;
    
}


#endif