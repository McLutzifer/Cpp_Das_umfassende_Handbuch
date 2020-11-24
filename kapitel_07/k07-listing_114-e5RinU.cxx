class Widget : public Base {
    explicit Widget(int);     // keine automatische Konvertierung von int
    ~Widget();                // eine Funktion mit ~ vor dem Namen ist ein Destruktor
    virtual void update();    // vorangestelltes virtual
    void calc1() override;    // nachgestelltes override
    void calc2() final;       // nachgestelltes final
    void draw() const;        // nachgestelltes const
    virtual void paint() = 0; // abstrakte Methode
};

