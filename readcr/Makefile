obj-m	:= hello.o 
KDIR	:= /lib/modules/$(shell uname -r)/build
PWD		:= $(shell pwd)
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	rm hello.ko hello.mod.c hello.mod.o hello.o modules.order Module.symvers

