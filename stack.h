#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>

template <class type>
class stackCell {
private:
	stackCell<type> *next;
	stackCell<type> *prev;
	
	type data;


public:
	stackCell(type _data, stackCell<type> *_prev, stackCell<type> *_next);
	~stackCell();

	void	destroy();
	type&	getData();

	stackCell<type>* getNext() { return this->next; }
	stackCell<type>* getPrev() { return this->prev; }	
	void setNext(stackCell<type>* _cell) { this->next = _cell; }
	void setPrev(stackCell<type>* _cell) { this->prev = _cell; }
};

template <class type>
class stack {
private:
	size_t size;

	stackCell<type> *first;
	stackCell<type> *last;

public:
	stack();
	~stack();

	void push(type _object);
	void pushBottom(type _object);
	type pop();
	type popBottom();

	size_t getSize();

	type& operator[](size_t _number);
};

// Implementation

template <class type>
stackCell<type>::stackCell(type _data, stackCell<type> *_next, stackCell<type> *_prev) {
	this->data	= _data;
	this->next	= _next;
	this->prev	= _prev;
}

template <class type>
stackCell<type>::~stackCell() {
	if (this->next != NULL)
		this->next->setPrev(NULL);
	if (this->prev != NULL)
		this->prev->setNext(NULL);
}

template <class type>
void stackCell<type>::destroy() {
	if (this->prev != NULL)
		this->prev->setNext(this->next);
	if (this->next != NULL)
		this->next->setPrev(this->prev);
}

template <class type>
type& stackCell<type>::getData() {
	return this->data;
}

template <class type>
stack<type>::stack() {
	this->size	= 0;
	this->first	= NULL;
	this->last	= NULL;
}

template <class type>
stack<type>::~stack() {
	// TODO
}

template <class type>
void stack<type>::push(type _object) {
	this->last = new stackCell<type>(_object, this->last, NULL);
	if (!this->size)
		this->first = this->last;
	this->size++;
}

template <class type>
void stack<type>::pushBottom(type _object) {
	this->first = new stackCell<type>(_object, NULL, this->first);
	this->size++;
}

template <class type>
type stack<type>::pop() {
	type _temp = *this->last;
	this->last = _temp.prev;
	this->size--;
	return _temp.getData();
}

template <class type>
type stack<type>::popBottom() {
	type _temp = *this->first;
	this->first = _temp.next;
	this->size--;
	return _temp.getData();
}

template <class type>
size_t stack<type>::getSize() {
	return this->size;
}

template <class type>
type& stack<type>::operator[](size_t _number) {
	bool exp = _number < (this->size - _number - 1);
	stackCell<type> *iterator = exp ? this->first : this->last;
	for (register size_t i(0); i < size_t(exp ? _number : (const size_t)this->size - _number - 1); i++)
		iterator = exp ? iterator->getNext() : iterator->getPrev();
	return iterator->getData();
}

#endif //_STACK_H_