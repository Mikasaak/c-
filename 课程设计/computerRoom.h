#pragma once
#include"globalFile.h"
#include<iostream>
#include<string>
using namespace std;
class ComputerRoom
{
public:
	string ComR_ID="";//机房的编号
	int ComR_Maxsize;//机房的最大容量

	ComputerRoom();

	ComputerRoom(string id, const int size);

};