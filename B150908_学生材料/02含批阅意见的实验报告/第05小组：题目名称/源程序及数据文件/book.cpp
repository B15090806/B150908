/*��book.c�ļ�����������*/
#include "book.h"
#include <stdio.h>
#include <string.h>
int readBook(Book  *book,int n )          /*����ͼ���¼ֵ��ͼ��Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book's information\n");
		printf("num:  ");
	     scanf("%ld", &book[i].number);
		if (book[i].number==0) break;
		printf("name: ");
		scanf("%s",book[i].title);	
		printf("�����Ȿ�����������:\n");
		scanf("%d",&book[i].kc);	
	} 
	return i;
}
void printBook ( Book  *book , int n)       /*�������ͼ���¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", book[i].number);
		printf("%8s", book[i].title);
	    printf("%5d\n",book[i].kc);
	}
}
int equal(Book b1,Book b2,int condition)  /*����ж�����ͼ���¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�������*/
		return b1.number==b2.number;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(b1.title,b2.title)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����ȽϿ��*/
	     return b1.kc==b2.kc;
	else return 1;                       /*�����������1*/
} 
int larger(Book b1,Book b2,int condition)   /*����condition�����Ƚ������ŵĴ�С*/
{
	if(condition==1)
		return b1.number>b2.number;
	else return 1;
}
void sortBook(Book book[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Book t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(book[minpos],book[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=book[i];
			book[i]=book[minpos];
			book[minpos]=t;
		}
	}
}
int deleteBook(Book book[],int n,Book b)            /*��������ɾ��ָ�������ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(book[i],b,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(book[i],b,1)����*/ 
		book[j]=book[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
int searchBook(Book book[],int n,Book b,int condition,int f[ ])  /*��book��������condition��������*/
/*��b��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(book[i],b,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}
int addBook(Book book[],int n,Book b)              /*��book�������������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortBook(book,n,1);                            /*�Ȱ�����������*/
	for (i=n-1;i>=0;i--)                          /*�������Ŵ�С��������*/
	{
		if (!larger(book[i],b,1))                    /*���b���ڵ�ǰԪ��book[i]�����˳�ѭ��*/
		break;
		book[i+1]=book[i];                         /*����Ԫ��book[i]����һ��λ��*/
	}
	book[i+1]=b;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}
int readStudent(Student  *student, int n)          /*��������˼�¼ֵ��������Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one borrower's information\n");
		printf("code:  ");
	     scanf("%ld", &student[i].num);
		if (student[i].num==0) break;
		printf("name: ");
		scanf("%s",&student[i].name);	
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}
void printStudent ( Student  *student, int n)       /*������н����˼�¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", student[i].num);
		printf("%8s", student[i].name);
		printf("%s  %ld",student[i].message.title,student[i].message.number);
	}
}
int equal1(Student s1,Student s2,int condition)
{
  if(condition==1)
  return s1.num==s2.num;
  else  return 1;
 }
int larger(Student s1,Student s2,int condition)
{ 
   if(condition==1)
         return s1.num>s2.num;
   else return 1;
 }
void sortStudent(Student stu[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Student t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(stu[minpos],stu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=stu[i];
			stu[i]=stu[minpos];
			stu[minpos]=t;
		}
	}
}
int searchStudent(Student stu[],int n,Student s,int condition,int f[ ])  /*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal1(stu[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}
int insertStudent(Student student[],int n,Student s)              /*��student��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortStudent(student,n,1);                              /*�Ȱ�ѧ������*/
	for(i=0;i<n;i++)
  	{
	 if(equal1(student[i],s,1))
	 {
           printf("This record exist,can not insert");
	   }
	  }
        for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(student[i],s,1))                    /*���s���ڵ�ǰԪ��student[i]�����˳�ѭ��*/
		break;
		student[i+1]=student[i];                         /*����Ԫ��student[i]����һ��λ��*/
	}
	student[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}
int deleteStudent(Student student[],int n,Student s)        /*��������ɾ��ָ�������ŵ�һ��Ԫ��*/
{
  int i,j;
  for(i=0;i<n;i++)                       /*Ѱ�Ҵ�ɾ����Ԫ��*/
     if(equal1(student[i],s,1))       /*����ҵ����Ԫ�����˳�ѭ��*/                   
     break;                               /*����Ҳ�����ɾ����Ԫ��*/
    if(i==n);
    {
      printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
      return n;
      }
      for (j=i;j<n-1;j++)                          /*�˴���������Ϊi<n��equal(book[i],b,1)����*/
         student[j]=student[j+1];                    /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
         n--;                                        /*Ԫ�ظ������ټ�1*/
         return n;                                 /*�������и���*/
 }