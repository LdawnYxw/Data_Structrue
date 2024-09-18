#pragma once
#include<list>
#include<deque>

namespace yxw {

	template<class T, class Container = std::deque<T>>
	class queue {
	public:

		queue(){}

		void push(const T& x) {
			con.push_back(x);
		}

		void pop() {
			con.pop_front();
		}

		size_t size() {
			return con.size();
		}

		bool empty() {
			return con.empty();
		}

		T& front() {
			return con.front();
		}

		const T& front() const{
			return con.front();
		}

		T& back() {
			return con.back();
		}

		const T& back() const {
			return con.back();
		}

	private:
		Container con;
	};
}