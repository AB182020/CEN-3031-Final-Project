#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Recipe.h"
#pragma once
using namespace std;



class Storage {
private:

public:
    void ReadFile();
    void insertMap(Recipe recipe);
};
