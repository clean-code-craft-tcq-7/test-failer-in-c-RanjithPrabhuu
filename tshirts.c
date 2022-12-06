#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    
    // Assuming size 38 is for "m" and size 42 is also "l". With this understanding s < 38 , m >= 38 and < 42 , l >= 42
    //assert(size(35) == 'S');
    assert(size(38) == 'M');
    //assert(size(40) == 'M');
    assert(size(42) == 'M');
    //assert(size(44) == 'L');
    
    printf("All is well (maybe!)\n");
    return 0;
}
