#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct teacher)
int n=0;
struct teacher
{
long num;
char name[20];
char sex[5];
int age;
char edu[20];
char title[20];
long wage;

char addr[100];
char telep[15];
struct teacher*next;
}*head=NULL;
void key()
{
	int i;
	long a;
	for(i=0;i<3;i++)
	{
	printf("请输入口令(还可输入%d次)：\n",3-i);
	scanf("%d",&a);
	if(a==123456){
		printf("欢迎进入系统\n");
		break;
		}
	else printf("口令错误\n");
} 
if(i==3)//判断可以输入口令的次数是否用完
{
printf("可使用的口令输入次数已用完,将自动退出！\n");
exit(0);
}
}
void save()//把数据存入文件的函数
{
FILE *fp;
int i;
char filename[20];
struct teacher *p;
printf("\n是否把此次登录系统录入和修改后的教师信息保存到文件中\n");
printf("1：         【是】         0：       【否】\n请选择：");
scanf("%d",&i);
while((i!=0)&&(i!=1))//判断输入的选择是否有效
{
printf("选择无效,请重新输入正确选项：");
scanf("%d",&i);
}
if(i==1)//判断是否选择了要保存
{
printf("\n请输入要保存数据的文件名：");
scanf("%s",filename);
if((fp=fopen(filename,"wb"))=NULL)
{
	printf("\n无法打开文件\n");
	exit(0);
}
for(p=head;p!=NULL;p=p->next)
if(fwrite(p,sizeof(struct teacher),1,fp)!=1)
printf("\n此处数据有误\n");
fclose(fp);
}
exit(0);
}
void read()
{
	struct teacher teach[299],temp;
	int i=0;FILE*fp;char filename[20];
	printf("\n请输入存有教师信息的文件名：");
	 scanf("%s",filename);
	 if((fp=fopen(filename,"rb"))==NULL)
{
printf("\n无法打开文件\n");
exit(0);
}
fseek(fp,sizeof(struct teacher),2);/*将位置指针从文件末尾后退一个结构体的字节数*/
fread(&temp,sizeof(struct teacher),1,fp);/*认所指向的文件中读出数据存储到结构体变量temp中*/
fseek(fp,0,0);//将位置指针移到文件的开头
if(fread(&teach[i],sizeof(struct teacher),1,fp)==1)/*断文件开头读入的数据是否为空*/
{
printf("\n存有的教师信息如下：An");
while(teach[i].num!=temp.num)//进行循环读取文件
{
printf("教师号：%1d,姓名：%s,性别：%s,年龄：%d,学历：%s,",teach[i].num,teach[i].name,teach[i].sex,teach[i].age,teach[i].edu);
printf("职称：%s\n月薪：%ld,住址：%s,电话：%s\n",teach[i].title,teach[i].wage,teach[i].addr,teach[i].telep);
i=i+1;
fread(&teach[i],sizeof(struct teacher),1,fp);//从文件中读入数据存储到结构体变量teach【i】中

}
//输出文件中的最后一个信息
printf("教师号：%ld,姓名：%s,性别：%s,年龄：90d,学历：%s,",teach[i].num,teach[i].name,teach[i].sex,teach[i].age,teach[i].edu);

printf("职称：%s\n月薪：%ld,住址：%s,电话%s\n",teach[i].title,teach[i].wage,teach[i].addr,teach[i].telep);
fclose(fp);
}
else printf("该文件中无教师信息n");//文件为空时输出此处
}
void creat()//录入教师信息的函数
{
	
struct teacher *p1,*p2,*p3;
p1=p2=(struct teacher*)malloc(LEN);/*申请一个结构体字节数的空间用来存储一个教师的信息*/
printf("请输入一位教师的教师号(结束录入请输入0)：");
scanf("%ld",&p1->num);
if(p1->num!=0)//判断用户是要结束录入还是要存储信息*/
if(head==NULL)head=p1;//判断链表是否为空,是则将链表头指向p1*/
else//链表不为空则将链表尾指向p1
{
	p3=head;//p3用来记录链表的尾部while(p3->next！=NULL)/*若p3不是链表尾则将p3指向下一个结点*材
p3=p3->next;
p3->next=p1;//将最后一个结点指向p1
}
while(p1->num!=0)//判断用户是否结束录入功能
{//录入该教师号的教师对应的信息
printf("姓名：");
scanf("%s",p1->name);
printf("性别：");
scanf("%s",p1->sex);
printf("年龄：");
scanf("%d",&p1->age);
printf("学历：");
scanf("%s",p1->edu);
printf("职称：");
scanf("%s",p1->title);
printf("月薪：");
scanf("%ld",&p1->wage);
printf("住址：");
scanf("%s",p1->addr);
printf("电话：");
scanf("%s",p1->telep);
n=n+1;//给统计录入的教师数n加一
/*判断是否为第一个录入的信息,是则将链表头指向p1,否则将p2指向p1*/
if(n==1)head=p1;
else p2->next=p1;p2=p1;
//p2用来记录链表的最后一个结点
p1=(struct teacher*)malloc(LEN);//厘新申请空间
printf("请输入一位教师的教师号(结束录入请输入0)：");
scanf("%ld",&p1->num);
}
p2->next=NULL;//将最后一个结点指问空
}
void print()//输出教师信息的函数
{
	
struct teacher *p;
int i;p=head;
if(head!=NULL)//判断链表是否为空
{
printf("\n这%d位教师的信息为：\n",n);
do
{
	printf("教师号：%ld,姓名：%s,性别：%s,年龄：%d,学历：%s,职称：%s\n",p->num,p->name,p->sex,p->age,p->edu,p->title);
	printf("月薪：%ld,住址：%s,电话：%s\n",p->wage,p->addr,p->telep);
	p=p->next;//将下一个结点的首地址赋给p
	
}while(p!=NULL);//到链表尾时结束循环
}
else//链表为空时执行以下部分
{
printf("\n你此次登录系统还没有录入教师信息,可进行以下操作：\n");
printf("1：【浏览以前保存在文件中的教师信息】2：【开始录入教师信息】\n");
printf("3：【退出系统】4：【返回菜单】\n");
printf("请选择：");
scanf("%d",&i);
while((i<1)&&(i>4))
{
	printf("选择无效,请重新输入正确选项：");
	scanf("%d",&i);
}
if(i==1)read();//调用从文件读取数据的函数
if(i==2)creat();//调用录入信息的函数
if(i==3)exit(0);//退出系统
}
}
void del()//删除教师信息的函数
{
	struct teacher *p1,*p2;long i;
	if(head==NULL)//判断链表是否为空
{
printf("n还未录入过教师信息n");//链表为空时输出
return;printf("请输入要删除教师信息的教师号：");
scanf("%1d",&i);
p1=head;
while(i!=p1->num)//直到p1指向的结点是要删除的信息位置
{
if(p1->next==NULL)
break;//p1的下个结点为空则退出循环
p2=p1;//p2用来记录p1的前一个结点
p1=p1->next;//p1指向下一个结点
}

if(i==p1->num)//判断p1是否为要删除的信息if
{
if(p1==head)head=p1->next;//若p1为头结点则将头指针指向p1的下一个结点*材
else p2->next=p1->next;//p1非头结点则将p1后面的结点连接到p1前一个结点的后面制
printf("\n已删除教师号为%1d的教师信息n",i);
n=n-1;//记录教师数的n要减一
}
//p1不是要删除的信息则表示要删除的信息不再链表中
else printf("\n已录入的教师信息中没有教师号为%1d的\n",i);
return;
}
}
void sort1()//按教师号进行排序的函数
{
struct teacher *p1,*p2,*p3,*p4;
int i,j;
if(head==NULL)
{
printf("\n还未录入过教师信息n");
return;}
if(head->next!=NULL)//判断是否只有一个信息
{//用冒泡法排序
p1=head;///p1记录用来比较的两个结点中的前面一个
p2=head->next;//p2记录比较的两个结点中的后面个
for(i=1;i<n;i++)//实现n-1趟比较的外循环
{
	for(j=0;j<n-i;j++)//在每一趟中进行n-i次比较的内循环
	{
	if(p1->num>p2->num)/*比较相邻两个结点中教师号大小*/
{
//当p1的教师号大时则对调两个结点的位置
if(p1==head)head=p2;
else p3->next=p2;//p1为头结点时则将头指针指向p2;否则就将p2连接到用来记录p1前一个结点的p3的后面*制
p4=p2->next;
//p4用来记录p2后面的结点
p2->next=p1;//p1的结点换到原来p2的位置
p1->next=p4;//原来p2后面的结点连接到p1
 p3=p2;//p3记录下p2的位置
p2=p4;//p2指向原来位置的下一个结点
}
else//p1中教师号没有打过p2中教师号;则将p1;p2都指向它们各自位置的下一个结点*制
{
	p3=p1;//记录p1后移一位后它前个结点的位置
	p1=p2;
	p2=p2->next;
}
}
	p1=head;//p1指向链表头;开始下一趟外循环的准备
	p2=p1->next;//p2指向链表第二个结点

}
}
printf("\n按教师号排序后的教师信息如下：n");
print();//调用教师信息浏览函数
}
void sort2()//按月薪排序的函数;算法跟按教师号排序的一样
{
	struct teacher*p1,*p2,*p3,*p4;int i,j;
	if(head==NULL)
	{
printf("\n还未录入过教师信息n");
return;
}
if(head->next!=NULL)
{
p1=head;
p2=head->next;
for(i=1;i<n;i++)
{
	for(j=0;j<n-i;j++)
	{
if(p1->wage>p2->wage)
{
if(p1==head)head=p2;
 else p3->next=p2;
  p4=p2->next;
  p2->next=p1;
  p1->next=p4;
   p3=p2;
   p2=p4;
}
else
{
	p3=p1;
	p1=p2;
 p2=p2->next;
}
}
p1=head; 
p2=p1->next;
}
}
printf("\n按月薪排序后的教师信息如下：\n");
print();
}
void sort3()//按年龄排序的函数,算法跟按教师号排序的一样
{
	struct teacher*p1,*p2,*p3,*p4;
int i,j;
if(head==NULL)
{
printf("\n还未录入过教师信息n");
return;
}
if(head->next!=NULL)
{
p1=head; 
p2=head->next;
 for(i=1;i<n;i++){
 
for(j=0;j<n-i;j++){
if(p1->age>p2->age){

if(p1==head)head=p2; 
else p3->next=p2; 
p4=p2->next;
p2->next=p1;
p1->next=p4;
p3=p2;
p2=p4;
}
else
{
	p3=p1;
	p1=p2;
	 p2=p2->next;
}
}
p1=head; 
p2=p1->next;
}
}
printf("\n 按年龄排序后的教师信息如下：\n");
print();
}
void choose1()//选择排序方式的函数
{
int i;
printf("排序方式n");
printf("1：【按教师号排序】2：【按年龄排序】\n");
printf("3：【按月薪排序】\n");
printf("请选择：");
scanf("%d",&i);
while((i<1)||(i>3))
{
	printf("选择无效,请重新输入正确选项：");
	scanf("%d",&i);
}
switch(i)
{
case 1:
sort1();
break;
case 2:
sort3();
break;
case 3:
sort2();
break;
}
}
void search1()//按教师号查找的函数
{
struct teacher *p;long i;//存储用户输入的想要删除的教师号
if(head==NULL)
{
printf("\n还未录入过教师信息n’");
return;
}
printf("请输入要查找的教师信息的教师号：");
scanf("%ld",&i);
for(p=head;p!=NULL;p=p->next)
//p顺序指向结点与i比较,找出有i的数据的结点并输出
if(p->num==i)
{
	printf("教师号：%ld,姓名：%s,性别：%s,年龄：%d,学历：%s,职称：%s\n",p->num,p->name,p->sex,p->age,p->edu,p->title);
	printf("月薪：%ld,住址：%s,电话：%s\n",p->wage,p->addr,p->telep);
	return;
}
printf("已录入的教师信息中不存在该教师号\n");
}
void search2()//按姓名查找的函数
{
	struct teacher*p;
	char i[20];//记录用户输入的想要删除的姓名
	int j=0;//j用来记录找到了多少个信息
	if(head==NULL)
{
printf("\n还未录入过教师信息n");
return;
}
printf("请输入要查找的信息的教师姓名：");
scanf("%s",i);
for(p=head;p!=NULL;p=p->next)
if(strcmp(p->name,i)==0)//比较p指向的结点中的姓名跟i的是否一致,是则输出
{
	printf("教师号：%1d,姓名：%s,性别：%s,年龄：%d,学历：%s,职称：%s\n",p->num,p->name,p->sex,p->age,p->edu,p->title);
	printf("月薪：%ld,住址：%s,电话：%s\n",p->wage,p->addr,p->telep);
	j=j+1;//每输出一个教师的信息则j加一
}
}
void search3()//按职称查找的函数,算法与按姓名查找的一样
{
	struct teacher*p;
	char i[20];int j=0;
	if(head==NULL)
	{
	
printf("\n还未录入过教师信息\n");
return;
}
printf("请输入要查找的信息的教师职称：");
scanf("%s",i);
for(p=head;p!=NULL;p=p->next)
if(strcmp(p->title,i)==0)
{
	printf("教师号：%1d,姓名：%s,性别：%s,年龄：%d,学历：%s,职称：%s\n",p->num,p->name,p->sex,p->age,p->edu,p->title);
	printf("月薪：%ld,住址：%s,电话：%s\n",p->wage,p->addr,p->telep);
	j=j+1;
}
if(j==0)
printf("已录入的教师信息中不存在该职称的教师\n");
}
void search4()//按年龄查找的函数,算法与按教师号查找的一样
{
	struct teacher *p;
	 int i,j=0;
if(head==NULL)
{
	printf("\n还未录入过教师信息\n");
	return;}
	printf("请输入要查找的信息的教师年龄：");
	scanf("%d",&i);
	for(p=head;p!=NULL;p=p->next)
if(p->age==i)
{
	printf("教师号：%1d,姓名：%s,性别：%s,年龄：0d,学历：%s,职称：%s\n",p->num,p->name,p->sex,p->age,p->edu,p->title);
	printf("月薪：%ld,住址：%s,电话：%s\n",p->wage,p->addr,p->telep);
	j=j+1;
}
if(j==0)
printf("已录入的教师信息中不存在该年龄的教师n");
}
void choose2()//选择查找方式的函数
{
	int i;
	printf("1：【按教师号查询】2：【按姓名查询】\n");
	printf("3：【按职称查询】4：【按年龄查询】\n");
	printf("请选择：");
	scanf("%d",&i);
	while((i<1)||(i>4))
{
	printf("选择无效，请重新输入正确选项：");
	scanf("%d",&i);
}
switch(i)
{
case 1:search1();break;
case 2:search2();break;
case 3:search3();break;
case 4:search4();break;
}
}
void menu()//菜单栏函数
{
int i;
printf("菜单\n");
printf("   ===== 1：【教师信息录入】   =======  2：【教师信息输出】\n");
printf("   ===== 3：【教师信息删除】   =======  4：【查询个人信息】\n");
printf("   ===== 5：【排序】           =======  6：【退出系统】\n");
printf("请选择：");
scanf("%d",&i);
while((i<1)||(i>6))
{
	printf("选择无效，请重新输入正确选项：");
	scanf("%d",&i);
	
}

switch(i)
{
case 1:creat();break;
case 2:print();break;
 case 3:del();break; 
 case 4:choose2();break;
  case 5:choose1();break;
   case 6:save();
}
menu();
}

main()//主函数
{
	key();
	menu();
	
}





























