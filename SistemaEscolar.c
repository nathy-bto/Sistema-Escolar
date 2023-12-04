#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_ALUNOS 800
#define MAX_SIZE_CURSOS 15
#define MAX_SIZE_TURMAS 30
#define MAX_SIZE_PROFESSORES 20


//estrutura que define o campo cadastro de alunos
typedef struct{
    char nome;
    char matricula; //permite letras, caracteres e numeros na matricula
    int idade;
    int tamanhoListaAlunos;
}cadastroAlunos;

//estrutura que define cadastro de cursos
typedef struct{
    char nomeCurso;
    double cargaHoraria;
    int tamanhoListaCursos;
}cadastroCurso;

//estrutura que define cadastro de turmas
typedef struct{
    char identificador;
    cadastroAlunos alunosMatriculados;
    //professores responsaveis;
    int tamanhoListaTurmas;
}cadastroTurmas;

//estrutura que define cadastro de professores
typedef struct {
    char nome;
    char disciplinasLecionadas;
    cadastroTurmas turmasMinistradas;
    int tamanhoListaProfessores;
}cadastroProfessores;


//iniciando listas
void iniciaLista(cadastroAlunos *lista, cadastroCurso *lista2, cadastroTurmas *lista3, cadastroProfessores *lista4){
    lista->tamanhoListaAlunos = 0; //a lista deve iniciar com tamanho atual zero
    lista2->tamanhoListaCursos = 0;
    lista3->tamanhoListaTurmas = 0;
    lista4->tamanhoListaProfessores = 0;
}

//inserindo alunos na lista
void insereAluno(cadastroAlunos *lista, char nome, char matricula, int idade){
    if (lista->tamanhoListaAlunos < MAX_SIZE_ALUNOS)
    {
        lista->nome = nome;
        lista->matricula = matricula;
        lista->idade = idade;
        //falta implementar tamanho
    }else{
        printf("lista cheia! o aluno não pode ser adicionado");
    }
}

//inserindo cursos na lista
void insereCurso(cadastroCurso *listaCurso, char nomeCurso, double cargaHoraria){
    if (listaCurso->tamanhoListaCursos < MAX_SIZE_CURSOS)
    {
        listaCurso->nomeCurso = nomeCurso;
        listaCurso->cargaHoraria = cargaHoraria;
        //falta implementar tamanho
    }else{
        printf("lista cheia! o curso não pode ser adicionado na lista");
    }
}

//inserindo turmas na lista
void insereTurmas(cadastroTurmas *listaTurmas, char identificador, cadastroAlunos alunosMatriculados){
    if (listaTurmas->tamanhoListaTurmas < MAX_SIZE_TURMAS)
    {
        listaTurmas->identificador = identificador;
        listaTurmas->alunosMatriculados = alunosMatriculados;
        //falta implementar tamanho
    }else{
        printf("lista cheia! a turma não pode ser adicionada na lista");
    }
}

//inserindo professores na lista
void insereProfessores(cadastroProfessores *listaProfessores, char nome, cadastroTurmas disciplinasLecionadas, cadastroTurmas turmasMinistradas){
    if (listaProfessores->tamanhoListaProfessores < MAX_SIZE_PROFESSORES)
    {
        listaProfessores->nome = nome;
        listaProfessores->disciplinasLecionadas = disciplinasLecionadas;
        listaProfessores->turmasMinistradas = turmasMinistradas;
        //falta implementar tamanho
    }else{
        printf("lista cheia!, o professor não pode ser adicionado");
    }
    
}