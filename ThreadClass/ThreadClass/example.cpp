#include <iostream>
#include <stdio.h>
#include "CThread.h"
void test_fun(void)
{
	std::cout << "test_fun" << std::endl;
}
void test_fun2(void)
{
	std::cout << "tesdadgsat_fun" << std::endl;
}
int main(void)
{
	CThread c1(test_fun);
	c1.start();
	CThread c2(test_fun2);
	c2.start();
	CThread c3;
	c3.bindFunc(test_fun2);;
	c3.start();
	system("pause");
	return 0;

}