/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 13 mars 2025
Fichier : main.cpp
But : Fichier principale
*********************************************/
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

void affichageVecteurAvecUneBoucle(vector<int> &v)
{
    cout<<"Affichage du contenu du vecteur avec une boucle:"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
}
void affichageVecteurAvecUnIterateur(vector<int> &v)
{
    cout<<"Affichage du contenu du vecteur avec un iterateur:"<<endl;
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++)
    {
        cout<<*it<<endl;
    }
}

int main()
{
     //  ----------------[ Partie 1]-------------------
     // Création du vecteur
     vector<int> v1;
     vector<int> v2;

     // Redimensionnement du vecteur
     v1.resize(3);

     // Remplissage du vecteur
     v1[0] = 5;
     v1[1] = 7;
     v1[2] = 9;

    //  Parcours du vecteur
    // * Avec les indices :
    cout<<"Affichage du contenu du vecteur avec les indices:"<<endl;
    cout<<v1[0]<<endl<<v1[1]<<endl<<v1[2]<<endl;
    // * Avec une boucle :
    affichageVecteurAvecUneBoucle(v1);
    // "* Avec un itérateur :
    affichageVecteurAvecUnIterateur(v1);

    // Ajout d'un élément à la fin du vecteur
    v1.push_back(2);
    cout<<"Vecteur après l'ajout d'un élément:"<<endl;
    cout<<"Taille du vecteur : "<<v1.size()<<endl;
    affichageVecteurAvecUnIterateur(v1);

    // Copie du vecteur v1 dans un vecteur v2
    cout<<"Vecteur v2 copie de v1"<<endl;
    copy(v1.begin(), v1.end(), back_inserter(v2));
    affichageVecteurAvecUnIterateur(v2);

     //  ----------------[ Partie 2 ]-------------------

     //  ----------------[ Partie 3 ]-------------------

}
