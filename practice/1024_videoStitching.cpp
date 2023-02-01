class Solution {
public:
  string validIPAddress(string queryIP) {
    return checkIPv4(queryIP) ? "IPv4" : checkIPv6(queryIP) ? "IPv6" : "Neither"; 
  }
private:
  bool checkIPv4(string queryIP){
    vector<string> tokens = split(queryIP, '.');
    if (tokens.size() != 4){return false;}
    for (auto token: tokens){
      if (token.size() == 0 || token.size() > 3){return false;}
      if ((token.size() > 1 && token[0] == '0')){return false;}
      for (auto ch: token){
        if (!isdigit(ch)){return false;}
      }
      if (stoi(token) > 255){return false;}
    }
    return true;
  }
  vector<string> split(string ip, char deli){
    vector<string> tokens;
    size_t pos;
    while ((pos = ip.find(deli)) != string::npos){
      tokens.push_back(ip.substr(0, pos));
      ip.erase(0, pos + 1);
    }
    tokens.push_back(ip);
    return tokens;
  }
  bool checkIPv6(string queryIP){
    vector<string> tokens = split(queryIP, ':');
    if (tokens.size() != 8){return false;}
    for (auto token: tokens){
      if (token.size() > 4 || token.size() < 1){return false;}
      for (auto ch: token){
        if (!isdigit(ch)){
          int idx1 = (int) ch - 'a';
          int idx2 = (int) ch - 'A';
          if (idx1 >= 0 && idx1 <= 5){continue;}
          if (idx2 >= 0 && idx2 <= 5){continue;}
          return false;
        }
      }
    }
    return true;
  }
};
