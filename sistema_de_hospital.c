#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

typedef struct{
    char nome[100];
    char cpf[30];
    char capturaCpf[30];
    char telefone[15];
    char email[100];
    char rua[100];
    char numero[10];
    char bairro[60];
    char cidade[60];
    char estado[40];
    char cep[15];
    char comorbidade[30];
    int idadeInt;
    char idadeStr[10];
    char grupoDeRisco[30];
} Dados;

typedef struct{
    char diaNasc[5];
    char mesNasc[5];
    char anoNasc[10];
    char dataNasc[20];
    char armazenaDia;
    char armazenaMes;
    char armazenaAno;
    char digitadoDia[5];
    char digitadoMes[5];
    char digitadoAno[10];
    int diaCaptura;
    int mesCaptura;
    int anoCaptura;
    char diaAniver[5];
    char mesAniver[5];
    char anoAniver[10];
    char infoNasc[30];
} Calendario;

struct st_dataCad{
    char diaDiagnostico[5];
    char mesDiagnostico[5];
    char anoDiagnostico[10];
    char infoDiagnostico[20];
    int diaAtual;
    int mesAtual;
    int anoAtual
} dataCad;

void inicial();
void login();
void obrigatorio();
void cadastro();
int validaCpf();
int validaData();
void formataNasc();
void geraDataCadastro();
void verificaComorbidade();
void verificaGrupoDeRisco();
void arqPaciente();
void arqGrupoDeRisco();
void opcoesPrograma();
void executaPrograma();
void encerraPrograma();

Dados dados;
Calendario calendario;

int resposta;
FILE *arquivo;

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    inicial();

    return 0;
}

void inicial(){

        resposta = 0;

        printf("\n\n=============================\n");
        printf("===== SISTEMA DE SAUDE ======\n");
        printf("=============================\n");
        printf("=== Cadastro de pacientes ===\n");
        printf("=============================\n");
        printf("=============================\n\n");
        system("pause");
        system("@cls||clear");

        do {
            printf("\n\n=============================\n");
            printf("= Paciente possui covid-19? =\n");
            printf("=============================\n\n");
            printf("========== Digite: ==========\n\n");
            printf("           1 - Sim           \n");
            printf("           2 - Não           \n\n");
            printf("=============================\n\n");
            scanf("%d", &resposta);

        if(resposta == 1){
            system("@cls||clear");
            login();
        }
        else if (resposta == 2){
            system("@cls||clear");
            printf("\n\n===========================\n\n");
            printf(" Sistema prossegue apenas    \n");
            printf(" com diagnóstico positivo    \n");
            printf("\n===========================\n\n");
            exit(0);
        }
        else{
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("====== Opção inválida! ======\n");
            printf("=============================\n\n");
            getchar();
            Sleep(1000);
            system("@cls||clear");
        }
        } while(resposta != 1 && resposta != 2);
}

void login(){

        //login: enfermeira
        //password: 123456

        char user1[20];
        char pass1[20];
        char user2[20] = "enfermeira";
        char pass2[20] = "123456";
        int verificador = 1;

        do
          {
            printf("\n\n=============================\n");
            printf("======= TELA DE LOGIN =======\n");
            printf("=============================\n");
            printf("=============================\n\n");
            printf("Usuário: ");
            scanf("%s", &user1);

            printf("senha: ");
            scanf("%s", &pass1);

         if (strcmp(user1, user2) == 0 && strcmp(pass1, pass2) == 0){
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("==== Logado no sistema! =====\n");
            printf("=============================\n\n\n");
            system("pause");
            system("@cls||clear");
            getchar();
            executaPrograma();
        }
        else if (strcmp(user1, user2) != 0 && strcmp(pass1, pass2) != 0){
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("====== Login inválido! ======\n");
            printf("=============================\n\n");
            verificador += 1;
            Sleep(2000);

            if(verificador < 4){
            system("@cls||clear");
            printf("\n\n====== Tentativas %d/3 ======\n", verificador);
            }
        }
        } while(verificador < 4);
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("===== Acesso bloqueado! =====\n");
            printf("=============================\n\n");
            Sleep(3000);
            exit(0);
}

