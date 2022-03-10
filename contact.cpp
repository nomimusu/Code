#include "contact.h"

void InitContact(struct Contact* ps)
{
	//ʹ��memset()������data[MAX]���ռ��ֵ����Ϊ0
	memset(ps->data, 0, sizeof(ps->data));
	//���汣��0�˵���Ϣ
	ps ->size = 0;
}

void Addcontact(struct Contact* ps)
{
	//���ͨѶ¼���������������������ʾ
	if (ps->size == MAX)
	{
		printf("�����������޷��������");
	}
	else
	{
		printf("����������:>");
		//psָ��con��con����1000����Ϣ��ͨѶ¼��size������ͨѶ¼������size�ҵ�ͨѶ¼�������ĸ�λ�ã��������λ���ҵ�ָ������
		//C���Ե��ַ���Ϊ������ʽ,����������ƿ��Ա�ʾ���ַ,�ʶ��ַ������벻��Ҫ�ӵ�ַ����
		//���������ַ������ͱ����ȵ����Ʋ���ֱ�ӱ�ʾ��ַ,����Ҫ�ӵ�ַ������
		scanf_s("%s", ps->data[ps->size].name,20);
		printf("����������:>");
		scanf_s("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf_s("%s", ps->data[ps->size].gender,5);
		printf("������绰:>");
		scanf_s("%s", ps->data[ps->size].tele,12);
		printf("�������ַ:>");
		scanf_s("%s", ps->data[ps->size].addr,30);
		//��֪�ͻ��洢�ɹ�
		printf("��ӳɹ�\n");
		//��ʾ������һ����Ա
		ps->size++;
	}
}

void Showcontact(const struct Contact*ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].gender,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//��ΪFindByName()�����Ĺ�����Ҫ��Delcontact(),Searchcontact()ʹ�ã����Ե�����װ
//��ϣ��FindByName()������¶������c�ļ�����ͷ�ļ�,����ǰ�����static,�Ժ������������������
//����ҵ��ˣ������������ڵ�Ԫ�ص��±꣬���û�ҵ�������-1
static int FindByName(struct Contact*ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			//�ҵ��ˣ������±�
			return i;
	}
	if (i == ps->size)
	{
		//�Ҳ���������-1;
		return -1;
	}
}

void Delcontact(struct Contact* ps)
{
	//����Ҫɾ��������
	char name[MAX_NAME];
	printf("������Ҫɾ�����˵�����:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(ps, name);

	if (-1 == pos)
	{
		printf("Ҫɾ�����˲����ڡ�\n");
	}
	else
	{
		//��ǰһ��Ԫ�ظ������е�Ԫ��
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		//ͨѶ¼��Ԫ�ظ�������һ��
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
	////ȷ��Ҫɾ�������Ƿ����
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	//���Ҫɾ�����˵����ִ���
	//	if (0 == strcmp(name, ps->data[i].name))
	//	{
	//		break;
	//	}
	//}
	////��Ҫ�ų��������н����Ҳû���ҵ�Ҫɾ�����˵����
	//if (i == ps->size)
	//{
	//	
	//}
	////�ҵ���ɾ�����˵��±�,��ʱ��i��Ҫɾ����Ԫ�ص��±�
	//else
	//{
	//	//��ǰһ��Ԫ�ظ������е�Ԫ��
	//	int j = 0;
	//	for (j = i; j < ps->size - 1; j++)
	//	{
	//		ps->data[j] = ps->data[j + 1];
	//	}
	//	//ͨѶ¼��Ԫ�ظ�������һ��
	//	ps->size--;
	//	printf("ɾ���ɹ���\n");
	//}
}

void Searchcontact(struct Contact*ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵�����:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("����ϵ�˲����ڡ�\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].gender,
				ps->data[pos].tele,
				ps->data[pos].addr);
		}
}

void Modifycontact(struct Contact*ps)
{
	//����Ҫ���ҵ���ϵ�˵�����
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("�޷��ҵ�Ҫ�޸ĵ���ϵ�ˡ�\n");
	}
	else
	{
		printf("�������µ�����:>");
		scanf_s("%s", ps->data[pos].name, MAX_NAME);
		printf("����������:>");
		scanf_s("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf_s("%s", ps->data[pos].gender, MAX_GENDER);
		printf("������绰:>");
		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
		printf("�������ַ:>");
		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
		//��֪�ͻ��洢�ɹ�
		printf("�޸ĳɹ�\n");
	}
}