#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *repeatStr(char *str, size_t count)
{
    if (count == 0)
        return NULL;
    char *ret = malloc(strlen(str) * count + count);
    if (ret == NULL)
        return NULL;
    strcpy(ret, str);
    while (--count > 0)
    {
        strcat(ret, str);
    }
    return ret;
}

void printSpeechBubbleTop(int width)
{
    for (int column = 0; column <= width; column++)
    {
        printf("-");
    }
    printf("\n");
}

void printSpeechBubbleBottom(int width)
{
    printf("%-6s", "");
    for (int column = 0; column <= width; column++)
    {
        if (column == 1)
        {
            printf("\\");
        }
        else if (column == 2)
        {
            printf("/");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
}

void printSpeechBubbleBody(char *textList[], int width, int height)
{
    int counter = 0;
    int spacerCount = 0;
    char spacer[10];
    char *padLeftSpacer;
    char *padRightSpacer;
    for (int row = 0; row <= height; row++)
    {
        if (row == 0)
        {
            printf("%s\\%-10s\\\n", spacer, "");
        }
        else if (row == height)
        {
            strcat(spacer, " ");
            spacerCount++;
            printf("%s\\%-10s\\\n", spacer, "");
        }
        else if (row >= 1 && row <= height - 3)
        {
            strcat(spacer, " ");
            spacerCount++;
            char *text = textList[counter];
            int textLength = strlen(text);
            int pad = ceil((width - textLength) / 2);
            padLeftSpacer = repeatStr(" ", pad);
            padRightSpacer = repeatStr(" ", pad);
            if(counter == 0){
                strcat(padLeftSpacer," ");
            }
            printf("%s\\%s%s%s\\\n", spacer, padLeftSpacer, text, padRightSpacer);
            counter = counter + 1;
        }
    }
}

void getSpeechBubble(int width, int height)
{
    char *textList[4] = {"SLC", "Sommer", "LESE", "CLUB"};
    printSpeechBubbleTop(width);
    printSpeechBubbleBody(textList, width, height);
    printSpeechBubbleBottom(width);
}

int main()
{
    getSpeechBubble(10, 7);
}