// @File		MCP3424.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		18/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MCP3424_H
#define MCP3424_H

#define MCP3424_SLA_W 0xD0
#define MCP3424_SLA_R 0xD1

#define MCP3424_CONTINUOUS_CONVERSION_MODE 0x90
#define MCP3424_ONE_SHOT_CONVERSION_MODE 0x80
#define MCP3424_CHANNEL_0 0x00
#define MCP3424_CHANNEL_1 0x20
#define MCP3424_CHANNEL_2 0x40
#define MCP3424_CHANNEL_3 0x60
#define MCP3424_12_BIT_SELECTION 0x00
#define MCP3424_14_BIT_SELECTION 0x06
#define MCP3424_16_BIT_SELECTION 0x08
#define MCP3424_18_BIT_SELECTION 0x0C
#define MCP3424_PGA_X1_GAIN 0x00
#define MCP3424_PGA_X2_GAIN 0x01
#define MCP3424_PGA_X4_GAIN 0x02
#define MCP3424_PGA_X8_GAIN 0x03

void MCP3424_Read(unsigned int *dt, unsigned char *cf)
{
	Wire_Start();
	Wire_Write(MCP3424_SLA_R);
	*dt = Wire_Ack();
    *dt <<= 8;
	*dt = Wire_Ack();
	*cf = Wire_Nack();
	Wire_Stop();   
}

void MCP3424_write(unsigned char data)
{
	Wire_Start();
	Wire_Write(MCP3424_SLA_W);
	Wire_Write(data);
	Wire_Stop();
}

#endif
