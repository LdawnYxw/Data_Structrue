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
		//构造函数
		String(const char* str = ""): _size(strlen(str)) {//在初始化列表只初始化size,防止多次调用strlen
			_str = new char[_size + 1];//加1注意有'\0'
			strcpy(_str, str);
			_capacity = _size;
		}

		//输出size, capacity,字符串
		size_t size() const { // const可以让const string和非const string都可以调用
			return _size;
		}

		size_t capacity() const {
			return _capacity;
		}

		const char* c_str() const {
			return _str;
		}

		//重载下标访问操作符 
		char& operator[](size_t pos) {//加&来进行修改
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

		//扩容reserve
		void reserve(size_t n) {
			if (n > _capacity) {//开一个新的内存块复制然后指向即可
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				_str = tmp;
				_capacity = n;
			}
		}

		//调整有效字符大小resize
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
				reserve(_capacity == 0 ? 4 : 2 * _capacity);//二倍扩容
			}

			/*
			int end = _size;
			while (end >= （int)pos) {//end最后等于-1，所以必须要强制类型转换，否则会导致整形提升,end的int会被隐式转换成size_t
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

		//删除erase
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
			std::swap(_str, s._str);//直接交换的地址，不要开第三空间
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
			
			const char* p = strstr(_str + pos, sub);//strstr就是用来匹配字符串的
			if (p) {
				return p - _str;
			}
			else {
				return npos;
			}
		}




		//构析函数
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