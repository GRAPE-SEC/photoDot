// Name: photoDot.c
// Compile: gcc -o photoDot photoDot.c -fno-stack-protector -no-pie -zexecstack

#include <stdio.h>
#include <string.h>

void dotty(char* buf){
    char filter[400];

    strcpy(va,buf);

    int i;
    for(i = 0; i < 400; i++) {
      
      if(va[i]=='\0'){
        break;
      }

      if(va[i] != '\x20' && va[i] != '\x0A') {
      va[i] = '.';
      }
      printf("%c",va[i]);
    }
    printf("\n\n");
    printf("Dot Filter Applied!!\n");
}

int main(){

    char buf[512];
      
    printf("Press Enter to read data...\n");

    getchar(); // Wait for Enter key press

    FILE* file = fopen("data","r");

    if(file == NULL) {
        printf("No File!\n");
        return 0;
    }

    fread(buf, 1, 512, file);
    fclose(file);

    dotty(buf);

      
    return 0;
}