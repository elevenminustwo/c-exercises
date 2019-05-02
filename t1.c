#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	char cmd[50];
	char *ch = malloc(8);
	free(ch);
	
	//strcpy(cmd, "free -m >> log \n ./t1.exe");
	//system(cmd);
	
	return 0;
	
#elif __unix__ // all unices not caught above
        printf("Unix detected \n");
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

return 0;
}

