#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<assert.h>
void* my_memcpy(void* arr1, const void* arr2,size_t num)
{
	assert(arr1 && arr2);
	void* arr = arr1;
	while (num--)
	{
		*(char*)arr1 = *(char*)arr2;
		arr1 = (char*)arr1 + 1;
		arr2 = (char*)arr2 + 1;
	}
	return arr;
}
void* my_memmove(void* arr1, const void* arr2, size_t num)
{
	assert(arr1 && arr2);
	void* arr = arr1;
	if (arr1 < arr2)
	{
		while (num--)
		{
			*(char*)arr1 = *(char*)arr2;
			arr1 = (char*)arr1 + 1;
			arr2 = (char*)arr2 + 1;
		}
	}
	else 
	{
		while (num--)
		{
			*((char*)arr1+num) = *((char*)arr2+num);
		}
	}
	return arr;
}
//void* my_memmove(void* dest, const void* src, size_t sz)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if (dest < src)
//	{
//		//前->后
//		int i = 0;
//		for (i = 0; i < sz; i++)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//后->前
//		while (sz--)
//		{
//			*((char*)dest + sz) = *((char*)src + sz);
//		}
//	}
//	return ret;
//}
int main()
{
	int arr[20] = { 1,2,3,4,5,6,7,8 };
	int arr1[] = { 1,2,3,4,5,6 };
	my_memmove(arr, arr+2, 24);
	return 0;
}