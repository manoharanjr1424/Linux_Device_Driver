obj-m += basic.o
DEVICE_DRIVER_FILE_NAME = basic.ko
DEVICE_MAJOR_NUM = 24
DEVICE_MINOR_NUM = 0
DEVICE_NAME = mano_device
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	$(shell mknod /dev/$(DEVICE_NAME) c $(DEVICE_MAJOR_NUM) $(DEVICE_MINOR_NUM) )
	$(shell chmod 666 /dev/$(DEVICE_NAME))
	$(shell insmod $(DEVICE_DRIVER_FILE_NAME))
clean:
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) clean
	$(shell rmmod $(DEVICE_DRIVER_FILE_NAME))
	$(shell rm /dev/$(DEVICE_NAME))
