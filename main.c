#include "header.h"
int cnt=0;
void *readfromfile(char *file)
{
	char *ptr=NULL;
	FILE *src=NULL;
	src=fopen(file,"r");
	if(src==NULL)
	{
		printf("file not found :");
		exit(0);
	}
	fseek(src,0,2);
	long size =ftell(src)+1;
	fseek(src,0,0);
	ptr=calloc(1,size);
	fread(ptr,size,1,src);
	ptr[size-1]='\0';
	fclose(src);
	return ptr;
}
void writetofile(char *ptr,char *file)
{
	FILE *fptr=NULL;
	int len=strlen(ptr);
	fptr=fopen(file,"w");
	fwrite(ptr,len,1,fptr);
}
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("give exe ,.c,.i files\n");
		exit(0);
	}
	char str[100];
	char ch[]=".c";
	strcpy(str,argv[1]);
	char *p=NULL;
	p=str;
	while(p=strstr(p,ch))
	{
		memcpy(p,".i",2);
	}

	char *lines=NULL;
	lines=readfromfile(argv[1]);
	lines=commentremove(lines);
	lines=macroreplace(lines);
	lines=headerinclusion(lines);
	writetofile(lines,str);
}
