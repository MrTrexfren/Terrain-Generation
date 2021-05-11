#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

int grid[10][10] = {
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
}; 

void generate() {
	HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	
	for(int i = 0; i < 10; i++) {
		for(int n = 0; n < 10; n++) {
			int random_tile = rand() % 2;
			grid[i][n] = random_tile;
			cout << grid[i][n] << " ";
			for(int e = 0; e < 10; e++) {
				if(grid[i][n] == 0) {
				    SetConsoleTextAttribute(c, 10);
			    } else if(grid[i][n] == 1) {
				    SetConsoleTextAttribute(c, 11);
			    }
			    
			}
		}
		cout << endl;
	}
}

int main() {
	HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(grid[0][0] == 0) {
		SetConsoleTextAttribute(c, 10);
	} else if(grid[0][0] == 1) {
		SetConsoleTextAttribute(c, 11);
	}
	
	cout << "Green is Land\nBlue is Water\n" << endl;
	
	bool exit = false;
	generate();
	while(!exit){
		if(grid[0][0] == 0) {
		    SetConsoleTextAttribute(c, 10);
	    } else if(grid[0][0] == 1) {
		    SetConsoleTextAttribute(c, 11);
        }
		string choice;
    	cout << "\nGenerate again? [y/n] ";
    	cin >> choice;
    	
    	if(choice == "y") {
	    	system("cls");
		    generate();
	    } else if(choice == "n") {
	    	exit = true;
	    }
	}
	

	return 0;
}
