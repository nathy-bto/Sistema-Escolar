# Sistema-Escolar
Projeto da materia Estrutura de dados

1. Objetivo:
Desenvolver um sistema escolar em linguagem C utilizando uma lista estática para gerenciar alunos, turmas, professores, cursos e matrículas.
Funcionalidades Principais:

2. Cadastro de Alunos:
Permitir o cadastro de alunos com informações como matrícula, nome, idade, etc. 
Manter uma lista dinâmica estática de alunos com tamanho máximo pré-definido.

3. Cadastro de Cursos:
Permitir o registro de cursos com detalhes como nome do curso, carga horária, etc.
Manter uma lista dinâmica estática de cursos com tamanho máximo pré-definido.

4. Matrícula em Cursos:
Permitir a matrícula de um aluno em um ou mais cursos.
Estabelecer essa relação entre aluno e curso através da lista dinâmica estática.

5. Cadastro de Turmas:
Possibilitar o cadastro de turmas com informações como identificador, disciplina, etc.
Manter uma lista dinâmica estática de turmas com tamanho máximo pré-definido.

6. Designação de Professores:
Permitir a atribuição de professores a turmas específicas.
Relacionar professores e turmas através da lista dinâmica estática.


Listagens:
Mostrar a lista de alunos por turma.
Listar cursos disponíveis.
Exibir os professores com suas turmas.

Estruturas de Dados:
--------------------
Aluno:

    Matrícula;
    Nome;
    Lista dinâmica estática de cursos matriculados;
Curso:

    Nome do curso;
    Carga horária;
    Próximo curso na lista;

Turma:

    Identificador;
    Lista dinâmica estática de alunos matriculados;
    Professor responsável;

Professor:

    Nome;
    Disciplina lecionada;
    Lista dinâmica estática de turmas ministradas;

Orientações Gerais:
-------------------
Implementar a lista dinâmica estática para cada entidade (alunos, cursos, turmas, professores) utilizando arrays.
Definir um tamanho máximo para cada lista estática.

Utilizar mecanismos de controle de posição livre/ocupada para a manipulação dos elementos nas listas estáticas.
Criar funções separadas para operações como inserção, remoção, busca, etc.
Documentar o código de forma clara, incluindo comentários explicativos.

Observações:
------------
Este projeto visa a aplicação dos conceitos de listas dinâmicas estáticas em um contexto prático de um sistema escolar. A correta implementação das estruturas estáticas e a manipulação dos elementos são aspectos cruciais a serem considerados.

