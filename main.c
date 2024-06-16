#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define RED     "\x1b[41m"  // Código ANSI para fundo vermelho
#define GREEN   "\x1b[42m"  // Código ANSI para fundo verde
#define BLUE    "\x1b[44m"  // Código ANSI para fundo azul
#define RESET   "\x1b[0m"   // Código ANSI para resetar a formatação
#define LARGURA 50
#define ALTURA  35

typedef struct {
    int x, y;
} Posicao;

void imprimirLabirinto(char labirinto[ALTURA][LARGURA], Posicao jogador) {
    system("cls"); // Limpar a tela (para Windows)
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (i == jogador.y && j == jogador.x) {
                printf(GREEN "P " RESET); // Jogador
            } else if (labirinto[i][j] == '#') {
                printf(RED "  " RESET); // Parede
            } else if (labirinto[i][j] == 'E') {
                printf(BLUE "E " RESET); // Saída
            } else {
                printf("  "); // Espaço vazio
            }
        }
        printf("\n");
    }
}

void imprimirMenu(char menu1[ALTURA][LARGURA]) {
    system("cls"); // Limpar a tela (para Windows)
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 50; j++) {
            if (menu1[i][j] == '=') {
                printf(BLUE "  " RESET); // Blue for '='
            } else if (menu1[i][j] != ' ') {
                printf(RED " %c" RESET, menu1[i][j]); // Red for menu text
            } 
        }
        printf("\n");
    }
    
}

void imprimirInstrucoes() {
    system("cls"); // Limpar a tela (para Windows)
    printf("Instruções do Jogo do Labirinto:\n");
    printf("1. Use as teclas W, A, S, D para mover o jogador (P) pelo labirinto.\n");
    printf("2. Tente chegar à saída marcada como 'E'.\n");
    printf("3. Evite as paredes marcadas como '#'.\n");
    printf("\nPressione qualquer tecla para voltar ao menu.\n");
    _getch(); // Espera por uma tecla para voltar ao menu
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    char menu[ALTURA][LARGURA] = {
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "==============================================",
        "=============================================="
    };

    
    const char *menu_items[] = {
        "===================-MENU-=====================",
        "==============1-INICIAR JOGO====================",
        "================2-INSTRUCOES==================",
        "===================3-SAIR====================="
    };

    strcpy(menu[18], menu_items[0]);
    strcpy(menu[19], menu_items[1]);
    strcpy(menu[20], menu_items[2]);
    strcpy(menu[21], menu_items[3]);





     char labirinto[ALTURA][LARGURA] = {
        "##################################################",
        "#    #                #       #          #       #",
        "# ## # ####### ####### ###### ########## ###### ##",
        "# ## #   #     #          #   #           #      #",
        "# ## ### # ######## ######### ####### ##### #### #",
        "#      # # #          #        #      # #     #  #",
        "#### # ### ########## # ####### ####### ##### ## #",
        "#    #      #         # #      #       # #    #  #",
        "# ### ####### ######### # ######## ########### ## #",
        "#      #               #       #       #     #   #",
        "##### ####### ######## ########### ####### ## ####",
        "#            #      #            #     #    #    #",
        "# ###### ### ###### #### ########## ##### ## #####",
        "#    # #       #  #   # #        #   #     #     #",
        "# #### ##### # # ## # # ####### # # ###### ##### #",
        "# #    #   # #  #  # # #     #  # # #        #   #",
        "# # ####### # # #### # # ##### ## ## ### ######## #",
        "# #      #  # #      #    #       #  #       #   #",
        "# ##### ## ### ## # ###### ######## ## ####### # #",
        "#      #  #    #  # #            #        #   # #",
        "##### #### ######  ######## #### ######### ## ### #",
        "#       #        #        #  #       #        #  #",
        "# ### ### ######## ########## ######### ####### ##",
        "# #   #      #        #          #         #    # ",
        "# # ###### # # ###### ###### ######### ###### ## #",
        "#        # #   #      #     #          #  #   # #",
        "#######  # ######## ######### ####### ###### ## #",
        "#        #   #        #  #    #           #      #",
        "###### #### ######### ## #### ##########  ### ### ",
        "#     #          #               #      #    #   #",
        "## ### #### ########### ####### ####### ### ### ##",
        "#  #    #         #     #     # #            #   #",
        "# ### #### ###### # ########### # # ######## ##  #",
        "#      #  #    #   #               #           E#",
        "##################################################"
    };

    Posicao jogador;
    char entrada;
    char opcao;
    int em_jogo = 1;
    int jogando = 0;

    while (em_jogo) {
        imprimirMenu(menu);
        char opcao = getch();

        switch (opcao) {
            case '1':
                jogador.x = 1;
                jogador.y = 1;
                jogando = 1;
                break;
            case '2':
                imprimirInstrucoes();
                break;
            case '3':
                em_jogo = 0;
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        while (jogando) {
            imprimirLabirinto(labirinto, jogador);
            entrada = _getch(); // Captura a entrada do teclado

            switch (entrada) {
                case 'w': // Move para cima
                    if (jogador.y > 0 && labirinto[jogador.y - 1][jogador.x] != '#') {
                        jogador.y--;
                    }
                    break;
                case 's': // Move para baixo
                    if (jogador.y < ALTURA - 1 && labirinto[jogador.y + 1][jogador.x] != '#') {
                        jogador.y++;
                    }
                    break;
                case 'a': // Move para esquerda
                    if (jogador.x > 0 && labirinto[jogador.y][jogador.x - 1] != '#') {
                        jogador.x--;
                    }
                    break;
                case 'd': // Move para direita
                    if (jogador.x < LARGURA - 1 && labirinto[jogador.y][jogador.x + 1] != '#') {
                        jogador.x++;
                    }
                    break;
            }

            // Verifica se o jogador chegou à saída
            if (labirinto[jogador.y][jogador.x] == 'E') {
                jogando = 0;
                printf("Parabéns! Você chegou à saída!\n");
                printf("Pressione qualquer tecla para voltar ao menu.\n");
                _getch(); // Espera por uma tecla para voltar ao menu
            }
        }
    }

    return 0;
}