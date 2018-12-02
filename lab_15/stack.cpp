//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// stack.cpp
//
#include "stack.h"

stack::~stack() {}

bool d_stack::is_empty()
{
    return data.count() == 0;
}

void d_stack::push(const datatype & x)
{
    data.append(x);
}

void d_stack::pop()
{
    if (is_empty()) return;    
    data.resize(data.count() - 1);
}

stack::datatype d_stack::top()
{
    if (is_empty()) 
        throw std::out_of_range("Попытка получить элемент из пустого стека");
    return data[data.count() - 1];
}

std::ostream & operator<<(std::ostream & os, const d_stack & s)
{
	os << s.data.count();
	for (int i = 0; i < s.data.count(); ++i)
		os << s.data[i]<<" ";
	return os;
}

void coppy(l_stack::node * is, l_stack::node *& to)
{
	if (is== nullptr)
	{
		to = nullptr;
		return;
	}
	l_stack::node *p = new l_stack::node;
	p->data = is->data;
	p->next = nullptr;
	to = p;
	coppy(is->next, to->next);
}

void delete_list(l_stack::node *& is)
{
	l_stack::node *tmp;
	while (is!=nullptr) 
	{
		tmp = is->next;
		delete is;
		is = tmp;
	}
	
}

void edd_list(l_stack::node *& is, const l_stack::datatype & x)
{
	if (is == nullptr)
	{
		l_stack::node *p = new l_stack::node;
		p->data = x;
		p->next = nullptr;
		is = p;
		return;
	}
	l_stack::node *p = new l_stack::node;
	p->data = x;
	p->next = is;
	is = p;

}

std::ostream & operator<<(std::ostream & os, const l_stack & s)
{

	l_stack:: node *tmp = s.begin;
	while (tmp)
	{
		os << tmp->data << " ";
		tmp=tmp->next;
	}
	return os;
}






l_stack::l_stack(const l_stack & s)
{
	coppy(s.begin, this->begin);

}

l_stack & l_stack::operator=(const l_stack & s)
{
	coppy(s.begin, this->begin);
	return *this;
}

l_stack::~l_stack()
{
	delete_list(this->begin);
}

bool l_stack::is_empty()
{
	return this->begin == nullptr;
}

void l_stack::push(const datatype & x)
{
	edd_list(begin, x);
}

void l_stack::pop()
{

	node *tmp = begin->next;
	
	delete begin;
	begin = nullptr;
	begin = tmp;
	
}

l_stack:: datatype l_stack::top()
{
	node *tmp = begin;
	while (!tmp->next) tmp= tmp->next;
	return tmp->data;
}
