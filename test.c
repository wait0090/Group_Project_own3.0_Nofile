#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

int main()
{
	write_date();
	srand((unsigned int)time(NULL));  //��ʼ�������������
	printf("******************************  ��ѧ���������  ******************************\n\n");
	int op = 1;  //�û�ѡ��
	menu(op);  //��ӡ�˵�
	while (1)
	{
		printf("��ѡ��>");  //ѡ��˵��еĹ���
		scanf("%d", &op);
		if (op == 4)  //�˳�ϵͳ
		{
			break;
		}
		else
		{
			use_function(op); //ִ���û���ѡ����
			printf("\n");  //��ӡ���� ��������
		}
	}
	return 0;
}