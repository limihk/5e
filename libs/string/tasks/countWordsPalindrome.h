#ifndef LABA_5E_COUNTWORDSPALINDROME_H
#define LABA_5E_COUNTWORDSPALINDROME_H

int countWordsPalindrome(char *str) {
    char *endStr = getEndOfString(str);

    char *wordBegin = findNonSpace(str);
    char *wordEnd = find(str, endStr, ',');

    int countPalindrome = 0;
    while (*wordEnd != '\0' || isgraph(*wordBegin) || isdigit(*wordBegin)) {
        wordBegin = findNonSpace(wordBegin);
        wordEnd = find(wordBegin, endStr, ',');
        countPalindrome += isPalindrome(wordBegin, wordEnd);

        wordBegin = wordEnd + 1;
    }

    return countPalindrome;
}

void test_countWordsPalindrome_onlySpace() {
    char s[] = "     ";
    assert(countWordsPalindrome(s) == 0);
}

void test_countWordsPalindrome_onlySpaceCharacters() {
    char s[] = " \t  \t  \n  \t  \n   ";
    assert(countWordsPalindrome(s) == 0);
}

void test_countWordsPalindrome_oneWordNoPalindrome() {
    char s[] = "hi";
    assert(countWordsPalindrome(s) == 0);
}

void test_countWordsPalindrome_oneWordPalindrome() {
    char s[] = "ihi";
    assert(countWordsPalindrome(s) == 1);
}

void test_countWordsPalindrome_hasPalindromes() {
    char s[] = "radar, tot, ton, hih, asdsa, apple, oppo";
    assert(countWordsPalindrome(s) == 5);
}

void test_countWordsPalindrome_noSpaces() {
    char s[] = "radar,tot,ton,hih,asdsa,apple,oppo";
    assert(countWordsPalindrome(s) == 5);
}

void test_ccountWordsPalindrome_oneLetter() {
    char s[] = "a,b,c,d,e,f,g";
    assert(countWordsPalindrome(s) == 7);
}

void test_countWordsPalindrome() {
    test_countWordsPalindrome_onlySpace();
    test_countWordsPalindrome_onlySpaceCharacters();
    test_countWordsPalindrome_oneWordNoPalindrome();
    test_countWordsPalindrome_oneWordPalindrome();
    test_countWordsPalindrome_hasPalindromes();
    test_countWordsPalindrome_noSpaces();
    test_ccountWordsPalindrome_oneLetter();
}

#endif
