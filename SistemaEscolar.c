#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_ALUNOS 800
#define MAX_SIZE_CURSOS 15
#define MAX_SIZE_TURMAS 30
#define MAX_SIZE_PROFESSORES 20

// Estruturas que definem cadastro de cursos
typedef struct{
    char nomeCurso;
    double cargaHoraria;
    Curso *proximoCurso;
}Curso;

typedef struct{
    Curso cursos[MAX_SIZE_CURSOS];
    int tamanhoListaCursos;
}cadastroCursos;

// Estruturas que definem cadastro de alunos
typedef struct{
    char nome[50];
    char matricula[10]; //permite letras, caracteres e numeros na matricula
    int idade;
    cadastroCursos cursosAluno[MAX_SIZE_CURSOS];
    int quantidadeCursos;
}Aluno;

typedef struct{
    Aluno alunos[MAX_SIZE_ALUNOS];
    int tamanhoListaAlunos;
}cadastroAlunos;

// Estrutura que define cadastro de turmas

typedef struct{
    char identificador;
    cadastroAlunos alunosMatriculados;
    Professor professorResponsavel;
}Turma;

typedef struct{
    Turma turmas[MAX_SIZE_TURMAS];
    int tamanhoListaTurmas;
}cadastroTurmas;

// Estrutura que define cadastro de professores
typedef struct {
    char nome;
    char disciplinaLecionada;
    cadastroTurmas turmasMinistradas;
}Professor;

typedef struct{
    Professor professores[MAX_SIZE_PROFESSORES];
    int tamanhoListaProfessores;
}cadastroProfessores;


// Iniciando listas
void iniciaLista(cadastroAlunos *lista, cadastroCursos *lista2, cadastroTurmas *lista3, cadastroProfessores *lista4){
    lista->tamanhoListaAlunos = 0; //a lista deve iniciar com tamanho atual zero
    lista2->tamanhoListaCursos = 0;
    lista3->tamanhoListaTurmas = 0;
    lista4->tamanhoListaProfessores = 0;
}

//inserindo alunos na lista
void insereAluno(cadastroAlunos *lista, const char *nome, const char *matricula, int idade){
    if (lista->tamanhoListaAlunos < MAX_SIZE_ALUNOS)
    {
        Aluno novoAluno;

        strcpy(novoAluno.nome, nome);
        strcpy(novoAluno.matricula, matricula);
        novoAluno.idade = idade;

        lista->alunos[lista->tamanhoListaAlunos] = novoAluno;

        //incrementando o tamanho da lista
        lista->tamanhoListaAlunos++;
    }else{
        printf("lista cheia! o aluno não pode ser adicionado");
    }
}

//inserindo cursos na lista
void insereCurso(cadastroCursos *lista, const char nomeCurso, double cargaHoraria){
    if (lista->tamanhoListaCursos < MAX_SIZE_CURSOS)
    {
        Curso novoCurso;

        strcpy(novoCurso.nomeCurso, nomeCurso);
        novoCurso.cargaHoraria, cargaHoraria;

        lista->cursos[lista->tamanhoListaCursos] = novoCurso;

        //incrementando o tamanho da lista
        lista->tamanhoListaCursos++;
    }else{
        printf("lista cheia! o curso não pode ser adicionado na lista");
    }
}

//inserindo turmas na lista
void insereTurmas(cadastroTurmas *listaTurmas, const char identificador, cadastroAlunos alunosMatriculados){
    if (listaTurmas->tamanhoListaTurmas < MAX_SIZE_TURMAS)
    {
        //encaixar a nova turma na lista
        Turma novaTurma;

        novaTurma.identificador = identificador;
        novaTurma.alunosMatriculados = alunosMatriculados;

        listaTurmas->turmas[listaTurmas->tamanhoListaTurmas] = novaTurma;

        //incrementando o tamanho da lista
        listaTurmas->tamanhoListaTurmas++;
    }else{
        printf("lista cheia! a turma não pode ser adicionada na lista");
    }
}

//inserindo professores na lista
void insereProfessores(cadastroProfessores *listaProfessores, char nome, cadastroTurmas disciplinasLecionadas, cadastroTurmas turmasMinistradas){
    if (listaProfessores->tamanhoListaProfessores < MAX_SIZE_PROFESSORES)
    {
        Professor novoProfessor;

        novoProfessor.nome = nome;
        strcpy(novoProfessor.disciplinaLecionada, disciplinasLecionadas);
        novoProfessor.turmasMinistradas = turmasMinistradas;

        listaProfessores->professores[listaProfessores->tamanhoListaProfessores] = novoProfessor;
       
        listaProfessores->tamanhoListaProfessores++;
    }else{
        printf("lista cheia! o professor não pode ser adicionado na lista");
    }
    
}

<<<<<<< HEAD


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
int buscarCurso(cadastroCursos cadastro2, char nomeCurso[], double cargaHoraria){
    for (int i = 0; i < cadastro2.tamanhoListaCursos; i++)
    {
        if (strcmp(cadastro2.cursos[i].nomeCurso) == 0 || strcmp(cadastro2.cursos[i].cargaHoraria, cargaHoraria) == 0)
        {
            return i;
        }
        
    }
    return -1;
}

//funcao para buscar turmas na lista
int buscarTurmas(cadastroTurmas cadastro3, char identificador, cadastroAlunos alunosMatriculados, cadastroProfessores professoresResponsaveis){
    for (int i = 0; i < cadastro3.tamanhoListaTurmas; i++)
    {
        if (cadastro3.turmas[i].identificador == identificador &&
            strcmp(cadastro3.turmas[i].alunosMatriculados, alunosMatriculados) == 0 &&
            strcmp(cadastro3.turmas[i].professoresResponsaveis, professoresResponsaveis) == 0){
            return i;
        }
    }
    return -1;
}

//funcao para buscar professores na lista
    int buscarProfessor(cadastroProfessores cadastro4, char nome[],char disciplinasLecionadas, cadastroTurmas turmasMinistradas){
        for (int i = 0; i < cadastro4.tamanhoListaProfessores; i++)
        {
            if (strcmp(cadastro4.professores[i].nome, nome) == 0 &&
                strcmp(cadastro4.professores[i].disciplinasLecionadas, disciplinasLecionadas) ==  &&
                strcmp(cadastro4.professores[i].turmasMinistradas, turmasMinistradas) == 0)
            {
                return i;
            }
        }
        return printf("professor não encontrado");
    }
=======
// Função para matricular um aluno em um curso
void matricularAluno(cadastroAlunos *lista, cadastroCursos *lista1) {
    if ( lista->tamanhoListaAlunos == 0 || lista1->tamanhoListaCursos == 0) {
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
    lista->alunos[qualAluno - 1].cursosAluno[lista->alunos[qualAluno - 1].quantidadeCursos].cursos[lista->alunos[qualAluno-1]->quantidadeCursos] = lista1->cursos[qualCurso - 1];
   
    lista->alunos[qualAluno - 1].quantidadeCursos++;

    printf("Aluno matriculado no curso com sucesso!\n");
}


>>>>>>> 59562f2ccea162f3f50746111e52fd438d77f4b3
