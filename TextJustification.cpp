// TC : O(n*m), SC : O(n)

class Solution {
public:
    int MAX_WIDTH;
    string findLine(int i, int j, int eachGaddaSpace, int extraSpaceGadda,vector<string>&  words){
        string line = "";

        for(int k=i; k<j; k++){
            line += words[k];

            if(k == j-1){ 
                continue;
            }

            for(int z = 1; z<=eachGaddaSpace; z++)
                line += " ";
            
            if(extraSpaceGadda > 0){
                line += " ";
                extraSpaceGadda--;
            }
        }

        while(line.length() < MAX_WIDTH){
            line += " ";
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();

        MAX_WIDTH = maxWidth;

        int i=0;
        while(i<n){
            int lettersCount = words[i].length();
            int j = i+1;
            int gadde = 0;

            while(j<n && words[j].length() + 1 + gadde + lettersCount <= maxWidth){
                lettersCount += words[j].length();
                gadde += 1;
                j++;
            }

            int remainingGadde = maxWidth - lettersCount;
            int eachGaddaSpace = gadde == 0 ? 0 : remainingGadde / gadde;
            int extraSpaceGadda =  gadde == 0 ? 0 : remainingGadde % gadde;

            if(j == n){
                eachGaddaSpace = 1;
                extraSpaceGadda = 0;
            }

            res.push_back(findLine(i, j, eachGaddaSpace, extraSpaceGadda, words));

            i = j;
        }

        return res;
    }
};