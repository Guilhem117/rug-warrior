void main()
{
    
    const float distance = 120; /* The distance in centimeter */
    
    printf("running for\n%.2d meter", distance);
    init_motors();
    drive(100,0);
    sleep(feetToMotor(feetToCm(distance), 100));
    stop();
}
