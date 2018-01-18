




class PhysicTriangle
{
public:
    Vertex tri[3];
    FLOATING_VALUES_TYPE image[3][2];
    Vertex normal;
    FLOATING_VALUES_TYPE det;
    
    unsigned int texture;                    // jesli 0 to nie rysowaæ, przed podaniem do vektora trójk¹tów nale¿ odi¹æ jeden ( nie zmieniaj¹c wartoœci tej zmiennej )      
    
    
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
