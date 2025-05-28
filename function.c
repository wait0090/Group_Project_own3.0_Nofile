#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

Title title[TITLEnum];    //题库抽题数
Id id[IDnum];            //注册的账号
Id user_temp;            //登录的账号

Temp tem = { { 0,0,0,0 },{0,0,0,0},{0},{0} };  //临时数据

//写入结构体
void write_date()
{
	//题库数据
	title[0].num = 1;  //题号
	title[1].num = 2;
	title[2].num = 3;
	title[3].num = 4;
	title[4].num = 5;

	strcpy(title[0].question, "计算机中总线包括地址总线、数据总线和____总线。\0");         //题干
	strcpy(title[1].question, "复制整个屏幕到剪切板，使用____键。\0");
	strcpy(title[2].question, "十进制数10的二进制表示为____。\0");
	strcpy(title[3].question, "从图表的存在形式上，Excel提供了嵌入式图表和____两种。\0");
	strcpy(title[4].question, "LAN、MAN和WAN分别代表的是局域网、城域网和____。\0");

	strcpy(title[0].answer, "控制\0");          //正确答案
	strcpy(title[1].answer, "PrintScreen\0");
	strcpy(title[2].answer, "1010\0");
	strcpy(title[3].answer, "工作表式图表\0");
	strcpy(title[4].answer, "广域网\0");


	//设置账号
	strcpy(id[0].acc, "1111\0");  //设置账号
	strcpy(id[0].pwd, "1111\0");  //设置密码
	strcpy(id[1].acc, "2222\0");  //设置账号
	strcpy(id[1].pwd, "2222\0");  //设置密码
	strcpy(id[2].acc, "3333\0");  //设置账号
	strcpy(id[2].pwd, "3333\0");  //设置密码
}

//菜单
void menu(int op)
{
	printf("            **************************菜单**************************\n");
	switch (op)
	{
		case 1:
			printf("            ********************  [1] 登录      ********************\n");
		case 2:
			printf("            ********************  [2] 开始考试  ********************\n");
		case 3:
			printf("            ********************  [3] 查看答卷  ********************\n");
		case 4:
			printf("            ********************  [4] 退出系统  ********************\n\n");
			break;
		default:
			printf("选择错误！请重新选择\n\n");
	}
}

//功能调用
void use_function(int op)
{
	switch (op)
	{
		case 1:  //登录
			if (tem.user_option[0] == 0)  //未登录
			{
				log_in();
			}
			else
			{
				printf("你的账号已登录！\n请勿重复登录！\n\n");
			}
			break;
		case 2:  //考试
			if (tem.user_option[0] != 0)  //判断登录状态
			{
				if (tem.user_option[1] == 0)
				{
					draw_out();
					student_exam();
					is_true();
					print_judge();
				}
				else
				{
					printf("不能重复刷分哦！\n\n");
				}
				//选择菜单
				static int i = 1;
				if (i)
				{
					menu(3);
					i = 0;
				}				
			}
			else
			{
				printf("请先登录再操作哦！\n\n");
			}
			break;
		case 3:  //查看答卷
			if (tem.user_option[0] != 0)  //判断登录状态
			{
				if (tem.user_option[1] != 0)
				{
					system("cls");
					printf("******************************  大学计算机考试  ******************************\n\n");
					view();
				}
				else
				{
					printf("请认真答完题才能查看答卷哦！\n\n");
				}
			}
			else
			{
				printf("请先登录再操作哦！\n\n");
			}
			break;
		default:
			printf("选择错误！请重新选择\n\n");
	}
}

