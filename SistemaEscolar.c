#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_ALUNOS 800
#define MAX_SIZE_CURSOS 15
#define MAX_SIZE_TURMAS 30
#define MAX_SIZE_PROFESSORES 20


//estruturas que definem cadastro de alunos
typedef struct{
    char nome[50];
    char matricula[10]; //permite letras, caracteres e numeros na matricula
    int idade;
}Aluno;

typedef struct{
    Aluno alunos[MAX_SIZE_ALUNOS];
    int tamanhoListaAlunos;
}cadastroAlunos;

//estruturas que definem cadastro de cursos
typedef struct{
    char nomeCurso;
    double cargaHoraria;
}Curso;

typedef struct{
    Curso cursos[MAX_SIZE_CURSOS];
    int tamanhoListaCursos;
}cadastroCursos;

//estrutura que define cadastro de turmas
typedef struct{
    char identificador;
    cadastroAlunos alunosMatriculados;
    cadastroProfessores professoresResponsavies;
}Turma;

typedef struct{
    Turma turmas[MAX_SIZE_TURMAS];
    int tamanhoListaTurmas;
}cadastroTurmas;

//estrutura que define cadastro de professores
typedef struct {
    char nome;
    char disciplinasLecionadas;
    cadastroTurmas turmasMinistradas;
}Professor;

typedef struct{
    Professor professores[MAX_SIZE_PROFESSORES];
    int tamanhoListaProfessores;
}cadastroProfessores;


//iniciando listas
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
        strcpy(lista->alunos[lista->tamanhoListaAlunos].nome, nome);
        strcpy(lista->alunos[lista->tamanhoListaAlunos].matricula, matricula);
        lista->alunos[lista->tamanhoListaAlunos].idade = idade;
        //inccrementando o tamanho da lista
        lista->tamanhoListaAlunos++;
    }else{
        printf("lista cheia! o aluno não pode ser adicionado");
    }
}

//inserindo cursos na lista
void insereCurso(cadastroCursos *listaCurso, const char nomeCurso, double cargaHoraria){
    if (listaCurso->tamanhoListaCursos < MAX_SIZE_CURSOS)
    {
        strcpy(listaCurso->cursos[listaCurso->tamanhoListaCursos].nomeCurso, nomeCurso);
        listaCurso->cursos[listaCurso->tamanhoListaCursos].cargaHoraria, cargaHoraria;
        listaCurso->tamanhoListaCursos++;
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
        novoProfessor.disciplinasLecionadas = disciplinasLecionadas;
        novoProfessor.turmasMinistradas = turmasMinistradas;

        listaProfessores->professores[listaProfessores->tamanhoListaProfessores] = novoProfessor;
        listaProfessores->tamanhoListaProfessores++;
    }else{
        printf("lista cheia! o professor não pode ser adicionado na lista");
    }
    
}



//funcao para buscar um aluno na lista
int buscarAluno(cadastroAlunos cadastro, char nome[], char matricula[]){
    for (int i = 0; i < cadastro.tamanhoListaAlunos; i++)
    {
        if (strcmp(cadastro.alunos[i].nome, nome == 0 || strcmp(cadastro.alunos[i].matricula == 0)))
        {
            //retorna o indice do aluno
            return i; 
        }
    }
    return printf("aluno não encontrado");
}

//funcao para buscar um curso na lista
int buscarCurso(cadastroCursos cadastro2, char nomeCurso[], double cargaHoraria){
    for (int i = 0; i < cadastro2.tamanhoListaCursos; i++)
    {
        if (strcmp(cadastro2.cursos[i].nomeCurso == 0 || strcmp(cadastro2.cursos[i].cargaHoraria, cargaHoraria == 0)))
        {
            return i;
        }
        
    }
    return printf("curso não encontrado");
}

//funcao para buscar turmas na lista
int buscarTurmas(cadastroTurmas cadastro3, char identificador, cadastroAlunos alunosMatriculados, cadastroProfessores professoresResponsavies){
    for (int i = 0; i < cadastro3.tamanhoListaTurmas; i++)
    {
        if (strcmp(cadastro3.turmas[i].identificador, identificador == 0 || strcmp(cadastro3.turmas[i].alunosMatriculados, alunosMatriculados == 0))){
            return i;
        }
    }
    return printf("turma não encontrada");
}

//funcao para buscar professores na lista
    int buscarProfessor(cadastroProfessores cadastro4, char nome[],char disciplinasLecionadas, cadastroTurmas turmasMinistradas){
        for (int i = 0; i < cadastro4.tamanhoListaProfessores; i++)
        {
            if (strcmp(cadastro4.professores[i].nome, nome == 0 || strcmp(cadastro4.professores[i].disciplinasLecionadas, disciplinasLecionadas == 0 || cadastro4.professores[i].turmasMinistradas, turmasMinistradas == 0)))
            {
                return i;
            }
        }
        return printf("professor não encontrado");
    }