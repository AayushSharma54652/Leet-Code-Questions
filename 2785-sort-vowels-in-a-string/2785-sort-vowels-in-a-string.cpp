class Solution {
public:
    string sortVowels(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a'||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u'){
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            else if(s[i] == 'A'||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U'){
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }
        
        string vowels;
        //Upper ke vowels
        for(int i=0;i<26;i++){
            char c = i + 'A';
            while(upper[i]){
                vowels += c;
                upper[i]--;
            }
        }
        //Lower ke liye
        
        for(int i=0;i<26;i++){
            char c = i + 'a';
            while(lower[i]){
                vowels += c;
                lower[i]--;
            }
        }
        
        int first = 0;
        int second = 0;
        while(second < vowels.size()){
            if(s[first] == '#'){
                s[first] = vowels[second];
                second++;
            }
            first++;
        }
        return s;
        
    }
};