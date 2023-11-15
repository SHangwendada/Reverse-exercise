#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>

//修改API入口为 mov eax, 00400000;jmp eax是程序能跳转到自己的函数
BYTE __NewCode[7] = { 0xE9, 0x0, 0x0, 0x0, 0x0, 0x0 };
BYTE __OldCode[7] = { 0 };

FARPROC __MessageBoxAddress;

int WINAPI MyMessageBoxA(
	HWND hWnd,          // handle to owner window
	LPCTSTR lpText,     // text in message box
	LPCTSTR lpCaption,  // message box title
	UINT uType          // message box style
);
int mystrcmp(const char* s1, const char* s2);

void InlineHook();
void InlineHook();

int Strcmp(const char* s1, const char* s2) {
	return strcmp(s1, s2);
}


void main()
{
	InlineHook();
	char s1[256] = { 0 };
	char s2[] = "flag{Maybe_1_4m_a_f4ck_fl4g~}";
	puts("Please input Your flag");
	gets_s(s1);
	if (!Strcmp(s1, s2)) {
		puts("Right!!");
	}
	else {
		puts("Wrong!!");
	}
	system("pause");
}

void InlineHook()
{

	if (ReadProcessMemory(INVALID_HANDLE_VALUE, Strcmp, __OldCode, 7, NULL) == 0)
	{
		printf("ReadProcessMemory error\n");
		return;
	}

	DWORD JmpAddress = (DWORD)mystrcmp;
	// 计算自定义函数的地址.
	// 构造新头部代码
	__NewCode[0] = 0xB8;            //
	memcpy(&__NewCode[1], &JmpAddress, 4);    // mov eax, _JmpAddr
	__NewCode[5] = 0xFF;            //
	__NewCode[6] = 0xE0;            // jmp eax
	DWORD dwOldProtect = 0;
	//DWORD dwOldProtect = 0; //旧保护属性
	// 去内存保护
	::VirtualProtect(Strcmp, 7, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	//写入跳转，开始Hook
	WriteProcessMemory(INVALID_HANDLE_VALUE, Strcmp, __NewCode, 7, NULL);
	// 写内存保护
	::VirtualProtect(Strcmp, 7, dwOldProtect, &dwOldProtect);
}

int mystrcmp(const char* s1, const char* s2) {
	char s3[] = { 0x55,0x5F,0x52,0x54,0x48,0x7B,0x5C,0x44,0x6C,0x75,0x46,0x5D,0x5D,0x4A,0x6C,0x47,0x0,0x5B,0x6C,0x5B,0x3,0x5C,0x58,0x6C,0x2,0x40,0x12,0x12,0x4E,0};
	if (!IsDebuggerPresent()) {
		for (int i = 0; i < strlen(s1); i++)
		{
			s3[i] ^= 0x33;
		}
	}
	WriteProcessMemory(INVALID_HANDLE_VALUE, (void*)Strcmp,
		(void*)__OldCode, 7, NULL);
	int ret = Strcmp(s1, s3);
	return ret;
}
