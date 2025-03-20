#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>   
#include <map>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class CVS{
    private:
        map<int, list<string>> m;
    public:
        CVS();
        void read(string filename);
        void write(string filename);
        void affiche_evenements();
        void ajoute_evenement(int date, string event);
};
