#include<stdio.h>
#include<string.h>
unsigned char check[] = { 0x2e,0x84,0x21,0xa7,0x7b,0x46,0x6c,0x6f,0x77,0x65,0x72,0x2d,0x21,0x40,0x23,0x24,0x25,0x5e,0x26,0x2a,0x28,0x29,0x27,0x27,0x5b,0x5d,0x5b,0x5d,0x5b,0x7d };
unsigned char key[] = "HUHSTSEC";
int main()
{
    puts("Please input your flag");
    _asm {
        jz label1
        jnz label1
        nop
        label1 :
    }
    char flag[256] = { 0 };
    gets_s(flag);
    _asm {
        jz label1
        jnz label1
        nop
        label1 :
    }
    if (strlen(flag) != 30) {
        puts("nonono");
        return 0;
    }
    _asm {
        jz label1
        jnz label1
        nop
        label1 :
    }
    int tmp = 1;
    for (int i = 0; i < 30; i++) {
        tmp = (tmp * key[i % 8]) & 0xff;
        flag[i] ^= tmp;
    }
    _asm {
        jz label1
        jnz label1
        nop
        label1 :
    }

    for (int i = 0; i < 30; i++) {
        if ((unsigned char)flag[i] != check[i]) {
            puts("NONONO!!");
            return 0;
        }
    }
    puts("RIght!");
}
