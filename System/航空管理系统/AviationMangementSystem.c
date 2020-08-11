
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
//函数声明 
void banquan();//版权函数 
void banquan1();//版权函数1 
void interface();//界面函数 
void menu();//菜单函数 
void registered();//注册函数
void sheshidu ();//温度对照表 
void game();//游戏函数 
void interface1();//界面函数1 
void select();//选择函数 
void select1();//选择函数 1
void login();//登陆函数
void main1();
static i = 0;
static a = 0;
typedef struct node{
	char start_place[20];//起点
	char end_place[20];//终点
	char start_time[20];//起时间
	char end_time[20];//降时间
	char no[20];//航班号
	float price;//票价
	int number;//票数
	char name[20];//姓名
	char card[20];//证件号
	int number1;//订票数量
	struct node * link; //定义node型结构指针 
}NODE; 

//typedef struct  node NODE;  //定义结点类型 


struct user{
			char username[20];
			char password[20];
			}u[10];
void banquan()  //版权函数 
{
	printf("软 件 开 发: 航 空 管 理 系 统// 测 试 版 本 1.6\n\n");
	printf("开 发 人: 第 四 小 组 所 有 成 员\t\t\t\t版 权 号: 20181030107\n\n");
			}


void banquan1() { //版权函数 1
	printf("软 件 开 发: 航 空 管 理 系 统\n\n");
	printf("开 发 人: 第 四 小 组 所 有 成 员\t\t\t\t版 权 号: 12581\n\n");
}			


void interface()//界面函数 
{
	printf("\t\t欢 迎 使 用 本 系 统 测 试 版 本 1.6\n");
	printf("\t\t\t _________________\n");
	printf("\t\t\t|                 |\n");
	printf("\t\t\t|   1.新用户注册  |\n");
	printf("\t\t\t|_________________|\n");
	printf("\t\t\t|                 |\n");
	printf("\t\t\t|   2. 登   陆    |\n");
	printf("\t\t\t|_________________|\n");	
	printf("\t\t\t|                 |\n");
	printf("\t\t\t|   0. 退   出    |\n");
	printf("\t\t\t|_________________|\n");
    printf("\n");
} 


void menu()//菜单函数 
{	printf("\t\t\t*********************\n");
	printf("\t\t\t*    菜 单 列 表    *\n"); 
	printf("\t\t\t*********************\n");
	printf("\t\t*************************************\n");
	printf("\t\t*   ● 温度对照表--------------- 1  *\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*   ●  游  戏------------------ 2  *\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*   ●  名  字------------------ 3  *\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*   ●  航班管理系统------------ 4  *\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*   ●  退   出----------------- 0  *\n");
    printf("\t\t*************************************\n\n");
	
}


void registered()//注册函数
{
	char username1[20]; 
	char password1[20];
	char password2[20]; 
	int k; 
	printf("\t\t   首 次 登 陆 需 要 注 册 账 号\n\n"); 	
	printf("\t\t\t注 册 账 号: ");
	scanf("%s",username1);
	printf("\n"); 
	for(k = 0;k <= i;k++){ 
		if(strcmp (u[k].username,username1) == 0){ 
			printf("\t\t**************************************\n");
		 	printf("\t\t* 该 用 户 已 被 注 册 请 重 新 输 入*\n");
		 	printf("\t\t**************************************\n\n");
			system("pause");
			system("cls");//清屏函数
			break;}} 
		if(k > i) 	
		{
		strcpy(u[i].username,username1); 
		printf("\t\t\t输 入 密 码: ");
		scanf("%s",password1);
	printf("\n");
while(1){
	printf("\t\t\t确 认 密 码: "); 
	scanf("%s",password2);
	printf("\n"); 
		if( strcmp (password1,password2) == 0 ){ 
	 	strcpy(u[i].password,password1); 
	 	printf("\t\t*********************************\n");
		printf("\t\t*       账 号 注 册 成 功       *\n ");
		printf("\t\t*********************************\n\n");
		system("pause");
		system("cls");//清屏函数 
	 	i++; 
		break;} 
		else 
		printf("\t\t*******************************************\n");
		printf("\t\t* 账 号 注 册 失 败 , 请 您 重 新 输 入 *\n ");
		printf("\t\t*******************************************\n\n");
		system("pause");
		system("cls");//清屏函数
		break;}}
} 


