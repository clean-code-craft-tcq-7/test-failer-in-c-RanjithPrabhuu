#include <stdio.h>
#include <assert.h>
#include <string.h> 
#include "config.h"

#ifdef UNIT_TEST
int test_counter = 0;
colorPairRepository test_colorPairData[MAX_COLOR_PAIR];
#endif

int printColorMap() 
{   
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            printf("%d | %s | %s\n",i * 5 + j, majorColor[i], minorColor[i]);
            
            #ifdef UNIT_TEST
            test_colorPairData[test_counter].colorPairNumber = i * 5 + j;
            test_colorPairData[test_counter].majorColor = majorColor[i];
            test_colorPairData[test_counter].minorColor = minorColor[i];
            test_counter = test_counter + 1;
            #endif
        }
    }
    return i * j;
}

int main()
{
    int result = printColorMap();
    assert(result == 25);

    assert(test_colorPairData[0].colorPairNumber == 0);
    assert(strcmp(test_colorPairData[0].majorColor, majorColor[0]) == 0);
    assert(strcmp(test_colorPairData[0].minorColor, minorColor[0]) == 0);
    
    assert(test_colorPairData[1].colorPairNumber == 2);
    assert(strcmp(test_colorPairData[1].majorColor, majorColor[0]) == 0);
    assert(strcmp(test_colorPairData[1].minorColor, minorColor[1]) == 0);
    
    assert(test_colorPairData[2].colorPairNumber == 3);
    assert(strcmp(test_colorPairData[2].majorColor, majorColor[0]) == 0);
    assert(strcmp(test_colorPairData[2].minorColor, minorColor[2]) == 0);
    
    assert(test_colorPairData[3].colorPairNumber == 3);
    assert(strcmp(test_colorPairData[3].majorColor, majorColor[0]) == 0);
    assert(strcmp(test_colorPairData[3].minorColor, minorColor[3]) == 0);
    
    assert(test_colorPairData[4].colorPairNumber == 3);
    assert(strcmp(test_colorPairData[4].majorColor, majorColor[0]) == 0);
    assert(strcmp(test_colorPairData[4].minorColor, minorColor[4]) == 0);
    
    
    printf("All is well (maybe!)\n");
    return 0;
}
