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
	

	
	

	





	
	
		///*ʹ��wcstombs��mbstowcs֮ǰ�������setlocale���Ա��������*/
		//setlocale(LC_ALL, ".936");
		///*�ٶ���һ��Unicode(UTF-16LE)������ļ�������򿪣����±���ΪANSI��д��aa.txt�У��ټ��������Unicode��д��aw.txt��*/
		///*���������a.txt�ļ�����������û����������*/
		//char* filename = "a.txt";
		//char* filenamea = "aa.txt";
		//char* filenamew = "aw.txt";
		//FILE*     input = fopen(filename, "rb");
		//FILE*     inputa = fopen(filenamea, "wb");
		//FILE*     inputw = fopen(filenamew, "wb");
		//wchar_t * buf;
		///*BOE���ã�UTF-16LE��BOEΪFEFF��������Ƚ����ȡ������wcstombs�����ʧ��*/
		//fgetwc(input);
		//fputwc(0xFEFF, inputw);
		///*��ʼ��ȡ�ļ�*/
		//while (!feof(input))
		//{
		//	buf = (wchar_t *)malloc(sizeof(wchar_t)*BUFF_SIZE);
		//	memset(buf, 0, sizeof(wchar_t)* BUFF_SIZE);
		//	fgetws(buf, BUFF_SIZE, input);
		//	fputs(w2m(buf), inputa);
		//	fputws(m2w(w2m(buf)), inputw);
		//}
		///*��������*/
		//fclose(input);
		//fclose(inputa);
		//fclose(inputw);
		//free(buf);

		
	

	system("pause");
	return 0;
}