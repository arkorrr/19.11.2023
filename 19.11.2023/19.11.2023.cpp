#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <Windows.h>

using namespace std;

void Task1(FILE* file)
{
    char line[1024];
    int max_length = 0;

    while (fgets(line, sizeof(line), file)) {
        int length = strlen(line);
        if (length > max_length) {
            max_length = length;
        }
    }

    fclose(file);

    printf("Length of the longest line: %d\n", max_length);
}

void Task2(FILE* file)
{
    char word[1024];
    char searchWord[1024];
    cout << "Enter a word: ";
    cin >> searchWord;

    int count = 0;

    while (fscanf(file, "%1023s", word) == 1) {
        if (strcmp(word, searchWord) == 0) {
            ++count;
        }
    }

    fclose(file);
    printf("Word '%s' meets %d time(s).\n", searchWord, count);
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Дан текстовый файл. Найти длину самой длинной строки.
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }
    Task1(file);

    //Дан текстовый файл. Посчитать сколько раз в нем встречается заданное пользователем слово
    FILE* file2 = fopen("Task2.txt", "r");
    if (!file)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    Task2(file2);
    return 0;
}

