#include "Letter_ectopic_words.h"

int main()
{
    std::string s = "anagram";
    std::string t = "nagaram"; 

    bool ans = isAnagram(s, t);

    std::cout << std::boolalpha;
    std::cout << ans << std::endl;

    return 0;
}