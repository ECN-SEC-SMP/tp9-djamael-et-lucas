//#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>   
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include "test.h"
#include "CVS.h"


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

//Créez une fonction affiche qui affiche le contenu du vecteur passé en paramètre. 
void affiche(vector<string> const &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

//Créez une fonction concatene qui concatène l’ensemble des éléments du vecteur dans une seule variable de type std::string.
string concatene(vector<string> const &v){
    string res = "";
    for(int i = 0; i < v.size(); i++){
        res += v[i];
    }
    return res;
}

// Créez une fonction ajoute_virgule qui ajoute une virgule derrière chaque mot contenu dans le std::vector.
void ajoute_virgule(vector<string> &v){
    for_each(v.begin(), v.end(), [](string &s){
        s += ",";
    });
}

// Vecteur de chaines de caractères
void partie2(){
    // Definition d'un vecteur stockant des chaines de caractères sans spécifier sa taille
    vector<string> v;

    // Ajouter 5 std::string à ce vecteur
    v.push_back("Bonjour");
    v.push_back("comment");
    v.push_back("allez");
    v.push_back("vous");
    v.push_back("?");

    // Afficher la taille du vecteur v
    cout << "Taille du vecteur v: " << v.size() << endl;
    // Afficher sa capacité(capacity) 
    cout << "Capacite du vecteur v: " << v.capacity() << endl;
    //La différence entre la taille et la capacité est que la taille est le nombre d'éléments actuellement stockés dans le vecteur, tandis que la capacité est le nombre d'éléments que le vecteur peut contenir avant que la mémoire ne soit allouée.

    // — Affichez le contenu du vecteur sur une même ligne (chaque mot étant séparé par un espace) avec les mêmes trois méthodes différentes que précédemment
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
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //Réalisez un échange entre le contenu de la case d’indice 1 avec le contenu de la case d’indice 3 de votre vecteur Utilisez swap
    swap(v[1], v[3]);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;


    // Insérez la valeur "a tous" après le premier élément dans votre vecteur. Vérifiez votre résultat.
    v.insert(v.begin() + 1, "a tous");
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // Remplacer le point d’interrogation final par " ???". Vérifiez votre résultat.
    v[v.size() - 1] = "???";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // Afficher le contenu du vecteur en séparant chaque chaine par une virgule
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;

    // Triez le vecteur en utilisant un algorithme de la STL. L’ordre de tri par défaut est celui de la comparaison alphabétique sur des std::string. Affichez le résultat obtenu.
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // fonction affiche
    affiche(v);

    // fonction concatene
    cout << concatene(v) << endl;

    // fonction ajoute_virgule
    ajoute_virgule(v);
    affiche(v);
}


