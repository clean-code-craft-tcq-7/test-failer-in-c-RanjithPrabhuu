#define UNIT_TEST   1
#define MAX_COLOR_PAIR_POSSIBLE 25

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Structure which will act as a repository to return the color pair information
typedef struct{
    int colorPairNumber;
    const char *majorColor;
    const char *minorColor;
}colorPairRepository;
