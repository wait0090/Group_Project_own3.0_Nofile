#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

int main()
{
	write_date();
	srand((unsigned int)time(NULL));  //初始化随机数发生器
	printf("******************************  大学计算机考试  ******************************\n\n");
	int op = 1;  //用户选择
	menu(op);  //打印菜单
	while (1)
	{
		printf("请选择：>");  //选择菜单中的功能
		scanf("%d", &op);
		if (op == 4)  //退出系统
		{
			break;
		}
		else
		{
			use_function(op); //执行用户所选功能
			printf("\n");  //打印空行 界面美化
		}
	}
	return 0;
}