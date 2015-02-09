#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
    printk(KERN_INFO "Hello, world\n");
    unsigned long long cr0, cr2, cr3, cr4;
#ifdef __x86_64__
    __asm__ __volatile__ (
        "mov %%cr0, %%rax\n\t"
        "mov %%eax, %0\n\t"
        "mov %%cr2, %%rax\n\t"
        "mov %%eax, %1\n\t"
        "mov %%cr3, %%rax\n\t"
        "mov %%eax, %2\n\t"
        "mov %%cr4, %%rax\n\t"
        "mov %%eax, %3\n\t"
    : "=m" (cr0), "=m" (cr2), "=m" (cr3), "=m" (cr4)
    : /* no input */
    : "%rax"
    );
    printk(KERN_INFO "cr0 = 0x%llX\n", cr0);
    printk(KERN_INFO "cr2 = 0x%llX\n", cr2);
    printk(KERN_INFO "cr3 = 0x%llX\n", cr3);
    printk(KERN_INFO "cr4 = 0x%llX\n", cr4);
#elif defined(__i386__)
#endif
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

