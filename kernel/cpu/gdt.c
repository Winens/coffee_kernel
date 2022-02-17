//
// Created by winens on 2/17/22.
//

#include <cpu/gdt.h>
#include <stdint.h>
#include <stdio.h>

void GDT_Create_Desc(uint32_t base, uint32_t limit, uint16_t flag){
    uint64_t ds;
    ds = limit & 0x000F0000;
    ds |= (flag <<  8) & 0x00F0FF00;
    ds |= (base >> 16) & 0x000000FF;
    ds |=  base & 0xFF000000;
    ds <<= 32;
    ds |= base << 16;
    ds |= limit & 0x0000FFFF;

    printf("0x%.16llX\n", ds);
}

void GDT_Exec(){
    GDT_Create_Desc(0, 0, 0);
    GDT_Create_Desc(0, 0x000FFFFF, (GDT_CODE_PL0));
    GDT_Create_Desc(0, 0x000FFFFF, (GDT_DATA_PL0));
    GDT_Create_Desc(0, 0x000FFFFF, (GDT_CODE_PL3));
    GDT_Create_Desc(0, 0x000FFFFF, (GDT_DATA_PL3));
}