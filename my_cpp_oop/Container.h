#pragma once

template <class T> 
class Container {

public:

	Container();
	Container(uint32_t capacity);
	Container(const Container<T> & anotherContainer);
	~Container();

	void add(T const& value);

	T& get(uint32_t index);

	T& pop();

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

	T* m_elements;

	void resize();
};

template<class T>
Container<T>::Container() {
	m_size = 0;
	m_capacity = m_size*2;
	m_elements = nullptr;
}

template<class T>
Container<T>::Container(uint32_t capacity) {
	m_size = 0;
	m_capacity = capacity;
	m_elements = new T[capacity]();
}

template<class T>
Container<T>::Container(const Container<T> & anotherContainer):
	m_size(anotherContainer.m_size),
	m_capacity(anotherContainer.m_capacity),
	m_elements(new T[m_capacity]) {
	for (uint32_t i = 0; i < m_size; i++) {
		m_elements[i] = anotherContainer.m_elements[i];
	}
}

template<class T>
Container<T>::~Container() {
	m_size = 0;
	m_capacity = 0;
	delete m_elements;
}

template<class T>
void Container<T>::add(T const & value) {
	if (m_size > m_capacity) {
		resize();
	}
	m_elements[m_size] = value;
	++m_size;
}

template<class T>
T& Container<T>::get(uint32_t index) {
	if (index >= m_size) {
		throw exception("wrong index");
	}
	return m_elements[index];
}

template<class T>
T & Container<T>::pop() {
	T result = m_elements[--m_size];
	m_elements[m_size].~T();
	m_elements[m_size] = NULL;
	return result;
}

template<class T>
void Container<T>::clear() {
	int count = m_size;
	for (int i = 0; i < count; i++) {
		pop();
	}
	m_size = 0;
}

template<class T>
void Container<T>::resize() {
	m_capacity = m_capacity * 2;
	T* increasedArray = new T[m_capacity];
	for (uint32_t i = 0; i < m_size; i++) {
		increasedArray[i] = m_elements[i];
	}
	m_elements = increasedArray;
}







