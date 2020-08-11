#include <stdio.h>     
int year(int y)  
{    if ((y%4==0) && (y%100!=0) || y%400==0)  
        return 366;  
    else  
        return 365;  
}  
  
int main()  
{  
    int y;  
    int i,j,sum=0;    
    int begin,week;  
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
printf("请输入年份："); 
   scanf("%d",&y);  
   for(i=1;i<y;i++)  
       sum+=year(i);  
     
    week=(sum+1)%7;     
      
    if(year(y)==366)  
        days[1]=29;   
  
    printf("\n%d年日历如下：\n\n",y);   
  
    for(i=0;i<12;i++)  
   {  
        printf("   *************%d月****************\n",i+1);  
        printf("   SUN  Mon  Tue  Wed  Thu  Fri  Sat\n");  
        printf("======================================\n");  
        begin=1;  
        for(j=0;j<week;j++)  
            printf("");  
       while(begin<=days[i])  
       {  
            printf("%5d",begin);  
            begin++;  
           week=(week+1)%7;  
            if(week%7==0)  
                printf("\n");  
        }  
       printf("\n\n");   
  }  
     
 
	return 0;  }
 
