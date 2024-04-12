
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "FarmData.h"
#include "View.h"

using namespace std;

class Control {
		
	public:
		
		void launch();

	
	private:	
		
		FarmData farmData;
		View view;

		static const vector<string> menu;

};
#endif