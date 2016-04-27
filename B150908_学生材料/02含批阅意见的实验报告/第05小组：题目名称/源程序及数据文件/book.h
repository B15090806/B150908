/* ①book.h文件的完整内容 */
#ifndef _BOOK             /*条件编译，防止重复包含的错误*/
#define _BOOK
#include <string.h>
#define NUM 10  
struct Book
{
	char title[20];             /*书名 */
	long number[20];            /*索引号 */
	int time;                 /*借阅次数 */
	int kc;                    /*该图书总数量*/
};
typedef struct Book Book;              /*定义图书常量，此处可以根据实际需要修改常量值*/
struct Student                   /*学生记录的数据域*/
{
		long num[10];              /*学号 */
		char name[20];        /*姓名 */
	    Book message;
		 
};typedef struct Student Student;

#define sizeBook sizeof(Book)      /*一条图书记录所需要的内存空间大小*/
#define sizeStudent sizeof(Student)      /*一个借阅人记录所需要的内存空间大小*/
int readBook(Book book[],int n);       /*读入书书籍名称*/
int readStudent(Student  *student, int n);          /*读入借阅人记录值，借阅人为0或读满规定条数记录时停止*/
void printBook( Book  *Book , int n);   /*输出所有书籍记录的值*/
void printStudent( Student  *student, int n);       /*输出所有借阅人记录的值*/
void sortBook(Book book[],int n,int condition);   /*选择法从大到小排序，按condition所规定的条件*/
void sortStuent(Student stu[],int n,int condition);  /*选择法排序，按condition条件由小到大排序*/
int larger(Book b1,Book b2,int condition);  /*根据condition条件比较两个Student记录的大小*/
int searchBook(Book book[],int n,Book b,int condition,int f[]) ;  /*根据条件找数组中与b相等的各元素*/
int searchStudent(Student stu[],int n,Student s,int condition,int f[ ]);  /*在stu数组中依condition条件查找*/
int addBook(Book book[],int n,Book b);                   /*向数组中增加一条图书信息*/
int deleteBook(Book book[],int n,Book b);                   /*从数组中删除一条图书信息*/
#endif