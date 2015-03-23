/** 
  *@file 12345.cpp
  *@version 1.0
  *@date 23/03/2015
  *@title Реализация очереди
  */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int n=5; ///размер очереди
struct Queue
{
int data[n]; ///массив данных
int last; ///указатель на начало
};
/** 
  *@func Функция создания очереди
	 */
void Creation(Queue *Q) 
{ Q->last=0; }
/** 
  *@func Функция проверки очереди на пустоту
	 */
bool Full(Queue *Q) 
{
if (Q->last==0) return true;
else return false;
}
/** 
  *@func Функция добавления элемента
	 */
void Add(Queue *Q) 
{
if (Q->last==n)
{ cout<<"\nOchered zapolnena\n"; return; }
int value;
cout<<"\nZnachenie = "; cin>>value;
 Q->data[Q->last++]=value;
cout<<endl<<"Element dobavlen v ochered\n\n";
}
/** 
  *@func Функция удаления элемента
	 */
void Delete(Queue *Q) 
{
for (int i=0; i<Q->last && i<n; i++) ///смещение элементов
Q->data[i]=Q->data[i+1]; Q->last--;
}
/** 
  *@func Функция печати очереди
	 */
int Print(Queue *Q) 
{ int i=0;
while(i != Q->last)
	{
		cout<<Q->data[i]<<" ";
	 i++;}
return 0;
}
/** 
  *@func Главная функция
	 */
void main() 
{
Queue Q;
Creation(&Q);
int N;
char x;
	/** 
	*@brief Вводим количество действий над очередью. Выбираем между добавлением и удалением файла
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
			Add(&Q); break;
		case 'd':
			if (Full(&Q)) cout<<endl<<"Ochered pusta\n";
				else
				{
					Delete(&Q);
					cout<<endl<<"Element udalen iz ocheredi\n";
				} break;
			default:
			goto metka;
		}
	}
if (Full(&Q)) cout<<endl<<"Ochered pusta\n";
else
	{
		Print(&Q);
	}
return;
}

