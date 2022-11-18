#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#pragma once
using namespace std;


class Recipe {

public:
    string name;
    string description;
    string ingredients;
    string numIngredients;
    string servingSize;
    string numServings;
    string recipeSteps;
    string tags;
    string searchTerms;

    Recipe();

};
