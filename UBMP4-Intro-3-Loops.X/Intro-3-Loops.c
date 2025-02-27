/*==============================================================================
 Project: Intro-3-Loops
 Date:    May 16, 2021
 
 This example program demonstrates the use of while and for loop structures to
 change the brightness of LEDs using PWM (Pulse-Width Modulated) signals.
 
 Additional program analysis and programming activities expand the use of loops
 to create tones of different pitches and frequency sweeps.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.


#define A5
#ifdef originalCode
// Program variable definitions
unsigned char TonLED4 = 127;    // LED brightness PWM value
unsigned char PWMperiod;        // PWM period counter for PWM loops
unsigned int period = 460;      // Sound period value for later activities

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        // Decrease brightness
        if(SW2 == 0)
        {
            TonLED4 -= 1;
        }

        // Increase brightness
        if(SW3 == 0)
        {
            TonLED4 += 1;
        }
        
        // PWM LED4 brightness
        PWMperiod = 255;
        while(PWMperiod != 0)
        {
            if(TonLED4 == PWMperiod)
            {
                LED4 = 1;
            }
            PWMperiod --;
            __delay_us(20);
        }
        LED4 = 0;
        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
#endif
#ifdef programAnalysis
// Program variable definitions
unsigned char TonLED4 = 127;    // LED brightness PWM value
unsigned char PWMperiod;        // PWM period counter for PWM loops
unsigned int period = 460;      // Sound period value for later activities

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        // Decrease brightness
        if(SW2 == 0)
        {
            TonLED4 -= 1;
        }

        // Increase brightness
        if(SW3 == 0)
        {
            TonLED4 += 1;
        }

        // Question 5
        // PWM LED4 brightness
        for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
        {
            if(TonLED4 == PWMperiod)
            {
                LED4 = 1;
            }
            __delay_us(20);
        }
        LED4 = 0;

        // Question 6

        PWMperiod = 128;

        if(PWMperiod == 128)
        {
            LED5 = 1;
        }
        else
        {
            LED5 = 0;
        }

        // Question 7

        if(SW4 == 0)
        {
            period -= 1;
        }
        
        if(SW5 == 0)
        {
            period += 1;
        }
        
        // Make a tone
        for(unsigned char cycles = 50; cycles != 0; cycles--)
        {
            BEEPER = !BEEPER;
            for(unsigned int p = period; p != 0; p--);
        }
        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
#endif
#ifdef A1
// Program that increases and decreases brightness of a light
// but it stops the light from wrapping, as in the original code
// had a bug that if you held the button it would increase the 
// brightness to the max then reset to a brightness of 0.
// The problem was 255 + 1 = 0 because the char variable wraps
// Program variable definitions
unsigned char TonLED4 = 127;    // LED brightness PWM value
unsigned char PWMperiod;        // PWM period counter for PWM loops

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        // Decrease brightness
        if(SW2 == 0 && TonLED4 > 0)
        {
            TonLED4 -= 1;
        }

        // Increase brightness
        if(SW3 == 0 && TonLED4 < 255)
        {
            TonLED4 += 1;
        }

        // PWM LED4 brightness
        for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
        {
            if(TonLED4 == PWMperiod)
            {
                LED4 = 1;
            }
            __delay_us(20);
        }
        LED4 = 0;

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
#endif
#ifdef A2
// Same as the previous activity, but now you can control two lights.
// Program variable definitions
unsigned char TonLED4 = 127;    // LED brightness PWM value
unsigned char TonLED5 = 127;    // LED brightness PWM value

unsigned char PWMperiod;        // PWM period counter for PWM loops

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        // Decrease brightness of LED D4
        if(SW2 == 0 && TonLED4 > 0)
        {
            TonLED4 -= 1;
        }

        // Increase brightness of LED D4
        if(SW3 == 0 && TonLED4 < 255)
        {
            TonLED4 += 1;
        }

        // Decrease brightness of LED D5
        if(SW5 == 0 && TonLED5 > 0)
        {
            TonLED5 -= 1;
        }

        // Increase brightness of LED D5
        if(SW4 == 0 && TonLED5 < 255)
        {
            TonLED5 += 1;
        }

        // PWM LED4 brightness
        for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
        {
            if(TonLED4 == PWMperiod)
            {
                LED4 = 1;
            }

            if(TonLED5 == PWMperiod)
            {
                LED5 = 1;
            }
            __delay_us(20);
        }
        LED4 = 0;
        LED5 = 0;

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
#endif
#ifdef A3
// A program where when you press the on button the light slowly increases brightness to turn on.
// When you press the off button the light slowly decreases brightness to turn off. 

unsigned char TonLED4 = 0;      // LED brightness PWM value
unsigned char PWMperiod;        // PWM period counter for PWM loops

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        // Turn light off slowly
        if(SW2 == 0 && LED4 == 1)
        {
            for(unsigned char i = 0; i < 255; i ++)
                {
                TonLED4 --;
                    for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
                    {
                        if(TonLED4 == PWMperiod)
                        {
                            LED4 = 1;
                        }
                        __delay_us(20);
                    }
                LED4 = 0;
                }
        }

        // Turn light on slowly
        if(SW3 == 0 && LED4 == 0)
        {
            for(unsigned char i = 0; i < 255; i ++)
            {
                TonLED4 ++;
                for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
                {
                    if(TonLED4 == PWMperiod)
                    {
                        LED4 = 1;
                    }
                    __delay_us(20);
                    }
                    if(TonLED4 == 255)
                    {
                        LED4 = 1;
                    }
                    else
                    {
                        LED4 = 0;
                    }
                }
            }

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
#endif
#ifdef A4
// Program variable definitions
// This program makes a light pulse. Its slightly broken
// because to reset the code you need to unplug the UBMP4
// then hold the SW1, then plug it in, then let go. It should reset.
// Regardless of the bug it works and I just took the code from the 
// last activity.
unsigned char TonLED4 = 255;      // LED brightness PWM value
unsigned char PWMperiod;        // PWM period counter for PWM loops


int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
            for(unsigned char i = 0; i < 255; i ++)
                {
                TonLED4 --;
                    for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
                    {
                        if(TonLED4 == PWMperiod)
                        {
                            LED4 = 1;
                        }
                        __delay_us(20);
                    }
                LED4 = 0;
                }
            for(unsigned char i = 0; i < 255; i ++)
            {
                TonLED4 ++;
                for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
                {
                    if(TonLED4 == PWMperiod)
                    {
                        LED4 = 1;
                    }
                    __delay_us(20);
                    }
                    if(TonLED4 == 255)
                    {
                        LED4 = 1;
                    }
                    else
                    {
                        LED4 = 0;
                    }
                }
            }

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }

#endif
#ifdef A5
// Program variable definitions
// Makes a chirping or "pew pew" noise by sweeping through a range of frequencies.
unsigned int period = 120;

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        if(SW2 == 0)
        {
        period = 120;
        for(unsigned char i = 0; i < 25; i++)
        {
            period ++;
            for(unsigned char cycles = 50; cycles != 0; cycles--)
            {
                BEEPER = !BEEPER;
                for(unsigned int p = period; p != 0; p--);
            }
        }
        period = 120;
        for(unsigned char i = 0; i < 25; i++)
        {
            period ++;
            for(unsigned char cycles = 50; cycles != 0; cycles--)
            {
                BEEPER = !BEEPER;
                for(unsigned int p = period; p != 0; p--);
            }
        }

        }
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}
#endif

/* Program Analysis
 * 
 * 1. The main part of the program contains the 'while(1)' loop. What condition
 *    is being evaluated within its brackets? (Hint: Think about the Boolean
 *    variables from Activity 2-Variables.) How many times will this loop run?

 The "1" in the while(1) is saying the condition is always true, or in other words the loop is on.
 If the statement was while(0) the loop wouldn't run because the conditon is always false. 1 is true
 and 0 is false. The loop while(1) will run indefinitely because the loop checks if 1 == true.
 * 
 * 2. There is a second 'while(PWMperiod != 0)' loop inside the first while
 *    loop. What condition is being evaluated inside this while statement's
 *    brackets? How many times will the contents of this inner loop run?

 The condition that is being evaluated inside the while statement is if the char variable PWMperiod is
 not equal to 0. The while loop will run whenever the variable PWM is not equal to 0. In short it checks
 if if the variable is equal to 0, if not then it runs the code. The contents of the loop will loop 255 times 
 because the contents of the while loop says to subtract one from PWMperiod each loop. When it reaches 0 it 
 will resume the while(1) loop, but then the variable will be set to 255 in the while(1) loop, and the
 while(PWMperiod != 0) will begin again, in essesence it is indefinite.
 * 
 * 3. What condition is being evaluated by the if statement inside the loop?
 *    What happens when the if condition is true?

The condition being evaluated in the if statement inside the while(PWMperiod != 0) loop is if (TonLED4 == PWMperiod).
The if statement checks too see if the variable TonLED4's value is equal to the value of variable PWMperiod. If this 
statement is true then code is run that makes LED4 turn on.

 * 
 * 4. Pressing the up or down buttons (SW3 and SW2) will increase or decrease
 *    the brightness of LED D4 using PWM (Pulse-Width Modulation). How many 
 *    different brightnesses can the LED have? What would the step size of one
 *    brightness level change be if it was expressed as a percentage?

 // The LED could have 256 (0-255) different brightnesses as the TonLED4 variable, which controls the brightness, is an 8-bit variable.
 The change in brightness level expressed as a percentage would be aproximately 0.3%.
 * 
 * 5. The while loop needs three statements to perform its function. First, the
 *    assignment statement 'PWMperiod = 255;' sets the PWMperiod variable. Next,
 *    the condition 'while(PWMperiod != 0)' runs the contents of the loop code
 *    while the condition is true. Unlike if statements, in which program flow
 *    continues below the contents of the if structure, the while loop causes
 *    the condition to be re-evaluated after executing the contents of its code.
 *    To ensure that the while loop does end at some point, the assignment
 *    statement 'PWMperiod --;' modifies the variable from within the loop.
 *    When the condition is false, the loop terminates and the program continues
 *    running the code below the loop structure.
 * 
 *    A 'for' loop is an alternative to a while loop, and incorporates the
 *    assignment of the loop variable, the loop conditional check, and variable
 *    modification into a single statement as shown in the example code. Replace
 *    the entire while structure in the code with the following for structure:
        
        // PWM LED4 brightness
        for(unsigned char PWMperiod = 255; PWMperiod != 0; PWMperiod --)
        {
            if(TonLED4 == PWMperiod)
            {
                LED4 = 1;
            }
            __delay_us(20);
        }
        LED4 = 0;
        
 *    What is an advantage of using a for loop instead of a while loop?

 An advantage of using a for loop instead of a while loop is that with a for loop it is easier to understand 
 and read. All three conditions are in the for loops first statement, so you cann easily change the code from their.
 With a while loop the conditions were inside of the while loop, so it was a little bit complicated. With for loop
 it might be easier to nest for loops inside for loops. A while loop is for when you want code to run when ever the 
 statement is true. A for loop is useful when you want code to run a certain number of times.
 * 
 * 6. The 'for' loop, above, redefines the PWMperiod variable in the 
 *    initialization statement: 'for(unsigned char PWMperiod = 255; ...'
 * 
 *    This instance of the PWMperiod variable will be local to the for loop,
 *    and won't maintain its value outside of the loop, or alter the value of
 *    the existing PWMperiod variable. It's a bad idea to re-use variable names
 *    inside loops since having two different versions of the same variable
 *    creates confusion. Is this really the case? Let's prove that the global
 *    PWMperiod variable is not affected by the local PWMperiod variable
 *    inside the for loop. Add this line above the for loop:
 
        PWMperiod = 128;

 *    Next, add the following lines after the for loop:
        
        if(PWMperiod == 128)
        {
            LED5 = 1;
        }
        else
        {
            LED5 = 0;
        }
        
 *    Compile and run the code. When the program runs, the PWMperiod variable
 *    inside the for loop will count down from 255 to 0, and should be 0 when
 *    the loop finishes. Is LED D5 lit? What must the value of PWMperiod be?

 When the code is run LED D5 is lit. The value of the global variable PWMperiod is 128.
 The value of the local variable of PWMperiod in the for loop is different however.

 * 
 *    Can you remove the global PWMperiod variable definition from the top of 
 *    the program now that PWMperiod is being defined in the for loop?

 Yes, you can remove the definiton from the top because the variable is being defined in the for loop.
 * 
 * 7. Add this code below the PWM loop to generate a tone:
                
        // Change pitch
        if(SW4 == 0)
        {
            period -= 1;
        }
        
        if(SW5 == 0)
        {
            period += 1;
        }
        
        // Make a tone
        for(unsigned char cycles = 50; cycles != 0; cycles--)
        {
            BEEPER = !BEEPER;
            for(unsigned int p = period; p != 0; p--);
        }

 *    The section to make a tone contains nested for loops. The outer loop 
 *    repeatedly causes the BEEPER pin to toggle before the inner loop runs.
 *    The inner loop is an empty loop, shown by its trailing semicolon ';'. It
 *    contains no code, so nothing will be repeated, but exists only to add a
 *    time delay to our program. The higher the number of loops, the more
 *    instruction cycles it will take to decrement the loop counter variable
 *    to zero, increasing the time delay until the next cycle.
 * 
 *    What variable type is period? How large a number can this variable hold?

 The variable period is an integer period type. The largest postitive integer for a 32-bit unsigned int variable
 is 2^32-1 (subtract one because of the 0). Therefore the highest number and unsigned int can hold is
 4,294,967,295.

 * 
 * 8. Why is period copied to the local variable p inside the inner for loop?
 *    What would happen if the actual period variable was decremented instead?

 The code is saying p in the for loop is equal to period the global variable. If period was used
 in the for loop the IDE would show an error because the period is not defined in the for loop.

 * 
 * Programming Activities
 * 
 * 1. Pressing and holding SW2 or SW3 causes the brightness of LED D4 to cycle
 *    through its entire brightness range. Modify the code so that pressing and
 *    holding SW2 will dim the LED until it is off and then keep if off, and
 *    pressing and holding SW3 will brighten the LED and keep it at maximum
 *    brightness.
 * 
 * 2. Modify your program to control the brightness of LED D5 using SW4 and SW5
 *    while using SW3 and SW2 to control LED D4. Hint: To ensure each LED can
 *    reach maximum brightness (100% PWM on-time), you'll have to perform both
 *    PWM functions in the same loop. You can see the resulting PWM wave if you
 *    have access to an oscilloscope. If not, just light the other two LEDs and 
 *    compare the brightness of LEDs D4 and D5 to them.
 * 
 * 3. Rather than having lights suddenly turn on at full brightness, or motors
 *    turn on at full power, create a program that uses a for loop and your PWM
 *    code to make a 'soft-start' program that slowly increases the PWM on-time
 *    when you press a button. Can you make it turn off in a similar way?
 * 
 * 4. Make a program that creates an automated, electronic 'pulse', repeatedly
 *    brightening and dimming one or more LEDs.
 * 
 * 5. Make a 'chirp' or 'pew-pew' sound effect by sweeping through a range of
 *    frequencies when a button is pressed.
 */
