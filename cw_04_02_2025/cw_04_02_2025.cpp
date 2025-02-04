// определение символической константы _UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE

#include <iostream>
#include <windows.h>
#include <tchar.h>// для макросов windows

//  1. Пользователь вводит текст(только кириллица).Подсчитать количество слов, которые заканчиваются на гласную букву.

using namespace std;

int vowelEndingWordCount(_TCHAR str[])
{
    _TCHAR vow[] = _T("аеёиоуыэюяАЕЁИОУЫЭЮЯ");

    int vLen = _tcslen(vow);

    auto isVowel = [&](_TCHAR ch)
    {
        for (int i = 0; i < vLen; i++)
        {
            if (ch == vow[i])
            {
                return true;
            }
        }
        return false;
    };

    int count = 0;
    int len = _tcslen(str);

    for (int i = 0; i < len; i++)
    {
        if (isVowel(str[i]) && !_istalpha(str[i + 1]))
        {
            count++;
        }
    }
    return count;
}


void main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    _TCHAR szBuf3[300] = _T("съешь ещё этих мягких французских булок, да выпей чаю.");

    wcout << vowelEndingWordCount(szBuf3) << endl;
}