void sheshidu ()//温度对照表 
	{ double F,C = 0.0;
		printf("\t\t\t    摄氏温度与华氏温度对照表\n");
		printf("\t\t*------------------------------------------------* \n");
while(C <= 100){ 
	printf("\n");	
 	printf("\t\t|    摄氏温度为%3.lf时---------->",C);
		F = 9.0 / 5 * C + 32;
	printf("华氏温度为%3.lf    |    \n",F );
		C = C + 10;
	    printf("\t\t------------------------------------------------ \n");}
	    	system("pause");
	    	system("cls");//清屏 
}  


void game()
{
	int x,y,w = 0,s = 0,p = 0,sum1 = 0,sum2 = 0;
	int w1 = 0,s1 = 0;
	char z[10];
	printf("\t\t**********************************\n");
	printf("\t\t*         猜  拳  游  戏         *\n");
	printf("\t\t*                                *\n");
	printf("\t\t*    ● 游 戏 规 则              *\n");
	printf("\t\t*                                *\n");
	printf("\t\t*    ● 赢一局加10分             *\n");
	printf("\t\t*                                *\n");
	printf("\t\t*    ● 输一局扣10分             *\n");
	printf("\t\t*                                *\n");
	printf("\t\t*    ● 平局不加分不扣分         *\n");
	printf("\t\t*                                *\n");
	printf("\t\t*        1: 开 始 游 戏          *\n");
	printf("\t\t*                                *\n");
	printf("\t\t*        0: 退 出 游 戏          *\n");
	printf("\t\t**********************************\n\n");
	printf("开 始 或 结 束 游 戏: ");
		scanf("%d",&x);
	printf("\n");
		if(x == 1){
		printf("\t\t******************************\n");
		printf("\t\t*       游  戏  开  始       *\n");
		printf("\t\t*                            *\n");
		printf("\t\t* 1: 石头    2: 剪刀    3:布 *\n");
		printf("\t\t*                            *\n");
		printf("\t\t*     0: 退  出  游  戏      *\n");   
		printf("\t\t******************************\n\n");
		}
    	else {
    			printf("\t\t*********************************\n");
				printf("\t\t*        游  戏  结  束         *\n");
				printf("\t\t*                               *\n");
				printf("\t\t*  胜 利: %3d      得 分: %3d   *\n",w,w*10);
				printf("\t\t*                               *\n");
				printf("\t\t*  失 败: %3d      扣 分: %3d   *\n",s,s*10);
				printf("\t\t*                               *\n");
				printf("\t\t*  平 局: %3d      无 分:   0   *\n",p);
				printf("\t\t*                               *\n");
				printf("\t\t*********************************\n\n");
				system("pause");}
    		
	while(x != 0 ){
		printf("开 始 输 入: ");
		scanf("%d",&x);
		printf("\n");
		y = rand()%3;
	switch(x){
			case 1:
			switch(y){
			case 0:	
				printf("\t\t你 选 择 的 是: 石 头\n\n");
				printf("\t\t电 脑 选 择 的: 石 头\n\n");
				printf("\t\t\t[平   局]\n\n");
				p++;break;
			case 1:
				printf("\t\t你 选 择 的 是: 石 头\n\n");	
				printf("\t\t电 脑 选 择 的: 剪 刀\n\n");
				printf("\t\t\t[你 赢 了]\n\n");
				w++;s1++;break;
			case 2:
				printf("\t\t你 选 择 的 是: 石 头\n\n");	
				printf("\t\t电 脑 选 择 的:  布\n\n");
				printf("\t\t\t[你 输 了]\n\n");
				s++;w1++;break;}break;
		case 2:
			switch(y){
				case 0:	
				printf("\t\t你 选 择 的 是: 剪 刀\n\n");
				printf("\t\t电 脑 选 择 的: 剪 刀\n\n");
				printf("\t\t\t[平   局]\n\n");
				p++;break;
				case 1:
				printf("\t\t你 选 择 的 是: 剪 刀\n\n");	
				printf("\t\t电 脑 选 择 的: 剪 刀\n\n");
				printf("\t\t\t[平  局]\n\n");
				p++;break;
				case 2:
				printf("\t\t你 选 择 的 是: 剪刀\n\n");	
				printf("\t\t电 脑 选 择 的:  布\n\n");
				printf("\t\t\t[你 赢了]\n\n");
				w++;s1++;break;}break; 
			case 3:
				switch(y){
					case 0:	
				printf("\t\t你 选 择 的 是: 布\n\n");
				printf("\t\t电 脑 选 择 的: 布\n\n");
				printf("\t\t\t[平   局]\n\n");
				p++;break;
			case 1:
				printf("\t\t你 选 择 的 是: 布\n\n");	
				printf("\t\t电 脑 选 择 的: 剪 刀\n\n");
				printf("\t\t\t[你 输 了]\n\n");
				s++;w1++;break;
			case 2:
				printf("\t\t你 选 择 的 是:  布\n\n");	
				printf("\t\t电 脑 选 择 的:  布\n\n");
				printf("\t\t\t[平  局]\n\n");
				p++;break;} break;
			case 0:
				sum1 = w  * 10 -  s * 10;
				sum2 = w1 * 10 - s1 * 10;
				if(sum1 > sum2)
					 strcpy(z,"你 赢 了");
				else if(sum2 > sum1)
					 strcpy(z,"你 输 了");
				else 
				 	 strcpy(z,"平    手"); 
				printf("\t\t**********************************\n");
				printf("\t\t*         游  戏  结  束         *\n");
				printf("\t\t*                                *\n");
				printf("\t\t*   胜 利: %3d      得 分: %3d   *\n",w,w * 10);
				printf("\t\t*                                *\n");
				printf("\t\t*   失 败: %3d      扣 分: %3d   *\n",s,s * 10);
				printf("\t\t*                                *\n");
				printf("\t\t*   平 局: %3d      不 分:  0    *\n",p);
				printf("\t\t*                                *\n");
				printf("\t\t*   你: %3d分       电 脑: %3d分 *\n",sum1,sum2);
				printf("\t\t*                                *\n");
				printf("\t\t*            %s            *\n",z);
				printf("\t\t**********************************\n\n");
			 system("pause");system("cls");break;}}
 } 
 
 void interface1()//界面函数 
{
	printf("\t\t***************************************\n");
	printf("\t\t*    欢 迎 使 用 航 空 管 理 系 统    *\n");
	printf("\t\t***************************************\n\n");
	printf("\t\t***************************************\n");
	printf("\t\t*   ● 录入航班信息--------------- 1  *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*   ● 删除航班信息--------------- 2  *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*   ● 查询航班信息--------------- 3  *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*   ● 全部航班信息--------------- 4  *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*   ●   订    票  --------------- 5  *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*   ●   退    票  --------------- 6  *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*   ●   退    出  --------------- 0  *\n");
  	printf("\t\t***************************************\n\n");
}
 
 void select()//选择函数 
{
	int x;
do{
	menu();
	printf("请 输 入 服 务 选 择: ");
    scanf("%d",&x); 
    printf("\n\n");
     switch(x){
     	case 1: sheshidu();break;
     	case 2: system("cls"); 
		 		game();break;
    	case 3: lvhexiang(); break;
   		case 4: banquan1(); //界面1函数 
				select1();
				break;
     	case 0: 
		printf("\t\t*******************************************\n");
		printf("\t\t* 亲 !  欢   迎   下   次   来   玩   呀  *\n");
		printf("\t\t*******************************************\n\n");
		system("pause");
		system("cls");//清屏 
		printf("\n\n");
		break;
		default :
		printf("\t\t*********************************************\n");
		printf("\t\t*    没 有 此 选 项 !  请 重 新 输 出 !     *\n");
		printf("\t\t*********************************************\n\n");
		system("pause");
		system("cls"); //清屏 
		break;
		}	}while(x != 0);
}	

