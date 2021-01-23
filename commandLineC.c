#include<stdio.h>
int string_to_int(char*);
int main(int argc,char*argv[])
{ //  char str[] = "45";
/*	char *str;
	str = argv[1];
	printf("%s",str);
	*/
	int i,a,b;
	a = string_to_int(argv[1]);
	b = string_to_int(argv[2]);
	printf(" sum  is %d",a+b);
	for(i=0;i<argc;i++)
	{
		printf("\n%s",argv[i]);
	}
	

	return 0;
}

int string_to_int(char *str)
{
	int i,x;
	for(i=0,x=0;str[i];i++)
	{ 
        if(i==0&&str[0] == '-')   // for handling -45 as cmdLine Input
		     i++;
		if(str[i]>='0'&&str[i]<='9')
			x = x *10 + (str[i] - 48);
		else
			break;
	}
	if(str[0] == '-')     //for handling -45 as cmdLine Input
		x = -x;
	return (x);
}