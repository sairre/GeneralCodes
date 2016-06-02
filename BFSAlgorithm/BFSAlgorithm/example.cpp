#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
#include <time.h>
/// to use the function _chdir
#include <direct.h>
/// to use the struct _finddata_t
#include <io.h>
std::string converSize(double cnt);
int main(void)
{
	while (true)
	{
		int start, end, diff;
		char buf[256];
		printf("Input:");
		gets(buf);

		start = clock();
		std::string _filePath = buf;
		//	std::cin >> _filePath;
		std::queue<std::string> _infoQueue;

		_infoQueue.push(_filePath);

		int _filenum = 0;
		double cnt = 0;



		while (!_infoQueue.empty())
		{
			std::string _tmpDirPath = _infoQueue.front();
			_infoQueue.pop();
			_chdir(_tmpDirPath.c_str());

			//首先查找dir中符合要求的文件
			long hFile;
			_finddata_t fileinfo;
			if ((hFile = _findfirst("*.*", &fileinfo)) != -1)
			{
				do
				{
					//检查是不是目录
					//如果是,则进行处理
					std::string _tmpFilePath = _tmpDirPath + "\\" + fileinfo.name;
					if ((fileinfo.attrib & _A_SUBDIR))
					{
						if (strcmp(fileinfo.name, ".") == 0 || strcmp
							(fileinfo.name, "..") == 0)
							continue;



						_infoQueue.push(_tmpFilePath);

					}
					else
					{
						///TODO calculate the size of files and numbers of files except directories

						//		std::cout << _tmpFilePath << std::endl;

						cnt = cnt + fileinfo.size;
						_filenum++;

					}
				} while (_findnext(hFile, &fileinfo) == 0);
				_findclose(hFile);
			}
		}





		

		converSize(cnt);
		std::cout << "FILES:" << _filenum << std::endl;
		end = clock();
		diff = end - start;

		std::cout << "times:" << diff << std::endl;
	}
	
	system("pause");

	return 0;
	
}

std::string converSize(double cnt)
{
#define KSIZE 1024
	std::string str = "";
	long long sk = KSIZE * KSIZE;
	long long sm = sk * KSIZE;
	long long sg = sm * KSIZE;
	if (cnt < KSIZE)
		str = "B";
	else if (cnt < KSIZE * KSIZE)
	{
		str = "KB";
		cnt = cnt / KSIZE;

	}
	else if (cnt < sm)
	{
		str = "MB";
		cnt = cnt / (KSIZE * KSIZE);

	}
	else if (cnt < sg)
	{
		str = "GB";
		long long size = KSIZE * KSIZE;
		size = size * KSIZE;
		cnt = cnt / size;

	}
	else
	{
		str = "TB";
		long long size = KSIZE * KSIZE;
		size = size * KSIZE;
		size = size * KSIZE;
		cnt = cnt / size;
	}
	std::cout << cnt << " " << str << std::endl;
	
	
	return str;
}