#pragma once
#include<assert.h>
#include<initializer_list>

namespace yxw {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//������
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

		//���캯��
		vector() : start(nullptr), finish(nullptr), end_of_storage(nullptr) {}

		vector(const vector<T>& v) {
			reverse(v.capacity());
			for (auto& e : v) {//�����÷�ֹǳ����
				push_back(e);
			}
		}

		//Ӧ�� vector<int> a = { 0�� 1�� 2�� 3�� 4}
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

		vector(int n, const T& val = T()) {//��ֹ������ģ�巢����ͻ
			reverse(n);
			for (size_t i = 0; i < n; i++) {
				push_back(val);
			}
		}

		//������
		size_t size() const{ //��Ч���ݴ�С
			return finish - start;
		}

		size_t capacity() const { //�ռ�����
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

		//β��
		void push_back(const T& val) {
			insert(end(), val);
		}

		//����
		void insert(iterator pos, const T& val) {

			assert(pos >= start);
			assert(pos <= finish);

			if (finish == end_of_storage) {
				size_t len = pos - start;
				reverse(capacity() == 0 ? 4 : capacity() * 2);
				pos = start + len;//��ֹ������ʧЧ
			}

			++ finish;
			for (iterator it = finish - 1; it > pos; it --) {
				*it = *(it - 1);
			}

			*pos = val;
		}

		//βɾ
		void pop_back() {
			erase(end() - 1);
		}

		//ɾ��
		iterator erase(iterator pos) {
			
			assert(pos >= start);
			assert(pos < finish);

			--finish;
			for (iterator it = pos; it != finish; it++) {
				*it = *(it + 1);
			}

			return pos;
		}


		//��������
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