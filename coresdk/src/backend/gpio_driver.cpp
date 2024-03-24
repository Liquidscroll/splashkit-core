// gpio_driver.cpp
// This file is part of the SplashKit Core Library.
// Copyright (©) 2024 Aditya Parmar. All Rights Reserved.

#include "gpio_driver.h"

#include <string>
#include <iostream>
#include <cstdlib> // Add this line to include the necessary header for the exit() function

#ifdef RASPBERRY_PI
#include "pigpiod_if2.h"


using namespace std;
// Use https://abyz.me.uk/rpi/pigpio/pdif2.html for reference
namespace splashkit_lib
{
        int pi = -1;

        // Check if pigpio_init() has been called before any other GPIO functions
        bool check_pi()
        {

                if (pi < 0)
                {
                        cout << "gpio_init() must be called before any other GPIO functions" << endl;
                        return false; 
                }
                else
                        return true;
        }

        // Initialize the GPIO library
        int sk_gpio_init()
        {

                pi = pigpio_start(0, 0);
                return pi;
        }

        // Read the value of a GPIO pin
        int sk_gpio_read(int pin)
        {

                if (check_pi())
                {
                        return gpio_read(pi, pin);
                }
		else
		{
			return -1;
		}
        }

        // Write a value to a GPIO pin
        void sk_gpio_write(int pin, int value)
        {

                if (check_pi())
                {
                	gpio_write(pi, pin, value);
		}
		else
		{
			return;
		}
        }

        // Set the mode of a GPIO pin
        void sk_gpio_set_mode(int pin, int mode)
        {

                if (check_pi())
                {
	                set_mode(pi, pin, mode);
		}
		else
		{
			return;
		}
        }

        int sk_gpio_get_mode(int pin)
        {

                if (check_pi())
                {
                	return get_mode(pi, pin);
		}
		else
		{
			return;
		}
        }
        void sk_gpio_set_pull_up_down(int pin, int pud)
        {

                if (check_pi())
                {
                	set_pull_up_down(pi, pin, pud);
		}
		else
		{
			return;
		}
        }
        void sk_set_pwm_range(int pin, int range)
        {

                if (check_pi())
                {
                	set_PWM_range(pi, pin, range);
		}
		else
		{
			return;
		}
        }
        void sk_set_pwm_frequency(int pin, int frequency)
        {

                if (check_pi())
                {
                	set_PWM_frequency(pi, pin, frequency);
		}
		else
		{
			return;
		}
        }
        void sk_set_pwm_dutycycle(int pin, int dutycycle)
        {

                if (check_pi())
                {
                	set_PWM_dutycycle(pi, pin, dutycycle);
		}
		else
		{
			return;
		}
        }

        // Cleanup the GPIO library
        void sk_gpio_cleanup()
        {

                if (check_pi())
                {
                	pigpio_stop(pi);
		}
		else
		{
			return;
		}
        }
}
#endif
