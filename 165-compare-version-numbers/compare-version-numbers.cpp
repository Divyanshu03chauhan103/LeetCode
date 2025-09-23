class Solution {
public:
    int extract_num(const string &s, int &i){
        string num="";
        int n=s.size();

        while(i<n && s[i]!='.'){
            num+=s[i];
            i++;
        }
        return stoi(num);
    }

    int compareVersion(string version1, string version2) {
        vector<int> revision1;
        vector<int> revision2;

        for(int i=0;i<version1.size();){
            revision1.push_back(extract_num(version1,i));
            if(i<version1.size() && version1[i]=='.') i++;
        }

        for(int i=0;i<version2.size();){
            revision2.push_back(extract_num(version2,i));
            if(i<version2.size() && version2[i]=='.') i++;
        }

        int i=0;
        while(i<revision1.size() && i<revision2.size()){
            if(revision1[i]>revision2[i]) return 1;
            else if(revision1[i]<revision2[i]) return -1;
            i++;
        }

        while(i<revision1.size()){
            if(revision1[i]>0) return 1;
            i++;
        }

        while(i<revision2.size()){
            if(revision2[i]>0) return -1;
            i++;
        }

        return 0;
    }
};
