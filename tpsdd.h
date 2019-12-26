#ifndef __SDD__H__
#define __SDD__H__
#define max 100
// definition du type boolieen
typedef enum
{
	false, //0
	true	//1	
}bool;
/*############################# PARTIE DES PILES ##########################*/
//définition d'une pile
typedef struct stackElement
{
	int value;
	struct stackElement *next;
}stackElement, *stack;

//##prototypes des fonctions##\\
//creation d'une nouvelle pile
stack newStack(void);
//verifier si la pile est vide
bool isEmpty_stack(stack st);
//afficher une pile
void printStack(stack st);
//empiler une valeur 
stack pushStack(stack st, int x);
//depiler une valeur
stack popStack(stack st);
//voir le sommet de la pile
int topStack(stack st);
//voir la taille de la pile
int stackLength(stack st);
//vider la pile
stack clearStack(stack st);
//la menu de travail des piles
void menuStack(void);
/*######################### FIN DE LA PARTIE DES PILES ####################*/
////////////////////////////////////////////////////////////////////////////
/*############################ PARTIE DES LISTES ##########################*/
/*struct de la list*/
typedef struct listElement 
{
	int value;
	struct listElement *next;	
}listElement, *list;
/*Prototypes*/
//creation d'un nouveau elem
list newList(void);
//verifier si la list est vide
bool is_emptyList(list li);
//la langueur de la liste 
int listLength(list li);
//afficher la liste
void printList(list li);
//ajouter une valeur a la fin d'une liste
list pushbackList(list li, int x);
//ajouter une valeur au debut de la liste
list pushFrontList(list li,int x);
//retirer une valeur de la fin
list popBackList(list li);
//detirer une valeur du debut
list popFrontList(list li);
//liquider une liste
list clearList(list li);
//chercher une valeur
bool lookForValue(list li,int x);   // si oui retourne true sinon retourne false
//chercher la valeur de l'indice <index>
void lookValueIndex(list li,int index); // index de la pile commence par un 1
//menu de travail des listes
void menuList(void);
/*######################## FIN DE LA PARTIE DES LISTES ####################*/
/////////////////////////////////////////////////////////////////////////////
/*############################# PARTIE DES FILES ##########################*/
/* Définition de la file */
typedef struct queueElement
{
	int value;
	struct queueElement *next;
}queueElement, *queue;
/* Paramètres de la file */
static queueElement *first = NULL;
static queueElement *last = NULL;
static int nbElement = 0; 
/* Prototypes */
//vérifier si la file est vide
bool is_emptyQueue(void);
//vérifier la length
int queueLength(void);
//retourne le premier elem
int queueFirst(void);
//retourne le dernier elem
int queueLast(void);
//afficher une file
void printQueue(void);
//ajouter un elem
void pushQueue(int x);
//retirer des elem
void popQueue(void);
//liquider la file
void clearQueue(void);
//le menu d'utilisation des files
void menuQueue(void);
/*################### FIN DE LA PARTIE DES FILES ##########################*/
/////////////////////////////////////////////////////////////////////////////
//////////////////// EN TABLEAU //////////////
/*############################# PARTIE DES LISTES ##########################*/
//definition du type de la liste à l'aide de tableau
typedef struct listTElementT
{
	int tab[max];
	int indexLast;
	int nbElement;
}listTElementT, *listT;
/*########Les prototypes des fonctions########*/
//creation d'un nouveau elem
listT newlistT(void);
//verifier si la list est vide
bool is_emptylistT(listT li);
//la langueur de la liste 
int listTLength(listT li);
//afficher la liste
void printlistT(listT li);
//ajouter un elem a la fin d'une liste
listT pushbacklistT(listT li, int x);
//ajouter debut de la liste
listT pushFrontlistT(listT li,int x);
//delistTer un elem de la fin
listT popBacklistT(listT li);
//delistTer un elem du debut
listT popFrontlistT(listT li);
//liquider une liste
listT clearlistT(listT li);
//chercher une valeur
bool lookForValueT(listT li,int x);   // si oui retourne true sinon retourne false
//chercher la valeur de l'indice index
void lookValueIndexT(listT li,int index); // index de la pile commence par un 1
//menu d'utilisation
void menuListT(void);
/*############################# PARTIE DES FILES ##########################*/
//##declaration du type de la file##//
typedef struct queueTElementT
{
	int tab[max];
	int indexLastOne;
	int numberElem;
}queueTElementT, *queueT;
//## les prototypes des fonctions ##//
//initialiser et cree une file
queueT newqueueT(void);
//vérifier si la file est vide
bool is_emptyqueueT(queueT qu);
//vérifier la length
int queueTLength(queueT qu);
//retourne le premier elem
int queueTFirst(queueT qu);
//retourne le dernier elem
int queueTLast(queueT qu);
//afficher une file
void printqueueT(queueT qu);
//ajouter un elem
void pushqueueT(queueT qu,int x);
//retirer des elem
void popqueueT(queueT qu);
//liquider la file
void clearqueueT(queueT qu);
//le menu d'utilisation
void menuQueueT(void);
/*############################# PARTIE DES PILES ##########################*/
// la definition de la structure de la pile à l'aide des tableaux
typedef struct stackTElementT
{
	int tab[max];
	int indexSommet;
}stackTElementT, *stackT;
/* Les prototypes des fonctions */
//creation et initialisation d'une nouvelle pile
stackT newstackT(void);
//verifier si la pile est vide
bool isEmpty_stackT(stackT st);
//afficher la pile
void printstackT(stackT st);
//empiler la pile
stackT pushstackT(stackT st, int x);
//depiler la pile
void popstackT(stackT st);
//retourner le sommet  de la pile
int topstackT(stackT st);
// retourner la taille de la pile
int stackTLength(stackT st);
//vider une pile
void clearstackT(stackT st);
void menuStackT(void);
///////////////  FIN  ///////////////////
// fonction pour l'ensemble du programme   /////////////////////////////////
void choix(void);
//////////////////////////////////////////////////////////////////////////
#endif