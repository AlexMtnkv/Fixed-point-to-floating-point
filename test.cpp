#include "scale.h"

int main()
{   
    print_FromScale(0, 7, 8, 0, 0.0);
    print_FromScale(255, 7, 8, 0, 0.0);
    print_FromScale(94, 28, 28, 1, 0.0);
    print_FromScale(118112256, 28, 28, 1, 1.0);
    print_FromScale(255, 7, 8, 1, 0.0);
    print_FromScale(16711680, 23, 8, 0, 0.0);
    print_FromScale(16711680, 23, 4, 1, 3.0);
    print_FromScale(983040, 19, 4, 0, 3.0);
    print_FromScale(983040, 19, 4, 1, 3.0);
    print_FromScale(65536, 16, 1, 0, 0.1);
    print_FromScale(65536, 17, 2, 1, 0.334);
    print_FromScale(196608, 17, 2, 1, 0.7);
    
    return 0;
}
