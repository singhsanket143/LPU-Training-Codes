#include <iostream>
using namespace std;

	// The codes for foreground and background colours are:
	// 			foreground background
	// black        30         40
	// red          31         41
	// green        32         42
	// yellow       33         43
	// blue         34         44
	// magenta      35         45
	// cyan         36         46
	// white        37         47
	// Additionally, you can use these:
	// reset             0  (everything back to normal)
	// bold/bright       1  (often a brighter shade of the same colour)
	// underline         4
	// inverse           7  (swap foreground and background colours)
	// bold/bright off  21
	// underline off    24
	// inverse off      27
const string black("\033[0;30m");
const string bright_black("\033[1;30m");
const string red("\033[0;31m");
const string bright_red("\033[1;31m");
const string green("\033[0;32m");
const string yellow("\033[0;33m");
const string blue("\033[0;34m");
const string magenta("\033[0;35m");
const string cyan("\033[0;36m");
const string bright_cyan("\033[1;36m");
const string white("\033[0;37m");
const string black_bg("\033[0;40m");
const string bright_black_bg("\033[1;40m");
const string red_bg("\033[0;41m");
const string bright_red_bg("\033[1;41m");
const string green_bg("\033[0;42m");
const string yellow_bg("\033[0;43m");
const string blue_bg("\033[0;44m");
const string magenta_bg("\033[0;45m");
const string cyan_bg("\033[0;46m");
const string bright_cyan_bg("\033[1;46m");
const string white_bg("\033[0;47m");
const string reset_colors("\033[0m");
const string clear_screen_ansi("\033[2J");
const string win_clear_screen("cls");
const string linux_clear_screen("clear");
const string linux_block("\u25A0");
const char win_block = -2;
void sleep() {
	for(int i=0;i<50000000;i++);
}
void printPic(char** pic,int n,int m) {
    for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(pic[i][j]=='.')
				cout<<black<<win_block;
			else if(pic[i][j]=='#')
				cout<<red<<win_block;
			else if(pic[i][j]=='R')
				cout<<bright_red<<win_block;
			else
				cout<<bright_cyan<<pic[i][j];
		} cout<<endl;
	}
}

void fillColor(char ** pic,int i,int j,int n,int m) {
    if(i<0 || j<0 || i>=n || j>=m || pic[i][j]=='R' || pic[i][j]=='#') return;
    pic[i][j]='R';
	system(win_clear_screen.c_str());
    printPic(pic,n,m);
    sleep();
    fillColor(pic,i+1,j,n,m);
    fillColor(pic,i,j+1,n,m);
    fillColor(pic,i,j-1,n,m);
    fillColor(pic,i-1,j,n,m);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    char** pic=new char*[n];
    for(int i=0;i<n;i++) {
        pic[i]=new char[m+1];
        cin>>pic[i];
    } int i,j; cin>>i>>j;
    fillColor(pic,i,j,n,m);
	cout<<reset_colors;
}