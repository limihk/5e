
#ifndef LABA_5E_SEARCHFIRSTWORD_H
#define LABA_5E_SEARCHFIRSTWORD_H

char *searchFirstWord(char *str, char *word) {
    while (*str != '\0') {
        if (*str == *word) {
            int isFound = 1;

            char *beginWord = word;
            char *beginStr = str;

            while (*beginWord != '\0' && isFound || !isspace(*beginStr) && *beginStr != '\0') {
                if (*beginStr != *beginWord)
                    isFound = 0;
                beginStr++;
                beginWord++;
            }
            if (isFound)
                return str;
        }
        str++;
    }
    return str;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        *copy(source, getEndOfString(source), _stringBuffer) = '\0';
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        char *beginWord = searchFirstWord(readPtr, word1.begin);
        recPtr = copy(readPtr, beginWord, recPtr);
        readPtr = beginWord + w1Size;

        if (*beginWord == '\0') {
            *recPtr = '\0';
            return;
        }

        recPtr = copy(word2.begin, word2.end, recPtr);

    }
    *recPtr = '\0';
}

void test_replace_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    char w1[MAX_WORD_SIZE] = "HI";
    char w2[MAX_WORD_SIZE] = "HELLO";
    replace(s, w1, w2);
    ASSERT_STRING("", s);
}

void test_replace_onlySpace() {
    char s[MAX_STRING_SIZE] = "       ";
    char w1[MAX_WORD_SIZE] = "HI";
    char w2[MAX_WORD_SIZE] = "HELLO";
    replace(s, w1, w2);
    ASSERT_STRING("       ", s);
}

void test_replace_onlySpaceCharacters() {
    char s[MAX_STRING_SIZE] = " \t  \t  \n  \t  \n   ";
    char w1[MAX_WORD_SIZE] = "HI";
    char w2[MAX_WORD_SIZE] = "HELLO";
    replace(s, w1, w2);
    ASSERT_STRING(" \t  \t  \n  \t  \n   ", s);
}

void test_replace_nonWords() {
    char s[MAX_STRING_SIZE] = "HI";
    char w1[MAX_WORD_SIZE] = "";
    char w2[MAX_WORD_SIZE] = "";
    replace(s, w1, w2);
    ASSERT_STRING("HI", s);
}

void test_replace_withWords() {
    char s[MAX_STRING_SIZE] = "HI";
    char w1[MAX_WORD_SIZE] = "HI";
    char w2[MAX_WORD_SIZE] = "HELLO";
    replace(s, w1, w2);
    ASSERT_STRING("HELLO", s);
}

void test_replace_withWordsBeginMiddleEnd() {
    char s[MAX_STRING_SIZE] = "HI OH HI SORRY HI";
    char w1[MAX_WORD_SIZE] = "HI";
    char w2[MAX_WORD_SIZE] = "HELLO";
    replace(s, w1, w2);
    ASSERT_STRING("HELLO OH HELLO SORRY HELLO", s);
}

void test_replace_WordsWithTheBeginningOfTheFirstWord() {
    char s[MAX_STRING_SIZE] = "HIOH HISORRY HI";
    char w1[MAX_WORD_SIZE] = "HI";
    char w2[MAX_WORD_SIZE] = "HELLO";
    replace(s, w1, w2);
    ASSERT_STRING("HIOH HISORRY HELLO", s);
}

void test_replace() {
    test_replace_emptyString();
    test_replace_onlySpace();
    test_replace_onlySpaceCharacters();
    test_replace_nonWords();
    test_replace_withWords();
    test_replace_withWordsBeginMiddleEnd();
    test_replace_WordsWithTheBeginningOfTheFirstWord();
}

#endif
