#include <iostream>

// Practice 10 — Andrew Bennett
// CIS 5 Week 10 · Gradebook tools

void printScores(const int scores[], int n) {
  for (int i = 0; i < n; i++) std::cout << scores[i] << " ";
  std::cout << "\n";
}

void curve(int scores[], int n, int points) {
  // iterate through the scores array and add value of points parameter to value at each index
  for(int i = 0; i < n; i++)
  {
    scores[i] += points;
  }
}

void minMax(const int scores[], int n, int& lo, int& hi) {
  // set both lo and hi to the value in the first index of scores array
  lo = scores[0];
  hi = scores[0];

  //iterate through the scores array
  for(int i = 0; i < n; i++)
  {
    //assign value at current index if it is lower than current value in lo
    if(lo > scores[i])
    {
      lo = scores[i];
    }
    //assign value at current index if it is higher than current value in hi
    if(hi < scores[i])
    {
      hi = scores[i];
    }
  }
}

bool findScore(const int scores[], int n, int target, int* where) {

  // check if where is currently assigned a non nullptr value
  if (where != nullptr)
  {
    //iterate through scores array
    for(int i = 0; i < n; i++)
    {
      // if current index's value is equal to the target, set dereferenced where value to current index and return true
      if (scores[i] == target)
      {
        *where = i;
        return true;
      }
    }
  }
  // if target is not found in the array or where value was equal to nullptr, return false
  return false;
}

int main() {
  int scores[5] = {72, 88, 95, 60, 81};
  const int N = 5;

  std::cout << "Before: ";
  printScores(scores, N);

  int lo = 0, hi = 0;
  minMax(scores, N, lo, hi);
  std::cout << "Low: " << lo << "  High: " << hi << "\n";

  curve(scores, N, 5);
  std::cout << "After curve +5: ";
  printScores(scores, N);

  int at = -1;
  if (findScore(scores, N, 100, &at)) std::cout << "100 found at index " << at << "\n";
  if (!findScore(scores, N, 50, nullptr)) std::cout << "50 not found\n";
  return 0;
}
