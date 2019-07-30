#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int jj;
    int mm;
    int aa;
}date_de_projection;

typedef struct
{
    int numero;
    date_de_projection date;
    int heure;
    int minute;
    int numero_salle;
    char nom_film[30];
    int numero_chaise;
}billet;


typedef struct
{
    int ID;
    billet blt;
}spectateur;

typedef struct cellule cellule;
struct cellule
{
    spectateur spt;
    cellule *suivant;
};

typedef struct File
{
    cellule *tete;
    cellule *Queue;
}File;

typedef struct cellule *liste;

void enregistrement(char *Nom_fichier);

void enfiler(File *F,spectateur s);

int validation_billet(File F,int jour,int mois ,int annee,int heure,int minute);

void afficher(File F);

void ajouter_liste(File *F,liste tab[]);

void afficher_liste(liste l);

void afficher_nbre_spectateur(liste tab[]);

void trier_toute_liste(liste tab[]);

File initialiser();


#endif // HEADER_H_INCLUDED
