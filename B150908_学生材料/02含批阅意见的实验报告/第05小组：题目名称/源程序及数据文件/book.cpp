/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>

int readBook(Book  *book , int n)          /*读入图书记录值，图书为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book's information\n");
		printf("num:  ");
	     scanf("%ld", &book[i].number);
		if (book[i].number==0) break;
		printf("name: ");
		scanf("%s",&book[i].title);	
		printf("输入这本书的数量总数:\n");
		scanf("%d",&book[i].kc);	
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printBook ( Book  *book , int n)       /*输出所有图书记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", book[i].number);
		printf("%8s", book[i].title);
	    printf("%5d\n",book[i].kc);
	}
}
int equal(Book b1,Book b2,int condition)  /*如何判断两个图书记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较索引号*/
		return b1.number==b2.number;
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/
     {
	     if (strcmp(b1.title,b2.title)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较库存*/
	     return b1.kc==b2.kc;
	else return 1;                       /*其余情况返回1*/
} 
int larger(Book b1,Book b2,int condition)  /*根据condition条件比较两个图书借阅次数*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较借阅次数*/
		return b1.time>b2.time;	
	else return 1; /*其余情况返回1*/
}
int smaller(Book b1,Book b2,int condition)  /*根据condition条件比较两个图书借阅次数*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较借阅次数*/
		return b1.time<b2.time;	
	else return 1; /*其余情况返回1*/
}
void caluTime(int m[],Book book[],int n)
{
   int i,j,*p;
   for(i=0;i<NUM;i++)
   {
   	m[i]=book[0].time;
   	for(j=1;j<n;j++)
  	   if(m[i]<book[j].time)
	   	  m[i]=book[j].time;
   }
   for(i=0;i<NUM;i++)
   {
   	*p=book[j].time;
   	for(j=1;j<n;j++)
   	  if(*p>book[j].time)
   	     *p=book[j].time;
   }	
} 
void reverse(Book book[],int n)             /*数组元素逆置*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=book[i];
		book[i]=book[n-1-i];
		book[n-1-i]=temp;
	}
}
void sortBook(Book book[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos,maximum;                      /*minpos用来存储本趟最小元素所在的下标*/
	Book t,k;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (smaller(book[maximum],book[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=book[i];
			book[i]=book[minpos];
			book[minpos]=t;
		}
	 for(i=0;i<n-1;i++)
	 {
 		maximum=i;
 		for(j=i+1;j<n;j++)
 		  if(larger(book[minpos],book[j],condition))
 		      maximum=j;
 	}
	}
}
int searchBook(Book book[],int n,Book b,int condition,int f[ ])  /*在book数组中依condition条件查找*/
/*与b相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(book[i],b,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}
int addBook(Book book[],int n,Book b)              /*向book数组中依索引号递增插入一个元素s*/
{
	int i;
	sortBook(book,n,1);                            /*先按索引号排序*/
	for (i=n-1;i>=0;i--)                          /*按索引号从小到大有序*/
	{
		if (!larger(book[i],b,1))                    /*如果b大于当前元素book[i]，则退出循环*/
		break;
		book[i+1]=book[i];                         /*否则元素book[i]后移一个位置*/
	}
	book[i+1]=b;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}
int deleteBook(Book book[],int n,Book b)            /*从数组中删除指定学号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(book[i],b,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(book[i],b,1)成立*/ 
		book[j]=book[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
int readStudent(Student  *student, int n)          /*读入借阅人记录值，借阅人为0或读满规定条数记录时停止*/
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
	return i;                         /*返回实际读入的记录条数*/
}
void printStudent ( Student  *student, int n)       /*输出所有借阅人记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", student[i].num);
		printf("%8s", student[i].name);
		printf("%s  %ld",student[i].message.title,student[i].message.number);
	}
}
int equal(Student s1,Student s2,int condition)
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
void reverse1(Student student[],int n)
{
  int i;
  Student temp;
  for(i=0;i<n/2;i++)
   {
     temp=student[i];
      student[i]=student[n-1-i];
      student[n-1-i]=temp;
     }
 }
void sortStudent(Student stu[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Student t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(stu[minpos],stu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=stu[i];
			stu[i]=stu[minpos];
			stu[minpos]=t;
		}
	}
}
int searchStudent(Student stu[],int n,Student s,int condition,int f[ ])  /*在stu数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(stu[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}
int insertStudent(Student student[],int n,Student s)              /*向student数组中依学号递增插入一个元素s*/
{
	int i;
	sortStudent(student,n,1);                              /*先按学号排序*/
	for(i=0;i<n;i++)
  	{
	 if(equal(student[i],s,1))
	 {
           printf("This record exist,can not insert");
	   }
	  }
        for (i=n-1;i>=0;i--)                          /*按学号从小到大有序*/
	{
		if (!larger(student[i],s,1))                    /*如果s大于当前元素student[i]，则退出循环*/
		break;
		student[i+1]=student[i];                         /*否则元素student[i]后移一个位置*/
	}
	student[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}
int deleteStudent(Student student[],int n,Student s)
{
  int i,j;
  for(i=0;i<n;i++)
     if(equal(student[i],s,1))
     break;
    if(i==n);
    {
      printf("This record does not exist!\n");
      return n;
      }
      for (j=i;j<n-1;j++)
         student[j]=student[j+1];
         n--;
         return n;
 }
