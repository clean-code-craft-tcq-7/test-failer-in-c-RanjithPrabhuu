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
    //Test 1: Threshold is 150 degreeC, input is 301.5F and Network alerter gives status 200
    testNetworkAlertStatus = 200;
    alertInCelcius(301.5, networkAlertStub, 150);
    assert(alertFailureCount == 0);
    //Test 2: Threshold is 150 degreeC, input is 302F and Network alerter gives status 200
    testNetworkAlertStatus = 200;
    alertInCelcius(302, networkAlertStub, 150);
    assert(alertFailureCount == 0);
    //Test 3: Threshold is 150 degreeC, input is 302.4F and Network alerter gives status 200
    testNetworkAlertStatus = 200;
    alertInCelcius(302.4, networkAlertStub, 150);
    assert(alertFailureCount == 0);
    //Test 4: Threshold is 150 degreeC, input is 303.5F and Network alerter gives status 500
    testNetworkAlertStatus = 500;
    alertInCelcius(303.5, networkAlertStub, 150);
    assert(alertFailureCount == 1);
    
    printf("%d alerts failed.\n", alertFailureCount);
    
    printf("All is well (maybe!)\n");
    return 0;
}
