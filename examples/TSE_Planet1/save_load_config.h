/*
const byte BUFFER_SIZE = 32;
char conf_buffer[BUFFER_SIZE];

void saveGlobalConfig(String filepath)
{

}

bool loadGlobalConfig(String filepath)
{
  char  *key, *value;
  byte i, buffer_length, line_counter = 0;

  File config_file = SD.open(filepath, FILE_READ);
  if (!config_file) {
    return false;
  }

  while (config_file.available() > 0 ) {

    //read a full line
    i = 0;
    while ((buffer[i++] = config_file.read()) != '\n') {

      /* Si la ligne dépasse la taille du buffer */
      if (i == BUFFER_SIZE) {

        /* On finit de lire la ligne mais sans stocker les données */
        while (config_file.read() != '\n');
        break; // Et on arrête la lecture de cette ligne
      }
    }

    buffer_length = i;

    if (i == BUFFER_SIZE) {
      //line is to long
    }

    /* Finalise la chaine de caractéres ASCIIZ en supprimant le \n au passage */
    buffer[--i] = '\0';

    /* Incrémente le compteur de lignes */
    ++line_counter;

    /* Ignore les lignes vides ou les lignes de commentaires */
    if (buffer[0] == '\0' || buffer[0] == '#') continue;

    /* Cherche l'emplacement de la clef en ignorant les espaces et les tabulations en début de ligne */
    i = 0;
    while (buffer[i] == ' ' || buffer[i] == '\t') {
      if (++i == buffer_length) break; // Ignore les lignes contenant uniquement des espaces et/ou des tabulations
    }
    if (i == buffer_length) continue; // Gère les lignes contenant uniquement des espaces et/ou des tabulations
    key = &buffer[i];

    /* Cherche l'emplacement du séparateur = en ignorant les espaces et les tabulations âpres la clef */
    while (buffer[i] != '=') {

      /* Ignore les espaces et les tabulations */
      if (buffer[i] == ' ' || buffer[i] == '\t') buffer[i] = '\0';

      if (++i == buffer_length) {
        break; //ignore bad format
      }
    }
    if (i == buffer_length) continue; // Gère les lignes mal formé

    /* Transforme le séparateur = en \0 et continue */
    buffer[i++] = '\0';

    /* Cherche l'emplacement de la valeur en ignorant les espaces et les tabulations âpres le séparateur */
    while (buffer[i] == ' ' || buffer[i] == '\t') {
      if (++i == buffer_length) {
        break; // Ignore bad format
      }
    }
    if (i == buffer_length) continue; // Gère les lignes mal formé
    value = &buffer[i];

    //get data : add the global variable you want to retrieve here.
    if (strcmp(key, "toto") == 0) {
      toto = atoi(value);
    }
    else if (strcmp(key, "tata") == 0) {
      tata = atoi(value);
    }
    else if (strcmp(key, "titi") == 0) {
      titi = atoi(value);
    }
    else { // Default
      //unknown key
    }

  }

  /* Ferme le fichier de configuration */
  config_file.close();
}

void saveGameConfig(String filepath)
{

}

void loadGameConfig(String filepath)
{

}

*/
