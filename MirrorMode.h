#include <iostream>
#include <string>

using namespace std;

class MirrorMode
{
  public:
    MirrorMode();
    MirrorMode(int height, int width, double den);
    ~MirrorMode();
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
