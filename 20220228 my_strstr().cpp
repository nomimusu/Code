#include <stdio.h>
#include <assert.h>

//通过自定义函数my_strstr()判断p2指向的字符串是否是p1指向字符串的子串，如果是，返回p2指向的字符串在p1指向的字符串中第一次出现的指针，如果否，返回NULL
//因为对两个字符串进行比较，不需要修改他们的值，所以*左边加了const
char* my_strstr(const char* p1, const char* p2)
{
	//形参是指针，涉及解引用，所以不能是空指针
	assert(p1 && p2);
	//设置一个指针cur来定位p1指向的字符串的匹配起始位置
	//p1是const char*，所以需要强制类型转换
	char* cur = (char*)p1;

	//如果p2指向的是一个空字符，那么可以返回指针p1
	//因为函数返回值是char*，p1是const char*，所以需要对p1进行强制类型转化
	if (!*p2)
	{
		return (char*)p1;
	}

	//判断条件为cur没有指向字符串的\0
	while (*cur)
	{
		//设置指针s1，从cur指向的位置出发，逐步移动
		char* s1 = cur;
		//设置指针s2，从p2指向的位置出发，逐步移动
		char* s2 = (char*)p2;

		//判断条件1：如果s1指向的字符==s2指向的字符，那么s1++，s2++
		//判断条件2：如果s2指向的字符是\0，说明p2指向的字符串全部对比结束，p2指向的字符串是p1指向字符串的子串
		//判断条件3：如果s1指向的字符是\0，说明p1指向的字符串全部对比结束，p2指向的字符串不是p1指向字符串的子串
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		
		if (*s2 == '\0')
		{
			return cur;//找到子串
		}

		//如果p1指向的字符串比p2指向的字符串要短，那么s1会比s2更快得指向'\0'，这时候就不需要cur指向的位置不需要继续移动，直接返回NULL
		if (*s1 == '\0')
		{
			return NULL;
		}

		//如果cur指向的字符，跟s2指向的不同，cur++
		cur++;
	}

	return NULL;
}

int main()
{
	const char* p1 = "abbbcdef";
	const char* p2 = "def";
	char* ret = my_strstr(p1, p2);
	
	if (ret == NULL)
	{
		printf("p2指向的字符串不是p1指向字符串的子串\n");
	}
	else
	{
		printf("%s\n", ret);
	}
}