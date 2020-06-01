static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    /* {"",        "mpdup",                0,  44}, */
	{"   ",	"shadomusic",	        0,	11},
	{"|  ",	    "shadotime",	        30,	1},
	{"|  ",	    "shadovol",	            0,	10},
	{"",	    "shadobat",	            5,	3},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = "  ";
