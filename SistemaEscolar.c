#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_ALUNOS 100
#define MAX_SIZE_CURSOS 50
#define MAX_SIZE_TURMAS 20
#define MAX_SIZE_PROFESSORES 30

// Estrutura para armazenar informações de curso
typedef struct{
    char nomeCurso[50];
    int cargaHoraria;
} Curso;

// Estrutura para armazenar informações de aluno
typedef struct{
    char nome[50];
    int matricula;
    int idade;
    Curso cursosAluno[MAX_SIZE_CURSOS];
    int quantidadeCursos;
} Aluno;

// Alunos
typedef struct{
    Aluno alunos[MAX_SIZE_ALUNOS];
    int tamanhoListaAlunos;
} listaAlunos;

// Estrutura para armazenar informações de turma
typedef struct{
    int identificador;
    listaAlunos alunosMatriculados[MAX_SIZE_ALUNOS];
    int quantidadeAlunos;
} Turma;

// Turmas
typedef struct{
    Turma turmas[MAX_SIZE_TURMAS];
    int tamanhoListaTurmas;
} listaTurmas;

// Estrutura para armazenar informações de professor
typedef struct{
    char nome[50];
    char disciplinaLecionada[50];
    listaTurmas turmasMinistradas[MAX_SIZE_TURMAS];
    int quantidadeTurmas;
} Professor;



// Cursos
typedef struct{
    Curso cursos[MAX_SIZE_CURSOS];
    int tamanhoListaCursos;
} listaCursos;

// Professores
typedef struct{
    Professor professores[MAX_SIZE_PROFESSORES];
    int tamanhoListaProfessores;
} listaProfessores;

/// Função para inicializar as listas
void inicializarListas(listaAlunos *alunos, listaCursos *cursos, listaTurmas *turmas, listaProfessores *professores){
    // Inicializa lista de alunos
    alunos->tamanhoListaAlunos = 0;

    // Inicializa lista de cursos
    cursos->tamanhoListaCursos = 0;

    // Inicializa lista de turmas
    turmas->tamanhoListaTurmas = 0;

    // Inicializa lista de professores
    professores->tamanhoListaProfessores = 0;
}


// Função para cadastrar um novo aluno
void cadastrarAluno(listaAlunos *listaAluno, const char *nome, int idade)
{

    if (listaAluno->tamanhoListaAlunos < MAX_SIZE_ALUNOS)
    {
        // Captura de informações do novo aluno
        Aluno novoAluno;

        strcpy(novoAluno.nome, nome);

        novoAluno.idade = idade;

        // Adiciona o novo aluno ao array de alunos
        listaAluno->alunos[listaAluno->tamanhoListaAlunos] = novoAluno;

        // Atualiza o número de alunos
        listaAluno->tamanhoListaAlunos++;
        // Criando a matrícula do aluno
        novoAluno.matricula = listaAluno->tamanhoListaAlunos;

        printf("Aluno cadastrado com sucesso!\n");
    }
    else
    {
        printf("Lista cheia! O aluno não pode ser adicionado.\n");
    }
}

// Função para cadastrar um novo curso
void cadastrarCurso(listaCursos *listaCurso, const char *nomeCurso, int cargaHoraria)
{
    if (listaCurso->tamanhoListaCursos < MAX_SIZE_CURSOS)
    {
        // Captura de informações do novo curso
        Curso novoCurso;

        strncpy(novoCurso.nomeCurso, nomeCurso, sizeof(novoCurso.nomeCurso) - 1);
        novoCurso.cargaHoraria = cargaHoraria;

        // Adiciona o novo curso ao array de cursos
        listaCurso->cursos[listaCurso->tamanhoListaCursos] = novoCurso;

        // Atualiza o número de cursos
        listaCurso->tamanhoListaCursos++;

        printf("Curso cadastrado com sucesso!\n");
    }
    else
    {
        printf("Lista cheia! O curso não pode ser adicionado na lista.\n");
    }
}

// Função para cadastrar um professor
void cadastrarProfessor(listaProfessores *professores, const char *nome[], const char *disciplinasLecionada[])
{
    if (professores->tamanhoListaProfessores < MAX_SIZE_PROFESSORES)
    {
        Professor novoProfessor;

        strncpy(novoProfessor.nome, nome, sizeof(novoProfessor.nome) - 1);
        strncpy(novoProfessor.disciplinaLecionada, disciplinasLecionada, sizeof(novoProfessor.disciplinaLecionada) - 1);

        // Adiciona o novo professor à lista
        professores->professores[professores->tamanhoListaProfessores] = novoProfessor;
        // Atualiza o número de professores
        professores->tamanhoListaProfessores++;

        printf("Professor cadastrado com sucesso!\n");
    }
    else
    {
        printf("Lista cheia! O professor não pode ser adicionado na lista.\n");
    }
}

