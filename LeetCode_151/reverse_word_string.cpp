#include "reverse_word_string.h"

std::string reverseWords(std::string s)
{
    int len = (size_t)s.size();
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != ' ')
        { // 发现单词
            if (j != 0)
                s[j++] = ' '; // 如果不是第一个单词，手动补一个空格

            // 开始搬运整个单词
            while (i < len && s[i] != ' ')
            {
                s[j++] = s[i++];
            }
        }
    }
    s.resize(j); // 关键：j就是处理后字符串的真实长度，舍弃后面残余的字符

    int newLen = s.size();

    reverse(s.begin(), s.end()); // 例如 "hello world" -> "dlrow olleh"

    int start = 0;
    for (int i = 0; i <= newLen; i++)
    {
        // 逻辑：遇到空格或到达末尾，说明抓到了一个完整的单词
        if (i == newLen || s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i); // 翻转 [start, i-1] 范围
            start = i + 1;                             // start 跳到空格后的下一个位置，准备处理下个单词
        }
    }

    return s;
}