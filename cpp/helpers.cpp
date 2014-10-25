#include <sstream>
#include <cstdlib>

namespace N {
	//user selects which square they want to move from/to
	void userSelectSquare(int arr[], string request){
		cout << request;
		istringstream iss;
		string userString, temp1, temp2;
		int row, column;
		getline(cin, userString);
		iss.str(userString);
		iss >> temp1 >> temp2;
		row = atoi(temp1.c_str());
		column = atoi(temp2.c_str());
		arr[0] = row;
		arr[1] = column;
		iss.str("");
		return;
		}
}