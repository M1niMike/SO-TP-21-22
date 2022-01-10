#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include "balcao.h"
#include "utente.h"
#include "medico.h"

// var goblais para o classificador (envia e recebe)
char recebe[50]; 
char envia[50];




BALCAO balcao;// rever logica disso






void lePipes()
{ // unnamed pipes + classificador

    int FD_BC[2];
    int FD_CB[2];

    pipe(FD_BC);
    pipe(FD_CB);

    int id = fork();

    if (id > 0)
    {

        close(FD_BC[0]);
        write(FD_BC[1], recebe, 50);
        close(FD_CB[1]);
        read(FD_CB[0], envia, 50);
        close(FD_CB[0]);

        printf("recebeu do classificador: %s\n", envia);
    }

    else if (id == 0)
    {
        close(STDIN_FILENO);

        dup(FD_BC[0]); // para duplicar o file descriptor, ligando-o ao primeiro fd vazio

        close(FD_BC[0]);
        close(FD_BC[1]);
        close(STDOUT_FILENO);

        dup(FD_CB[1]);

        close(FD_CB[1]);
        close(FD_CB[0]);

        execl("./classificador", "classificador", NULL);
    }
    else
    {
        printf("Falha na criacao do fork()");

        exit(EXIT_FAILURE);
    }
}





void help()
{ //printfs de aux

    printf("---------------------\n");
    printf("COMANDOS\n");
    printf("[utentes] - lista os utentes em fila de espera indicando qual a especialidade e qual a prioridade, e também os utentes atualmente a serem atendidos, em que especialidade e por qual especialista.\n");
    printf("[especialistas] - indica a lista de especialistas conhecidos e estado atual (a espera, a atender o utente X)\n");
    printf("[delut <utente>] - remove o utente em espera X, informando-o atraves do seu programa cliente (que depois encerra). Esse utente sai do sistema. Valido apenas para utentes que ainda nao comecaram a ser atendidos.\n");
    printf("[delesp <especialista>] - remove o especialista X, informando-o atraves do seu programa medico (que depois encerra). Valido apenas para especialistas que nao estejam a atender nenhum utente no momento.\n");
    printf("[freq N] - passa a apresentar a ocupacao das filas de espera de N em N segundos.\n");
    printf("[encerra] - termina o sistema, avisando os clientes, os medicos e o classificador.\n");
    printf("[help] - mostra os comandos disponiveis no sistema.\n");
    printf("---------------------\n");
}




void TestVar(){
       
    BALCAO balcao;

    printf("MAXMEDICOS: %d\n", balcao.quantidadeMedicos);
    printf("MAXCLIENTES: %d\n", balcao.quantidadeClientes);
}




void sair()
{ // encerra programa e apaga fifo server
    printf("Fim do programa!\n");
    unlink(FIFO_BAL);
    exit(EXIT_SUCCESS);
}




void clear()
{ // comando limpa
    system("clear");
}







void varAmb()
{ //variaveis de ambiente

    BALCAO balcao;

    //definicao var ambiente
    setenv("MAXCLIENTES", "5", 1);
    setenv("MAXMEDICOS", "5", 1);

    //verificacao var ambiente
    if (getenv("MAXCLIENTES") != NULL)
    {
        balcao.quantidadeClientes = atoi(getenv("MAXCLIENTES"));
    }
    else
    {
        fprintf(stderr, "ATENCAO! E NECESSARIO DEFINIR UMA VARIAVEL DE AMBIENTE: MAXCLIENTES!\n");
        exit(EXIT_FAILURE);
    }
    if (getenv("MAXMEDICOS") != NULL)
    {
        balcao.quantidadeMedicos = atoi(getenv("MAXMEDICOS"));
    }
    else
    {
        fprintf(stderr, "ATENCAO! E NECESSARIO DEFINIR UMA VARIAVEL DE AMBIENTE: MAXMEDICOS!\n");
        exit(EXIT_FAILURE);
    }

    printf("MAXMEDICOS: %d \n\n", balcao.quantidadeMedicos);
    printf("MAXCLIENTES: %d \n\n", balcao.quantidadeClientes);

}






char *interface(char cmd[50])
{ //interface do programa

    printf("Comando: ");
    fflush(stdout);
    scanf("%s", cmd);

    if (strcmp(cmd, "help") == 0)
    {
        help();
    }
    else if (strcmp(cmd, "sair") == 0)
    {
        sair();
    }
    else if (strcmp(cmd, "utentes") == 0)
    {
        printf("\nA ser implementado\n");
    }
    else if (strcmp(cmd, "especialistas") == 0)
    {
        printf("\nA ser implementado\n");
    }
    else if (strcmp(cmd, "delut") == 0)
    {
        printf("\nA ser implementado\n");
    }
    else if (strcmp(cmd, "delesp") == 0)
    {
        printf("\nA ser implementado\n");
    }
    else if (strcmp(cmd, "freq") == 0)
    {
        printf("\nA ser implementado\n");
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        clear();
    }
    else if (strcmp(cmd, "classificador") == 0)
    {
        lePipes();
    }
    else if (strcmp(cmd, "ambiente") == 0)
    {
        TestVar();
    }
    else
    {
        printf("\nAviso [Comando invalido!]\n");
    }

    return cmd;
}





void verificaBalcao()
{ //verifica se já existe um balcao ativo

    if (access(FIFO_BAL, F_OK) == 0)
    {
        printf("Aviso [Balcao ativo]\n");
        exit(EXIT_FAILURE);
    }
}






void alocaMemoria(medico **pmedico, utente **putente)// arrumar isto Gonzo
{

    *pmedico = malloc(sizeof(medico));
    if (*pmedico == NULL)
    {
        printf("\nerro na alocacao de memoria\n");
        free(*pmedico);
    }

    *putente = malloc(sizeof(utente));
    if (*putente == NULL)
    {
        printf("\nerro na alocacao de memoria\n");
        free(*putente);
    }
}







void criaFifo()
{   
    printf("Criando FIFO Balcao\n");
     if (mkfifo(FIFO_BAL, 0777) == -1)
    { // criacao fifo balcao
        if (errno != EEXIST)
        {
            printf("Erro [Criacao - Fifo balcao]\n");
            exit(EXIT_FAILURE);
        }
    }

}








int main()
{
    char cmd[50];
    int fifo;
   
    printf("Inicializando o programa...\n");
    verificaBalcao();
    criaFifo();
    
    printf("A espera do Utente...\n");
    fifo = open(FIFO_BAL, O_RDONLY);

    if(fifo == -1)
    {
        printf("Erro [Abertura - Fifo balcao]\n");
        exit(EXIT_FAILURE);
    }


    medico *pmedico;
    utente *putente;

    // pmedico = malloc(sizeof(medico));
    // if(pmedico == NULL){
    //     printf("\nerro na alocacao de memoria\n");
    //     free(pmedico);
    //     return 0;
    // }

    // putente = malloc(sizeof(utente));
    // if(putente == NULL){
    //     printf("\nerro na alocacao de memoria\n");
    //     free(putente);
    //     return 0;

    // }

    alocaMemoria(&pmedico, &putente);
    varAmb();

    if (read(fifo, recebe, 50) == -1)
    {
        printf("Erro [Read - Fifo balcao - Sintomas]\n");
        exit(EXIT_FAILURE);
    }

    printf("Sintomas recebido: %s\n", recebe);

    close(fifo);
    while (1)
    {
        interface(cmd);
    }

    return 0;
}
