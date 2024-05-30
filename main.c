#include <stdio.h>
#include <stdlib.h>


int criar_arquivo(){
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL)
    {
        printf("erro ao abrir arquivo\n");
        return 1;
    }
    printf("Arquivo Criado com sucesso!\n");
    fclose(arquivo);
    return 0;
}

int escrever_dados(const char *dados){
    FILE *arquivo = fopen("dados.txt", "a");
    if (arquivo == NULL)
    {
        printf("erro ao abrir arquivo\n");
        return 1;
    }
    fprintf(arquivo,"%s\n", dados);
    printf("dados adicionados com sucesso!\n");
    fclose(arquivo);
    return 0;
}

int ler_arquivo(){

    char linha[100];

    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("erro ao abrir arquivo\n");
        return 1;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);
    }
    fclose(arquivo);
    return 0;
}

int atualizar_dados(const char *dados){
    FILE *arquivo = fopen("dados.txt", "a");
    if (arquivo == NULL)
    {
        printf("erro ao abrir arquivo\n");
        return 1;
    }
    fprintf(arquivo,"%s\n", dados);
    printf("dados atualizados com sucesso!\n");
    fclose(arquivo);
    return 0;
}

int excluir_arquivo(const char *nome_arquivo){
        if(remove(nome_arquivo) == 0){
		printf("O arquivo %s foi excluido com sucesso!\n", nome_arquivo);
	}
	else{
		printf("Erro ao excluir arquivo %s\n", nome_arquivo);
	}
    return 0;
}



int main(){

    int op;
    char dados[100];

    do
    {
        printf("\n[1]-Criar arquivo\n[2]-Escrever dados no arquivo\n[3]-Ler arquivo\n[4]-Atualizar arquivo\n[5]-Excluir arquivo\n[0]-Sair do programa\nDigite uma opcao:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            criar_arquivo();
            break;

        case 2:
            printf("Diite oque deseja escrever dentro do arquivo: ");
            scanf("%s",dados);
            escrever_dados(dados);
            break;
        
         case 3:
            ler_arquivo();
            break;
        
        case 4:
            printf("Digite oque deseja adicionar dentro do arquivo: ");
            scanf("%s",dados);
            atualizar_dados(dados);
            break;

        case 5:
            excluir_arquivo("dados.txt");
            break;

        case 0:
        printf("programa encerrado!");
        break;

        default:
            printf("opcao invalida...");
            break;
        }
    } while (op!=0);
    


    return 0;
}
