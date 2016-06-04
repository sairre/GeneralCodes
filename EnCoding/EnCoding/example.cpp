#include <iostream>
#include <stdio.h>
#include <fstream>

#include "encode.h"
using namespace std;
int main(void)
{
	ifstream file("D:\\test.txt");

//	file.open("D:\\test.txt", ios::in | ios::out | ios::binary);
	char buffer[256000];
	char * output;
	ofstream outfile("D:\\out.txt",ios::app);
	if (file.is_open())
	{
		memset(buffer, 0, sizeof(buffer));

	
		while (file.getline(buffer,1024))
		{
			if (outfile.is_open())
			{
				output = ANSIToUTF8(buffer);
				std::string str = output;
				outfile.write(str.c_str(), str.size());
			}
			std::cout << buffer << std::endl;

		}
		

		
	}
	file.close();
	outfile.close();
	//memset(output, 0, sizeof(output));
	

	
	

	





	
	
		///*使用wcstombs和mbstowcs之前必须调用setlocale，以便决定内码*/
		//setlocale(LC_ALL, ".936");
		///*假定有一个Unicode(UTF-16LE)编码的文件，将其打开，重新编码为ANSI，写入aa.txt中，再继续编码回Unicode，写入aw.txt中*/
		///*如果不存在a.txt文件，则程序出错，没有做错误处理*/
		//char* filename = "a.txt";
		//char* filenamea = "aa.txt";
		//char* filenamew = "aw.txt";
		//FILE*     input = fopen(filename, "rb");
		//FILE*     inputa = fopen(filenamea, "wb");
		//FILE*     inputw = fopen(filenamew, "wb");
		//wchar_t * buf;
		///*BOE设置，UTF-16LE的BOE为FEFF，如果不先将其读取出来，wcstombs会调用失败*/
		//fgetwc(input);
		//fputwc(0xFEFF, inputw);
		///*开始读取文件*/
		//while (!feof(input))
		//{
		//	buf = (wchar_t *)malloc(sizeof(wchar_t)*BUFF_SIZE);
		//	memset(buf, 0, sizeof(wchar_t)* BUFF_SIZE);
		//	fgetws(buf, BUFF_SIZE, input);
		//	fputs(w2m(buf), inputa);
		//	fputws(m2w(w2m(buf)), inputw);
		//}
		///*后续处理*/
		//fclose(input);
		//fclose(inputa);
		//fclose(inputw);
		//free(buf);

		
	

	system("pause");
	return 0;
}