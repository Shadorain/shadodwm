static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",	"music",	        0,	11},
    //{"",    "mpdup"             0,  0},
    //{"",	"memory",	        10,	14}, 
    //{"",	"cpu",		        10,	18}, 
    //{"",	"nettraf",	        1,	16}, 
	{"",	"volume",	        0,	10},
	{"",	"clock",	        60,	1},
	{"",	"battery",	        5,	3},
	//{"",	"internet",	        5,	4},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
