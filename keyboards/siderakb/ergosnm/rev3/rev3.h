#pragma once

// clang-format off
#define LAYOUT( \
    LA0, LA1, LA2, LA3, LA4, LA5,                RA5, RA4, RA3, RA2, RA1, RA0, \
    LB0, LB1, LB2, LB3, LB4, LB5,                RB5, RB4, RB3, RB2, RB1, RB0, \
    LC0, LC1, LC2, LC3, LC4, LC5,                RC5, RC4, RC3, RC2, RC1, RC0, \
    LD0, LD1, LD2, LD3, LD4, LD5,                RD5, RD4, RD3, RD2, RD1, RD0, \
    LE0, LE1, LE2, LE3, LE4,                          RE4, RE3, RE2, RE1, RE0, \
                             LE5, LE6, LE7,      RE5,                          \
                             LF5, LF6, LF7                                     \
    ) \
    { \
        { XXX, LA0, LA1, LA2, LA3, LA4, LA5, LE6 }, /* Row 0  */ \
        { XXX, LB0, LB1, LB2, LB3, LB4, LB5, LE7 }, /* Row 1  */ \
        { XXX, LC0, LC1, LC2, LC3, LC4, LC5, LF5 }, /* Row 2  */ \
        { XXX, LD0, LD1, LD2, LD3, LD4, LD5, LF6 }, /* Row 3  */ \
        { XXX, LE0, LE1, LE2, LE3, LE4, LE5, LF7 }, /* Row 4  */ \
        { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, /* Row 5  */ \
                                                                 \
        { XXX, RA0, RA1, RA2, RA3, RA4, RA5, XXX }, /* Row 6  */ \
        { XXX, RB0, RB1, RB2, RB3, RB4, RB5, XXX }, /* Row 7  */ \
        { XXX, RC0, RC1, RC2, RC3, RC4, RC5, XXX }, /* Row 8  */ \
        { XXX, RD0, RD1, RD2, RD3, RD4, RD5, XXX }, /* Row 9  */ \
        { XXX, RE0, RE1, RE2, RE3, RE4, RE5, XXX }, /* Row 10 */ \
        { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }  /* Row 11 */ \
    }
// clang-format on
