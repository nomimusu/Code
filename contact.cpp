#include "contact.h"

void InitContact(struct Contact* ps)
{
	//使用memset()函数将data[MAX]这块空间的值都设为0
	memset(ps->data, 0, sizeof(ps->data));
	//里面保存0人的信息
	ps ->size = 0;
}

void Addcontact(struct Contact* ps)
{
	//如果通讯录里面的容量已满，发出提示
	if (ps->size == MAX)
	{
		printf("容量已满，无法继续添加");
	}
	else
	{
		printf("请输入姓名:>");
		//ps指向con，con包含1000人信息的通讯录和size，先找通讯录，根据size找到通讯录里具体的哪个位置，根据这个位置找到指定参数
		//C语言的字符串为数组形式,而数组的名称可以表示其地址,故对字符串输入不需要加地址符。
		//而单独的字符、整型变量等的名称不能直接表示地址,故需要加地址符。”
		scanf_s("%s", ps->data[ps->size].name,20);
		printf("请输入年龄:>");
		scanf_s("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf_s("%s", ps->data[ps->size].gender,5);
		printf("请输入电话:>");
		scanf_s("%s", ps->data[ps->size].tele,12);
		printf("请输入地址:>");
		scanf_s("%s", ps->data[ps->size].addr,30);
		//告知客户存储成功
		printf("添加成功\n");
		//表示增加了一个成员
		ps->size++;
	}
}

void Showcontact(const struct Contact*ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空。\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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

//因为FindByName()函数的功能需要被Delcontact(),Searchcontact()使用，所以单独封装
//不希望FindByName()函数暴露在其他c文件或者头文件,所以前面加上static,对函数的作用域进行限制
//如果找到了，返回名字所在的元素的下标，如果没找到，返回-1
static int FindByName(struct Contact*ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			//找到了，返回下标
			return i;
	}
	if (i == ps->size)
	{
		//找不到，返回-1;
		return -1;
	}
}

void Delcontact(struct Contact* ps)
{
	//输入要删除的名字
	char name[MAX_NAME];
	printf("请输入要删除的人的名字:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(ps, name);

	if (-1 == pos)
	{
		printf("要删除的人不存在。\n");
	}
	else
	{
		//将前一个元素覆盖现有的元素
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		//通讯录的元素个数少了一个
		ps->size--;
		printf("删除成功。\n");
	}
	////确认要删除的人是否存在
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	//如果要删除的人的名字存在
	//	if (0 == strcmp(name, ps->data[i].name))
	//	{
	//		break;
	//	}
	//}
	////需要排除遍历所有结果，也没有找到要删除的人的情况
	//if (i == ps->size)
	//{
	//	
	//}
	////找到被删除的人的下标,此时的i是要删除的元素的下标
	//else
	//{
	//	//将前一个元素覆盖现有的元素
	//	int j = 0;
	//	for (j = i; j < ps->size - 1; j++)
	//	{
	//		ps->data[j] = ps->data[j + 1];
	//	}
	//	//通讯录的元素个数少了一个
	//	ps->size--;
	//	printf("删除成功。\n");
	//}
}

void Searchcontact(struct Contact*ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的人的姓名:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("该联系人不存在。\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
	//输入要查找的联系人的名字
	char name[MAX_NAME];
	printf("请输入要修改的联系人的名字:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("无法找到要修改的联系人。\n");
	}
	else
	{
		printf("请输入新的姓名:>");
		scanf_s("%s", ps->data[pos].name, MAX_NAME);
		printf("请输入年龄:>");
		scanf_s("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf_s("%s", ps->data[pos].gender, MAX_GENDER);
		printf("请输入电话:>");
		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
		printf("请输入地址:>");
		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
		//告知客户存储成功
		printf("修改成功\n");
	}
}