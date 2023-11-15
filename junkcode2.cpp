//_asm
//{
//    call f1
//    push eax
//    f1:
//    add     byte ptr[esp + 0], 7
//    ret
//    _EMIT 0x89
//}
#include<stdio.h>
#include<string.h>
unsigned char check[] = { 0x35,0x6a,0x2f,0x7a,0x32,0x5c,0x33,0x73,0x23,0x64,0x3b,0x37,0x6f,0x5d,0x7b,0x3f,0x76,0x58,0x68,0x37,0x61,0x33,0x78,0x3b,0xf,0x5c,0x12,0x47,0x15,0x60 };
unsigned char key[] = "HUHSTSEC";
int main()
{
    puts("Please input your flag");
    _asm
    {
        call f1
        push eax
       f1 :
        add     byte ptr[esp + 0], 7
        ret
        _EMIT 0x89
    }
    char flag[256] = { 0 };
    gets_s(flag);
    _asm
    {
        call f2
        push eax
       f2 :
        add     byte ptr[esp + 0], 7
        ret
        _EMIT 0x89
    }
    if (strlen(flag) != 30) {
        puts("nonono");
        return 0;
    }
    _asm
    {
        call f3
        push eax
        f3 :
        add     byte ptr[esp + 0], 7
        ret
        _EMIT 0x89
    }
    int tmp = 27;
    for (int i = 0; i < 30; i++) {
        tmp = (tmp ^ key[i % 8]) & 0xff;
        flag[i] ^= tmp;
    }
    _asm
    {
        call f4
        push eax
        f4 :
        add     byte ptr[esp + 0], 7
        ret
        _EMIT 0x89
    }
    for (int i = 0; i < 30; i++) {
        if ((unsigned char)flag[i] != check[i]) {
            puts("NONONO!!");
            return 0;
        }
    }
    puts("RIght!");
}
