/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** cbuffer
*/

#ifndef SERRORH_H_
    #define SERRORH_H_
    #include <stddef.h>
    #include <stdarg.h>

    #ifndef ERRORHANDLING_H_
        #define ERROR 84
        #define SUCCESS 0
        #define UNUSED __attribute__((unused))
        #define DEPRECATED __attribute__((deprecated))
        #define LIKELY(x)       __builtin_expect((x),1)
        #define UNLIKELY(x)     __builtin_expect((x),0)
        #define WUR __attribute__((warn_unused_result))
        #define ASSERT_MALLOC(ptr, ret) if (UNLIKELY(ptr == NULL)) return ret;
        #define ASSERT_PTR(ptr, retrn) if (ptr == NULL) return retrn;
    #endif /* !ERRORHANDLING_H_ */

    #define IS_FLAG(c) (c == 'c' || c == 's' || c == 'd' \
|| c == 'u' || c == 'l')

    struct flag_s {
        char flag;
        void (*fptr)(va_list);
    };

    void err_printchar(va_list ap);
    void err_printstr(va_list ap);
    void err_printnbr(va_list ap);
    void err_printnbr_u(va_list ap);
    void err_printnbr_l(va_list ap);
    void err_put(const char *fmt);
    void err_print(const char *fmt, ...);
    void expr_assert(int expr, const char *fmt, ...);

    #ifdef DEBUG
        #include <stdio.h>
        #define DEBUGF(fmt, ...) err_print(fmt, __VA_ARGS__)
    #else
        #define DEBUGF(fmt, ...)
    #endif /* !DDEBUG */

#endif /* !SERRORH_H_ */
