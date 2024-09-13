#include<iostream>
#include"String.h"

void String_test1() {
	yxw::String s1("yxw");
	yxw::String s2("cx");
	for (int i = 0; i < s1.size(); i++) {
		std::cout << s1[i] << " ";
	}
}

void String_test2() {
	yxw::String s1("Yxw");
	s1 += "Cx";
	yxw::String s2("Cx");
	s1 += s2;
	std::cout << s1.c_str() << "\n";
}

void String_test3() {
	yxw::String s1("YxwCX");
	int pos = s1.find("Cx");
	if (pos == yxw::String::npos) {
		std::cout << "NO" << "\n";
	}
	else {
		std::cout << "YES" << "\n";
	}
}

void String_test4() {
	yxw::String s1("Yxw");
	int pos = s1.find('x', 1);
	if (pos == yxw::String::npos) {
		std::cout << "NO" << "\n";
	}
	else {
		std::cout << "YES" << "\n";
	}
}

int main() {
	String_test4();
	return 0;
}