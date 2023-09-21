#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Todo {
    int id;
    char deadline[100];
    char Title[100];
    char Description[100];
    int Statut;
};


int n;
int id = 1;
int statut = 0;
struct Todo todo[100];


void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}
void blue(){
    printf("\033[0;34m");
}
void green(){
    printf("\033[0;32m");
}


void AjouterP(){
    reset();
    printf("================================================================================== Ajouter une Tache ====================================================================================\n");
    int i;

    printf("Entrez nombre des tachs: ");
    scanf("%d",&n);

    for (i = 0; i < n ; i++) {
        yellow();
        printf("Entrez tache %d detaills:\n", i+1);  
        reset();      
        printf("Title: ");
        scanf(" %29[^\n]", &todo[i].Title);
        printf("Description: ");
        scanf(" %29[^\n]", &todo[i].Description);
        printf("Statut: ");
        yellow();
        printf("\n1 ===> Realiser");
        printf("\n2 ===> En Cour de Realisation");
        printf("\n3 ===> Pas Realiser");
        printf("\nTapez votre choix [1-3] : ");
        scanf("%d", &todo[i].Statut);
        reset();
        printf("Deadline: ");
        scanf(" %29[^\n]", &todo[i].deadline);
        todo[i].id = id;
        id++;
    }
}
void AjouterN(){

    int i;
    n = 1;
    for (i = 0; i < n ; i++) {
        printf("Entrez une tache detaills:\n", i+1);
        printf("Title: ");
        scanf(" %29[^\n]", &todo[i].Title);
        printf("Description: ");
        scanf(" %29[^\n]", &todo[i].Description);
        printf("Statut: ");
        scanf(" %29[^\n]", &todo[i].Statut);
        printf("Deadline: ");
        scanf(" %29[^\n]", &todo[i].deadline);
    }
    
}
void Afficher() {
    int i;
    green();
    printf("\n==================================================================================== Your Todo List ====================================================================================\n");
    for (i = 0 ; i < n ; i++) {
        printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
        printf("ID: %d\n", todo[i].id);
        printf("Deadline: %s\n", todo[i].deadline);
        printf("Title: %s\n", todo[i].Title);
        printf("Description: %s\n", todo[i].Description);
        if (todo[i].Statut == 1){
            printf("Statut : Realiser\n");        
        }
        else if (todo[i].Statut == 2){
            printf("Statut : En Cours de Realisation\n");
        }
        else if (todo[i].Statut == 3){
            printf("Statut : Pas Realiser\n");
        }
        
    }
}
void AfficherAlpha() {
    struct Todo temp;
    int i, j;
    green();
    printf("\n==================================================================================== Your Todo List ====================================================================================\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(todo[i].Title, todo[j].Title) > 0) {
                temp = todo[i];
                todo[i] = todo[j];
                todo[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("======================================================================================= Todo %d =========================================================================================\n", i + 1);
        printf("ID: %d\n", todo[i].id + i);
        printf("Deadline: %s\n", todo[i].deadline);
        printf("Title: %s\n", todo[i].Title);
        printf("Description: %s\n", todo[i].Description);
        printf("Statut: %s\n", todo[i].Statut);
    }
}

void Supprimer(){
    int id, i , j;
    printf("Entrez le ID que tu doit supprimer : ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (todo[i].id == id) {
            todo[i] = todo[n-1];
            printf("Done!!!!!!!!!\n");
            n--;
            break;
        }
    }            
    
}

void RecherchId(){
    int id;

    printf("Entrez l'ID de la tache a Rechercher : ");
    scanf("%d", &id);

    for (int i = 0 ; i < n; i++) {
        if (todo[i].id == id) {
            green();
            printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
            printf("ID: %d\n", todo[i].id);
            printf("Deadline: %s\n", todo[i].deadline);
            printf("Title: %s\n", todo[i].Title);
            printf("Description: %s\n", todo[i].Description);
            if (todo[i].Statut == 1){
                printf("Statut : Realiser\n");
            }
            else if (todo[i].Statut == 2){
                printf("Statut : En Cours de Realisation\n");
            }
            else if (todo[i].Statut == 3){
                printf("Statut : Pas Realiser\n");
            }
        }
    }
}

void RecherchTitre(){
    char title[100];

    printf("Entrez le Titre de la tache a Rechercher : ");
    scanf("%s", &title);

    for (int i = 0 ; i < n; i++) {
        if (strcmp(todo[i].Title , title) == 0) {
            green();
            printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
            printf("ID: %d\n", todo[i].id);
            printf("Deadline: %s\n", todo[i].deadline);
            printf("Title: %s\n", todo[i].Title);
            printf("Description: %s\n", todo[i].Description);
            if (todo[i].Statut == 1){
                printf("Statut : Realiser\n");        
            }
            else if (todo[i].Statut == 2){
                printf("Statut : En Cours de Realisation\n");
            }
            else if (todo[i].Statut == 3){
                printf("Statut : Pas Realiser\n");
            }
        }
    }
}

