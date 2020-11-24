if(int result;  (result = read(buffer, 100)) != 0) {
    std::cerr << "Es trat Fehler Nummer "<< result << " auf.\n";
}

