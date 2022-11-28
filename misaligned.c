#include <stdio.h>
#include <assert.h>
#include <string.h> 
#include "config.h"

int printColorMap() 
{
    int test_counter = 0;
    colorPairRepository test_colorPairData[MAX_COLOR_PAIR];
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            printf("%d | %s | %s\n", test_colorPairData.colorPairNumber, test_colorPairData.majorColor, test_colorPairData.minorColor);
            
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

    assert(test_colorPairData[0].colorPairNumber == 1);
    assert(strcmp(test_colorPairData[0].majorColor, "White") == 0);
    assert(strcmp(test_colorPairData[0].minorColor, "Blue") == 0);
    assert(test_colorPairData[1].colorPairNumber == 2);
    assert(strcmp(colorPairNumber[1].majorColor, "White") == 0);
    assert(strcmp(colorPairNumber[1].minorColor, "Orange") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
