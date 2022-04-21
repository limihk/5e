
#ifndef LABA_5E_DELETEPALINDROMES_H
#define LABA_5E_DELETEPALINDROMES_H

void deletePalindromes(char *str) {
    char *begin = str;
    char *beginCopy = str;

    WordDescriptor word;
    while (getWord(begin, &word)) {
        if (!isPalindrome(word.begin, word.end)) {
            beginCopy = copy(word.begin, word.end, beginCopy);
            *beginCopy++ = ' ';
        }

        begin = word.end;
    }

    if (beginCopy != str)
        beginCopy--;

    *beginCopy = '\0';
}

void test_deletePalindromes_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    deletePalindromes(s);
    ASSERT_STRING("", s);
}

void test_deletePalindromes_OneWordNoPalindrome() {
    char s[MAX_STRING_SIZE] = "Hello";
    deletePalindromes(s);
    ASSERT_STRING("Hello", s);
}

void test_deletePalindromes_OneWordPalindrome() {
    char s[MAX_STRING_SIZE] = "ollo";
    deletePalindromes(s);
    ASSERT_STRING("", s);
}

void test_deletePalindromes_OneLetter() {
    char s[MAX_STRING_SIZE] = "a b c d e f";
    deletePalindromes(s);
    ASSERT_STRING("", s);
}

void test_deletePalindromes_StringHasPalindromes() {
    char s[MAX_STRING_SIZE] = "radar tot ton hih asdsa apple oppo";
    deletePalindromes(s);
    ASSERT_STRING("ton apple", s);
}

void test_deletePalindromes_StringNoHasPalindromes() {
    char s[MAX_STRING_SIZE] = "radars tots ton hihs asdsas apple oppos";
    deletePalindromes(s);
    ASSERT_STRING("radars tots ton hihs asdsas apple oppos", s);
}

void test_deletePalindromes() {
    test_deletePalindromes_emptyString();
    test_deletePalindromes_OneWordNoPalindrome();
    test_deletePalindromes_OneWordPalindrome();
    test_deletePalindromes_OneLetter();
    test_deletePalindromes_StringHasPalindromes();
    test_deletePalindromes_StringNoHasPalindromes();
}

#endif
