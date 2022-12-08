#include <stdio.h>
#include "testAlerter.h"

// variable to return the network alert status
int testNetworkAlertStatus;

//function definition of network alert test stub
int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return testNetworkAlertStatus;
}
