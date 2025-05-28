#pragma once

#include <stdio.h>  //输入输出
#include <time.h>   //time test.c 
#include <string.h>  //strcmp strcpy function.c 
#include <stdlib.h>  //system exit function.c 

//题库题目数量
#define TITLEnum 5
//抽题数量
#define DRAWnum 4
//单题分值
#define SCORE 10.0

//账号数量
#define IDnum 3
//账号长度
#define ACC 5
//密码长度
#define PWD 5

//创建结构体
typedef struct title_dank  //题库
{
	int num;               //题号
	char question[100];    //题干
	char answer[20];       //答案
	char user_answer[20];  //考生答案
	char judge_paper[10];  //判卷结果
}Title;

typedef struct account  //账户
{
	char acc[ACC+1];  //账号
	char pwd[PWD+1];  //密码
}Id;

typedef struct temp_date  //系统运行产生的临时数据
{
	int user_option[4];   //下标 0登录 1考试 2查看试卷
	int num[4];           //存储抽到的题号 
	float student_score;  //存储考生分数
	int count;            //记录答对题数
}Temp;


void write_date();  //写入结构体
void menu(int op);  //菜单
void use_function(int op);  //功能调用
void log_in();  //登录
void draw_out();  //抽题
void is_repeat(int i);  //题目重复 重抽
void student_exam();  //考生答题
void is_true();  //系统判卷
void print_judge();  //打印评判结果
void view();  //查看卷面