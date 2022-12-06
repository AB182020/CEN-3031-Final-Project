//
// Created by Katie Perera on 11/4/22.
//
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#pragma once
using namespace std;


class Recipe {

//all of the variables in the recipe class
public:
    string name;
    string description;
    vector<string> ingredients;
    vector<string> numIngredients;
    string servingSize;
    string numServings;
    vector<string> recipeSteps;
    vector<string> tags;
    vector<string> searchTerms;

    Recipe();

};



