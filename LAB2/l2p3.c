#include<stdio.h>
int main()
{
 FILE *fp;
 fp=fopen("l2p3.c","r");
 char ch;
 ch=fgetc(fp);
 printf("#");
 while(ch!=EOF)
  {
    ch=fgetc(fp);
    printf("%c",ch);
  }
 fclose(fp);
}
