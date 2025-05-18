#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/printk.h>



#define DEVICE_MAJOR_NUMBER 24

int retval = 0;

static int device_open(struct inode *device_inode, struct file *device_file);
static int device_close(struct inode *device_inode, struct file *device_file);

static struct file_operations  filesoperation = {
	.open = device_open,
	.release = device_close,
};

/*
	Here i Demonstrated the members which are all present in the inode structure and 
	file structure 
	Src : https://elixir.bootlin.com/linux/v6.8.12/source/include/linux/fs.h
	Refer the Above link for structure members 

*/
static int device_open(struct inode *device_inode, struct file *device_file) {
	pr_info("Device Major Number %d Device Minor Number %d\n",imajor(device_inode),iminor(device_inode));
	pr_info("Device Mode 0x%x\n", device_file->f_mode);
	pr_info("Device file Position 0x%lld\n",device_file->f_pos);
	pr_info("Device flag 0x%x\n", device_file->f_flags);
	
	return 0;
}


static int device_close(struct inode *device_inode, struct file *device_file) {
	pr_info("Device was Closed Successfully \n");
	return 0;
}



static int __init moduleInit(void) {
	retval = register_chrdev(DEVICE_MAJOR_NUMBER,"mano_device_01", &filesoperation);
	if( retval >= 0 ) {
		printk("Device Initilazed\n");
		return 0;
	}else {
		printk("Device was Not initialized\n");
		return -1;
	}
}

static void __exit moduleExit(void) {
	unregister_chrdev(DEVICE_MAJOR_NUMBER,"mano_device_01");
	printk("Module was Released\n");
}

module_init(moduleInit);
module_exit(moduleExit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Manoharan");
MODULE_DESCRIPTION("Initial Basic Device Module");


