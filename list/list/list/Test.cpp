#include<iostream>
#include"list.h"

void test1() {
	yxw::list<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);
	for (auto x : a) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	a.push_front(0);
	a.push_front(2);
	a.push_front(5);

	yxw::list<int>::iterator it = a.begin();
	while (it != a.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}

void test2() {
	yxw::list<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);
	for (auto x : a) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	a.push_front(0);
	a.push_front(2);
	a.push_front(5);

	a.pop_front();
	a.pop_back();

	yxw::list<int>::iterator it = a.begin();
	while (it != a.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";

}

void test3() {
	yxw::list<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);
	for (auto x : a) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	a.push_front(0);
	a.push_front(2);
	a.push_front(5);

	yxw::list<int>::iterator it = a.begin();
	while (*it != 2) {
		it++;
	}

	it = a.erase(it);

	a.insert(it, 10);

	it = a.begin();
	while (it != a.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";

	std::cout << a.front() << "\n";
	std::cout << a.back() << "\n";
}

int main() {

	test3();

	return 0;
}