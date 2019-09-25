#include<stdlib.h>
#include<stdio.h>

//	Unoesc - Engenharia de Computação - 1° semestre/
//	Jogo da Velha para Matéria de Programação Experimental;
//	Desenvolvido por Murilo Silvani e Rodrigo Tolomeotti;
//	Data da entrega: 08/05/2018

int main()
{

	int linha = 99, coluna = 99, l1 = 99, c1 = 99, l2 = 99, c2 = 99, l3 = 99, c3 = 99, l4 = 99, c4 = 99, l5 = 99, c5 = 99, l6 = 99, c6 = 99, l7 = 99, c7 = 99, l8 = 99, c8 = 99, l9 = 99, c9 = 99;
	char v[linha][coluna];

	v[linha][coluna] = ' ';

	jogada1:
	printf("   1  2  3  \n");
	printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
	printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
	printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

	printf("jogador 1: \n");
	scanf("%d %d", &linha, &coluna);

	// jogada 1
	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'X';
					l1 = linha;
					c1 = coluna;

					system("cls");
					jogada2:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 2: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada1;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada1;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada1;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada1;
	}
	// fim da jogada 1
	// jogada 2
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada2;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'O';
					l2 = linha;
					c2 = coluna;

					system("cls");
					jogada3:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 1: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada2;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada2;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada2;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada2;
	}
	// fim da jogada 2
	// jogada 3
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada3;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'X';
					l3 = linha;
					c3 = coluna;

					system("cls");
					jogada4:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 2: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada3;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada3;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada3;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada3;
	}
	// fim da jogada 3
	// jogada 4
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada4;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'O';
					l4 = linha;
					c4 = coluna;

					system("cls");
					jogada5:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 1: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada4;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada4;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada4;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada4;
	}
	// fim da jogada 4
	// jogada 5
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada5;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'X';
					l5 = linha;
					c5 = coluna;

					if(v[1][1] == 'X' && v[2][2] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'X' && v[2][2] == 'X' && v[3][1] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'X' && v[2][1] == 'X' && v[3][1] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][2] == 'X' && v[2][2] == 'X' && v[3][2] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'X' && v[2][3] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'X' && v[1][2] == 'X' && v[1][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[2][1] == 'X' && v[2][2] == 'X' && v[2][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[3][1] == 'X' && v[3][2] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}

					system("cls");
					jogada6:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 2: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada5;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada5;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada5;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada5;
	}
	// fim da jogada 5
	// jogada 6
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada6;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'O';
					l6 = linha;
					c6 = coluna;

					if(v[1][1] == 'O' && v[2][2] == 'O' && v[3][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'O' && v[2][2] == 'O' && v[3][1] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'O' && v[2][1] == 'O' && v[3][1] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][2] == 'O' && v[2][2] == 'O' && v[3][2] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'O' && v[2][3] == 'O' && v[3][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'O' && v[1][2] == 'O' && v[1][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[2][1] == 'O' && v[2][2] == 'O' && v[2][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[3][1] == 'O' && v[3][2] == 'O' && v[3][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}

					system("cls");
					jogada7:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 1: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada6;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada6;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada6;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada6;
	}
	// fim da jogada 6
	// jogada 7
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada7;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'X';
					l7 = linha;
					c7 = coluna;

					if(v[1][1] == 'X' && v[2][2] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'X' && v[2][2] == 'X' && v[3][1] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'X' && v[2][1] == 'X' && v[3][1] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][2] == 'X' && v[2][2] == 'X' && v[3][2] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'X' && v[2][3] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'X' && v[1][2] == 'X' && v[1][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[2][1] == 'X' && v[2][2] == 'X' && v[2][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[3][1] == 'X' && v[3][2] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}

					system("cls");
					jogada8:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 2: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada7;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada7;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada7;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada7;
	}
	// fim da jogada 7
	// jogada 8
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada8;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'O';
					l8 = linha;
					c8 = coluna;

					if(v[1][1] == 'O' && v[2][2] == 'O' && v[3][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'O' && v[2][2] == 'O' && v[3][1] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'O' && v[2][1] == 'O' && v[3][1] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][2] == 'O' && v[2][2] == 'O' && v[3][2] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'O' && v[2][3] == 'O' && v[3][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'O' && v[1][2] == 'O' && v[1][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[2][1] == 'O' && v[2][2] == 'O' && v[2][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[3][1] == 'O' && v[3][2] == 'O' && v[3][3] == 'O') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 2 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}

					system("cls");
					jogada9:
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("jogador 1: \n");
					scanf("%d %d", &linha, &coluna);
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada8;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada8;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada8;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada8;
	}
	// fim da jogada 8
	// jogada 9
	if ((linha == l1 && coluna == c1) || (linha == l2 && coluna == c2) || (linha == l3 && coluna == c3) || (linha == l4 && coluna == c4) || (linha == l5 && coluna == c5) || (linha == l6 && coluna == c6) || (linha == l7 && coluna == c7) || (linha == l8 && coluna == c8) || (linha == l9 && coluna == c9)) {
		printf("Jogada nao Permitida (Posicao ja Ocupada) - Jogue Novamente\n");
		goto jogada9;
	}

	if(linha >= 1) {
		if (linha <= 3) {
			if(coluna >= 1) {
				if (coluna <= 3) {
					v[linha][coluna] = 'X';
					l9 = linha;
					c9 = coluna;

					if(v[1][1] == 'X' && v[2][2] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'X' && v[2][2] == 'X' && v[3][1] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'X' && v[2][1] == 'X' && v[3][1] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][2] == 'X' && v[2][2] == 'X' && v[3][2] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][3] == 'X' && v[2][3] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[1][1] == 'X' && v[1][2] == 'X' && v[1][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[2][1] == 'X' && v[2][2] == 'X' && v[2][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}else if (v[3][1] == 'X' && v[3][2] == 'X' && v[3][3] == 'X') {
						system("cls");
						printf("   1  2  3  \n");
						printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
						printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
						printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);
						printf("Jogador 1 ganhou, Parabens!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						return 0;
					}

					system("cls");
					printf("   1  2  3  \n");
					printf("1  %c| %c |%c \n", v[1][1], v[1][2], v[1][3]);
					printf("2  %c| %c |%c \n", v[2][1], v[2][2], v[2][3]);
					printf("3  %c| %c |%c \n", v[3][1], v[3][2], v[3][3]);

					printf("Fim de Jogo: Empate\n");
				}else if(coluna >= 4) {
					printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
					goto jogada9;
				}
			}else if(coluna <= 0) {
				printf("Jogada nao Permitida (Coluna nao Existe) - Jogue Novamente\n");
				goto jogada9;
			}
		}else if(linha >= 4) {
			printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
			goto jogada9;
		}
	}else if(linha <= 0) {
		printf("Jogada nao Permitida (Linha nao Existe) - Jogue Novamente\n");
		goto jogada9;
	}
	// fim da jogada 9
	return 0;
}