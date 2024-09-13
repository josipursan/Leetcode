#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1].
For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
========================

Remarks on the problem setup : 

    1.the default signature of the divide function set up by leetcode is : int divide(int dividend, int divisor){...}
        -given the problem description says we are dealing with an environment that can only store integers within the 32 bit signed integer range,
        function signature makes no sense (assuming that int32_t is [-2,147,483,648 to 2,147,483,647], and int is [−32767, +32767])
*/

int divide(int32_t dividend, int32_t divider)
{
    int32_t summation = 0;
    int32_t inc = 0;

    while(summation < ((dividend<0) ? dividend*(-1) : dividend))
    {
        if(summation > (INT32_MAX - ( (divider < 0) ? divider*(-1) : divider )))
        {
            if(dividend < 0 && divider < 0)
            {
                return INT32_MAX;
            }
            else if(dividend < 0 || divider < 0)
            {
                return INT32_MIN;
            }
        }

        if((summation += (divider < 0) ? divider*(-1) : divider) > ( (dividend < 0) ? dividend*(-1) : dividend))
        {
            break;
        }
        inc++;
    }
        
    if(divider > 0 && dividend > 0)
    {
        return inc;
    }

    if(divider < 0 && dividend < 0)
    {
        return inc;
    }
    else
    {
        return inc*(-1);
    }
}

int main()
{   
    int32_t a_dividend = 50;
    int32_t a_divider = 2;
    int32_t b_dividend = 50000;
    int32_t b_divider = 2234;
    int32_t c_dividend = 1105737;
    int32_t c_divider = 10005;

    int32_t d_dividend = 692842;
    int32_t d_divider = -2316;
    int32_t e_dividend = -3344886;
    int32_t e_divider = 9005;
    int32_t f_dividend = -3300694;
    int32_t f_divider = -3015;

    int32_t a = divide(a_dividend, a_divider);
    int32_t b = divide(b_dividend, b_divider);
    int32_t c = divide(c_dividend, c_divider);
    
    int32_t d = divide(d_dividend, d_divider);
    int32_t e = divide(e_dividend, e_divider);
    int32_t f = divide(f_dividend, f_divider);

    printf("a : %" PRId32 "\n", a);
    printf("b : %" PRId32 "\n", b);
    printf("c : %" PRId32 "\n", c);
    printf("d : %" PRId32 "\n", d);
    printf("e : %" PRId32 "\n", e);
    printf("f : %" PRId32 "\n", f);

    return 0;
}