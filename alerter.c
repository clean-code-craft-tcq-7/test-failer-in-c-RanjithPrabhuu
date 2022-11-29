#include <stdio.h>
#include <assert.h>
#include "config.h"

int alertFailureCount = 0;

#ifdef UNIT_TEST //start of macro to switch between test code and production code
#define networkAlert networkAlertStub
int test_AlertStatusOfNetwork = 0;
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return test_AlertStatusOfNetwork;
}
#endif //end of macro to switch between test code and production code

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() 
{
    //test case when alert status is 200
    test_AlertStatusOfNetwork = 200;
    alertInCelcius(400.5);
    assert(alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);
    
    //test case when alert status is 500
    test_AlertStatusOfNetwork = 500;
    alertInCelcius(303.6);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    
    printf("All is well (maybe!)\n");
    return 0;
}
