#ifndef LABA_5E_REVERSEWORDS_H
#define LABA_5E_REVERSEWORDS_H

void reverseWords(char *str) {
    *copy(str, getEndOfString(str), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    char *begin = str;
    for (int i = 0; i < _bag.size; i++) {
        begin = copyReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, begin);
        *begin = '\n';
        begin++;

    }
    if (begin != str)
        begin--;

    *begin = '\0';
}

void printReverseWords(char *str) {
    reverseWords(str);
    printf("%s", str);
}

void test_reverseWords_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    reverseWords(s);

    ASSERT_STRING("", s);
}

void test_reverseWords_onlySpace() {
    char s[MAX_STRING_SIZE] = "        ";
    reverseWords(s);

    ASSERT_STRING("", s);
}

void test_reverseWords_onlySpaceCharacters() {
    char s[MAX_STRING_SIZE] = " \t  \t  \n  \t  \n   ";
    reverseWords(s);

    ASSERT_STRING("", s);
}

void test_reverseWords_oneWord() {
    char s[MAX_STRING_SIZE] = "Hello";
    reverseWords(s);

    ASSERT_STRING("olleH", s);
}

void test_reverseWords_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c d e e d c a b";
    reverseWords(s);

    ASSERT_STRING("a\nb\nc\nd\ne\ne\nd\nc\na\nb", s);
}

void test_reverseWords_withWords() {
    char s[MAX_STRING_SIZE] = "Hello world right left middle";
    reverseWords(s);

    ASSERT_STRING("olleH\ndlrow\nthgir\ntfel\nelddim", s);
}

void test_reverseWords() {
    test_reverseWords_emptyString();
    test_reverseWords_onlySpace();
    test_reverseWords_onlySpaceCharacters();
    test_reverseWords_oneWord();
    test_reverseWords_oneLetter();
    test_reverseWords_withWords();
}





#endif
