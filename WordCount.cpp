#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;


int main(int argc ,char** argv) {

    FILE *fp;  // ָ���ļ���ָ��
    char buffer[1000];  //���������洢��ȡ����ÿ�е�����
    int bufferLength;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int charNumber = 0;  // ��ǰ�е��ַ���
    int wordNumber = 0; // ��ǰ�еĵ�����
    int charCount = 0;// ���ַ��� 
    int wordCount = 0;// �ܵ����� 
    if( (fp=fopen(argv[2], "rb")) == NULL )//���ļ�������Ϊ�ɶ���д 
	{
        perror(argv[2]);//��ʾ������Ϣ 
        return -1;
    }
    // ÿ�ζ�ȡһ�����ݣ����浽buffer������ÿ�����ֻ����1000���ַ�
    while(fgets(buffer, 1000, fp) != NULL)
	{
        bufferLength = strlen(buffer);
        // ����������������
        for(i=0; i<bufferLength; i++)
		{
            c = buffer[i];
            if(c < '0' || c > '9')
			{  
                charNumber++;  // ֻҪ�������֣��ַ�����1
                isBlank = 0;
                if( c==' '|| c==',')
				{     // �����ո���߶��ű�ʾǰһ��Ϊ���� 
			      if(!isBlank)
				    {
					 wordNumber++; 
			     	} // ����ϸ��ַ����ǿո���ô��������1
                  isBlank = 1;
                } 
            }
            
        }
        if(!isBlank)
		{
		   wordNumber++; 
     	} // ������һ���ַ����ǿո���ô��������1
        isBlank = 1;  // ÿ�λ�������Ϊ1
        // һ�н������������ַ������ܵ�������������
        charNumber--;//ÿ��Ҫ��һ������Ϊ�������һ�У�ÿһ�ж���һ�����з�
		//�����з��ĳ��ֻᵼ��\0ʧЧ��������һ���ַ�����ʱ\0��������ܵ����������� 
        charCount += charNumber;  // ���ַ���
        wordCount += wordNumber;  // �ܵ�����
        // ���㣬����ͳ����һ��
        charNumber = 0;
        wordNumber = 0;
    }	 
    if(strcmp(argv[1],"-c")==0)//��strcmp���������ַ����Ƚ��жϵ�һ�������Ƿ���� 
	  {
	  	 printf("�ַ�����%d",charCount+1);
	  }
	  else if(strcmp(argv[1],"-w")==0)
	  {
	  	printf("��������%d",wordCount);
	  }
    fclose(fp);

  system("pause");
  return 0;
}

