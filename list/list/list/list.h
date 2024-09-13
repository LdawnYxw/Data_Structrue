#pragma once
#include<assert.h>

namespace yxw {
	template<class T>
	struct List_Node {
		
		List_Node<T>* _next;
		List_Node<T>* _prev;
		T _data;

		List_Node(const T& x = T()) : _next(nullptr), _prev(nullptr), _data(x) {}
	};

	template<class T, class Ref, class Ptr>
	struct ListIterator {
		typedef List_Node<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;

		Node* _node;

		ListIterator() {
			_node = new Node();
		}
		ListIterator(Node* node): _node(node){}

		Ref operator*() {
			return _node->_data;
		}

		Ptr operator->() {
			return &_node->_data;
		}

		Self& operator++() {
			_node = _node->_next;
			return *this;
		}

		Self operator++(int) {
			Self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		Self& operator--() {
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int) {
			Self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const Self& lt) {
			return _node != lt._node;
		}

		bool operator==(const Self& lt) {
			return _node == lt._node;
		}

	};

	template<class T>
	class list{
		typedef List_Node<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		iterator begin() {
			return _head->_next;
		}

		iterator end() {
			return _head;
		}

		const_iterator begin() const {
			//这里要重新弄一个const_iterator而不是直接const iterator,
			//是因为后者const是迭代器本身（结构体）(相当于Node* const p),而不是结构体里面的数据（相当于const Node* p）
			return _head->_next;
		}

		const_iterator end() const {
			return _head;
		}

		list() {
			Init();
		}

		void Init() {
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			_size = 0;
		}

		list(const list<T>& lt) {
			
			Init();
			for (auto& e : lt) {
				push_back(e);
			}

		}

		void push_back(const T& x) {
			insert(end(), x);
		}

		void push_front(const T& x) {
			insert(begin(), x);
		}

		void pop_back() {
			erase(--end());
		}

		void pop_front() {
			erase(begin());
		}

		T front() {
			return *(begin());
		}

		T back() {
			return (_head->_prev)->_data;
		}

		void insert(iterator pos, const T& val) {

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(val);

			prev->_next = newnode;
			newnode->_next = cur;
			newnode->_prev = prev;
			cur->_prev = newnode;

			_size++;
		}

		iterator erase(iterator pos) {
			
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = cur->_next;
			cur->_next->_prev = prev;

			delete[] cur;
			_size--;

			return iterator(prev->_next);
		}

		size_t size() const {
			return _size;
		}

		bool empty() {
			return _size == 0;
		}

		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
		}

		void swap(list<T>& lt) {
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt) {
			swap(lt);
			return *this;
		}

		~list() {
			clear();
			delete[] _head;
			_head = nullptr;
		}

	private:
		Node* _head;
		size_t _size;
	};
};