#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
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
    printf("All is well (maybe!)\n");
    //newly added tests
    assert(size(38) == 'S'); //Test to check the boundary value 38 for "s" size
    assert(size(38) == 'M'); //Test to check the boundary value 38 for "m" size
    assert(size(42) == 'M'); //Test to check the boundary value 42 for "m" size
    assert(size(42) == 'L'); //Test to check the boundary value 42 for "l" size
    return 0;
}
