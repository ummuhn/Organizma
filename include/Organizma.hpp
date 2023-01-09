/**
 * @file Organizma.hpp
 * @description Organizma sınıfı sistemlerden oluşur.


 * @date 25.12.2022
 * @author ümmühan Akyıldız tandogan.ummuhan@gmail.com
 */

#ifndef ORGANIZMA_HPP
#define ORGANIZMA_HPP

#include <iostream>
#include "ArrayList.hpp"
#include "Sistem.hpp"
using namespace std;

class Organizma
{
public:
    ArrayList<Sistem> *sistemler = new ArrayList<Sistem>();
    int len;
    void Mutasyon()
    {

        std::vector<int> array;
        int lng = sistemler->size();
        for (int i = 0; i < lng; i++)
        {
            for (int o = 0; o < 100; o++)
            {
               
               

            }
        }
    }

    void OrganizmaYazdir()
    {
        int lng = sistemler->size();
        for (int i = 0; i < lng; i++)
        {
            cout << sistemler->elementAt(i).sistemString << endl;
        }
    }

    Organizma(){

    };

    ~Organizma()
    {
        delete sistemler;
    }
};

#endif
