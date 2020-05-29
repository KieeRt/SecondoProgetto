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
 * \return true se operazione di registrazione è avvenuta con successo
 *
 */

User initUtente();
User registazioneUtente();

bool registrazioneSulFile(User utente);

void stampaUtente(User utente);

void updateCampoFile(char *nomeCampo, int nuovoValore);


