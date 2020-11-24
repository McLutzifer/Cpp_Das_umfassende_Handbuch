auto maxOf2(int a, int b) {
    return a<b ? b : a;   // ein return: der Compiler ermittelt int
}
auto minOf3(int a, int b, int c) {
     if(a<b) return a<c ? a : c;
     else return b<c ? b : c;
}
auto medianOf3(int a, int b, int c) {
     // komplexer, aber kein Problem für den Compiler
     return minOf3(maxOf2(a,b), maxOf2(b,c), maxOf2(a,c));
}

