#include "stdafx.h"
#include "HeapBinary.h"


heaps::heaps()
:currentsize{ 0 }{
	a = new int[1000001];
}
heaps::~heaps(){
	delete[] a;
}
void heaps::insert(int value){
	a[0] = value;
	int hole = ++currentsize;
	while (a[hole / 2]>value){
		a[hole] = std::move(a[hole / 2]);
		hole /= 2;
	}
	a[hole] = std::move(a[0]);
}
int heaps::extract_min(){
	int return_value = a[1];
	int hole = 1, child = 0;
	int temp = std::move(a[currentsize--]);
	while (2 * hole <= currentsize){
		child = 2 * hole;
		if (child != currentsize && a[child + 1]<a[child]){
			++child;
		}
		if (a[child]<temp){
			a[hole] = std::move(a[child]);
		}
		else{
			break;
		}
		hole = child;
	}
	a[hole] = std::move(temp);
	return return_value;
}
bool heaps::isempty(){
	return currentsize == 0;
}

void heaps::print(){
	for (int i = 1; i <= currentsize; ++i){
		std::cout << a[i] << std::endl;
	}
}

size_t heaps::size(){
	return currentsize;
}
