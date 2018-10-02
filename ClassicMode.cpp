#include <iostream>
#include "ClassicMode.h"
#include "InputControl.h"
#include <unistd.h>
#include <fstream>
#include <string>

using namespace std;


ClassicMode::ClassicMode() //default constructor
{

}

ClassicMode::ClassicMode(int height, int width, double den)
{
  col = height;
  rows = width;
  density = den;
  generation = 0;
  oput = SetOutputType();

  past = new char*[height];
  for(int i = 0; i < height; i++)
    past[i] = new char[width];

  present = new char*[height];
  for(int i = 0; i < height; i++)
    present[i] = new char[width];

  future = new char*[height];
  for(int i = 0; i < height; i++)
    future[i] = new char[width];
}

ClassicMode::~ClassicMode()
{
  delete past;
  delete present;
  delete future;
}

void ClassicMode::GenerateGrid(string input)   //generates a grid if user does not implement one in their file
{
  if(oput == "console")
    cin.ignore();
  string temp;
  InputControl ic;
  if(input == "file")
  {
    present = ic.CountGrid(ic.GetFileName(), present);
  }
  else
  {
    cout << "Generation: " << generation << endl;  //starts at gen 0
    for(int i = 0; i < col; ++i)
    {
      for(int j = 0; j < rows; ++j)
      {
        if ((double)rand() / (double)RAND_MAX >= density / 100.0)
        {
          present[i][j] = '-';
          cout<<present[i][j];
        }
        else
        {
          present[i][j] = 'X';
          cout<<present[i][j];
        }
      }
      cout<<endl;
    }
    cout << "Let's go through the next generation. Press enter." << endl;
    if(oput == "console")
      cin.ignore();
  }
}

void ClassicMode::CountNeighbors()   //counts neighbors and then fills the future array with what is meant to happen
{
  int mates = 0;           //neighbors
  for(int i = 0; i < col; ++i)
  {
    for(int j = 0; j < rows; ++j)
    {
      if(j != 0 && present[i][j-1] == 'X') //checks the top place   ggg
        mates++;
      if(i != 0 && present[i-1][j] == 'X') //checks the left place   ggg
        mates++;
      if(j != rows-1 && present[i][j+1] == 'X')  //checks the bottom place   ggg
        mates++;
      if(i != col-1 && present[i+1][j] == 'X') //checks the right place   ggg
        mates++;
      if((i != 0 && j != 0) && present[i-1][j-1] == 'X') //checks top left place (diagonal top left)  ggg
        mates++;
      if((j != 0 && i != col-1) && present[i+1][j-1] == 'X') //checks top right place (diagonal top right)  ggg
        mates++;
      if((i != 0 && j != rows-1) && present[i-1][j+1] == 'X') //checks bottom left place (diagonal bottom left)  ggg
        mates++;
      if((j != rows-1 && i != col-1) && present[i+1][j+1] == 'X') //checks bottom right place (diagonal bottom right)  ggg
        mates++;
       //all of the above is checking number of neighbors


      if(mates <= 1)
        future[i][j] = '-';
      else if(mates == 2)
        future[i][j] = present[i][j];
      else if(mates == 3)
        future[i][j] = 'X';
      else
        future[i][j] = '-';

      mates = 0;
    }
  }
}

void ClassicMode::UpdateGrid()   //will iterate through a generation and display the new generation
{
  bool loopp = true;
  bool loopf = true;
  bool dashAll = true;
  CountNeighbors();
  if(oput == "console")
  {
    generation++;
    cout << "Generation: " << generation << endl;
    for(int i = 0; i < col; i++)
    {
      for(int j = 0; j < rows; j++)
      {
        if(present[i][j] != future[i][j] )   //checks if all elements are equal as it will then be an infinite loop
          loopf = false;

        if(past[i][j] != future[i][j])
          loopp = false;

        if(future[i][j] == 'X')   //checks if all elements are '-'s
          dashAll = false;

        past[i][j] = present[i][j];
        present[i][j] = future[i][j];
        cout << present[i][j];
      }
      cout << endl;
    }

    if(dashAll == true)
      cout << "Seems like all of your lifeforms died. Game Over." << endl;
    else if(loopf == true && dashAll == false)
      cout << "Congrats, you have won The Game of Life! Your civilization is sustainable!" << endl;
    else if(loopp == true && dashAll == false)
      cout << "Congrats, you have won The Game of Life! Your civilization is sustainable!" << endl;
    else
    {
      cout << "Let's go through the next generation. Press enter." << endl;
      if(oput == "console")
        cin.ignore();
      UpdateGrid();
    }
  }
  else if(oput == "file")
  {
    ofstream file;
    file.open(fileName);

    generation++;
    file << "Generation: " << generation << endl;
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < col; j++)
      {
        if(present[i][j] != future[i][j] )   //checks if all elements are equal as it will then be an infinite loop
          loopf = false;

        if(past[i][j] != future[i][j])
          loopp = false;

        if(present[i][j] == 'X')   //checks if all elements are '-'s
          dashAll = false;

        past[i][j] = present[i][j];
        present[i][j] = future[i][j];
        file << present[i][j];
      }
      file << endl;
    }

    if(dashAll == true)
      cout << "Seems like all of your lifeforms died." << endl;
    else if(loopf == true && dashAll == false)
      cout << "Congrats, you have won The Game of Life! Your civilization is sustainable!" << endl;
    else if(loopp == true && dashAll == false)
      cout << "Congrats, you have won The Game of Life! Your civilization is sustainable!" << endl;
    else
    {
      cout << "Let's go through the next generation. Press enter." << endl;
      if(oput == "console")
        cin.ignore();
      UpdateGrid();
    }
  }
}

string ClassicMode::SetOutputType()
{
  string fileName;
  string output;
  while(true)
  {
    cout<<"Would you like to output to a 'file' or to the 'console'?"<<endl;
    cin>>output;
    if(output == "file")
    {
      cout<<"Enter the file you would like to output to: "<<endl;
      cin>>fileName;
      ifstream file(fileName);
      if(file.fail())
      {
        cout<<"Invalid file! Please try again."<<endl;
        continue;
      }
      else
      {
        break;
      }
    }
    else if(output == "console")
    {
      break;
    }
    else
    {
      cout << "Invalid input, please try again.";
    }
  }
  return output;
}
