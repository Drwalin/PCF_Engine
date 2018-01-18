




class PhysicTriangle
{
public:
    Vector tri[3];
    float image[3][2];
    Vector normal;
    float det;
    
    unsigned int texture;                    // jesli 0 to nie rysowaæ, przed podaniem do vektora trójk¹tów nale¿ odi¹æ jeden ( nie zmieniaj¹c wartoœci tej zmiennej )      
    
    
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
