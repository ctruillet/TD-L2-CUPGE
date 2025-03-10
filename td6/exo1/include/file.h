#ifndef FILE_H
#define FILE_H


// Déclaration des structures incomplètes
typedef struct File * File;

// Prototypes des fonctions
File initFile();
void enfiler(File f, int value);
int defiler(File f);
int fileEstVide(File f);
void afficheFile(File f);

#endif // FILE_H
