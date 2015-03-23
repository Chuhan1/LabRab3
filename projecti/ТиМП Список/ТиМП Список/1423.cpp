/** 
  *@file 1423.cpp
  *@version 1.0
  *@date 23/03/2015
  *@title Реализация списка
  */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Spisok
{
	int data;///информационное поле
Spisok *next;///указатель на следующий элемент
Spisok *pred;///указатель на предыдуший элемент
};
Spisok *head;
/** 
  *@func Функция добавления элемента
	 */
void AddSpisok(int position, int value)
{
	Spisok *node=new Spisok; ///создание нового элемента
node->data=value; ///присвоение элементу значения
if (head==NULL) ///если список пуст
{
 node->next=node; ///установка указателя next
 node->pred=node; ///установка указателя prev
 head=node; ///определяется голова списка
}
else
{
 Spisok *p=head;
for(int i=position; i>1; i--) p=p->next;
 p->pred->next=node;
 node->pred=p->pred;
 node->next=p; //добавление элемента
p->pred=node;
}
cout<<"\nElement dobavlen...\n";
}
/** 
  *@func Функция удаления элемента
	 */
void DeleteSpisok(int position)
{
 if (head==NULL) { cout<<"\nSpisok pust\n"; return; }
if (head==head->next) ///если это последний элемент в списке
{
delete head; ///удаление элемента
head=NULL;
}
else
{
 Spisok *a=head;
for (int i=position; i>1; i--) a=a->next;
if (a==head) head=a->next;
 a->pred->next=a->next; ///удаление элемента
a->next->pred=a->pred;
delete a;
}
cout<<"\nElement udalen...\n";

}
/** 
  *@func Функция печати списка
	 */
void PrintSpisok()
{
if (head==NULL) cout<<"Spisok pust\n";
else
{
 Spisok *a=head;
cout<<"\nElementi spiska: ";
do
{
cout<<a->data<<" ";
 a=a->next;
} while(a!=head); cout<<"\n";
}
}
void main()
{
	int index, value, N;
	char x;
	/** 
	*@brief Вводим количество действий со списком, далее выбираем либо добавление элементов либо удаление элементов. Затем для добавления вводим индекс и значение элемента. Для удаления вводим индекс элемента.
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
			cout<<"Vvedite index elementa = ";
			cin>>index;
			cout<<"Vvedite znachenie";
			cin>>value;
			AddSpisok(index,value);
			break;
		case 'd':
			cout<<"Vvedite index elementa = ";
			cin>>index;
			DeleteSpisok(index);
			break;
		default:
			goto metka;
		}
	}
	PrintSpisok();
	return;
}

