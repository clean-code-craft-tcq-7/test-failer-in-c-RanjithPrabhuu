#include <stdio.h>
#include <assert.h>
#include <string.h> 
#include "misalignedConfig.h"

//variable added for test case addition
int counter = 0;
colorPairRepository colorPairData[MAX_COLOR_PAIR];

// function to print the color pair
void printColorPair(char* colorPairBuff, int Idx)
{
    memset(colorPairBuff, 0, TABLE_ROW_SIZE);
    sprintf(colorPairBuff, "%-2d | %-6s | %s",colorPairData[Idx].colorPairNumber,colorPairData[Idx].majorColor, colorPairData[Idx].minorColor);
}

// function to print the color pair and map
void printColorMap() 
{   
    int i = 0, j = 0;
    char colorPairBuffer[TABLE_ROW_SIZE];
    
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {       
            //statements to copy the pair num and colors to buffer which is used in printing the table
            colorPairData[counter].colorPairNumber = (i * 5 + j) + 1;
            colorPairData[counter].majorColor = majorColor[i];
            colorPairData[counter].minorColor = minorColor[j];     
            
            // print color pair
            printColorPair(colorPairBuffer, counter);
            printf("%s\n", colorPairBuffer);
            
            counter = counter + 1;       
        }
    }
}

int main()
{
    printColorMap();
    
    // major color "white" is taken for test case validation
    //test case to check the pair number 1 and its major and minor color. 
    assert(colorPairData[0].colorPairNumber == 1); //This will pass
    assert(strcmp(colorPairData[0].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(colorPairData[0].minorColor, minorColor[0]) == 0); //This will pass
    
    //test case to check the pair number 2 and its major and minor color.
    assert(colorPairData[1].colorPairNumber == 2); //This will pass
    assert(strcmp(colorPairData[1].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(colorPairData[1].minorColor, minorColor[1]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of a major color
    
    //test case to check the pair number 3 and its major and minor color.
    assert(colorPairData[2].colorPairNumber == 3); //This will pass
    assert(strcmp(colorPairData[2].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(colorPairData[2].minorColor, minorColor[2]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of single major color
    
    //test case to check the pair number 4 and its major and minor color.
    assert(colorPairData[3].colorPairNumber == 4); //This will pass
    assert(strcmp(colorPairData[3].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(colorPairData[3].minorColor, minorColor[3]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of a major color
    
    //test case to check the pair number 5 and its major and minor color.This will fail
    assert(colorPairData[4].colorPairNumber == 5); //This will pass
    assert(strcmp(colorPairData[4].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(colorPairData[4].minorColor, minorColor[4]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of a major color
      
    // similar to the above 5 test cases for major color "white", the test cases can be extended for all the other four major color's and their minor color pair's
    
    // test case to check the indentation
    char colorPairBuffer[TABLE_ROW_SIZE];
    printColorPair(colorPairBuffer, 0);
    assert(strcmp(colorPairBuffer,"1  | White  | Blue") == 0);
    printColorPair(colorPairBuffer, 1);
    assert(strcmp(colorPairBuffer,"2  | White  | Orange") == 0);
    printColorPair(colorPairBuffer, 2);
    assert(strcmp(colorPairBuffer,"3  | White  | Green") == 0);
    printColorPair(colorPairBuffer, 3);
    assert(strcmp(colorPairBuffer,"4  | White  | Brown") == 0);
    printColorPair(colorPairBuffer, 4);
    assert(strcmp(colorPairBuffer,"5  | White  | Slate") == 0);
    printColorPair(colorPairBuffer, 5);
    assert(strcmp(colorPairBuffer,"6  | Red    | Blue") == 0);
    
    // similar to the above 5 test cases for major color "white" indentation check, the test cases can be extended for all the other four major color's and their minor color pair's
    
    printf("All is well (maybe!)\n");
    return 0;
}
