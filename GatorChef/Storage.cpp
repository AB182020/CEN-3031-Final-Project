#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>
#include "Recipe.h"
#include "Storage.h"
#pragma once
using namespace std;

//read in function of the csv file
void Storage::ReadFile() {
    ifstream inFile("finalRecipes.csv");
    Recipe recipe;

    if(inFile.is_open()){
        string line;
        getline(inFile, line);

        while(getline(inFile, line)){
            istringstream stream(line);

            //creating all the variables for the information from the csv
            string iD, name, description, ingredients, numIngredients, servingSize, numServings, recipeSteps, tags, searchTerms;
            string temp;

            //reading in line by line the information from the csv
            getline(stream, iD, ',');
            getline(stream, name, ',');
            getline(stream, temp, '"');
            getline(stream, description, '"');
            getline(stream, temp, '[');
            getline(stream, ingredients, ']');
            getline(stream,temp, '[');
            getline(stream, numIngredients, ']');
            getline(stream, temp, ',');
            getline(stream, servingSize, ',');
            getline(stream, numServings, ',');
            getline(stream, temp, '[');
            getline(stream, recipeSteps, ']');
            getline(stream, temp, '[');
            getline(stream, tags, ']');
            getline(stream, temp, '{');
            getline(stream, searchTerms, '}');
            getline(stream, temp, '"');

            //cout << name;

//            Recipe recipe;
            recipe.name = name;
            recipe.description = description;
            recipe.ingredients = ingredients;

    
            //setting more variable equal to eachother
            recipe.numIngredients = numIngredients;
            recipe.servingSize = servingSize;
            //recipe.numServings = numIngredients; // typo?
            recipe.numServings = numServings;

//         
            recipe.recipeSteps = recipeSteps;

            recipe.tags = tags;

            recipe.searchTerms = searchTerms;
            insertMap(recipe);
        }
    }
}

//function for inserting recipes into the map
void Storage :: insertMap(Recipe recipe) {
    //cout << recipe.name << endl; // good

//    cout << recipe.description << endl; // have to account for missing sections

//    for (int i = 0; i < recipe.ingredients.size(); i++) {
//        cout << recipe.ingredients[0] << endl; // printing out without any spaces
//    }

//    for (int i = 0; i < recipe.numIngredients.size(); i++) {
//        cout << recipe.numIngredients[0] << endl; not printing anything
//    }

    //cout << recipe.servingSize << endl; // have to account for missing values
//    cout << recipe.numServings << endl; // have to account for missing values
//    for (int i = 0; i < recipe.recipeSteps.size(); i++) {
//        cout << recipe.recipeSteps[i] << endl; // okay
//    }

//    for (int i = 0; i < recipe.tags.size(); i++) {
//        cout << recipe.tags[i] << " "; // okay
//    }

//    for (int i = 0; i < recipe.searchTerms.size(); i++) {
//        cout << recipe.searchTerms[i] << endl;
//    }
    //creating map and vectors of the data
    map<string, vector<string>> data;
    vector<vector<string>> values;
    vector<string> des;
    des.push_back(recipe.description);
    vector<string> servingSize;
    servingSize.push_back(recipe.servingSize);
    vector<string> numServings;
    numServings.push_back(recipe.numServings);
    vector<string> tags;
    tags.push_back(recipe.tags);
    vector<string> steps;
    steps.push_back(recipe.recipeSteps);
    vector<string> ingredients;
    ingredients.push_back(recipe.ingredients);
    vector<string> search;
    search.push_back(recipe.searchTerms);
    vector<string> num;
    num.push_back(recipe.numIngredients);

    //pushing information into the vector
    values.push_back(des);
    values.push_back(servingSize);
    values.push_back(numServings);
    values.push_back(tags);
    values.push_back(steps);
    values.push_back(ingredients);
    values.push_back(search);
    values.push_back(num);

    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values[i].size(); j++) {
            //cout << values[i][j] << endl;
            data[recipe.name].push_back(values[i][j]);
        }
    }


    for(auto it = data.begin(); it != data.end(); ++it)
    {
        cout << "Name: " << it -> first << endl;
        for (int i = 0; i < it->second.size(); i++) {
//            for (int j = 0; j < it->second[i].size(); j++) {
                cout << it->second[i] << endl;
                //cout << it->second[j] << endl;
            }
            //}
        }

}
