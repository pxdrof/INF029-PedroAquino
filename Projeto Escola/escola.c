#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tamanhoAluno 3

/* Nota - Não permitir trocar a matrícula por uma já existente durante a atualização na opção 3 */

/* variaáveis geral - lista vazia */
#define listaVazia - 1

/* Variáveis usadas somente para retorno - cadastro aluno */
#define cadastroInvalido -2
#define listaCheia -3
#define cadastropreexistente -4
#define cadastroRealizado -5

/* variáveis usadas somente para retorno - atualizar aluno */
#define atualizacaoPreexistente -6
#define atualizacaoRealizada -7
#define atualizacaoInvalido -8

/* variáveis usadas somente para retorno - excluir aluno */
#define exclusaoRealizada -9
#define exclusaoInvalida -10


typedef struct {
  int matricula;
  /* int cpf;
  int dataNascimento;
  char nome[50];*/
  char sexo; 
  bool ativo;
} Aluno;

/* Protótipos das Funções */
int menuPrincipal();
int menuAluno();
int cadastroAluno();
void listarAluno();
int atualizarAluno();
int excluirAluno();


int main(void){

  int sair = 0;
  int opcaoMenu;
  
  /* variáveis para o módulo aluno */
  Aluno listaAluno[tamanhoAluno];
  int icontAluno = 0;
  int opcaoAluno;
  
  do
  {
    opcaoMenu = menuPrincipal();

    switch(opcaoMenu)
    {

      case 0:
      {
        sair = 1;
        printf("\nSaindo do programa...\n");
        break;
      }

      case 1:
      {
        do 
        {
          
          opcaoAluno = menuAluno();
          
          switch(opcaoAluno)
          {
            case 0:
            {
              printf("\nVoltando ao menu principal...\n");
              break;
            }

            case 1:
            {

              int retorno = cadastroAluno(listaAluno, icontAluno);

              if (retorno == cadastroInvalido){
                printf("Matrícula inválida!\n");
              } else if (retorno == listaCheia){
                printf("Lista de alunos cheia!\n");
              } else if (retorno == cadastropreexistente){
                printf("Matrícula já cadastrada!\n");
              } else if (retorno == cadastroRealizado){
                printf("Cadastro realizado com sucesso!\n");
                icontAluno++;
              } else if (retorno == listaVazia){
                printf("\nAinda não há alunos cadastrados\n");
              }
              
              break;
            }

            case 2: 
            {
              listarAluno(listaAluno, icontAluno);
              break;
            }

            case 3:
            {
              int retorno = atualizarAluno(listaAluno, icontAluno);

              if (retorno == listaVazia){
                printf("\nAinda não há alunos cadastrados\n");
              } else if (retorno == atualizacaoPreexistente){
                printf("Matrícula não pode ser atualizada pois já existe pelo menos uma com essa numeração na lista!\n");
              } else if (retorno == atualizacaoRealizada){
                printf("Atualização realizada com sucesso!\n");
              } else if (retorno == atualizacaoInvalido){
                printf("Matrícula inválida!\n");
              }

              break;
            }

            case 4:
            {

              int retorno = excluirAluno(listaAluno, icontAluno);

              if (retorno == listaVazia){
                printf("\nAinda não há alunos cadastrados\n");
              } else if (retorno == exclusaoRealizada){
                printf("Exclusão realizada com sucesso!\n");
                icontAluno--;
              } else if (retorno == exclusaoInvalida){
                printf("Exclusão não pode ser efetuada!\n");
              }
              
              break;
            }

            default:
            {
              printf("Opção inválida!\n");
              break;
            }
          }
        } while(opcaoAluno != 0);
        
        break;
      }

      case 2:
      {
        printf("\nMódulo Professor\n");
        break;
      }

      case 3:
      {
        printf("\nMódulo Disciplina\n");
        break;
      }

      default:
      {
        printf("\nOpção inválida!\n");
      }
    }

  } while (sair == 0);
}

/* Funções - menu */

int menuPrincipal(int opcaoMenu){
  
  printf("\n**** Projeto escola ****\n");
  printf("0° -> Sair\n");
  printf("1° -> Aluno\n");
  printf("2° -> Professor\n");
  printf("3° -> Disciplina\n");
  printf("Opção escolhida -> ");
  scanf("%d", &opcaoMenu);

  return opcaoMenu;
}

int menuAluno(int opcaoAluno){
  
  printf("\n**** Módulo Aluno ****\n");
  printf("0° -> Voltar ao menu\n");
  printf("1° -> Cadastrar aluno\n");
  printf("2° -> Listar aluno\n");
  printf("3° -> Atualizar aluno\n");
  printf("4° -> Excluir aluno\n");
  printf("Opção escolhida -> ");
  scanf("%d", &opcaoAluno);

  return opcaoAluno;
}

