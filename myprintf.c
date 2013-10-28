#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include<string.h>

char *itoa(long value, char *s);

void myprintf(char *fmt,...)
{
	va_list ap;
	va_start(ap,fmt);
	char c;
	int a;
	double b;
	char buf[20];
	char *p = NULL;

//	printf("ap start is %s\n",*ap);
	while(*fmt != '\0') {
		c = *fmt;
		if( c != '%') {
			write(STDOUT_FILENO,&c,1);
			fmt++;
		}
		else {
			fmt++;
			switch(*fmt) {
			case 'd':
				a = va_arg(ap,int);
				sprintf(buf,"%d",a);
				write(STDOUT_FILENO,buf,strlen(buf));
				fmt++;
				break;
			
			case 'f':
				b = va_arg(ap,double);
				sprintf(buf,"%f",b);
				write(STDOUT_FILENO,buf,strlen(buf));
				fmt++;
				break;
			
			case 's':
				p = va_arg(ap,char *);
				write(STDOUT_FILENO,p,strlen(p));
				fmt++;
				break;

			}

		}
	}
	

}

int main()
{
	myprintf("test!\n");
	myprintf("test %d %d\n",1234,5678);
	myprintf("test %d %f\n",1234,1.234);
	myprintf("test %s %d %f\n","uestc starts at",1956,0.001);
	return 0;
}
