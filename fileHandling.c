#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
int main(int argc,char*argv[])
{   

    printf("Numbers of arguements = %d",argc);
	int line_no;
	char *in_file = argv[1];
	FILE *input_file = fopen(in_file,"r");
	
	char out_file[100];
	strcpy(out_file,argv[1]);
	strcat(out_file,".out");
	FILE *output_file = fopen(out_file,"w");
	
	char line[100];
	for(line_no =1;fgets(line,sizeof(line),input_file)!=NULL;line_no++)
	{
	  //	printf("LINE %d: %s",line_no,line);
	  //	fprintf(output_file,"LINE %d: %s",line_no,line);
	  fputs(line,stdout);
	  fputs(line,output_file);
	}
	printf("\n\nhello");
/*	if(input_file)
	{
		fclose(input_file);
		fclose(output_file);
	}
	*/
	printf("\n\nhello");
	getch();
	return 0;
}
	