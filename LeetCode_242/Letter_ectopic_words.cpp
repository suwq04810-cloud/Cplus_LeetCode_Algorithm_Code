#include "Letter_ectopic_words.h"

bool isAnagram(std::string s, std::string t)
{
    int hash[27] = {0};
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a' + 1]++;
    }

    for (size_t j = 0; j < t.size(); j++)
    {
        hash[t[j] - 'a' + 1]--;
    }

    for (int i = 1; i < 27; i++)
    {
        if (hash[i] != 0)
        {
            return false;
        }
    }
    return true;
}