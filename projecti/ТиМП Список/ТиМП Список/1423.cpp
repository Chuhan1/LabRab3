/** 
  *@file 1423.cpp
  *@version 1.0
  *@date 23/03/2015
  *@title ���������� ������
  */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Spisok
{
	int data;///�������������� ����
Spisok *next;///��������� �� ��������� �������
Spisok *pred;///��������� �� ���������� �������
};
Spisok *head;
/** 
  *@func ������� ���������� ��������
	 */
void AddSpisok(int position, int value)
{
	Spisok *node=new Spisok; ///�������� ������ ��������
node->data=value; ///���������� �������� ��������
if (head==NULL) ///���� ������ ����
{
 node->next=node; ///��������� ��������� next
 node->pred=node; ///��������� ��������� prev
 head=node; ///������������ ������ ������
}
else
{
 Spisok *p=head;
for(int i=position; i>1; i--) p=p->next;
 p->pred->next=node;
 node->pred=p->pred;
 node->next=p; //���������� ��������
p->pred=node;
}
cout<<"\nElement dobavlen...\n";
}
/** 
  *@func ������� �������� ��������
	 */
void DeleteSpisok(int position)
{
 if (head==NULL) { cout<<"\nSpisok pust\n"; return; }
if (head==head->next) ///���� ��� ��������� ������� � ������
{
delete head; ///�������� ��������
head=NULL;
}
else
{
 Spisok *a=head;
for (int i=position; i>1; i--) a=a->next;
if (a==head) head=a->next;
 a->pred->next=a->next; ///�������� ��������
a->next->pred=a->pred;
delete a;
}
cout<<"\nElement udalen...\n";

}
/** 
  *@func ������� ������ ������
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
	*@brief ������ ���������� �������� �� �������, ����� �������� ���� ���������� ��������� ���� �������� ���������. ����� ��� ���������� ������ ������ � �������� ��������. ��� �������� ������ ������ ��������.
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

