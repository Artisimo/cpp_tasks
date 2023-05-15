int cipskaits(int sk){

    int cipSkaits = 0;
    do{
        sk = sk / 10;
        cipSkaits++;
    }while(sk >= 1);
    return cipSkaits;
}

