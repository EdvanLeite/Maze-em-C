#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>//Necessário para usar a função System("cls")
#include <conio.h>//Necessário para scanear sem ENTER
#include <string.h>
#include <unistd.h> // Necessário para usar a função sleep

#define RESET   "\x1b[0m"     // Resetar formatação (ANSI)
#define RED     "\x1b[41m"    // Fundo vermelho (ANSI)
#define GREEN   "\x1b[42m"    // Fundo verde (ANSI)
#define YELLOW  "\x1b[43m"    // Fundo amarelo (ANSI)
#define BLUE    "\x1b[44m"    // Fundo azul (ANSI)
#define MAGENTA "\x1b[45m"    // Fundo magenta (ANSI)
#define CYAN    "\x1b[46m"    // Fundo ciano (ANSI)
#define WHITE   "\x1b[47m"    // Fundo branco (ANSI)



=======
#include <stdlib.h>
#include <termios.h>
#include <unistd.h> //inserção de bibliotecas para substituir a biblioteca conio 
#include <string.h>
#include <locale.h>
>>>>>>> 42237dc8eee7a3066c1a290020ae18c0f3153d63

#define LARGURA 50
#define ALTURA  35

typedef struct {
    int x, y;
} Posicao;

void imprimirLabirinto(char labirinto[ALTURA][LARGURA], Posicao jogador) {
    system("cls"); // Limpar a tela 
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (i == jogador.y && j == jogador.x) {
                printf(GREEN "P " RESET); // Jogador
            } else if (labirinto[i][j] == '#') {
                printf(RED "  " RESET); // Parede
            } else if (labirinto[i][j] == 'E') {
                printf(BLUE "  " RESET); // Saída
            } else {
                printf("  "); // Espaço vazio
            }
        }
        printf("\n");
    }
}

void imprimirMenu(char menu1[ALTURA][LARGURA]) {
<<<<<<< HEAD
    system("cls"); // Limpar a tela (para Windows)
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
=======
    system("cls"); // Limpar a tela 
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 50; j++) {
>>>>>>> 42237dc8eee7a3066c1a290020ae18c0f3153d63
            if (menu1[i][j] == '=') {
                printf(BLUE "  " RESET); // Blue for '='
            } else if (menu1[i][j] != ' ') {
                printf(RED " %c" RESET, menu1[i][j]); // Red for menu text
            } 
        }
        printf("\n");
    }

}

<<<<<<< HEAD
void imprimirInstrucoes(char instrucao[ALTURA][LARGURA]) {
    system("cls"); // Limpar a tela (para Windows)
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (instrucao[i][j] == '=') {
                printf(CYAN "  " RESET); // Fundo azul para '='
            } else if (instrucao[i][j] == ' ') {
                printf(MAGENTA "  " RESET); // Fundo magenta para espaços
            }else  {
                printf(MAGENTA "%c" RESET, instrucao[i][j]); // Fundo magenta para espaços
            }
        }
        printf("\n");
    }
    _getch();
=======
void imprimirInstrucoes() {
    system("cls"); // Limpar a tela 
    printf("Instruções do Jogo do Labirinto:\n");
    printf("1. Use as teclas W, A, S, D para mover o jogador (P) pelo labirinto.\n");
    printf("2. Tente chegar à saída marcada como 'E'.\n");
    printf("3. Evite as paredes marcadas como '#'.\n");
    printf("\nPressione qualquer tecla para voltar ao menu.\n");
    getchar(); // Espera por uma tecla para voltar ao menu  //_getch por getchar
}

// Função para capturar a entrada do teclado sem esperar o Enter
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
>>>>>>> 42237dc8eee7a3066c1a290020ae18c0f3153d63
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

    char *intrucoes_itens[] = {
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

    strcpy(instrucoes[16], intrucoes_itens[0]);
    strcpy(instrucoes[17], intrucoes_itens[1]);
    strcpy(instrucoes[18], intrucoes_itens[2]);
    strcpy(instrucoes[19], intrucoes_itens[3]);
    strcpy(instrucoes[20], intrucoes_itens[4]);


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

   

     char labirinto3[ALTURA][LARGURA] = {
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

<<<<<<< HEAD
        while (jogando==1) {
            imprimirLabirinto(labirinto1, jogador);
            entrada = _getch(); // Captura a entrada do teclado
=======
        while (jogando) {
            imprimirLabirinto(labirinto, jogador);
            entrada = getch(); // Captura a entrada do teclado
>>>>>>> 42237dc8eee7a3066c1a290020ae18c0f3153d63

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
                jogando ++;
                printf("Parabéns! Você chegou à saída!\n");
<<<<<<< HEAD
                printf("Vamos para o Segundo Labirinto\n");
                 sleep(3);
                 jogador.x = 1;
                 jogador.y = 1;
                 while (jogando==2) {
                    imprimirLabirinto(labirinto3, jogador);
                    entrada = _getch(); // Captura a entrada do teclado

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
                        printf("Parabéns! Você chegou à saída!\n");
                        printf("Pressione qualquer tecla para voltar ao menu.\n");
                        _getch(); // Espera por uma tecla para voltar ao menu
                    }
                }
            }

                
=======
                printf("Pressione qualquer tecla para voltar ao menu.\n");
                getchar(); // Espera por uma tecla para voltar ao menu
>>>>>>> 42237dc8eee7a3066c1a290020ae18c0f3153d63
            }
        }


       

    return 0;
}