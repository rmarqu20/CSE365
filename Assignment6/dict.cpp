#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    fstream myDict;
    string word, fileName;
    int defs = 0;

    for(int i = 1; i < argc; i++)
    {
        string command = argv[i];
        if(command.compare("-d") != 1)
        {
            fileName = "dictionary.txt";
            myDict.open(fileName);
            while (getline(myDict,word))
            {
                defs++;
            }
            cout << fileName << " has " << defs << " words.\n";
        }

        if(command.compare("-d") == 0)
        {
            fileName = argv[i + 1];
            myDict.open(fileName);
            while (getline(myDict,word))
            {
                defs++;
            }
            cout << fileName << " has " << defs << " words.\n";
        }

        if(command.compare("-p") == 0)
        {
            string search = argv[i + 1];
            int numWords = 0;
            int maxWords = 1000;

            command = argv[i+ 1];
            if(command.compare("-n") == 0)
            {
                string max = argv[4];
                stringstream strStream(max);
                strStream >> maxWords;
            }

            myDict.open(fileName);
            while (getline(myDict,word) || numWords != maxWords)
            {
                if(word.find(search,0) != string::npos)
                {
                    cout << word << "\n";
                    numWords++;
                }
            }
        }
        //if(command.compare("-s") == 0)
        {
            
        }
    }
    myDict.close();
    return 0;
}
