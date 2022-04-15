#include<iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class tripleDES
{
    public:
        void encrypt(int key, string inFileName, string outFileName);
        void decrypt(int key, string inFileName, string outFileName);
};

// encrypt a file given in string file name and key in int
void tripleDES::encrypt(int key, string inFileName, string outFileName)
{
    //open the file
    ifstream inFile;
    inFile.open(inFileName.c_str());
    //check if the file is open
    if(!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    //create a new file
    ofstream outFile;
    outFile.open(outFileName.c_str());
    //check if the file is open
    if(!outFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    //read the file
    string line;
    while(getline(inFile, line))
    {
        //encrypt the line
        for(int i = 0; i < line.length(); i++)
        {
            //encrypt the character
            line[i] = line[i] + key;
        }
        //write the line to the new file
        outFile << line << endl;
    }
    //close the files
    inFile.close();
    outFile.close();
}

// decrypt a file given in string file name and key in int
void tripleDES::decrypt(int key, string inFileName, string outFileName)
{
    //open the file
    ifstream inFile;
    inFile.open(inFileName.c_str());
    //check if the file is open
    if(!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    //create a new file
    ofstream outFile;
    outFile.open(outFileName.c_str());
    //check if the file is open
    if(!outFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    //read the file
    string line;
    while(getline(inFile, line))
    {
        //decrypt the line
        for(int i = 0; i < line.length(); i++)
        {
            //decrypt the character
            line[i] = line[i] - key;
        }
        //write the line to the new file
        outFile << line << endl;
    }
    //close the files
    inFile.close();
    outFile.close();
}

int main(){
    int key1 = 3;
    int key2 = 16;
    int key3 = 25;
    int choice;

    string inFileName;
    string outFileName;

    tripleDES t;

    cout<<"\t\t\t\tTriple Data Encryption Standard Algoritm\n\n";
    while(choice!=0)
    {
        cout<<"Enter 1 to encrypt a file"<<endl;
        cout<<"Enter 2 to decrypt a file"<<endl;
        cout<<"Enter 0 to exit"<<endl;
		cout<<"\n>> ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter the file name to encrypt: ";
                cin>>inFileName;
                cout<<"Enter the file name to save the encrypted file: ";
                cin>>outFileName;

                t.encrypt(key1, inFileName, outFileName);                
                t.decrypt(key2, outFileName, inFileName); 
                t.encrypt(key3, inFileName, outFileName);
                //file encypted in temp.obj
                
                cout<<"Encrypted file in "<< outFileName <<"\n"<<endl;  
                break; 
            case 2:
                cout<<"Enter the file name to decrypt: ";
                cin>>inFileName;
                cout<<"Enter the file name to save the decrypted file: ";
                cin>>outFileName;
                
                t.decrypt(key2, inFileName, outFileName); 
                t.encrypt(key3, outFileName, inFileName);
                t.decrypt(key1, inFileName, outFileName); 
                //file decypted
                
                cout<<"Decrypted file in "<< outFileName <<"\n"<<endl; 
        }
    }
    return 0;
}
