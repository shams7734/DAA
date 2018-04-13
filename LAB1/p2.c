#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void removeNewline(char *name)
{
	int i;
	int size = strlen(name);
	for(i=size-1;i>=0;i--)
		if(name[i] == '\n')
			{name[i] = '\0'; return;}
}

int isCorrectExt(char *name)
{
	int i;
	int size = strlen(name);

	for(i=size-1;i>=0;i--)
		if(name[i] == '.')
			break;
	if((name[i+1] == 't' && name[i+2]=='x' && name[i+3]=='t') || (name[i+1] == 'd' && name[i+2]=='a' && name[i+3]=='t' ))
		return 1;
	return 0;
	
}
void sort(int* arr,int size)
{   

	int i,j,temp;

	for(i=0;i<size;i++)
		for(j=0;j<size-i-1;j++)
		{
		    if(arr[j]>arr[j+1])
		    {
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		    }
		}  
}


int main(int argc,char *argv[])
{
	FILE *list,*fin,*fout;
	int size,*arr,i;
	char name[100];
	char pathRead[100] = "";
	char pathWrite[100] = "sortedFileSystem/";
	char command[100] = "ls ";

	strcat(command,argv[1]);
	strcat(command," > files.txt");
	
	system(command);
		
	if((list = fopen("files.txt","r"))==NULL)
	{
		printf("Error in opening file");
		exit(1);
	}

	system("mkdir sortedFileSystem");
	
	while(fgets(name,100,list)!=NULL)
	{
		
		if(isCorrectExt(name))
		{
			removeNewline(name);
			strcat(pathRead,argv[1]);			
			strcat(pathRead,"/");
			strcat(pathRead,name);	
		
			strcat(pathWrite,name);	

			//printf("%s",pathRead);
			//printf("%s\n",pathWrite);
			
			if((fin=fopen(pathRead,"r"))==NULL)
			{
				printf("Error in opening read file");
				exit(1);				
			}	
			if((fout=fopen(pathWrite,"w"))==NULL)		
			{
				printf("Error in opening write file");
				exit(1);			
			}	
			fscanf(fin,"%d",&size);

		
			arr = (int*)calloc(size,sizeof(int));
			
			for(i=0;i<size;i++)
				fscanf(fin,"%d",&arr[i]);
					
			sort(arr,size); 
				
			for(i=0;i<size;i++)
				fprintf(fout,"%d\t",arr[i]);
			
			fclose(fin);
			fclose(fout);			
		}
			
			size=0;
			strcpy(pathWrite,"sortedFileSystem/");
			strcpy(pathRead,"");
			

	}

    fclose(list);
	return 0;
}
