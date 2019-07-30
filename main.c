#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

int main()
{
   File F;
   liste l=NULL;
   liste tab[10];
   spectateur s;
   int x,jour,mois,annee,heure,minute;
   int r;
   //char Nom_fichier[25];
   do
   {
       printf("--------------MENU------------- \n");
       printf("1-Enregistrer spectateur dans un fichier txt \n");
       printf("2-Enfiler spectateur \n");
       printf("3-Valider spectateur \n");
       printf("4-Afficher tete et  Queue \n");
       printf("5-Ajouter Spectateur dans liste \n");
       printf("6-Afficher Liste \n");
       printf("7-Compter spectateur \n");
       printf("8-Trier liste selon numero de salles \n");
       printf("9-Initialiser \n");
       printf("0-quitter \n");
       printf("Veuillez entrer votre choix \n");
       scanf("%d",&x);
       switch(x)
       {
       case 1 :
        enregistrement("Fichier.txt");
        break;

       case 2 :
       enfiler(&F,s);
        break;

       case 3 :
        printf("Entrez le jour moid et annee\n");
        scanf("%d %d %d",&jour,&mois,&annee);
        printf("Entrer l'heure et minute \n");
        scanf("%d %d",&heure,&minute);
        r=validation_billet(F,jour,mois,annee,heure,minute);
        break;

       case 4 :
        afficher(F);
        break;
       case 5 :
        printf("Entrez le jour moid et annee\n");
        scanf("%d %d %d",&jour,&mois,&annee);
        printf("Entrer l'heure et minute \n");
        scanf("%d %d",&heure,&minute);
        ajouter_liste(&F,tab);
        break;
       case 6 :
        afficher_liste(l);
        break;
       case 7 :
        afficher_nbre_spectateur(tab);
        break;
       case 8 :
        trier_toute_liste(tab);
       case 9 :
           F=initialiser();
        break;


       }

   }while(x!=0);
    return 0;
}


