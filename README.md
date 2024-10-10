# ProgSoftBasico
Cadeira de Programação de Software Básico

## O que o professor pode perguntar?

### Quantos bytes são usados nessa joça?

### Por que as funções são adicionadas no lib_ppm.h?
Pela compilação, porque o compilador, já recebe a informação correta pra compilar.


### O que é aquele "malloc", no código?
O malloc, é usado para alocar memória dinamicamente para um array 2D de estruturas struct pixel_s.
Que representa os sub-pixels gerados para cada pixel da imagem original, antes de serem alocados na imagem ampliada.
--> Professor passou isso pra nós?


### Explicação da Função principal para realizar o zoom de 3x "zoom_imagem":
Começa corrigindo as dimensões ampliadas, de acordo com o zoom, nesse caso, 3x.
Então, aloca memória proporcional ao tamanho do zoom, caso não consiga, retorna erro.

Caso consiga, segue para o próximo percorrendo cada pixel da imagem original e mapeando os sub-pixels.
Para então, copiar os sub-pixels gerados para a imagem ampliada.
Utilizando uma matriz, que também expande de acordo com o tamanho do zoom desejado.
Então, aloca cada sub-pixel, como um "novo pixel", na imagem ampliada.


### Melhor otimização que realizamos no código
É a geração de subpixels, pois evita a repetição de código e possibilita a implementação da variação do zoom desejado facilmente.