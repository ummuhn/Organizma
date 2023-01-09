#ifndef OKUMA_HPP
#define OKUMA_HPP
#include <sstream>
#include "Doku.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Okuma
{
private:
    int StringToInt(string s)
    {
        int n = atoi(s.c_str()); // string'i int'e çevir
        return n;
    }
    int *DiziOlustur(int uzunluk, std::vector<int> v)
    {
        int *sayilar = new int[uzunluk];
        for (int i = 0; i < uzunluk; i++)
        {
            sayilar[i] = v[i];
        }
        return sayilar;
    }   // The class
public: // Access specifier
    Doku splitAndConvert(const std::string &s, char delimiter)
    {
        std::vector<int> values;
        std::string token;
        std::istringstream tokenStream(s);
        int count = 0;
        while (std::getline(tokenStream, token, delimiter))
        {
            values.push_back(std::stoi(token));
            count++;
        }

        int *p = this->DiziOlustur(values.size(), values);
        return Doku(count, p);
    }
    Doku splitAndConvertMutasyon(const std::string &s, char delimiter)
    {
        std::vector<int> values;
        std::string token;
        std::istringstream tokenStream(s);
        int count = 0;
        while (std::getline(tokenStream, token, delimiter))
        {
            if (StringToInt(token) % 2 == 0)
                values.push_back(StringToInt(token) / 2);

            else
                values.push_back(StringToInt(token));
            count++;
        }

        int *p = this->DiziOlustur(values.size(), values);
        return Doku(count, p);
    }
};

#endif