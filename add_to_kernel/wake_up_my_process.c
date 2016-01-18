#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops.
#include <asm/uaccess.h> // required for copy_from and copy_to user functions
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/wait.h> // Required for the wait queues
#include <linux/sched.h> // Required for task states (TASK_INTERRUPTIBLE etc )

asmlinkage int wake_up_my_process(int pid)
{
	int re = -1;
	struct task_struct *task;
	printk("Hello wake!!\n");

	for_each_process(task)
	{
		if(pid == task->pid)
		{
			printk("found process %i", pid);
			if(task->state != 0)
			{
				wake_up_process(task);
				re = 0;
				printk("wake up!");
			}
		}
	}
	return re;
}
