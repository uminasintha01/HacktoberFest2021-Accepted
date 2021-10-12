#include<stdio.h>

void main()
{
FILE * fp;
fp=fopen("input.txt","r");
FILE * ifile;
ifile=fopen("output.txt","w");
char buff[1000];
fgets(buff,1000,(FILE *)fp);
int i=0;
for(i=0;buff[i]!='\0';i++)
{
if(buff[i]>47 &&buff[i]<57)
{
fputc(buff[i],ifile);
}
}
fgets(buff,1000,(FILE *)fp);
for(i=0;buff[i]!='\0';i++)
{
if(buff[i]>47&&  buff[i]<57)
{
fputc(buff[i],ifile);
}
}
fclose(fp);
fclose(ifile);
}
