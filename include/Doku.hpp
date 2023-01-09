/**
 * @file Doku.hpp
 * @description Doku sınıfı Hücrelerden oluşur.


 * @date 25.12.2022
 * @author ümmühan Akyıldız tandogan.ummuhan@gmail.com
 */

#ifndef DOKU_HPP
#define DOKU_HPP
#include <sstream>

using namespace std;

class Doku
{
public:
   int length; // Length of a box
   int *hucreler;

   Doku()
   {
      this->length = 0;
   }
   Doku(int length, int *hucreler)
   {
      this->length = length;
      this->hucreler = hucreler;
   }
   ~Doku()
   {
      delete hucreler;
   }
};
#endif