class rinda{
private:
    int vertibas[5];
    int elementuSkaits;
    int rindasSakums;           // Izveidoju arī rindas sākuma un beigu mainīgos, kas satur šo elementu indeksus.
    int rindasBeigas;
public:
    rinda();
    ~rinda();
    void enqueue(int n);
    int dequeue();
    int Count();
    bool isEmpty();
};

