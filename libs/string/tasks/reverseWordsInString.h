
#ifndef LABA_5E_REVERSEWORDSINSTRING_H
#define LABA_5E_REVERSEWORDSINSTRING_H

void reverseWordsInString(char *str) {
    char *end = copy(str, getEndOfString(str), _stringBuffer);
    char *beginCopy = str;

    char *rbegin = end - 1;

    WordDescriptor word;
    while (getWordReverse(rbegin, _stringBuffer - 1, &word)) {
        beginCopy = copy(word.begin, word.end, beginCopy);
        *beginCopy++ = ' ';

        rbegin -= word.end - word.begin + 1;
        rbegin = findNonSpaceReverse(rbegin, _stringBuffer - 1);
    }

    if (beginCopy != str)
        beginCopy--;

    *beginCopy = '\0';
}

void test_reverseWordsInString_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordsInString(s);

    ASSERT_STRING("", s);
}

void test_reverseWordsInString_onlySpace() {
    char s[MAX_STRING_SIZE] = "       ";
    reverseWordsInString(s);

    ASSERT_STRING(" ", s);
}

void test_reverseWordsInString_oneWord() {
    char s[MAX_STRING_SIZE] = "pain";
    reverseWordsInString(s);

    ASSERT_STRING("pain", s);
}

void test_reverseWordsInString_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c a b c";
    reverseWordsInString(s);

    ASSERT_STRING("c b a c b a", s);
}

void test_reverseWordsInString_WordsInString() {
    char s[MAX_STRING_SIZE] = "One    two  three four five   six seven ";
    reverseWordsInString(s);

    ASSERT_STRING("seven six five four three two One", s);
}


void test_reverseWordsInString() {
    test_reverseWordsInString_emptyString();
    test_reverseWordsInString_onlySpace();
    test_reverseWordsInString_oneWord();
    test_reverseWordsInString_oneLetter();
    test_reverseWordsInString_WordsInString();
}

#endif
