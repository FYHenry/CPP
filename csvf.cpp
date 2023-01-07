/*****************************************\
|* Code C++ pour lire un fichier CSV.    *|
|*                                       *|
|* Auteur : Alnotz        .              *|
|* Note : On peut surement faire mieux ! *|
\*****************************************/
/*g++ -Wall -Wextra -c csvf.cpp && g++ -Wall -Wextra csvf.o -o csvf*/
/* Bibliotheques standards de C++ 11. */
#include <iostream>// Entree/sortie.
#include <fstream>// Fichiers.
#include <cstring>// Caracteres.
#include <cstdlib>// Controles de procedures.
#define LINES 8// Lignes.
#define ROWS 6// Colonnes.
/* Fonction secondaire. */
/* Un texte d'aide pour connaître les commandes. */
/* Une seule commande ici : '-h' pour l'aide. X-) */
void helper(void)// Que du texte... :-|
{
  std::cout << "/*********************************************\\" << std::endl;
  std::cout << "|* Section d'aide pour le programme 'csvf'.  *|" << std::endl;
  std::cout << "|*                                           *|" << std::endl;
  std::cout << "|* csvf [-h|--help]                          *|" << std::endl;
  std::cout << "|*                                           *|" << std::endl;
  std::cout << "\\*********************************************/" << std::endl;
  std::cout << std::endl;
  std::cout << "Pour manipuler ce programme, il suffit d'avoir";
  std::cout << " le fichier 'csvin.csv' dans le meme repertoire." << std::endl;
  std::cout << std::endl;
  std::cout << " Contenu de 'csvin.csv' :" << std::endl;
  std::cout << std::endl;
  std::cout << "\"X\",\"Y\",\"Z\",\"U\",\"V\",\"P\"" << std::endl;
  std::cout << "1,1,1,1,1,1" << std::endl;
  std::cout << "2,2,2,2,2,2" << std::endl;
  std::cout << "3,3,3,3,3,3" << std::endl;
  std::cout << "4,4,4,4,4,4" << std::endl;
  std::cout << "5,5,5,5,5,5" << std::endl;
  std::cout << "6,6,6,6,6,6" << std::endl;
  std::cout << "7,7,7,7,7,7" << std::endl;
  std::cout << "8,8,8,8,8,8" << std::endl;
  std::cout << std::endl;
  std::cout << "Apres ca, on execute 'csvf'."<< std::endl;
}
/* Fonction principale. */
int main(int argc, char** argv)
{
  /* Avant de commencer, a-t-on ajoute une option ? */
  if (argc == 2)// si une option...
  {
    /* En cas d'option '-h' ou '--help'... */
    if (strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0)
    {
      /* Page d'aide invoquee. */
      helper();
      /* Fin du programme avec succes. */
      exit(EXIT_SUCCESS);
    }
  }
  /* Texte memorise. */
  char text[LINES+1][5*ROWS-1];
  /* Indices ligne/colonne. */
  char i,j;
  /* Matrice d'entiers. */
  int matrix[LINES][ROWS];
  /* Pour s'assurer la fin de chaque ligne.
   * Une ligne = une sous-chaine.
   */
  for (i=1; i<ROWS; i++)
  {
    text[i][5*ROWS-1-1]='\0';
  }
  /* Pour la deco. car j'aime ca. :-D */
  std::cout << "/*****************************************\\"
            << std::endl;
  std::cout << "|* Code C++ pour lire un fichier CSV.    *|"
            << std::endl;
  std::cout << "|*                                       *|"
            << std::endl;
  std::cout << "|* Auteur : Frederic Henry.              *|"
            << std::endl;
  std::cout << "|* Note : On peut surement faire mieux ! *|"
            << std::endl;
  std::cout << "\\*****************************************/"
            << std::endl;
  std::cout << std::endl;
  /* Lecture de fichier texte avec "std::ifstream". */
  std::cout << "Lecture de \"./csvin.csv\"..." << std::endl;
  std::ifstream entree("csvin.csv");// Pointeur de fichier.
  std::cout << "Table CSV (en-tete) :" << std::endl;
  /* Ligne 0 lue. */
  entree >> text[0];
  std::cout << text[0] << std::endl;
  /* Les autres lignes. */
  std::cout << "Table CSV (corps) :" << std::endl;
  for (i=1; i<LINES+1; i++)
  {
    entree >> text[i];
    std::cout << text[i] << std::endl;
  }
  /* Lecture integrale. */
  std::cout << "Table CSV (tout) :" << std::endl;
  for (i=0; i<LINES+1; i++)
  {
    std::cout << text[i] << std::endl;
  }
  /* Fermeture du fichier. */
  entree.close();
  std::cout << std::endl;
  /* Affichage du tableau de caracteres. */
  std::cout << "Version tableau de caracteres :" << std::endl;
  /* En-tete. */
  for (j=0; j<ROWS; j++)
  {
    std::cout << text[0][4*j+1]  << ' ';
  }
  /* Corps. */
  std::cout << std::endl;
  for (i=1; i<LINES+1; i++)
  {
    for (j=0; j<ROWS; j++)
    {
      std::cout << text[i][2*j]  << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  /* Pareil, facon nombres entiers. */
  std::cout << "Version tableau d'entiers :" << std::endl;
  /* Conversion du texte a la matrice entiere. */
  for (i=0; i<LINES; i++)
  {
    for (j=0; j<ROWS; j++)
    {
      matrix[i][j]=(int)text[i+1][2*j]-48;
    }
  }
  /* Affichage de la matrice. */
  for (i=0; i<LINES; i++)
  {
    for (j=0; j<ROWS; j++)
    {
      std::cout << matrix[i][j]  << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  /* Ce coup-ci, ecriture de tableau dans un fichier. */
  std::cout << "Ecriture d'un tableau CSV \"./csvout.csv\"..." << std::endl;
  std::ofstream sortie("csvout.csv");
  /* Dabord l'en-tete. */
  sortie << "\"X\",\"Y\",\"Z\",\"U\",\"V\",\"P\"" << std::endl;
  /* En suite le corps. */
  for (i=0; i<LINES; i++)
  {
    for (j=0; j<ROWS-1; j++)
    {
      sortie << matrix[i][j] << ',';
    }
    sortie << matrix[i][ROWS-1] << std::endl;
  }
  /* Fichier ferme. */
  sortie.close();
  std::cout << std::endl;
  /* Fini. */
  std::cout << "Fin" << std::endl;
  /* Pour dire que tout a bien marche. */
  return EXIT_SUCCESS;
}

