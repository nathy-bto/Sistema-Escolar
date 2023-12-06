#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_ALUNOS 800
#define MAX_SIZE_CURSOS 15
#define MAX_SIZE_TURMAS 30
#define MAX_SIZE_PROFESSORES 20

// Estruturas que definem cadastro de cursos
typedef struct{
    char nomeCurso[50];
    double cargaHoraria;
    Curso *proximoCurso;
}Curso;

typedef struct {
    Curso cursos[MAX_SIZE_CURSOS];
    int tamanhoListaCursos;
} cadastroCursos;

// Estruturas que definem cadastro de alunos
typedef struct {
    char nome[50];
    char matricula[10]; // permite letras, caracteres e numeros na matricula
    int idade;
    Curso cursosAluno[MAX_SIZE_CURSOS];
    int quantidadeCursos;
} Aluno;

typedef struct {
    Aluno alunos[MAX_SIZE_ALUNOS];
    int tamanhoListaAlunos;
} cadastroAlunos;

// Estrutura que define cadastro de professores
typedef struct  {
    char nome[50];
    char disciplinaLecionada[50];
    Turma *turmasMinistradas;
}Professor;

typedef struct {
    Professor professores[MAX_SIZE_PROFESSORES];
    int tamanhoListaProfessores;
} cadastroProfessores;

// Estrutura que define cadastro de turmas
typedef struct {
    char identificador;
    cadastroAlunos alunosMatriculados;
    Professor professorResponsavel;
} Turma;

typedef struct {
    Turma turmas[MAX_SIZE_TURMAS];
    int tamanhoListaTurmas;
} cadastroTurmas;

// Iniciando listas
void iniciaLista(cadastroAlunos *lista, cadastroCursos *lista2, cadastroTurmas *lista3, cadastroProfessores *lista4) {
    lista->tamanhoListaAlunos = 0;
    lista2->tamanhoListaCursos = 0;
    lista3->tamanhoListaTurmas = 0;
    lista4->tamanhoListaProfessores = 0;
}

// Inserindo alunos na lista
void insereAluno(cadastroAlunos *lista, const char *nome, const char *matricula, int idade) {
    if (lista->tamanhoListaAlunos < MAX_SIZE_ALUNOS) {
        Aluno novoAluno;

        strcpy(novoAluno.nome, nome);
        strcpy(novoAluno.matricula, matricula);
        novoAluno.idade = idade;

        lista->alunos[lista->tamanhoListaAlunos] = novoAluno;

        // Incrementando o tamanho da lista
        lista->tamanhoListaAlunos++;
    } else {
        printf("Lista cheia! O aluno não pode ser adicionado.\n");
    }
}

// Inserindo cursos na lista
void insereCurso(cadastroCursos *lista, const char *nomeCurso, double cargaHoraria) {
    if (lista->tamanhoListaCursos < MAX_SIZE_CURSOS) {
        Curso novoCurso;

        strncpy(novoCurso.nomeCurso, nomeCurso, sizeof(novoCurso.nomeCurso) - 1);
        novoCurso.cargaHoraria = cargaHoraria;

        lista->cursos[lista->tamanhoListaCursos] = novoCurso;

        // Incrementando o tamanho da lista
        lista->tamanhoListaCursos++;
    } else {
        printf("Lista cheia! O curso não pode ser adicionado na lista.\n");
    }
}

// Inserindo turmas na lista
void insereTurmas(cadastroTurmas *listaTurmas, const char identificador, cadastroAlunos alunosMatriculados) {
    if (listaTurmas->tamanhoListaTurmas < MAX_SIZE_TURMAS) {
        // Encaixar a nova turma na lista
        Turma novaTurma;

        novaTurma.identificador = identificador;
        novaTurma.alunosMatriculados = alunosMatriculados;
        novaTurma.professorResponsavel = NULL; // Inicializando como NULL

        listaTurmas->turmas[listaTurmas->tamanhoListaTurmas] = novaTurma;

        // Incrementando o tamanho da lista
        listaTurmas->tamanhoListaTurmas++;
    } else {
        printf("Lista cheia! A turma não pode ser adicionada na lista.\n");
    }
}

// Inserindo professores na lista
void insereProfessores(cadastroProfessores *listaProfessores, const char *nome, const char *disciplinasLecionadas, cadastroTurmas turmasMinistradas) {
    if (listaProfessores->tamanhoListaProfessores < MAX_SIZE_PROFESSORES) {
        Professor novoProfessor;

        strncpy(novoProfessor.nome, nome, sizeof(novoProfessor.nome) - 1);
        strncpy(novoProfessor.disciplinaLecionada, disciplinasLecionadas, sizeof(novoProfessor.disciplinaLecionada) - 1);
        novoProfessor.turmasMinistradas = turmasMinistradas;

        listaProfessores->professores[listaProfessores->tamanhoListaProfessores] = novoProfessor;

        listaProfessores->tamanhoListaProfessores++;
    } else {
        printf("Lista cheia! O professor não pode ser adicionado na lista.\n");
    }
    
}