int create ( NODE *head)
{
	NODE *p;
	char c;
while(c != 'n' && c!= 'N' ){
		p = (NODE *) malloc (sizeof (NODE));//申请新数据结点 
		system("cls");
		printf("\t\t***********************************************\n");
		printf("\t\t*    正   在   录   入   航   班   信   息    *\n");
		printf("\t\t***********************************************\n\n");
		
	printf("\t\t出 发 地 址: ");
	scanf("%s",p -> start_place);
			printf("\n");
	printf("\t\t目 的 地 址: ");
	scanf("%s",p -> end_place);
		printf("\n");
	printf("\t\t起 飞 时 间: ");
	scanf("%s",p -> start_time);
		printf("\n");
	printf("\t\t到 达 时 间: ");
	scanf("%s",p -> end_time);
		printf("\n");
	printf("\t\t航 班 编 号: ");
	scanf("%s",p -> no);
		printf("\n");
	printf("\t\t机 票 价 格: ");
	scanf("%f",&p -> price);
	    printf("\n");
	printf("\t\t机 票 数 量: ");
	scanf("%d",&p -> number);
	    printf("\n");
	p -> link = head -> link; //将NULL存入p的link中 
	head -> link = p;//将数据结点p插在表头结点之后
	
		printf("\t\t\t*************************************\n");
		printf("\t\t\t*    录   入   信   息   完   成    * \n");
		printf("\t\t\t*************************************\n\n");
	printf("\t\t\t是 否 继 续( Y / N):");
	scanf("%s",&c);
	//system("pause");
	}
	system("cls");
	return 0;
}