// Função para matricular um aluno em um curso
void matricularAluno(listaAlunos *listaAluno, listaCursos *listaCurso)
{
    if (listaAluno->tamanhoListaAlunos == 0 || listaCurso->tamanhoListaCursos == 0)
    {
        printf("Não há alunos ou cursos cadastrados. Cadastre alunos e cursos antes de matricular.\n");
        return;
    }

    int matriculaAluno, idCurso;

    // Exibe a lista de alunos disponíveis
    printf("\nAlunos Disponíveis: \n");
    for (int i = 0; i < listaAluno->tamanhoListaAlunos; i++)
    {
        printf("%d. %s\n", i + 1, listaAluno->alunos[i].nome);
    }

    // Solicita a escolha do aluno
    printf("Escolha o número correspondente ao aluno: ");
    scanf("%d", &matriculaAluno);

    if (matriculaAluno < 1 || matriculaAluno > listaAluno->tamanhoListaAlunos)
    {
        printf("Número de aluno inválido.\n");
        return;
    }

    // Exibe a lista de cursos disponíveis
    printf("\nCursos Disponíveis: \n");
    for (int i = 0; i < listaCurso->tamanhoListaCursos; i++)
    {
        printf("%d. %s\n", i + 1, listaCurso->cursos[i].nomeCurso);
    }

    // Solicita a escolha do curso
    printf("Escolha o número correspondente ao curso: ");
    scanf("%d", &idCurso);

    if (idCurso < 1 || idCurso > listaCurso->tamanhoListaCursos)
    {
        printf("Número de curso inválido.\n");
        return;
    }

    // Realiza a matrícula do aluno no curso escolhido
    listaAluno->alunos[matriculaAluno - 1].cursosAluno[listaAluno->alunos[matriculaAluno - 1].quantidadeCursos] = listaCurso->cursos[idCurso - 1];

    printf("Aluno matriculado no curso com sucesso!\n");
}

// Função para cadastrar uma nova turma
void cadastrarTurma(listaTurmas *listaTurma)
{
    if (listaTurma->tamanhoListaTurmas < MAX_SIZE_TURMAS)
    {
        // Captura de informações da nova turma
        Turma novaTurma;

        novaTurma.identificador = listaTurma->tamanhoListaTurmas;

        // Adiciona a nova turma ao array de turmas
        listaTurma->turmas[listaTurma->tamanhoListaTurmas] = novaTurma;

        // Atualiza o número de turmas
        listaTurma->tamanhoListaTurmas++;

        printf("Turma de identificador %d cadastrada com sucesso!\n", novaTurma.identificador);
    }
    else
    {
        printf("Lista cheia! A turma não pode ser adicionada na lista.\n");
    }
}

// Função para designar um professor para uma turma
void designarProfessor(listaProfessores *listaProfessor, listaTurmas *listaTurma)
{
    if (listaProfessor->tamanhoListaProfessores == 0 || listaTurma->tamanhoListaTurmas == 0)
    {
        printf("Não há professores ou turmas cadastrados. Cadastre professores e turmas antes de designar.\n");
        return;
    }

    int idProfessor, idTurma;

    // Exibe a lista de professores disponíveis
    printf("\nProfessores Disponíveis: \n");
    for (int i = 0; i < listaProfessor->tamanhoListaProfessores; i++)
    {
        printf("%d. %s - %s\n", i + 1, listaProfessor->professores[i].nome, listaProfessor->professores[i].disciplinaLecionada);
    }

    // Solicita a escolha do professor
    printf("Escolha o número correspondente ao professor: ");
    scanf("%d", &idProfessor);

    if (idProfessor < 1 || idProfessor > listaProfessor->tamanhoListaProfessores)
    {
        printf("Número de professor inválido.\n");
        return;
    }

    // Exibe a lista de turmas disponíveis
    printf("\nTurmas Disponíveis: \n");
    for (int i = 0; i < listaTurma->tamanhoListaTurmas; i++)
    {
        printf("%d. Turma %d\n", i + 1, listaTurma->turmas[i].identificador);
    }

    // Solicita a escolha da turma
    printf("Escolha o número correspondente à turma: ");
    scanf("%d", &idTurma);

    if (idTurma < 1 || idTurma > listaTurma->tamanhoListaTurmas)
    {
        printf("Número de turma inválido.\n");
        return;
    }

    listaProfessor->professores[idProfessor-1].quantidadeTurmas++;
    int quantidadeTurmas = listaProfessor->professores[idProfessor-1].quantidadeTurmas;
    // Realiza a designação do professor para a turma escolhida
    listaProfessor->professores[idProfessor - 1].turmasMinistradas[quantidadeTurmas] = listaTurma->turmas[idTurma - 1];

    printf("Professor designado para a turma com sucesso!\n");
}

