#include "stopwatch.h"
#include "head.h"
#include <iostream>

// 测试1：将字符串中小于0x20的字符拷贝到新的字符串中
void test()
{
	Stopwatch watcher;
	watcher.Start();

	for (int i = 0; i < 1000000; ++i)
	{
		std::string str = "hello world";
		str = remove_ctrl_ref(str);
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