//登录
void log_in()
{
	(tem.user_option[0])++;  //记录状态
	printf("请按照提示登录\n\n");

	//登录状态
	int situation = 0;  //系统未检测到当前账号（未注册）
	int m = 0;
	while (m < 3)
	{
		m++;
		//用户输入
		printf("请输入账号：>");
		scanf("%s", user_temp.acc);
		printf("请输入密码：>");
		scanf("%s", user_temp.pwd);
		printf("\n");  //打印空行 界面美化

		//系统验证
		int i = 0;
		for (i = 0; i < IDnum; i++)
		{
			if (strcmp(id[i].acc, user_temp.acc) == 0)  //账号验证成功
			{
				if (strcmp(id[i].pwd, user_temp.pwd) == 0)  //密码验证成功
				{
					situation = 1;  //成功登录
				}
				else
				{
					situation = -1;  //账号已注册 密码错误
				}
			}
		}
		if (situation == 1)
		{
			printf("登录成功！\n");
			printf("当前账号：%s\n\n", user_temp.acc);  //打印考生当前登录账号，以确认身份
			break;
		}
		else if (situation == -1)
		{
			printf("密码错误！\n\n");
		}
		else if (situation == 0)
		{
			printf("账号未注册！\n\n");
		}
	}
	if (m == 3)
	{
		printf("已连续三次账号验证错误！\n");
		(tem.user_option[0])--;  //记录状态
	}
}

//抽题
void draw_out()
{
	int i = 0;
	for (i = 0; i < DRAWnum; i++)  //循环四次 抽取四道题目题号 放入数组num
	{
		tem.num[i] = rand() % DRAWnum + 1;  //抽题
		is_repeat(i);
	}
}

//题目重复 重抽
void is_repeat(int i)
{
	int j = 0;
	for (j = 0; j < i; j++)   //重复
	{
		if (tem.num[j] == tem.num[i])
		{
			tem.num[i] = rand() % DRAWnum + 1;  //重新抽题
			is_repeat(i);  //递归
			break;
		}
	}
}

//考生答题
void student_exam()
{
	(tem.user_option[1])++;  //记录考试状态

	int i = 0;
	for (i = 0; i < DRAWnum; i++)
	{
		system("cls");  //清空上一题

		printf("******************************  考试中  ******************************\n\n");  //考试界面

		printf("%d.", i + 1);  //打印题号
		printf("%s", title[tem.num[i] - 1].question);  //打印题目

		printf("\n请答题：>");
		scanf("%s", title[tem.num[i] - 1].user_answer);  //考生输入答案
	}
	printf("\n");  //打印空行 界面美化
}

//系统判卷
void is_true()
{
	int i = 0;
	for (i = 0; i < DRAWnum; i++)
	{
		if (strcmp(title[tem.num[i] - 1].answer, title[tem.num[i] - 1].user_answer) == 0)  //与题库答案对比
		{
			(tem.count)++;
			strcpy(title[tem.num[i] - 1].judge_paper, "正确\0");  //存入评判结果
		}
		else
		{
			strcpy(title[tem.num[i] - 1].judge_paper, "错误\0");  //存入评判结果
		}
	}
}

//打印评判结果
void print_judge()
{
	system("cls");
	printf("******************************  考试已结束  ******************************\n\n");
	tem.student_score = (tem.count) * SCORE;  //计算考生总分
	printf("满分：%.1f\n", (DRAWnum * SCORE));
	printf("答对%d道题\n", tem.count);
	printf("考生最终得分：%.1f\n", tem.student_score);

	//适当鼓励
	if (tem.count > (DRAWnum / 2))
	{
		printf("太棒了！\n\n");
	}
	else
	{
		printf("再接再厉！继续加油哦！\n\n");
	}
}

//查看卷面
void view()
{
	(tem.user_option[2])++;  //记录卷面查看情况
	printf("******************************  考生本次作答情况  ******************************\n\n");
	menu(3);
	printf("考生最终得分：%.1f\n\n", tem.student_score);
	int i = 0;
	for (i = 0; i < DRAWnum; i++)
	{
		printf("%d.", i + 1);
		printf("%s\n", title[tem.num[i] - 1].question);
		printf(" 正确答案：%s\n", title[tem.num[i] - 1].answer);
		printf(" 考生作答：%s\n", title[tem.num[i] - 1].user_answer);
		printf(" 系统判卷：%s\n\n", title[tem.num[i] - 1].judge_paper);
	}
}