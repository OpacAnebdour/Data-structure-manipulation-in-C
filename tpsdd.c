#include <stdio.h>
#include <stdlib.h>
#include "tpsdd.h"

/*############################# PARTIE DES PILES ##########################*/
/**
newStack : fonction pour crer er initialiser une pile
*@param : void , rien
*@return : stack , le type de la pile initialiser et vide
on concidére que une pile nouvelle pile initialiser veut dire NULL 
*/
stack newStack(void)
{
	return NULL;
}
/**
isEmpty_stack : fonction pour verifier si une pile est vide ou non
*@param : stack , le type de la pile de travail qu'on veut tester
*@return : bool , le type declarer booliéen true si la pile est vide et false sinon
*/
bool isEmpty_stack(stack st)
{
	if(st == NULL)
		return true;
	return false;
}
/**
pushStack : fonction pour ajouter ou empiler une valeur dans la pile
*@param : stack, int : le type de la pile de travail et l'entier qu'on veut empiler
*@return : stack , la pile finale avec la valeur empiler
on cree un nouveau element dont on va inserer la valeur puis en le pointe sur la pile de
base pour qu'elle devient la suite
*/
stack pushStack(stack st, int x)
{
	stackElement *element; // creation de l'element avec l'allocation dynamic et la teste sur l'allocation

	element = malloc(sizeof(*element));
	if(!element){
		fprintf(stderr, "\n Problem of dynamic location \n");
		exit(EXIT_FAILURE);
	}
	element->value = x;	// insertion de l'entier dans la cellule element
	element->next = st; // pointer l'element sur la pile initiale 

	return element; // retourner la nouvelle pile
}
/**
popStack : fonction pour depiler une valeur de la pile
*@param : stack, le type de la pile qu'on veut depiler
*@return : stack , la pile finale avec une valeur depiler
on cree un nouveau element puis on lui affecter la suite du 1er element de pile de base
*/
stack popStack(stack st)
{
	stackElement *element;  // creation d element

	if(isEmpty_stack(st)) // tester si la pile est deja vide
		return newStack();
	element = st->next; // affectation de la suite du 1er element de la pile de base à l'element
	free(st); // liberer la pile initiale
	st=NULL; // assurer la liberation
	return element; // retourner la nouvelle pile depiler
}
/**
clearStack : fonction pour razer ou vider une pile
*@param stack : le type de la pile de travail 
*@return stack : la pile razée
on utilise la recurssevité on parcour la pile on liberant la place memoire du premier element apres avoir stocker 
la suite dans un nouveau element qu'on a deja cree
*/
stack clearStack(stack st)
{
	stackElement *element;   // creation de l'element pour recuperer la suite du 1er element
	if(isEmpty_stack(st)) // si la pile est deja vide
		return newStack();

	element = st->next; // sauvgarder la suite du 1er element pour la recurssivité
	free(st); // liberer la place memoire
	st=NULL;
	return clearStack(element); //retourner la fonction avec la suite de la pile de base comme param 
}
/**
printStack : fonction pour afficher une pile
*@param : stack, le type de la pile de travail
*@return : void , rien car on va tout afficher
*/
void printStack(stack st)
{
	if(isEmpty_stack(st)){   // la cas de la pile est vide
		printf("\n [ ] \n");
		return;
	}
	while(!isEmpty_stack(st)){
		printf("[%d]\n",st->value);
		st = st->next;
	}
}
/**
topStack : une fonction qui donne le sommet d'une pile
*@param : stack, le type de la pile de travail
*@return : int , un entier qui represente le sommet d'une pile
*/
int topStack(stack st)
{
	if(isEmpty_stack(st)) // le cas ou la pile est vide
		printf("\n il y a pas de sommet car la pile est vide \n");
	return st->value;
}
/**
stackLength : une fonction qui donne la taille d'une pile
*@param : stack, le type de la pile de travail
*@return : int , un entier qui represente la taille d'une pile
tant que la pile n'est pas vide on la parcourant on fait taille + 1
*/
int stackLength(stack st)
{
	int length = 0; // entier represente la taille de la pile
	while(!isEmpty_stack(st)){
		length++;
		st = st->next;
	}
	return length;
}
void menuStack(void)
{
	bool quit = true;
	stack sta;
	while(quit){
		printf("\n 0 : Changer la SDD\n");
		printf("\n 1 : Creation d'une pile\n");
		printf("\n 2 : Verifier si la pile est vide \n");
		printf("\n 3 : Afficher une pile\n");
		printf("\n 4 : Ajouter une valeur a la pile\n");
		printf("\n 5 : Depiler une pile\n");
		printf("\n 6 : Le sommet de la pile\n");
		printf("\n 7 : La taille de la pile\n");
		printf("\n 8 : Liquider une pile\n");
		printf("\n 99 : Quitter le programme\n");
		int i;
		printf("\n Entrez votre choix : \n");
		scanf("%d",&i);
			if(i == 0){
				system("cls");
				choix();
			}
			if(i == 1){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				sta = newStack();
				printf("\n La pile est ete bien cree \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 2){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(isEmpty_stack(sta))
					printf("\n la pile est vide \n");
				else
					printf("\n la pile est non vide \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 3){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printStack(sta);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 4){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				sta = pushStack(sta,x);
				printf("\n La valeur %d a ete bien empiler... \n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 5){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				sta = popStack(sta);
				printf("\n la 1ere valeur a ete depiler \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 6){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est le sommet [%d]",topStack(sta));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 7){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est la taille [%d]",stackLength(sta));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 8){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				sta = clearStack(sta);
				printf("\n la pile est totalment liquider \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if( i == 99){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("\n Merci d avoir utilise ce programme :) a+ \n");
				printf("\n");
				printf("\n--------------------------------\n");
				quit = false;
			}				
	}
}
/*######################### FIN DE LA PARTIE DES PILES ####################*/
////////////////////////////////////////////////////////////////////////////
/*############################ PARTIE DES LISTES ##########################*/
/**
newList : une fonction qui retourne une liste initialisé
* @param : void, elle ne prend rien comme parametre
* @retrun : NULL  on considere que le NULL veut dire une liste initialiser
*/
list newList(void)
{
	return NULL;
}
/**
is_emptyList : une fonction qui vérifie si le liste est vide ou non
* @param : list, elle prend comme parametre un type "list" la liste de travail
* @return : la fonction retourne true si la liste est vide et false si non
*/
bool is_emptyList(list li)
{
	if(li == NULL) //si li egale à NULL alors elle est initialiser y a rien là de dans
		return true; // elle est vide
	return false; // elle est non vide
}
/**
listLength : une fonction qui retourne la taille d'une liste
*@param : list, elle prend comme parametre le type "list" la liste de travail
*@return : int, retourne la taille de liste
tand que la liste n'egale pas au NULL on continu a parcourir la liste on incrementant
le int "size" initialiser à 0
*/
int listLength(list li)
{
	int size = 0;
	if(!is_emptyList(li))
	{
		while(li != NULL){
			++size;
			li = li->next;
		}
	}	
	return size;
}
/**
printList : une fonction qui affiche la liste
* @param : list, le type de liste cette la liste qu'on veut afficher
* @return : void, elle retourne rien puisque on veut juste afficher la liste
si la liste est vide on affiche une case vide, sinon tant qu'il y a des elements 
dans la liste on les affiche un par un 
*/
void printList(list li)
{
	// le cas oû la liste est vide
	if(is_emptyList(li)){
		printf("[ ]\n");
		return;
	}
	// si la liste n'est pas vide
	while(li != NULL){
		printf("[%d]->",li->value);
		li = li->next; // passage au suivant pour l'afficher jusqu'a trouvé le NULL
	}
	printf("\n");
}
/**
pushbackList : une fonction qui permet d'ajouter un element à la fin de la liste
* @param : list && int , le type list celui de la liste de travail et un int la valeur
qu'on veut ajouter à la fin de la liste
* @return : list , le type list de la liste aprés l'ajoute de la valeur à la fin
on cree un element de la liste on insert le int x puis on parcours la liste jusqu'a
arriver à la fin de liste puis on ajoute notre element à la fin pour retourner la liste finale
*/
list pushbackList(list li, int x)
{
	//creation de l'element pour inserer le x
	listElement *element;
	element = malloc(sizeof(*element));
	//tester la allocation dynamic est bien passé
	if(element==NULL){
		fprintf(stderr, "Problem dynamic allocation\n");
		exit(EXIT_FAILURE);
	}
	//inserer le x dans l'element et pointer le suivant sur le NULL pour la fin de la liste
	element->value = x;
	element->next = NULL;
	//la cas ou il y a rien dans la liste on retourne notre element avec le x
	if(is_emptyList(li))
		return element;
	//cree un poiteur pointé sur le liste pour ne pas perdre l'information
	listElement *tmp;
	tmp = li;
	//parcourir la liste jusqu'a l'arriver à la fin de liste 
	while(tmp->next != NULL )
		tmp = tmp->next;
	//mettre l'element à la fin de liste pour qu'il devient la queue de la liste
	tmp->next = element;

	return li; 
}
/**
pushFrontList : une fonction pour ajouter une valeur à la tête de la liste
*@param : list, int : le type de la liste de travail et une valeur entier qu'on veut ajouter
*@return : list , la liste finale qui contient la valeur inserer au debut
on cree un element de la liste on insert le int x puis on le pointe sur la liste 
pour qu'il soit la tête de la liste puis on retourner la liste finale
*/
list pushFrontList(list li,int x)
{
	//creation de l'element pour inserer le x
	listElement *element;
	element = malloc(sizeof(*element));
	//tester la allocation dynamic est bien passé
	if(element==NULL){
		fprintf(stderr, "Problem dynamic allocation\n");
		exit(EXIT_FAILURE);
	}
	//inserer le x dans l'element
	element->value = x;
	// le cas oû la liste est vide on pointe notre zlzmznt sur NULL càd la tête de la liste
	if(is_emptyList(li))
		element->next=NULL;
	else //sinon on le point sur la liste initiale pour devenir sa tête 
		element->next=li;

	return element;
}
/**
popBackList : fonction pour supprimer une valeur de la fin de la liste
* @param : list, c'est la liste de travail dont on veut supprimer une valeur de sa fin
* @return : list , c'est la liste finale apres la suppression de la valeur à la fin
on parcours la liste jusqu'a l avant dernier element puis on casse la liaison avec cette element
*/
list popBackList(list li)
{
	//le cas oû la liste est vide
	if(is_emptyList(li))
		return newList();
	//le cas oû la liste contient un seul element
	if(li->next == NULL){
		free(li);
		li = NULL;
		return newList();
	}

	listElement *tmp = li;
	listElement *avant = li;
	// parcourir la liste jusqu'a l'avant dernier element
	while(tmp->next != NULL){
		avant = tmp;   // sauvgarder tmp
		tmp = tmp->next;
	}
	avant->next = NULL; //lier l'avant dernier element avec le NULL
	free(tmp); // liberer le dernier element
	tmp=NULL; // assurer la liberation du dernier element
	return li;
}
/**
popFrontList : fonction pour supprimer une valeur au debut de la liste
* @param : list, c'est la liste de travail dont on veut supprimer une valeur du debut
* @return : list , c'est la liste finale apres la suppression de la valeur du debut
on cree un nouveau element de la liste puis on lui affecte la suite du premier element de la liste
de base on la sauvgardant puis on libere ce dernier
*/
list popFrontList(list li)
{
	if(is_emptyList(li)) // le cas oû la pile est vide
		return newList();

	listElement *element; // creation de l'element de travail

	element = malloc(sizeof(*element)); // la allocation dynamic avec le teste qu'elle a ete bien passe

	if(element==NULL){
		fprintf(stderr, "Problem dynamic allocation\n");
		exit(EXIT_FAILURE);
	}
	element = li->next; //affectation de la suite du 1er element de la liste au nouveau element
	free(li); // liberer le premier element de la liste qui contient le 1er element 
	li = NULL; //assurer la liberation

	return element;  //retourner l'element qui contient la suite du 1er element de la liste de base
}
/**
clearList : fonction qui raze tous les element de la liste
* @param : list, le type de la liste dont on veut supprimer tous les elements
* @return : list , la liste vide
on parcour toute la liste tant qu'il y a des element on utilise la fonction de suppression de front qui est 
plus simple on doit pas parcourir toute la liste pour supprimer le dernier element
*/
list clearList(list li)
{
	if(is_emptyList(li))  // si la liste est deja vide
		return newList();

	while(li != NULL){   // parcour de la liste on supprimant tous les elements
		li = popFrontList(li);
	}  // on retourne rien ici car le retour se trouve dans la fonction popFrontList(li)
}
/**
lookForValue : fonction qui permet de voir si une valeur existe dans la liste ou pas
* @param : list, int : le type de la liste de travail et un entier la valeur cherché
* @return : bool, type definie comme un boulienne true si la valeur trouvé et false sinon
on parcours la liste jusqu'a trouver le NULL on testant la value avec l'entier si elles sont égales
on retourne true sinon false
*/
bool lookForValue(list li,int x)
{
	// si la liste est vide
	if(is_emptyList(li)){
		//printf("\n la liste est vide \n");
		return false;
	}
	// cree une liste pour ne pas toucher à la liste de base
	listElement *crt=NULL;
	crt = li;
	while(crt->next != NULL){  // parcour de la liste avec NULL le teste d'arrete
		if(crt->value == x){
			//printf("Value exsist\n");
			return true;
		}
		crt = crt->next;
	}
	return false;
}
/**
lookValueIndex : c'est une fonction donne la valeur qui se trouve dans une position donnée
* @param : list, int : le type de la liste de travail et un entier la position donnée
* @return : void , rien car on affiche tout
on parcours la liste jusqu'a passer le nombre d'element egale a la position qu'on veut 
puis on l'affiche
*/
void lookValueIndex(list li,int index)  // index de la liste commence par un 1
{
	int indice=1;
	if(is_emptyList(li)) // la liste est vide
		printf("la liste est vide\n");
	
	while(indice != index){
		if(li == NULL){
			printf("\n La position est impossible \n"); // le cas d'une position impossible
			exit(EXIT_FAILURE);							//  > à la taille de la liste par exemple						
		}

		li = li->next;
		indice++;
	}
	printf("La valeur qui se trouve a la position %d est %d\n",index,li->value);
}
void menuList(void)
{
	bool quit = true;
	list li;
	while(quit){
		printf("\n 0 : Changer la SDD\n");
		printf("\n 1 : Creation d'une liste\n");
		printf("\n 2 : Verifier si la liste est vide \n");
		printf("\n 3 : Afficher la taille de la liste\n");
		printf("\n 4 : Afficher la liste\n");
		printf("\n 5 : Ajouter une valeur a la fin\n");
		printf("\n 6 : Ajouter une valeur au debut\n");
		printf("\n 7 : retirer une valeur de la fin\n");
		printf("\n 8 : retirer une valeur du debut\n");
		printf("\n 9 : vider la liste totalment\n");
		printf("\n 10 : Chercher une valeur dans la liste\n");
		printf("\n 11 : Chercher une valeur a un index dans la liste pile \n");
		printf("\n 99 : Quitter le programme\n");
		int i;
		printf("\n Entrez votre choix : \n");
		scanf("%d",&i);
			if(i == 0){
				system("cls");
				choix();
			}
			if(i == 1){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = newList();
				printf("\n La liste a ete cree ...\n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 2){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(is_emptyList(li))
					printf("\n la liste est vide \n");
				else
					printf("\n la liste est non vide \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 3){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("La taille de cette liste est : (%d)",listLength(li));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 4){
				system("cls");
				printf("\n-----------------------------------\n");
				printf("\n");
				printList(li);
				printf("\n");
				printf("\n------------------------------------\n");
			}
			if(i == 5){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = pushbackList(li, x);
				printf("La valeur (%d) a ete ajouter au la fin avec succes\n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 6){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = pushFrontList(li, x);
				printf("La valeur (%d) a ete ajouter au debut avec succes\n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 7){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = popBackList(li);
				printf("\n la valeur a la fin a ete retirer avec succes \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 8){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = popFrontList(li);
				printf("\n la valeur au debut a ete retirer avec succes \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 9){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = clearList(li);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 10){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("\n Entrez la valeur que vous voullez verifer l existance : ");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(lookForValue(li, x))
					printf("\n La valeur %d existe dans la liste \n",x);
				else
					printf("\n La valeur %d N EXISTE PAS dans la liste\n",x);
				printf("\n");
				printf("\n---------------------------------\n");
			}
			if(i == 11){
				system("cls");
				printf("\n----------------------------------------\n");
				printf("\n");
				int x;
				printf("\n Entrez l index dont vous voullez voir la valeur :  ");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				lookValueIndex(li, x);
				printf("\n");
				printf("\n-------------------------------------------\n");
			}
			if( i == 99){
				system("cls");
				printf("\n Merci d avoir utilise ce programme a+ :) \n");
				quit = false;
			}				
	}
}
/*######################## FIN DE LA PARTIE DES LISTES ####################*/
/////////////////////////////////////////////////////////////////////////////
/*############################# PARTIE DES FILES ##########################*/
/**
is_emptyQueue : fonction qui verifie si la file est vide ou non 
*@param : void , car la file est deja cree au niveau des paramètres
*@return bool , type boolieen 
si la tete egal a la queue alors la pile est vide donc on retourne true et false sinon
*/
bool is_emptyQueue(void)
{
	if(first == NULL && last == NULL)
		return true;

	return false;
}
/**
queueLength : fonction qui donne la taille de la file
*@param : void : car la file est deja cree au niveau des paramètres
*@return : int ,  entier represente la taille de la file
on a deja fait une variable nnElement qui represente le nombre de cellule dans cette file
*/
int queueLength(void)
{
	return nbElement;
}
/**
queueFirst : fonction qui retourne la tête 
*@param : void, car la file est deja cree au niveau des paramètres
*@return : int , retourne la valeur de l'element de la tête
*/
int queueFirst(void)
{
	if(is_emptyQueue()) // le cas ou la file est vide
		printf("\n Impossibe car la file est vide \n");
	return first->value;
}
/**
queueLast : fonction qui retourne la queue 
*@param : void, car la file est deja cree au niveau des paramètres
*@return : int , retourne la valeur de l'element de la queue
*/
int queueLast(void)
{
	if(is_emptyQueue()) // le cas ou la file est vide
		printf("\n Impossibe car la file est vide \n");
	return last->value;
}
/**
printQueue : fonction qui affiche la file
*@param : void, car la file est deja cree au niveau des paramètres
*@return : void, car on va tout afficher
on cree un nouveau element et on lui affecte la tête de la file puis on parcours la file jusqu a le
dernier element on les affichant
*/
void printQueue(void)
{
	if(is_emptyQueue()){
		printf("\n [ ] \n");
		return;
	}
	queueElement *tmp = first;  // creation d'un nouveau element et affectation de la tête de la file
	while(tmp != NULL){
		printf("[%d] ",tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
pushQueue : fonction pour enfiler une valeur
*@param : int, un entier la valeur qu'on veut inserer
*@return :void
on cree un element dans le quel on va inserer la valeur qu'on veut ajouter à la file puis on pointe vers
lui le suivant de la cellule last pour devenir la fin de la file
*/
void pushQueue(int x)
{
	// creation du nouveau element avec l'allocation et son teste
	queueElement *element;
	element=malloc(sizeof(*element));

	if(element == NULL){
		fprintf(stderr, "\n Error :dynamic allocation problem \n");
		exit(EXIT_FAILURE);
	}
	element->value = x;  // insertion de la valeur x dans la cellule
	element->next = NULL; // pointer son suivant vers le NULL

	if(is_emptyQueue()){  // le cas de la file est vide dans on doit avoir un seul element
		first = element;
		last = element;
	}
	else{     // sinon
		last->next = element;
		last = element;
	}
	nbElement++;  // incrementation de nbElement pour les nombre des elements de la file
}
/**
popQueue : fonction qui defile une valeur
*@param : void, tout se passe au niveau des parametre de la structure de donnée
*@param : void, tout se passe au niveau des parametre de la structure de donnée
on cree une nouvelle cellule en lui affectant la tête de la file pour liberer sa place memoire
puis on pointe la nouvelle tê^te vers l'element suivant 
*/
void popQueue(void)
{
	if(is_emptyQueue()){
		printf("\n rien a retirer, la file est vide. \n");
		return;
	}
	queueElement *tmp = first;  // creation d'un element qui reçoit la tete pour le liberer par la suite
	if(first == last){
		first = NULL;
		last = NULL;
	}
	else
		first = first->next; // affecter la tete à la nouvelle tete qui a ete le suivant de l'ancienne tete

	free(tmp); // liberer la place memoire
	tmp=NULL;  // assurer la liberation
	nbElement--; // decrementer le nembre d'element de la file
}
/**
clearQueue : fonction pour vider une file
*@param : void
*@param : void
tant qu'il y a pas d'element on utilise la fonction de défilement
*/
void clearQueue(void)
{
	if(is_emptyQueue()){  // le file est deja vide
		printf("\n rien a liquider \n");
		return;
	}
	while(!is_emptyQueue())  // la file est non vide
		popQueue();
}
void menuQueue(void)
{
	bool quit = true;
	queueElement *queu;
	while(quit){
		printf("\n 0 : Changer la SDD \n");
		printf("\n 1 : Verifier si la file est vide\n");
		printf("\n 2 : La taille de la file \n");
		printf("\n 3 : Afficher le 1er elem de la file\n");
		printf("\n 4 : Afficher le dernier elem de la file\n");
		printf("\n 5 : Afficher la file \n");
		printf("\n 6 : enfiler une valeur\n");
		printf("\n 7 : depiler une valeur\n");
		printf("\n 8 : Liquider une pile\n");
		printf("\n 99 : Quitter le programme\n");
		int i;
		printf("\n Entrez votre choix : \n");
		scanf("%d",&i);
			if(i == 0){
				system("cls");
				choix();
			}
			if(i == 1){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(is_emptyQueue())
					printf("\n la file est vide \n");
				else
					printf("\n la file est non vide \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 2){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est la taille [%d]",queueLength());
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 3){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est le 1ere valeur [%d]",queueFirst());
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 4){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est le dernier valeur [%d]",queueLast());
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 5){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printQueue();
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 6){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				pushQueue(x);
				printf("\n La valeur %d a ete enfiler... \n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 7){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				popQueue();
				printf("\n la file est defile \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 8){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				clearQueue();
				printf("\n la pile est totalment liquider \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if( i == 99){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("\n Merci d avoir utilise ce programme :) a+ \n");
				quit = false;
				printf("\n");
				printf("\n--------------------------------\n"); 	
			}				
	}
}
//////////////////// PARTIE DES LISTE EN TABLEAU //////
/**
newlistT : fonction pour cree et initialiser la liste
*@param : void
*@return : listT, la liste cree initialiser  
*/
listT newlistT(void)
{
	listT element; // creation d'un nouveau element
	element = malloc(sizeof(element)); // allocation dynamic

	if(!element){  // teste sur l'allocation dynamic
		printf("\nERROR ALLOCATION DYNAMIC\n");
		exit(EXIT_FAILURE);
	}
	element->indexLast = -1; 
	element->nbElement = 0;

	return element;
}
/**
is_emptylistT : fonction pour verifier si la liste est vide 
*@param : listT , la liste de travail
*@return : bool, type declarer boolieen true si la liste est vide et false sinon
*/
bool is_emptylistT(listT li)
{
	if(li->nbElement == 0) 
		return true;
	return false;
	//li->nbElement==0 ? return true : return false;
}
/**
listTLength : fonction qui retourne la taille de la liste
*@param : listT : la liste de travail
*@return : int : la taille de la liste
*/
int listTLength(listT li)
{
	return li->nbElement;
}
/**
printlistT : fonction pour afficher une liste
*@param : listT , la liste de travail
*@return : void , rien on va tout afficher
on parcours la liste tant qu'on a pas arrive a la fin de la liste on les affiche 1 par 1
*/
void printlistT(listT li)
{
	if(is_emptylistT(li)){ // la pile est vide
		printf("\n[ ]\n");
	}
	for(int i=0;i<=li->indexLast;printf("[%d] ",li->tab[i++]));
} 
/**
pushbacklistT : fonction pour ajouter un element à la fin de la liste 
*@param : listT int : la liste de travail et une valeur entier qu'on veut ajouter
*@return : listT ; la liste finale avec la valeur ajouter à la fin
*/
listT pushbacklistT(listT li, int x)
{
	if(is_emptylistT(li)){
		li->indexLast++;
		li->nbElement++;
		li->tab[0] = x;
		return li;
	}
	if(li->nbElement <= max){
		li->indexLast++;
		li->nbElement++;
		li->tab[li->indexLast] = x;
	}
	else
		printf("\n Error la liste est sature \n");	
	return li;
} 
/**
pushFrontlistT
*@param : listT, int: la liste de travail et un entier qu'on veut ajouter au debut de la liste
*@return : listT , la liste finale avec l'entier ajouter à la tête de la liste
on cree une cellule à la fin de la liste puis on fait déplacement de l'ensemble des valeurs des
autres cellule pour vider la 1ere valeur dans laquel on insert notre entier
*/
listT pushFrontlistT(listT li,int x)
{
	if(is_emptylistT(li)){ // le cas ou la liste est vide
		li->indexLast++;
		li->nbElement++;
		li->tab[0] = x;
		return li;
	}  // la cas ou la liste est non vide
	li->indexLast++;
	li->nbElement++;
	// deplacement des elements d'un rang vers la fin de la liste pour vider la 1ere place 
	for(int i=li->indexLast;i >=-1;i--){
		li->tab[i+1] = li->tab[i];
	}
	li->tab[0] = x; // puis inserer l'entier
	return li;
}
/**
popBacklistT : une fonction pour supprimer une valeur à la fin de la liste 
*@param : listT, la liste de travail
*@return : listT, la liste finale avec la derniere valeur supprimé 
*/
listT popBacklistT(listT li)
{
	if(is_emptylistT(li))  // la cas d'une liste vide
		li = newlistT();
	// la liste n'est pas vide
	li->nbElement--;
	li->indexLast--;

	return li;
}
/**
popFrontlistT
*@param : listT, la liste de travail
*@return : listT, la liste finale avec la 1ere valeur supprimé
on fait deplacer tout les elements vers l'avant puis on deccremente les variables de positions
*/
listT popFrontlistT(listT li)
{
	int crt=0;
	if(is_emptylistT(li)) // la cas d'une liste vide
		li = newlistT();
	// la cas d'une liste non vide
	for(int i=0;i<=li->indexLast;i++){
		crt = li->tab[i];
		li->tab[i] = li->tab[i+1];
		li->tab[i+1] = crt;
	}
	li->indexLast--;
	li->nbElement--;

	return li;
}
/**
clearlistT :
*@param : listT, la liste de travail
*@return : listT, la liste finale vidée
tant qu'il y a des valeur dans la liste on utilise la fonction de suppression popBacklistT qui est plus simple
*/
listT clearlistT(listT li)
{
	while(li->indexLast != -1)
		li = popBacklistT(li);

	return li;
}
/**
lookForValueT : fonction qui verifie si une valeur existe dans la liste ou non
*@param : listT, int : la liste de travail et l'entier qu'on veut verifier son existance dans la liste
*@return bool: true si l'entier existe et false sinon
on parcours la liste en testant chaque valeur si elle est egale a l'entier
*/
bool lookForValueT(listT li,int x)
{
	if(is_emptylistT(li)) // la liste est vide donc la valeur n'existe pas
		return false;

	for(int i=0;i<=li->indexLast;i++){	// la liste n'est pas vide et le parcours de la liste
		if(li->tab[i] == x)
			return true;
	}
	return false;
}
/**
lookValueIndexT : fonction qui affiche la valeur qui se trouve dans une pisotion donnée
*@param : listT, int : la liste de travail et la position 
*@return : void , rien on va afficher la valeur
on parcours la liste le nombre de fois jusqu'a arrive a la position donnée
*/
void lookValueIndexT(listT li,int index)
{
	if(is_emptylistT(li))  // le cas d'une liste vide 
		printf("\n la liste est deja vide \n");
	else if(index > max)  // si la position donnée depasse la capacité de la liste
		printf("\n il y a rien dans cette position la liste se termine a %d \n",li->nbElement);
	else if((index > li->nbElement) && (index < max)) // si la position donnée depasse la partie des valeur
		printf("\n il y a rien dans cette position la liste se termine a %d \n",li->nbElement);

	for(int i=0; i<=li->indexLast;i++){
		if(i == index-1)
			printf("\n La valeur qui se trouve dans la position %d est : [%d] \n",index,li->tab[i]);
	}
}
void menuListT(void)
{
	bool quit = true;
	listT li;
	while(quit){
		printf("\n 0 : Changer la SDD\n");
		printf("\n 1 : Creation d'une liste\n");
		printf("\n 2 : Verifier si la liste est vide \n");
		printf("\n 3 : Afficher la taille de la liste\n");
		printf("\n 4 : Afficher la liste\n");
		printf("\n 5 : Ajouter une valeur a la fin\n");
		printf("\n 6 : Ajouter une valeur au debut\n");
		printf("\n 7 : retirer une valeur de la fin\n");
		printf("\n 8 : retirer une valeur du debut\n");
		printf("\n 9 : vider la liste totalment\n");
		printf("\n 10 : Chercher une valeur dans la liste\n");
		printf("\n 11 : Chercher une valeur a un index dans la liste \n");
		printf("\n 99 : Quitter le programme\n");
		int i;
		printf("\n Entrez votre choix : \n");
		scanf("%d",&i);
			if(i == 0){
				system("cls");
				choix();
			}
			if(i == 1){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = newlistT();
				printf("\n La liste a ete cree ...\n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 2){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(is_emptylistT(li))
					printf("\n la liste est vide \n");
				else
					printf("\n la liste est non vide \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 3){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("La taille de cette liste est : (%d)",listTLength(li));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 4){
				system("cls");
				printf("\n-----------------------------------\n");
				printf("\n");
				printlistT(li);
				printf("\n");
				printf("\n------------------------------------\n");
			}
			if(i == 5){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = pushbacklistT(li, x);
				printf("La valeur (%d) a ete ajouter au la fin avec succes\n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 6){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = pushFrontlistT(li, x);
				printf("La valeur (%d) a ete ajouter au debut avec succes\n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 7){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = popBacklistT(li);
				printf("\n la valeur a la fin a ete retirer avec succes \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 8){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = popFrontlistT(li);
				printf("\n la valeur au debut a ete retirer avec succes \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 9){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				li = clearlistT(li);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 10){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("\n Entrez la valeur que vous voullez verifer l existance : ");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(lookForValueT(li, x))
					printf("\n La valeur %d existe dans la liste \n",x);
				else
					printf("\n La valeur %d N EXISTE PAS dans la liste\n",x);
				printf("\n");
				printf("\n---------------------------------\n");
			}
			if(i == 11){
				system("cls");
				printf("\n----------------------------------------\n");
				printf("\n");
				int x;
				printf("\n Entrez l index dont vous voullez voir la valeur :  ");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				lookValueIndexT(li, x);
				printf("\n");
				printf("\n-------------------------------------------\n");
			}
			if( i == 99){
				system("cls");
				printf("\n Merci d avoir utilise ce programme a+ :) \n");
				quit = false;
			}				
	}
}
/*################### FIN DE LA PARTIE DES FILES ##########################*/

///////////// PARTIE DES FILES EN TABLEAU/////////
/**
newqueueT : focntion qui cree et initialise la file 
*@param : void
*@return : queueT , la file cree et initialise
on cree un element de type queueT dont on initialise
indice du dernier element à 1 et le nembre d'element à 0 
*/
queueT newqueueT(void)
{
	queueTElementT *qu;
	qu = malloc(sizeof(*qu));
	if(!qu){
		fprintf(stderr, "\n Error dynamic allocation \n");
		exit(EXIT_FAILURE);
	}
	qu->indexLastOne = -1;
	qu->numberElem = 0;

	return qu;
}
/**
is_emptyqueueT : fonction qui verifie que la file est vide ou non
*@param : queueT , la file qu'on veut tester si elle est vide ou non
*@return :bool , boolieen : true si elle est vide et false sinon
*/
bool is_emptyqueueT(queueT qu)
{
	if(qu->numberElem == 0)
		return true;
	return false;
}
/**
queueTLength : fonction qui retourne la taille de la file 
*@param : queueT , la file de travail
*@return : int , represente taille
*/
int queueTLength(queueT qu)
{
	return qu->numberElem;
}
/**
queueTLength : fonction qui retourne le 1er element de la file 
*@param : queueT , la file de travail
*@return : int , represente le 1er element de la file
*/
int queueTFirst(queueT qu)
{
	if(is_emptyqueueT(qu)){
		printf("Il y a rien a retourner, la file est vide\n");
		exit(1);
	}
	return qu->tab[0];
}
/**
queueTLength : fonction qui retourne le dernier element de la file 
*@param : queueT , la file de travail
*@return : int , represente le dernier element de la file
*/
int queueTLast(queueT qu)
{
	if(is_emptyqueueT(qu)){
		printf("Il y a rien a retourner, la file est vide\n");
		//exit(1);
	}
	return qu->tab[qu->indexLastOne];
}
/**
printqueueT : fonction qui affiche la queueT
*@param : queueT , la file de travail
*@return : void
on parcour la file jusqu'a la fin de file puis on affiche le dernier
*/
void printqueueT(queueT qu)
{
	if(is_emptyqueueT(qu)){ // le cas d'une file vide
		printf("[ ]");
		//exit(1);
	}
	for(int i=0;i<=qu->indexLastOne;i++)  // sinon
		printf("[%d] ",qu->tab[i]);
}
/**
pushqueueT : fonction pour enfiler une valeur
*@param : queueT, int : la file de travail et la valeur d'entier
*@return : void passage par adresse
*/
void pushqueueT(queueT qu,int x)
{
	if(is_emptyqueueT(qu)){  // la cas ou la file est vide
		qu->indexLastOne++;
		qu->tab[qu->indexLastOne] = x;
		qu->numberElem++;
	}
	else{ // la cas ou la file est non vide
		qu->tab[++(qu->indexLastOne)] = x;
		qu->numberElem++;
	}
}
/**
popqueueT : une fonction qui defile une valeur de la file
*@param : queueT , la file de travail
*@return : void
*/
void popqueueT(queueT qu)
{
	if(is_emptyqueueT(qu)) // la pile est vide
		printf("la file est deja vide..\n");
	// la pile est non vide
	qu->numberElem--;
	for(int i=0;i<=qu->indexLastOne;i++)
		qu->tab[i] = qu->tab[i+1];
	
	qu->indexLastOne--;
}
/**
clearqueueT : fonction qui vide une file
*@param : queueT , la file de travail
*@return : void
on parcours la file en utilisant la fonction de defilage
*/
void clearqueueT(queueT qu)
{
	while(qu->numberElem != 0)
		popqueueT(qu);
}
void menuQueueT(void)
{
	queueT qu;
	bool quit = true;
	queueTElementT *queu;
	while(quit){
		printf("\n 0 : Changer la SDD\n");
		printf("\n 1 : Creation d une file \n");
		printf("\n 2 : Verifier si la file est vide\n");
		printf("\n 3 : La taille de la file \n");
		printf("\n 4 : Afficher le 1er elem de la file\n");
		printf("\n 5 : Afficher le dernier elem de la file\n");
		printf("\n 6 : Afficher la file \n");
		printf("\n 7 : enfiler une valeur\n");
		printf("\n 8 : depiler une valeur\n");
		printf("\n 9 : Liquider une pile\n");
		printf("\n 99 : Quitter le programme\n");
		int i;
		printf("\n Entrez votre choix : \n");
		scanf("%d",&i);
			if(i == 0){
				system("cls");
				choix();
			}
			if(i == 1){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				qu = newqueueT();
				printf("La file est bien ete cree ...\n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 2){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(is_emptyqueueT(qu))
					printf("\n la file est vide \n");
				else
					printf("\n la file est non vide \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 3){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est la taille [%d]",queueTLength(qu));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 4){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est le 1ere valeur [%d]",queueTFirst(qu));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 5){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est le dernier valeur [%d]",queueTLast(qu));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 6){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printqueueT(qu);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 7){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				pushqueueT(qu,x);
				printf("\nLa valeur %d a ete bien enfiler\n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 8){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				popqueueT(qu);
				printf("\n la file est defile \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 9){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				clearqueueT(qu);
				printf("\n la file est totalment liquider \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if( i == 99){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("\n Merci d avoir utilise notre programme \n");
				quit = false;
				printf("\n");
				printf("\n--------------------------------\n");
			}			
	}
}
/////////////// FIN PARTIE FILE ////////////// 

/////////////// PARITE DES PILES EN TABLEAU ////////////////////////////
/**
newstackT : fonction pour creer et initialiser une pile
*@param : void
*@return : stackT , le type de la pile initialisée et crée
on cree un element de type pile puis on affecter -1 à la index du Sommet
*/
stackT newstackT(void)
{
	stackTElementT *element;
	element = malloc(sizeof(*element));
	if(!element){
		fprintf(stderr, "\n Error dynamic allocation \n");
		exit(EXIT_FAILURE);
	}
	element->indexSommet = -1;
	return element;
}
/**
isEmpty_stackT : une fonction qui vérifie que la pile est vide 
*@param : stackT, le type de pile qu'on veut verifie si elle est vide
*@return : bool, le type boolieen true si elle est vide et false sinon
*/
bool isEmpty_stackT(stackT st)
{
	if(st->indexSommet == -1)
		return true;

	return false;
}
/**
printstackT : une fonction pour afficher une pile
*@param : stackT , la pile qu'on veut afficher
*@retrun : void , rien on affiche tout
tant que l'indice du sommet est != de -1 donc il y a des elements
et on les affichant
*/
void printstackT(stackT st)
{
	if(isEmpty_stackT(st))  // la pile est vide
		printf("\n [ ] \n");
	int index = st->indexSommet;
	while(index != -1){  // sinon
		printf("[%d]\n",st->tab[index]);
		index--;
	}
}	
/**
pushstackT : fonction qui empile une valeur dans la pile
*@param : stackT, int : c'est la pile et la valeur qu'on veut empiler 
*@return : stackT : la pile avec la valeur empiler 
*/
stackT pushstackT(stackT st, int x)
{
	if(isEmpty_stackT(st)){   // si la pile est vide
		st->indexSommet = 0;
		st->tab[st->indexSommet] = x;
		return st;
	}
	st->indexSommet++;
	st->tab[st->indexSommet] = x;
	return st;
}
/**
popstackT : la fonction qui depile une pile
*@param : stackT, la pile qu'on veut depiler
*@return : void , rien passage par adresse
il faut juste decrementer l'indice du sommet
*/
void popstackT(stackT st)
{
	if(isEmpty_stackT(st)) // si la pile est vide
		printf("\nLa pile est deja vide\n");

	st->indexSommet--;
}
/**
topstackT : la fonction qui retourne le sommet de la pile
*@param : stackT , la pile qu'on veut voir son sommet
*@return : int , le sommet de la pile
*/
int topstackT(stackT st)
{
	return st->tab[st->indexSommet];
}
/**
topstackT : la fonction qui retourne la taille de la pile
*@param : stackT , la pile qu'on veut voir la taille
*@return : int , la taille de la pile
*/
int stackTLength(stackT st)
{
	return st->indexSommet+1;
}
/**
clearstackT : fonction qui vide la pile
*@param : stackT , la pile q'on veut vider
*@return : void, rien
tant qu'il y a des elements dans la pile on utilise la fonction qui  depile
*/
void clearstackT(stackT st)
{
	if(isEmpty_stackT(st))  // le cas ou la pile est vide
		printf("deja vide\n");

	while(!isEmpty_stackT(st)) // la cas de la pile est non vide
		popstackT(st);
}
void menuStackT(void)
{
	bool quit = true;
	stackT sta;
	while(quit){
		printf("\n 0 : Changer la SDD\n");
		printf("\n 1 : Creation d'une pile\n");
		printf("\n 2 : Verifier si la pile est vide \n");
		printf("\n 3 : Afficher une pile\n");
		printf("\n 4 : Ajouter une valeur a la pile\n");
		printf("\n 5 : Depiler une pile\n");
		printf("\n 6 : Le sommet de la pile\n");
		printf("\n 7 : La taille de la pile\n");
		printf("\n 8 : Liquider une pile\n");
		printf("\n 99 : Quitter le programme\n");
		int i;
		printf("\n Entrez votre choix : \n");
		scanf("%d",&i);
			if(i == 0){
				system("cls");
				choix();
			}
			if(i == 1){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				sta = newstackT();
				printf("\n La pile est bien ete cree... \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 2){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				if(isEmpty_stackT(sta))
					printf("\n la pile est vide \n");
				else
					printf("\n la pile est non vide \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 3){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printstackT(sta);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 4){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				int x;
				printf("entrez la valeur a ajouter\n");
				scanf("%d",&x);
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				sta = pushstackT(sta,x);
				printf("\n La valeur %d a ete bien empiler \n",x);
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 5){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				popstackT(sta);
				printf("\n la 1ere valeur a ete depiler \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 6){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est le sommet [%d]",topstackT(sta));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 7){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("c'est la taille [%d]",stackTLength(sta));
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if(i == 8){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				clearstackT(sta);
				printf("\n la pile est totalment liquider \n");
				printf("\n");
				printf("\n--------------------------------\n");
			}
			if( i == 99){
				system("cls");
				printf("\n--------------------------------\n");
				printf("\n");
				printf("\n Merci d utiliser ce programme :) a+ \n");
				quit = false;
				printf("\n");
				printf("\n--------------------------------\n");
			}				
	}
}
///////////////////  FIN PARTIE DES PILES //////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void choix(void)
{
	system("cls");
	int i;
	printf("\n Choisissez ce que vous voullez utiliser \n");
	printf("\n");
	printf("\n 11 : Les Listes en pointeur \n");
	printf("\n 12 : Les Piles en pointeur \n");
	printf("\n 13 : Les Files en pointeur \n");
	printf("\n****************************************\n");
	printf("\n 111 : Les Listes en tableau \n");
	printf("\n 122 : Les Piles en tableau \n");
	printf("\n 133 : Les Files en tableau \n");
	printf("\n 99 : Quitter \n");
	printf(":> ");
	scanf("%d",&i);
	system("cls");
	if(i == 11)
		menuList();
	if(i == 12)
		menuStack();
	if(i == 13)
		menuQueue();
	if(i == 111)
		menuListT();
	if(i == 122)
		menuStackT();
	if(i == 133)
		menuQueueT();
	if(i == 99){
		printf("\n Merci d avoir utilise ce programme :) a+ \n");
		exit(EXIT_FAILURE);
	}
}
