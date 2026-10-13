#include "header.h"
void *headerinclusion(char *ptr)
{
	char ch[]="#include<stdio.h>";
	FILE *fptr;
	char *header,*first,*last;
	long len;
	int n;
	fptr=fopen("/usr/include/stdio.h","r");
	if(fptr==NULL)
	{
		printf("stdio.h not found");
		return ptr;
	}
	fseek(fptr,0,2);
	len=ftell(fptr)+1;
	rewind(fptr);
	header=malloc(len);
	fread(header,1,len,fptr);
	header[len-1]='\0';
	fclose(fptr);
	first=strstr(ptr,ch);
	if(first != NULL)
	{
	ptr=realloc(ptr,strlen(ptr)-strlen(ch)+strlen(header)+1);
	if(ptr==NULL)
	{
		free(header);
		return NULL;
	}
	first=strstr(ptr,ch);
	last=first+strlen(ch);
	//using memove 
	memmove(first+strlen(header),last,strlen(last)+1);
	memcpy(first,header,strlen(header));
	}
	free(header);
	return ptr;
}
