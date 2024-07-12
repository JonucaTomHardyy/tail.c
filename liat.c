#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liat.h"

int main(int argc, char *argv[]){
	double byte=0;
	int n = atoi(argv[2]);

		if(argc==1){
			liat(argv[1], 10);
		}
		else if(argc==3 && strcmp(argv[1], "-n")==0){
			liat(argv[3], n);
		}
		else if(argc==3 && (strcmp(argv[1], "-bn") || strcmp(argv[1], "-nb"))==0){
			byte=liat(argv[3], n);
			printf("total: %lf",byte);
		}
		else if(argc==3 && strcmp(argv[1], "-b")==0){
			byte=liat(argv[3],n);
			printf("total: %lf",byte);
		}

	return 0;
}

int liat(char *fichier,int line_affiche){
	FILE *file;
	//overture
	file=fopen(fichier, "r");
	if(file==NULL){
		printf("error pointeur");
		return 1;
	}

	char line[1000], cp_line[1000][1000];
	int nb_line=0, i=0;
	
  //etape1 (compte nombre de ligne et copier les linges dans cp_line)
	do{
		fgets(line, sizeof(line), file);
		strcpy(cp_line[nb_line], line);
		nb_line++;
	}while(feof(file)!=1);
	printf("total: %d\n",nb_line);

  //etape2 afficher les 10 dernier ligne
	for(i=line_affiche; i>=0; i--){
		printf("%s",cp_line[nb_line-i]);
	}

	//fermeture
	fclose(file);
	
	return nb_line;
}
