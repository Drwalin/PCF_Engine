




class PhysicTriangle
{
public:
    Vector tri[3];
    float image[3][2];
    Vector normal;
    float det;
    
    unsigned int texture;                    // jesli 0 to nie rysowa�, przed podaniem do vektora tr�jk�t�w nale� odi�� jeden ( nie zmieniaj�c warto�ci tej zmiennej )      
    
    
    float GetMaxX();            // +
    float GetMaxY();            // +
    float GetMaxZ();            // +
    float GetMinX();            // +
    float GetMinY();            // +
    float GetMinZ();            // +
    
    void CalculateNormal();     // +
    void CalculateDet();        // +
    
    PhysicTriangle();           // +
};
