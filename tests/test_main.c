#include <stdio.h>
#include <stdlib.h> // Include necessary header for malloc
#include "CUnit/Basic.h"

// Define struct pixel_s and struct image_s if not already defined
struct pixel_s {
    int r;
    int g;
    int b;
};

struct image_s {
    int width;
    int height;
    struct pixel_s *pix;
};

// Function prototypes
void gerar_subpixel(struct pixel_s *pixel, struct pixel_s matriz[3][3]);
void zoom_image(struct image_s *orig, struct image_s *ampliada);
void test_case_1();
void test_case_2();
void test_gerar_subpixel();
void test_zoom_image();

// Test case for gerar_subpixel function
void test_gerar_subpixel() {
    struct pixel_s pixel = {100, 150, 200};
    struct pixel_s matriz[3][3];
    gerar_subpixel(&pixel, matriz);

    // Verifying the red component
    CU_ASSERT(matriz[0][0].r == 0);
    CU_ASSERT(matriz[0][1].r == 100);
    CU_ASSERT(matriz[0][2].r == 0);

    // Verifying the green component
    CU_ASSERT(matriz[1][0].g == 150);
    CU_ASSERT(matriz[1][1].g == 0);
    CU_ASSERT(matriz[1][2].g == 150);

    // Verifying the blue component
    CU_ASSERT(matriz[2][0].b == 200);
    CU_ASSERT(matriz[2][1].b == 200);
    CU_ASSERT(matriz[2][2].b == 200);
}

// Test case for zoom_image function
void test_zoom_image() {
    struct image_s orig, ampliada;
    orig.width = 2;
    orig.height = 2;
    orig.pix = (struct pixel_s *)malloc(orig.width * orig.height * sizeof(struct pixel_s));

    // Initializing original image pixels
    orig.pix[0] = (struct pixel_s){100, 150, 200};
    orig.pix[1] = (struct pixel_s){50, 100, 150};
    orig.pix[2] = (struct pixel_s){200, 50, 100};
    orig.pix[3] = (struct pixel_s){150, 200, 50};

    zoom_image(&orig, &ampliada);

    // Verifying the dimensions of the zoomed image
    CU_ASSERT(ampliada.width == 6);
    CU_ASSERT(ampliada.height == 6);

    // Verifying some pixels of the zoomed image
    CU_ASSERT(ampliada.pix[0].r == 0);
    CU_ASSERT(ampliada.pix[1].r == 100);
    CU_ASSERT(ampliada.pix[2].r == 0);
    CU_ASSERT(ampliada.pix[6].g == 150);
    CU_ASSERT(ampliada.pix[7].g == 0);
    CU_ASSERT(ampliada.pix[8].g == 150);
    CU_ASSERT(ampliada.pix[12].b == 200);
    CU_ASSERT(ampliada.pix[13].b == 200);
    CU_ASSERT(ampliada.pix[14].b == 200);

    free(orig.pix);
    free(ampliada.pix);
}

// Add test cases to the suite
int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Test Suite", NULL, NULL);
    CU_add_test(suite, "Test Case 1", test_case_1);
    CU_add_test(suite, "Test Case 2", test_case_2);
    CU_add_test(suite, "Test gerar_subpixel", test_gerar_subpixel);
    CU_add_test(suite, "Test zoom_image", test_zoom_image);

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}