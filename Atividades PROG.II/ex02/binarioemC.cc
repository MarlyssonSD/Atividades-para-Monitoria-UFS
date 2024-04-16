#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade, ano_nascimento;
} Perfil;

void escreveBinario(char *arq)
{
    Perfil um_perfil;
    FILE *arquivo = fopen(arq, "ab");

    if (arquivo)
    {
        printf("Escreva o nome, a idade e depois o ano nascimento:\n");
        fgets(um_perfil.nome, 50, stdin);
        scanf("%d%d", &um_perfil.idade, &um_perfil.ano_nascimento);
        fwrite(&um_perfil, sizeof(Perfil), 1, arquivo);
        fclose(arquivo);
        // printf("%s", um_perfil.nome);
    }
    else
    {
        printf("Não abriu");
    }
    fclose(arquivo);
}

void modificaPerfil(char *arq, int posicao)
{
    Perfil novo_perfil;
    FILE *arquivo = fopen(arq, "r+b");
    if (arquivo)
    {

        fseek(arquivo, (posicao - 1) * sizeof(Perfil), SEEK_SET);

        printf("\nModificando informações\n ");
        printf("Escreva o nome, a idade e depois o ano nascimento:\n");
        fflush(stdin);
        fgets(novo_perfil.nome, 50, stdin);
        scanf("%d%d", &novo_perfil.idade, &novo_perfil.ano_nascimento);
        fwrite(&novo_perfil, sizeof(Perfil), 1, arquivo);
    }
    else
    {
        printf("Arquivo não abriu");
    }
    fclose(arquivo);
}

void lerBinario(char *arq)
{
    Perfil um_perfil;
    FILE *arquivo = fopen(arq, "rb");

    if (arquivo)
    {
        printf("\n\t---Lista de perfis---");
        while (!feof(arquivo))
        {
            if (fread(&um_perfil, sizeof(Perfil), 1, arquivo))
            {
                printf("\nNome: %sIdade: %d\nAno de nascimento: %d", um_perfil.nome, um_perfil.idade, um_perfil.ano_nascimento);
                printf("\n------------------------------------\n");
            }
        }
    }
    else
    {
        printf("Não abriu");
    }
    fclose(arquivo);
}

int contaPerfis(char *arq)
{
    Perfil um_perfil;
    FILE *arquivo = fopen(arq, "rb");

    int contador = 0;
    if (arquivo)
    {
        while (!feof(arquivo))
        {
            if (fread(&um_perfil, sizeof(Perfil), 1, arquivo))
                contador += 1;
        }
    }
    else
    {
        printf("Não abriu");
    }
    fclose(arquivo);
    return contador;
}

void binarioToTxt(char *arqBin, char *arqTxt)
{
    Perfil um_perfil;
    FILE *arquivoBin = fopen(arqBin, "rb");
    FILE *arquivoTxt = fopen(arqTxt, "wt");
    if (arquivoBin && arquivoTxt)
    {
        while (!feof(arquivoBin))
        {
            if (fread(&um_perfil, sizeof(Perfil), 1, arquivoBin))
            {
                fprintf(arquivoTxt, "Nome: %sIdade: %d\nAno de nascimento: %d\n\n", um_perfil.nome, um_perfil.idade, um_perfil.ano_nascimento);
                printf("Entrou");
            }
            // printf("Entrou");
        }
    }
    else
    {
        printf("\nErro na abertura do(s) arquivo(s)\n");
    }
    fclose(arquivoBin);
    fclose(arquivoTxt);
}

void lerTxt(char *arqTxt)
{
    FILE *arquivoTxt = fopen(arqTxt, "rt");
    char *caractere;
    if (arquivoTxt)
    {
        while ((fgets(caractere, sizeof(caractere), arquivoTxt) != NULL))
        {
            printf("%s", caractere);
        }
    }
    else
    {
        printf("\nErro na abertura do arquivo\n");
    }
    fclose(arquivoTxt);
}

int main()
{
    char *arqBin = ("PESSOAS.dat");
    char *meutxt = ("PESSOAS.TXT");
    int quant, op = 5;
    int Quantidade_de_perfis = contaPerfis(arqBin);
    do
    {

        printf("\n\tMenu:\n");
        printf("1. Escrever em um arquivo binario\n");
        printf("2. Modificar perfil\n");
        printf("3. Ler arquivo binario\n");
        printf("4. Converter arquivo binario para texto (.txt)\n");
        printf("5. Ler arquivo (.txt) \n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            escreveBinario(arqBin);
            break;
        case 2:
            lerBinario(arqBin);
            printf("Quatidade de perfis: %d\n", Quantidade_de_perfis);
            printf("Qual perfil deseja modificar? ");
            scanf("%d", &quant);
            modificaPerfil(arqBin, quant);
            lerBinario(arqBin);
            break;
        case 3:
            lerBinario(arqBin);
            break;
        case 4:
            binarioToTxt(arqBin, meutxt);
            break;
        case 5:
            lerTxt(meutxt);
            break;
        default:
            break;
        }
    } while (op != 0);
    return 0;
}
