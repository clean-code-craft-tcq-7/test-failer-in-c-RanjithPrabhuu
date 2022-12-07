#include <stdio.h>
#include <assert.h>
#include "config.h"

// flag to return the failure count
int alertFailureCount = 0;

//flag to return the alert status for test cases
int test_AlertStatusOfNetwork = 0;

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return test_AlertStatusOfNetwork;
}

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
    //Test 1 is Threshold is 200 degreeC, farenheit is 400F and Network alerter gives status 200
    test_AlertStatusOfNetwork = 200;
    alertInCelcius(400, networkAlertStub, 200);
    assert(alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);
    
    //Test 2 is Threshold is 200 degreeC, farenheit is 350F and Network alerter gives status 500
    test_AlertStatusOfNetwork = 500;
    alertInCelcius(350, networkAlertStub, 200);
    assert(alertFailureCount == 1);   
    printf("%d alerts failed.\n", alertFailureCount);

    printf("All is well (maybe!)\n");
    return 0;
}
