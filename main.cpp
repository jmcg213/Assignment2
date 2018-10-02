#include <iostream>
#include <string>
#include "InputControl.h"
#include "MirrorMode.h"
#include "DoughnutMode.h"
#include "ClassicMode.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  InputControl ic;
  string gameType;

  cout<<"Welcome to the game of life where we'll simulate dna growth!"<<endl;

  string fileName = ic.SetInputType();

  while(true)
  {
    cout<<"What game mode would you like to run? 'Classic', 'Doughnut', or 'Mirror'"<<endl;
    cin>>gameType;

    if(gameType == "Classic" || gameType == "classic")
    {
      ClassicMode cm(ic.GetHeight(), ic.GetWidth(), ic.GetDensity());
      cm.GenerateGrid(fileName);
      cm.UpdateGrid();
      break;
    }
    else if(gameType == "Doughnut" || gameType == "doughnut")
    {
      DoughnutMode gm(ic.GetHeight(), ic.GetWidth(), ic.GetDensity());
      gm.GenerateGrid(fileName);
      gm.UpdateGrid();
      break;
    }
    else if(gameType == "Mirror" || gameType == "mirror")
    {
      MirrorMode mm(ic.GetHeight(), ic.GetWidth(), ic.GetDensity());
      mm.GenerateGrid(fileName);
      mm.UpdateGrid();
      break;
    }
    else
    {
      cout << "Invalid input. Please try again." << endl;
    }
  }
}
