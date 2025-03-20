/*********************************************
Auteurs :	Djamaël LAHAMION
Date : 13 mars 2025
Fichier : main.cpp
But : Fichier principale
*********************************************/
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
// Définition du foncteur
class AjouteVirgule
{
public:
    void operator()(string& s) const
    {
        s += ",";
    }
};

void ajoute_virgule(vector<string>& str)
{
    for_each(str.begin(), str.end(), AjouteVirgule());
}

void affiche(const vector<string>& str)
{
    for (const string& s : str)
    {
        cout << s << " ";
    }
    cout << endl;
}
string concatene(const vector<string>& str)
{
    string resultat;
    for (size_t i = 0; i < str.size(); i++)
    {
        resultat += str[i];
        if (i < str.size() - 1)
        {
            resultat += " ";
        }
    }
    return resultat;
}

void affichageVecteurAvecUneVirgule(vector<string> &str)
{
    cout << "Affichage du contenu du vecteur avec une virgule:" << endl;
    for (size_t i = 0; i < str.size(); i++)
    {
        cout << str[i];
        if (i < str.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
void affichageVecteurAvecUneBoucle(vector<int> &v)
{
    cout << "Affichage du contenu du vecteur avec une boucle:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
void affichageVecteurAvecUneBoucle(vector<string> &str)
{
    cout << "Affichage du contenu du vecteur avec une boucle:" << endl;
    for (int i = 0; i < str.size() - 1; i++)
    {
        cout << str[i] << " ";
    }
    cout << str[str.size() - 1] << endl;
}
void affichageVecteurAvecUnIterateur(vector<int> &v)
{
    cout << "Affichage du contenu du vecteur avec un iterateur:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}
void affichageVecteurAvecUnIterateur(vector<string> &str)
{
    cout << "Affichage du contenu du vecteur avec un iterateur:" << endl;
    for (vector<string>::iterator it = str.begin(); it != str.end() - 1; it++)
    {
        cout << *it << " ";
    }
    cout << str[str.size() - 1] << endl;
}
int main()
{
    //  ----------------[ Partie 1 : VECTEUR D’ENTIERS]-------------------
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
    cout << "Affichage du contenu du vecteur avec les indices:" << endl;
    cout << v1[0] << endl
         << v1[1] << endl
         << v1[2] << endl;
    // * Avec une boucle :
    affichageVecteurAvecUneBoucle(v1);
    // "* Avec un itérateur :
    affichageVecteurAvecUnIterateur(v1);

    // Ajout d'un élément à la fin du vecteur
    v1.push_back(2);
    cout << "Vecteur après l'ajout d'un élément:" << endl;
    cout << "Taille du vecteur : " << v1.size() << endl;
    affichageVecteurAvecUnIterateur(v1);

    // Copie du vecteur v1 dans un vecteur v2
    cout << "Vecteur v2 copie de v1" << endl;
    copy(v1.begin(), v1.end(), back_inserter(v2));
    affichageVecteurAvecUnIterateur(v2);

    //  ----------------[ Partie 2 : VECTEUR DE CHAINES DE CARACTÈRES]-------------------
    vector<string> str;
    str.push_back("Bonjour");
    str.push_back("comment");
    str.push_back("allez");
    str.push_back("vous");
    str.push_back("?");

    // Affichage de la taille du vecteur
    cout << "Taille: " << str.size() << endl;
    // Affichage de la capacite du vecteur
    cout << "Capacite: " << str.capacity() << endl;

    // Ajout d'elements
    str.push_back("Bien");
    str.push_back("et");
    str.push_back("vous");
    str.push_back("?");

    // Affichage de la taille du vecteur
    cout << "Taille: " << str.size() << endl;
    // Affichage de la capacite du vecteur
    cout << "Capacite: " << str.capacity() << endl;

    // Affichage du vecteur
    cout << "Affichage du string avec les indices:" << endl;
    cout << str[0] << " "
         << str[1] << " "
         << str[2] << " "
         << str[3] << " "
         << str[4] << " "
         << str[5] << " "
         << str[6] << " "
         << str[7] << " "
         << str[8] << endl;
    cout << endl;

    affichageVecteurAvecUneBoucle(str);
    cout << endl;

    affichageVecteurAvecUnIterateur(str);

    // Echange entre les cases
    cout << endl
         << "Echange entre les cases" << endl;
    swap(str[1], str[3]);
    affichageVecteurAvecUnIterateur(str);

    // Inserer a tous
    str.insert(str.begin() + 1, "a tous");
    affichageVecteurAvecUnIterateur(str);
    // Remplacer "?" par "???"
    for (string &s : str)
    {
        if (s == "?")
        {
            s = " ???";
        }
    }
    cout << "\nAprès modification du point d'interrogation :" << endl;
    affichageVecteurAvecUnIterateur(str);

    affichageVecteurAvecUneVirgule(str);

    sort(str.begin(), str.end());

    // Affichage du vecteur trié
    cout << "\nAprès tri du vecteur :" << endl;
    affichageVecteurAvecUneVirgule(str);
    cout << "\nAprès tri du vecteur et en utilisant affiche :" << endl;
    affiche(str);

    string phrase = concatene(str);
    cout << "Texte concaténé : " << phrase << endl;

    ajoute_virgule(str);

    cout << "Après ajout de la virgule :" << endl;
    for (const string& s : str)
        cout << s << " ";
    cout << endl;


    //  ----------------[ Partie 3 : Listes]-------------------
    cout<<endl<<"Partie 2 : Listes"<<endl;
    list<int> nombres = {10, 20, 30, 40, 50, 60, 70, 80};
    
    // Affichage des éléments avec des itérateurs
    for (auto iter = nombres.begin(); iter != nombres.end(); ++iter) {
        cout << *iter << " ";
    }
    cout<<endl<<endl;
    // Obtenir un itérateur vers le troisième élément (index 2)
    auto it = nombres.begin();
    advance(it, 2);
    
    // Supprimer le troisième élément
    nombres.erase(it);

    // Affichage des éléments avec des itérateurs
    for (auto iter = nombres.begin(); iter != nombres.end(); ++iter) {
        cout << *iter << " ";
    }
    cout<<endl<<endl;
}
