#include"computerRoom.h"
using namespace std;

//无参构造
ComputerRoom::ComputerRoom()
{

}
//有参构造
ComputerRoom::ComputerRoom( string id, const int size)
{
	ComR_ID = id;
	ComR_Maxsize = size;
}