void obrigatorio(){
        system("@cls||clear");
        printf("\n\n=============================\n");
        printf("===== Dado obrigatório! =====\n");
        printf("=============================\n\n");
        Sleep(1000);
        system("@cls||clear");
        printf("\n\n=============================\n");
        printf("===== DADOS DO PACIENTE =====\n");
        printf("=============================\n");
        }

void cadastro(){

        int verifica = 0;

        printf("\n\n=============================\n");
        printf("===== DADOS DO PACIENTE =====\n");
        printf("=============================\n");

        do{
            verifica = 0;
            printf("\nNome: ");
            fflush(stdout);
            fgets(dados.nome, 50, stdin);
            if(strcmp(dados.nome,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        validaCpf();

        validaData();

        formataNasc();

        do{
            verifica = 0;
            printf("\nTelefone: ");
            fflush(stdout);
            fgets(dados.telefone, 50, stdin);
            if(strcmp(dados.telefone,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nE-mail: ");
            fflush(stdout);
            fgets(dados.email, 50, stdin);
            if(strcmp(dados.email,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nRua: ");
            fflush(stdout);
            fgets(dados.rua, 50, stdin);
            if(strcmp(dados.rua,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nNúmero: ");
            fflush(stdout);
            fgets(dados.numero, 50, stdin);
            if(strcmp(dados.numero,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nBairro: ");
            fflush(stdout);
            fgets(dados.bairro, 50, stdin);
            if(strcmp(dados.bairro,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nCidade: ");
            fflush(stdout);
            fgets(dados.cidade, 50, stdin);
            if(strcmp(dados.cidade,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nEstado: ");
            fflush(stdout);
            fgets(dados.estado, 50, stdin);
            if(strcmp(dados.estado,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        do{
            verifica = 0;
            printf("\nCEP: ");
            fflush(stdout);
            fgets(dados.cep, 50, stdin);
            if(strcmp(dados.cep,"\n") == 0){
            obrigatorio();
            }else{
            verifica = 1;
        }
        }while(verifica != 1);

        geraDataCadastro();

        printf("\n\n");

        system("pause");
        system("@cls||clear");
}

int validaCpf(){

        char verificaCpf[11];
        int liberaCpf = 0;

        do{

        liberaCpf = 0;
        int testeIgual = 0;

        printf("\nCPF: ");
        scanf("%s", &dados.capturaCpf);

        int i = 0;
        for(; i < 11; i++) {
        verificaCpf[i] = dados.capturaCpf[i] - 48;
        testeIgual += verificaCpf[i];
        }
        if(testeIgual / 11 == verificaCpf[i - 1] && testeIgual % 11 == 0) {
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("=== Digite um CPF válido! ===\n");
            printf("=== Sem pontos ou traços  ===\n");
            printf("=============================\n\n");
            Sleep(2000);
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("===== DADOS DO PACIENTE =====\n");
            printf("=============================\n");
        }
        else {
            int j = 0;
            int total = 0;
            for(int i = 10; i >= 2; i--) {
            total = total + verificaCpf[j] * i;
            j++;
        }
            int validacao1 = total % 11;
            if(validacao1 < 2) {
            validacao1 = 0;
        }
        else {
            validacao1 = 11 - validacao1;
        }
            j = 0;
            total = 0;
            for(int i = 11; i >= 2; i--) {
            total = total + verificaCpf[j] * i;
            j++;
        }
            int validacao2 = total % 11;
        if(validacao2 < 2) {
            validacao2 = 0;
        }
        else {
            validacao2 = 11 - validacao2;
        }
        if(validacao1 == verificaCpf[9] && validacao2 == verificaCpf[10]) {
            liberaCpf = 1;
        }
        else {
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("=== Digite um CPF válido! ===\n");
            printf("=== Sem pontos ou traços  ===\n");
            printf("=============================\n\n");
            Sleep(2000);
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("===== DADOS DO PACIENTE =====\n");
            printf("=============================\n");
        }
        }
        }while(liberaCpf != 1);

            strcpy(dados.cpf, dados.capturaCpf);

    return 0;
}


int validaData(){

        int validador;
        int controleDia;
        int controleMes;
        int controleAno;

        do{

        validador = 0;
        controleDia = 0;
        controleMes = 0;
        controleAno = 0;

        printf("\nData de Nascimento: ");

        //Dia
        printf("\nDia (dd): ");

        do
        {
           calendario.armazenaDia = getch();
           if (isdigit(calendario.armazenaDia)!=0)
           {
              calendario.digitadoDia[controleDia] = calendario.armazenaDia;
              controleDia++;
              printf ("%c", calendario.armazenaDia);
           }
           else if(calendario.armazenaDia==8&&controleDia)
           {
              calendario.digitadoDia[controleDia]='\0';
              controleDia--;
              printf("\b \b");
           }
        }while(calendario.armazenaDia!=13);

        calendario.digitadoDia[controleDia]='\0';
        calendario.diaCaptura = atoi(calendario.digitadoDia);

        //Mes
         printf("\nMês (mm): ");

        do
        {
           calendario.armazenaMes = getch();
           if (isdigit(calendario.armazenaMes)!=0)
           {
              calendario.digitadoMes[controleMes] = calendario.armazenaMes;
              printf ("%c", calendario.armazenaMes);
              controleMes++;
           }
           else if(calendario.armazenaMes==8&&controleMes)
           {
              calendario.digitadoMes[controleMes]='\0';
              controleMes--;
              printf("\b \b");
           }
        }while(calendario.armazenaMes!=13);

        calendario.digitadoMes[controleMes]='\0';
        calendario.mesCaptura = atoi(calendario.digitadoMes);

        // Ano
        printf("\nAno (aaaa): ");

        do
        {
           calendario.armazenaAno = getch();
           if (isdigit(calendario.armazenaAno)!=0)
           {
              calendario.digitadoAno[controleAno] = calendario.armazenaAno;
              controleAno++;
              printf ("%c", calendario.armazenaAno);
           }
           else if(calendario.armazenaAno==8&&controleAno)
           {
              calendario.digitadoAno[controleAno]='\0';
              controleAno--;
              printf("\b \b");
           }
        }while(calendario.armazenaAno!=13);

        calendario.digitadoAno[controleAno]='\0';
        calendario.anoCaptura = atoi(calendario.digitadoAno);


        if(calendario.mesCaptura > 0 && calendario.mesCaptura < 13 && calendario.anoCaptura > 1900 && calendario.anoCaptura < 2021){
        if((calendario.mesCaptura == 1 || calendario.mesCaptura == 3 || calendario.mesCaptura == 5 || calendario.mesCaptura == 7 ||calendario.mesCaptura == 8 || calendario.mesCaptura == 10 || calendario.mesCaptura == 12) && (calendario.diaCaptura > 0 && calendario.diaCaptura <= 31)){
            validador = 1;
        } else if(calendario.mesCaptura == 2 && (calendario.diaCaptura > 0 && calendario.diaCaptura <= 29)){
            validador = 1;
        } else if((calendario.mesCaptura == 4 || calendario.mesCaptura == 6 || calendario.mesCaptura == 9 || calendario.mesCaptura == 11) && (calendario.diaCaptura > 0 && calendario.diaCaptura <= 30)){
            validador = 1;
        } else{
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("== Digite uma data válida! ==\n");;
            printf("=============================\n\n");
            Sleep(1000);
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("===== DADOS DO PACIENTE =====\n");
            printf("=============================\n");
        }
        }else{
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("== Digite uma data válida! ==\n");;
            printf("=============================\n\n");
            Sleep(1000);
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("===== DADOS DO PACIENTE =====\n");
            printf("=============================\n");
        }
        } while(validador != 1);
        getchar();
        printf("\n");

        return;
}

void formataNasc(){

        itoa(calendario.diaCaptura, &calendario.diaAniver, 10);
		itoa(calendario.mesCaptura, &calendario.mesAniver, 10);
		itoa(calendario.anoCaptura, &calendario.anoAniver, 10);

		strcpy(calendario.infoNasc, "");

		if(calendario.diaCaptura < 10){
            sprintf(calendario.diaAniver, "0%d", calendario.diaCaptura);
        }else{
            sprintf(calendario.diaAniver, "%d", calendario.diaCaptura);
        }

        if(calendario.mesCaptura < 10){
            sprintf(calendario.mesAniver, "0%d", calendario.mesCaptura);
        }else{
            sprintf(calendario.mesAniver, "%d", calendario.mesCaptura);
        }

        strcat(calendario.infoNasc, calendario.diaAniver);
        strcat(calendario.infoNasc, "/");
        strcat(calendario.infoNasc, calendario.mesAniver);
        strcat(calendario.infoNasc, "/");
        strcat(calendario.infoNasc, calendario.anoAniver);
        strcat(calendario.infoNasc, "\n\0");
}

void geraDataCadastro(){

         time_t t = time(NULL);
         struct tm tm = *localtime(&t);

        //dia
        if(tm.tm_mday < 10){
            sprintf(dataCad.diaDiagnostico, "0%d", tm.tm_mday);
        }else{
            sprintf(dataCad.diaDiagnostico, "%d", tm.tm_mday);
        }

        //mês
        if((tm.tm_mon + 1) < 10){
            sprintf(dataCad.mesDiagnostico, "0%d", tm.tm_mon + 1);
        }else{
            sprintf(dataCad.mesDiagnostico, "%d", tm.tm_mon + 1);
        }

        //ano
        sprintf(dataCad.anoDiagnostico, "%d", tm.tm_year + 1900);

        strcpy(dataCad.infoDiagnostico, "");
        strcat(dataCad.infoDiagnostico, dataCad.diaDiagnostico);
        strcat(dataCad.infoDiagnostico, "/");
        strcat(dataCad.infoDiagnostico, dataCad.mesDiagnostico);
        strcat(dataCad.infoDiagnostico, "/");
        strcat(dataCad.infoDiagnostico, dataCad.anoDiagnostico);
        strcat(dataCad.infoDiagnostico, "\0");
}

void verificaComorbidade(){

        resposta = 0;

        do{
            printf("\n\n=============================\n");
            printf("====== Paciente possui ======\n");
            printf("======  comorbidade?   ======\n");
            printf("=============================\n\n");
            printf("========== Digite: ==========\n\n");
            printf("           1 - Sim           \n");
            printf("           2 - Não           \n\n");
            printf("=============================\n\n");
            scanf("%d", &resposta);

        if(resposta == 1){
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("===== Qual comorbidade? =====\n");
            printf("=============================\n\n");
            scanf("%s", dados.comorbidade);
            printf("\n");

        system("pause");
        system("@cls||clear");

        }else if (resposta == 2){
            strcpy(dados.comorbidade, "Nenhuma");
            system("pause");
            system("@cls||clear");
        }
         else{
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("====== Opção inválida! ======\n");
            printf("=============================\n\n");
            getchar();
            Sleep(1000);
            system("@cls||clear");
        }
        }while(resposta != 1 && resposta != 2);
}

void verificaGrupoDeRisco(){

        dataCad.diaAtual = atol(dataCad.diaDiagnostico);
        dataCad.mesAtual = atol(dataCad.mesDiagnostico);
        dataCad.anoAtual = atol(dataCad.anoDiagnostico);

        dados.idadeInt = dataCad.anoAtual - calendario.anoCaptura;

        if(calendario.mesCaptura == dataCad.mesAtual){
            if(calendario.diaCaptura > dataCad.diaAtual){
                dados.idadeInt = dados.idadeInt - 1;
            }
        }

        if(calendario.mesCaptura > dataCad.mesAtual){
                dados.idadeInt = dados.idadeInt - 1;
        }

        itoa(dados.idadeInt, dados.idadeStr, 10); //itoa converte int para string

        if(dados.idadeInt > 65 || resposta == 1){
            strcpy(dados.grupoDeRisco, "Sim");
        }else{
            strcpy(dados.grupoDeRisco, "Não");
        }
}

void arqPaciente(){

        arquivo = fopen("arquivoPaciente.txt", "a");
        fputs("===========================================\n", arquivo);
        fputs("|           DADOS  DO  PACIENTE           |\n", arquivo);
        fputs("===========================================\n", arquivo);
        fputs("\nNome: ", arquivo);
        fputs(dados.nome, arquivo);
        fputs("CPF: ", arquivo);
        fputs(dados.cpf, arquivo);
        fputs("\nData de Nascimento: ", arquivo);
        fputs(calendario.infoNasc, arquivo);
        fputs("Telefone: ", arquivo);
        fputs(dados.telefone, arquivo);
        fputs("E-mail: ", arquivo);
        fputs(dados.email, arquivo);
        fputs("\n---------------- Endereço -----------------\n\n", arquivo);
        fputs("Rua: ", arquivo);
        fputs(dados.rua, arquivo);
        fputs("Número: ", arquivo);
        fputs(dados.numero, arquivo);
        fputs("Bairro: ", arquivo);
        fputs(dados.bairro, arquivo);
        fputs("Cidade: ", arquivo);
        fputs(dados.cidade, arquivo);
        fputs("Estado: ", arquivo);
        fputs(dados.estado, arquivo);
        fputs("CEP: ", arquivo);
        fputs(dados.cep, arquivo);
        fputs("\n----------- Informações de saude ----------\n", arquivo);
        fputs("\nIdade: ", arquivo);
        fputs(dados.idadeStr, arquivo);
        fputs("\nComorbidade: ", arquivo);
        fputs(dados.comorbidade, arquivo);
        fputs("\nPaciente faz parte do Grupo de Risco? ", arquivo);
        fputs(dados.grupoDeRisco, arquivo);
        fputs("\nData do Diagnostico: ", arquivo);
        fputs(dataCad.infoDiagnostico, arquivo);
        fputs("\n\n===========================================\n\n", arquivo);
        fclose(arquivo);

        printf("\n\n=============================\n");
        printf("===== SISTEMA DE SAUDE ======\n");
        printf("=============================\n");
        printf("=============================\n\n");
        printf(" Confira a pasta do programa!\n\n");
        printf("  Foi gerado um arquivo com  \n");
        printf("  as informações do paciente \n\n");
        printf("=============================\n\n");

        system("pause");
        system("@cls||clear");
}

void arqGrupoDeRisco(){

        if(dados.idadeInt > 65 || resposta == 1){
        arquivo = fopen("grupoDeRisco.txt", "a");
        fputs("====================================\n", arquivo);
        fputs("|   Informações a serem enviadas   |\n", arquivo);
        fputs("|   para a central da Secretaria   |\n", arquivo);
        fputs("|       da Saúde da cidade         |\n", arquivo);
        fputs("====================================\n", arquivo);
        fputs("\nIdade: ", arquivo);
        fputs(dados.idadeStr, arquivo);
        fputs("\nCEP: ", arquivo);
        fputs(dados.cep, arquivo);
        fputs("\n===================================\n\n", arquivo);
        fclose(arquivo);

        printf("\n\n=============================\n");
        printf("===== SISTEMA DE SAUDE ======\n");
        printf("=============================\n");
        printf("=============================\n\n");
        printf("=============================\n");
        printf("      Paciente faz parte     \n");
        printf("      do grupo de risco!     \n");
        printf("=============================\n\n");
        printf("       Confira a pasta       \n");
        printf("    do programa novamente,   \n");
        printf("foi gerado outro arquivo com \n");
        printf("  a idade e CEP do paciente  \n");
        printf("      para ser enviado       \n");
        printf("    a secretaria de saúde    \n\n");
        printf("=============================\n\n");

        system("pause");
        getchar();
        system("@cls||clear");
        }
}

void opcoesPrograma(){

        resposta = 0;

        do
        {
        printf("\n\n=============================\n");
        printf("Pretende fazer novo cadastro?\n");
        printf("=============================\n\n");
        printf("========== Digite: ==========\n\n");
        printf("           1 - Sim           \n");
        printf("           2 - Não           \n\n");
        printf("=============================\n\n");
        scanf("%d", &resposta);

        if (resposta == 1){
            system("@cls||clear");
            getchar();
            executaPrograma();
        }
        else if (resposta == 2){
            system("@cls||clear");
            encerraPrograma();
        }
        else {
            system("@cls||clear");
            printf("\n\n=============================\n");
            printf("====== Opção inválida! ======\n");
            printf("=============================\n\n");
            getchar();
            Sleep(2000);
            system("@cls||clear");
            }

        } while(resposta != 1 && resposta != 2);
}

void executaPrograma(){

        cadastro();

        verificaComorbidade();

        verificaGrupoDeRisco();

        arqPaciente();

        arqGrupoDeRisco();

        opcoesPrograma();
}

void encerraPrograma(){

        //fim do programa
        printf("\n\n=============================\n");
        printf("===== SISTEMA DE SAUDE ======\n");
        printf("=============================\n");
        printf("=============================\n\n");
        printf("         Encerrando...       \n\n");
        printf("=============================\n\n");
        exit(0);
}
