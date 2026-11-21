/* FATAL-ERROR.C -- c_fatal, reporting an error and ending the program.
 */

/* Report `what` through perror from text mode and exit with code 63h. */
INT c_fatal(rt_addr what)
{
    c_set_mode_keeping_errno(3);
    perror(what);
    exit(0x63);
}