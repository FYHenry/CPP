/*************************\
|  Quaternions            |
\*************************/
/*
g++ -std=c++17 -o QuaternionDual main.cpp QuaternionDual.cpp
*/
#ifndef QUATERNIONS_HPP
#define QUATERNIONS_HPP
/* En-tête de la bibliothèque standard :
 * Entrées et sortie en C++.
 */
#include <iostream>
/* En-tête de la bibliothèque standard :
 * Chaînes de caractère en C++.
 */
#include <string>
/* 
 * Vecteurs C++.
 */
#include <vector>
/*
 * Tableaux C++.
 */
#include <array>
/* Header Guard.
 * Pour éviter de redéfinir.
 * Tout le code de l'en-tête est dedans.
 */
typedef std::array<double, 2> vector2;
typedef std::array<double, 4> vector4 ;
/* Classe 'Dual'. */
class Dual
{
/* Partie verrouillée (héritable). */
protected:
  double __r ;// Réel.
  double __d ;// Dual.
/* Partie accessible (héritable). */
public:
  /* Constructeur. */
  Dual(void) ;
  Dual(double r, double d) ;
  /* Destructeur. */
  ~Dual(void) ;
  /* Lecture. */
  double getReal(void) ;
  double getDual(void) ;
  /* Écriture. */
  void setReal(double r) ;
  void setDual(double d) ;
  /* Affichage. */
  void show(void);
};
/* Header Guard.
 * Pour éviter de redéfinir.
 * Tout le code de l'en-tête est dedans.
 */
/* Classe 'Quaternion'. */
class Quaternion
{
/* Partie protégée (héritable). */
protected:
  double __t ;// scalaire.
  /* Éléments de vecteur. */
  double __x ;
  double __y ;
  double __z ;
  /* Vecteur. */
  vector4 __vec ;
public:
/* Partie publique (accessible) */
  /* Constructeurs. */
  Quaternion(void) ;
  Quaternion(double t, double x, double y, double z) ;
  Quaternion(double* v) ;
  Quaternion(vector4 vec) ;
  /* Destructeur. */
  ~Quaternion(void) ;
  /* Accesseurs. */
  double getScalar(void) ;
  double getX(void) ;
  double getY(void) ;
  double getZ(void) ;
  vector4 getVector(void) ;
  /* Mutateurs. */
  void setScalar( double t) ;
  void setX(double x) ;
  void setY(double y) ;
  void setZ(double z) ;
  void setVector(double t, double x, double y, double z) ;
  void setVector(double *v) ;
  void setVector(vector4 vec) ;
  /* Affichage. */
  void show(void) ;
};
/* Header Guard.
 * Pour éviter de redéfinir.
 * Tout le code de l'en-tête est dedans.
 */
/* Classe 'Quaternion dual'. */
class QuaternionDual : protected Quaternion
{
/* Partie verrouillée (héritable). */
protected:
/* Partie accessible (héritable). */
public:
  /* Constructeur. */
  QuaternionDual(void) ;
  /* Destructeur. */
  ~QuaternionDual(void) ;
};
#endif//QUATERNIONS_HPP
