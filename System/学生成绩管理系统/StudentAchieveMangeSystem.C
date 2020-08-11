#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 200
int id=0;		/*全局变量,添加数据时自增.*/
int *p;
char delechar[]="qq65559696";
struct score
{
	int c;
	int java;
	int vb;
	int sql;
	int asp;
};
struct user		/*结构体,学生数据各项属性定义.*/
{
	char name[50];
	char sex[10];
	char no[20];
	int userid;
	struct score grade ;
};
struct user users[MAX];	/*全局结构体数组,定义可存储学生数.*/
void adduser();		/*添加数据的函数说明.*/
void updateuser();	/*修改数据的函数说明.*/
void deleteuser();	/*删除数据的函数说明.*/
void selectuser();	/*查询数据的函数说明.*/
void selectno();	/*按学号查询函数说明.*/
void selectall();	/*查询全部学生函数声明.*/
void selectgrade();
void upgrade(int a);
int average(int i);
int verify(int a);
int verifyg(int a);
int load();
void save();

int main()
{
    int conn;
    id=load();
    system("title 学生成绩信息管理系统");
    printf("***************\nqq:3289705398\nMy Name: 杜文鑫!\n***************\n");
	for(;;)			/*无限循环,用于每次执行完各操作函数时返回主菜单.*/
	{
		printf("\n\n\n\n");	/*主菜单开始*/
		printf("***********************************\n");	/*主菜单开始*/
		printf("=======学生成绩信息系统============\n");
		printf("***********************************\n");
		printf(">>>    1 添加.\n");
		printf(">>>    2 修改.\n");
		printf(">>>    3 删除.\n");
		printf(">>>    4 查询.\n");
		printf(">>>    5 清屏.\n");
		printf(">>>    其他任意键退出.\n");
		printf("***********************************\n");
		printf("***********************************\n\n\n");
		printf("输入操作:");					/*主菜单结束*/
		scanf("%d",&conn);	/*输入数字,给全局变量conter赋值,用于判断添加,删除数据等操作.*/
		if (conn==1||conn==2||conn==3||conn==4||conn==5)	/*判断输入数字是否在1到5之间*/
		{
			switch(conn)		/*如果上面判断是在1到4间,则执行switch,判断conter是1到4间的哪一个.*/
			{
			case 1  : adduser(); save();    break;		/*是1,则执行添加函数,转至添加函数进行操作.*/
			case 2  : updateuser(); save(); break;	/*是2,则执行修改函数,转至修改函数进行操作.*/
			case 3  : deleteuser(); save(); break;	/*是3,则执行删除函数,转至删除函数进行操作.*/
			case 4  : selectuser(); break;	/*是4,则执行查询函数,转至查询函数进行操作.*/
			case 5  : system("cls"); break;
			default : exit(0);				/*都不是,则退出程序.*/
			}
		}
		else exit(0);
	}
}
void adduser()	/*添加数据函数,*/
{
    char ch;
	int i=0;
	printf("姓名:");
	scanf("%s",users[id].name);
	printf("性别:");
	scanf("%s",users[id].sex);
	printf("输入成绩:\n");
	printf("c语言:");
	scanf("%d",&users[id].grade.c);
    users[id].grade.c=verifyg(users[id].grade.c);
	printf("Java:");
	scanf("%d",&users[id].grade.java);
	users[id].grade.java=verifyg(users[id].grade.java);
	printf("Vb:");
	scanf("%d",&users[id].grade.vb);
	users[id].grade.vb=verifyg(users[id].grade.vb);
	printf("Sql:");
	scanf("%d",&users[id].grade.sql);
	users[id].grade.sql=verifyg(users[id].grade.sql);
	printf("Asp:");
	scanf("%d",&users[id].grade.asp);
	users[id].grade.asp=verifyg(users[id].grade.asp);
	while(i==0)
	{
	printf("学号:");
	scanf("%s",users[id].no);
	i=verify(id);
    }
    if(i!=0)
    {
    users[id].userid=id;
    id++;
    printf("\n完成!\n\n");
    }

}
void updateuser()	/*修改数据函数,*/
{
	char upno[10],ch;
	int conn;
	int b=0;
	int i,j;
	printf("输入学号:");
	scanf("%s",upno);
      for(i=0;i<id;i++)
      {
        if(strcmp(users[i].no,upno)==0)	/*遍历所有数据,判断输入的学号于数据里面的学号是否相同,不同则不执行修改.*/
	    {
             printf("\n将要修改以下资料:\n");
    		 printf("姓名:%s\n性别:%3s,   学号:%10s ,   平均份:%3d \nC:%d , Java:%d ,  Vb:%d , Sql:%d , Asp:%d\n\n",users[i].name,users[i].sex,users[i].no,average(i),users[i].grade.c,users[i].grade.java,users[i].grade.vb,users[i].grade.sql,users[i].grade.asp);
    		 printf("\n\n按任意键继续,按0返回...\n\n");
    		 ch=getch(); if(ch==48) {j=1; break;}
    	  	 printf("修改:  1.姓名  , 2.性别 , 3.学号 , 4.成绩 , 0.主目录 , 其他键退出.\n");
    		 printf("请选择:");
    		 scanf("%d",&conn);
    		 if(conn==1||conn==2||conn==3||conn==4)
			 switch(conn)
			 {
    			case 1 : printf("姓名:");scanf("%s",users[i].name); j=1; printf("\n完成!\n\n"); break;
    			case 2 : printf("性别:");scanf("%s",users[i].sex); j=1; printf("\n完成!\n\n"); break;
    			case 3 : while(b==0){printf("学号:");scanf("%s",users[i].no);b=verify(i);}if(b!=0){j=1;b=0;printf("\n完成!\n\n");} break;
    			case 4 : j=1; upgrade(i); break;
		     }
    		 else if(conn==0) {j=1; break;}
    		 else exit(0);

       if(j!=1) printf("\n没有此学生!\n\n");
       }
     }
}
void upgrade(int a)  //修改成绩 
{
    int conn;
	int i;
	for(;;)
	{
		printf("修改成绩:  1.C  , 2.Java , 3.Vb , 4.Sql , 5.Asp , 0.主目录 , 其他键退出.\n");
		printf("输入操作:");
		scanf("%d",&conn);
		if(conn==1||conn==2||conn==3||conn==4||conn==5)
		{
					switch(conn)
					{
					case 1 : printf("C:");scanf("%d",&users[a].grade.c); break;
					case 2 : printf("Java:");scanf("%d",&users[a].grade.java); break;
					case 3 : printf("Vb:");scanf("%d",&users[a].grade.vb); break;
					case 4 : printf("Sql:");scanf("%d",&users[a].grade.sql); break;
					case 5 : printf("Asp:");scanf("%d",&users[a].grade.asp); break;
					}
					printf("完成!\n\n");
		}
		else if(conn==0)
			break;
		else
			exit(0);
	}
}
void deleteuser()	/*删除数据函数,*/
{
	char deno[10];
	int i,j,k=0;
	struct user temp;
	printf("学号:");
	scanf("%s",deno);
	for(i=0;i<id;i++)	/*遍历所有数据,判断输入的学号于数据里面的学号是否相同,不同则不执行删除操作,.*/
	{
       	if(strcmp(users[i].no,deno)==0)
       	{
           for(j=i;j<id-1;j++)
			users[j]=users[j+1];
			id--;
			k=1;
			printf("删除成功...\n");
        }	
    }
	if(k==0)
		printf("没有此学生!\n");
}

