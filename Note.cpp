//name of program : death note game in C++.
//goal : to make a game as i learn C++ online  
//how it works: the TV shows a random person's name. the player has to type the name. repeats.

//date = 27/06/2022
//author : Xidong Shangguan (Lola)

//references: http://www.fredosaurus.com/notes-cpp/io/readtextfile.html
#include <fstream> //file read write 
#include <iostream>//cout etc
#include <curses.h>//input to terminal etc 
#include <unistd.h> //time for linux 
#include <string.h> 
#include <algorithm>//trim strings 


using namespace std;
bool gameOver; //global

const int width = 20;
const int height = 8;

int score, total;

string name, line;
string note;

string names[100];

int ii = 0;

void ReadF()
{
    //file reading for array of random names 
    ifstream inFile;
    inFile.open("names.txt");
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string x;//next line?
    
    int i = 0;
    
    while ( !inFile.eof())
    {
        inFile >> x;
        names[i] = x;
        i++;
    }
}

void Setup()
{
    gameOver = false;
   
    note = "Death Note";
        
    //score = rand()%width;
    //cout<<score;
}

void Draw()  //for the name == line question ignore this function except cout << name 
{
    system("clear");

    cout << "below is TV";
    cout << "\n";

    for (int jj = 0; jj<width; jj++)//top
    {
        cout << "-";
    }

    cout << "\n";

    for (int jj= 0 ; jj<(height/2)-1 ; jj++)//first half
    {
        cout <<"|";
        cout << string( (width-2), ' ' );
        cout << "|";
        cout << "\n";
    }

    cout << "|";//name
  //  cout << string(5, ' ');
    cout << names[ii];      // (cout << name)----------
    
    cout << "\n";

    for (int kk= 0 ; kk<(height/2) ; kk++)//second half
    {
        cout <<"|";
        cout << string( (width-2), ' ' );
        cout << "|";
        cout << "\n";
    }
    
    for (int jj = 0; jj<width; jj++)//bottom
    {    
        cout << "-";
    }

    cout << "\n";

    cout << note;
    cout << "\n";   
    for (int jj = 0; jj<width; jj++)//top
    {
        cout << "-";
    }
    cout << "\n";

}

void Input()
{
    getline(cin, line);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    
}
void Logic()
{
    cout << line;
    names[ii].erase(remove(names[ii].begin(), names[ii].end(), ' '), names[ii].end());

    cout << names[ii];
    if (line.compare(names[ii]) ==0)
    {
        cout<< " has died\n";

        gameOver = true;

    }
    else if (line.compare(names[ii]) !=0)

    {
        
        cout << " is still alive!\n";
    }
}

int main()
{

    ReadF();    

    while (ii<62)
    {
        Setup();
        while (!gameOver)
        {
            Draw();
        
            Input();
            Logic();
            usleep(1000000);

        }
    
        ii++;
    }
    return 0;
}



