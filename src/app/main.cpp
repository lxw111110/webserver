/*************************************************************************
	> File Name: src/app/main.cpp
	> Author:L
	> Mail:731278512@qq.com
	> Created Time: 2018年06月12日 星期二 23时51分37秒
 ************************************************************************/

#include<iostream>
#include "dlfcn.h"
using namespace std;

int main(void)
{

//	hello();

	typedef void (*hello_t)(void);
	void *handle = dlopen("../build/src/module/libhello.so",RTLD_LAZY);
	if(!handle)
	{
		cout<<"open so error!"<<endl;
		cout<<dlerror()<<endl;
		return -1;
	}
	hello_t hello=(hello_t)dlsym(handle,"hello");
	if(!hello)
	{
		cout<<"use so error!"<<endl;
		cout<<dlerror()<<endl;
		dlclose(handle);
		return -1;
	}
	hello();
	dlclose(handle);

	return 0;
}





