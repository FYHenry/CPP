/* En-tête pour les classes
 * de quaternion dual.
 */
#include "QuaternionDual.hpp"
/* Méthodes Dual. */
/* Constructeur. */
Dual::Dual(void)
{
  setReal(1) ;
  setDual(1) ;
}
/* Constructeur. */
Dual::Dual(double r, double d)
{
  setReal(r) ;
  setDual(d) ;
}
/* Accesseurs. */
double Dual::getReal(void)
{
  return __r ;
}
double Dual::getDual(void)
{
  return __d ;
}
/* Mutateur. */
void Dual::setReal(double r)
{
  __r = r ;
}
void Dual::setDual(double d)
{
  __d = d ;
}
/* Affichage */
void Dual::show(void)
{
  std::cout << "Dual[" << getReal() << "]"
            << "[" << getDual() << "]]"
            << std::endl ;
}
/* Méthodes Quaternion. */
/* Constructeurs. */
Quaternion::Quaternion(void)
{
  setScalar(1) ;
  setX(1) ;
  setY(1) ;
  setZ(1) ;
  setVector(1,1) ;
}
Quaternion::Quaternion(double t, double x, double y, double z)
{
  setScalar(t) ;
  setX(x) ;
  setY(y) ;
  setZ(z) ;
  setVector(1,1,1,1) ;
}
Quaternion::Quaternion(double v[4])
{
  setScalar(v[0]) ;
  setX(v[1]) ;
  setY(v[2]) ;
  setZ(v[3]) ;
  setVector(v) ;
}
Quaternion::Quaternion(vector4 vec)
{
  setScalar(vec[0]) ;
  setX(vec[1]) ;
  setY(vec[2]) ;
  setZ(vec[3]) ;
  setVector(vec) ;
}
/* Accesseurs */
double Quaternion::getScalar(void)
{
  return __t
}
double Quaternion::getX(void)
{
  return __x
}
double Quaternion::getY(void)
{
  return __y
}
double Quaternion::getZ(void)
{
  return __z
}
vector4 Quaternion::getVector(void)
{
  return __vec
}
/* Mutateurs */
void  setScalar(double t) ;
{
  __t = t ;
}
void setX(double x) ;
{
  __x = x ;
}
void setY(double y) ;
{
  __y = y ;
}
void setZ(double z) ;
{
  __z = z ;
}
void setVector(double t, double x, double y, double z) ;
{
  vector4 vec = {t, x, y, z} ;
  __vec = vec ;
}
void setVector(double* v)
{
  vector4 vec(v) ;
  __vec = vec ;
