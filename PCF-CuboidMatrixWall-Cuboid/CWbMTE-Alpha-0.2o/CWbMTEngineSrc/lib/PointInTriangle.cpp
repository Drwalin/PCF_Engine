
// include "Matrix.cpp"



inline float TriArea2D(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return (x1-x2)*(y2-y3) - (x2-x3)*(y1-y2);
}


inline void Barycentric(Vector m, Vector a, Vector b, Vector c, Vector p, float &u, float &v, float &w)
{
    // m - normal
    // Nominators and one-over-denominator for u and v ratios
    float nu, nv, ood;
    // Absolute components for determining projection plane
    float x = abs(m[0]), y = abs(m[1]), z = abs(m[2]);
    // Compute areas in plane of largest projection
    if (x >= y && x >= z)
    {
        // x is largest, project to the yz plane
        nu = TriArea2D( p[1], p[2], b[1], b[2], c[1], c[2] ); // Area of PBC in yz plane
        nv = TriArea2D( p[1], p[2], c[1], c[2], a[1], a[2] ); // Area of PCA in yz plane
        ood = 1.0f / m[0]; // 1/(2*area of ABC in yz plane)
    }
    else if (y >= x && y >= z)
    {
        // y is largest, project to the xz plane
        nu = TriArea2D( p[0], p[2], b[0], b[2], c[0], c[2] );
        nv = TriArea2D( p[0], p[2], c[0], c[2], a[0], a[2] );
        ood = 1.0f / -m[1];
    }
    else
    {
        // z is largest, project to the xy plane
        nu = TriArea2D( p[0], p[1], b[0], b[1], c[0], c[1] );
        nv = TriArea2D( p[0], p[1], c[0], c[1], a[0], a[1] );
        ood = 1.0f / m[2];
    }
    u = nu * ood;
    v = nv * ood;
    w = 1.0f - u - v;
}



// Test if point p is contained in triangle (a, b, c)
inline int TestPointTriangle( Vector p, Vector a, Vector b, Vector c, Vector normal )
{
    float u, v, w;
    Barycentric( normal, a, b, c, p, u, v, w );
    return v >= 0.0f && w >= 0.0f && (v+w) <= 1.0f;
}






