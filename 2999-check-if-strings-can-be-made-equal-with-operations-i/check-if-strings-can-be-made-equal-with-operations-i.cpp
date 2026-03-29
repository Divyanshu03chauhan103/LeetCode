class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        if(s1==s2) return true;
        string temp1=s1;
        swap(s1[0],s1[2]);
        if(s1==s2) return true;

        swap(s1[1],s1[3]);
        if(s1==s2) return true;
        swap(temp1[1],temp1[3]);
        if(temp1==s2) return true;
        swap(temp1[0],temp1[2]);
        return temp1==s2;
    }
};