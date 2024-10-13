#include <stdio.h>
#define tamanhoAluno 3

int main(void){

  int sair = 0;

  int icontAluno = 0;
  int listaAluno[tamanhoAluno];
  int opcaoMenu;
  int opcaoAluno;

  int matriculaAluno;



  do{

    printf("**** Projeto escola ****\n");
    printf("0° -> Sair\n");
    printf("1° -> Aluno\n");
    printf("2° -> Professor\n");
    printf("3° -> Disciplina\n");
    printf("Opção escolhida -> ");
    scanf("%d", &opcaoMenu);

    switch(opcaoMenu){

      case 0:
      {
        sair = 1;
        printf("Saindo do programa...\n");
        break;
      }

      case 1:
      {
        do {
          printf("\nMódulo Aluno\n");
          printf("0° -> Voltar ao menu\n");
          printf("1° -> Cadastrar aluno\n");
          printf("2° -> Listar aluno\n");
          printf("3° -> Atualizar aluno\n");
          printf("4° -> Excluir aluno\n");
          printf("Opção escolhida -> ");
          scanf("%d", &opcaoAluno);

          switch(opcaoAluno){
            case 0:
            {
              printf("\nVoltando ao menu...");
              break;
            }

            case 1:
            {
              if (icontAluno == tamanhoAluno){
                printf("\nNúmero máximo de alunos cadastrados atingido!\n");
              } else {
                printf("\nCadastrar aluno\n");
                printf("Insira a matrícula do aluno -> ");
                scanf("%d", &matriculaAluno);
                printf("\n");

                if (matriculaAluno < 0){
                  printf("\nMatrícula inválida!\n");
                } else {
                  listaAluno[icontAluno] = matriculaAluno;
                  icontAluno++;
                }
              }

              break;
            }

            case 2:
            {
              printf("\nListar aluno\n");
              for (int icont = 0; icont < tamanhoAluno; icont++){
                printf("Matrícula: %d\n", listaAluno[icont]);
              }
              break;
            }

            case 3:
            {
              printf("Atualizar aluno\n");
              break;
            }

            case 4:
            {
              printf("Excluir aluno\n");
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