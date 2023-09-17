#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "DS18B20.h"
#include "Delay.h"
#include "clock.h"

sbit beep=P1^5;
float T;
int i;
int b[3] = {0,0,10};
void main()
{	 
     LCD_Init();
     LCD_ShowString(1,1,"1.time  2.clock");
	 LCD_ShowString(2,1,"3.temperature");
	 while(1)
	 {
     if(P3_0==0)
	 {
	 LCD_ShowString(1,1,"                ");
	 LCD_ShowString(2,1,"                ");
	 LCD_ShowString(1,1,"time:");
	 LCD_ShowString(2,1,"  :  :  ");
	 DS1302_SetTime();

     while(1)
	 {	
	    if(P3_3==0){break;}
	    else
		{
	    DS1302_ReadTime();
	    LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
        }
     }
	 }		  
	 
	 if(P3_1==0)
	 {
	    LCD_ShowString(1,1,"                ");
	    LCD_ShowString(2,1,"                ");
		LCD_ShowString(1,1,"clock:");
		LCD_ShowString(2,1,"  :  :  ");
		LCD_ShowNum(2,1,b[0],2);
		LCD_ShowNum(2,4,b[1],2);
		LCD_ShowNum(2,7,b[2],2);
		
		while(!(b[0]==0&&b[1]==0&&b[2]==0))
		{
		LCD_ShowNum(2,1,b[0],2);
		LCD_ShowNum(2,4,b[1],2);
		LCD_ShowNum(2,7,b[2],2);
		timeset();
		timedel();  
		if(P3_3==0){break;}
		Delay(1000);
	    }

		if(b[0]==0&&b[1]==0&&b[2]==0)
		{
		while(1)
	    {
			if(P3_3==0){break;}	
			 
			   
			else
			{
		    	for(i = 100;i > 0;i--)
			    {
			  	beep = ~beep;
				beep=1;				  
				}
		    }
	    }
		}	
	 }

	 if(P3_2==0)
	 {
	   
		DS18B20_ConvertT();	
	   
		
		LCD_ShowString(1,1,"                ");
	    LCD_ShowString(2,1,"                ");	
	    LCD_ShowString(1,1,"Temperature:");
	    while(1)
	    {
		DS18B20_ConvertT();	
		T=DS18B20_ReadT();	
		if(T<0)				
		{
			LCD_ShowChar(2,1,'-');	
			T=-T;		
		}
		else				
		{
		LCD_ShowChar(2,1,'+');	
		}
		LCD_ShowNum(2,2,T,3);	
		LCD_ShowChar(2,5,'.');		
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
		if(P3_3==0){break;}
    	}
	 }

	 if(P3_3==0)
	 {
	 LCD_ShowString(1,1,"1.time  2.clock");
	 LCD_ShowString(2,1,"3.temperature");
	 }
	 }
}