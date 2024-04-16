#pragma once

#include"stdafx.h"
#include"Constans.h"

void shiftLeft(int arr[], const int n, int number_of_shifts);
void shiftLeft(double arr[], const int n, int number_of_shift);
void shiftLeft(char arr[], const int n, int number_of_shifts);
void shiftLeft(char arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);      //построчный
void shiftLeft_arr1(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts); //сквозной
void shiftLeft_arr2(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts); //построчный
void shiftLeft_arr3(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts); //сквозной
void shiftLeft(double arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);