#include <stdio.h> // base do código
#include <time.h>//Necessario para o timer
#include <sys/time.h>//Necessario para o timer
#include <stdlib.h>//Necessário para usar a função System("cls")
#include <conio.h>//Necessário para scanear sem ENTER
#include <string.h> //Necessário para 
#include <unistd.h> // Necessário para usar a função sleep
#include <locale.h> // Necessário para printar os acentos 

#define RESET   "\x1b[0m"     // Resetar formatação (ANSI)
#define RED     "\x1b[41m"    // Fundo vermelho (ANSI)
#define GREEN   "\x1b[42m"    // Fundo verde (ANSI)
#define YELLOW  "\x1b[43m"    // Fundo amarelo (ANSI)
#define BLUE    "\x1b[44m"    // Fundo azul (ANSI)
#define MAGENTA "\x1b[45m"    // Fundo magenta (ANSI)
#define CYAN    "\x1b[46m"    // Fundo ciano (ANSI)
#define WHITE   "\x1b[47m"    // Fundo branco (ANSI)


#define LARGURA 70
#define ALTURA  40

typedef struct {
    int x, y;
    char nick[13];
} Posicao;

void start_timer(struct timeval *start_time) { //Captura o tempo inicial.
    gettimeofday(start_time, NULL);
}

void stop_timer(struct timeval *end_time) {//Captura o tempo final.
    gettimeofday(end_time, NULL);
}

double elapsed_time(struct timeval start_time, struct timeval end_time) { //Calcula o tempo decorrido entre o tempo inicial e o tempo final em segundos e microsegundos.
    long seconds = end_time.tv_sec - start_time.tv_sec;
    long useconds = end_time.tv_usec - start_time.tv_usec;
    double elapsed = seconds + useconds / 1000000.0;
    return elapsed;
}
void imprimirFinal(char fim[ALTURA][LARGURA], double tempo, Posicao Jogador) {
    system("cls"); // Use "clear" para Unix/Linux
    int minutes = (int) tempo / 60;
    int seconds = (int) tempo % 60;
    int k = 0, y = 0;
    char time_str[5];
    sprintf(time_str, "%02d:%02d", minutes, seconds);
    int a = strlen(Jogador.nick);

    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (fim[i][j] == '=') {
                printf(GREEN "  " RESET);
            } else if (fim[i][j] == '~') {
                printf(BLUE "  " RESET);
            }  else if (fim[i][j] == '#') {
                printf(BLUE " %c" RESET, time_str[k]);
                k++;
            } else if (fim[i][j] == '*') {
                if (y < a ) {
                    printf(BLUE " %c" RESET, Jogador.nick[y]);
                    y++;
                } else {
                    printf(GREEN "  " RESET); 
                }
            } else if (fim[i][j] == '-') {
                printf(RED "  " RESET); 
            } else {
                printf(BLUE " %c" RESET, fim[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    char final[ALTURA][LARGURA]= {
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~========================PARABENS==*****============================~",
        "~===================================================================~",
        "~================O ULTIMO LABIRINTO FOI FINALIZADO==================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===============================TIMER===============================~",
        "~===================================================================~",
        "~==============================-------==============================~",
        "~==============================-#####-==============================~",
        "~==============================-------==============================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~===================================================================~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
    };
    struct timeval start_time, end_time;
    double elapsed;
    Posicao jogador;
    char entrada;    
    char opcao;
    int em_jogo = 1;
    int jogando = 0;
    

    while (em_jogo) {
        
        char opcao = getch();

        switch (opcao) {
            case '1':
               
                fgets(jogador.nick,50,stdin);
                jogador.x = 1;
                jogador.y = 1;
                jogando = 1;
                start_timer(&start_time);
                stop_timer(&end_time);
                system("cls");
                elapsed = elapsed_time(start_time, end_time);
                imprimirFinal(final, elapsed, jogador);
                sleep(6);
                break;
                }}}