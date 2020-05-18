#include <stdio.h>

unsigned short CRC16_Modbus(unsigned char *pdata, int len)
{
	unsigned short crc = 0xFFFF;
	int i, j;
	for (j = 0; j < len; j++)
	{
		crc = crc ^ pdata[j];
		for (i = 0; i < 8; i++)
		{
			if ((crc & 0x0001) > 0)
			{
				crc = crc >> 1;
				crc = crc ^ 0xA001;
			}
			else
				crc = crc >> 1;
		}
	}
	return crc;
}

int main(void)
{
	unsigned char Data_01[6] = {0x01, 0x10, 0x00, 0x02, 0x06, 0x01};
	unsigned char Data_00[6] = {0x01, 0x10, 0x00, 0x02, 0x06, 0x00};
	unsigned short Crc_01 = 0xFFFF;
	unsigned short Crc_00 = 0xFFFF;
	Crc_01 = CRC16_Modbus(Data_01, 6);
	Crc_00 = CRC16_Modbus(Data_00, 6);
	printf("%x %x %x %x %x %x %x\n", Data_01[0], Data_01[1], Data_01[2], Data_01[3], Data_01[4], Data_01[5], Crc_01);
	printf("%x %x %x %x %x %x %x\n", Data_00[0], Data_00[1], Data_00[2], Data_00[3], Data_00[4], Data_00[5], Crc_00);
	return 0;
}
