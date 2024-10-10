#include <stdio.h>
#include <assert.h>
#include "main.c"  // Include the main.c file to access the gerar_subpixel function


void test_gerar_subpixel() {
    struct pixel_s test_pixel = {100, 150, 200};
    struct pixel_s test_matriz[3][3];

    gerar_subpixel(&test_pixel, test_matriz);

    // Add assertions to check the output of the function for different input values
    assert(test_matriz[0][0].r == 0 && test_matriz[0][0].g == 0 && test_matriz[0][0].b == 0);
    assert(test_matriz[0][1].r == 0 && test_matriz[0][1].g == 100 && test_matriz[0][1].b == 0);
    // Add more assertions for other cases
}


int main() {
    test_gerar_subpixel();
    printf("All tests passed successfully!\n");
    return 0;
}