void selectuser()	/*查询控制函数,*/
{
	int conn;
	for(;;)
	{
		printf("***********************************\n");
		printf(">>>    1.查询全部学生.\n");
		printf(">>>    2.按学号查询.\n");
		printf(">>>    0.主目录\n");
		printf(">>>    其他键退出.\n");
		printf("***********************************\n\n");
		printf("输入操作:");
		scanf("%d",&conn);
		if(conn==1||conn==2)
		{
			switch(conn)
			{
			case 1 : selectall(); break;
			case 2 : selectno(); break;
			}
		}
		else if(conn==0)
			break;
		else
			exit(0);
	}
}

void selectall()	/*查询所有数据函数,*/
{
	int i;
	if(id==0)
	{
	printf("\n\n没有数据,按任意键返回...\n\n");
	getch();
    }
	else
	{
	printf("\n\n┏━━━━━━━━━━━━━━━━━━━━清单━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┣━━━━━━━━━━━━━━━━━━━共  %-4ld条记录━━━━━━━━━━━━━━━━━━━——┫\n",id);
	for(i=0;i<id;i++)
	{
                if(i%5==0 && i!=0)
                {
                printf("┃下一页...");
                getch();
                }
				printf("\x0d┃姓名:%-10s性别:%-6s学号:%-12s平均分:%d┃\n┃成绩:[C:%d]  [Java:%d]  [Vb:%d]  [Sql:%d]  [Asp:%d] ┃\n",users[i].name,users[i].sex,users[i].no,average(i),users[i].grade.c,users[i].grade.java,users[i].grade.vb,users[i].grade.sql,users[i].grade.asp);
				printf("┠──────────────────────────━━━━━━━━━━━━━━━━━━━━━━┨\n");
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n");
   }
}

void selectno()	/*按学号查询数据函数,*/
{
	char seno[10];
	int i,ii=0;
	printf("输入学号:");
	scanf("%s",seno);
	for(i=0;i<id;i++)
	{
		if(strcmp(users[i].no,seno)==0)
		{
			printf("\n\n*****************************清单******************************\n");
			printf("||%-59s||\n",users[i].name);
			printf("||===========================================================||\n");
			printf("||性别:[%3s],   学号:[%10s ],   平均份:[%3d ],         ||\n",&users[i].sex,&users[i].no,average(i));
			printf("||--------------------------<成绩>---------------------------||\n");
			printf("||C:[%3d ], Java:[%3d ],  Vb:[%3d ], Sql:[%3d ], Asp:[%3d ], ||\n",users[i].grade.c,users[i].grade.java,users[i].grade.vb,users[i].grade.sql,users[i].grade.asp);
			printf("||===========================================================||\n");
			ii=1;
			printf("***************************************************************\n\n\n");
		}
	}
	if(ii!=1)
		printf("没有此学生!\n");
}
int average(int i)  //平均分 
{
int a;
a=(users[i].grade.c + users[i].grade.java + users[i].grade.vb + users[i].grade.sql + users[i].grade.asp)/5;
return(a);
}

int verify(int a)  //验证学号是否重复 
{
    int i,b;
	for(i=0;i<id;i++)
	{
     if(i==a)
     continue;
     
     if(strcmp(users[a].no,users[i].no)==0)
     {
      printf("\n已有学号为%s的学生!\n重新输入:",users[a].no);
      b=0;
      break;
     }
     else b=1;
     //printf("[%s]    [[%s]]\n",users[a].no,users[i].no);
    }
    return(b);
}

int verifyg(int a)  //验证成绩是否超出范围 
{
	while(a<0||a>100)
	{
    printf("\n错误.范围:0~100   重新输入:");
    scanf("%d",&a);
    }
    return (a);
}

int load()
{
 int num=0,i;
 char temp;
 FILE *fp;
 if((fp=fopen("olize.dat","rb"))!=NULL)
 {
  fscanf(fp,"%d",&num);
  //printf("[[   %d   ]]\n",num);
   for(i=0;i<num;i++)
   {
     fscanf(fp,"%s%s%s%d%d%d%d%d",users[i].name,users[i].sex,users[i].no,&users[i].grade.c,&users[i].grade.java,&users[i].grade.vb,&users[i].grade.sql,&users[i].grade.asp);
     //printf("[[%s,%s,%s,%d,%d,%d,%d,%d]]\n\n",users[i].name,users[i].sex,users[i].no,users[i].grade.c,users[i].grade.java,users[i].grade.vb,users[i].grade.sql,users[i].grade.asp);
   }
  fclose(fp);
 }
 return (num);
}

void save()
{
 int num,i,j;
 struct user temp;
 FILE *fp;
 if((fp=fopen("olize.dat","wb"))==NULL)
 {
 printf("保存数据失败,数据文件无法打开...\n\n\n按任意键退出...");
 getch();
 exit(0);
 }
 for(i=0;i<id;i++)
 for(j=i+1;j<id;j++)
  if(average(i)<average(j))
  {temp=users[i];users[i]=users[j];users[j]=temp;}
 fprintf(fp,"%d\r\n",id);
 for(i=0;i<id;i++)
 fprintf(fp,"%-15s%-4s%-20s%-4d%-4d%-4d%-4d%-4d\r\n",users[i].name,users[i].sex,users[i].no,users[i].grade.c,users[i].grade.java,users[i].grade.vb,users[i].grade.sql,users[i].grade.asp);
 fclose(fp);
}
