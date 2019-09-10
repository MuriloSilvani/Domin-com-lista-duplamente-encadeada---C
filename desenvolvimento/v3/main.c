#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pecaDomino{
	int valores[2];
	pecaDomino *proxima, *anterior;
}pecaDomino;

void mostrarPecas(pecaDomino *listaQueVaiSerMostrada);

pecaDomino *inicializarLista();

pecaDomino *inserirPeca(int *aumentaContador, pecaDomino *listaQueRecebePeca, int valor1, int valor2);

pecaDomino *removerPeca(int *diminuiContador, pecaDomino *listaQueRemovePeca, int valor1, int valor2);

pecaDomino *gerarPecas(int *aumentaContador, pecaDomino *listaQueVaiReceberPecas);

pecaDomino *darPecaAleatoria(int *contDar, pecaDomino *dar, int *contReceber, pecaDomino *receber);

/////////////////////////////////////////////////////////////////////////////// 

int main(){
	
	int x = 0;
	while(x < 1000){
		
		system("cls");
		
	x++;
	int contMonte = 0;
	pecaDomino *monte = inicializarLista();
	monte = gerarPecas(&contMonte, monte);

	int contJogador1 = 0;
	pecaDomino *jogador1 = inicializarLista();

	int contJogador2 = 0;
	pecaDomino *jogador2 = inicializarLista();
	
	

	for(int i = 0; i < 28; i++){
		jogador1 = darPecaAleatoria(&contMonte, monte, &contJogador1, jogador1);
	};
	// for(int i = 0; i < 7; i++){
	// 	jogador2 = darPecaAleatoria(&contMonte, monte, &contJogador2, jogador2);
	// };
	
	

		
		// printf("\nPecas do monte: [total: %i]\n", contMonte);
		// mostrarPecas(monte);
		// printf("\nPecas do Jogador 1: [total: %i]\n", contJogador1);
		// mostrarPecas(jogador1);	
		// printf("\nPecas do Jogador 2: [total: %i]\n", contJogador2);
		// mostrarPecas(jogador2);	
		
		
	
		

system("pause");		


	printf("\n\n\n\n\n\n");
};



	
	return 0;
};

/////////////////////////////////////////////////////////////////////////////// 


pecaDomino *inicializarLista(){
	return NULL;
};

pecaDomino *inserirPeca(int *aumentaContador, pecaDomino *listaQueRecebePeca, int valor1, int valor2){
	pecaDomino *novaPeca = (pecaDomino*) malloc(sizeof(pecaDomino));
	novaPeca->valores[0] = valor1;
	novaPeca->valores[1] = valor2;

	*aumentaContador = *aumentaContador + 1;

	// Lista vazia
	if(listaQueRecebePeca == NULL){
		novaPeca->proxima = NULL;
		novaPeca->anterior = NULL;
		return novaPeca;
	};	
	
	pecaDomino *ultima, *auxiliar = listaQueRecebePeca;

	while(auxiliar != NULL && auxiliar->valores[0] == valor1 && auxiliar->valores[1] == valor2){
		ultima = auxiliar;
		auxiliar = auxiliar->proxima;
	};
	
	// Inserção no início
	if(auxiliar == listaQueRecebePeca){
		novaPeca->proxima = listaQueRecebePeca;
		novaPeca->anterior = NULL;
		listaQueRecebePeca->anterior = novaPeca;
		return novaPeca;
	};

	// Inserção no final
	if(auxiliar == NULL){
		novaPeca->proxima = NULL;
		novaPeca->proxima = ultima;
		ultima->proxima = novaPeca;
		return listaQueRecebePeca;
	};

	//Inserção no meio
	novaPeca->proxima = auxiliar;
	novaPeca->anterior = ultima;
	auxiliar->anterior = novaPeca;
	ultima->proxima = novaPeca;

	return listaQueRecebePeca;
};

