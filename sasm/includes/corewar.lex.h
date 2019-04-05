#ifndef _COREWAR_LEX_H_
#define _COREWAR_LEX_H_

#include <stdint.h>
#include <stdbool.h>


static char const*
g_corewar_token_name_table[30] = {
	"NAME",
	"COMMENT",
	"STR",
	"LABEL",
	"REGT",
	"INDIRECT",
	"DIRECT",
	"SEP",
	"LFORK",
	"STI",
	"FORK",
	"LLD",
	"LD",
	"ADD",
	"ZJMP",
	"SUB",
	"LDI",
	"OR",
	"ST",
	"AFF",
	"LIVE",
	"XOR",
	"LLDI",
	"AND",
	"NEWLINE",
	"UNKNOWN",
	"SCOMMENT",
	"SPACE",
	"ERROR",
	"EOF",
};

#ifndef _ONLY_STATE_TOKEN_

#define START_STATE	1
#define DEAD_STATE	0

#define ELLIPSIS(X,Y)	[X ... Y]

static uint8_t
g_corewar_state_table[85][256] = {
	{
		[0]=0,
	},
	{
		[122]=21,
		[121]=14,
		[120]=20,
		ELLIPSIS(116, 119) = 14,
		[115]=19,
		[114]=18,
		ELLIPSIS(112, 113) = 14,
		[111]=17,
		ELLIPSIS(109, 110) = 14,
		[108]=16,
		ELLIPSIS(103, 107) = 14,
		[102]=15,
		ELLIPSIS(98, 101) = 14,
		[97]=13,
		[95]=14,
		[90]=21,
		[89]=14,
		[88]=20,
		ELLIPSIS(84, 87) = 14,
		[83]=19,
		[82]=18,
		ELLIPSIS(80, 81) = 14,
		[79]=17,
		ELLIPSIS(77, 78) = 14,
		[76]=16,
		ELLIPSIS(71, 75) = 14,
		[70]=15,
		ELLIPSIS(66, 69) = 14,
		[65]=13,
		[59]=12,
		[58]=11,
		ELLIPSIS(48, 57) = 10,
		[46]=9,
		[45]=7,
		[44]=8,
		[43]=7,
		[37]=6,
		[35]=5,
		[34]=4,
		[32]=2,
		[10]=3,
		[9]=2,
	},
	{
		[32]=22,
		[9]=22,
	},
	{
		[0]=0,
	},
	{
		ELLIPSIS(35, 255) = 23,
		[34]=24,
		ELLIPSIS(11, 33) = 23,
		ELLIPSIS(0, 9) = 23,
	},
	{
		ELLIPSIS(11, 255) = 25,
		ELLIPSIS(0, 9) = 25,
	},
	{
		[58]=28,
		ELLIPSIS(48, 57) = 27,
		[45]=26,
		[43]=26,
	},
	{
		ELLIPSIS(48, 57) = 29,
	},
	{
		[0]=0,
	},
	{
		[110]=31,
		[99]=30,
		[78]=31,
		[67]=30,
	},
	{
		ELLIPSIS(97, 122) = 34,
		[95]=34,
		ELLIPSIS(65, 90) = 34,
		[58]=33,
		ELLIPSIS(48, 57) = 32,
	},
	{
		ELLIPSIS(97, 122) = 35,
		[95]=35,
		ELLIPSIS(65, 90) = 35,
		ELLIPSIS(48, 57) = 35,
	},
	{
		ELLIPSIS(11, 255) = 25,
		ELLIPSIS(0, 9) = 25,
	},
	{
		ELLIPSIS(111, 122) = 36,
		[110]=39,
		ELLIPSIS(103, 109) = 36,
		[102]=38,
		[101]=36,
		[100]=37,
		ELLIPSIS(97, 99) = 36,
		[95]=36,
		ELLIPSIS(79, 90) = 36,
		[78]=39,
		ELLIPSIS(71, 77) = 36,
		[70]=38,
		[69]=36,
		[68]=37,
		ELLIPSIS(65, 67) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(112, 122) = 36,
		[111]=40,
		ELLIPSIS(97, 110) = 36,
		[95]=36,
		ELLIPSIS(80, 90) = 36,
		[79]=40,
		ELLIPSIS(65, 78) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(109, 122) = 36,
		[108]=44,
		ELLIPSIS(106, 107) = 36,
		[105]=43,
		ELLIPSIS(103, 104) = 36,
		[102]=42,
		[101]=36,
		[100]=41,
		ELLIPSIS(97, 99) = 36,
		[95]=36,
		ELLIPSIS(77, 90) = 36,
		[76]=44,
		ELLIPSIS(74, 75) = 36,
		[73]=43,
		ELLIPSIS(71, 72) = 36,
		[70]=42,
		[69]=36,
		[68]=41,
		ELLIPSIS(65, 67) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(115, 122) = 36,
		[114]=45,
		ELLIPSIS(97, 113) = 36,
		[95]=36,
		ELLIPSIS(83, 90) = 36,
		[82]=45,
		ELLIPSIS(65, 81) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(50, 57) = 47,
		[49]=46,
		[48]=36,
	},
	{
		ELLIPSIS(118, 122) = 36,
		[117]=49,
		[116]=48,
		ELLIPSIS(97, 115) = 36,
		[95]=36,
		ELLIPSIS(86, 90) = 36,
		[85]=49,
		[84]=48,
		ELLIPSIS(65, 83) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(112, 122) = 36,
		[111]=50,
		ELLIPSIS(97, 110) = 36,
		[95]=36,
		ELLIPSIS(80, 90) = 36,
		[79]=50,
		ELLIPSIS(65, 78) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(107, 122) = 36,
		[106]=51,
		ELLIPSIS(97, 105) = 36,
		[95]=36,
		ELLIPSIS(75, 90) = 36,
		[74]=51,
		ELLIPSIS(65, 73) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		[32]=22,
		[9]=22,
	},
	{
		ELLIPSIS(35, 255) = 23,
		[34]=24,
		ELLIPSIS(11, 33) = 23,
		ELLIPSIS(0, 9) = 23,
	},
	{
		[0]=0,
	},
	{
		ELLIPSIS(11, 255) = 25,
		ELLIPSIS(0, 9) = 25,
	},
	{
		ELLIPSIS(48, 57) = 27,
	},
	{
		ELLIPSIS(48, 57) = 52,
	},
	{
		ELLIPSIS(97, 122) = 53,
		[95]=53,
		ELLIPSIS(65, 90) = 53,
		ELLIPSIS(48, 57) = 53,
	},
	{
		ELLIPSIS(48, 57) = 54,
	},
	{
		[111]=55,
		[79]=55,
	},
	{
		[97]=56,
		[65]=56,
	},
	{
		ELLIPSIS(97, 122) = 34,
		[95]=34,
		ELLIPSIS(65, 90) = 34,
		[58]=33,
		ELLIPSIS(48, 57) = 32,
	},
	{
		[0]=0,
	},
	{
		ELLIPSIS(97, 122) = 34,
		[95]=34,
		ELLIPSIS(65, 90) = 34,
		[58]=33,
		ELLIPSIS(48, 57) = 34,
	},
	{
		ELLIPSIS(97, 122) = 57,
		[95]=57,
		ELLIPSIS(65, 90) = 57,
		ELLIPSIS(48, 57) = 57,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(101, 122) = 36,
		[100]=58,
		ELLIPSIS(97, 99) = 36,
		[95]=36,
		ELLIPSIS(69, 90) = 36,
		[68]=58,
		ELLIPSIS(65, 67) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(103, 122) = 36,
		[102]=59,
		ELLIPSIS(97, 101) = 36,
		[95]=36,
		ELLIPSIS(71, 90) = 36,
		[70]=59,
		ELLIPSIS(65, 69) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(101, 122) = 36,
		[100]=60,
		ELLIPSIS(97, 99) = 36,
		[95]=36,
		ELLIPSIS(69, 90) = 36,
		[68]=60,
		ELLIPSIS(65, 67) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(115, 122) = 36,
		[114]=61,
		ELLIPSIS(97, 113) = 36,
		[95]=36,
		ELLIPSIS(83, 90) = 36,
		[82]=61,
		ELLIPSIS(65, 81) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(106, 122) = 36,
		[105]=62,
		ELLIPSIS(97, 104) = 36,
		[95]=36,
		ELLIPSIS(74, 90) = 36,
		[73]=62,
		ELLIPSIS(65, 72) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(112, 122) = 36,
		[111]=63,
		ELLIPSIS(97, 110) = 36,
		[95]=36,
		ELLIPSIS(80, 90) = 36,
		[79]=63,
		ELLIPSIS(65, 78) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(119, 122) = 36,
		[118]=64,
		ELLIPSIS(97, 117) = 36,
		[95]=36,
		ELLIPSIS(87, 90) = 36,
		[86]=64,
		ELLIPSIS(65, 85) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(101, 122) = 36,
		[100]=65,
		ELLIPSIS(97, 99) = 36,
		[95]=36,
		ELLIPSIS(69, 90) = 36,
		[68]=65,
		ELLIPSIS(65, 67) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(55, 57) = 36,
		ELLIPSIS(48, 54) = 66,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(106, 122) = 36,
		[105]=67,
		ELLIPSIS(97, 104) = 36,
		[95]=36,
		ELLIPSIS(74, 90) = 36,
		[73]=67,
		ELLIPSIS(65, 72) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(99, 122) = 36,
		[98]=68,
		[97]=36,
		[95]=36,
		ELLIPSIS(67, 90) = 36,
		[66]=68,
		[65]=36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(115, 122) = 36,
		[114]=69,
		ELLIPSIS(97, 113) = 36,
		[95]=36,
		ELLIPSIS(83, 90) = 36,
		[82]=69,
		ELLIPSIS(65, 81) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(110, 122) = 36,
		[109]=70,
		ELLIPSIS(97, 108) = 36,
		[95]=36,
		ELLIPSIS(78, 90) = 36,
		[77]=70,
		ELLIPSIS(65, 76) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(48, 57) = 52,
	},
	{
		ELLIPSIS(97, 122) = 71,
		[95]=71,
		ELLIPSIS(65, 90) = 71,
		ELLIPSIS(48, 57) = 71,
	},
	{
		ELLIPSIS(48, 57) = 54,
	},
	{
		[109]=72,
		[77]=72,
	},
	{
		[109]=73,
		[77]=73,
	},
	{
		ELLIPSIS(97, 122) = 57,
		[95]=57,
		ELLIPSIS(65, 90) = 57,
		ELLIPSIS(48, 57) = 57,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(108, 122) = 36,
		[107]=74,
		ELLIPSIS(97, 106) = 36,
		[95]=36,
		ELLIPSIS(76, 90) = 36,
		[75]=74,
		ELLIPSIS(65, 74) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(115, 122) = 36,
		[114]=75,
		ELLIPSIS(97, 113) = 36,
		[95]=36,
		ELLIPSIS(83, 90) = 36,
		[82]=75,
		ELLIPSIS(65, 81) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(102, 122) = 36,
		[101]=76,
		ELLIPSIS(97, 100) = 36,
		[95]=36,
		ELLIPSIS(70, 90) = 36,
		[69]=76,
		ELLIPSIS(65, 68) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(106, 122) = 36,
		[105]=77,
		ELLIPSIS(97, 104) = 36,
		[95]=36,
		ELLIPSIS(74, 90) = 36,
		[73]=77,
		ELLIPSIS(65, 72) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(113, 122) = 36,
		[112]=78,
		ELLIPSIS(97, 111) = 36,
		[95]=36,
		ELLIPSIS(81, 90) = 36,
		[80]=78,
		ELLIPSIS(65, 79) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 71,
		[95]=71,
		ELLIPSIS(65, 90) = 71,
		ELLIPSIS(48, 57) = 71,
	},
	{
		[109]=79,
		[77]=79,
	},
	{
		[101]=80,
		[69]=80,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(108, 122) = 36,
		[107]=81,
		ELLIPSIS(97, 106) = 36,
		[95]=36,
		ELLIPSIS(76, 90) = 36,
		[75]=81,
		ELLIPSIS(65, 74) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		[101]=82,
		[69]=82,
	},
	{
		[0]=0,
	},
	{
		ELLIPSIS(97, 122) = 36,
		[95]=36,
		ELLIPSIS(65, 90) = 36,
		[58]=33,
		ELLIPSIS(48, 57) = 36,
	},
	{
		[110]=83,
		[78]=83,
	},
	{
		[116]=84,
		[84]=84,
	},
	{
		[0]=0,
	},
};