int dingpiao ( NODE *head)//订票 
{
	NODE *p;
		p = (NODE *) malloc (sizeof (NODE));//申请新数据结点 
		system("cls");
		printf("\t\t******************************\n");
		printf("\t\t*    订    票    界    面    *\n");
		printf("\t\t******************************\n\n");
		
	printf("\t\t输 入 要 购 买 航 班 的 航 班 号: ");
	scanf("%s",p -> no);
			printf("\n");
	printf("\t\t输 入 姓 名: ");
	scanf("%s",p -> name);
		printf("\n");
	printf("\t\t输 入 证 件 号: ");
	scanf("%s",p -> card);
		printf("\n");
	printf("\t\t输 入 购 买 的 票 数: ");
	scanf("%d",&p -> number1);
		printf("\n");
//	p -> link = head -> link; //将NULL存入p的link中 
//	head -> link = p;//将数据结点p插在表头结点之后
		printf("\t\t\t            *************************************\n");
		printf("\t\t\t            *   订 单 生 成 中 请 稍 后......   *\n");
		printf("\t\t\t            *************************************\n\n");
		sleep(3);
		printf("\t\t\t*******************************************************************\n");
		printf("\t\t\t*    机   票   定   购   完   成 , 祝   您   旅   途   愉    快   * \n");
		printf("\t\t\t*******************************************************************\n\n");
		a = a + (p -> number1);
	system("pause");
	system("cls");
	return 0;
}


int tuipiao ( NODE *head)//退票 
{
	NODE *p;
		p = (NODE *) malloc (sizeof (NODE));//申请新数据结点 
		system("cls");
		printf("\t\t******************************\n");
		printf("\t\t*    退    票    界    面    *\n");
		printf("\t\t******************************\n\n");
		
	printf("\t\t输 入 要 退 购 航 班 的 航 班 号: ");
	scanf("%s",p -> no);
			printf("\n");
	printf("\t\t输 入 姓 名: ");
	scanf("%s",p -> name);
		printf("\n");
	printf("\t\t输 入 证 件 号: ");
	scanf("%s",p -> card);
		printf("\n");
	printf("\t\t输 入 退 购 的 票 数: ");
	scanf("%d",&p -> number1);
		printf("\n");
	p -> link = head -> link; //将NULL存入p的link中 
	head -> link = p;//将数据结点p插在表头结点之后
		printf("\t\t\t*************************************\n");
		printf("\t\t\t*   订 单 生 成 中 请 稍 后......   *\n");
		printf("\t\t\t*************************************\n\n");
		sleep(3);
		printf("\t\t\t*************************************\n");
		printf("\t\t\t*    机   票   退   购   完   成    * \n");
		printf("\t\t\t*************************************\n\n");
		a = a - (p -> number1);
	system("pause");
	system("cls");
	return 0;
}