pecaDomino *gerarPecas(int *aumentaContador, pecaDomino *listaQueVaiReceberPecas){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j <= i; j++){
			listaQueVaiReceberPecas = inserirPeca(aumentaContador, listaQueVaiReceberPecas, i, j);
		};
	};
	printf("Status: TERMINA GERAR PECAS ------------------------------------\n");
	return listaQueVaiReceberPecas;
};

void mostrarPecas(pecaDomino *listaQueVaiSerMostrada){
	if(listaQueVaiSerMostrada == NULL){
		printf("A lista nao contem itens.\n");
		return;
	}else{
		pecaDomino *ultima;
		for(int i = 0; listaQueVaiSerMostrada != NULL; listaQueVaiSerMostrada = listaQueVaiSerMostrada->proxima, i++){
			ultima = listaQueVaiSerMostrada;
		};
		listaQueVaiSerMostrada = ultima;
		for(int i = 0; listaQueVaiSerMostrada != NULL; i++){
			printf("[%d|%d] ", listaQueVaiSerMostrada->valores[0], listaQueVaiSerMostrada->valores[1]);
			listaQueVaiSerMostrada = listaQueVaiSerMostrada->anterior;
		};
		printf("\n");
	};
};

pecaDomino *removerPeca(int *diminuiContador, pecaDomino *listaQueRemovePeca, int valor1, int valor2){
	printf("Status: INICIA REMOVER PECA  devieria remover [%i|%i]\n", valor1, valor2);
	pecaDomino *auxiliar = listaQueRemovePeca;
	
	*diminuiContador = *diminuiContador - 1;
	
	// Lista vazia
	if(listaQueRemovePeca == NULL){
		return NULL;	
	};

	while(auxiliar != NULL && (auxiliar->valores[0] != valor1 || auxiliar->valores[1] != valor2)){
		auxiliar = auxiliar->proxima;
	};

	// Elemento não encontrado
	if(auxiliar == NULL){
		return listaQueRemovePeca;
	};
		
	// Elemento único
	if(auxiliar->proxima == NULL && auxiliar->anterior == NULL){
		free(auxiliar);
		return NULL;
	};

	pecaDomino *remove;

	// Exclusão no início
	if(auxiliar->anterior == NULL){
		remove = auxiliar->proxima;
		remove->anterior = NULL;
		free(auxiliar);
		return remove;
	};

	// Exclusão no final
	if(auxiliar->proxima == NULL){
		auxiliar->anterior->proxima = NULL;
		free(auxiliar);
		return listaQueRemovePeca;
	};

	// Exclusão no meio
	auxiliar->anterior->proxima = auxiliar->proxima;
	auxiliar->proxima->anterior = auxiliar->anterior;
	free(auxiliar);

	return listaQueRemovePeca;
};

pecaDomino *darPecaAleatoria(int *contDar, pecaDomino *dar, int *contReceber, pecaDomino *receber){
	pecaDomino *auxList = dar;	
	int valor1, valor2;
	srand((unsigned)time(NULL));
	int randomValue = (rand() % *contDar)+1;
	
	
	// printf("\nPecas do monte: [total: %i]\n", *contDar);
	// mostrarPecas(dar);
	// printf("\nPecas do Jogador 1: [total: %i]\n", *contReceber);
	// mostrarPecas(receber);	
	
	printf("Valor rand: ");
	scanf("%i",&randomValue);
	printf("RANDOM: %i   max: %i ------------------------\n", randomValue, *contDar);
	
	
	for(int i = 0; i < randomValue; i++){
		valor1 = auxList->valores[0];
		valor2 = auxList->valores[1];
		if(auxList->proxima != NULL){
			auxList = auxList->proxima;
		}else{
			auxList = NULL;
		};
	};
	

	
	
	receber = inserirPeca( contReceber, receber, valor1, valor2);
	dar = removerPeca( contDar, dar, valor1, valor2);
	
	return receber;
	
	
};