// Função para listar alunos por turma
void listarAlunosPorTurma(listaTurmas *listaTurma, listaAlunos *listaAluno)
{
    if (listaAluno->tamanhoListaAlunos == 0 || listaTurma->tamanhoListaTurmas == 0)
    {
        printf("Não há alunos ou turmas cadastrados. Cadastre alunos e turmas antes de listar.\n");
        return;
    }

    int idTurma;

    // Exibe a lista de turmas disponíveis
    printf("\nTurmas Disponíveis: \n");
    for (int i = 0; i < listaTurma->tamanhoListaTurmas; i++)
    {
        printf("%d. Turma %d\n", i + 1, listaTurma->turmas[i].identificador);
    }

    // Solicita a escolha da turma
    printf("Escolha o número correspondente à turma: ");
    scanf("%d", &idTurma);

    if (idTurma < 1 || idTurma > listaTurma->tamanhoListaTurmas)
    {
        printf("Número de turma inválido.\n");
        return;
    }

    // Exibe a lista de alunos da turma escolhida
    printf("\nAlunos da Turma %d: \n", listaTurma->turmas[idTurma - 1].identificador);
    for (int i = 0; i < MAX_SIZE_ALUNOS; i++)
    {
        if (listaTurma->turmas[idTurma - 1].alunosMatriculados[i] != NULL)
        {
            printf("%d. %s\n", i + 1, listaAluno->alunos[i].nome);
        }
    }
}

// Função para listar cursos disponíveis
void listarCursosDisponiveis(listaCursos *listaCurso)
{
    if (listaCurso->tamanhoListaCursos == 0)
    {
        printf("Não há cursos cadastrados. Cadastre cursos antes de listar.\n");
        return;
    }

    printf("\nCursos Disponíveis:\n");
    for (int i = 0; i < listaCurso->tamanhoListaCursos; i++)
    {
        printf("%d. %s - Carga horária: %d horas\n", i + 1, listaCurso->cursos[i].nomeCurso, listaCurso->cursos[i].cargaHoraria);
    }
}

// Função para exibir professores com suas turmas
void exibirProfessoresComTurmas(listaProfessores *listaProfessor, listaTurmas *listaTurma)
{
    if (listaProfessor->tamanhoListaProfessores == 0 || listaTurma->tamanhoListaTurmas == 0)
    {
        printf("Não há professores ou turmas cadastrados. Cadastre professores e turmas antes de exibir.\n");
        return;
    }

    printf("\n=== Professores com Suas Turmas ===\n");

    for (int i = 0; i < listaProfessor->tamanhoListaProfessores; i++)
    {
        printf("%d. Professor: %s - Disciplina: %s\n", i + 1, listaProfessor->professores[i].nome, listaProfessor->professores[i].disciplinaLecionada);

        printf("   Turmas associadas:\n");

        int contadorTurmas = 0;
        for (int j = 0; j < listaTurma->tamanhoListaTurmas; j++)
        {
            if (listaTurma->turmas[j].professorResponsavel == i)
            {
                printf("   - Turma %d\n", listaTurma->turmas[j].identificador);
                contadorTurmas++;
            }
        }

        if (contadorTurmas == 0)
        {
            printf("   Nenhuma turma associada.\n");
        }

        printf("\n");
    }
}

int main()
{
    // Declarando as variaveis de teste
    listaAlunos listaAluno;
    listaCursos listaCurso;
    listaProfessores listaProfessor;
    listaTurmas listaTurma;
    // Inicializando as listas
    inicializarListas(&listaAluno, &listaCurso, &listaProfessor, &listaTurma);
    // Menu principal com as opções do sistema
    int opcao;
    do
    {
        printf("\nSelecione uma das opções abaixo:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Cadastrar Curso\n");
        printf("3. Cadastrar Professor");
        printf("4. Cadastrar Turma\n");
        printf("3. Matricular Aluno em Curso\n");
        printf("5. Designar Professor para Turma\n");
        printf("6. Listar Alunos por Turma\n");
        printf("7. Listar Cursos Disponíveis\n");
        printf("8. Exibir Professores com Turmas\n");
        printf("0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            char nomeAluno[50];
            int matriculaAluno, idadeAluno;

            printf("Digite o nome do aluno: ");
            scanf("%s", &nomeAluno);
            cadastrarAluno(&listaAluno, nomeAluno, idadeAluno);
            break;
        case 2:
            char nomeCurso[50];
            int cargaHoraria;

            printf("Digite o nome do Curso: \n");
            scanf("%s", &nomeCurso);

            printf("Digite o nome do aluno: \n");
            scanf("%d", &cargaHoraria);

            cadastrarCurso(&listaCurso, nomeCurso, cargaHoraria);
            break;

        case 3:
            char nomeProfessor[50];
            char disciplinaLecionada[50];

            printf("Digite o nome do professor:\n");
            scanf("%s", &nomeProfessor);

            printf("Digite a disciplina lecionada pelo professor:\n");
            scanf("%s", &disciplinaLecionada);

            cadastrarProfessor(&listaProfessor, nomeProfessor, disciplinaLecionada);
            break;
        case 4:
            cadastrarTurma(&listaTurma);
            break;
        case 5:
            matricularAluno(&listaAluno, &listaCurso);
            break;

        case 6:
            designarProfessor(&listaProfessor, &listaTurma);
            break;
        case 7:
            listarAlunosPorTurma(&listaTurma, &listaAluno);
            break;
        case 8:
            listarCursosDisponiveis(&listaCurso);
            break;
        case 9:
            exibirProfessoresComTurmas(&listaProfessor, &listaTurma);
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
