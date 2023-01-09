#include <iostream>
#include <fstream>
#include <string>
#include "Okuma.hpp"
#include "BST.hpp"
#include "Organizma.hpp"
#include "Organ.hpp"
#include "Doku.hpp"
#include "Radix.hpp"

using namespace std;

int main()
{

    // Create a text string, which is used to output the text file
    string dokuString;
    string sistemString;
    string mutasyonluSistemString;
    Okuma okuma;
    // Read from the text file
    ifstream MyReadFile("doc/Veri2.txt");
    Organizma *organizma = new Organizma();
    Sistem *sistem = new Sistem();
    // Use a while loop together with the getline() function to read the file line by line
    BST<int> *bst = new BST<int>();
    int dokuSayisi = 0;
    int organSayisi = 0;
    string s = "ORGANIZMA";

    s.insert(0, 20, ' ');        // sola 3 boşluk ekle
    s.insert(s.size(), 20, ' '); // sağa 3 boşluk ekle
    cout << s << endl;
    while (getline(MyReadFile, dokuString))
    {
        // Output the text from the file
        Doku v = okuma.splitAndConvert(dokuString, ' ');

        Radix *radix = new Radix(v.hucreler, v.length);
        int orta = radix->SortAndGetMiddle();

        bst->Add(orta);
        delete radix;
        if (orta % 50 == 0)
        {
            // cout << dokuSayisi << ". Sira Mutasyona Ugrayacak" << endl;
        }

        dokuSayisi++;

        if (dokuSayisi % 20 == 0)
        {
            // bir organ olustu , bunun denge durumunu kontrol et

            Organ *organ = new Organ(bst, bst->IsBalanced());
            organ->kok = bst->findRoot();
            sistem->organlar[organSayisi] = organ;
            sistemString = sistemString + organ->isBalanced;

            if (dokuSayisi % 2000 == 0)
            {
                // Yeni Sistem oluştu
                // cout << sistemString << endl;
                sistem->sistemString = sistemString;
                sistemString = "";
                organSayisi = 0;
                organizma->sistemler->add(*sistem);
                sistem = new Sistem();
            }

            bst = new BST<int>();
        }
    }

    organizma->OrganizmaYazdir();

    if (cin.get() == '\n')
    {
        organizma->Mutasyon();
        organizma->OrganizmaYazdir();
    }

    // Close the file
    MyReadFile.close();
}
