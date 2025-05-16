#ifndef _GPIO_H
#define _GPIO_H


#define GPIO_BASE_ADDR 0xfe200000
#define GPIO_BASE_SIZE 0xB4 
typedef enum {
    GPFSEL0                = 0x00,
    GPFSEL1                = 0x04,
    GPFSEL2                = 0x08,
    GPFSEL3                = 0x0C,
    GPFSEL4                = 0x10,
    GPFSEL5                = 0x14,
    GPSET0                 = 0x1C,
    GPSET1                 = 0x20,
    GPCLR0                 = 0x28,
    GPCLR1                 = 0x2C,
    GPLEV0                 = 0x34,
    GPLEV1                 = 0x38,
    GPEDS0                 = 0x40,
    GPEDS1                 = 0x44,
    GPREN0                 = 0x4C,
    GPREN1                 = 0x50,
    GPFEN0                 = 0x58,
    GPFEN1                 = 0x5C,
    GPHEN0                 = 0x64,
    GPHEN1                 = 0x68,
    GPLEN0                 = 0x70,
    GPLEN1                 = 0x74,
    GPAREN0                = 0x7C,
    GPAREN1                = 0x80,
    GPAFEN0                = 0x88,
    GPAFEN1                = 0x8C,
    GPIO_PUP_PDN_CNTRL_REG0 = 0xE4,
    GPIO_PUP_PDN_CNTRL_REG1 = 0xE8,
    GPIO_PUP_PDN_CNTRL_REG2 = 0xEC,
    GPIO_PUP_PDN_CNTRL_REG3 = 0xF0
} gpio_reg_offset_t;

#endif
