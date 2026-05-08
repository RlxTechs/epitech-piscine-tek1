#include <stdio.h>
#include <stdlib.h>

int is_separator(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    }
    return 0;
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i] != '\0') {
        if (is_separator(str[i]) == 1) {
            in_word = 0;
        } else if (in_word == 0) {
            count = count + 1;
            in_word = 1;
        }
        i = i + 1;
    }
    return count;
}

int word_len(char *str, int start)
{
    int len = 0;

    while (str[start + len] != '\0' && is_separator(str[start + len]) == 0) {
        len = len + 1;
    }
    return len;
}

char *copy_word(char *str, int start, int len)
{
    char *word = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (word == NULL) {
        return NULL;
    }
    while (i < len) {
        word[i] = str[start + i];
        i = i + 1;
    }
    word[i] = '\0';
    return word;
}

void free_words(char **words)
{
    int i = 0;

    if (words == NULL) {
        return;
    }
    while (words[i] != NULL) {
        free(words[i]);
        i = i + 1;
    }
    free(words);
}

char **split_words(char *str)
{
    int total = count_words(str);
    char **words = malloc(sizeof(char *) * (total + 1));
    int i = 0;
    int index = 0;
    int len = 0;

    if (words == NULL) {
        return NULL;
    }
    while (str[i] != '\0') {
        while (str[i] != '\0' && is_separator(str[i]) == 1) {
            i = i + 1;
        }
        if (str[i] != '\0') {
            len = word_len(str, i);
            words[index] = copy_word(str, i, len);
            if (words[index] == NULL) {
                words[index] = NULL;
                free_words(words);
                return NULL;
            }
            index = index + 1;
            i = i + len;
        }
    }
    words[index] = NULL;
    return words;
}

int main(void)
{
    char **words = split_words("RLX apprend malloc et les strings");
    int i = 0;

    if (words == NULL) {
        return 1;
    }
    while (words[i] != NULL) {
        printf("word[%d] = %s\n", i, words[i]);
        i = i + 1;
    }
    free_words(words);
    return 0;
}
