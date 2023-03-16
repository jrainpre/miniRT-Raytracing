#include "miniRT.h"

/*
Deterministic Finite Automaton:
https://automatonsimulator.com/#%7B%22type%22%3A%22DFA%22%2C%22dfa%22%3A%7B%22transitions%22%3A%7B%22start%22%3A%7B%22%20%22%3A%22start%22%2C%22c%22%3A%22s0%22%7D%2C%22s0%22%3A%7B%22y%22%3A%22s14%22%7D%2C%22s1%22%3A%7B%220%22%3A%22s3%22%2C%22%20%22%3A%22s1%22%2C%22-%22%3A%22s41%22%7D%2C%22s3%22%3A%7B%220%22%3A%22s3%22%2C%22.%22%3A%22s5%22%2C%22%2C%22%3A%22s15%22%7D%2C%22s5%22%3A%7B%220%22%3A%22s8%22%7D%2C%22s8%22%3A%7B%220%22%3A%22s8%22%2C%22%2C%22%3A%22s15%22%7D%2C%22s6%22%3A%7B%220%22%3A%22s44%22%2C%22%20%22%3A%22s6%22%7D%2C%22s9%22%3A%7B%220%22%3A%22s9%22%2C%22%2C%22%3A%22s10%22%7D%2C%22s10%22%3A%7B%220%22%3A%22s4%22%7D%2C%22s4%22%3A%7B%220%22%3A%22s4%22%2C%22%2C%22%3A%22s11%22%7D%2C%22s11%22%3A%7B%220%22%3A%22s7%22%7D%2C%22s7%22%3A%7B%220%22%3A%22s7%22%2C%22%20%22%3A%22s13%22%2C%22n%22%3A%22s12%22%7D%2C%22s13%22%3A%7B%22%20%22%3A%22s13%22%2C%22n%22%3A%22s12%22%7D%2C%22s14%22%3A%7B%22%20%22%3A%22s1%22%7D%2C%22s15%22%3A%7B%220%22%3A%22s16%22%2C%22-%22%3A%22s42%22%7D%2C%22s16%22%3A%7B%220%22%3A%22s16%22%2C%22.%22%3A%22s17%22%2C%22%2C%22%3A%22s19%22%7D%2C%22s17%22%3A%7B%220%22%3A%22s18%22%7D%2C%22s18%22%3A%7B%220%22%3A%22s18%22%2C%22%2C%22%3A%22s19%22%7D%2C%22s19%22%3A%7B%220%22%3A%22s20%22%2C%22-%22%3A%22s43%22%7D%2C%22s20%22%3A%7B%220%22%3A%22s20%22%2C%22.%22%3A%22s21%22%2C%22%20%22%3A%22s23%22%7D%2C%22s21%22%3A%7B%220%22%3A%22s22%22%7D%2C%22s22%22%3A%7B%220%22%3A%22s22%22%2C%22%20%22%3A%22s23%22%7D%2C%22s23%22%3A%7B%220%22%3A%22s2%22%2C%22%20%22%3A%22s23%22%2C%22-%22%3A%22s38%22%7D%2C%22s24%22%3A%7B%220%22%3A%22s24%22%2C%22.%22%3A%22s25%22%2C%22%20%22%3A%22s6%22%7D%2C%22s25%22%3A%7B%220%22%3A%22s26%22%7D%2C%22s26%22%3A%7B%220%22%3A%22s26%22%2C%22%20%22%3A%22s6%22%7D%2C%22s37%22%3A%7B%220%22%3A%22s24%22%2C%22%20%22%3A%22s37%22%7D%2C%22s34%22%3A%7B%22%20%22%3A%22s37%22%2C%22.%22%3A%22s35%22%7D%2C%22s36%22%3A%7B%220%22%3A%22s36%22%2C%22%20%22%3A%22s37%22%7D%2C%22s35%22%3A%7B%220%22%3A%22s36%22%7D%2C%22s38%22%3A%7B%220%22%3A%22s2%22%7D%2C%22s2%22%3A%7B%22.%22%3A%22s27%22%2C%22%2C%22%3A%22s29%22%7D%2C%22s27%22%3A%7B%220%22%3A%22s28%22%7D%2C%22s28%22%3A%7B%220%22%3A%22s28%22%2C%22%2C%22%3A%22s29%22%7D%2C%22s29%22%3A%7B%220%22%3A%22s30%22%2C%22-%22%3A%22s39%22%7D%2C%22s39%22%3A%7B%220%22%3A%22s30%22%7D%2C%22s30%22%3A%7B%22.%22%3A%22s31%22%2C%22%2C%22%3A%22s33%22%7D%2C%22s31%22%3A%7B%220%22%3A%22s32%22%7D%2C%22s32%22%3A%7B%220%22%3A%22s32%22%2C%22%2C%22%3A%22s33%22%7D%2C%22s33%22%3A%7B%220%22%3A%22s34%22%2C%22-%22%3A%22s40%22%7D%2C%22s40%22%3A%7B%220%22%3A%22s34%22%7D%2C%22s41%22%3A%7B%220%22%3A%22s3%22%7D%2C%22s42%22%3A%7B%220%22%3A%22s16%22%7D%2C%22s43%22%3A%7B%220%22%3A%22s20%22%7D%2C%22s44%22%3A%7B%220%22%3A%22s44%22%2C%22.%22%3A%22s45%22%2C%22%20%22%3A%22s47%22%7D%2C%22s45%22%3A%7B%220%22%3A%22s46%22%7D%2C%22s46%22%3A%7B%220%22%3A%22s46%22%2C%22%20%22%3A%22s47%22%7D%2C%22s47%22%3A%7B%220%22%3A%22s9%22%2C%22%20%22%3A%22s47%22%7D%7D%2C%22startState%22%3A%22start%22%2C%22acceptStates%22%3A%5B%22s12%22%5D%7D%2C%22states%22%3A%7B%22start%22%3A%7B%7D%2C%22s0%22%3A%7B%22top%22%3A435%2C%22left%22%3A0%2C%22displayId%22%3A%22CY_IDENTIFIER_1%22%7D%2C%22s14%22%3A%7B%22top%22%3A515%2C%22left%22%3A0%2C%22displayId%22%3A%22CY_IDENTIFIER_2%22%7D%2C%22s1%22%3A%7B%22top%22%3A66%2C%22left%22%3A31%2C%22displayId%22%3A%22CY_SPACE_1%22%7D%2C%22s3%22%3A%7B%22top%22%3A74%2C%22left%22%3A253%2C%22displayId%22%3A%22CY_ORIG_X_BEFORE_DECIMAL%22%7D%2C%22s41%22%3A%7B%22top%22%3A14%2C%22left%22%3A177%2C%22displayId%22%3A%22CY_ORIG_X_SIGN%22%7D%2C%22s5%22%3A%7B%22top%22%3A172%2C%22left%22%3A257%2C%22displayId%22%3A%22CY_ORIG_X_DECIMAL%22%7D%2C%22s15%22%3A%7B%22top%22%3A177%2C%22left%22%3A501%2C%22displayId%22%3A%22CY_COMMA_1%22%7D%2C%22s8%22%3A%7B%22top%22%3A303%2C%22left%22%3A240%2C%22displayId%22%3A%22CY_ORIG_X_AFTER_DECIMAL%22%7D%2C%22s6%22%3A%7B%22top%22%3A184%2C%22left%22%3A1964%2C%22displayId%22%3A%22CY_SPACE_4%22%7D%2C%22s44%22%3A%7B%22top%22%3A426%2C%22left%22%3A1755%2C%22displayId%22%3A%22CY_HEIGHT_BEFORE_DECIMAL%22%7D%2C%22s9%22%3A%7B%22top%22%3A81%2C%22left%22%3A2211%2C%22displayId%22%3A%22CY_RED%22%7D%2C%22s10%22%3A%7B%22top%22%3A183%2C%22left%22%3A2189%2C%22displayId%22%3A%22CY_COMMA_5%22%7D%2C%22s4%22%3A%7B%22top%22%3A305%2C%22left%22%3A2279%2C%22displayId%22%3A%22CY_GREEN%22%7D%2C%22s11%22%3A%7B%22top%22%3A411%2C%22left%22%3A2288%2C%22displayId%22%3A%22CY_COMMA_6%22%7D%2C%22s7%22%3A%7B%22top%22%3A531%2C%22left%22%3A2408%2C%22displayId%22%3A%22CY_BLUE%22%7D%2C%22s13%22%3A%7B%22top%22%3A290%2C%22left%22%3A2610%2C%22displayId%22%3A%22CY_SPACE_6%22%7D%2C%22s12%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A532%2C%22left%22%3A2650%2C%22displayId%22%3A%22CY_ACCEPT%22%7D%2C%22s16%22%3A%7B%22top%22%3A72%2C%22left%22%3A716%2C%22displayId%22%3A%22CY_ORIG_Y_BEFORE_DECIMAL%22%7D%2C%22s42%22%3A%7B%22top%22%3A16%2C%22left%22%3A561%2C%22displayId%22%3A%22CY_ORIG_Y_SIGN%22%7D%2C%22s17%22%3A%7B%22top%22%3A166%2C%22left%22%3A729%2C%22displayId%22%3A%22CY_ORIG_Y_DECIMAL%22%7D%2C%22s19%22%3A%7B%22top%22%3A169%2C%22left%22%3A975%2C%22displayId%22%3A%22CY_COMMA_2%22%7D%2C%22s18%22%3A%7B%22top%22%3A299%2C%22left%22%3A724%2C%22displayId%22%3A%22CY_ORIG_Y_AFTER_DECIMAL%22%7D%2C%22s20%22%3A%7B%22top%22%3A81%2C%22left%22%3A1237%2C%22displayId%22%3A%22CY_ORIG_Z_BEFORE_DECIMAL%22%7D%2C%22s43%22%3A%7B%22top%22%3A16%2C%22left%22%3A1091%2C%22displayId%22%3A%22CY_ORIG_Z_SIGN%22%7D%2C%22s21%22%3A%7B%22top%22%3A183%2C%22left%22%3A1202%2C%22displayId%22%3A%22CY_ORIG_Z_DECIMAL%22%7D%2C%22s23%22%3A%7B%22top%22%3A185%2C%22left%22%3A1471%2C%22displayId%22%3A%22CY_SPACE_2%22%7D%2C%22s22%22%3A%7B%22top%22%3A310%2C%22left%22%3A1206%2C%22displayId%22%3A%22CY_ORIG_Z_AFTER_DECIMAL%22%7D%2C%22s2%22%3A%7B%22top%22%3A431%2C%22left%22%3A233%2C%22displayId%22%3A%22CY_AXIS_X_BEFORE_DECIMAL%22%7D%2C%22s38%22%3A%7B%22top%22%3A370%2C%22left%22%3A235%2C%22displayId%22%3A%22CY_AXIS_X_SIGN%22%7D%2C%22s24%22%3A%7B%22top%22%3A77%2C%22left%22%3A1683%2C%22displayId%22%3A%22CY_DIAMETER_BEFORE_DECIMAL%22%7D%2C%22s25%22%3A%7B%22top%22%3A183%2C%22left%22%3A1682%2C%22displayId%22%3A%22CY_DIAMETER_DECIMAL%22%7D%2C%22s26%22%3A%7B%22top%22%3A312%2C%22left%22%3A1680%2C%22displayId%22%3A%22CY_DIAMETER_AFTER_DECIMAL%22%7D%2C%22s37%22%3A%7B%22top%22%3A510%2C%22left%22%3A1474%2C%22displayId%22%3A%22CY_SPACE_3%22%7D%2C%22s34%22%3A%7B%22top%22%3A426%2C%22left%22%3A1205%2C%22displayId%22%3A%22CY_AXIS_Z_BEFORE_DECIMAL%22%7D%2C%22s35%22%3A%7B%22top%22%3A510%2C%22left%22%3A1202%2C%22displayId%22%3A%22CY_AXIS_Z_DECIMAL%22%7D%2C%22s36%22%3A%7B%22top%22%3A598%2C%22left%22%3A1205%2C%22displayId%22%3A%22CY_AXIS_Z_AFTER_DECIMAL%22%7D%2C%22s27%22%3A%7B%22top%22%3A515%2C%22left%22%3A231%2C%22displayId%22%3A%22CY_AXIS_X_DECIMAL%22%7D%2C%22s29%22%3A%7B%22top%22%3A515%2C%22left%22%3A506%2C%22displayId%22%3A%22CY_COMMA_3%22%7D%2C%22s28%22%3A%7B%22top%22%3A600%2C%22left%22%3A225%2C%22displayId%22%3A%22CY_AXIS_X_AFTER_DECIMAL%22%7D%2C%22s30%22%3A%7B%22top%22%3A419%2C%22left%22%3A723%2C%22displayId%22%3A%22CY_AXIS_Y_BEFORE_DECIMAL%22%7D%2C%22s39%22%3A%7B%22top%22%3A363%2C%22left%22%3A724%2C%22displayId%22%3A%22CY_AXIS_Y_SIGN%22%7D%2C%22s31%22%3A%7B%22top%22%3A509%2C%22left%22%3A724%2C%22displayId%22%3A%22CY_AXIS_Y_DECIMAL%22%7D%2C%22s33%22%3A%7B%22top%22%3A510%2C%22left%22%3A971%2C%22displayId%22%3A%22CY_COMMA_4%22%7D%2C%22s32%22%3A%7B%22top%22%3A603%2C%22left%22%3A723%2C%22displayId%22%3A%22CY_AXIS_Y_AFTER_DECIMAL%22%7D%2C%22s40%22%3A%7B%22top%22%3A369%2C%22left%22%3A1205%2C%22displayId%22%3A%22CY_AXIS_Z_SIGN%22%7D%2C%22s45%22%3A%7B%22top%22%3A503%2C%22left%22%3A1751%2C%22displayId%22%3A%22CY_HEIGHT_DECIMAL%22%7D%2C%22s47%22%3A%7B%22top%22%3A504%2C%22left%22%3A2015%2C%22displayId%22%3A%22CY_SPACE_5%22%7D%2C%22s46%22%3A%7B%22top%22%3A604%2C%22left%22%3A1745%2C%22displayId%22%3A%22CY_HEIGHT_AFTER_DECIMAL%22%7D%7D%2C%22transitions%22%3A%5B%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22start%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22c%22%2C%22stateB%22%3A%22s0%22%7D%2C%7B%22stateA%22%3A%22s0%22%2C%22label%22%3A%22y%22%2C%22stateB%22%3A%22s14%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%22-%22%2C%22stateB%22%3A%22s41%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s5%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s15%22%7D%2C%7B%22stateA%22%3A%22s5%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s8%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s8%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s15%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s44%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s9%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s10%22%7D%2C%7B%22stateA%22%3A%22s10%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s11%22%7D%2C%7B%22stateA%22%3A%22s11%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s13%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s12%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s13%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s12%22%7D%2C%7B%22stateA%22%3A%22s14%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22s15%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s16%22%7D%2C%7B%22stateA%22%3A%22s15%22%2C%22label%22%3A%22-%22%2C%22stateB%22%3A%22s42%22%7D%2C%7B%22stateA%22%3A%22s16%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s16%22%7D%2C%7B%22stateA%22%3A%22s16%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s17%22%7D%2C%7B%22stateA%22%3A%22s16%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s19%22%7D%2C%7B%22stateA%22%3A%22s17%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s18%22%7D%2C%7B%22stateA%22%3A%22s18%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s18%22%7D%2C%7B%22stateA%22%3A%22s18%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s19%22%7D%2C%7B%22stateA%22%3A%22s19%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s20%22%7D%2C%7B%22stateA%22%3A%22s19%22%2C%22label%22%3A%22-%22%2C%22stateB%22%3A%22s43%22%7D%2C%7B%22stateA%22%3A%22s20%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s20%22%7D%2C%7B%22stateA%22%3A%22s20%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s21%22%7D%2C%7B%22stateA%22%3A%22s20%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s23%22%7D%2C%7B%22stateA%22%3A%22s21%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s22%22%7D%2C%7B%22stateA%22%3A%22s22%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s22%22%7D%2C%7B%22stateA%22%3A%22s22%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s23%22%7D%2C%7B%22stateA%22%3A%22s23%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s23%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s23%22%7D%2C%7B%22stateA%22%3A%22s23%22%2C%22label%22%3A%22-%22%2C%22stateB%22%3A%22s38%22%7D%2C%7B%22stateA%22%3A%22s24%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s24%22%7D%2C%7B%22stateA%22%3A%22s24%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s25%22%7D%2C%7B%22stateA%22%3A%22s24%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s25%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s26%22%7D%2C%7B%22stateA%22%3A%22s26%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s26%22%7D%2C%7B%22stateA%22%3A%22s26%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s37%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s24%22%7D%2C%7B%22stateA%22%3A%22s37%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s37%22%7D%2C%7B%22stateA%22%3A%22s34%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s37%22%7D%2C%7B%22stateA%22%3A%22s34%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s35%22%7D%2C%7B%22stateA%22%3A%22s36%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s36%22%7D%2C%7B%22stateA%22%3A%22s36%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s37%22%7D%2C%7B%22stateA%22%3A%22s35%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s36%22%7D%2C%7B%22stateA%22%3A%22s38%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s2%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s27%22%7D%2C%7B%22stateA%22%3A%22s2%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s29%22%7D%2C%7B%22stateA%22%3A%22s27%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s28%22%7D%2C%7B%22stateA%22%3A%22s28%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s28%22%7D%2C%7B%22stateA%22%3A%22s28%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s29%22%7D%2C%7B%22stateA%22%3A%22s29%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s30%22%7D%2C%7B%22stateA%22%3A%22s29%22%2C%22label%22%3A%22-%22%2C%22stateB%22%3A%22s39%22%7D%2C%7B%22stateA%22%3A%22s39%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s30%22%7D%2C%7B%22stateA%22%3A%22s30%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s31%22%7D%2C%7B%22stateA%22%3A%22s30%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s33%22%7D%2C%7B%22stateA%22%3A%22s31%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s32%22%7D%2C%7B%22stateA%22%3A%22s32%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s32%22%7D%2C%7B%22stateA%22%3A%22s32%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s33%22%7D%2C%7B%22stateA%22%3A%22s33%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s34%22%7D%2C%7B%22stateA%22%3A%22s33%22%2C%22label%22%3A%22-%22%2C%22stateB%22%3A%22s40%22%7D%2C%7B%22stateA%22%3A%22s40%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s34%22%7D%2C%7B%22stateA%22%3A%22s41%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s42%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s16%22%7D%2C%7B%22stateA%22%3A%22s43%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s20%22%7D%2C%7B%22stateA%22%3A%22s44%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s44%22%7D%2C%7B%22stateA%22%3A%22s44%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s45%22%7D%2C%7B%22stateA%22%3A%22s44%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s47%22%7D%2C%7B%22stateA%22%3A%22s45%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s46%22%7D%2C%7B%22stateA%22%3A%22s46%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s46%22%7D%2C%7B%22stateA%22%3A%22s46%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s47%22%7D%2C%7B%22stateA%22%3A%22s47%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s9%22%7D%2C%7B%22stateA%22%3A%22s47%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s47%22%7D%5D%2C%22bulkTests%22%3A%7B%22accept%22%3A%22cy%5Cn50.0%2C0.0%2C20.6%5Cn0.0%2C0.0%2C1.0%2014.2%2021.42%5Cn10%2C0%2C255%22%2C%22reject%22%3A%22%22%7D%7D
*/

