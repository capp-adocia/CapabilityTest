#include "stopwatch.h"
#include "head.h"
#include <iostream>

// 测试1：将字符串中小于0x20的字符拷贝到新的字符串中
void test()
{
	Stopwatch watcher(OutputUnit::Microseconds);
	watcher.Start();

	for (int i = 0; i < 1000000; ++i)
	{
		//std::string str = "hello world";
		//str = remove_ctrl_ref(str);

		const char* original = "hello world";  // 包含控制字符
		size_t size = strlen(original);  // 获取原字符串长度

		char filtered[100];  // 目标字符数组，确保足够大
		remove_ctrl_cstrings(filtered, original, size);
	}
//Stopwatch: start
//Stopwatch : already started
//Stopwatch : stop 14453 mS

//Stopwatch: start
//Stopwatch : already started
//Stopwatch : stop 3930 mS
}

int main (int, char**) 
{

    test();

    return 0;
}

/*
	阿姆达尔定律
*/