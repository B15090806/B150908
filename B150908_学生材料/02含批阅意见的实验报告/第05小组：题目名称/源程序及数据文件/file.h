 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "book.h"        
int  createFile(Book book[])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open book file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input book's information:\n");
	n=readBook(book,NUM);                /*����book.h�еĺ���������*/
fwrite(book,sizeBook,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);
	 return n;
}
int readFile(Book book[ ] )                     /*���ļ��е����ݶ������ڽṹ������book��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\book.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("bookfile does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&book[i],sizeBook,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&book[i],sizeBook,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}
void saveFile(Book book[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open  book file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(book,sizeBook,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
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
   printf("input borrower's information:\n");                        /*�ر��ļ�*/
   m=readStudent(student,STU);
  fwrite(student,sizeStudent,m,fq);
  fclose(fq);
  return m;
}
int readstudentFile(Student student[ ] )                     /*���ļ��е����ݶ������ڽṹ������book��*/
{
   	FILE *fq;
	int j=0;
	if((fq=fopen("d:\\student.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("studentfile does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&student[j],sizeStudent,1,fq);                   /*������һ����¼*/
   	while(!feof(fq))                            /*�ļ�δ����ʱѭ��*/
	{
		j++;
	    	fread(&student[j],sizeStudent,1,fq);              /*�ٶ�����һ����¼*/
     }
	fclose(fq);                                /*�ر��ļ�*/
	return j;                                  /*���ؼ�¼����*/
}
void savestudentFile(Student student[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fq;	
   	if((fq=fopen("d:\\student.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open student file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(student,sizeStudent,n,fq);        
	fclose(fq);                              /*�ر��ļ�*/
}