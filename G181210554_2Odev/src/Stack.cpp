/*@file  :Stack.cpp
* @description :Stack sinifi icin gereken metod govdelerini bulundurur.
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/
#include "Stack.h"
bool Stack::IsFull()
	{
		return length == capacity;
	}

void Stack::Reserve(int capacity)
{
	int* yeniDizi = new int[capacity];
	for (int i = 0; i < length; i++) {
		yeniDizi[i] = items[i];
	}
	if (items != NULL)
		delete[] items;
	items = yeniDizi;
	this->capacity = capacity;
}

Stack::Stack()
{
	items = NULL;
	head = -1;
	length = 0;
	capacity = 0;
	//basta O atiyoruz stack'e
	Push((int)'O');
}
bool Stack::IsEmpty()
{
	return head == -1;
}
void Stack::Push(const int& obj)
{
	if (IsFull()) { //fullse kapasitenin 2 kati kadar yer ayiriyoruz
		Reserve(max(1, 2 * capacity));
	}
	head++;
	items[head] = obj;
	length++;
}
int Stack::Pop()
{
	if (IsEmpty())
		return -1;
	int sonDeger = items[head];
	head--;
	length--;
	return sonDeger;
}
void Stack::Clear()
{
	head = -1;
	length = 0;
}
Stack::~Stack()
{
	if (items != NULL)
		delete[] items;
	items = NULL;
}
