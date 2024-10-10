/* file:          lib_ppm.h
 * description:   PPM library
 * date:          03/2023
 * author:        Sergio Johann Filho <sergio.johann@acad.pucrs.br>
 */

struct pixel_s {
	unsigned char r, g, b;
};

struct image_s {
	int width;
	int height;
	struct pixel_s *pix;
};

int read_ppm(char *file, struct image_s *image);
int write_ppm(char *file, struct image_s *image);
int new_ppm(struct image_s *image, int width, int height);
int free_ppm(struct image_s *image);

// Adição das funções de zoom
void gerar_subpixel(struct pixel_s *p, struct pixel_s matriz[3][3]);
void zoom_imagem(struct image_s *orig, struct image_s *ampliada);