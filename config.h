#define MAX_COLOR_PAIR 25
#define TABLE_ROW_SIZE 50

// array to hold the major and minor color names
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Structure which will act as a repository to return the color pair information
typedef struct{
    int colorPairNumber;
    const char *majorColor;
    const char *minorColor;
}colorPairRepository;

//function pointer for test codes
typedef int (*networkAlertStub_FunPtr )(float);
