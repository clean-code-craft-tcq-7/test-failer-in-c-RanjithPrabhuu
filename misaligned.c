#include <stdio.h>
#include <assert.h>
#include <string.h> 
#include "config.h"

//variable added for test case addition
int test_counter = 0;
colorPairRepository test_colorPairData[MAX_COLOR_PAIR];

int printColorMap() 
{   
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            printf("%d | %s | %s\n",i * 5 + j, majorColor[i], minorColor[i]);
            
            //statements added for test case addition
            test_colorPairData[test_counter].colorPairNumber = i * 5 + j;
            test_colorPairData[test_counter].majorColor = majorColor[i];
            test_colorPairData[test_counter].minorColor = minorColor[i];
            test_counter = test_counter + 1;
        }
    }
    return i * j;
}

int main()
{
    int result = printColorMap();
    assert(result == 25);
    
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
    printf("All is well (maybe!)\n");
    return 0;
}
