/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"owner.h"

void printHead( )      /*打印车主信息的表头*/
{
printf("%8s%10s%8s%6s%10s%6s\n","车牌号","姓名","性别","单次时间","总时间","平均费用");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 车主信息管理 ********\n");
		printf("******** 4. 停车信息统计 ********\n");
		printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 添加车主信息 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除车主信息 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改车主信息 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )     /*3、车主信息管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算停车总时间 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 计算平均停车费用 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、停车信息统计菜单函数*/
{
		printf("&&&&&&&& 1. 计算停车最长时间 &&&&&&&&\n");
		printf("&&&&&&&& 2. 计算停车最短时间 &&&&&&&&\n");
		printf("&&&&&&&& 3. 计算停车平均平均分 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按车牌号查询   ########\n");
		printf("######## 2. 按姓名查询   ########\n");
		/*后面的根据名次查询删除*/
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Owner own[],int n)    	     /*该函数完成基本信息管理*/
/*按车牌号进行插入删除修改，车牌号不能重复*/
{  
		int choice,t,find[NUM];
     Owner s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readOwn(&s,1);       /*读入一条待插入的车主记录*/
					 n=insertOwn(own,n,s);   /*调用函数插入车主记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的车主车牌号*/
					 n=deleteOwn(own,n,s);   /*调用函数删除指定车牌号的车主记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的车主车牌号*/
				      t=searchOwn(own,n,s,1,find) ; /*调用函数查找指定车牌号的车主记录*/
				      if (t)                 /*如果该车牌号的记录存在*/
					 {
						  readOwn(&s,1);   /*读入一条完整的车主记录信息*/
					      own[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该车牌号的记录不存在*/ 
 printf("this owner is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void informationManage(Owner own[],int n)          /*该函数完成车主信息管理功能*/
{  
	int choice;
	do
	{
		menuInformatiom( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(own,n);         /*求所有车主的总停车时间*/
					  break;
			case 2:   calcuTimetable(own,n);         /*根据所有车主平均停车费用*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最高分、最低分、平均分*/
int i;
    printf(s);                                  /*这里的s传入的是输出分数的提示信息*/
    for (i=0;i<3;i++)                           /*i控制哪一门课*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Student stu[],int n)               /*该函数完成考试成绩统计功能*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,stu,n);                 /*调用此函数求三门课的最高、最低、平均值*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("三门课的最高分分别是:\n",mark,0);  /*输出最高分*/
				      break;
				case 2:   printMarkCourse("三门课的最低分分别是:\n",mark,1);  /*输出最低分*/
				      break;
				case 3:   printMarkCourse("三门课的平均分分别是:\n",mark,2);  /*输出平均分*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Student stu[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Student s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a student\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询学生的学号*/
					  break;
				case 2:   printf("Input a student\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询学生的姓名*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*输入待查询学生的名次*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchStu(stu,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printStu(&stu[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Student stu[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortStu(stu,n,1);         /*按学号由小到大的顺序排序记录*/ 
          	 printStu(stu,n);          /*按学号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(stu,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(stu,n);     /* 3. 学生成绩管理*/
					break;
			case 4: countManage(stu,n);     /* 4. 考试成绩统计*/
					break;
			case 5: searchManage(stu,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Student stu[NUM];                /*定义实参一维数组存储学生记录*/
      int choice,n;
	 n=readFile(stu);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(stu);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(stu,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortStu(stu,n,1);                   /*存入文件前按学号由小到大排序*/ 
	     saveFile(stu,n);                   /*将结果存入文件*/
      return 0;
}
