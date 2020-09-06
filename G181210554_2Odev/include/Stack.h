/*@file  :Stack.h
* @description :Stack sinifinin tanimlanmasi yapilan header dosyasi.
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/
#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include<algorithm>
using namespace std;

class Stack {
private:
	int* items;
	int head;
	int length;
	int capacity;
	bool IsFull();
	void Reserve(int capacity);
public:
	Stack();
	bool IsEmpty();
	void Push(const int& obj); //yigittan eleman cekme
	int Pop();  //yigita eleman atma
	void Clear();
	~Stack();
};
#endif