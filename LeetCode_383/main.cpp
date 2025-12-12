#include "ransom_note.h"

int main()
{
    std::string ransomNote = "aab";
    std::string magazine = "aa";

    bool ans = canConstruct(ransomNote, magazine);

    std::cout << std::boolalpha << ans << std::endl;

    return 0;
}