//本程序需引用的头文件均在framework.h中
#include "framework.h"
//本程序窗口控件，句柄的ID，函数前向声明，全局变量声明均在resource.h中
#include "resource.h"
//base64编码
char* Base64Encode(unsigned char* str) {
	int encodeLength;
	int stringLength;
	unsigned char* res;
	int i, j;
	//定义base64编码表  
	unsigned char* table = (unsigned char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	//计算经过base64编码后的字符串长度  
	stringLength = strlen((char*)str);
	if (stringLength % 3 == 0)
		encodeLength = stringLength / 3 * 4;
	else
		encodeLength = (stringLength / 3 + 1) * 4;

	res = (unsigned char*)malloc(sizeof(unsigned char) * encodeLength + 1);
	if (res == NULL) {
		return (char*)"ZXJyb3I=";
	}
	res[encodeLength] = '\0';

	//以3个8位字符为一组进行编码  
	for (i = 0, j = 0; i < encodeLength - 2; j += 3, i += 4)
	{
		res[i] = table[str[j] >> 2]; //取出第一个字符的前6位并找出对应的结果字符  
		res[i + 1] = table[(str[j] & 0x3) << 4 | (str[j + 1] >> 4)]; //将第一个字符的后位与第二个字符的前4位进行组合并找到对应的结果字符  
		res[i + 2] = table[(str[j + 1] & 0xf) << 2 | (str[j + 2] >> 6)]; //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符  
		res[i + 3] = table[str[j + 2] & 0x3f]; //取出第三个字符的后6位并找出结果字符  
	}

	switch (stringLength % 3)
	{
	case 1:
		res[i - 2] = '=';
		res[i - 1] = '=';
		break;
	case 2:
		res[i - 1] = '=';
		break;
	}

	return (char*)res;
}