#pragma once
#include <iostream>
#include <initializer_list> 
#include <vector>
class Sort
{
private:
    int arr[100], nrElemente;
	
public:
    Sort(int n, int mini, int maxi);
    Sort(std::initializer_list <int> valoare);
    Sort(int vector[], int n);
    Sort(int n, ...);
    Sort(const char s[100]);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
