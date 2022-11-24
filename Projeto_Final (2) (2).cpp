
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char palavra[20];
char palavra_secreta[30];

void forca(int erro){
		//Desenho inicial da forca
		if(erro == 0){
			printf("____________\n");
			printf("|          |\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-\n\n");
		}
		else if(erro == 1){
			printf("____________\n");
			printf("|          |\n");
			printf("|          O\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-\n\n");
		}
		else if(erro == 2){
			printf("____________\n");
			printf("|          |\n");
			printf("|          O\n");
			printf("|          |\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-\n\n");		
		}
		else if(erro == 3){
			printf("____________\n");
			printf("|          |\n");
			printf("|          O\n");
			printf("|         /|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-\n\n");
		}
		else if(erro == 4){
			printf("____________\n");	
			printf("|          |  \n");
			printf("|          O  \n");
			printf("|         /|\\  \n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-\n\n");
		}
		else if(erro == 5){
			printf("____________\n");
			printf("|          |\n");
			printf("|          O \n");
			printf("|         /|\\  \n");
			printf("|           \\  \n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-\n\n");
		}
		else if(erro == 6){
			printf("____________\n");
			printf("|          |\n");
			printf("|          O  \n");
			printf("|         /|\\  \n");
			printf("|         / \\  \n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-           Voce foi enforcado :( \n\n");	
		}
}
//escolher uma palavra aleatoria do arquivo .txt
void escolhe_palavra() {
	FILE* f;

	f = fopen("palavras.txt", "r");
	//caso o arquivo nao exista
	if(f == 0) {
		printf("Banco de dados de palavras não disponível\n\n");
		exit(1);
	}
//randomisar as palavras
	int qtd_de_palavras;
	fscanf(f, "%d", &qtd_de_palavras);

	srand(time(0));
	int randomico = rand() % qtd_de_palavras;

	for(int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", palavra_secreta);
	}

	fclose(f);
}


//Funcao para adicionar uma nova palavra
void adiciona_palavra() {
		char nova_palavra[30];

		printf("Digite a nova palavra, em letras maiusculas: ");
		scanf("%s", nova_palavra);
		
	//abrir o arquivo onde vai ser salvo
		FILE* f;
		
	//verificar se o arquivo existe ou nao
		f = fopen("palavras.txt", "r+");
		if(f == 0) {
			printf("Banco de dados de palavras nao disponivel\n\n");
			exit(1);
		}
		
		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);
		
	//salvar a palavra digitada no arquivo .txt
		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", nova_palavra);
	
	printf("Palavra salva!!");
	//fechar o arquivo .txt	
		fclose(f);

	}

void classific(){
	char nome[30];
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	FILE* f;
		
	//verificar se o arquivo existe ou nao
	f = fopen("nome.txt", "r+");
	if(f == 0) {
		printf("Banco de dados do nome nao disponivel\n\n");
		exit(1);
	}
		
		
	//salvar a nome digitada no arquivo .txt
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n%s", nome);
	
	//fechar o arquivo .txt	
	fclose(f);
}
void ranking(){
	FILE* f;
		
	//verificar se o arquivo existe ou nao
	f = fopen("nome.txt", "r");
	if(f == 0) {
		printf("Banco de dados do nome nao disponivel\n\n");
		exit(1);
	}
	//ler os nomes do arquivo
	printf("Nomes: \n\n");
	char c; 
	do{
		c = fgetc(f);
		printf("%c", c); 
	}while( c != EOF);
	
	fclose(f);
}
int main(){
	int escolha_inic;
	//menu inicial
	printf("1 - Comecar o Jogo \t 2 - Ranking \t 3 - Cadastrar Palavra\t 4 - Creditos\t 5 - Sair \n\n");
	
	printf("Escolha uma opcao utilizando o numero indicado: ");
	scanf("%d", &escolha_inic);
	
	//if do "menu" para iniciar o jogo
	int erro = 0;
	if(escolha_inic == 1){
	//limpar a tela
		system("cls");
	//void para pegar o nome para o ranking
		classific();
		strcpy(palavra, palavra_secreta);//copia de palavra_secreta
		
		  //substitui letras por '_'
		  	printf("Palavra: \n");
			for(int i=0;i<strlen(palavra);i++){
				
				palavra[i]='_';
				
			}
			
		
		while(1){
			
		//void para escolher a palavra
			escolhe_palavra();
		//void para imprimir a forca
			forca(erro);
				
		  	
			for(int i=0;i<strlen(palavra);i++){
                printf("%c ", palavra[i]);
            }
            
            int cont = 0;
			for(int i = 0; i < strlen(palavra_secreta);i++){
                cont += 1;
            }	
            
			printf("\nA quantidade de letras da palavra e %d. ", cont);
			printf("\n");
			
		//capturar a letra digitada pelo usuario
			char letra;
			printf("Digite uma letra em maiusculo: ");
			scanf("%s", &letra);
	
			int sera_que_errou=1;//1=sim 0=nao	
			for(int i=0;i<strlen(palavra_secreta); i++){
		      if(letra == palavra_secreta[i]){//certo
		        palavra[i]=letra;
		        sera_que_errou=0;
		    	} 
			}
			
			if(sera_que_errou==1){
      			erro++;
    		}
    		
			if(strcmp(palavra,palavra_secreta)==0){
	      //ENTAO ganhou
		    printf("\nVocê acertou: ");
		    for(int i=0;i<strlen(palavra);i++){
		        printf("%c ", palavra[i]);
		    }
		    printf("\nParabéns!");
		      
		    break;
	    	}
		    //verifica se perdeu
		    if(erro == 6){
		      //perdeu
		      forca(erro);
		      break;
		    }
		}
	}
	//if do "menu" para ver o ranking
	else if(escolha_inic == 2){
		system("cls");
		printf("====================== Ranking ======================\n\n");
		ranking();
	}
	//if do "menu" para cadastrar a palavra
	else if(escolha_inic == 3){
		system("cls");
		adiciona_palavra();
	}
	//if do "menu" para ver os creditos
	else if(escolha_inic == 4){
		system("cls");
		printf("======================    Creditos   ======================\n\n");
		printf("---------------------- Programadores ----------------------|\n\t\t\t\t\t\t\t   |\n");
		printf("Nomes:\t\t\t\t\t\t RMG:\t   |\n"); 
		printf("1 - Joao Victor Martelleto de Paula Teixeira \t 30427355  |\n");
		printf("2 - Danylo Rodrigues Nunes \t\t\t 30345235  |\n");
		printf("3 - Lauane Louise Viana Santos \t\t\t 31584764  |\n");
		printf("4 - Ygor Vinnicius Rodrigues de Pontes \t\t 30892821  |\n\t\t\t\t\t\t\t   |\n");
		
		printf("-----------------------------------------------------------|");
	}
	//if do "menu inicial" onde vai "Finalizar o codigo
	else if(escolha_inic == 5){
		system("cls");
		printf("\n\n------------------ Finalizado ------------------");
		exit(EXIT_SUCCESS);
	}
}
