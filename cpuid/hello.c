#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");
#if 0 /*0 to use kernel header*/
static inline void cpuid(u32 id, u32 *a, u32 *b, u32 *c, u32 *d)
{
        asm volatile(".ifnc %%ebx,%3 ; movl  %%ebx,%3 ; .endif  \n\t"
                     "cpuid                                     \n\t"
                     ".ifnc %%ebx,%3 ; xchgl %%ebx,%3 ; .endif  \n\t"
                    : "=a" (*a), "=c" (*c), "=d" (*d), EBX_REG (*b)
                    : "a" (id)
        );
}
#endif
static int hello_init(void)
{
    printk(KERN_INFO "Hello, world\n");
    unsigned int eax, ebx, ecx, edx;
	cpuid(0x1, &eax, &ebx, &ecx, &edx);
	printk(KERN_INFO "%x %x %x %x\n", eax, ebx, ecx, edx);
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

