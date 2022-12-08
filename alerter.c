#include <stdio.h>
#include <assert.h>
#include "testAlerter.h"

// flag to return the failure count
int alertFailureCount = 0;

void alertInCelcius(float farenheit,int(*networkAlert)(float), float threshold) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode;
    if(celcius > threshold)
    {
        returnCode = networkAlert(celcius);   
        if (returnCode != 200) 
        {       
            alertFailureCount += 1;
        }
     }       
}

int main() 
{
    //Test 1 is Threshold is 200 degreeC, farenheit is 350 and Network alerter gives status 200
    test_AlertStatusOfNetwork = 200;
    alertInCelcius(350, networkAlertStub, 200);
    assert(alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);
    
    //Test 2 is Threshold is 200 degreeC, farenheit is 400 and Network alerter gives status 200
    test_AlertStatusOfNetwork = 200;
    alertInCelcius(400, networkAlertStub, 200);
    assert(alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);
    
    //Test 2 is Threshold is 200 degreeC, farenheit is 420 and Network alerter gives status 500
    test_AlertStatusOfNetwork = 500;
    alertInCelcius(420, networkAlertStub, 200);
    assert(alertFailureCount == 1);   
    printf("%d alerts failed.\n", alertFailureCount);

    printf("All is well (maybe!)\n");
    return 0;
}
