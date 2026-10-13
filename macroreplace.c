#include "header.h"
void *macroreplace(char *ptr)
{
	char *first,*last,*p;
	char name[100];
	char value[100];
	int n,plen,vlen;
	first=strstr(ptr,"#define");
	if(first==NULL)
	{
		return ptr;
	}
	first=first+7;//7 because the len of #define is 7
	while(*first==' ' || *first == '\t')
	{
		first++;
	}
	last=first;
	while(*last != ' ' && *last != '\t' && *last != '\n' &&*last != '\0')
	{
		last++;
	}
	n=last-first;//it gives the length of the macro name;
	memcpy(name,first,n);
	name[n]='\0';
	while(*last==' '|| (*last) =='\t')
	{
		last++;
	}
	first=last;
	while(*last != ' ' && *last != '\n')
	{
		last++;
	}
	n=last-first;
	memcpy(value,first,n);
	value[n]='\0';
	if(*last=='\n')
	{
		last++;
	}
	puts(name);
	puts(value);
	plen=strlen(name);
	vlen=strlen(value);
	printf("%d",vlen);
	first=strstr(ptr,"#define");
	memmove(first,last,strlen(last)+1);
	p=ptr;
	while((p=strstr(p,name))!=NULL)
	{
		if((p>ptr && (*(p-1)=='_') ||(*(p-1)>='a' && *(p-1)<='z') || (*(p-1) >='A' && *(p-1) <='Z') ||
			(*(p-1) >='0' && *(p-1) <='9') || (p[plen]=='_') ||(p[plen]>='a' && p[plen]<='z') ||
						 (p[plen] >='A' &&p[plen]<='Z') || (p[plen]>='0' && p[plen]<='9') ))
		{
			p=p+plen;
			continue;
		}
		memmove(p+vlen,p+plen,strlen(p+plen)+1);
		memcpy(p,value,vlen);
		p=p+plen;
	}
	return ptr;
}
