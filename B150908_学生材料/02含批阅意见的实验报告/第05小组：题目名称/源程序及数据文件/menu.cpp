#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"
void printHead( )      /*打印图书信息的表头*/
{
printf("%ld%s%ld%s%d\n","索引号","书名","学号","姓名","库存");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 图书信息管理 ********\n");
		printf("******** 3. 借阅人信息管理 ********\n");
		printf("******** 4. 借阅数据统计********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}
void peopleBase()      /*3、借阅人信息管理菜单函数*/
{      
	    printf("@@@@@@@@@ 1. 插入借阅人信息记录 @@@@@@@@\n");
		printf("@@@@@@@@@ 2. 删除借阅人信息记录 @@@@@@@@\n");
		printf("@@@@@@@@@ 3. 修改借阅人信息记录 @@@@@@@@\n");
        printf("@@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}

void menuCount( )    /*4、统计菜单函数*/
{
	    printf("&&&&&&&& 1. 求借阅次数最高 &&&&&&&&\n");
		printf("&&&&&&&& 1. 求借阅次数最低 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按书名查询   ########\n");
		printf("######## 2. 按索引号查询   ########\n");
		printf("######## 3. 借阅人信息查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Book book[],int n)    	     /*该函数完成基本图书信息管理*/
/*按索引号进行插入删除修改，索引号不能重复*/
{  
		int choice,t,find[NUM];
     Book b;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readBook(&b,1);       /*读入一条待插入的图书记录*/
					 n=addBook(book,n,b);   /*调用函数插入图书记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&b.number);  /*读入一个待删除的图书索引号*/
					 n=deleteBook(book,n,b);   /*调用函数删除指定索引号的图书记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&b.number);  /*读入一个待修改的图书索引号*/
				      t=searchBook(book,n,b,1,find) ; /*调用函数查找指定索引号的图书记录*/
				      if (t)                 /*如果该索引号的记录存在*/
					 {
						  readBook(&b,1);   /*读入一条完整的图书记录信息*/
					      book[find[0]]=b;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该索引号的记录不存在*/ 
 printf("this book is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}
int baseManage1(Student student[],int n)    	     /*该函数完成借阅人基本信息管理*/
/*按学号进行插入删除修改， 学号不能重复*/
{  
		int choice,t,find[NUM];
     Student s;
do
	    {   
         peopleBase( );                  /*显示对应的二级菜单*/
           printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readStudent(&s,1);       /*读入一条待插入的借阅人记录*/
					 n=insertStudent(student,n,s);   /*调用函数插入借阅人记录*/
					 break;
			   case 2:  printf("Input the student number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的学号*/
					 n=deleteStudent(student,n,s);   /*调用函数删除指定学号的借阅人记录*/
					 break;
			   case 3:  printf("Input the student number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的学号记录*/
				      t=searchStudent(student,n,s,1,find) ; /*调用函数查找指定学号的借阅人记录*/
				      if (t)                 /*如果该学号的记录存在*/
					 {
						  readStudent(&s,1);   /*读入一条完整的借阅人记录信息*/
					      student[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该学好的借阅人记录不存在*/ 
 printf("this people is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}
void printBookTimes(char *b,double m[NUM][2],int k)   /*打印借阅次数通用函数，被countManage 调用
                                                  /*形式参数k代表输出不同的内容*/
  { 
	int i;
	printf(b);
	for(i=0;i<NUM;i++)
	   printf("%d",m[i][k]);
    printf("\n");
  } 
void countManage(Book book[],int n)               /*该函数完成借阅次数的统计功能*/
{
		int choice;
		double mark[NUM][2];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printBookTimes("10本书的最高借阅次数是:\n",mark,0);  /*输出最高次数*/
				      break;
				case 2:   printBookTimes("·10本书的最低借阅次数是:\n",mark,1);  /*输出最低次数*/
				      break;
				
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Book book[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
    Book b;
    Student s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s title will be searched:\n");
				      scanf("%ld",&b.title);         /*输入待查询图书的索引号*/
					  break;
				case 2:   printf("Input a book\'s number will be searched:\n");
				      scanf("%s",&b.number);	          /*输入待查询图书的书名*/		  
				      break;   
			    case 3:  printf(" search the informatiom of the readers"); 
			           scanf("%ld",&s.num);          /*输入待查询借阅人的学号*/ 
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchBook(book,n,b,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printBook(&book[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Book book[],Student student[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortBook(book,n,1);         /*按借阅次数由小到大的顺序排序记录*/ 
          	 printBook(book,n);          /*按借阅次数由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(book,n);    /* 2. 图书基本信息管理*/
			   	     break;
			case 3: n=baseManage1(student,n);     /* 3. 借阅人信息管理*/
					break;
			case 4: countManage(book,n);     /* 4. 借阅次数统计*/
					break;
			case 5: searchManage(book,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Book book[NUM];
		Student student[STU];               /*定义实参一维数组存储图书记录*/
      int choice,n,m;
	 n=readFile(book);                  /*首先读取文件，记录条数返回赋值给n*/
	 m=readstudentFile(student);
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(book);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
         }
	  else if(!m)
	  	{
  		    m=createstudentfile(student);
  	     }	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(book,student,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortBook(book,n,1);                   /*存入文件前借阅次数由小到大排序*/ 
	     saveFile(book,n);                   /*将结果存入文件*/
      return 0;
}
