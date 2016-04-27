/* ��book.h�ļ����������� */
#ifndef _BOOK             /*�������룬��ֹ�ظ������Ĵ���*/
#define _BOOK
#include <string.h>
#define NUM 10  
struct Book
{
	char title[20];             /*���� */
	long number[20];            /*������ */
	int time;                 /*���Ĵ��� */
	int kc;                    /*��ͼ��������*/
};
typedef struct Book Book;              /*����ͼ�鳣�����˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Student                   /*ѧ����¼��������*/
{
		long num[10];              /*ѧ�� */
		char name[20];        /*���� */
	    Book message;
		 
};typedef struct Student Student;

#define sizeBook sizeof(Book)      /*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/
#define sizeStudent sizeof(Student)      /*һ�������˼�¼����Ҫ���ڴ�ռ��С*/
int readBook(Book book[],int n);       /*�������鼮����*/
int readStudent(Student  *student, int n);          /*��������˼�¼ֵ��������Ϊ0������涨������¼ʱֹͣ*/
void printBook( Book  *Book , int n);   /*��������鼮��¼��ֵ*/
void printStudent( Student  *student, int n);       /*������н����˼�¼��ֵ*/
void sortBook(Book book[],int n,int condition);   /*ѡ�񷨴Ӵ�С���򣬰�condition���涨������*/
void sortStuent(Student stu[],int n,int condition);  /*ѡ�����򣬰�condition������С��������*/
int larger(Book b1,Book b2,int condition);  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
int searchBook(Book book[],int n,Book b,int condition,int f[]) ;  /*������������������b��ȵĸ�Ԫ��*/
int searchStudent(Student stu[],int n,Student s,int condition,int f[ ]);  /*��stu��������condition��������*/
int addBook(Book book[],int n,Book b);                   /*������������һ��ͼ����Ϣ*/
int deleteBook(Book book[],int n,Book b);                   /*��������ɾ��һ��ͼ����Ϣ*/
#endif