#include <iostream>
#include <string>

using namespace std;

class ClassicMode
{
  public:
    ClassicMode();
    ClassicMode(int height, int width, double den);
    ~ClassicMode();
    void GenerateGrid(string input);
    void CountNeighbors();
    void UpdateGrid();
    string SetOutputType();
    char** past;
    char** present;
    char** future;
    string fileName;

  private:
    int density;
    int rows;
    int col;
    int generation;
    string oput;

};

//classic mode header
