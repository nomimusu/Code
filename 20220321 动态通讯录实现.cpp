////test.c ���ڲ���
////contact.c ���ں�������
////contact.h ����ͷ�ļ�
////���1000��������Ϣ�����������䡢�Ա𡢵绰��סַ������š���ɾ��ġ���ӡ������Ϣ
//
//#include "contact.h"
//
//void menu()
//{
//	printf("********1.add       2.del************\n");
//	printf("********3.search    4.modify*********\n");
//	printf("********5.show      6.sort***********\n");
//	printf("********0.exit            ***********\n");
//}
//
//int main()
//{
//	int input = 0;
//	//����ͨѶ¼,�����ܹ���1000���˵���Ϣ�Լ���¼�����ж����˵���Ϣ
//	struct Contact con;
//	//��ʼ��ͨѶ¼
//	InitContact(&con);
//
//	do{
//		menu();
//		printf("��ѡ��");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			//��ͨѶ¼����ӳ�Ա��Ϣ
//			Addcontact(&con);
//			break;
//		case DEL:
//			//ɾ��ͨѶ¼��ĳ�Ա
//			Delcontact(&con);
//			break;
//		case SEARCH:
//			Searchcontact(&con);
//			break;
//		case MODIFY:
//			Modifycontact(&con);
//			break;
//		case SHOW:
//			Showcontact(&con);
//			break;
//		case SORT:
//			break;
//		case EXIT:
//			printf("�˳�ͨѶ¼��\n");
//			break;
//		default:
//			printf("�������");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//
//#include "contact.h"
//
//void menu()
//{
//	printf("****1.ADD      2.DEL*******\n");
//	printf("****3.SEARCH   4.MODIFY****\n");
//	printf("****5.SHOW     0.EXIT******\n");
//
//}
//
//int main()
//{
//	int input = 0;
//	//����һ��ͨѶ¼
//	struct Contact con;
//	//��ʼ��ͨѶ¼����ָ����Ϊ0��
//	Initcontact(&con);
//
//	do{
//		menu();
//		printf("��ѡ��:>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			Addcontact(&con);
//			break;
//		case DEL:
//			break;
//		case SEARCH:
//			break;
//		case MODIFY:
//			break;
//		case SHOW:
//			Showcontact(&con);
//			break;
//		case EXIT:
//			printf("�˳�ͨѶ¼\n");
//		default:
//			printf("�����������������\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//��ͨѶ¼���в���
//���ò˵�����ͨ��do....while()������ѭ����switch case()���ѡ��˵����ﲻͬ�Ĺ���

#include "20220321 ��̬ͨѶ¼ʵ��.h"

void menu()
{
	printf("****1.Add        2.Del**************\n");
	printf("****3.Search     4.Modify***********\n");
	printf("****5.Show       6.Sort*************\n");
	printf("****0.Exit             *************\n");
}

void test()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case Add:
			add_contact(&con);
			break;
		case Del:
			del_contact(&con);
			break;
		case Search:
			search_contact(&con);
			break;
		case Modify:
			modify_contact(&con);
			break;
		case Show:
			show_contact(&con);
			break;
		case Sort:
			sort_contact(&con);
			break;
		case Exit:
			//����ͨѶ¼���ͷſ��ٵĶ�̬�ڴ�ռ�
			destory_contact(&con);
			printf("�˳�����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}