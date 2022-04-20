#ifndef LABA_5E_ALTERNATINGWORDSFORMTWOSTRING_H
#define LABA_5E_ALTERNATINGWORDSFORMTWOSTRING_H

void alternatingWordsFormTwoString(char *resultS, char *s1, char *s2) {
    char *beginS = resultS;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            beginS = copy(word1.begin, word1.end, beginS);
            *beginS++ = ' ';
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            beginS = copy(word2.begin, word2.end, beginS);
            *beginS++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (beginS != resultS)
        beginS--;

    *beginS = '\0';
}

void test_alternatingWordsFormTwoString_stringsEmpty() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "", "");
    ASSERT_STRING("", s);
}

void test_alternatingWordsFormTwoString_stringsSpace() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "   ", "   ");
    ASSERT_STRING("", s);
}

void test_alternatingWordsFormTwoString_OneWordString() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "Hello", "World");
    ASSERT_STRING("Hello World", s);
}

void test_alternatingWordsFormTwoString_OneWordInSecondString() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "Hello and cat and dog", "monkey");
    ASSERT_STRING("Hello monkey and cat and dog", s);
}

void test_alternatingWordsFormTwoString_OneWordInFirstString() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "monkey", "Hello and cat and dog");
    ASSERT_STRING("monkey Hello and cat and dog", s);
}

void test_alternatingWordsFormTwoString_firstStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "", "Hello World");
    ASSERT_STRING("Hello World", s);
}

void test_alternatingWordsFormTwoString_secondStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    alternatingWordsFormTwoString(s, "Hello World", "");
    ASSERT_STRING("Hello World", s);
}

void test_alternatingWordsFormTwoString() {
    test_alternatingWordsFormTwoString_stringsEmpty();
    test_alternatingWordsFormTwoString_stringsSpace();
    test_alternatingWordsFormTwoString_OneWordString();
    test_alternatingWordsFormTwoString_OneWordInSecondString();
    test_alternatingWordsFormTwoString_OneWordInFirstString();
    test_alternatingWordsFormTwoString_firstStringIsEmpty();
    test_alternatingWordsFormTwoString_secondStringIsEmpty();
}



#endif
