#include <stdio.h>
#include <stdlib.h>
#include "lib_ppm.h"  // Incluindo a biblioteca fornecida

// Função para gerar sub-pixels de acordo com a intensidade de cor
void gerar_subpixel(struct pixel_s *pixel, struct pixel_s matriz[3][3]) {
    int cores[3] = {pixel->r, pixel->g, pixel->b};

    // Definindo o padrão de sub-pixels para cada intensidade de cor
    // Aumento de complexidade, mas otimização de código
    for (int i = 0; i < 3; i++) {
        int cor = cores[i];
        if (cor <= 74) { // Tudo preto
            matriz[i][0] = (struct pixel_s){0, 0, 0};
            matriz[i][1] = (struct pixel_s){0, 0, 0};
            matriz[i][2] = (struct pixel_s){0, 0, 0};
        } else if (cor <= 134) { // Apenas o sub-pixel do meio é colorido
            matriz[i][0] = (struct pixel_s){0, 0, 0};
            matriz[i][1] = (struct pixel_s){i == 0 ? cor : 0, i == 1 ? cor : 0, i == 2 ? cor : 0};
            matriz[i][2] = (struct pixel_s){0, 0, 0};
        } else if (cor <= 179) { // Sub-pixels laterais são coloridos
            matriz[i][0] = (struct pixel_s){i == 0 ? cor : 0, i == 1 ? cor : 0, i == 2 ? cor : 0};
            matriz[i][1] = (struct pixel_s){0, 0, 0};
            matriz[i][2] = (struct pixel_s){i == 0 ? cor : 0, i == 1 ? cor : 0, i == 2 ? cor : 0};
        } else { // Todos os sub-pixels são coloridos
            matriz[i][0] = (struct pixel_s){i == 0 ? cor : 0, i == 1 ? cor : 0, i == 2 ? cor : 0};
            matriz[i][1] = (struct pixel_s){i == 0 ? cor : 0, i == 1 ? cor : 0, i == 2 ? cor : 0};
            matriz[i][2] = (struct pixel_s){i == 0 ? cor : 0, i == 1 ? cor : 0, i == 2 ? cor : 0};
        }
    }
}

// Função principal para realizar o zoom de 3x
void zoom_image(struct image_s *orig, struct image_s *ampliada) {
    // Corrigindo as dimensões ampliadas
    ampliada->width = orig->width * 3;
    ampliada->height = orig->height * 3;
    ampliada->pix = (struct pixel_s *)malloc(ampliada->width * ampliada->height * sizeof(struct pixel_s));

    if (!ampliada->pix) {
        printf("Erro ao alocar memória para a imagem ampliada.\n");
        exit(1);
    }

    // Percorrendo cada pixel da imagem original e mapeando sub-pixels
    for (int y = 0; y < orig->height; y++) {
        for (int x = 0; x < orig->width; x++) {
            struct pixel_s matriz[3][3];
            gerar_subpixel(&orig->pix[y * orig->width + x], matriz);

            // Copiando sub-pixels gerados para a imagem ampliada
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    // Definindo as novas coordenadas da imagem ampliada (3x maior)
                    int new_y = y * 3 + i;
                    int new_x = x * 3 + j;

                    ampliada->pix[new_y * ampliada->width + new_x] = matriz[i][j];
                }
            }
        }
    }
}

int main() {
    struct image_s imagem_original, imagem_ampliada;

    // Leitura da imagem original
    if (read_ppm("lena.ppm", &imagem_original) != 0) {
        printf("Erro ao ler a imagem original.\n");
        return 1;
    }

    // Realizar zoom de 3x
    zoom_image(&imagem_original, &imagem_ampliada);

    // Escrever a imagem ampliada
    if (write_ppm("lena_ampliada.ppm", &imagem_ampliada) != 0) {
        printf("Erro ao escrever a imagem ampliada.\n");
        return 1;
    }

    // Liberar a memória alocada
    free_ppm(&imagem_original);
    free_ppm(&imagem_ampliada);

    return 0;
}
