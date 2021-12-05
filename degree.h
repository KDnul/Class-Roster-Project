#pragma once
#ifndef DEGREE_H // Header Guard
#define DEGREE_H // Header Guard

#include<iostream>

using namespace std;

enum Degree_Program {SECURITY, NETWORK, SOFTWARE};

// Parallel array to get strings for each degree program
static const string degreeProgramString[] = { "SECURITY", "NETWORK", "SOFTWARE" };

#endif // End of header guard
