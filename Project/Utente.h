#include <stdbool.h>
struct TUtente{
     char * codiceFiscale;
     char * password;
     int punti;
     char * nome;
     char * cognome;
};

typedef struct TUtente User;

/** Registra utente, viene fatta una scrittura sul file Utenti.txt
 *
 * \param
 * \param
 * \return true se operazione di registrazione � avvenuta con successo
 *
 */

User initUtente();
User registazioneUtente();

bool updateUserOnFile(User utente);

void stampaUtente(User utente);


void registraFileUtente(User utente);

User login();

bool checkPassword(char* codiceFiscale, char* password);

User getUtente(char* codiceFiscale);
//Conta numeri di utenti escluso quelli del amministratore
int countUtenti();
User* getAllUtenti(int numberUser);
