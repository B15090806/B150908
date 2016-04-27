 /*③ file.h文件的内容如下：*/
#include <stdio.h>
#include <stdlib.h>
#include "book.h"        
int  createFile(Book book[])              /*建立初始的数据文件*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*指定好文件名，以写入方式打开*/
	{
	    printf("can not open book file !\n");         /*若打开失败，输出提示信息*/
	    exit(0);                           /*然后退出*/
    	}
	printf("input book's information:\n");
	n=readBook(book,NUM);                /*调用book.h中的函数读数据*/
fwrite(book,sizeBook,n,fp);                  /*将刚才读入的所有记录一次性写入文件*/
 	fclose(fp);
	 return n;
}
int readFile(Book book[ ] )                     /*将文件中的内容读出置于结构体数组book中*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\book.dat", "rb")) == NULL)  /*以读的方式打开指定文件*/
	{
	    printf("bookfile does not exist,create it first:\n");  /*如果打开失败输出提示信息*/
	    return 0;                              /*然后返回0*/
	}	 
    	fread(&book[i],sizeBook,1,fp);                   /*读出第一条记录*/
   	while(!feof(fp))                            /*文件未结束时循环*/
	{
		i++;
	    	fread(&book[i],sizeBook,1,fp);              /*再读出下一条记录*/
     }
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}
void saveFile(Book book[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("can not open  book file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(book,sizeBook,n,fp);        
	fclose(fp);                              /*关闭文件*/
}
int createstudentfile(Student student[])
{
     FILE *fq;
     int m;
	 if((fq=fopen("d:\\student.dat","wb"))==NULL)
	 {
 		printf("can not open student file !\n");
 		exit(0);
 	}
   printf("input borrower's information:\n");                        /*关闭文件*/
   m=readStudent(student,STU);
  fwrite(student,sizeStudent,m,fq);
  fclose(fq);
  return m;
}
int readstudentFile(Student student[ ] )                     /*将文件中的内容读出置于结构体数组book中*/
{
   	FILE *fq;
	int j=0;
	if((fq=fopen("d:\\student.dat", "rb")) == NULL)  /*以读的方式打开指定文件*/
	{
	    printf("studentfile does not exist,create it first:\n");  /*如果打开失败输出提示信息*/
	    return 0;                              /*然后返回0*/
	}	 
    	fread(&student[j],sizeStudent,1,fq);                   /*读出第一条记录*/
   	while(!feof(fq))                            /*文件未结束时循环*/
	{
		j++;
	    	fread(&student[j],sizeStudent,1,fq);              /*再读出下一条记录*/
     }
	fclose(fq);                                /*关闭文件*/
	return j;                                  /*返回记录条数*/
}
void savestudentFile(Student student[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fq;	
   	if((fq=fopen("d:\\student.dat", "wb")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("can not open student file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(student,sizeStudent,n,fq);        
	fclose(fq);                              /*关闭文件*/
}