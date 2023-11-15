#include <jni.h>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cppandriod_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
   // std::string hello = "flag{Co0l_JustaEasy_so}";
    unsigned char flag[] = {0x2E,0x39,0x29,0x34,0x2F,0x10,0x2A,0x73,0x24,0xA,0x2,0x26,0x27,0x27,0x24,0x6,0x29,0x26,0x31,0xC,0x27,0x3C,0x38,0x43,0x50,0x55,0x48,0x53,0x58,0xAC,0x31,0x43,0x48,0xE5,0x7E,0};
    unsigned char key[] = "HUHSTSEC";
    for(int i = 0 ; i < strlen((char*)flag) ; i ++ ){
        flag[i]^=key[i%8];
    }
    printf("%s",flag);
    string result(reinterpret_cast<char*>(flag));
    return env->NewStringUTF(result.c_str());
}