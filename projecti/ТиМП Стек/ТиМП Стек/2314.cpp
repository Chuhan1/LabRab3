/** 
  *@file 2314.cpp
  *@version 1.0
  *@date 23/03/2015
  *@title Реализация стека
  */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int n=5;
struct Stack
{
int A[n];
int count;
};
/** 
  *@func Функция создания стека
   */
void Creation(Stack *p)
{ p->count=0; }
/** 
  *@func Функция проверки стека на пустоту
   */
int Full(Stack *p)
{
if (p->count==0) return 1;
else if (p->count==n) return -1;
else return 0;
}
/** 
  *@func Функция добавления элемента в стек
   */
void Add(Stack *p)
{
int value;
cout<<"Vvedite element = "; cin>>value;
 p->A[p->count]=value;
 p->count++;
}
/** 
  *@func Функция удаления элемента из стека
   */
void Delete(Stack *p)
{ p->count--; }
/** 
  *@func Функция печати стека
   */
int Print(Stack *p)
{ while(p->count !=0)
 {cout<<p->A[p->count-1]<<" ";
	p->count--;} 
return 0;
 }
/** 
  *@func Основная функция
   */
void main()
{
 Stack s;
 Creation(&s);
	int N;
	char x;
	/** 
	*@brief Вводим количество действий над стеком. Выбираем между добавлением и удалением файла
*/
	cout<<"Vvedite kolichestvo deistvij"<<endl;
	cin>>N; 
	cout<<"Vvedite a dlja dobavlenija elementa"<<endl;
	cout<<"Vvedite d dlja udalenija elementa"<<endl;
	for(int i=0;i<N;i++)
	{
		metka:
		cout<<"Vi vveli= ";
		cin>>x;
		switch(x)
		{
		case 'a': 
			if (Full(&s)==-1) cout<<endl<<"Stek zapolnen\n\n";
			else
				{
					Add(&s);
					cout<<endl<<"Element dobavlen v stek\n\n";
				} break;
		case 'd':
			if (Full(&s)==1) cout<<endl<<"Stek pust\n\n";
			else
			{
				Delete(&s);
				cout<<endl<<"Element udalen iz stecka\n\n";
			} break;
			default:
			goto metka;
		}
	}
	if (Full(&s)==1) cout<<endl<<"Stek pust\n\n";
else
	{
Print(&s);
	}
	return;
}