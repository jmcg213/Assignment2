#include <iostream>
#include <string>

using namespace std;

class DoughnutMode
{
  public:
    DoughnutMode();
    DoughnutMode(int height, int width, double den);
    ~DoughnutMode();
    void GenerateGrid(string input);
    void CountNeighbors();
    void UpdateGrid();
    string SetOutputType();
    string fileName;

    char** past;
    char** present;
    char** future;

  private:
    int density;
    int rows;
    int col;
    int generation;
    string oput;
};

//classic mode header
