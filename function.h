#pragma once

#include <stdio.h>  //�������
#include <time.h>   //time test.c 
#include <string.h>  //strcmp strcpy function.c 
#include <stdlib.h>  //system exit function.c 

//�����Ŀ����
#define TITLEnum 5
//��������
#define DRAWnum 4
//�����ֵ
#define SCORE 10.0

//�˺�����
#define IDnum 3
//�˺ų���
#define ACC 5
//���볤��
#define PWD 5

//�����ṹ��
typedef struct title_dank  //���
{
	int num;               //���
	char question[100];    //���
	char answer[20];       //��
	char user_answer[20];  //������
	char judge_paper[10];  //�о���
}Title;

typedef struct account  //�˻�
{
	char acc[ACC+1];  //�˺�
	char pwd[PWD+1];  //����
}Id;

typedef struct temp_date  //ϵͳ���в�������ʱ����
{
	int user_option[4];   //�±� 0��¼ 1���� 2�鿴�Ծ�
	int num[4];           //�洢�鵽����� 
	float student_score;  //�洢��������
	int count;            //��¼�������
}Temp;


void write_date();  //д��ṹ��
void menu(int op);  //�˵�
void use_function(int op);  //���ܵ���
void log_in();  //��¼
void draw_out();  //����
void is_repeat(int i);  //��Ŀ�ظ� �س�
void student_exam();  //��������
void is_true();  //ϵͳ�о�
void print_judge();  //��ӡ���н��
void view();  //�鿴����