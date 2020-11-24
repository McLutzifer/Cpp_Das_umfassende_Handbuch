double add(double a, double b) { return a + b; }
double add(int, int) = delete;   // add(3,4) verbieten

