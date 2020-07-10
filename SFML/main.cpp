/*****************************************************************//**
 * \file   main.cpp
 * \brief  Main function that calls and runs an instance of the canvas
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#include "Globals.cpp"

int main(int argc, char*argv[])
{
	CCanvas::instance().Run();
	return 0;
}