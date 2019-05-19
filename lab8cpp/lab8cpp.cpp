
#include "pch.h"

#include <iostream>
using namespace std;


/*
* односвязный список
* реализация
*/


template<typename T>
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(T data);

	//добавление элемента в список по указанному индексу
	void insert(T data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();
	//удаление элемента после каждого положительного числа
	void delelem();


private:


	template<typename T>
	class Node
	{
	public:
		Node * pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}
//delelem-удаление  элемента после каждого положительно числа

template<typename T>
void List<T>::delelem()
{
	Node<T> *current = this->head;
	Node<T> *prev = current;
	bool del_next = false;
	while (current != nullptr)
	{
		if (del_next)
		{
			if (current->data <= 0) del_next = false;
			prev->pNext = current->pNext;
			delete[] current;
			current = prev->pNext;
		}
		else
		{
			if (current->data > 0)
				del_next = true;
			prev = current;
			current = current->pNext;
		}
	}
}



int main()
{

	setlocale(LC_ALL, "ru");


	List<int> lst;
	lst.push_front(5);
	lst.push_front(14);
	lst.push_front(-101);
	lst.push_front(42);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "delelem" << endl << endl;

	lst.delelem();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}
