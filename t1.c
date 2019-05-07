#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUZZ_SIZE 50

int main(void){
#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      printf("WIN64 detected \n");
   #else
      printf("WIN32 detected \n");
   #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
        printf("Linux detected \n");
	char cmd[100];
	char pwd[3];
	char buff[BUZZ_SIZE];
	strcpy(pwd,"pwd >> log");
	system(pwd);
	FILE *f = fopen("log","w");
	fseek(f,-1,SEEK_END);
	char b[100] = "/log .";
	fputs(b,f);
	fclose(f);
	FILE *file = fopen("log","r");
	fgets(buff, BUZZ_SIZE,file);
	char a[100] = "cd $HOME cd media \n cd * \n cd * \n cp ";
	strcat(a,buff-1);
	printf("==== %s",buff-1);
	fclose(file);
	system(a);
	
	return 1;
	
#elif __unix__ // all unices not caught above
        printf("Unix detected \n");
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

return 0;
}

