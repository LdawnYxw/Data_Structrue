#pragma once
#include<vector>
#include<list>
#include<deque>

namespace yxw {

	template<class T, class Container = std::deque<T>>
	class stack {
	public:

		stack(){}

		void push(const T& x) {
			con.push_back(x);
		}

		void pop(){
			con.pop_back();
		}

		size_t size() {
			return con.size();
		}

		bool empty() {
			return con.empty();
		}

		T& top() {
			return con.back();
		}

		const T& top() const {
			return con.back();
		}

	private:
		Container con;
	};

}