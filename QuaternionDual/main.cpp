/* Code principal. */
/* Import de l'en-tête. */
#include "QuaternionDual.hpp"
/* Fonction principale. */
int main(int argc, char** argv)
{
  std::cout << "Début";
  Quaternion q();
  q.setX(7);
  std::cout << "Vecteur : ";
  for(auto n : q.getVector())
  {
    std::cout << n << " ";
  }
  std::cout << ".\n";
  std::cout << "Fin" << std::endl;
  return EXIT_SUCCESS ;
}
