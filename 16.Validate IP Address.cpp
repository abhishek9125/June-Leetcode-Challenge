class Solution {
public:
    string validIPAddress(string IP){
        bool isIPv4 = checkIP(IP);
        string result;
        return result = isIPv4 ? checkValidIPv4(IP) : checkValidIPv6(IP);
    }
    
    bool checkIP(string IP){
        for(auto c : IP){
            if(c=='.'){
                return true;
            }
        }
        return false;
    }
    
    bool isNumeric(string s){
        for(auto c : s){
            if(c<'0' && c>'9'){
                return false;
            }
        }
        if(s>"255" || s<"0"){
            return false;
        }
        return true;
    }
    
    bool isAlphaNumeric(string s){
        for(auto c : s){
            if((c>='0' && c<='9') || (c>='a' && c<='f') || (c>='A' && c<='F')){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    string checkValidIPv4(string IP){
        vector<string> groups = splitString(IP,'.');
        if(groups.size()!=4){
            return "Neither";
        }
        for(auto s : groups){
            if(!isNumeric(s) || s.size()==0 || s.size()>3 || (s.size()>1 && s[0]=='0')){
                return "Neither";
            }
        }
        return "IPv4";
    }
    
    string checkValidIPv6(string IP){
        vector<string> groups = splitString(IP,':');
        if(groups.size()!=8){
            return "Neither";
        }
        for(auto s : groups){
            if(!isAlphaNumeric(s) || s.size()==0 || s.size()>4){
                return "Neither";
            }
        }
        return "IPv6";
    }
    
    vector<string> splitString(string s,char token){
        vector<string> result;
        string current;
        for(auto c : s){
            if(c==token){
                result.push_back(current);
                current.clear();
            }
            else{
                current.push_back(c);
            }
        }
        result.push_back(current);
        return result;
    }    
    
};
