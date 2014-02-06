int l_enc_counts = 0;
int r_enc_counts = 0;
int enc_proc_handle = 0;

void encoder_aux()  /* Local click counter */
{
    int l_old, r_old, l_new, r_new; /* Trigger on Hi -> Low transition */

    while(1)
    {
        l_new = left_shaft();
        r_new = right_shaft();

        /* (old and not new) => 1 -> 0 transition */
        if(l_old & ~l_new)
            l_enc_counts++;

        if(r_old & ~r_new)
            r_enc_counts++;

        /* Update transition detector */
        l_old = l_new;
        r_old = r_new;
    }
}

void main()
{
    if(enc_proc_handle /= 0)
        kill_process(enc_proc_handle);  /* Don't start the process twice */

    enc_proc_handle = start_process(encoder_aux()); /* Show SE state on LEDs */

    while(1)
    {
        printf("Encoders Test   ");
        printf("L");

        if(left_shaft())
            printf("*");        /* Left SE is ON */
        else
            printf("%c",0xA5);  /* Left SE is OFF */

        printn(l_enc_counts,5); /* Report Left clicks */
        printf(" R");

        if(right_shaft())
            printf("*");        /* Right SE is ON */
        else
            printf("%c",0xA5);  /* Right SE is OFF */

        printn(r_enc_counts,5); /* Report Right clicks */
        printf("\n");
        sleep(0.3);
    }
}
