/**
 * @file Organ.hpp
 * @description Sistem sınıfı organlardan oluşur.


 * @date 25.12.2022
 * @author ümmühan Akyıldız tandogan.ummuhan@gmail.com
 */


#ifndef ORGAN_HPP
#define ORGAN_HPP
#include <sstream>
#include "BST.hpp"

using namespace std;

class Organ
{
public:
    string isBalanced; // Length of a box
    int kok; // Length of a box
    BST<int> *dokular; // 20 Adet doku
    Organ()
    {
    }

    Organ(BST<int> *dokular, string isBalanced)
    {
        this->isBalanced = isBalanced;
        this->dokular = dokular;
    }
    ~Organ(){
       delete dokular; 
    }
};
#endif