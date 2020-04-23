#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>

int main(int abc, char **xyz)
{
	printf("Invoking the 'sh_task_info ' systemcall \n");
	int pid = atoi(xyz[1]);
	long int ret_status = syscall(317,pid,xyz[2]);
	if(ret_status == 0)
	{
		printf("Systemcall is executed correctly\n");
		printf("Systemcall returned %ld\n", ret_status);
		//You can do sudo nano filename to see the contents of your file
		//You can also do dmesg to see the contents
	}
	else
	{
		printf("System call is not executed \n");
		printf("System call returned %ld\n",ret_status);
		perror("Error ");
		printf("Error number:  %d\n",errno);
	}
	return 0;
}