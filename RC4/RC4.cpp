#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<cstring>
#include<list>
#include<stdlib.h>
using namespace std;
typedef int status;
typedef int selemtype;
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
            .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    佛祖保佑       永不宕机     永无BUG
*/
void rc4_init(unsigned char*s, unsigned char*key, unsigned long Len) {
	int i = 0, j = 0;
	char k[256] = { 0 };
	unsigned char tmp = 0;
	for (i = 0; i < 256; i++) {
		s[i] = i;
		k[i] = key[i % Len];
	}
	for (i = 0; i < 256; i++) {
		j = (j + s[i] + k[i]) % 256;
		tmp = s[i];
		s[i] = s[j];//交换s[i]和s[j]
		s[j] = tmp;
	}
}

/*加解密*/
void rc4_crypt(unsigned char*s, unsigned char*Data, unsigned long Len) {
	int i = 0, j = 0, t = 0;
	unsigned long k = 0;
	unsigned char tmp;
	for (k = 0; k < Len; k++) {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;
		tmp = s[i];
		s[i] = s[j];//交换s[x]和s[y]
		s[j] = tmp;
		t = (s[i] + s[j]) % 256;
		Data[k] ^= s[t];
	}
}

int main () {
	//unsigned char flag[] = "flag{D0_y0uL1k3_Rc4}";
	puts("Please Input flag~");
	unsigned char input[256] = {0};
	unsigned char check[] = {0x81,0x1C,0x39,0x23,0xE6,0x45,0x8C,0xC5,0xCC,0x47,0x8F,0xC4,0xE,0xF6,0xC7,0xE7,0xD0,0x73,0x5E,0xA6,0};
	int Keylen = 8;
	int flaglen = 20;
	unsigned char key[] = "HUHSTSEC";
	unsigned char Sbox[256 + 5] = {0};
	rc4_init(Sbox, key, Keylen);
	gets((char*)input);

	if(flaglen != strlen((char*)input)){
		puts("Wrong!!");
		return 0;
	}
	rc4_crypt(Sbox,input,flaglen);
	for(int i = 0 ; i < flaglen ; i ++ ){
		if(input[i]!=check[i]){
			puts("Wrong!!");
			return 0;
		}
	}
	puts("Right!!");
}

