#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Utente.h"
User initUtente(){
    User utente;
    utente.nome = (char*)malloc(sizeof(char)*10);
    utente.cognome = (char*)malloc(sizeof(char)*10);
    utente.codiceFiscale = (char*)malloc(sizeof(char)*10);
    utente.password = (char*)malloc(sizeof(char)*10);
    return utente;
}
User registazioneUtente(){
    User utente = initUtente();
    char buff [20];
    char buff1 [20];
    int count = 0;


    printf("Compila i seguenti campi:\n");

    strcpy(utente.nome, doSceltaString("Nome\nInput -> ", 0, 2, 20));


    strcpy(utente.cognome, doSceltaString("Cognome\nInput -> ", 0, 2, 20));

    do{
        if(count > 0)
            printf("C.F gia' e' registrato nel sistema\n");
        count++;
        strcpy(utente.codiceFiscale, doSceltaString("Codice Fiscale (16 caratteri)\nInput -> ", 16, 0, 0));
    }while(checkIfExist(utente.codiceFiscale, "Utenti.txt"));


    strcpy(utente.password, doCompare());



    utente.punti = 0;
    registraFileUtente(utente);


}

bool updateUserOnFile(User utente){ // Da rinominare
   FILE *source, *target;
    char* buff1[400];
    char* buff2[400];
    int i = 0;
    char* last_CF[400];
    char tmp[20];
    source = fopen("Utenti.txt", "r");

    if( source == NULL){
        printf("Impossibile aprire file Prenotazioni.txt\n");
        exit(0);
    }
    else{
        target = fopen("tmp.txt", "w+");
        if(target == NULL){
            printf("Impossibile creare nuovo file tmp.txt\n");
            exit(0);
        }
        else{
            while(fgets(buff1,400,source)!=NULL){
                if(strstr(buff1,"@CodiceFiscale")){ //Se il campo e' quello CodiceFiscale
                    strcpy(buff2,strremove(buff1,"@CodiceFiscale ")); //Viene rimosso il campo @CodiceFiscale dalla stringa buff1

                    strcpy(last_CF, buff2); // Salvo la variabile del attuale codice fiscale per i futuri controlli
                    if(!strcmp(buff2, utente.codiceFiscale)){ //Se il valore del campo CodiceFiscale corrisponde al c.f passato
                    fprintf(target, "%s\n", concatenation("@CodiceFiscale ", utente.codiceFiscale));

                            fprintf(target, "%s", "@Nome ");
                            fprintf(target, "%s\n", utente.nome);

                            fprintf(target, "%s", "@Cognome ");
                            fprintf(target, "%s\n", utente.cognome);


	                        fprintf(target, "%s", "@Password ");
	                        fprintf(target, "%s\n", utente.password);

                            fprintf(target, "%s", "@Punti ");
                            fprintf(target, "%d\n", utente.punti);
                    }
                    else{
                    	 fprintf(target, "%s\n", concatenation("@CodiceFiscale ", buff1)); // CASP ELSE Se il campo @CodiceFiscale e' diverso dal nostro codice_fiscale passato

                    }
                }
                else if (!strcmp(last_CF, utente.codiceFiscale)){
                    // CASP ELSE IF Se il campo e' diverso dal @CodiceFiscale, faccio scorrere fgets
                   // printf("CASP ELSE IF Se il campo e' diverso dal @CodiceFiscale \n");
                }
                else{
                    fprintf(target, "%s", buff1); // CASP ELSE Se il campo e' diverso dal @CodiceFiscale

                }
            }

        }
        fclose(target);
    }
    fclose(source);


    if(remove("Utenti.txt") == 0){

    }
    else{
        printf("Impossibile eliminare il file Utenti.txt\n");
    }

    if(rename("tmp.txt", "Utenti.txt") == 0){

    }
    else{
        printf("Impossibile rinominare il nome del file tmp.txt in Utenti.txt\n");
    }

}

void stampaUtente(User utente){
    printf("Nome:%s\n", utente.nome);
    printf("Cognome:%s\n", utente.cognome);
    printf("Codice Fiscale:%s\n", utente.codiceFiscale);
    printf("Password:%s\n", utente.password);
    printf("Punti:%d\n", utente.punti);
}

void registraFileUtente(User utente){

    FILE * fp;
    fp = fopen("Utenti.txt", "a");

    char tmp[20];
    fflush(stdin);



   if(!fp){
        printf("Errore nell'apertura del file");
        return -1;
    }
    else{
    fprintf(fp,"%s\n" ,   concatenation("@CodiceFiscale ", utente.codiceFiscale));
    fprintf(fp,"%s\n" ,   concatenation("@Nome ", utente.nome));
    fprintf(fp,"%s\n" ,  concatenation("@Cognome ", utente.cognome));
    fprintf(fp,"%s\n" ,   concatenation("@Password ", utente.password));
    sprintf(tmp, "%d", utente.punti);
    fprintf(fp, "%s\n", concatenation("@Punti ", tmp));
    }
    fclose(fp);


}


