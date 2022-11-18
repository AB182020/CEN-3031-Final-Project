//
// Created by Katie Perera on 11/1/22.
//
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Recipe.h"
#include "Storage.h"
#pragma once
using namespace std;

void Storage::ReadFile() {
    ifstream inFile("recipes_w_search_terms.csv");

    if(inFile.is_open()){
        string line;
        getline(inFile, line);

        while(getline(inFile, line)){
            istringstream stream(line);

            string iD, name, description, ingredients, numIngredients, servingSize, numServings, recipeSteps, tags, searchTerms;
            string temp;

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

            cout << name;

            Recipe recipe;
            recipe.name = name;
            recipe.description = description;
            bool add = false;
            int num = 0;
            string tempName;
            for (int i = 0; i <= ingredients.length(); i++){
               if (ingredients[i] == '\''){
                   num += 1;
                   if(num % 2 != 0){
                       add = true;
                   }else if(num % 2 == 0){
                       add = false;
                   }
               }else if(ingredients[i] == ' ' | ingredients[i] == ','){
                   continue;
               }else{
                   if(add){
                       tempName.push_back(ingredients[i]);
                   }else{
                       recipe.ingredients.push_back(tempName);
                       tempName = "";
                   }

               }

            }
            num = 0;
            add = false;
            tempName = "";
            for (int i = 0; i <= numIngredients.length(); i++){
                if (numIngredients[i] == '"'){
                    num += 1;
                    if(num % 2 != 0){
                        add = false;
                    }else if(num % 2 == 0){
                        add = true;
                    }
                }else if(numIngredients[i] == ','){
                    continue;
                }else{
                    if(add){
                        tempName.push_back(numIngredients[i]);
                    }else{
                        recipe.numIngredients.push_back(tempName);
                        tempName = "";
                    }

                }

            }
            recipe.servingSize = servingSize;
            recipe.numServings = numServings;

            add = false;
            num = 0;
            tempName = "";
            for (int i = 0; i <= recipeSteps.length(); i++){
                if (recipeSteps[i] == '\''){
                    num += 1;
                    if(num % 2 != 0){
                        add = true;
                    }else if(num % 2 == 0){
                        add = false;
                    }
                }else{
                    if(add){
                        tempName.push_back(recipeSteps[i]);
                    }else{
                        recipe.recipeSteps.push_back(tempName);
                        tempName = "";
                    }
                }
            }

            add = false;
            num = 0;
            tempName = "";
            for (int i = 0; i <= tags.length(); i++){
                if (tags[i] == '\''){
                    num += 1;
                    if(num % 2 != 0){
                        add = true;
                    }else if(num % 2 == 0){
                        add = false;
                    }
                }else{
                    if(add){
                        tempName.push_back(tags[i]);
                    }else{
                        recipe.tags.push_back(tempName);
                        tempName = "";
                    }
                }
            }

            add = false;
            num = 0;
            tempName = "";
            for (int i = 0; i <= searchTerms.length(); i++){
                if (searchTerms[i] == '\''){
                    num += 1;
                    if(num % 2 != 0){
                        add = true;
                    }else if(num % 2 == 0){
                        add = false;
                    }
                }else{
                    if(add){
                        tempName.push_back(searchTerms[i]);
                    }else{
                        recipe.searchTerms.push_back(tempName);
                        tempName = "";
                    }
                }
            }

        }
    }
}
