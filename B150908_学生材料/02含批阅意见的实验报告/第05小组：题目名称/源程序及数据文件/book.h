#ifndef _BOOK             /*�������룬��ֹ�ظ������Ĵ���*/
#define _BOOK
#include <string.h>
#define NUM 3 
#define STU 3 
struct Book
{
	char title[20];             /*���� */
	long number;            /*������ */
	int time;                 /*���Ĵ��� */
	int kc;                    /*��ͼ��������*/
};
typedef struct Book Book;              /*����ͼ�鳣�����˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Student                   /*ѧ����¼��������*/
{
		long num;              /*ѧ�� */
		char name[20];        /*���� */
	    Book message;
		 
};typedef struct Student Student;

#define sizeBook sizeof(Book)      /*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/
#define sizeStudent sizeof(Student)      /*һ�������˼�¼����Ҫ���ڴ�ռ��С*/
int readBook(Book book[],int n);       /*�������鼮����*/
void printBook( Book  *Book , int n);   /*��������鼮��¼��ֵ*/
int equal(Book b1,Book b2,int condition);/*�Ƚ�ͼ���¼�Ƿ���ͬ*/
int larger(Book b1,Book b2,int condition);  /*����condition�����Ƚ�����ͼ�������ŵĴ�С*/
void sortBook(Book book[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/
int searchBook(Book book[],int n,Book b,int condition,int f[]) ;  /*������������������b��ȵĸ�Ԫ��*/
int addBook(Book book[],int n,Book b);                   /*������������һ��ͼ����Ϣ*/
int deleteBook(Book book[],int n,Book b);                   /*��������ɾ��һ��ͼ����Ϣ*/
int readStudent(Student  student[], int n);          /*��������˼�¼ֵ��������Ϊ0������涨������¼ʱֹͣ*/
void printStudent( Student  *student, int n);       /*������н����˼�¼��ֵ*/
int equal1(Student s1,Student s2,int condition);/*�Ƚ�ѧ����¼�Ƿ���ͬ*/
void sortStudent(Student stu[],int n,int condition);  /*ѡ�����򣬰�condition������С��������*/
int searchStudent(Student stu[],int n,Student s,int condition,int f[ ]);  /*��stu��������condition��������*/
int insertStudent(Student student[],int n,Student s);  /*������������һ��ѧ����Ϣ*/ 
int deleteStudent(Student student[],int n,Student s);
#endif