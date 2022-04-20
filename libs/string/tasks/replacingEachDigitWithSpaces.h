#ifndef LABA_5E_REPLACINGEACHDIGITWITHSPACES_H
#define LABA_5E_REPLACINGEACHDIGITWITHSPACES_H

#define THE_CODE_OF_THE_DIGIT_ZERO_IN_CHAR 48

void replacingEachDigitWithSpaces(char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    char *readPtr = _stringBuffer;

    while (readPtr < endBuffer) {
        if (isdigit(*readPtr)) {
            while (*readPtr != THE_CODE_OF_THE_DIGIT_ZERO_IN_CHAR) {
                *s = ' ';
                s++;
                (*readPtr)--;
            }
            readPtr++;
            *s = *readPtr;
        } else {
            readPtr++;
            s++;
        }
    }
    *s = '\0';
}

void test_replacingEachDigitWithSpaces_figuresInWord() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    replacingEachDigitWithSpaces(s);
    ASSERT_STRING("A   BC ", s);
}

void test_replacingEachDigitWithSpaces_AfterBeforeWord() {
    char s[MAX_STRING_SIZE] = "4A3B12E0C1\t";
    replacingEachDigitWithSpaces(s);
    ASSERT_STRING("    A   B   EC \t", s);
}

void test_replacingEachDigitWithSpaces_noFigures() {
    char s[MAX_STRING_SIZE] = "ABEC";
    replacingEachDigitWithSpaces(s);
    ASSERT_STRING("ABEC", s);
}

void test_replacingEachDigitWithSpaces_noLetters() {
    char s[MAX_STRING_SIZE] = "1234";
    replacingEachDigitWithSpaces(s);
    ASSERT_STRING("          ", s);
}

void test_replacingEachDigitWithSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    replacingEachDigitWithSpaces(s);
    ASSERT_STRING("", s);
}

void test_replacingEachDigitWithSpaces() {
    test_replacingEachDigitWithSpaces_figuresInWord();
    test_replacingEachDigitWithSpaces_AfterBeforeWord();
    test_replacingEachDigitWithSpaces_noFigures();
    test_replacingEachDigitWithSpaces_noLetters();
    test_replacingEachDigitWithSpaces_emptyString();
}

#endif
