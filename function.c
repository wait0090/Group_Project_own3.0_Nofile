#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

Title title[TITLEnum];    //��������
Id id[IDnum];            //ע����˺�
Id user_temp;            //��¼���˺�

Temp tem = { { 0,0,0,0 },{0,0,0,0},{0},{0} };  //��ʱ����

//д��ṹ��
void write_date()
{
	//�������
	title[0].num = 1;  //���
	title[1].num = 2;
	title[2].num = 3;
	title[3].num = 4;
	title[4].num = 5;

	strcpy(title[0].question, "����������߰�����ַ���ߡ��������ߺ�____���ߡ�\0");         //���
	strcpy(title[1].question, "����������Ļ�����а壬ʹ��____����\0");
	strcpy(title[2].question, "ʮ������10�Ķ����Ʊ�ʾΪ____��\0");
	strcpy(title[3].question, "��ͼ��Ĵ�����ʽ�ϣ�Excel�ṩ��Ƕ��ʽͼ���____���֡�\0");
	strcpy(title[4].question, "LAN��MAN��WAN�ֱ������Ǿ���������������____��\0");

	strcpy(title[0].answer, "����\0");          //��ȷ��
	strcpy(title[1].answer, "PrintScreen\0");
	strcpy(title[2].answer, "1010\0");
	strcpy(title[3].answer, "������ʽͼ��\0");
	strcpy(title[4].answer, "������\0");


	//�����˺�
	strcpy(id[0].acc, "1111\0");  //�����˺�
	strcpy(id[0].pwd, "1111\0");  //��������
	strcpy(id[1].acc, "2222\0");  //�����˺�
	strcpy(id[1].pwd, "2222\0");  //��������
	strcpy(id[2].acc, "3333\0");  //�����˺�
	strcpy(id[2].pwd, "3333\0");  //��������
}

//�˵�
void menu(int op)
{
	printf("            **************************�˵�**************************\n");
	switch (op)
	{
		case 1:
			printf("            ********************  [1] ��¼      ********************\n");
		case 2:
			printf("            ********************  [2] ��ʼ����  ********************\n");
		case 3:
			printf("            ********************  [3] �鿴���  ********************\n");
		case 4:
			printf("            ********************  [4] �˳�ϵͳ  ********************\n\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n\n");
	}
}

//���ܵ���
void use_function(int op)
{
	switch (op)
	{
		case 1:  //��¼
			if (tem.user_option[0] == 0)  //δ��¼
			{
				log_in();
			}
			else
			{
				printf("����˺��ѵ�¼��\n�����ظ���¼��\n\n");
			}
			break;
		case 2:  //����
			if (tem.user_option[0] != 0)  //�жϵ�¼״̬
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
					printf("�����ظ�ˢ��Ŷ��\n\n");
				}
				//ѡ��˵�
				static int i = 1;
				if (i)
				{
					menu(3);
					i = 0;
				}				
			}
			else
			{
				printf("���ȵ�¼�ٲ���Ŷ��\n\n");
			}
			break;
		case 3:  //�鿴���
			if (tem.user_option[0] != 0)  //�жϵ�¼״̬
			{
				if (tem.user_option[1] != 0)
				{
					system("cls");
					printf("******************************  ��ѧ���������  ******************************\n\n");
					view();
				}
				else
				{
					printf("�������������ܲ鿴���Ŷ��\n\n");
				}
			}
			else
			{
				printf("���ȵ�¼�ٲ���Ŷ��\n\n");
			}
			break;
		default:
			printf("ѡ�����������ѡ��\n\n");
	}
}

