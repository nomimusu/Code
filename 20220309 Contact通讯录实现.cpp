//test.c ���ڲ���
//contact.c ���ں�������
//contact.h ����ͷ�ļ�
//���1000��������Ϣ�����������䡢�Ա𡢵绰��סַ������š���ɾ��ġ���ӡ������Ϣ

#include "contact.h"

void menu()
{
	printf("********1.add       2.del************\n");
	printf("********3.search    4.modify*********\n");
	printf("********5.show      6.sort***********\n");
	printf("********0.exit            ***********\n");
}

int main()
{
	int input = 0;
	//����ͨѶ¼,�����ܹ���1000���˵���Ϣ�Լ���¼�����ж����˵���Ϣ
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			//��ͨѶ¼����ӳ�Ա��Ϣ
			Addcontact(&con);
			break;
		case DEL:
			//ɾ��ͨѶ¼��ĳ�Ա
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			printf("�˳�ͨѶ¼��\n");
			break;
		default:
			printf("�������");
			break;
		}
	} while (input);

	return 0;
}