/* ********* Inicio das funções módulo aluno ********* */
int cadastroAluno(Aluno listaAluno[], int icontAluno){

  int matriculaAluno;
  bool alunoEncontrado = false;
  
  if (icontAluno == tamanhoAluno){
    return listaCheia;
  } else {
    printf("\nCadastrar aluno\n");
    printf("Insira a matrícula do aluno -> ");
    scanf("%d", &matriculaAluno);

    if (matriculaAluno < 0){
      return cadastroInvalido;
    } else {
      for (int icont = 0; icont < icontAluno; icont++){
        if (listaAluno[icont].matricula == matriculaAluno){
          alunoEncontrado = true;
        }
      }

      if (alunoEncontrado != false){
        return cadastropreexistente;
      } else {
        listaAluno[icontAluno].matricula = matriculaAluno;
        listaAluno[icontAluno].ativo = true; /* aluno está ativo no sistema */
        return cadastroRealizado;
      }
    }
  }
}

void listarAluno(Aluno listaAluno[], int icontAluno){

  if (icontAluno > 0){
    printf("\nListar aluno\n");
    for (int icont = 0; icont < icontAluno; icont++){
      if (listaAluno[icont].ativo == true){
        printf("Matrícula: %d\n", listaAluno[icont].matricula);
      }
    }

  } else {
    printf("\nAinda não há alunos cadastrados!\n");
  }
  
}

int atualizarAluno(Aluno listaAluno[], int icontAluno){

  bool novaMatriculaPreexistente = false;
  int matriculaAluno;
  int novaMatriculaAluno;
  
  if (icontAluno > 0){
    printf("\nAtualizar aluno\n");
    printf("Insira a matrícula atual do aluno que deseja atualizar -> ");
    scanf("%d", &matriculaAluno);

    for (int icont = 0; icont < icontAluno; icont++){
      if (listaAluno[icont].matricula == matriculaAluno){
        printf("Digite a nova matrícula do aluno ->  ");
        scanf("%d", &novaMatriculaAluno);

        if (novaMatriculaAluno < 0){
          return atualizacaoInvalido;
          break;
        }
      }
    }

    for (int jcont = 0; jcont < icontAluno; jcont++){
      if (listaAluno[jcont].matricula == novaMatriculaAluno){
        novaMatriculaPreexistente = true;
      }
  
      if (novaMatriculaPreexistente != false){
        return atualizacaoPreexistente;
      } else {
        listaAluno[jcont].matricula = novaMatriculaAluno;
        return atualizacaoRealizada;
      }
    }
    
  } else {
    return listaVazia;
  }
}

int excluirAluno(Aluno listaAluno[], int icontAluno){

  int matriculaAluno;
  bool alunoEncontrado = false;
  
  if (icontAluno > 0){
    printf("\nExcluir aluno\n");
    printf("Insira a matrícula do aluno -> ");
    scanf("%d", &matriculaAluno);


    if (matriculaAluno < 0){
      return exclusaoInvalida;
    } else {
      for (int icont = 0; icont < tamanhoAluno; icont++){
        if (listaAluno[icont].matricula == matriculaAluno){
          listaAluno[icont].ativo = false; /* Aluno desativado do sistema */
          alunoEncontrado = true; /* A matrícula do aluno foi encontrada */
          /* exclusão lógica */
          for (int jcont = icont; jcont < tamanhoAluno - 1; jcont++){ 
            /* Shift - mover as posições do vetor para uma casa anterior */
            listaAluno[jcont].matricula = listaAluno[jcont + 1].matricula;
            /* listaAluno[jcont].cpf = listaAluno[jcont + 1].cpf;
            listaAluno[jcont].dataNascimento = listaAluno[jcont + 1].dataNascimento;
            listaAluno[jcont].nome = listaAluno[jcont + 1].nome; */
            listaAluno[jcont].sexo = listaAluno[jcont + 1].sexo; 
            listaAluno[jcont].ativo = listaAluno[jcont + 1].ativo; 

            return exclusaoRealizada;
          }
          break;
        } else {
          listaAluno[icont].ativo = true; /* Aluno ativo no sistema */
        }
      }
      if (alunoEncontrado == true){
         return exclusaoRealizada;
        } else {
        return exclusaoInvalida; 
      }
    }
  } else {
    return listaVazia;
  } 
}
/* ********* Fim das funções módulo aluno ********* */