//��¼
void log_in()
{
	(tem.user_option[0])++;  //��¼״̬
	printf("�밴����ʾ��¼\n\n");

	//��¼״̬
	int situation = 0;  //ϵͳδ��⵽��ǰ�˺ţ�δע�ᣩ
	int m = 0;
	while (m < 3)
	{
		m++;
		//�û�����
		printf("�������˺ţ�>");
		scanf("%s", user_temp.acc);
		printf("���������룺>");
		scanf("%s", user_temp.pwd);
		printf("\n");  //��ӡ���� ��������

		//ϵͳ��֤
		int i = 0;
		for (i = 0; i < IDnum; i++)
		{
			if (strcmp(id[i].acc, user_temp.acc) == 0)  //�˺���֤�ɹ�
			{
				if (strcmp(id[i].pwd, user_temp.pwd) == 0)  //������֤�ɹ�
				{
					situation = 1;  //�ɹ���¼
				}
				else
				{
					situation = -1;  //�˺���ע�� �������
				}
			}
		}
		if (situation == 1)
		{
			printf("��¼�ɹ���\n");
			printf("��ǰ�˺ţ�%s\n\n", user_temp.acc);  //��ӡ������ǰ��¼�˺ţ���ȷ�����
			break;
		}
		else if (situation == -1)
		{
			printf("�������\n\n");
		}
		else if (situation == 0)
		{
			printf("�˺�δע�ᣡ\n\n");
		}
	}
	if (m == 3)
	{
		printf("�����������˺���֤����\n");
		(tem.user_option[0])--;  //��¼״̬
	}
}

//����
void draw_out()
{
	int i = 0;
	for (i = 0; i < DRAWnum; i++)  //ѭ���Ĵ� ��ȡ�ĵ���Ŀ��� ��������num
	{
		tem.num[i] = rand() % DRAWnum + 1;  //����
		is_repeat(i);
	}
}

//��Ŀ�ظ� �س�
void is_repeat(int i)
{
	int j = 0;
	for (j = 0; j < i; j++)   //�ظ�
	{
		if (tem.num[j] == tem.num[i])
		{
			tem.num[i] = rand() % DRAWnum + 1;  //���³���
			is_repeat(i);  //�ݹ�
			break;
		}
	}
}

//��������
void student_exam()
{
	(tem.user_option[1])++;  //��¼����״̬

	int i = 0;
	for (i = 0; i < DRAWnum; i++)
	{
		system("cls");  //�����һ��

		printf("******************************  ������  ******************************\n\n");  //���Խ���

		printf("%d.", i + 1);  //��ӡ���
		printf("%s", title[tem.num[i] - 1].question);  //��ӡ��Ŀ

		printf("\n����⣺>");
		scanf("%s", title[tem.num[i] - 1].user_answer);  //���������
	}
	printf("\n");  //��ӡ���� ��������
}

//ϵͳ�о�
void is_true()
{
	int i = 0;
	for (i = 0; i < DRAWnum; i++)
	{
		if (strcmp(title[tem.num[i] - 1].answer, title[tem.num[i] - 1].user_answer) == 0)  //�����𰸶Ա�
		{
			(tem.count)++;
			strcpy(title[tem.num[i] - 1].judge_paper, "��ȷ\0");  //�������н��
		}
		else
		{
			strcpy(title[tem.num[i] - 1].judge_paper, "����\0");  //�������н��
		}
	}
}

//��ӡ���н��
void print_judge()
{
	system("cls");
	printf("******************************  �����ѽ���  ******************************\n\n");
	tem.student_score = (tem.count) * SCORE;  //���㿼���ܷ�
	printf("���֣�%.1f\n", (DRAWnum * SCORE));
	printf("���%d����\n", tem.count);
	printf("�������յ÷֣�%.1f\n", tem.student_score);

	//�ʵ�����
	if (tem.count > (DRAWnum / 2))
	{
		printf("̫���ˣ�\n\n");
	}
	else
	{
		printf("�ٽ���������������Ŷ��\n\n");
	}
}

//�鿴����
void view()
{
	(tem.user_option[2])++;  //��¼����鿴���
	printf("******************************  ���������������  ******************************\n\n");
	menu(3);
	printf("�������յ÷֣�%.1f\n\n", tem.student_score);
	int i = 0;
	for (i = 0; i < DRAWnum; i++)
	{
		printf("%d.", i + 1);
		printf("%s\n", title[tem.num[i] - 1].question);
		printf(" ��ȷ�𰸣�%s\n", title[tem.num[i] - 1].answer);
		printf(" ��������%s\n", title[tem.num[i] - 1].user_answer);
		printf(" ϵͳ�о�%s\n\n", title[tem.num[i] - 1].judge_paper);
	}
}