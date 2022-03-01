#pragma once
#include <iostream>
#include <cstring>


bool PeselValidator(const char* Tpesel, int PESEL[]);
void printPesel(int PESEL[]);
int getCtrlNumber(int PESEL[]);
int getDay(int PESEL[]);
int getMonth(int PESEL[]);
int getYear(int PESEL[]);
int sprawdzrok(int ROK[]);


