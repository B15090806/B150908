#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"
void printHead( )      /*��ӡͼ����Ϣ�ı�ͷ*/
{
printf("%ld%s%ld%s%d\n","������","����","ѧ��","����","���");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ͼ����Ϣ���� ********\n");
		printf("******** 3. ��������Ϣ���� ********\n");
		printf("******** 4. ��������ͳ��********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}
void peopleBase()      /*3����������Ϣ����˵�����*/
{      
	    printf("@@@@@@@@@ 1. �����������Ϣ��¼ @@@@@@@@\n");
		printf("@@@@@@@@@ 2. ɾ����������Ϣ��¼ @@@@@@@@\n");
		printf("@@@@@@@@@ 3. �޸Ľ�������Ϣ��¼ @@@@@@@@\n");
        printf("@@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}

void menuCount( )    /*4��ͳ�Ʋ˵�����*/
{
	    printf("&&&&&&&& 1. ����Ĵ������ &&&&&&&&\n");
		printf("&&&&&&&& 1. ����Ĵ������ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ��������ѯ   ########\n");
		printf("######## 2. �������Ų�ѯ   ########\n");
		printf("######## 3. ��������Ϣ��ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Book book[],int n)    	     /*�ú�����ɻ���ͼ����Ϣ����*/
/*�������Ž��в���ɾ���޸ģ������Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Book b;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readBook(&b,1);       /*����һ���������ͼ���¼*/
					 n=addBook(book,n,b);   /*���ú�������ͼ���¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&b.number);  /*����һ����ɾ����ͼ��������*/
					 n=deleteBook(book,n,b);   /*���ú���ɾ��ָ�������ŵ�ͼ���¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&b.number);  /*����һ�����޸ĵ�ͼ��������*/
				      t=searchBook(book,n,b,1,find) ; /*���ú�������ָ�������ŵ�ͼ���¼*/
				      if (t)                 /*����������ŵļ�¼����*/
					 {
						  readBook(&b,1);   /*����һ��������ͼ���¼��Ϣ*/
					      book[find[0]]=b;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����������ŵļ�¼������*/ 
 printf("this book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}
int baseManage1(Student student[],int n)    	     /*�ú�����ɽ����˻�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ� ѧ�Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Student s;
do
	    {   
         peopleBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
           printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readStudent(&s,1);       /*����һ��������Ľ����˼�¼*/
					 n=insertStudent(student,n,s);   /*���ú�����������˼�¼*/
					 break;
			   case 2:  printf("Input the student number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ����ѧ��*/
					 n=deleteStudent(student,n,s);   /*���ú���ɾ��ָ��ѧ�ŵĽ����˼�¼*/
					 break;
			   case 3:  printf("Input the student number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ�ѧ�ż�¼*/
				      t=searchStudent(student,n,s,1,find) ; /*���ú�������ָ��ѧ�ŵĽ����˼�¼*/
				      if (t)                 /*�����ѧ�ŵļ�¼����*/
					 {
						  readStudent(&s,1);   /*����һ�������Ľ����˼�¼��Ϣ*/
					      student[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*�����ѧ�õĽ����˼�¼������*/ 
 printf("this people is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}
void printBookTimes(char *b,double m[NUM][2],int k)   /*��ӡ���Ĵ���ͨ�ú�������countManage ����
                                                  /*��ʽ����k���������ͬ������*/
  { 
	int i;
	printf(b);
	for(i=0;i<NUM;i++)
	   printf("%d",m[i][k]);
    printf("\n");
  } 
void countManage(Book book[],int n)               /*�ú�����ɽ��Ĵ�����ͳ�ƹ���*/
{
		int choice;
		double mark[NUM][2];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printBookTimes("10�������߽��Ĵ�����:\n",mark,0);  /*�����ߴ���*/
				      break;
				case 2:   printBookTimes("��10�������ͽ��Ĵ�����:\n",mark,1);  /*�����ʹ���*/
				      break;
				
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Book book[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
    Book b;
    Student s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s title will be searched:\n");
				      scanf("%ld",&b.title);         /*�������ѯͼ���������*/
					  break;
				case 2:   printf("Input a book\'s number will be searched:\n");
				      scanf("%s",&b.number);	          /*�������ѯͼ�������*/		  
				      break;   
			    case 3:  printf(" search the informatiom of the readers"); 
			           scanf("%ld",&s.num);          /*�������ѯ�����˵�ѧ��*/ 
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchBook(book,n,b,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printBook(&book[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Book book[],Student student[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortBook(book,n,1);         /*�����Ĵ�����С�����˳�������¼*/ 
          	 printBook(book,n);          /*�����Ĵ�����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(book,n);    /* 2. ͼ�������Ϣ����*/
			   	     break;
			case 3: n=baseManage1(student,n);     /* 3. ��������Ϣ����*/
					break;
			case 4: countManage(book,n);     /* 4. ���Ĵ���ͳ��*/
					break;
			case 5: searchManage(book,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Book book[NUM];
		Student student[STU];               /*����ʵ��һά����洢ͼ���¼*/
      int choice,n,m;
	 n=readFile(book);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 m=readstudentFile(student);
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(book);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
         }
	  else if(!m)
	  	{
  		    m=createstudentfile(student);
  	     }	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(book,student,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortBook(book,n,1);                   /*�����ļ�ǰ���Ĵ�����С��������*/ 
	     saveFile(book,n);                   /*����������ļ�*/
      return 0;
}
