#include <reg52.h>
#include <stdio.h>
#define uchar unsigned char

sbit DIN = P3 ^ 1;
sbit CLK = P3 ^ 3;
sbit LOAD = P3 ^ 2;
void send(uchar add, uchar dat)
{
	uchar ADS, i, j;
	CLK = 0;
	LOAD = 0;
	DIN = 0;
	i = 4;
	while (i<16)
	{
		if (i<8)
		{
			ADS = add;
		}
		else
		{
			ADS = dat;
		}
		for (j = 8; j >= 1; j--)
		{
			if ((ADS & 0x80) == 0)
			{
				DIN = 0;
			}
			else
			{
				DIN = 1;
			}
			ADS = ADS << 1;
			CLK = 1;
			CLK = 0;
		}
		i = i + 8;
	}
	LOAD = 1;
}

void main(void)
{
	send(0x0c, 0x01);//正常状态
	send(0x0b, 0x07);//设置扫描范围DIG0-7
	send(0x0a, 0x05);//设置亮度11/32
	send(0x09, 0xff);//采用译码方式

	while (1)
	{
		send(0x01, 0x81);
		send(0x02, 0x82);
		send(0x03, 0x83);
		send(0x04, 0x84);
		send(0x05, 0x85);
		send(0x06, 0x86);
		send(0x07, 0x87);
		send(0x08, 0x88);

	}
}