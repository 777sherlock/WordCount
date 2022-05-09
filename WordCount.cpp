#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;


int main(int argc ,char** argv) {

    FILE *fp;  // 指向文件的指针
    char buffer[1000];  //缓冲区，存储读取到的每行的内容
    int bufferLength;  // 缓冲区中实际存储的内容的长度
    int i;  // 当前读到缓冲区的第i个字符
    char c;  // 读取到的字符
    int isBlank = 0;  // 上个字符是否是空格
    int charNumber = 0;  // 当前行的字符数
    int wordNumber = 0; // 当前行的单词数
    int charCount = 0;// 总字符数 
    int wordCount = 0;// 总单词数 
    if( (fp=fopen(argv[2], "rb")) == NULL )//打开文件并设置为可读可写 
	{
        perror(argv[2]);//提示错误信息 
        return -1;
    }
    // 每次读取一行数据，保存到buffer，并且每行最多只能有1000个字符
    while(fgets(buffer, 1000, fp) != NULL)
	{
        bufferLength = strlen(buffer);
        // 遍历缓冲区的内容
        for(i=0; i<bufferLength; i++)
		{
            c = buffer[i];
            if(c < '0' || c > '9')
			{  
                charNumber++;  // 只要不是数字，字符数加1
                isBlank = 0;
                if( c==' '|| c==',')
				{     // 遇到空格或者逗号表示前一个为单词 
			      if(!isBlank)
				    {
					 wordNumber++; 
			     	} // 如果上个字符不是空格，那么单词数加1
                  isBlank = 1;
                } 
            }
            
        }
        if(!isBlank)
		{
		   wordNumber++; 
     	} // 如果最后一个字符不是空格，那么单词数加1
        isBlank = 1;  // 每次换行重置为1
        // 一行结束，计算总字符数、总单词数、总行数
        charNumber--;//每行要减一个，因为除了最后一行，每一行都有一个换行符
		//而换行符的出现会导致\0失效而被当作一个字符，此时\0不在最后不能当作结束符了 
        charCount += charNumber;  // 总字符数
        wordCount += wordNumber;  // 总单词数
        // 置零，重新统计下一行
        charNumber = 0;
        wordNumber = 0;
    }	 
    if(strcmp(argv[1],"-c")==0)//用strcmp函数进行字符串比较判断第一个参数是否符合 
	  {
	  	 printf("字符数：%d",charCount+1);
	  }
	  else if(strcmp(argv[1],"-w")==0)
	  {
	  	printf("单词数：%d",wordCount);
	  }
    fclose(fp);

  system("pause");
  return 0;
}

