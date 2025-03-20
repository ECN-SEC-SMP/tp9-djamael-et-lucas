//class CVS

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

CVS::CVS(){
}

void CVS::read(string filename){
    ifstream file(filename);
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string date;
        string event;
        getline(ss, date, ';');
        getline(ss, event, ';');
        ajoute_evenement(stoi(date), event);
    }
    file.close();
}

void CVS::write(string filename){
    ofstream file(filename);
    for(map<int, list<string>>::iterator it = m.begin(); it != m.end(); it++){
        for(list<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            file << it->first << ";" << *it2 << endl;
        }
    }
    file.close();
}

void CVS::affiche_evenements(){
    for(map<int, list<string>>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << ": ";
        for(list<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void CVS::ajoute_evenement(int date, string event){
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