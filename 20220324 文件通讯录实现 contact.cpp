//#include "contact.h"
//
//void InitContact(struct Contact* ps)
//{
//	//使用memset()函数将data[MAX]这块空间的值都设为0
//	memset(ps->data, 0, sizeof(ps->data));
//	//里面保存0人的信息
//	ps ->size = 0;
//}
//
//void Addcontact(struct Contact* ps)
//{
//	//如果通讯录里面的容量已满，发出提示
//	if (ps->size == MAX)
//	{
//		printf("容量已满，无法继续添加");
//	}
//	else
//	{
//		printf("请输入姓名:>");
//		//ps指向con，con包含1000人信息的通讯录和size，先找通讯录，根据size找到通讯录里具体的哪个位置，根据这个位置找到指定参数
//		//C语言的字符串为数组形式,而数组的名称可以表示其地址,故对字符串输入不需要加地址符。
//		//而单独的字符、整型变量等的名称不能直接表示地址,故需要加地址符。”
//		scanf_s("%s", ps->data[ps->size].name,20);
//		printf("请输入年龄:>");
//		scanf_s("%d", &(ps->data[ps->size].age));
//		printf("请输入性别:>");
//		scanf_s("%s", ps->data[ps->size].gender,5);
//		printf("请输入电话:>");
//		scanf_s("%s", ps->data[ps->size].tele,12);
//		printf("请输入地址:>");
//		scanf_s("%s", ps->data[ps->size].addr,30);
//		//告知客户存储成功
//		printf("添加成功\n");
//		//表示增加了一个成员
//		ps->size++;
//	}
//}
//
//void Showcontact(const struct Contact*ps)
//{
//	if (ps->size == 0)
//	{
//		printf("通讯录为空。\n");
//	}
//	else
//	{
//		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
////因为FindByName()函数的功能需要被Delcontact(),Searchcontact()使用，所以单独封装
////不希望FindByName()函数暴露在其他c文件或者头文件,所以前面加上static,对函数的作用域进行限制
////如果找到了，返回名字所在的元素的下标，如果没找到，返回-1
//static int FindByName(struct Contact*ps, char name[MAX_NAME])
//{
//	int i = 0;
//	for (i = 0; i < ps->size; i++)
//	{
//		if (0 == strcmp(ps->data[i].name, name))
//			//找到了，返回下标
//			return i;
//	}
//	if (i == ps->size)
//	{
//		//找不到，返回-1;
//		return -1;
//	}
//}
//
//void Delcontact(struct Contact* ps)
//{
//	//输入要删除的名字
//	char name[MAX_NAME];
//	printf("请输入要删除的人的名字:>");
//	scanf_s("%s", name, MAX_NAME);
//
//	int pos = FindByName(ps, name);
//
//	if (-1 == pos)
//	{
//		printf("要删除的人不存在。\n");
//	}
//	else
//	{
//		//将前一个元素覆盖现有的元素
//		int j = 0;
//		for (j = pos; j < ps->size - 1; j++)
//		{
//			ps->data[j] = ps->data[j + 1];
//		}
//		//通讯录的元素个数少了一个
//		ps->size--;
//		printf("删除成功。\n");
//	}
//	////确认要删除的人是否存在
//	//int i = 0;
//	//for (i = 0; i < ps->size; i++)
//	//{
//	//	//如果要删除的人的名字存在
//	//	if (0 == strcmp(name, ps->data[i].name))
//	//	{
//	//		break;
//	//	}
//	//}
//	////需要排除遍历所有结果，也没有找到要删除的人的情况
//	//if (i == ps->size)
//	//{
//	//	
//	//}
//	////找到被删除的人的下标,此时的i是要删除的元素的下标
//	//else
//	//{
//	//	//将前一个元素覆盖现有的元素
//	//	int j = 0;
//	//	for (j = i; j < ps->size - 1; j++)
//	//	{
//	//		ps->data[j] = ps->data[j + 1];
//	//	}
//	//	//通讯录的元素个数少了一个
//	//	ps->size--;
//	//	printf("删除成功。\n");
//	//}
//}
//
//void Searchcontact(struct Contact*ps)
//{
//	char name[MAX_NAME];
//	printf("请输入要查找的人的姓名:>");
//	scanf_s("%s", name, MAX_NAME);
//
//	int pos = FindByName(ps, name);
//	if (-1 == pos)
//	{
//		printf("该联系人不存在。\n");
//	}
//	else
//	{
//		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
//	//输入要查找的联系人的名字
//	char name[MAX_NAME];
//	printf("请输入要修改的联系人的名字:>");
//	scanf_s("%s", name, MAX_NAME);
//
//	int pos = FindByName(ps, name);
//	if (-1 == pos)
//	{
//		printf("无法找到要修改的联系人。\n");
//	}
//	else
//	{
//		printf("请输入新的姓名:>");
//		scanf_s("%s", ps->data[pos].name, MAX_NAME);
//		printf("请输入年龄:>");
//		scanf_s("%d", &(ps->data[pos].age));
//		printf("请输入性别:>");
//		scanf_s("%s", ps->data[pos].gender, MAX_GENDER);
//		printf("请输入电话:>");
//		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
//		printf("请输入地址:>");
//		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
//		//告知客户存储成功
//		printf("修改成功\n");
//	}
//}
//
////
////#include "contact.h"
////
////
////void Initcontact(struct Contact*ps)
////{
////	//将通讯录种1000人的信息全部初始化为0
////	//第一个参数ps->data，是一个指针，指向要填充的内存块
////	//第二个参数0，是要被设置的值，该值以int类型进行传递，但函数在填充内存块时使用的是该值的无符号字符类型
////	//第三个参数sizeof(ps->data),要被设置成0的字符数
////	memset(ps->data,0,sizeof(ps->data));
////	ps->size = 0;
////}
////
////void Addcontact(struct Contact*ps)
////{
////	if (MAX == ps->size)
////	{
////		printf("容量已满，无法继续添加\n");
////	}
////	else
////	{
////		printf("请输入姓名:>");
////		scanf_s("%s", ps->data[ps->size].name, MAX_NAME);
////		printf("请输入年龄:>");
////		scanf_s("%d", &(ps->data[ps->size].age));
////		printf("请输入性别:>");
////		scanf_s("%s", ps->data[ps->size].gender, MAX_GENDER);
////		printf("请输入电话:>");
////		scanf_s("%s", ps->data[ps->size].tele, MAX_TELE);
////		printf("请输入地址:>");
////		scanf_s("%s", ps->data[ps->size].addr, MAX_ADDR);
////		printf("添加成功\n");
////		ps->size++;
////	}
////}
////
////void Showcontact(struct Contact*ps)
////{
////	int i = 0;
////	if (0 == ps->size)
////	{
////		printf("通讯录为空\n");
////	}
////	else
////	{
////		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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