//funcao para buscar um aluno na lista
int buscarAluno(cadastroAlunos cadastro, char nome[], char matricula[]){
    for (int i = 0; i < cadastro.tamanhoListaAlunos; i++)
    {
        if (strcmp(cadastro.alunos[i].nome, nome) == 0 || strcmp(cadastro.alunos[i].matricula, matricula) == 0)
        {
            //retorna o indice do aluno
            return i; 
        }
    }
    return -1;
}

//funcao para buscar um curso na lista
int buscarCurso(cadastroCursos cadastro2, char nomeCurso[], double cargaHoraria) {
    for (int i = 0; i < cadastro2.tamanhoListaCursos; i++) {
        if (strcmp(cadastro2.cursos[i].nomeCurso, nomeCurso) == 0 && cadastro2.cursos[i].cargaHoraria == cargaHoraria) {
            return i;
        }
    }
    return -1;
}

int buscarTurmas(cadastroTurmas cadastro3, char identificador, cadastroAlunos alunosMatriculados, cadastroProfessores professoresResponsaveis) {
    for (int i = 0; i < cadastro3.tamanhoListaTurmas; i++) {
        if (cadastro3.turmas[i].identificador == identificador &&
            cadastro3.turmas[i].alunosMatriculados == alunosMatriculados &&
            cadastro3.turmas[i].professorResponsavel == professoresResponsaveis) {
            return i;
        }
    }
    return -1;
}

//funcao para buscar professores na lista
int buscarProfessor(cadastroProfessores cadastro4, char nome[], char disciplinasLecionadas[], cadastroTurmas turmasMinistradas) {
    for (int i = 0; i < cadastro4.tamanhoListaProfessores; i++) {
        if (strcmp(cadastro4.professores[i].nome, nome) == 0 &&
            strcmp(cadastro4.professores[i].disciplinaLecionada, disciplinasLecionadas) == 0 &&
            cadastro4.professores[i].turmasMinistradas == turmasMinistradas) {
            return i;
        }
    }
    return -1;
}

// Função para matricular um aluno em um curso
void matricularAluno(cadastroAlunos *lista, cadastroCursos *lista1) {
    if (lista->tamanhoListaAlunos == 0 || lista1->tamanhoListaCursos == 0) {
        printf("Não há alunos ou cursos cadastrados. Cadastre alunos e cursos antes de matricular.\n");
        return;
    }

    int qualAluno, qualCurso;

    // Exibe a lista de alunos disponíveis
    printf("\n=== Alunos Disponíveis ===\n");
    for (int i = 0; i < lista->tamanhoListaAlunos; i++) {
        printf("%d. %s\n", i + 1, lista->alunos[i].nome);
    }

    // Solicita a escolha do aluno
    printf("Escolha o número correspondente ao aluno: ");
    scanf("%d", &qualAluno);

    if (qualAluno < 1 || qualAluno > lista->tamanhoListaAlunos) {
        printf("Número de aluno inválido.\n");
        return;
    }

    // Exibe a lista de cursos disponíveis
    printf("\n=== Cursos Disponíveis ===\n");
    for (int i = 0; i < lista1->tamanhoListaCursos; i++) {
        printf("%d. %s\n", i + 1, lista1->cursos[i].nomeCurso);
    }

    // Solicita a escolha do curso
    printf("Escolha o número correspondente ao curso: ");
    scanf("%d", &qualCurso);

    if (qualCurso < 1 || qualCurso > lista1->tamanhoListaCursos) {
        printf("Número de curso inválido.\n");
        return;
    }

    // Realiza a matrícula do aluno no curso escolhido
    lista->alunos[qualAluno - 1].cursosAluno[lista->alunos[qualAluno - 1].quantidadeCursos] = lista1->cursos[qualCurso - 1];

    lista->alunos[qualAluno - 1].quantidadeCursos++;

    printf("Aluno matriculado no curso com sucesso!\n");
}

int main() {
    // Exemplo de uso
    cadastroAlunos listaAlunos;
    cadastroCursos listaCursos;
    cadastroTurmas listaTurmas;
    cadastroProfessores listaProfessores;

    iniciaLista(&listaAlunos, &listaCursos, &listaTurmas, &listaProfessores);

    insereAluno(&listaAlunos, "Joao", "A12345", 20);
    insereAluno(&listaAlunos, "Maria", "B67890", 25);

    insereCurso(&listaCursos, "Programacao C", 40.0);
    insereCurso(&listaCursos, "Banco de Dados", 30.0);

    matricularAluno(&listaAlunos, &listaCursos);

    return 0;
}