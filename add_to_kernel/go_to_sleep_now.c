#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops.
#include <asm/uaccess.h> // required for copy_from and copy_to user functions
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/wait.h> // Required for the wait queues
#include <linux/sched.h> // Required for task states (TASK_INTERRUPTIBLE etc )

static DECLARE_WAIT_QUEUE_HEAD(my_wait_queue);

asmlinkage void go_to_sleep_now()
{
	printk("Hello sleep!!\n");
	printk(KERN_INFO "process %i call gotosleepnow.\n", current->pid);
	sleep_on(&my_wait_queue);
}
