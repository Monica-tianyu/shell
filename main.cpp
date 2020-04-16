#include"Function.h"
#include<iostream>
#include<string.h>
using namespace std;


int main()
{
	string s;
	char str[50];
	const char div[2]=" ";
	while(getline(cin,s))
	{	strcpy(str,s.c_str());
		char *p;
		p=strtok(str,div);
		if(strcmp(p,"cp")==0)
		{
			p=strtok(NULL,div);
			if(p==NULL)
			{
				cout<<"cp: 缺少了文件操作数"<<endl;
				goto End;
			}

			else if(strcmp(p,"-r")==0)
			{
				p=strtok(NULL,div);

			}
			else
			{
				char *p2=strtok(NULL,div);			
				copy(p,p2);
			}
		}
		else if(strcmp(p,"cmp")==0)
		{
			p=strtok(NULL,div);
			if(p==NULL)
			{
				cout<<"cmp: 操作数 “cmp” 后缺少参数"<<endl;
				goto End;
			}
			char *p2=strtok(NULL,div);
			compare(p,p2);
		}
		else if(strcmp(p,"wc")==0)
		{
			p=strtok(NULL,div);
			if(p==NULL)
			{
				goto End;
			}

			else if(strcmp(p,"-c")==0)
			{
				char *p2=strtok(NULL,div);
				if(p2==NULL)
				{
					goto End;
				}
				int c=count_ch(p2);
				if(c<0)
				{
					goto End;
				}
				else
				{
				cout<<c<<" "<<p2<<endl;
				}
			}
			else if(strcmp(p,"-l")==0)
			{
				char *p2=strtok(NULL,div);
				if(p2==NULL)
				{
					goto End;
				}
				int l=count_line(p2);
				if(l<0)
				{
					goto End;
				}
				else
				{
				cout<<l<<" "<<p2<<endl;
				}

			}
			else if(strcmp(p,"-w")==0)
			{
				char *p2=strtok(NULL,div);
				if(p2==NULL)
				{
					goto End;
				}
				int w=count_word(p2);
				if(w<0)
				{
					goto End;
				}
				else
				{
				cout<<w<<" "<<p2<<endl;
				}
			}
			else if(p[0]=='-')
			{
				cout<<"wc: 不适用的选项 -- "<<p+1<<endl;
				goto End;
			}
			else
			{
				wc(p);
			}
		}
		else if(strcmp(p,"cat")==0)
		{
			p=strtok(NULL,div);
			if(p==NULL)
			{
				goto End;
			}
			cat(p);
		}
		else if(strcmp(p,"exit")==0)
		{
			break;
		}
		else
		{
			cout<<p<<": 未找到命令"<<endl;
		}
End: ;

	}
		
	return 0;
}
