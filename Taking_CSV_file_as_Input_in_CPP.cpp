#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream fin;
    fin.open("mempool.csv", ios::in);
    vector<string> id;
    vector<int> weight;
    vector<int> fee;
    vector<vector<string>> par;
    string word, line;
    getline(fin, line);
    cout << line << endl;

    while (getline(fin, line))
    {
        stringstream lineStream(line);

        getline(lineStream, word, ',');
        id.push_back(word);
        getline(lineStream, word, ',');
        fee.push_back(stoi(word));
        getline(lineStream, word, ',');
        weight.push_back(stoi(word));
        vector<string> temp;
        while (getline(lineStream, word, ';'))
        {
            temp.push_back(word);
        }
        par.push_back(temp);
    }
    for (int i = 0; i < id.size(); i++)
    {
        cout << id[i] << " "<<fee[i]<<" "<<weight[i]<<" ";
        for(int j=0;j<par[i].size();j++){
            cout<<par[i][j]<<" ";
        }
        cout<<endl;
    }
}