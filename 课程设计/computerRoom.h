#pragma once
#include"globalFile.h"
#include<iostream>
#include<string>
using namespace std;
class ComputerRoom
{
public:
	string ComR_ID="";//�����ı��
	int ComR_Maxsize;//�������������

	ComputerRoom();

	ComputerRoom(string id, const int size);

};