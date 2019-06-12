#include <iostream>
using namespace std;

void display(int **grid, int m, int n) {
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) {
			cout<<grid[i][j]<<"\t";
		}
		cout<<endl;
	}
}

bool isItSafe(int **grid, int x, int y, int m , int n) {
	return x>=0 and y>=0 and x<m and y<n and grid[x][y]==-1;
}

bool knightsTour(int **grid, int x, int y, int m, int n, int csf) {
	// base case
	if(csf == m*n-1) {
		grid[x][y] = csf;
		display(arr, m, n);
		return true;
	}

	if(isItSafe(grid, x+1, y+2, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x+1, y+2, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x-1, y+2, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x-1, y+2, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x+2, y-1, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x+2, y-1, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x+2, y+1, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x+2, y+1, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x+1, y-2, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x+1, y-2, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x-1, y-2, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x-1, y-2, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x-2, y-1, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x-2, y-1, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	if(isItSafe(grid, x-2, y+1, m, n)) {
		// Work
		grid[x][y] = csf;
		if(knightsTour(grid, x-2, y+1, m, n, csf+1)) {
			return true;
		} else {
			grid[x][y]=-1;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	int m, n;
	cin>>m>>n;
	int **arr = new int*[m];
	for(int i=0;i<m;i++) {
		arr[i] = new int[n];
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			arr[i][j]=-1;
		}
	}
	if(knightsTour(arr, 2, 2, m ,n, 0)==true) {
		
	} else {
		cout<<"No solution";
	}
	return 0;
}