t_cy_state	cylinder_transition(t_cy_state state, char c)
{
	if (state == CY_START)
	{
		if (c == ' ')
			return (CY_START);
		if (c == 'c')
			return (CY_IDENTIFIER_1);
	}
	else if (state == CY_IDENTIFIER_1)
	{
		if (c == 'y')
			return (CY_IDENTIFIER_2);
	}
	else if (state == CY_IDENTIFIER_2)
	{
		if (c == ' ')
			return (CY_SPACE_1);
	}
	else if (state == CY_SPACE_1)
	{
		if (c == ' ')
			return (CY_SPACE_1);
		if (c == '-')
			return (CY_ORIG_X_SIGN);
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_1);
		if (c == '.')
			return (CY_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_1);
		if (ft_isdigit(c))
			return (CY_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_1)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-')
			return (CY_ORIG_Y_SIGN);
	}
	else if (state == CY_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_2);
		if (c == '.')
			return (CY_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_2);
		if (ft_isdigit(c))
			return (CY_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_2)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-')
			return (CY_ORIG_Z_SIGN);
	}
	else if (state == CY_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (c == '.')
			return (CY_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (ft_isdigit(c))
			return (CY_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_2)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (ft_isdigit(c))
			return (CY_AXIS_X_BEFORE_DECIMAL);
		if (c == ' ')
			return (CY_AXIS_X_SIGN);
	}
	else if (state == CY_AXIS_X_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_X_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_3);
		if (c == '.')
			return (CY_AXIS_X_DECIMAL);
	}
	else if (state == CY_AXIS_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_X_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_3);
		if (ft_isdigit(c))
			return (CY_AXIS_X_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_3)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_BEFORE_DECIMAL);
		if (c == '-')
			return (CY_AXIS_Y_SIGN);
	}
	else if (state == CY_AXIS_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_4);
		if (c == '.')
			return (CY_AXIS_Y_DECIMAL);
	}
	else if (state == CY_AXIS_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_4);
		if (ft_isdigit(c))
			return (CY_AXIS_Y_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_4)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_BEFORE_DECIMAL);
		if (c == '-')
			return (CY_AXIS_Z_SIGN);
	}
	else if (state == CY_AXIS_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (c == '.')
			return (CY_AXIS_Z_DECIMAL);
	}
	else if (state == CY_AXIS_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (ft_isdigit(c))
			return (CY_AXIS_Z_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_3)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (ft_isdigit(c))
			return (CY_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == CY_DIAMETER_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (c == '.')
			return (CY_DIAMETER_DECIMAL);
		if (ft_isdigit(c))
			return (CY_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == CY_DIAMETER_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == CY_DIAMETER_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (ft_isdigit(c))
			return (CY_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_4)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (ft_isdigit(c))
			return (CY_HEIGHT_BEFORE_DECIMAL);
	}
	else if (state == CY_HEIGHT_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (c == '.')
			return (CY_HEIGHT_DECIMAL);
		if (ft_isdigit(c))
			return (CY_HEIGHT_BEFORE_DECIMAL);
	}
	else if (state == CY_HEIGHT_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_HEIGHT_AFTER_DECIMAL);
	}
	else if (state == CY_HEIGHT_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (ft_isdigit(c))
			return (CY_HEIGHT_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_5)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (ft_isdigit(c))
			return (CY_RED);
	}
	else if (state == CY_RED)
	{
		if (c == ',')
			return (CY_COMMA_5);
		if (ft_isdigit(c))
			return (CY_RED);
	}
	else if (state == CY_COMMA_5)
	{
		if (ft_isdigit(c))
			return (CY_GREEN);
	}
	else if (state == CY_GREEN)
	{
		if (c == ',')
			return (CY_COMMA_6);
		if (ft_isdigit(c))
			return (CY_GREEN);
	}
	else if (state == CY_COMMA_6)
	{
		if (ft_isdigit(c))
			return (CY_BLUE);
	}
	else if (state == CY_BLUE)
	{
		if (ft_isdigit(c))
			return (CY_BLUE);
		if (c == '\n')
			return (CY_ACCEPT);
		if (c == ' ')
			return (CY_SPACE_6);
	}
	else if (state == CY_SPACE_6)
	{
		if (c == ' ')
			return (CY_SPACE_6);
		if (c == '\n')
			return (CY_ACCEPT);
	}
	else if (state == CY_ACCEPT)
		return (CY_ACCEPT);
	return (CY_REJECT);
}

int	is_valid_cylinder(char *line)
{
	t_cy_state	state;
	int			i;

	i = 0;
	state = CY_START;
	while (line[i])
	{
		state = cylinder_transition(state, line[i]);
		if (state == CY_REJECT)
			break ;
		i++;
	}
	if (state == CY_ACCEPT || state == CY_BLUE || state == CY_SPACE_6)
		return (1);
	ft_putstr_fd("Error\nCylinder could not be parsed\n", STDERR_FILENO);
	return (0);
}
