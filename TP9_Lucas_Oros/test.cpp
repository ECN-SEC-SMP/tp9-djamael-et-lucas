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

//Les Listes
void partie3(){
    // Creation d'une liste de huit entiers
    list<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8};

    // Supprimer le troisieme element
    list<int>::iterator it = list1.begin();
    advance(it, 2);
    list1.erase(it);

    // Afficher la liste
    for(list<int>::iterator it = list1.begin(); it != list1.end(); it++){
        cout << *it << " ";
    }
}


//Construisez une fonction ajoute_evenement qui ajoute un événement (date, intitulé) dans votre structure que vous passerez en paramètre M[clé]=valeur ou M.insert(std::make_pair(clé,valeur))
// Il faut séparer les cas où l’on ajoute un événement dans une liste déjà existante, du cas où il faut ajouter une nouvelle liste dans la map
void ajoute_evenement(map<int, list<string>> &m, int date, string event){
    if(m.find(date) == m.end()){ // Si la date n'existe pas
        list<string> l; // On crée une nouvelle liste l
        l.push_back(event); // On ajoute l'événement à la liste
        m.insert(make_pair(date, l)); // On insère la liste dans la map
    }else{
        m[date].push_back(event); // On ajoute l'événement à la liste existante
    }
    cout << "Evenement " << event << " ajoute a la date " << date << endl;
    cout << endl;
}

// fonction qui affiche l’ensemble des dates et des événements associés.
void affiche_evenements(map<int, list<string>> &m){
    for(map<int, list<string>>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << ": ";
        for(list<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Les Maps
void partie4(){
    map<int, list<string>> m;
    m[2020].push_back("Event1");
    m[2020].push_back("Event2");
    m[2020].push_back("Event3");
    m[2021].push_back("Event4");
    m[2021].push_back("Event5");
    m[2022].push_back("Event6");
    m[2023].push_back("Event7");

    // Afficher la map
    affiche_evenements(m);

    // Ajouter un événement à la date 2020
    ajoute_evenement(m, 2020, "Event8");
    // Ajouter un événement à la date 2024
    ajoute_evenement(m, 2024, "Event9");

    // Afficher la map
    affiche_evenements(m);
}


