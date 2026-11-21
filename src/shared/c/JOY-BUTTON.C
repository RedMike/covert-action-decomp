/* JOY-BUTTON.C -- c_joystick_button, whether a joystick button is down.
 */

/* Answer whether joystick button `button` is down. The game port at 201h
 * carries the four buttons in its high nibble, active low.
 */
INT c_joystick_button(INT button)
{
    return ((INT) inp(0x201) >> (button + 4) & 1) == 0;
}