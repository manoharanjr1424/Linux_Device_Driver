#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/io.h>
#include<linux/delay.h>
#include"gpio.h"


static void __iomem *gpio;

static int __init moduleInitialization(void) {
	unsigned int retval;
	unsigned int readvalue;
	printk("Kernel Module was Getting Initalized\n");
	
	gpio = ioremap(GPIO_BASE_ADDR,GPIO_BASE_SIZE);

	if( !gpio ){ 
		printk("Gpio Not Remapped Propelry");
		return -ENOMEM;
	}

	readvalue = ioread32(gpio+GPFSEL1);
	readvalue &=~(7 << 21);
	readvalue |=(1 << 21);
	iowrite32(readvalue, (gpio+GPFSEL1));
	
	
	iowrite32((1 << 17),(gpio+GPSET0));

	return 0;
}

static void __exit moduleExiting(void) {
	iowrite32((1 << 17),(gpio+GPCLR0));
	iounmap(gpio);
	printk("Device was Removed from Device \n");
}



module_init(moduleInitialization);
module_exit(moduleExiting);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MANOHARAN JAYAKUMAR");
MODULE_DESCRIPTION("Led Toggling using the iorrmap function");