static uint8_t
g_corewar_final_table[66][2] = {
	{2, 27},
	{3, 24},
	{5, 26},
	{8, 7},
	{10, 5},
	{12, 26},
	{13, 25},
	{14, 25},
	{15, 25},
	{16, 25},
	{17, 25},
	{18, 25},
	{19, 25},
	{20, 25},
	{21, 25},
	{22, 27},
	{24, 2},
	{25, 26},
	{27, 6},
	{29, 5},
	{32, 5},
	{33, 3},
	{35, 5},
	{36, 25},
	{37, 25},
	{38, 25},
	{39, 25},
	{40, 25},
	{41, 12},
	{42, 25},
	{43, 25},
	{44, 25},
	{45, 17},
	{46, 4},
	{47, 4},
	{48, 18},
	{49, 25},
	{50, 25},
	{51, 25},
	{52, 6},
	{53, 6},
	{54, 5},
	{57, 5},
	{58, 13},
	{59, 19},
	{60, 23},
	{61, 25},
	{62, 16},
	{63, 25},
	{64, 25},
	{65, 11},
	{66, 4},
	{67, 9},
	{68, 15},
	{69, 21},
	{70, 25},
	{71, 6},
	{74, 10},
	{75, 25},
	{76, 20},
	{77, 22},
	{78, 14},
	{80, 0},
	{81, 8},
	{84, 1},
	{0},
};

#define LOOK_TABLE_NOT_DEFINE	

static int8_t
g_corewar_skip_table[3] = {
	26,
	27,
	-1,
};

#endif /* _ONLY_STATE_TOKEN_ */
#endif /* _COREWAR_LEX_H_ */
