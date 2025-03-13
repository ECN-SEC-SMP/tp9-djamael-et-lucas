//#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>   
#include <map>
#include <vector>
#include <algorithm>
#include "test.h"


using namespace std;

// Vecteur d'entiers
void partie1(){
    // Definition d'un vecteur stockant des entiers sans spécifier sa taille
    vector<int> v;

    // Dimension du vecteur v de taille 3
    v.resize(3);

    // Affectation 3 valeurs
    v[0] = 12;
    v[1] = 34;
    v[2] = 56;

    // Parcourir et afficher le vecteur de 3 manières différentes
    // 1. Parcours avec un indice
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // 2. En exécutant une boucle sur une plage de nombres
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;

    // 3. Parcours avec un itérateur
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Ajout d'un élément à la fin du vecteur
    v.push_back(78);
    // Affichage du vecteur
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // copiez le premier vecteur dans d’autres vecteurs en utilisant copy et/ou assign
    vector<int> v2;
    v2.assign(v.begin(), v.end());
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
}

