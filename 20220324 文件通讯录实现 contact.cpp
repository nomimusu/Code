//#include "contact.h"
//
//void InitContact(struct Contact* ps)
//{
//	//ʹ��memset()������data[MAX]���ռ��ֵ����Ϊ0
//	memset(ps->data, 0, sizeof(ps->data));
//	//���汣��0�˵���Ϣ
//	ps ->size = 0;
//}
//
//void Addcontact(struct Contact* ps)
//{
//	//���ͨѶ¼���������������������ʾ
//	if (ps->size == MAX)
//	{
//		printf("�����������޷��������");
//	}
//	else
//	{
//		printf("����������:>");
//		//psָ��con��con����1000����Ϣ��ͨѶ¼��size������ͨѶ¼������size�ҵ�ͨѶ¼�������ĸ�λ�ã��������λ���ҵ�ָ������
//		//C���Ե��ַ���Ϊ������ʽ,����������ƿ��Ա�ʾ���ַ,�ʶ��ַ������벻��Ҫ�ӵ�ַ����
//		//���������ַ������ͱ����ȵ����Ʋ���ֱ�ӱ�ʾ��ַ,����Ҫ�ӵ�ַ������
//		scanf_s("%s", ps->data[ps->size].name,20);
//		printf("����������:>");
//		scanf_s("%d", &(ps->data[ps->size].age));
//		printf("�������Ա�:>");
//		scanf_s("%s", ps->data[ps->size].gender,5);
//		printf("������绰:>");
//		scanf_s("%s", ps->data[ps->size].tele,12);
//		printf("�������ַ:>");
//		scanf_s("%s", ps->data[ps->size].addr,30);
//		//��֪�ͻ��洢�ɹ�
//		printf("��ӳɹ�\n");
//		//��ʾ������һ����Ա
//		ps->size++;
//	}
//}
//
//void Showcontact(const struct Contact*ps)
//{
//	if (ps->size == 0)
//	{
//		printf("ͨѶ¼Ϊ�ա�\n");
//	}
//	else
//	{
//		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
//		int i = 0;
//		for (i = 0; i < ps->size; i++)
//		{
//			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
//				ps->data[i].name,
//				ps->data[i].age,
//				ps->data[i].gender,
//				ps->data[i].tele,
//				ps->data[i].addr);
//		}
//	}
//}
//
////��ΪFindByName()�����Ĺ�����Ҫ��Delcontact(),Searchcontact()ʹ�ã����Ե�����װ
////��ϣ��FindByName()������¶������c�ļ�����ͷ�ļ�,����ǰ�����static,�Ժ������������������
////����ҵ��ˣ������������ڵ�Ԫ�ص��±꣬���û�ҵ�������-1
//static int FindByName(struct Contact*ps, char name[MAX_NAME])
//{
//	int i = 0;
//	for (i = 0; i < ps->size; i++)
//	{
//		if (0 == strcmp(ps->data[i].name, name))
//			//�ҵ��ˣ������±�
//			return i;
//	}
//	if (i == ps->size)
//	{
//		//�Ҳ���������-1;
//		return -1;
//	}
//}
//
//void Delcontact(struct Contact* ps)
//{
//	//����Ҫɾ��������
//	char name[MAX_NAME];
//	printf("������Ҫɾ�����˵�����:>");
//	scanf_s("%s", name, MAX_NAME);
//
//	int pos = FindByName(ps, name);
//
//	if (-1 == pos)
//	{
//		printf("Ҫɾ�����˲����ڡ�\n");
//	}
//	else
//	{
//		//��ǰһ��Ԫ�ظ������е�Ԫ��
//		int j = 0;
//		for (j = pos; j < ps->size - 1; j++)
//		{
//			ps->data[j] = ps->data[j + 1];
//		}
//		//ͨѶ¼��Ԫ�ظ�������һ��
//		ps->size--;
//		printf("ɾ���ɹ���\n");
//	}
//	////ȷ��Ҫɾ�������Ƿ����
//	//int i = 0;
//	//for (i = 0; i < ps->size; i++)
//	//{
//	//	//���Ҫɾ�����˵����ִ���
//	//	if (0 == strcmp(name, ps->data[i].name))
//	//	{
//	//		break;
//	//	}
//	//}
//	////��Ҫ�ų��������н����Ҳû���ҵ�Ҫɾ�����˵����
//	//if (i == ps->size)
//	//{
//	//	
//	//}
//	////�ҵ���ɾ�����˵��±�,��ʱ��i��Ҫɾ����Ԫ�ص��±�
//	//else
//	//{
//	//	//��ǰһ��Ԫ�ظ������е�Ԫ��
//	//	int j = 0;
//	//	for (j = i; j < ps->size - 1; j++)
//	//	{
//	//		ps->data[j] = ps->data[j + 1];
//	//	}
//	//	//ͨѶ¼��Ԫ�ظ�������һ��
//	//	ps->size--;
//	//	printf("ɾ���ɹ���\n");
//	//}
//}
//
//void Searchcontact(struct Contact*ps)
//{
//	char name[MAX_NAME];
//	printf("������Ҫ���ҵ��˵�����:>");
//	scanf_s("%s", name, MAX_NAME);
//
//	int pos = FindByName(ps, name);
//	if (-1 == pos)
//	{
//		printf("����ϵ�˲����ڡ�\n");
//	}
//	else
//	{
//		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
//		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
//				ps->data[pos].name,
//				ps->data[pos].age,
//				ps->data[pos].gender,
//				ps->data[pos].tele,
//				ps->data[pos].addr);
//		}
//}
//
//void Modifycontact(struct Contact*ps)
//{
//	//����Ҫ���ҵ���ϵ�˵�����
//	char name[MAX_NAME];
//	printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
//	scanf_s("%s", name, MAX_NAME);
//
//	int pos = FindByName(ps, name);
//	if (-1 == pos)
//	{
//		printf("�޷��ҵ�Ҫ�޸ĵ���ϵ�ˡ�\n");
//	}
//	else
//	{
//		printf("�������µ�����:>");
//		scanf_s("%s", ps->data[pos].name, MAX_NAME);
//		printf("����������:>");
//		scanf_s("%d", &(ps->data[pos].age));
//		printf("�������Ա�:>");
//		scanf_s("%s", ps->data[pos].gender, MAX_GENDER);
//		printf("������绰:>");
//		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
//		printf("�������ַ:>");
//		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
//		//��֪�ͻ��洢�ɹ�
//		printf("�޸ĳɹ�\n");
//	}
//}
//
////
////#include "contact.h"
////
////
////void Initcontact(struct Contact*ps)
////{
////	//��ͨѶ¼��1000�˵���Ϣȫ����ʼ��Ϊ0
////	//��һ������ps->data����һ��ָ�룬ָ��Ҫ�����ڴ��
////	//�ڶ�������0����Ҫ�����õ�ֵ����ֵ��int���ͽ��д��ݣ�������������ڴ��ʱʹ�õ��Ǹ�ֵ���޷����ַ�����
////	//����������sizeof(ps->data),Ҫ�����ó�0���ַ���
////	memset(ps->data,0,sizeof(ps->data));
////	ps->size = 0;
////}
////
////void Addcontact(struct Contact*ps)
////{
////	if (MAX == ps->size)
////	{
////		printf("�����������޷��������\n");
////	}
////	else
////	{
////		printf("����������:>");
////		scanf_s("%s", ps->data[ps->size].name, MAX_NAME);
////		printf("����������:>");
////		scanf_s("%d", &(ps->data[ps->size].age));
////		printf("�������Ա�:>");
////		scanf_s("%s", ps->data[ps->size].gender, MAX_GENDER);
////		printf("������绰:>");
////		scanf_s("%s", ps->data[ps->size].tele, MAX_TELE);
////		printf("�������ַ:>");
////		scanf_s("%s", ps->data[ps->size].addr, MAX_ADDR);
////		printf("��ӳɹ�\n");
////		ps->size++;
////	}
////}
////
////void Showcontact(struct Contact*ps)
////{
////	int i = 0;
////	if (0 == ps->size)
////	{
////		printf("ͨѶ¼Ϊ��\n");
////	}
////	else
////	{
////		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
////		int i = 0;
////		for (i = 0; i < ps->size; i++)
////		{
////			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
////				ps->data[i].name,
////				ps->data[i].age,
////				ps->data[i].gender,
////				ps->data[i].tele,
////				ps->data[i].addr);
////		}
////	}
////}


