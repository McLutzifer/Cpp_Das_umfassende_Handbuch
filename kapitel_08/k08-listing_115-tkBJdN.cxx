// #includes, prims, eingabeBis(), ausgabePrims() und main() wie zuvor 
std::vector<int> prims{2};
void berechnePrimsBis(int bis) {
    /* Prims-Berechnung */
    /* vector muss an dieser Stelle {2} enthalten */
    for(int n=3; n<bis; n=n+2) {
        for(int teil: prims) {
            if(teil*teil > n)
                goto prim;      // mit goto, weil ein break ...
            if(n%teil==0)
                goto nichtPrim; // ... über zwei Schleifen nicht geht.
        }
      prim: ;                   // Ziel des Sprungs vor push_back
        prims.push_back(n);     // n ist prim! Merken als Teiler und Ergebnis
      nichtPrim: ;              // Ziel des Sprungs hinter push_back
    }
}

