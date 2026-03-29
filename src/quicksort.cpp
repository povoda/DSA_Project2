//
// Created by anast on 3/23/2026.
//
#include "quicksort.h"
using namespace std;

int partition(vector<Player>& arr, int low, int high){
  // Choosing the middle element as pivot to improve performance on sorted data
  int mid = low + (high - low) / 2;
  swap(arr[mid], arr[high]);
  int pivot = arr[high].Score;
  int i = low - 1;
  for(int j = low; j <= high - 1; j++){
    if(arr[j].Score > pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[high]);
  return i+1;
}

void quickSort(vector<Player>& arr, int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
