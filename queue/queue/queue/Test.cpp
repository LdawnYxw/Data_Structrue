#include<iostream>
#include"queue.h"

int main() {

	yxw::queue<int> a;

	a.push(1);
	a.push(3);
	a.push(1);
	a.push(4);

	while (!a.empty()) {
		std::cout << a.front() << "\n";
		a.pop();
	}

	return 0;
}