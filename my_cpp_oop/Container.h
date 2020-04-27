#pragma once
#include <memory>

template <class T> 
class Container {

public:
	Container();
	Container(uint32_t capacity);
	Container(const Container<T> & anotherContainer);
	~Container();

	void add(T const & value);

	T& get(uint32_t index) const;

	void remove();

	void clear();

	uint32_t size() const {
		return m_size;
	}

	uint32_t capacity() const {
		return m_capacity;
	}

	bool isEmpty() const {
		return m_size == 0;
	}
 
private:
	uint32_t m_size;
	uint32_t m_capacity;
	char* m_buffer;
	void resize();
};

template<class T>
Container<T>::Container() {
	m_size = 0;
	m_capacity = 0;
	m_buffer = nullptr;
}

template<class T>
Container<T>::Container(uint32_t capacity) :
	m_size(0),
	m_capacity(capacity) {
		m_buffer = new char[sizeof(T) * capacity];
}

template<class T>
Container<T>::Container(const Container<T> & anotherContainer) :
	m_size(anotherContainer.m_size),
	m_capacity(anotherContainer.m_capacity),
	m_buffer(new char[sizeof(T) * m_capacity]) {
	for (uint32_t i = 0; i < anotherContainer.m_size; ++i) {
		new(m_buffer + i * sizeof(T)) T(anotherContainer.get(i));
	}
}

template<class T>
Container<T>::~Container() {
	clear();
	m_size = 0;
	m_capacity = 0;
	delete m_buffer;
}

template<class T>
void Container<T>::add(T const & value) {
	if (m_size >= m_capacity) {
		resize();
	}	
	new(m_buffer + m_size * sizeof(T)) T(value);
	++m_size;
}

template<class T>
T& Container<T>::get(uint32_t index) const {
	if (index >= m_size) {
		throw "wrong index";
	}
	return (T&) m_buffer[index * sizeof(T)];
}

template<class T>
void Container<T>::remove() {
	get(m_size-1).~T();
	--m_size;
}

template<class T>
void Container<T>::clear() {
	int count = m_size;
	for (int i = 0; i < count; i++) {
		remove();
	}
	m_size = 0;
}

template<class T>
void Container<T>::resize() {
	m_capacity = m_capacity * 2 + 1;
	char * increasedBuffer = new char[sizeof(T) * m_capacity];
	for (uint32_t i = 0; i < sizeof(T) * m_size; i++) {
		increasedBuffer[i] = m_buffer[i];
	}
	delete m_buffer;
	m_buffer = increasedBuffer;
}
