




class PhysicTriangle
{
public:
    Vertex tri[3];
    FLOATING_VALUES_TYPE image[3][2];
    Vertex normal;
    FLOATING_VALUES_TYPE det;
    
    unsigned int texture;                    // jesli 0 to nie rysowa�, przed podaniem do vektora tr�jk�t�w nale� odi�� jeden ( nie zmieniaj�c warto�ci tej zmiennej )      
    
    
    FLOATING_VALUES_TYPE GetMaxX(); // +
    FLOATING_VALUES_TYPE GetMaxY(); // +
    FLOATING_VALUES_TYPE GetMaxZ(); // +
    FLOATING_VALUES_TYPE GetMinX(); // +
    FLOATING_VALUES_TYPE GetMinY(); // +
    FLOATING_VALUES_TYPE GetMinZ(); // +
    
    void CalculateNormal();         // +
    void CalculateDet();            // +
    
    PhysicTriangle();               // +
};
