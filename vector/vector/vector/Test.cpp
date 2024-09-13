#include<iostream>
#include<cstdio>
#include<vector>
#include"vector.h"

void test1() {
	yxw::vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);

	a.insert(a.begin(), 0);
	a.insert(a.begin(), 2);
	a.insert(a.begin(), 5);

	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";

	for (yxw::vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

void test2() {
	yxw::vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);

	a.insert(a.begin(), 0);
	a.insert(a.begin(), 2);
	a.insert(a.begin(), 5);

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";

	a.pop_back();
	a.pop_back();

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";

	a.erase(a.begin());

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

void test3() {
	std::vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";

	a.resize(10, 1);


	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";

	yxw::vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);

	for (auto e : b) {
		std::cout << e << " ";
	}
	std::cout << "\n";

	b.resize(10, 1);


	for (auto e : b) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

void test4() {
	yxw::vector<int> a(10, 1);

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

void test5() {
	yxw::vector<std::string> a = { "yixuan", "shajdh", "jsdhkf", "kdshkf"};

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";

}

void test6() {
	yxw::vector<int> a(10, 1);
	yxw::vector<int> b(a.begin(), a.end());

	for (auto e : b) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

void test7() {
	yxw::vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(4);

	a.insert(a.begin(), 0);
	a.insert(a.begin(), 2);
	a.insert(a.begin(), 5);

	yxw::vector<int>::iterator it = a.begin();

	while (it != a.end()) {
		if (*it % 2 == 0) {
			it = a.erase(it);//用完erase或者insert原来的迭代器可能会失效记得更新
		}
		else {
			++it;
		}
	}

	for (auto e : a) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

int main() {

	test7();

	return 0;
}