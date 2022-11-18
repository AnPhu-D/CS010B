#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void readData(const string &FileName, vector<double> &PathAngles, vector<double> &LiftCoeffs);

bool inBounds(double d, double lo, double hi) {
  return (d >= lo && d <= hi);
}

double lerp(const double &a, const double&b, const double &c, const double &fa, const double &fc);
void findClosestNeighbors(const double PathAngle, const vector<double> &PathAngles, double &HighNeighbor, double &LowNeighbor);
double interpolation(double PathAngle, const vector<double> &PathAngles, const vector<double> &LiftCoeffs);

bool isOrdered(const vector<double> &PathAngles);

int smallestValueIndexPast(vector<double> &v, int index);
void reorder(vector<double> &PathAngles, vector<double> &LiftCoeffs);

double getUserPathAngle(const double &Min, const double &Max);

double PA_Min,PA_Max;

int main(int argc, char *argv[]) {

  // Check if the args passed with the call are valid.
  if (argc != 2) {
    cout << "Error: Invalid number of arguments passed with call. Returnung with exit code 1." << endl;
    return 1;
  }

  // Initialize the vectors for PathAngles and CoLs.
  vector<double> PathAngles,LiftCoeffs;
  readData(argv[1], PathAngles, LiftCoeffs);
  if (PathAngles.size() == 0) {
    return 1;
  }

  string UserConfirm;
  do {

    double UserPathAngle;
    cout << "Enter a flight-path angle: ";
    cin >> UserPathAngle;
    cout << "You have chosen: " << UserPathAngle << " as the path angle." << endl;

    // Check if number is in bounds.
    if (inBounds(UserPathAngle, PA_Min, PA_Max)) {
      cout << "In bounds!" << endl;
      cout << "Result: " << interpolation(UserPathAngle, PathAngles, LiftCoeffs) << endl;
    } else {
      cout << "Error: Out of bounds!" << endl;
    }

    cout << "Would you like to enter another flight-path angle? ";
    cin >> UserConfirm;

    while (UserConfirm != "Yes" && UserConfirm != "No") {
      cout << "Invalid input; Please type [Yes] or [No]." << endl;
      cin >> UserConfirm;
    }

    if (UserConfirm == "No") {
      break;
    }

  } while(UserConfirm == "Yes");
  // Ask user for their path angle.
  

  return 0;

}

void readData(const string &FileName, vector<double> &PathAngles, vector<double> &LiftCoeffs) {
  // Create the inputstream and open the file.
  ifstream fin(FileName);

  // Check if the file was opened.
  if (!fin.is_open()) {
    cout << "Error opening " << FileName << endl;
    return;
  }

  double temp_pa,temp_col;

  // Manually conduct the first read.
  if (fin >> temp_pa) {
    PathAngles.push_back(temp_pa);

    // Initialize min/max to first angle.
    PA_Min = PathAngles.at(0);
    PA_Max = PathAngles.at(0);
  }
  if (fin >> temp_col) {
    LiftCoeffs.push_back(temp_col);
  }

  // While able to read input, write to vectors.
  // pa = PathAngles; col = Coefficient of Lifts
  while (fin >> temp_pa) {
    // Read in 2nd word on line into temp_col
    fin >> temp_col;

    // Push read values into vectors.
    PathAngles.push_back(temp_pa);
    LiftCoeffs.push_back(temp_col);

    if (temp_pa < PA_Min) {
      PA_Min = temp_pa;
    }

    if (temp_pa > PA_Max) {
      PA_Max = temp_pa;
    }

  }

  fin.close();

}

double lerp(const double &a, const double&b, const double &c, const double &fa, const double &fc) {
  return fa + ((b-a)/(c-a)) * (fc - fa);
}

void findClosestNeighbors(const double PathAngle, const vector<double> &PathAngles, int &LoIndex, int &HiIndex) {
  double HighNeighbor = PathAngles.at(PathAngles.size() - 1);
  double LowNeighbor = PathAngles.at(0);

  LoIndex = 0;
  HiIndex = 0;

  for (unsigned i = 0; i < PathAngles.size(); ++i) {
    double Current = PathAngles.at(i);

    if (Current < PathAngle) {
      double Diff = PathAngle - Current;
      double PDiff = PathAngle - LowNeighbor;

      if (Diff < PDiff) {
        LowNeighbor = Current;
        LoIndex = i;
      }
    } else if (Current > PathAngle) {
      double Diff = Current - PathAngle;
      double PDiff = HighNeighbor - PathAngle;

      if (Diff < PDiff) {
        HighNeighbor = Current;
        HiIndex = i;
      }
    } else if (Current == PathAngle) {
      HighNeighbor = Current;
      LowNeighbor = Current;

      HiIndex = i;
      LoIndex = i;

      return;
    }
  }
}

double interpolation(double PathAngle, const vector<double> &PathAngles, const vector<double> &LiftCoeffs) {

  for (unsigned i = 0; i < PathAngles.size(); ++i) {
    double temp_pa = PathAngles.at(i);

    if (temp_pa < PA_Min) {
      PA_Min = temp_pa;
    }

    if (temp_pa > PA_Max) {
      PA_Max = temp_pa;
    }

    if (PathAngle == temp_pa) {
      cout << "found in." << endl;
      cout << LiftCoeffs.at(i) << endl;
      return LiftCoeffs.at(i);
    }
  }

  // Find the closest neighbors.
  int LoInd,HiInd;
  findClosestNeighbors(PathAngle, PathAngles, LoInd, HiInd);

  double LerpResult = lerp(PathAngles.at(LoInd), PathAngle, PathAngles.at(HiInd), LiftCoeffs.at(LoInd), LiftCoeffs.at(HiInd));

  return LerpResult;

}

bool isOrdered(const vector<double> &PathAngles) {
  for (unsigned i = 1; i < PathAngles.size(); ++i) {
    if (PathAngles.at(i) < PathAngles.at(i-1)) {
      return false;
    }
  }
  return true;
}

int smallestValueIndexPast(vector<double> &v, int index) {
  int SmallestIndex = index;

  for (unsigned i = index + 1; i < v.size(); ++i) {
    // If smaller set si
    if (v.at(i) < v.at(SmallestIndex)) {
      SmallestIndex = i;
    }
  }

  return SmallestIndex;
}

void reorder(vector<double> &PathAngles, vector<double> &LiftCoeffs) {

  for (unsigned i = 0; i < PathAngles.size(); ++i) {
    int si = smallestValueIndexPast(PathAngles, i);

    swap(PathAngles.at(i), PathAngles.at(si));
    swap(LiftCoeffs.at(i), LiftCoeffs.at(si));
  }

}