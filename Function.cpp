#include<iostream>
#include<string.h>

using namespace std;

void copy(char *p,char *p2)
{
	if(p2==NULL)
	{
		cout<<"cp: 在'"<<p<<"' 后缺少了要操作的目标文件"<<endl;
		return ;
	}
	FILE*fp=fopen(p,"r");
	if(fp==NULL)
	{
		cout<<"cp: 无法获取'"<<p<<"' 的文件状态(stat): 没有那个文件或目录"<<endl;
		return;
	}
	if(strcmp(p,p2)==0)
	{
		cout<<"cp: '"<<p<<"' 与'"<<p2<<"' 为同一文件"<<endl;
		fclose(fp);
		return;
	}
	FILE*fp2=fopen(p2,"w");
	if(fp==NULL)
	{
		cout<<"创建失败！"<<endl;
		exit(-1);
	}
	char buf[100];
	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		int n=fputs(buf,fp2);
		if(n==EOF)
		{
			cout<<"复制失败！"<<endl;
		}
	}
	fclose(fp);
	fclose(fp2);		

}


void compare(char *p,char *p2)
{
	if(p2==NULL)
	{
		return;
	}
	int line_number=1;
	int ch=1;
	FILE *fp=fopen(p,"r");
	if(fp==NULL)
	{
		cout<<"cmp: "<<p<<": 没有那个文件或目录"<<endl;
		return;
	}
	FILE *fp2=fopen(p2,"r");
	if(fp2==NULL)
	{
		cout<<"cmp: "<<p2<<": 没有那个文件或目录"<<endl;
		return;
	}
	char buf1[1000];
	char buf2[1000];
	bool f1=false;
	while(fgets(buf1,sizeof(buf1),fp)!=NULL&&fgets(buf2,sizeof(buf2),fp2)!=NULL)
	{
		if(strcmp(buf1,buf2)==0)
		{
			line_number++;
		}
		else
		{
			f1=true;
			break;
		}
	}
	fclose(fp);
	fclose(fp2);
	fp=fopen(p,"r");
	if(fp==NULL)
	{
		cout<<"打开失败！文件"<<p<<"不存在"<<endl;
		exit(-1);
	}
	fp2=fopen(p2,"r");
	if(fp2==NULL)
	{
		cout<<"打开失败！文件"<<p2<<"不存在"<<endl;
		exit(-1);
	}
	char b1[2],b2[2];
	bool f2=false;
	while(fgets(b1,sizeof(b1),fp)!=NULL&&fgets(b2,sizeof(b2),fp2)!=NULL)
	{
		if(strcmp(b1,b2)==0)
		{
			ch++;
		}
		else
		{
			f2=true;
			break;
		}
	}
	if(f1==false&&f2==false);
	else
	{
		cout<<p<<" "<<p2<<" 不同：第 "<<ch<<" 字节，第 "<<line_number<<" 行"<<endl;
	}
	fclose(fp);
	fclose(fp2);
}


int count_line(char *p2)
{
	FILE *fp=fopen(p2,"r");
	if(fp==NULL)
	{
		cout<<"wc: "<<p2<<": 没有那个文件或目录"<<endl;
		return -1;
	}
	int l=0;
	char buf[1000];
	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		l++;
	}
	fclose(fp);
	return l;
}

int count_ch(char *p2)
{
	FILE *fp=fopen(p2,"r");
	if(fp==NULL)
	{
		cout<<"wc: "<<p2<<": 没有那个文件或目录"<<endl;
		return -1;
	}
	int c=0;
	char buf[2];
	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		c++;
	}
	fclose(fp);
	return c;
}

int count_word(char *p2)
{
	FILE *fp=fopen(p2,"r");
	if(fp==NULL)
	{
		cout<<"wc: "<<p2<<": 没有那个文件或目录"<<endl;
		return -1;
	}
	int w=0;
	char buf[2];
	bool flag=false;
	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		if(buf[0]!=' '&&buf[0]!='\t'&&buf[0]!='\n')
		{
			flag=true;
		}
		else
		{
			if(flag==true)
			{
				w++;
			}
			flag=false;
		}
	}
	fclose(fp);
	return w;
}

void wc(char *p)
{
	int c=count_ch(p);
	if(c<0)
	{
		return;
	}
	int l=count_line(p);
	int w=count_word(p);
	cout<<" "<<l<<" "<<w<<" "<<c<<" "<<p<<endl;
}


void cat(char *p)
{
	FILE *fp=fopen(p,"r");
	if(fp==NULL)
	{
		cout<<"cat: "<<p<<": 没有那个文件或目录"<<endl;
		return;
	}
	char buf[100];
	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		cout<<buf;
	}
	
}
