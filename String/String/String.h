/**
 *  author: Ldawn_AI
 *  Date: 2024-07-22
**/
#pragma warning(disable: 4996)
#pragma once
#include<assert.h>

namespace yxw {
	class String {
	public:
		//���캯��
		String(const char* str = ""): _size(strlen(str)) {//�ڳ�ʼ���б�ֻ��ʼ��size,��ֹ��ε���strlen
			_str = new char[_size + 1];//��1ע����'\0'
			strcpy(_str, str);
			_capacity = _size;
		}

		//���size, capacity,�ַ���
		size_t size() const { // const������const string�ͷ�const string�����Ե���
			return _size;
		}

		size_t capacity() const {
			return _capacity;
		}

		const char* c_str() const {
			return _str;
		}

		//�����±���ʲ����� 
		char& operator[](size_t pos) {//��&�������޸�
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const {
			assert(pos < _size);
			return _str[pos];
		}

		String(const String& s) {
			char* tmp = new char[s.size()];
		}

		//����reserve
		void reserve(size_t n) {
			if (n > _capacity) {//��һ���µ��ڴ�鸴��Ȼ��ָ�򼴿�
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				_str = tmp;
				_capacity = n;
			}
		}

		//������Ч�ַ���Сresize
		void resize(size_t n, char ch = '\0') {
			if (n <= _size) {
				_str[n] = '\0';
				_size = n;
			}else {
				reserve(n);
				for (size_t i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		//insert
		void insert(size_t pos, char ch) {
			assert(pos <= _size);

			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);//��������
			}

			/*
			int end = _size;
			while (end >= ��int)pos) {//end������-1�����Ա���Ҫǿ������ת��������ᵼ����������,end��int�ᱻ��ʽת����size_t
				_str[end] = _str[end + 1];
				--end;
			}
			*/

			size_t end = _size + 1;
			while (end > pos) {
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++ _size;
		}

		void insert(size_t pos, const char* str) {
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size == _capacity) {
				reserve(_size + len);
			}

			size_t end = _size + len;
			while (end > pos + len - 1) {
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
		}

		//push_back, append, +=
		void push_back(char ch) {
			insert(_size, ch);
		}

		void append(const char* str) {
			insert(_size, str);
		}

		String& operator+=(char ch) {
			push_back(ch);
			return *this;
		}

		String& operator+=(const char* str) {
			append(str);
			return *this;
		}

		String& operator+=(const String& s) {
			append(s.c_str());
			return *this;
		}

		//ɾ��erase
		void erase(size_t pos, size_t len = npos) {
			assert(pos < _size);

			if (len == npos || len >= _size - pos) {
				_str[pos] = '\0';
				_size = pos;
			}else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		//swap
		void swap(String& s) {
			std::swap(_str, s._str);//ֱ�ӽ����ĵ�ַ����Ҫ�������ռ�
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch, size_t pos = 0) const {
			assert(pos < _size);

			for (size_t i = pos; i < _size; i++) {
				if (_str[i] == ch) {
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* sub, size_t pos = 0) const {
			assert(pos < _size);
			
			const char* p = strstr(_str + pos, sub);//strstr��������ƥ���ַ�����
			if (p) {
				return p - _str;
			}
			else {
				return npos;
			}
		}




		//��������
		~String() {
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;

	public:
		static const int npos;
	};

	const int String::npos = -1;
}