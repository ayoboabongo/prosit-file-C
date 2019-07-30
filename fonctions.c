#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>


spectateur saisir_client(spectateur s)
{
    printf("ID client \n");
    scanf("%d",&s.ID);
    printf("Numero billet :\n");
    scanf("%d",&s.blt.numero);
    printf("Date de projection \n");
    do
    {
        printf("Jour : \n");
        scanf("%d",&s.blt.date.jj);
    }while((s.blt.date.jj)<1||(s.blt.date.jj>30));

       do
    {
        printf("Mois : \n");
        scanf("%d",&s.blt.date.mm);
    }while((s.blt.date.mm)<1||(s.blt.date.mm>12));

       do
    {
        printf("Annee : \n");
        scanf("%d",&s.blt.date.aa);
    }while((s.blt.date.aa)<2019||(s.blt.date.aa>2030));

    do
    {
         printf("Heure de projection \n");
         scanf("%d",&s.blt.heure);

    }while((s.blt.heure<0)||(s.blt.heure>23));

    do
    {
         printf("Minute de projection \n");
         scanf("%d",&s.blt.minute);

    }while((s.blt.minute<0)||(s.blt.minute>59));

    do
    {
        printf("Numero de la salle \n");
        scanf("%d",&s.blt.numero_salle);

    }while((s.blt.numero_salle<0)||(s.blt.numero_salle>10));

    printf("Nom du film \n");
    scanf("%s",s.blt.nom_film);
    printf("Numero de la chaise \n");
    scanf("%d",&s.blt.numero_chaise);

    return s;

}

void enregistrement(char *Nom_fichier)
{
    spectateur s;
    FILE *fichier=NULL;
    fichier=fopen(Nom_fichier,"a+");
     if(fichier!=NULL)
     {
         s=saisir_client(s);
        fprintf(fichier,"%d %d %d %d %s %d %d %d %d %d\n",s.ID,s.blt.numero,s.blt.numero_salle,s.blt.numero_chaise,s.blt.nom_film,s.blt.date.jj,s.blt.date.mm,s.blt.date.aa,s.blt.heure,s.blt.minute);
        fclose(fichier);
     }

     else
        printf("impossible d'ouvrir le fichier \n");
}

File initialiser()
{
    File F;
    F.tete=NULL;
    F.Queue=NULL;
    return F;
}

int file_vide(File F)
{
    if((F.tete==NULL)&&(F.Queue==NULL))
        return 1;
    else
        return 0;
}

void enfiler(File *F,spectateur s)
{
    cellule *nouv=malloc(sizeof(struct cellule));
    if(nouv!=NULL)
    {
         s=saisir_client(s);
         nouv->spt=s;
         nouv->suivant=NULL;

         if(file_vide(*F)==1)
           {
              F->tete=nouv;
              F->Queue=nouv;
           }

        else
          {
              (F->Queue)->suivant=nouv;
              F->Queue=nouv;
         }

   }

   else
    printf("Impossible d'allouer la memoire \n");


}

spectateur defiler(File *F,spectateur s)
{
    if(file_vide(*F)==1)
        printf("File vide rien a defiler \n");

    else
    {
        cellule *elementDefiler=F->tete;
        s=F->tete->spt;
        F->tete=elementDefiler->suivant;
        if(F->tete==NULL)
            F->Queue=NULL;
        free(elementDefiler);
    }

    return s;
}

int validation_billet(File F,int jour,int mois ,int annee,int heure,int minute)
{
    spectateur s;
    int time,r ;
    int timeh;
    timeh=s.blt.heure+1;
    time=s.blt.minute-20;
    s=defiler(&F,s);
    if(((s.blt.date.jj==jour)&&(s.blt.date.mm==mois)&&(s.blt.date.aa==annee))&&(((s.blt.heure==heure)||(s.blt.heure<timeh)||(s.blt.heure<12))&&(s.blt.minute>=time)))
    {
        r=1;
        return r;

    }


    else
    {
        r=0;
         return r;
    }


}

