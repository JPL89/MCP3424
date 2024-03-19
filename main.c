// @File		MAIN.C		 		
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
#include "utils.h"
#include "ks0066.h"
#include "wire.h"
#include "mcp3424.h"

unsigned int dt;
unsigned char cf;

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    Wire_Init();            
    
    KS0066_Init();
    KS0066_Clear(0);
    KS0066_Clear(1);  
    KS0066_Goto(0,0);                   
    
    MCP3424_write(  MCP3424_CONTINUOUS_CONVERSION_MODE|
                    MCP3424_CHANNEL_2 | MCP3424_16_BIT_SELECTION);
    
    __delay_ms(500);   
    
    MCP3424_Read(&dt, &cf);
    
    unsigned int r = dt;
        
    KS0066_Char(48 + r / 1000 % 10);
    KS0066_Char(48 + r / 100 % 10);
    KS0066_Char(48 + r / 10 % 10);
    KS0066_Char(48 + r / 1 % 10);
    
    while(1);
    
    return;
}
