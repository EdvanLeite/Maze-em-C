#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <locale.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[41m"
#define GREEN   "\x1b[42m"
#define YELLOW  "\x1b[43m"
#define BLUE    "\x1b[44m"
#define MAGENTA "\x1b[45m"
#define CYAN    "\x1b[46m"
#define WHITE   "\x1b[47m"

#define LARGURA 50
#define ALTURA  35

typedef struct {
    int x, y;
} Posicao;

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void imprimirLabirinto(char labirinto[ALTURA][LARGURA], Posicao jogador) {
    system("clear");
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (i == jogador.y && j == jogador.x) {
                printf(GREEN "P " RESET);
            } else if (labirinto[i][j] == '#') {
                printf(RED "  " RESET);
            } else if (labirinto[i][j] == 'E') {
                printf(BLUE "  " RESET);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void imprimirMenu(char menu1[ALTURA][LARGURA]) {
    system("clear");
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (menu1[i][j] == '=') {
                printf(BLUE "  " RESET);
            } else if (menu1[i][j] != ' ') {
                printf(RED " %c" RESET, menu1[i][j]);
            }
        }
        printf("\n");
    }
}

void imprimirInstrucoes(char instrucao[ALTURA][LARGURA]) {
    system("clear");
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (instrucao[i][j] == '=') {
                printf(CYAN "  " RESET);
            } else if (instrucao[i][j] == ' ') {
                printf(MAGENTA "  " RESET);
            } else {
                printf(MAGENTA "%c" RESET, instrucao[i][j]);
            }
        }
        printf("\n");
    }
    getch();
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

    char instrucoes[ALTURA][LARGURA] = {
        "                                                ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        " ============================================== ",
        "                                                "
    };

    char *menu_items[] = {
        "===================-MENU-=====================",
        "==============1-INICIAR JOGO====================",
        "================2-INSTRUCOES==================",
        "===================3-SAIR====================="
    };

    char *instrucoes_itens[] = {
        " ======================Instruções do Jogo do Labirinto:========================================= ",
        " =============1. Use as teclas W, A, S, D para mover o jogador (P) pelo labirinto.",
        " ================2. Tente chegar à saída marcada como 'E'.",
        " ==========3. Evite as paredes marcadas .===",
        " ===========\nPressione qualquer tecla para voltar ao menu.",
    };

    strcpy(menu[18], menu_items[0]);
    strcpy(menu[19], menu_items[1]);
    strcpy(menu[20], menu_items[2]);
    strcpy(menu[21], menu_items[3]);

    strcpy(instrucoes[16], instrucoes_itens[0]);
    strcpy(instrucoes[17], instrucoes_itens[1]);
    strcpy(instrucoes[18], instrucoes_itens[2]);
    strcpy(instrucoes[19], instrucoes_itens[3]);
    strcpy(instrucoes[20], instrucoes_itens[4]);

    char labirinto1[ALTURA][LARGURA] = {
        "##################################################",
        "#                             #          #       #",
        "# ## # ####### ####### ###### ########## ###### ##",
        "# ## #         #          #   #           #      #",
        "# ## ### # ######## ####  ### ####### ##### #### #",
        "#      # #            #          #    # #     #  #",
        "#### # ###  ######### # #######  ###### ##### ## #",
        "#    #                # #              # #    #  #",
        "# ########### ######### # ######## ########### ###",
        "#      #                               #     #   #",
        "##### ####### ######## ########### ####### ## ####",
        "#          #        #            #     #    #    #",
        "# ###### ### ###### #### ##########  #### ## #####",
        "#    # #       #  #   # #        #   #     #     #",
        "# #### ######  ####   # ####### ###  ##### ##### #",
        "# #    #   ##         #        # #          #   ##",
        "# # #######  ######  ## ##### ## ## ###  #########",
        "# #      #           #    #       #  #       #   #",
        "# #####  # ### #     ##### ########### ## #### ###",
        "#        ##    #  ####           #               #",
        "##### #### ######  ######## #### ############ ####",
        "#       #        #        #  #    ####        #  #",
        "# ### ############ ########## #########    ####  #",
        "# #   #      #        #                    #    ##",
        "# # #######  # ###### ###### ######### ##  ##    #",
        "#        ##    #      #     #          #         #",
        "#######  #   ###### ######### ####### #####  #####",
        "#        # ###        #  #    #           ####   #",
        "###### ##   ######### ## #### ##########    #  ###",
        "#                #               #   ####   ##   #",
        "## ### #### ########### ####### ####### ###  ## ##",
        "#  #    #         #     #     # #            #   #",
        "# ### #### ###### # ############    #######  ##  #",
        "#      #       #                  ##           E##",
        "##################################################"
    };

    char labirinto2[ALTURA][LARGURA] = {
        "##################################################",
        "#    #                #       #          #       #",
        "# ## # ####### ####### ###### ########## ###### ##",
        "# ## #   #     #          #   #           #      #",
        "# ## ### # ######## ######### ####### ##### #### #",
        "#      # # #          #        #      # #     #  #",
        "#### # ### ########## # ####### ####### ##### ## #",
        "#    #      #         # #      #       # #    #  #",
        "# ### ####### ######### # ######## ########### ###",
        "#      #               #       #       #     #   #",
        "##### ####### ######## ########### ####### ## ####",
        "#          #        #            #     #    #    #",
        "# ###### ### ###### #### ########## ##### ## #####",
        "#    # #       #  #   # #        #   #     #     #",
        "# #### ######  ####   # ####### ###  ##### ##### #",
        "# #    #   ##         #        # #          #   ##",
        "# # #######  ######  ## ##### ## ## ###  #########",
        "# #      #           #    #       #  #       #   #",
        "# #####  # ### #     ##### ########### ## #### ###",
        "#        ##    #  ####           #               #",
        "##### #### ######  ######## #### ############ ####",
        "#       #        #        #  #    ####        #  #",
        "# ### ############ ########## #########    ####  #",
        "# #   #      #        #                    #    ##",
        "# # #######  # ###### ###### ######### ##  ##    #",
        "#        ##    #      #     #          #         #",
        "#######  #   ###### ######### ####### #####  #####",
        "#        # ###        #  #    #           ####   #",
        "###### ##   ######### ## #### ##########    #  ###",
        "#                #               #   ####   ##   #",
        "## ### #### ########### ####### ####### ###  ## ##",
        "#  #    #         #     #     # #            #   #",
        "# ### #### ###### # ############    #######  ##  #",
        "#      #       #                  ##           E##",
        "##################################################"
    };

    char labirinto3[ALTURA][LARGURA] = {
        "##################################################",
        "#                             #          #       #",
        "# ## # ####### ####### ###### ########## ###### ##",
        "# ## #         #          #   #           #      #",
        "# ## ### # ######## ####  ### ####### ##### #### #",
        "#      # #            #          #    # #     #  #",
        "#### # ###  ######### # #######  ###### ##### ## #",
        "#    #                # #              # #    #  #",
        "# ########### ######### # ######## ########### ###",
        "#      #                               #     #   #",
        "##### ####### ######## ########### ####### ## ####",
        "#          #        #            #     #    #    #",
        "# ###### ### ###### #### ##########  #### ## #####",
        "#    # #       #  #   # #        #   #     #     #",
        "# #### ######  ####   # ####### ###  ##### ##### #",
        "# #    #   ##         #        # #          #   ##",
        "# # #######  ######  ## ##### ## ## ###  #########",
        "# #      #           #    #       #  #       #   #",
        "# #####  # ### #     ##### ########### ## #### ###",
        "#        ##    #  ####           #               #",
        "##### #### ######  ######## #### ############ ####",
        "#       #        #        #  #    ####        #  #",
        "# ### ############ ########## #########    ####  #",
        "# #   #      #        #                    #    ##",
        "# # #######  # ###### ###### ######### ##  ##    #",
        "#        ##    #      #     #          #         #",
        "#######  #   ###### ######### ####### #####  #####",
        "#        # ###        #  #    #           ####   #",
        "###### ##   ######### ## #### ##########    #  ###",
        "#                #               #   ####   ##   #",
        "## ### #### ########### ####### ####### ###  ## ##",
        "#  #    #         #     #     # #            #   #",
        "# ### #### ###### # ############    #######  ##  #",
        "#      #       #                  ##           E##",
        "##################################################"
    };

    Posicao jogador;
    char entrada;
    char opcao;
    int em_jogo = 1;
    int jogando = 0;

    while (em_jogo) {
        imprimirMenu(menu);
        opcao = getch();

        switch (opcao) {
            case '1':
                jogador.x = 1;
                jogador.y = 1;
                jogando = 1;
                break;
            case '2':
                imprimirInstrucoes(instrucoes);
                break;
            case '3':
                em_jogo = 0;
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        while (jogando == 1) {
            imprimirLabirinto(labirinto1, jogador);
            entrada = getch(); // Captura a entrada do teclado

            switch (entrada) {
                case 'w': // Move para cima
                    if (jogador.y > 0 && labirinto1[jogador.y - 1][jogador.x] != '#') {
                        jogador.y--;
                    }
                    break;
                case 's': // Move para baixo
                    if (jogador.y < ALTURA - 1 && labirinto1[jogador.y + 1][jogador.x] != '#') {
                        jogador.y++;
                    }
                    break;
                case 'a': // Move para esquerda
                    if (jogador.x > 0 && labirinto1[jogador.y][jogador.x - 1] != '#') {
                        jogador.x--;
                    }
                    break;
                case 'd': // Move para direita
                    if (jogador.x < LARGURA - 1 && labirinto1[jogador.y][jogador.x + 1] != '#') {
                        jogador.x++;
                    }
                    break;
            }

            // Verifica se o jogador chegou à saída
            if (labirinto1[jogador.y][jogador.x] == 'E') {
                jogando++;
                printf("Parabéns! Você chegou à saída!\n");
                printf("Vamos para o Segundo Labirinto\n");
                sleep(3);
                jogador.x = 1;
                jogador.y = 1;
                while (jogando == 2) {
                    imprimirLabirinto(labirinto2, jogador);
                    entrada = getch(); // Captura a entrada do teclado

                    switch (entrada) {
                        case 'w': // Move para cima
                            if (jogador.y > 0 && labirinto2[jogador.y - 1][jogador.x] != '#') {
                                jogador.y--;
                            }
                            break;
                        case 's': // Move para baixo
                            if (jogador.y < ALTURA - 1 && labirinto2[jogador.y + 1][jogador.x] != '#') {
                                jogador.y++;
                            }
                            break;
                        case 'a': // Move para esquerda
                            if (jogador.x > 0 && labirinto2[jogador.y][jogador.x - 1] != '#') {
                                jogador.x--;
                            }
                            break;
                        case 'd': // Move para direita
                            if (jogador.x < LARGURA - 1 && labirinto2[jogador.y][jogador.x + 1] != '#') {
                                jogador.x++;
                            }
                            break;
                    }

                    // Verifica se o jogador chegou à saída
                    if (labirinto2[jogador.y][jogador.x] == 'E') {
                        jogando++;
                        printf("Parabéns! Você chegou à saída!\n");
                        printf("Vamos para o Terceiro Labirinto\n");
                        sleep(3);
                        jogador.x = 1;
                        jogador.y = 1;
                        while (jogando == 3) {
                            imprimirLabirinto(labirinto3, jogador);
                            entrada = getch(); // Captura a entrada do teclado

                            switch (entrada) {
                                case 'w': // Move para cima
                                    if (jogador.y > 0 && labirinto3[jogador.y - 1][jogador.x] != '#') {
                                        jogador.y--;
                                    }
                                    break;
                                case 's': // Move para baixo
                                    if (jogador.y < ALTURA - 1 && labirinto3[jogador.y + 1][jogador.x] != '#') {
                                        jogador.y++;
                                    }
                                    break;
                                case 'a': // Move para esquerda
                                    if (jogador.x > 0 && labirinto3[jogador.y][jogador.x - 1] != '#') {
                                        jogador.x--;
                                    }
                                    break;
                                case 'd': // Move para direita
                                    if (jogador.x < LARGURA - 1 && labirinto3[jogador.y][jogador.x + 1] != '#') {
                                        jogador.x++;
                                    }
                                    break;
                            }

                            // Verifica se o jogador chegou à saída
                            if (labirinto3[jogador.y][jogador.x] == 'E') {
                                jogando = 0;
                                printf("Parabéns! Você completou todos os labirintos!\n");
                                sleep(3);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