void afficher(File F)
{
    printf("Tete \n");
    printf("\nID : %d \n Numero billet : %d \n Numero salle : %d \n Numero chaise : %d \n Nom film : %s \n Date de Projection : %d/%d/%d \n Heure : %dh%dmin",(F.tete)->spt.ID,(F.tete)->spt.blt.numero,(F.tete)->spt.blt.numero_salle,(F.tete)->spt.blt.numero_chaise,(F.tete)->spt.blt.nom_film,(F.tete)->spt.blt.date.jj,(F.tete)->spt.blt.date.mm,(F.tete)->spt.blt.date.aa,(F.tete)->spt.blt.heure,(F.tete)->spt.blt.minute);
    printf("\n");

    printf("Queue \n");
    printf("\nID : %d \n Numero billet : %d \n Numero salle : %d \n Numero chaise : %d \n Nom film : %s \n Date de Projection : %d/%d/%d \n Heure : %dh%dmin",(F.Queue)->spt.ID,(F.Queue)->spt.blt.numero,(F.Queue)->spt.blt.numero_salle,(F.Queue)->spt.blt.numero_chaise,(F.Queue)->spt.blt.nom_film,(F.Queue)->spt.blt.date.jj,(F.Queue)->spt.blt.date.mm,(F.Queue)->spt.blt.date.aa,(F.Queue)->spt.blt.heure,(F.Queue)->spt.blt.minute);
    printf("\n");
}


void initialiser_tab_liste(liste tab[])
{
    int i;
    for(i=0;i<10;i++)
    {
        tab[i]=0;
    }
}

liste ajout_debut(liste l,spectateur s)
{
    liste nouv=malloc(sizeof(struct cellule));
    if(nouv!=NULL)
    {
        s=saisir_client(s);
        nouv->spt=s;
        nouv->suivant=NULL;
        if(l==NULL)
            l=nouv;

        else
        {
            nouv->suivant=l;
            l=nouv;
        }
    }

    else
        printf("Impossible d'allouer de la memoire \n");

    return l;
}

void ajouter_liste(File *F,liste tab[])
{
    int r;
    int jour,mois,annee,heure,minute;
    spectateur s;
    while(F->tete!=NULL)
    {
            r=validation_billet(*F,jour,mois,annee,heure,minute);
          //initialiser_tab_liste(tab);
           if(r==1)
             {
                  tab[(s.blt.numero_salle)-1]=ajout_debut(tab[(s.blt.numero_salle)-1],s);
             }
      else
        printf("Billet non valide \n");



    }


}

void afficher_liste(liste l)
{
    if(l==NULL)
        printf("liste vide \n");

    liste tmp=l;
    while(tmp!=NULL)
    {
         printf("Liste \n");
         printf("\nID : %d \n Numero billet : %d \n Numero salle : %d \n Numero chaise : %d \n Nom film : %s \n Date de Projection : %d/%d/%d \n Heure : %dh%dmin",tmp->spt.ID,tmp->spt.blt.numero,tmp->spt.blt.numero_salle,tmp->spt.blt.numero_chaise,tmp->spt.blt.nom_film,tmp->spt.blt.date.jj,tmp->spt.blt.date.mm,tmp->spt.blt.date.aa,tmp->spt.blt.heure,tmp->spt.blt.minute);
         printf("\n");
         tmp=tmp->suivant;
    }
}

int nbre_spectateur(liste l)
{
    int nbre=0;
    liste tmp=NULL;
    while(tmp!=NULL)
    {
        nbre++;
        tmp=tmp->suivant;
    }

    return nbre;
}

void afficher_nbre_spectateur(liste tab[])
{

    int i,nbre;
    for(i=0;i<10;i++)
    {
        printf("Salle nimero : %d contient %d spectateurs \n",tab[i]->spt.blt.numero_salle,(nbre=nbre_spectateur(tab[i])));
    }
}

liste trier_liste(liste l)
{
    liste i=l;
    liste j;
    liste min;
    spectateur aux;
    while(i!=NULL)
    {
        min=i;
        j=i->suivant;
        while(j!=NULL)
        {
            if(j->spt.blt.numero_chaise<min->spt.blt.numero_chaise)
                min=j;
        }

        if(i!=j)
        {
            aux=i->spt;
            i->spt=min->spt;
            min->spt=aux;

        }

    }

    return l;
}

void trier_toute_liste(liste tab[])
{

    int i;
    for(i=0;i<10;i++)
    {
       tab[i]=trier_liste(tab[i]);
    }
}


/*
deuxieme vresion

void trier_list(liste l)
{
    int min;
    spectateur aux;
    struct cellule *tmp1,tmp2,tmp3;

    for(tmp1=l;tmp1->suivant!=NULL;tmp1=tmp1->suivant)
    {

        min=tmp1->spt.blt.numero_salle;
        tmp3=tmp1;
        for(tmp2=tmp1->suivant;tmp2!=NULL;tmp2=tmp2->suivant)
        {
            if(tmp2->spt.blt.numero_salle<min)
            {
                min=tmp2->spt.blt.numero_salle;
                tmp3=tmp2;
            }
        }

        aux=tmp1->spt;
        tmp1->spt=tmp3->spt;
        tmp3->spt=aux;
    }
}
*/
