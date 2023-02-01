/*
2115. Find All Possible Recipes from Given Supplies
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.
*/
class Solution {
public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> sup = {supplies.begin(), supplies.end()};
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegrees;
    for (auto recipe: recipes)
      inDegrees[recipe] = 0;
    int n=recipes.size();
    for (int i=0; i<n; i++){
      for (int j=0; j<ingredients[i].size(); j++){
        if (!sup.count(ingredients[i][j])){
          graph[ingredients[i][j]].push_back(recipes[i]);
          inDegrees[recipes[i]]++;
        }
      }
    }
    queue<string> noDep;
    for (auto x: inDegrees){
      if (x.second == 0)
        noDep.push(x.first);
    }
    vector<string> res;
    while (!noDep.empty()){
      string cur = noDep.front();
      res.push_back(cur);
      noDep.pop();
      for (auto next: graph[cur]){
        inDegrees[next]--;
        if (inDegrees[next] == 0)
          noDep.push(next);
      }
    }
    return res;
  }
};
