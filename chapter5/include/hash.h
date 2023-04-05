#ifndef HASH_H
#define HASH_H

#define Index unsigned int

Index HashChar(const char* Key, int TableSize);
Index HashChar2(const char* Key, int TableSize);
Index HashChar3(const char* Key, int TableSize);

Index Hash(int Key, int TableSize);

#endif