//通讯录种函数的具体实现

#include "20220324 文件通讯录实现.h"

void CheckCapacity(struct Contact* ps);

void load_contact(struct Contact* ps)
{
	//打开文件
	FILE* pfRead = fopen("Contact.txt", "rb");
	if (pfRead == NULL)
	{
		printf("Load Contact Failed :: %s\n", strerror(errno));
		return;
	}
	//把文件中的通讯录信息导入到通讯录
	//fread函数的返回值是实际读取到元素个数，所以如果每次都读取成功1个元素，那么就会返回1
	//元素读取完毕之后，就会返回0，所以可以根据fread的返回值来作为判断何时加载完毕
	while (fread(&(ps->data[ps->size]), sizeof(PeoInfo), 1, pfRead))
	{
		//检查容量是否足够
		CheckCapacity(ps);
		ps->size += 1;
	}
	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(struct Contact* ps)
{
	//动态通讯录默认的空间为DEFAULT_CAPACITY
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	//判断malloc函数返回的是否是空指针
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_CAPACITY;

	//当重新打开通讯录的时候，需要把文件里存储的通讯录信息导入到通讯录中
	load_contact(ps);
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		//增加容量
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增加容量成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
		
		
	}
}

void add_contact(struct Contact* ps)
{
	//检查通讯录容量是否已满，如果满了就需要增加容量
	//容量已满，增加通讯录空间
	//容量未满，不进行任何操作
	CheckCapacity(ps);

	//增加数据
		printf("请输入姓名:>");
		scanf_s("%s", ps->data[ps->size].name, MAX_NAME);
		printf("请输入年龄:>");
		scanf_s("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf_s("%s", ps->data[ps->size].gender, MAX_GENDER);
		printf("请输入电话:>");
		scanf_s("%s", ps->data[ps->size].tele, MAX_TELE);
		printf("请输入住址:>");
		scanf_s("%s", ps->data[ps->size].addr, MAX_ADDR);
		printf("添加联系人成功\n");
		ps->size++;
	//}
}

void show_contact(struct Contact* ps)
{
	//如果没有任何联系人
	int i = 0;
	if (0 == ps->size)
	{
		printf("通讯录为空");
	}
	else
	{
		printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
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

//Del, Search, Modify, Sort都会涉及按照姓名进行查找
//不希望FindbyName()被其他文件调用，所以使用static限制它的作用域
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
	//要删除的联系人的名字
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除的联系人:>");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindbyName(ps, name);
	if (-1 == pos)
	{
		printf("要删除的联系人不存在\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < ps->size -1; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		printf("删除成功\n");
		ps->size--;
	}
}

void search_contact(struct Contact *ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的联系人:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = FindbyName(ps, name);
	if (-1 == pos)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
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
	printf("请输入要修改的联系人姓名:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = FindbyName(ps, name);
	if (-1 == pos)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("请输入新的姓名:>");
		scanf_s("%s", ps->data[pos].name, MAX_NAME);
		printf("请输入新的年龄:>");
		scanf_s("%d", &(ps->data[pos].age));
		printf("请输入新的性别:>");
		scanf_s("%s", ps->data[pos].gender, MAX_GENDER);
		printf("请输入新的电话:>");
		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
		printf("请输入新的地址:>");
		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
		printf("修改完成\n");
	}
}


void sort_contact(struct Contact *ps)
{
	int i = 0;
	//需要对size-1个联系人进行排序
	for (i = 0; i < ps->size - 1; i++)
	{
		//每一次排序，需要对比sz-1-j次
		int j = 0;
		//假设已经是有序
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
	//打开文件
	FILE* pfWrite = fopen("Contact.txt", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//将通讯录写入文件
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&ps->data[i], sizeof(struct PeoInfo), 1, pfWrite);
	}
	//关闭文件
	fclose(pfWrite);
	pfWrite= NULL;

}