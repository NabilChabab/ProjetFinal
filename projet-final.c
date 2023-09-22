#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Deadline {
    int jj;
    int hh;
    int mm;
};


struct  Todo {
    int id;
    struct Deadline deadline;    
    char Title[100];
    char Description[100];
    int Statut;
};

char Nom[100];
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

void purple(){
    printf("\033[0;35m");
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
        scanf(" %[^\n]", &todo[i].Title);
        printf("Description: ");
        scanf(" %[^\n]", &todo[i].Description);
        printf("Statut: ");
        yellow();
        printf("\n1 ===> Realiser");
        printf("\n2 ===> En Cour de Realisation");
        printf("\n3 ===> Pas Realiser");
        printf("\nTapez votre choix [1-3] : ");
        scanf("%d", &todo[i].Statut);
        reset();
        printf("Deadline: \n");
        printf("Jours : ");
        scanf("%d", &todo[i].deadline.jj);
        printf("Heures : ");
        scanf("%d", &todo[i].deadline.hh);
        printf("Minutes : ");
        scanf("%d", &todo[i].deadline.mm);
        todo[i].id = id;
        id++;
    }
}
int nb = 0;

void Afficher() {
    int i;
    green();
    printf("\n==================================================================================== Your Todo List ====================================================================================\n");
    for (i = 0 ; i < n ; i++) {
        printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
        printf("ID: %d\n", todo[i].id);
        printf("Deadline: %d / %d / %d \n", todo[i].deadline.jj , todo[i].deadline.hh , todo[i].deadline.mm);
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
            if (strcasecmp(todo[i].Title, todo[j].Title) > 0) {
                temp = todo[i];
                todo[i] = todo[j];
                todo[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
        printf("ID: %d\n", todo[i].id);
        printf("Deadline: %d / %d / %d \n", todo[i].deadline.jj , todo[i].deadline.hh , todo[i].deadline.mm);
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

void AfficherDeadline() {
    struct Todo temp;
    int i, j;
    green();
    printf("\n==================================================================================== Your Todo List ====================================================================================\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (todo[i].deadline.jj > todo[j].deadline.jj) {
                temp = todo[i];
                todo[i] = todo[j];
                todo[j] = temp;
            }
            if (todo[i].deadline.jj == todo[j].deadline.jj) {
                if (todo[i].deadline.hh > todo[j].deadline.hh) {
                temp = todo[i];
                todo[i] = todo[j];
                todo[j] = temp;
                }
            }

            if (todo[i].deadline.hh == todo[j].deadline.hh) {
                if (todo[i].deadline.mm > todo[j].deadline.mm) {
                temp = todo[i];
                todo[i] = todo[j];
                todo[j] = temp;
                }
            }
            
            
        }
    }
    for (i = 0; i < n; i++) {
        printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
        printf("ID: %d\n", todo[i].id);
        printf("Deadline: %d / %d / %d \n", todo[i].deadline.jj , todo[i].deadline.hh , todo[i].deadline.mm);
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

void Afficher3jours(){
    struct Todo temp;
    int i;
    green();
    printf("\n==================================================================================== Your Todo List ====================================================================================\n");
        for (i = 0; i < n; i++) {
            if (todo[i].deadline.jj <= 3){
                printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
                printf("ID: %d\n", todo[i].id);
                printf("Deadline: %d / %d / %d \n", todo[i].deadline.jj , todo[i].deadline.hh , todo[i].deadline.mm);
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
            printf("Deadline: %d / %d / %d \n", todo[i].deadline.jj , todo[i].deadline.hh , todo[i].deadline.mm);
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
        if (strcasecmp(todo[i].Title , title) == 0) {
            green();
            printf("======================================================================================= Todo %d =========================================================================================\n",i+1);
            printf("ID: %d\n", todo[i].id);
            printf("Deadline: %d / %d / %d \n", todo[i].deadline.jj , todo[i].deadline.hh , todo[i].deadline.mm);
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
    printf("===================================================================================== Recherche Menu ====================================================================================\n");
    printf("1 ===> Rechercher une tache par son Id");
    printf("\n2 ===> Rechercher une tache par son Titre");
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

void ModifierDescription() {
    int id;

    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &id);

    for (int i = 0 ; i < n; i++) {
        if (todo[i].id == id) {
            
            printf("Entrez la nouvelle description : ");
            scanf(" %[^\n]", todo[i].Description);
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
            printf("Entrez la nouvelle Deadline (jours) : ");
            scanf("%d",&todo[i].deadline.jj);
            green();
            printf("Deadline modifiee avec succes.\n");
            printf("Le nouvelle Deadline est : %d\n",todo[i].deadline.jj);
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
    printf("\n4 ===> Afficher tout les Taches");
    printf("\n========================================================================================================================================================================================");
    printf("\nTapez votre choix [1-3] : ");
    scanf("%d",&choix);

    switch (choix){
        case 1:
            AfficherAlpha();
            break;
        case 2:
            AfficherDeadline();
            break;
        case 3:
            Afficher3jours();
            break;
        case 4:
            Afficher();
            break;    
        default:
            printf("erreur");
            break;    
    }

}

void Statistique(){

    int s = 0;
    int s1 = 0;
    int s2 = 0;

    for (int i = 0 ; i < n ; i++){
        printf("la somme des Taches est : %d\n",n);
        break;
    }

    for (int i = 0; i < n ; i++){
        if (todo[i].Statut == 1){
            s++;
            
        }
    }

    printf("la somme des Taches Realiser  est : %d\n",s);

    for (int i = 0; i < n ; i++){
        if (todo[i].Statut == 3){
            s1++;
           
        }
    }
    
    printf("la somme des Taches Pas Realiser  est : %d\n",s1);

    for (int i = 0; i < n ; i++){
        if (todo[i].Statut == 2){
            s2++;
           
        }
    }
    
    printf("la somme des Taches En Cours de Realisation  est : %d\n",s2); 

    int id;
    printf("Pour Afficher le nombre des jours restent Entrez le Id de la tache : ");
    scanf("%d",&id);

    int localday = 23;   
    int localhour = 10;   
    int localmin = 22;

    int res1;
    int res2;
    int res3;

    for (int i = 0 ; i < n ; i++){
        res1 = localday - todo[i].deadline.jj;
        res2 = localhour - todo[i].deadline.hh;
        res3 = localmin - todo[i].deadline.mm;
    }

    printf("le nombre de jour restent  est : %d / %d / %d \n",res1,res2,res3); 
    
}

void Menu(){


    char ChoixP;
    green();
    printf("Salut!! ===> Entrez Votre Nom : ");
    scanf("%s",&Nom);
        do{
        purple();
        printf("===================================================================================== Welcome Back %s ================================================================================\n",Nom);
        printf("=========================================================================================================================================================================================\n");
        printf("======================================================================================= Todo App ========================================================================================\n");
        printf("=========================================================================================================================================================================================\n");
        printf("========================================================================================= Menu ==========================================================================================\n");
        blue();
        printf("1 ===> Ajouter plusieurs nouvelles taches.");
        printf("\n2 ===> Afficher la liste de toutes les taches");
        printf("\n3 ===> Modifier une tache");
        printf("\n4 ===> Supprimer une tache par identifiant");
        printf("\n5 ===> Rechercher les Taches");
        printf("\n6 ===> Afficher les Statistiques");
        printf("\n7 ===> Quiter");
        yellow();
        printf("\n========================================================================================================================================================================================");
        printf("\nTapez votre choix [1-7] : ");
        scanf("%d",&ChoixP);

        switch (ChoixP){
        case 1:
            AjouterP();
            break;
        case 2:
            trieMenu();
            break;
        case 3:
            Modifier();
            break;
        case 4:
            Supprimer();
            break;
        case 5:
            Rechercher();
            break;
        case 6:
            Statistique();
            break;        
        case 7:
            red();
            printf("See You next Time Bye !!");
            exit(0);
            break;;       
        }
        
    }
    while (ChoixP != 9);
}


int main(){

    Menu();

    return 0;
}