void Rechercher(){

    int choix;

    printf("=========================================================================================================================================================================================\n");
    printf("===================================================================================== Modification Menu =================================================================================\n");
    printf("1 ===> Rechercher une tache par son Id");
    printf("\n2 ===> Rechercher une tâche par son Titre");
    printf("\n========================================================================================================================================================================================");
    printf("\nTapez votre choix [1-3] : ");
    scanf("%d",&choix);

    switch (choix){
        case 1:
            RecherchId();
            break;
        case 2:
            RecherchTitre();
            break;
        default:
            printf("erreur");
            break;    
    }
    
}
void Statistique(){
    
}

void ModifierDescription() {
    int id;

    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &id);

    for (int i = 0 ; i < n; i++) {
        if (todo[i].id == id) {
            
            printf("Entrez la nouvelle description : ");
            scanf("%s", todo[i].Description);
            green();
            printf("Description modifiee avec succes.\n");
            printf("La nouvelle Description est : %s\n",todo[i].Description);
        }
    }
}
void ModifierStatut() {
    int id;

    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (todo[i].id == id) {
            green();
            printf("\n1 ===> Realiser");
            printf("\n2 ===> En Cour de Realisation");
            printf("\n3 ===> Pas Realiser");
            printf("\nEntrez la nouvelle Statut : ");
            scanf("%d",&todo[i].Statut);
            if (todo[i].Statut == 1){
                printf("Statut : Realiser\n");        
            }
            else if (todo[i].Statut == 2){
                printf("Statut : En Cours de Realisation\n");
            }
            else if (todo[i].Statut == 3){
                printf("Statut : Pas Realiser\n");
            }
            printf("Statut modifiee avec succes.\n");
        }
    }
    
}
void ModifierDeadline() {
    int id;

    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &id);

    

    for (int i = 0; i < n; i++) {
        if (todo[i].id == id) {
            printf("Entrez la nouvelle Deadline : ");
            scanf("%s", todo[i].deadline);
            green();
            printf("Deadline modifiee avec succes.\n");
            printf("Le nouvelle Deadline est : %s\n",todo[i].deadline);
        }

    }
}

void Modifier(){
    int choix;

    printf("=========================================================================================================================================================================================\n");
    printf("===================================================================================== Modification Menu =================================================================================\n");
    printf("1 ===> Modifier la description");
    printf("\n2 ===> Modifier le Statut");
    printf("\n3 ===> Modifer Deadline");
    printf("\n========================================================================================================================================================================================");
    printf("\nTapez votre choix [1-3] : ");
    scanf("%d",&choix);

    switch (choix){
        case 1:
            ModifierDescription();
            break;
        case 2:
            ModifierStatut();
            break;
        case 3:
            ModifierDeadline();
            break;
        default:
            printf("erreur");
            break;    
    }
}


void trieMenu(){

    int choix;

    printf("=========================================================================================================================================================================================\n");
    printf("========================================================================================= Trie Menu =====================================================================================\n");
    printf("1 ===> Trier les taches par ordre alphabetique");
    printf("\n2 ===> Trier les taches par deadline");
    printf("\n3 ===> Afficher les taches dont le deadline est dans 3 jours ou moins");
    printf("\n========================================================================================================================================================================================");
    printf("\nTapez votre choix [1-3] : ");
    scanf("%d",&choix);

    switch (choix){
        case 1:
            AfficherAlpha();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("erreur");
            break;    
    }

}

void Menu(){


    char ChoixP;

        do{
        red();
        printf("===================================================================================== Welcome Back ======================================================================================\n");
        printf("=========================================================================================================================================================================================\n");
        printf("======================================================================================= Todo App ========================================================================================\n");
        printf("=========================================================================================================================================================================================\n");
        printf("========================================================================================= Menu ==========================================================================================\n");
        blue();
        printf("1 ===> Ajouter une nouvelle tache");
        printf("\n2 ===> Ajouter plusieurs nouvelles taches.");
        printf("\n3 ===> Afficher la liste de toutes les taches");
        printf("\n4 ===> Modifier une tache");
        printf("\n5 ===> Supprimer une tache par identifiant");
        printf("\n6 ===> Rechercher les Taches");
        printf("\n7 ===> Statistiques");
        printf("\n8 ===> Quiter");
        yellow();
        printf("\n========================================================================================================================================================================================");
        printf("\nTapez votre choix [1-7] : ");
        scanf("%d",&ChoixP);

        switch (ChoixP){
        case 1:
            AjouterN();
            break;
        case 2:
            AjouterP();
            break;
        case 3:
            Afficher();
            break;
        case 4:
            Modifier();
            break;
        case 5:
            Supprimer();
            break;
        case 6:
            Rechercher();
            break;
        case 7:
            Statistique();
            break;  
        case 8:
            printf("See You next Time Bye !!");
            exit(0);
            break;;       
        }
        
    }
    while (ChoixP != 7);
}


int main(){

    Menu();

    return 0;
}
