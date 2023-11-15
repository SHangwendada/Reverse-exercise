#include<stdio.h>
#include<string.h>
char key[] = "HUHSTSEC";
unsigned char check[] = {0x2e, 0x38, 0x2b, 0x39, 0x2b, 0x66, 0x37, 0x7b, 0x36, 0x23, 0x21, 0x6, 0xd5, 0xd3, 0xc7, 0x2d, 0x2b, 0x14, 0x39, 0xd5, 0xd7, 0xc1, 0};
char flag[256] = {0};
int main() {
//      char flag[] = "flag{0l1vm_Just_S0_so}";
        scanf("%s",flag);
        if (strlen(flag) != 22 ) {
                puts("Wrong!!");
                return  0;
        }
        for(int i = 0 ; i < 22 ; i ++ ){
                flag[i] += i;
        }
        for (int i = 0 ; i < 22 ; i ++ ) {
                if ( (unsigned char)(flag[i]^key[i % 8]) != check[i]) {
                        puts("Wrong!!");
                        return 0;
                }
        }
        puts("Right!!");
//      return 0;
//      for (int i = 0 ; i < 22 ; i ++ ) {
//              flag[i] += i;
//      }
//      for (int i = 0 ; i < 22 ; i ++ ) {
//              flag[i] ^= key[i % 8];
//      }
//      for (int i = 0 ; i < 22 ; i ++ ) {
//              printf("0x%x,", (unsigned char)flag[i]);
//      }
}