int output (NODE *head)
{
	system("cls");
	NODE *p;
	p = head -> link;
		printf("\t\t\t\t*******************************************\n");
		printf("\t\t\t\t*  正  在  显  示  全  部  航  班  信  息 *\n");
		printf("\t\t\t\t*******************************************\n\n");
		printf(" ========================================================================================================================== \n\n");
	while (p != NULL){
		printf("   航班号: %s     出发地址: %s     目的地址:%s     出发时间: %s     到达时间: %s     机票价格: %4.2f元     机票数量:%d张    \n",p -> no,p -> start_place,p -> end_place,p -> start_time,p -> end_time,p -> price,(p -> number ) -  a);
		printf(" ========================================================================================================================== \n\n");
		p = p -> link ;
	}	
		printf("\t\t\t\t    *************************************\n");
		printf("\t\t\t\t    *   航  班  信  息  显  示  完  毕  *\n");
		printf("\t\t\t\t    *************************************\n\n");
		system("pause");
		system("cls");
	return 0;
}

int delete (NODE *head){
	system("cls");
	NODE *q,*p;
	int n,i = 0;
		printf("\t\t\t\t*******************************************\n");
		printf("\t\t\t\t*  正   在   删   除   航   班   信   息  *\n");
		printf("\t\t\t\t*******************************************\n\n");
		printf("请 输 入 要 删 除 的 第 几 列 航 班: ");
		scanf("%d",&i);
		printf("\n");
		printf("\t\t\t\t    **************************************\n");
		printf("\t\t\t\t    *     将  要  删  除  的  信  息     *\n");
		printf("\t\t\t\t    **************************************\n\n");
		sleep(1); 
		printf(" ========================================================================================================================== \n\n");
	for(n = 0,q = head;n < i - 1 && q -> link != NULL ; ++n)
		q = q -> link;
	if (i > 0 && q -> link != NULL){
		p = q -> link;
		q -> link = p -> link;
	printf("   航班号: %s     出发地址: %s     目的地址:%s     出发时间: %s     到达时间: %s     机票价格: %4.2f元     机票数量:%d张        \n",p -> no,p -> start_place,p -> end_place,p -> start_time,p -> end_time,p -> price,(p -> number ) -  a);
		printf(" ========================================================================================================================== \n\n");
		free(p);
	}
		printf("\t\t\t\t    *************************************\n");
		printf("\t\t\t\t    *   信 息 删 除 中 请 稍 后.......  *\n");
		printf("\t\t\t\t    *************************************\n\n");
		sleep(3);
		printf("\t\t\t\t    *************************************\n");
		printf("\t\t\t\t    *   航  班  信  息  删  除  完  毕  *\n");
		printf("\t\t\t\t    *************************************\n");
		system("pause");
		system("cls");
}

int found (NODE *head){
	system("cls");
	NODE *q,*p;
	int n,i = 0;
		printf("\t\t\t\t*******************************************\n");
		printf("\t\t\t\t*  正   在   查  找   航   班   信   息   *\n");
		printf("\t\t\t\t*******************************************\n\n");
		printf("请 输 入 要 查 找 的 第 几 列 航 班: ");
		scanf("%d",&i);
		printf("\n");
		printf("\t\t\t\t    *************************************\n");
		printf("\t\t\t\t    *   信 息 查 找 中 请 稍 后.......  *\n");
		printf("\t\t\t\t    *************************************\n\n");
		sleep(3);
		printf(" ========================================================================================================================== \n\n");
	for(n = 0,q = head;n < i - 1 && q -> link != NULL ; ++n)
		q = q -> link;
	if (i > 0 && q -> link != NULL){
		p = q -> link;
		q -> link = p -> link;
		printf("   航班号: %s     出发地址: %s     目的地址:%s     出发时间: %s     到达时间: %s     机票价格: %4.2f元     机票数量:%d张                                     \n",p -> no,p -> start_place,p -> end_place,p -> start_time,p -> end_time,p -> price,(p -> number ) -  a);
		printf(" ========================================================================================================================== \n\n");
}
		printf("\t\t\t\t    *************************************\n");
		printf("\t\t\t\t    *   航  班  信  息  查 找  完  毕   *\n");
		printf("\t\t\t\t    *************************************\n");
		system("pause");
		system("cls");
}


