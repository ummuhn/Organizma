/**
 * @file Sistem.hpp
 * @description Sistem sınıfı organlardan oluşur.
 * @date 25.12.2022
 * @author ümmühan Akyıldız tandogan.ummuhan@gmail.com
 */

#ifndef SISTEM_HPP
#define SISTEM_HPP

#include <iostream>
#include "ArrayList.hpp"
#include "Organ.hpp"
using namespace std;

class Sistem
{
public:

string sistemString;
    Organ *organlar[100]; // 100 adet organ sistemi olusturur

    Sistem()
    {
    }

    ~Sistem()
    {
        
    }
};

#endif
