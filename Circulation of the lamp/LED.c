#include <__STC8H_H__.H>
#include <intrins.h>

int r=0;        //定义key2
int a=0;        //定义key1

/*延时函数*/
void Delay200ms()		//@24.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 25;
	j = 90;
	k = 176;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay1000ms()		//@24.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 122;
	j = 193;
	k = 128;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

/*主函数*/
void main()
{
	P0M1=0X00;	  //配置IO口
	P0M0=0XFF;
	EA=1;		      //总中断打开
	IT0=1;		    //当收到下降沿的信号就会触发外部中断0
	EX0=1;		    //允许外部中断0进行中断
	IT1=1;
	EX1=1;
	
	while(1)
	{
		if(r==0)
		{
			if(a==0)
			{
				P0=~(0X01);
				Delay200ms();
				P0=~(0X02);
				Delay200ms();
				P0=~(0X04);
				Delay200ms();
			}
			if(a==1)
			{
				P0=~(0X01);
				Delay1000ms();
				P0=~(0X02);
				Delay1000ms();
				P0=~(0X04);
				Delay1000ms();
			}
			if(a==2)
			{
				P0=~(0X01);
				Delay200ms();
				P0=~(0X02);
				Delay200ms();
				P0=~(0X04);
				Delay200ms();
			}
		}
		if(r==1)
		{
			if(a==0)
			{
				P0=~(0X01);
			}
			if(a==1)
			{
				P0=~(0X02);
			}
			if(a==2)
			{
				P0=~(0X04);
			}
		}
	}
	if(r==2)
	{
		if(a==0)
		{
			P0=~(0X01);
			Delay200ms();
			P0=~(0X02);
			Delay200ms();
			P0=~(0X04);
			Delay200ms();
		}
		if(a==1)
		{
			P0=~(0X01);
			Delay1000ms();
			P0=~(0X02);
			Delay1000ms();
			P0=~(0X04);
			Delay1000ms();
		}
		if(a==2)
		{
			P0=~(0X01);
			Delay200ms();
			P0=~(0X02);
			Delay200ms();
			P0=~(0X04);
			Delay200ms();
		}
	}
}

void int0_isr(void) interrupt 0	   //key1中断
{
  a++;
  if(a>2)
  {
		a=0;
  }
  while(P32==0);
}

void int1_isr(void) interrupt 2	   //key2中断
{
  r++;
  if(r>2)
  {
		r=0;
  }
  while(P33==0);
}