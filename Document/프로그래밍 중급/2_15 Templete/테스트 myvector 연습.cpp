//백터를 템플릿으로 구현하기

//멤버 변수 ( T* p, size_t size, capacity )
//메모리 관리 new delete
//생성자, 소멸자 ( Copy, Move, Uniform Initialization )
//대입 연산자 ( Copy, Move Assignment )
//추가, 삽입, 삭제 등 함수 (push_back, insert, erase... )
//첨자 연산자 ( operator[] ) 

//Nested Class 로 iterator Class 구현 

#include <iostream>

template<typename T>
class myvector
{
public:
	// nested class
	class iterator
	{
	public:
		iterator(T* p = nullptr, size_t idx = 0) : pv(p), pos(idx) {}
		~iterator() {}
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		iterator operator+(size_t n);
		iterator operator-(size_t n);
		bool operator==(const iterator& it) const noexcept;
		bool operator!=(const iterator& it) const noexcept;
		iterator& operator+=(size_t n);
		iterator& operator-=(size_t n);
		T& operator*() const;
		const T* operator->() const;
	private:
		friend class myvector;
		T* pv;
		size_t pos;
	};

	// constructors
	explicit myvector(size_t c = 1) : p(new T[c]{}), _size(0), _capacity(c) {};
	myvector(const myvector<T>& rhs) : p(new T[rhs._size]), _size(rhs._size), _capacity(rhs._capacity)
	{
		for (int i = 0; i < _size; ++i)
		{
			p[i] = rhs.p[i];
		}
	}
	myvector(myvector<T>&& rhs) : p(std::move(rhs.p)), _size(std::move(rhs._size)), _capacity(std::move(rhs._capacity)) { rhs.p = nullptr; }
	myvector(const std::initializer_list<T>& lst) : p(new T[lst.size()]{}), _size(lst.size()), _capacity(lst.size())
	{
		for (int i = 0; i < _size; ++i)
		{
			p[i] = lst[i];
		}
	}
	~myvector()
	{
		delete[] p;
	}

	// operator
	myvector<T>& operator=(const myvector& rhs);
	myvector<T>& operator=(myvector&& rhs);
	T& operator[](size_t pos);

private:
	T* p;
	size_t _size, _capacity;

public:
	inline T& front() { return p[0]; }
	inline const T& front() const { return p[0]; }
	inline T& back() { return p[_size - 1]; }
	inline const T& back() const { return p[_size - 1]; }

	inline iterator begin() { return iterator(p); }
	inline iterator end() { return iterator(p, _size); }
	inline iterator erase(const iterator& it);
	inline iterator erase(const iterator& sit, const iterator& eit);
	inline void push_back(const T& val);
	inline void push_back(const T&& val);
	inline void pop_back() { _size = _size > 0 ? _size - 1 : 0; };
	inline iterator insert(const iterator& it, const T& val);
	inline void resize(size_t n, const T& val = T());
	inline void reserve(size_t n);
	inline void swap(myvector<T>& rhs) noexcept;

	inline bool empty() const noexcept { return _size == 0; }
	inline void clear()  noexcept { _size = 0; }
	inline size_t size() const noexcept { return _size; }
	inline size_t capacity() const noexcept { return _capacity; }
};

template<typename T>
T& myvector<T>::operator[](size_t pos)
{
	return p[pos];
}

template<typename T>
myvector<T>& myvector<T>::operator=(myvector&& rhs)
{
	delete[] p;
	this->p = rhs->p;
	this->_size = rhs->_size;
	this->_capacity = rhs->_capacity;

	rhs->p = nullptr;

	return *this;
}

template<typename T>
myvector<T>& myvector<T>::operator=(const myvector& rhs)
{
	delete[] p;
	this->p = new T[rhs._size];
	this->_size = rhs._size;
	this->_capacity = rhs._capacity;

	for (int i = 0; i < _size; ++i)
	{
		this->p[i] = rhs.p[i];
	}

	return *this;
}

