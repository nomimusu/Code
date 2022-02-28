#include <stdio.h>
#include <assert.h>
#include <string.h>

//通过自定义my_strncmp()函数，按照词汇顺序比较p1和p2指向的字符串的前count个字符，并且返回一个表示他们之间大小关系的值
//因为p1和p2指向的是常量字符串，是不能被修改的，避免程序崩溃，所以在*左边加const
int my_strncmp(const char*p1, const char* p2, int count)
{
	//形参是指针，涉及解引用，所以不能是空指针
	assert(p1 && p2);

	//count作为计数器，判断p1和p2指向的字符是否相等，如果相等的话，p1和p2就指向下一个字符进行比较
	//结尾终止符也会比较，所以如果p1或者p2指向'/0'的时候，无论count多大，不再继续比较
	while (count-- && *p1 == *p2)
	{
		p1++;
		p2++;
	}

	return *p1 - *p2;
}

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcdefg";
	int count = 7;
	printf("%d\n", strncmp(p1, p2, count));
	int ret = my_strncmp(p1, p2, count);
	if (ret > 0)
		printf("p1 > p2\n");
	if (ret < 0)
		printf("p1 < p2\n");
	if (ret == 0)
		printf("p1 = p2\n");
	return 0;
}