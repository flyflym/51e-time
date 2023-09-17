#include "reg52.h"			 
#include "Delay.h"
#include "LCD1602.h"
extern int b[3];
sbit k5=P1^0;
sbit k6=P1^1;
sbit k7=P1^2;
sbit k8=P1^3;
void timedel()
{

     if(b[2]==0)
	 {
	   b[1]--;
	   b[2]=60;
	   if(b[1]==0&&b[0]!=0)
	   {
	   b[0]--;
	   b[1]=60;
	   }
	 }
	 else 
	 {
	   b[2]--;
	 }

}

void timeset()
{
    int j=0; 
	if(k5==0)
	{
	Delay(500);
	while(1)
	{
		LCD_ShowNum(2,1,b[0],2);
		LCD_ShowNum(2,4,b[1],2);
		LCD_ShowNum(2,7,b[2],2);
		if(k5==0){j++;Delay(500);}
		if(j==3){j=0;}

		if(j==0&&k6==0)
		{
		  LCD_ShowString(1,9,"set hour");
		  b[0]++;
		  Delay(500);
		}
		else if(j==0&&k7==0)
		{
	      LCD_ShowString(1,9,"set hour");
		  b[0]--;
		  Delay(500);
		}
	    else if(j==1&&k6==0)
		{
		  LCD_ShowString(1,9,"set mint");
		  b[1]++;
		  Delay(500);
		}
	   	else if(j==1&&k7==0)
		{
		  LCD_ShowString(1,9,"set mint");
		  b[1]--;
		  Delay(500);
		}
		else if(j==2&&k6==0)
		{ 
		  LCD_ShowString(1,9,"set secd");
		  b[2]++;
		  Delay(500);
		}
		else if(j==2&&k7==0)
		{
		  LCD_ShowString(1,9,"set secd");
		  b[2]--;
		  Delay(500);
		}
		if(k8==0){LCD_ShowString(1,9,"         ");break;}
	}
	}
}