class Solution {
public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool inComment=false;
    string s="";
    for (auto text: source){
      int n=text.size();
      for (int i=0; i<n; i++){
        if (!inComment && i<n-1 && text[i] == '/' && text[i+1] == '/')
          break;
        else if (!inComment && i<n-1 && text[i] == '/' && text[i+1] == '*'){
          inComment=true; i++;
        }
        else if (inComment && i<n-1 && text[i] == '*' && text[i+1] == '/'){
          inComment=false; i++;
        }
        else if (!inComment)
          s += text[i];
      }
      if (!inComment && s.size()){
        
        res.push_back(s);
        s.clear();
      }
    }
      
    return res;
  }
};
