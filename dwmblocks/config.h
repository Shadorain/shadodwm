static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    //{"",    "mpdup",             0,  0},
	{"",	"music",	        0,	11},
	{"",	"volume",	        0,	10},
	{"",	"clock",	        60,	1},
	{"",	"battery",	        5,	3},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " ";
