#include "ransom_note.h"

bool canConstruct(std::string ransomNote, std::string magazine)
{
    int ans[26] = {0};

    if (ransomNote.size() > magazine.size())
    {
        return false;
    }

    for (int val : ransomNote)
    {
        ans[val - 'a']++;
    }

    for (int val : magazine)
    {
        ans[val - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (ans[i] < 0)
        {
            return false;
        }
    }

    return true;
}