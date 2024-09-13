#pragma once
#include<assert.h>
#include<initializer_list>

namespace yxw {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//迭代器
		iterator begin() {
			return start;
		}

		iterator end() {
			return finish;
		}

		const_iterator begin() const {
			return start;
		}

		const_iterator end() const {
			return finish;
		}

		//构造函数
		vector() : start(nullptr), finish(nullptr), end_of_storage(nullptr) {}

		vector(const vector<T>& v) {
			reverse(v.capacity());
			for (auto& e : v) {//加引用防止浅拷贝
				push_back(e);
			}
		}

		//应对 vector<int> a = { 0， 1， 2， 3， 4}
		vector(std::initializer_list<T> v) {
			reverse(v.size());
			for (auto& e : v) {
				push_back(e);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last) {
			while (first != last) {
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T()) {
			reverse(n);
			for (size_t i = 0; i < n;i ++) {
				push_back(val);
			}
		}

		vector(int n, const T& val = T()) {//防止与上面模板发生冲突
			reverse(n);
			for (size_t i = 0; i < n; i++) {
				push_back(val);
			}
		}

		//主函数
		size_t size() const{ //有效数据大小
			return finish - start;
		}

		size_t capacity() const { //空间容量
			return end_of_storage - start;
		}

		bool empty() {
			return start == finish;
		}

		T& operator[](size_t pos) {
			assert(pos < size());
			return start[pos];
		}

		const T& operator[](size_t pos) const{
			assert(pos < size());
			return start[pos];
		}

		void swap(vector<T>& v) {
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(end_of_storage, v.end_of_storage);
		}

		vector<T>& operator=(vector<T> v) {
			swap(v);
			return *this;
		}

		void reverse(size_t n) {
			if (n > capacity()) {
				T* tmp = new T[n];
				size_t old_size = size();
				for (size_t i = 0; i < size(); i++) {
					tmp[i] = start[i];
				}
				delete[]start;

				start = tmp;
				finish = tmp + old_size;
				end_of_storage = tmp + n;
			}
		}

		void resize(size_t n, const T& val = T()) {
			if (n > size()) {
				reverse(n);
				for (iterator it = finish; it != start + n; it++) {
					*it = val;
				}
				finish = start + n;
			}
			else {
				finish = start + n;
			}
		}

		//尾插
		void push_back(const T& val) {
			insert(end(), val);
		}

		//插入
		void insert(iterator pos, const T& val) {

			assert(pos >= start);
			assert(pos <= finish);

			if (finish == end_of_storage) {
				size_t len = pos - start;
				reverse(capacity() == 0 ? 4 : capacity() * 2);
				pos = start + len;//防止迭代器失效
			}

			++ finish;
			for (iterator it = finish - 1; it > pos; it --) {
				*it = *(it - 1);
			}

			*pos = val;
		}

		//尾删
		void pop_back() {
			erase(end() - 1);
		}

		//删除
		iterator erase(iterator pos) {
			
			assert(pos >= start);
			assert(pos < finish);

			--finish;
			for (iterator it = pos; it != finish; it++) {
				*it = *(it + 1);
			}

			return pos;
		}


		//析构函数
		~vector() {
			delete[] start;
			start = finish = end_of_storage = nullptr;
		}

	private:
		iterator start = nullptr;
		iterator finish = nullptr;
		iterator end_of_storage = nullptr;
	};
}