void select1()//选择函数 1
{
	NODE * head;        //说明头指针head*
	NODE *p;
	p = (NODE *) malloc (sizeof (NODE)); //开辟新存储区，申请表头结点 
	p -> link = NULL;//*将表头结点的link置为NULL 
	head = p;  //*head 指向头结点p*
	system("cls");
	int x;
do{
	interface1(); 
	printf("请 输 入 服 务 选 择: ");
    scanf("%d",&x); 
    printf("\n\n");
     switch(x){
     	case 1:	
		 		system("cls");
				create ( head );break;
     	case 2:
     			system("cls");
		 	 	delete( head);break;
    	case 3: 
    			system("cls");
    			found (head);break;
   		case 4:	system("cls");
		   		output (head);break;
   		case 5:
   			system("cls");
   			dingpiao (head);break;
   		case 6:system("cls");
		   tuipiao (head);break;
     	case 0: 
		printf("\t\t*********************************************\n");
		printf("\t\t*    欢 迎 下 次 使 用 航 空 管 理 系 统    *\n");
		printf("\t\t*********************************************\n\n");
		system("pause");
		system("cls");//清屏 
		printf("\n\n");	break;
	default :
		printf("\t\t*********************************************\n");
		printf("\t\t*    没 有 此 选 项 !  请 重 新 输 出 !     *\n");
		printf("\t\t*********************************************\n\n");
		system("pause");
		system("cls"); //清屏 
		break;
		}	}while(x != 0);
}	

void login()//登陆函数  
{
	int j = 0; 
	char username[20]; 
	char password[20];
	printf("\t\t\t*********************\n");
	printf("\t\t\t* 登   陆   界   面 *\n");
	printf("\t\t\t*********************\n\n");
	printf("\t\t\t 账 号: ");
		 scanf("%s",username);
	printf("\n"); 
	printf("\t\t\t 密 码: ");
		scanf("%s",password);
	printf("\n");
while(j < i){
	 	if( (strcmp (u[j].username,username) == 0) && (strcmp (u[j].password,password) == 0) ){ 
	 		printf("\t\t\t*********************\n");
	 		printf("\t\t\t* 账 号 登 陆 成 功 *\n");
	 		printf("\t\t\t*********************\n\n\n");
	 		printf("\t\t加 载 中 > > > > > > > >");
	 		system("pause");
	 		system("cls");//清屏函数 
	 		printf("\n");
	 		select(); 
			break;} 
			j++;} 
		if(j >= i){
		printf("\t\t**************************************\n");
		printf("\t\t* 登 陆 失 败 ! 密 码 或 账 号 错 误 *\n");
		printf("\t\t**************************************\n\n"); 
		system("pause");
	 	system("cls");//清屏函数  
		printf("\n");} 
} 


int lvhexiang()//名字函数
{	
	 		printf("\t\t***************          ****************          ****************                    \n"); 
		    printf("\t\t              *          *              *                         *                    \n"); 
		    printf("\t\t              *          *              *                         *                    \n");
		    printf("\t\t***************          *              *          ****************                    \n");
		    printf("\t\t*                        *              *                         *                    \n"); 
		    printf("\t\t*                        *              *                         *                    \n"); 
		    printf("\t\t***************          ****************          ****************                    \n");
		    printf("\n"); 
		    printf("\t\t\t\t\t[ 2  0  3 ]\n\n\n"); 
		    system("pause");
		    system("cls"); //清屏 
}         



void main1()
{
	int x;
    banquan();
do{
	interface(); //界面函数 
	printf("请 输 入 标 号 选 择: ");
    scanf("%d",&x); 
    printf("\n\n");
     switch (x){
     	case 1: registered();break;
     	case 2: login(); break;
     	case 0:
		printf("\t\t\t******************************\n");
	 	printf("\t\t\t* 欢 迎 下 次 使 用 本 系 统 *\n");
	 	printf("\t\t\t******************************\n");break;
	default :
		printf("\t\t*********************************************\n");
		printf("\t\t*    没 有 此 选 项 !  请 重 新 输 出 !     *\n");
		printf("\t\t*********************************************\n\n");
		system("pause");
		system("cls"); //清屏 
		break;
		}
}while(x != 0);
     	system("pause");
}  
 main()
{
	main1();
	int create ( NODE *head);	
	int output (NODE *head);
	int delete( NODE *head ); 
	int found (NODE *head); 
	int dingpiao ( NODE *head);
	int tuipiao ( NODE *head); 
	getch();
}