User login(){
    User utente = initUtente();
    int check=0;
    char tmpCF[50];
    char tmpPassword[50];
    do{
        if(check){
            system("cls");
            printf("\nCoppia Codice Fiscale/Password non presente , riprova\n");

        }

        printf("Inserire codice fiscale: ");
        scanf("%s",tmpCF);

        printf("Inserire Password: ");
        scanf("%s",tmpPassword);


        check++;

    }while(!checkIfExist(tmpCF,"Utenti.txt")||!checkPassword(tmpCF,tmpPassword));

    utente = getUtente(tmpCF);


    return utente;
}

User getUtente(char* codiceFiscale){
        User utente=initUtente();
        char buff[400];
        char punti[20];
         char buffer[400];
        FILE *fp = fopen("Utenti.txt", "r");
        if(fp == NULL){
            printf("Impossibile aprire il file" );
        }else {

        while(fgets(buff,400,fp)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
            if(strstr(buff,"@CodiceFiscale"))
                strcpy(buffer,strremove(buff,"@CodiceFiscale "));
            if (!strcmp(buffer,codiceFiscale)){
                    strcpy(utente.codiceFiscale, buffer);

            if (!strcmp(utente.codiceFiscale,codiceFiscale)){
                if(strstr(buff,"@Nome"))
                    strcpy(utente.nome,strremove(buff,"@Nome "));
                if(strstr(buff,"@Cognome"))
                    strcpy(utente.cognome,strremove(buff,"@Cognome "));
                if(strstr(buff,"@Password"))
                    strcpy(utente.password,strremove(buff,"@Password "));
                if(strstr(buff,"@Punti")){
                    strcpy(punti,strremove(buff,"@Punti "));
                    utente.punti=atoi(punti);
                }

            }

            }
        }
        fclose(fp);

        return utente;
    }
}

bool checkPassword(char* codiceFiscale, char* password){
        bool find= false;
        char buff[200];
        char *tmpCF;
        tmpCF = (char*)malloc(sizeof(char)*16);
        char *tmpPassword;
        tmpPassword = (char*)malloc(sizeof(char)*16);

        FILE *fp = fopen("Utenti.txt", "r");
        if(fp == NULL){
            printf("Impossibile aprire il file" );
        }else {

        while(fgets(buff,200,fp)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
            if(strstr(buff,"@CodiceFiscale"))
                strcpy(tmpCF,strremove(buff,"@CodiceFiscale "));
                if (!strcmp(tmpCF,codiceFiscale))
                    strcpy(tmpPassword,strremove(buff,"@Password "));
                    if(!strcmp(tmpPassword,password))
                        find = true;
        }
    fclose(fp);
        return find;
    }
}

int countUtenti(){
	FILE *fp;
	char read_line[150];
	int count = 0;
	fp = fopen("Utenti.txt", "r");
	if(fp == NULL){
		printf("Errore apertura file Utenti.txt nella funzione countUtenti\n");
	}
	else{
		while (fgets(read_line, 150, fp) != NULL  ){
	        if(strstr(read_line,"@CodiceFiscale")){
                strcpy(read_line,strremove(read_line,"@CodiceFiscale "));
                if(strcmp(read_line, "admin")){
                    count++;
                }
	        }

        }
        fclose(fp);
	}
	return count;
}


User* getAllUtenti(int numberUser){
	User *utente = (User*)malloc(sizeof(struct TUtente)*numberUser);
	char read_line[150];
	char buff[150];
	int i = 0;
	FILE *fp;
		fp = fopen("Utenti.txt", "r");
		if(fp == NULL){
			printf("Errore apertura file Utenti.txt\n");
		}
		else{
			while (fgets(read_line, 150, fp) != NULL  ){

		        if(strstr(read_line,"@CodiceFiscale")){

	                strcpy(buff,strremove(read_line,"@CodiceFiscale "));
	                if(strcmp(buff, "admin")){
                         utente[i] = initUtente();
                       //  printf("Valore buff:%s\n", buff);
                        strcpy(utente[i].codiceFiscale, buff);

	                }
                  //  printf("Valore:%s\n", buff);
		        }
	                if(strcmp(buff, "admin")){

			            if(strstr(read_line,"@Nome")){

                            strcpy(utente[i].nome,strremove(read_line,"@Nome "));
                            //printf("Nome:%s\n", utente[i].nome);
			            }

		                if(strstr(read_line,"@Cognome")){

                            strcpy(utente[i].cognome,strremove(read_line,"@Cognome "));
                           //  printf("Cognome:%s\n", utente[i].cognome);
		                }

		                if(strstr(read_line,"@Password")){

                            strcpy(utente[i].password,strremove(read_line,"@Password "));
                         //   printf("Password:%s\n", utente[i].password);
		                }

		                if(strstr(read_line,"@Punti")){
		                    strcpy(read_line,strremove(read_line,"@Punti "));
		                    utente[i].punti=atoi(read_line);
		                     i++;
		                }


	                }




	        }
	        fclose(fp);
		}


		return utente;
}

