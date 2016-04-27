#ifndef _BOOK             /*条件编译，防止重复包含的错误*/
#define _BOOK
#include <string.h>
#define NUM 3 
#define STU 3 
struct Book
{
	char title[20];             /*书名 */
	long number;            /*索引号 */
	int time;                 /*借阅次数 */
	int kc;                    /*该图书总数量*/
};
typedef struct Book Book;              /*定义图书常量，此处可以根据实际需要修改常量值*/
struct Student                   /*学生记录的数据域*/
{
		long num;              /*学号 */
		char name[20];        /*姓名 */
	    Book message;
		 
};typedef struct Student Student;

#define sizeBook sizeof(Book)      /*一条图书记录所需要的内存空间大小*/
#define sizeStudent sizeof(Student)      /*一个借阅人记录所需要的内存空间大小*/
int readBook(Book book[],int n);       /*读入书书籍名称*/
void printBook( Book  *Book , int n);   /*输出所有书籍记录的值*/
int equal(Book b1,Book b2,int condition);/*比较图书记录是否相同*/
int larger(Book b1,Book b2,int condition);  /*根据condition条件比较两本图书索引号的大小*/
void sortBook(Book book[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/
int searchBook(Book book[],int n,Book b,int condition,int f[]) ;  /*根据条件找数组中与b相等的各元素*/
int addBook(Book book[],int n,Book b);                   /*向数组中增加一条图书信息*/
int deleteBook(Book book[],int n,Book b);                   /*从数组中删除一条图书信息*/
int readStudent(Student  student[], int n);          /*读入借阅人记录值，借阅人为0或读满规定条数记录时停止*/
void printStudent( Student  *student, int n);       /*输出所有借阅人记录的值*/
int equal1(Student s1,Student s2,int condition);/*比较学生记录是否相同*/
void sortStudent(Student stu[],int n,int condition);  /*选择法排序，按condition条件由小到大排序*/
int searchStudent(Student stu[],int n,Student s,int condition,int f[ ]);  /*在stu数组中依condition条件查找*/
int insertStudent(Student student[],int n,Student s);  /*向数组中增加一条学生信息*/ 
int deleteStudent(Student student[],int n,Student s);
#endif