//ͨѶ¼�ֺ����ľ���ʵ��

#include "20220324 �ļ�ͨѶ¼ʵ��.h"

void CheckCapacity(struct Contact* ps);

void load_contact(struct Contact* ps)
{
	//���ļ�
	FILE* pfRead = fopen("Contact.txt", "rb");
	if (pfRead == NULL)
	{
		printf("Load Contact Failed :: %s\n", strerror(errno));
		return;
	}
	//���ļ��е�ͨѶ¼��Ϣ���뵽ͨѶ¼
	//fread�����ķ���ֵ��ʵ�ʶ�ȡ��Ԫ�ظ������������ÿ�ζ���ȡ�ɹ�1��Ԫ�أ���ô�ͻ᷵��1
	//Ԫ�ض�ȡ���֮�󣬾ͻ᷵��0�����Կ��Ը���fread�ķ���ֵ����Ϊ�жϺ�ʱ�������
	while (fread(&(ps->data[ps->size]), sizeof(PeoInfo), 1, pfRead))
	{
		//��������Ƿ��㹻
		CheckCapacity(ps);
		ps->size += 1;
	}
	//�ر��ļ�
	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(struct Contact* ps)
{
	//��̬ͨѶ¼Ĭ�ϵĿռ�ΪDEFAULT_CAPACITY
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	//�ж�malloc�������ص��Ƿ��ǿ�ָ��
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_CAPACITY;

	//�����´�ͨѶ¼��ʱ����Ҫ���ļ���洢��ͨѶ¼��Ϣ���뵽ͨѶ¼��
	load_contact(ps);
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		//��������
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���������ɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
		
		
	}
}

