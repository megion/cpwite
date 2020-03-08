
#ifndef SRC_UTILS_CONSOLE_COLORS_H
#define SRC_UTILS_CONSOLE_COLORS_H

#include <stdio.h>

#define RESET_COLOR "\033[0m"
#define BLACK_COLOR "\033[30m"   /* Black */
#define RED_COLOR "\033[31m"     /* Red */
#define GREEN_COLOR "\033[32m"   /* Green */
#define YELLOW_COLOR "\033[33m"  /* Yellow */
#define BLUE_COLOR "\033[34m"    /* Blue */
#define MAGENTA_COLOR "\033[35m" /* Magenta */
#define CYAN_COLOR "\033[36m"    /* Cyan */
#define WHITE_COLOR "\033[37m"   /* White */

#define BOLDBLACK_COLOR "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED_COLOR "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN_COLOR "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW_COLOR "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE_COLOR "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA_COLOR "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN_COLOR "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE_COLOR "\033[1m\033[37m"   /* Bold White */

#define none 0x00
#define dbg 0x1F
#define info 0x0F
#define warn 0x07
#define err 0x03
#define crit 0x01

/* current log level */
#define LOG_LEVEL dbg

#define WHERESTR "%s:%d: "
#define WHEREARG __FILE__, __LINE__
#define PRINT_DEBUG_STR(...) printf(__VA_ARGS__)
#define log(X, _fmt, ...)                                                      \
    if ((LOG_LEVEL & X) == X) {                                                \
        if ((X == warn)) {                                                     \
            PRINT_DEBUG_STR(WHERESTR YELLOW_COLOR                              \
                            " warining: " _fmt RESET_COLOR "\n",               \
                            WHEREARG, ##__VA_ARGS__);                          \
        }                                                                      \
        else if ((X == err) || (X == crit)) {                                  \
            PRINT_DEBUG_STR(WHERESTR RED_COLOR " error: " _fmt RESET_COLOR     \
                                               "\n",                           \
                            WHEREARG, ##__VA_ARGS__);                          \
        }                                                                      \
        else {                                                                 \
            PRINT_DEBUG_STR(WHERESTR _fmt "\n", WHEREARG, ##__VA_ARGS__);      \
        }                                                                      \
    }

#endif
