
#include "balcao.h"

// var goblais fd
int fd_balcao, fd_utente, fd_medico;

pcomunica c, auxC;
putente u;
pmedico m, auxM;
pserver s;

void handler_sigalrm(int s, siginfo_t *i, void *v)
{
    unlink(CFF);
    unlink(FIFO_BAL);
    printf("\nEncerrando...\n");
    exit(EXIT_SUCCESS);
}

void classificador()
{ // unnamed pipes + classificador

    int FD_BC[2];
    int FD_CB[2];

    pipe(FD_BC);
    pipe(FD_CB);

    int id = fork();

    if (id > 0)
    {

        close(FD_BC[0]);
        write(FD_BC[1], c->sintomasUtente, sizeof(comunica));
        close(FD_CB[1]);
        read(FD_CB[0], c->Classificador, sizeof(comunica));
        close(FD_CB[0]);

        printf("recebeu do classificador: %s\n", c->Classificador);
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

        execl("./classificador", "classificador", NULL, NULL);
    }
    else
    {
        printf("Falha na criacao do fork()\n");

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

void sair()
{ // encerra programa e apaga fifo server
    printf("Fim do programa!\n");
    unlink(FIFO_BAL);
    unlink(CFF);
    unlink(MFF);
    exit(EXIT_SUCCESS);
}

void clear()
{ // comando limpa
    system("clear");
}

void varAmb()
{ //variaveis de ambiente

    //definicao var ambiente
    setenv("MAXCLIENTES", "5", 1);
    setenv("MAXMEDICOS", "5", 1);

    //verificacao var ambiente
    if (getenv("MAXCLIENTES") != NULL)
    {
        s->quantidadeClientes = atoi(getenv("MAXCLIENTES"));
    }
    else
    {
        fprintf(stderr, "ATENCAO! E NECESSARIO DEFINIR UMA VARIAVEL DE AMBIENTE: MAXCLIENTES!\n");
        exit(EXIT_FAILURE);
    }
    if (getenv("MAXMEDICOS") != NULL)
    {
        s->quantidadeMedicos = atoi(getenv("MAXMEDICOS"));
    }
    else
    {
        fprintf(stderr, "ATENCAO! E NECESSARIO DEFINIR UMA VARIAVEL DE AMBIENTE: MAXMEDICOS!\n");
        exit(EXIT_FAILURE);
    }

    printf("MAXMEDICOS: %d \n\n", s->quantidadeMedicos);
    printf("MAXCLIENTES: %d \n\n", s->quantidadeClientes);
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
    // else if (strcmp(cmd, "classificador") == 0)
    // {
    //     lePipes();
    // }
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

int main()
{
    c = malloc(sizeof(comunica));
    if (c == NULL)
    {
        fprintf(stderr, "\nErro [Alocacao Memoria - comunica]\n");
        free(c);
        return 0;
    }

    u = malloc(sizeof(utente));
    if (u == NULL)
    {
        fprintf(stderr, "\nErro [Alocacao Memoria - utente]\n");
        free(u);
        return 0;
    }

    m = malloc(sizeof(medico));
    if (m == NULL)
    {
        fprintf(stderr, "\nErro [Alocacao Memoria - medico]\n");
        free(m);
        return 0;
    }

    s = malloc(sizeof(server));
    if (s == NULL)
    {
        fprintf(stderr, "\nErro [Alocacao Memoria - server]\n");
        free(s);
        return 0;
    }

    char cmd[50];
    //COMUNICA comunica;

    struct sigaction sa;
    sa.sa_sigaction = handler_sigalrm;
    sa.sa_flags = SA_RESTART | SA_SIGINFO;

    struct timeval timeout;
    fd_set read_fds;
    int nfd;

    sigaction(SIGINT, &sa, NULL);

    printf("Inicializando o programa...\n");
    verificaBalcao();
    varAmb();

    printf("Criando FIFO Balcao\n");
    if (mkfifo(FIFO_BAL, 0777) == -1)
    { // criacao fifo balcao
        if (errno != EEXIST)
        {
            printf("Erro [Criacao - Fifo balcao]\n");
            exit(EXIT_FAILURE);
        }
    }

    fd_balcao = open(FIFO_BAL, O_RDWR | O_NONBLOCK);
    if (fd_balcao == -1)
    {
        printf("Erro [Abertura - Fifo balcao]\n");
        unlink(FIFO_BAL);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        //fflush(stdin);
        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(fd_balcao, &read_fds);
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        nfd = select(fd_balcao + 1, &read_fds, NULL, NULL, &timeout);
        if (nfd == 0)
        {
            printf("\nA ESPERA\n");
            fflush(stdout);
            continue;
        }
        if (nfd == -1)
        {
            perror("Erro [SELECT]\n");
            close(fd_balcao);
            unlink(FIFO_BAL);
            return EXIT_FAILURE;
        }
        if (FD_ISSET(0, &read_fds))
        {
            interface(cmd);
        }
        if (FD_ISSET(fd_balcao, &read_fds))
        {
            int numByte = read(fd_balcao, c, sizeof(comunica));
            if (numByte < sizeof(comunica))
            {
                fprintf(stderr, "Mensagem recebida incompleta %d\n", c->pid);
                continue;
            }
            fprintf(stderr, "\nMensagem recebida de %s %d\n", c->nomeUtente, c->pid);
            //fflush(stdout);
            printf("Insira utente ou medico\n");
            scanf("%s", c->msg);
            if (strcmp(c->msg, "utente") == 0)
            {
                printf("\nUtente: %s\n", c->nomeUtente);
                printf("\nSintomas recebido: %s\n", c->sintomasUtente);
                classificador(c->sintomasUtente);
                sprintf(CFF, FIFO_UTE, c->pid);
                fd_utente = open(CFF, O_RDWR | O_NONBLOCK);
                if (fd_utente == -1)
                {
                    fprintf(stderr, "\nErro [Abertura - Fifo Utente]\n");
                    unlink(CFF);
                    exit(EXIT_FAILURE);
                }
                if (write(fd_utente, c, sizeof(comunica)) == -1)
                {
                    printf("Erro [Write - Fifo Utente - Sintomas]\n");
                    //exit(EXIT_FAILURE);
                }
            }
            if (strcmp(c->msg, "medico") == 0)
            {

                
                printf("\nMedico: %s\n", c->nomeMedico);
                printf("\nEspecialidade: %s\n", c->especialidadeMedico);
                printf("\naqui:%s\n",c->Classificador);

                sprintf(MFF, FIFO_MED, c->pid);
                fd_medico = open(MFF, O_RDWR | O_NONBLOCK);
                if (fd_medico == -1)
                {
                    fprintf(stderr, "\nErro [Abertura - Fifo Medico]\n");
                    unlink(MFF);
                    exit(EXIT_FAILURE);
                }
                if (write(fd_medico, c, sizeof(comunica)) == -1)
                {
                    printf("Erro [Write - Fifo Utente]\n");
                    //exit(EXIT_FAILURE);
                }
            }
            else
            {
                continue;
            }
        }
    }
    return EXIT_SUCCESS;
}

