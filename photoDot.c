// Name: photoDot.c
// Compile: gcc -o photoDot photoDot.c -fno-stack-protector -no-pie -zexecstack

#include <stdio.h>
#include <string.h>

void dotty(char* mem){
    char filter_buffer[400];

    strcpy(filter_buffer,mem);

    int i;
    for(i = 0; i < 400; i++) {
      
      if(filter_buffer[i]=='\0'){
        break;
      }

      if(filter_buffer[i] != '\x20' && filter_buffer[i] != '\x0A') {
        filter_buffer[i] = '.';
      }
      printf("%c",filter_buffer[i]);
    }
    printf("\n\n");
    printf("Dot Filter Applied!!\n");
}

void hidden(){
  printf("###########################################\n");
  printf("############# id : Jaeho Jeon #############\n");
  printf("############# pw : qwer1234 ###############\n");
  printf("###########################################\n");
  fflush(stdout);
}

int main(){

    char file_buffer[512];
      
    printf("Press Enter to read data...\n");

    getchar(); // Wait for Enter key press

    FILE* file = fopen("image","r");

    if(file == NULL) {
        printf("No File!\n");
        return 0;
    }

    fread(file_buffer, 1, 512, file);
    
    fclose(file);

    dotty(file_buffer);
    

    printf("App Exit~\n");
      
    return 0;
}