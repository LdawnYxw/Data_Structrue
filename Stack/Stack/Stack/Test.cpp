#include<iostream>
#include"stack.h"


int main() {

	yxw::stack<int> a;
	a.push(1);
	a.push(3);
	a.push(1);
	a.push(4);

	a.top() += 5;
	std::cout << a.top() << "\n";


	return 0;
}