template<typename T>
void myvector<T>::swap(myvector<T>& rhs) noexcept
{
	T* tempP = this->p;
	size_t tempSize = this->_size;
	size_t tempCapacity = this->_capacity;

	this->p = rhs->p;
	this->_size = rhs->_size;
	this->_capacity = rhs->_capacity;

	rhs->p = tempP;
	rhs->_size = tempSize;
	rhs->_capacity = tempCapacity;
}

template<typename T>
void myvector<T>::reserve(size_t n)
{
	if (n < _size)
	{
		_size = n;
	}
	_capacity = n;

	T* pT = new T[n];

	for (int i = 0; i < _size; ++i)
	{
		pT[i] = p[i];
	}

	delete[] p;
	p = pT;
}

template<typename T>
void myvector<T>::resize(size_t n, const T& val /*= T()*/)
{
	reserve(n);

	for (int i = _size; i < _capacity; ++i)
	{
		p[i] = val;
	}

}

template<typename T>
typename myvector<T>::iterator myvector<T>::insert(const iterator& it, const T& val)
{
	if (_size == _capacity)
	{
		reserve(_size * 2);
	}

	for (int i = _size; i > it.pos; --i)
	{
		p[i] = p[i - 1];
	}

	p[it.pos] = val;

	return it;
}

template<typename T>
void myvector<T>::push_back(const T&& val)
{
	if (_size == _capacity)
	{
		reserve(_size * 2);
	}

	this->p[_size] = val;
	++_size;
}

template<typename T>
void myvector<T>::push_back(const T& val)
{
	if (_size == _capacity)
	{
		reserve(_size * 2);
	}

	this->p[_size] = val;
	++_size;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::erase(const iterator& sit, const iterator& eit)
{
	_size -= eit.pos - sit.pos;
	for (int i = eit.pos, j = sit.pos; i < size; ++i, ++j)
	{
		p[j] = p[i];
	}

	return sit;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::erase(const iterator& it)
{
	--_size;
	for (int i = it.pos; i < size - 1; ++i)
	{
		p[i] = p[i + 1];
	}

	return it;
}

template<typename T>
const T* myvector<T>::iterator::operator->() const
{
	return this->pv;
}

template<typename T>
T& myvector<T>::iterator::operator*() const
{
	return *(this->pv);
}

template<typename T>
bool myvector<T>::iterator::operator!=(const iterator& it) const noexcept
{
	return this->pos != it.pos;
}

template<typename T>
bool myvector<T>::iterator::operator==(const iterator& it) const noexcept
{
	return this->pos == it.pos;
}

template<typename T>
typename myvector<T>::iterator& myvector<T>::iterator::operator-=(size_t n)
{
	this->pv -= n;
	this->pos -= n;
	return *this;
}

template<typename T>
typename myvector<T>::iterator& myvector<T>::iterator::operator+=(size_t n)
{
	this->pv += n;
	this->pos += n;
	return *this;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::iterator::operator-(size_t n)
{
	auto ret = *this;
	ret -= n;
	return ret;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::iterator::operator+(size_t n)
{
	auto ret = *this;
	ret += n;
	return ret;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::iterator::operator--(int)
{
	auto ret = *this;
	this -= 1;
	return ret;
}

template<typename T>
typename myvector<T>::iterator& myvector<T>::iterator::operator--()
{
	this -= 1;
	return *this;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::iterator::operator++(int)
{
	auto ret = *this;
	*this += 1;
	return ret;
}

template<typename T>
typename myvector<T>::iterator& myvector<T>::iterator::operator++()
{
	*this += 1;
	return *this;
}


int main()
{
	myvector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;

	v.insert(v.begin(), 7);
	std::cout << *(v.begin() + 3) << std::endl;

	//v.erase(v.begin()+1);
	//v.pop_back();

	myvector<int>::iterator itr;

	auto test1 = v.begin();
	auto test2 = v.end();

	for (itr = v.begin(); itr != v.end(); ++itr)
		std::cout << *itr << ' ';
	std::cout << '\n';

	std::cout << "size: " << v.size() << '\n';
	std::cout << "capa: " << v.capacity() << '\n';

	return 0;
}