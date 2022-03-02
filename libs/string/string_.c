#include <stdio.h>
#include "string_.h"
#include <memory.h>
#include <ctype.h>

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {

    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }
    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend){
        while (rbegin != rend && !isspace(*rbegin)){
            rbegin--;
        }
    return rbegin;
}
int strcmp ( const char * lhs , const char * rhs ){
    if (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs)
        return strcmp(++lhs, ++rhs);
    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination){
    long long distance = endSource - beginSource;
    memcpy(beginDestination, beginSource, distance);

    return beginDestination + distance;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)){
    long long fDistance = 0;
    while (*beginSource != '\0' && beginSource != endSource)
        if (f(*(beginSource++))){
            memcpy(beginDestination++, beginSource - 1, sizeof(char));
            fDistance++;
        }

    return beginDestination + fDistance;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){
    long long fDistance = rbeginSource - rendSource;
    while (rbeginSource != rendSource)
        if (f(*(rbeginSource--))){
            memcpy(beginDestination, rbeginSource + 1, sizeof(char));
            fDistance++;
        }

    return beginDestination + fDistance;
}