void add_contact(struct Contact* ps)
{
	//���ͨѶ¼�����Ƿ�������������˾���Ҫ��������
	//��������������ͨѶ¼�ռ�
	//����δ�����������κβ���
	CheckCapacity(ps);

	//��������
		printf("����������:>");
		scanf_s("%s", ps->data[ps->size].name, MAX_NAME);
		printf("����������:>");
		scanf_s("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf_s("%s", ps->data[ps->size].gender, MAX_GENDER);
		printf("������绰:>");
		scanf_s("%s", ps->data[ps->size].tele, MAX_TELE);
		printf("������סַ:>");
		scanf_s("%s", ps->data[ps->size].addr, MAX_ADDR);
		printf("�����ϵ�˳ɹ�\n");
		ps->size++;
	//}
}

void show_contact(struct Contact* ps)
{
	//���û���κ���ϵ��
	int i = 0;
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ��");
	}
	else
	{
		printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s%-20d%-20s%-20s%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].gender,
				ps->data[i].tele,
				ps->data[i].addr
				);
		}
	}
}

//Del, Search, Modify, Sort�����漰�����������в���
//��ϣ��FindbyName()�������ļ����ã�����ʹ��static��������������
static int FindbyName(struct Contact *ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
			return i;
	}

	if (i == ps->size)
		return -1;
}

void del_contact(struct Contact* ps)
{
	//Ҫɾ������ϵ�˵�����
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ������ϵ��:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindbyName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < ps->size -1; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		printf("ɾ���ɹ�\n");
		ps->size--;
	}
}

void search_contact(struct Contact *ps)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ���ϵ��:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = FindbyName(ps, name);
	if (-1 == pos)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s%-20d%-20s%-20s%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].gender,
			ps->data[pos].tele,
			ps->data[pos].addr
			);
	}
}

void modify_contact(struct Contact *ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = FindbyName(ps, name);
	if (-1 == pos)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("�������µ�����:>");
		scanf_s("%s", ps->data[pos].name, MAX_NAME);
		printf("�������µ�����:>");
		scanf_s("%d", &(ps->data[pos].age));
		printf("�������µ��Ա�:>");
		scanf_s("%s", ps->data[pos].gender, MAX_GENDER);
		printf("�������µĵ绰:>");
		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
		printf("�������µĵ�ַ:>");
		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
		printf("�޸����\n");
	}
}


void sort_contact(struct Contact *ps)
{
	int i = 0;
	//��Ҫ��size-1����ϵ�˽�������
	for (i = 0; i < ps->size - 1; i++)
	{
		//ÿһ��������Ҫ�Ա�sz-1-j��
		int j = 0;
		//�����Ѿ�������
		int flag = 1;
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if (strcmp(ps->data[j].name,ps->data[j+1].name) > 0)
			{
				struct PeoInfo tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
				flag = 0;
			}
			if (1 == flag)
			{
				break;
			}
		}
	}
}

void destory_contact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void save_contact(struct Contact* ps)
{
	int i = 0;
	//���ļ�
	FILE* pfWrite = fopen("Contact.txt", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//��ͨѶ¼д���ļ�
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&ps->data[i], sizeof(struct PeoInfo), 1, pfWrite);
	}
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite= NULL;

}