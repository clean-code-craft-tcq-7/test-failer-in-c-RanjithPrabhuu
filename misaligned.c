#include <stdio.h>
#include <assert.h>
#include <string.h> 
#include "config.h"

//variable added for test case addition
int counter = 0;
colorPairRepository test_colorPairData[MAX_COLOR_PAIR];
char* colorPairBuffer[MAX_COLOR_PAIR];

void printColorMap() 
{   
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {       
            //statements to copy the pair num and colors to buffer which is used in printing the table
            test_colorPairData[counter].colorPairNumber = i * 5 + j;
            test_colorPairData[counter].majorColor = majorColor[i];
            test_colorPairData[counter].minorColor = minorColor[j];          
            
            // print color pair
            memset(colorPairBuffer[counter], 0, TABLE_ROW_SIZE);
            sprintf(colorPairBuffer[counter],"%-2d | %-6s | %s\n",test_colorPairData[counter].colorPairNumber,test_colorPairData[counter].majorColor,test_colorPairData[counter].minorColor);
            printf("%s\n",colorPairBuffer[counter]);
            
            counter = counter + 1;
        }
    }
}

int main()
{
    printColorMap();
    
    // major color "white" is taken for test case validation
    //test case to check the pair number 1 and its major and minor color. 
    assert(test_colorPairData[0].colorPairNumber == 0); //This will pass
    assert(strcmp(test_colorPairData[0].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(test_colorPairData[0].minorColor, minorColor[0]) == 0); //This will pass
    
    //test case to check the pair number 2 and its major and minor color.
    assert(test_colorPairData[1].colorPairNumber == 1); //This will pass
    assert(strcmp(test_colorPairData[1].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(test_colorPairData[1].minorColor, minorColor[1]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of a major color
    
    //test case to check the pair number 3 and its major and minor color.
    assert(test_colorPairData[2].colorPairNumber == 2); //This will pass
    assert(strcmp(test_colorPairData[2].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(test_colorPairData[2].minorColor, minorColor[2]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of single major color
    
    //test case to check the pair number 4 and its major and minor color.
    assert(test_colorPairData[3].colorPairNumber == 3); //This will pass
    assert(strcmp(test_colorPairData[3].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(test_colorPairData[3].minorColor, minorColor[3]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of a major color
    
    //test case to check the pair number 5 and its major and minor color.This will fail
    assert(test_colorPairData[4].colorPairNumber == 4); //This will pass
    assert(strcmp(test_colorPairData[4].majorColor, majorColor[0]) == 0); //This will pass
    assert(strcmp(test_colorPairData[4].minorColor, minorColor[4]) == 0); //This will fail since the minorColor[i] will be same for all the 5 pairs of a major color
      
    // similar to the above 5 test cases for major color "white", the test cases can be extended for all the other four major color's and their minor color pair's
    
    // test case to check the indentation
    assert(strcmp(colorPairBuffer[0],"1  | White  | Blue") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
