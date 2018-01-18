


#define OBJNUM object[calculate]
#define OBJPHYSNUM objectphys[calculate]


void Map::UpdatePhysic( unsigned int frametime )
{
    unsigned int calculate = 0;
    unsigned int a,b,c;
    for( calculate = 0; calculate < object.size(); calculate++ )
    {
        OBJNUM.speed[0] += OBJNUM.force[0] * (float(frametime)/1000.0f) / OBJNUM.mass;
        OBJNUM.speed[1] += OBJNUM.force[1] * (float(frametime)/1000.0f) / OBJNUM.mass;
        OBJNUM.speed[2] += OBJNUM.force[2] * (float(frametime)/1000.0f) / OBJNUM.mass;
        OBJNUM.force[0] = 0.0f;
        OBJNUM.force[1] = 0.0f;
        OBJNUM.force[2] = 0.0f;
    }
    
    for( calculate = 0; calculate < objectphys.size(); calculate ++ )
    {
        for( a=0; a<2; a++){
        for( b=0; b<2; b++){
        for( c=0; c<2; c++){
            OBJPHYSNUM.speed[a][b][c].vector[0] += OBJPHYSNUM.force[a][b][c].vector[0] * (float(frametime)/1000.0f) / OBJPHYSNUM.GetVertexMass( OBJPHYSNUM.pos[a][b][c].vector[0], OBJPHYSNUM.pos[a][b][c].vector[1], OBJPHYSNUM.pos[a][b][c].vector[2] );
            OBJPHYSNUM.speed[a][b][c].vector[1] += OBJPHYSNUM.force[a][b][c].vector[1] * (float(frametime)/1000.0f) / OBJPHYSNUM.GetVertexMass( OBJPHYSNUM.pos[a][b][c].vector[0], OBJPHYSNUM.pos[a][b][c].vector[1], OBJPHYSNUM.pos[a][b][c].vector[2] );
            OBJPHYSNUM.speed[a][b][c].vector[2] += OBJPHYSNUM.force[a][b][c].vector[2] * (float(frametime)/1000.0f) / OBJPHYSNUM.GetVertexMass( OBJPHYSNUM.pos[a][b][c].vector[0], OBJPHYSNUM.pos[a][b][c].vector[1], OBJPHYSNUM.pos[a][b][c].vector[2] );
        
            OBJPHYSNUM.force[a][b][c].vector[0] = 0.0f;
            OBJPHYSNUM.force[a][b][c].vector[1] = 0.0f;
            OBJPHYSNUM.force[a][b][c].vector[2] = 0.0f;
        }}}
    }
    
    ChangeForcesFunction( frametime );
    
    for( calculate = 0; calculate < object.size(); calculate ++ )
    {
        // grawitacja:
        OBJNUM.force.vertex[1] += gravitation * OBJNUM.mass;
        
        // opór powietrza:
               if( OBJNUM.speed[0] != 0.0f )     
                    OBJNUM.force[0] -= 1.3f * abs(OBJNUM.speed[0]) * OBJNUM.speed[0] * OBJNUM.width * (OBJNUM.heightlegs+OBJNUM.heightchest+OBJNUM.heighthead) * ( 0.3f );
               if( OBJNUM.speed[1] != 0.0f )
                    OBJNUM.force[1] -= 1.3f * abs(OBJNUM.speed[1]) * OBJNUM.speed[1] * OBJNUM.width * OBJNUM.width * ( 0.3f );
               if( OBJNUM.speed[2] != 0.0f )     
                    OBJNUM.force[2] -= 1.3f * abs(OBJNUM.speed[2]) * OBJNUM.speed[2] * OBJNUM.width * (OBJNUM.heightlegs+OBJNUM.heightchest+OBJNUM.heighthead) * ( 0.3f );
    }
    
    for( calculate = 0; calculate < objectphys.size(); calculate ++ )
    {
        // grawitacja:
        Vertex fastforce;
        fastforce[0] = 0.0f;
        fastforce[1] = gravitation * OBJPHYSNUM.mass;
        fastforce[2] = 0.0f;
        OBJPHYSNUM.AddForceVectorInPoint( OBJPHYSNUM.barycenter, fastforce );
        
        // opór powietrza:
        
        //fastforce[0] = -( 1.3f * abs(OBJPHYSNUM.speed.vector[1]) * OBJPHYSNUM.speed.vector[1] * OBJPHYSNUM.width * OBJPHYSNUM.width * ( 0.05f ) );
        //fastforce[1] = -( 1.3f * abs(OBJPHYSNUM.speed.vector[1]) * OBJPHYSNUM.speed.vector[1] * OBJPHYSNUM.width * OBJPHYSNUM.width * ( 0.05f ) );
        //fastforce[2] = -( 1.3f * abs(OBJPHYSNUM.speed.vector[1]) * OBJPHYSNUM.speed.vector[1] * OBJPHYSNUM.width * OBJPHYSNUM.width * ( 0.05f ) );
        
        fastforce[0] = 0.0f;
        fastforce[1] = 0.0f;
        fastforce[2] = 0.0f;
        
        for( a=0; a<2; a++){
        for( b=0; b<2; b++){
        for( c=0; c<2; c++){
            //OBJPHYSNUM.force[a][b][c].vertex[1] += gravitation * OBJPHYSNUM.GetVertexMass( OBJPHYSNUM.pos[a][b][c].vertex[0], OBJPHYSNUM.pos[a][b][c].vertex[1], OBJPHYSNUM.pos[a][b][c].vertex[2] );
            
            /*
            dodaje prêdkoœci z ka¿dego wierzcho³ka, po zakoñczeniu dodawania prêdkoœci nale¿y 'fastforce' podzieliæ przez 8, czyli iloœæ wierzcho³ków prostopad³oœcianu (obiektu fizycznego) 
          
            fastforce[0] += -( 1.3f * abs(OBJPHYSNUM.speed[a][b][c].vector[1]) * OBJPHYSNUM.speed[a][b][c].vector[1] * OBJPHYSNUM.width * OBJPHYSNUM.width * ( 0.05f ) );
            fastforce[1] += -( 1.3f * abs(OBJPHYSNUM.speed[a][b][c].vector[1]) * OBJPHYSNUM.speed[a][b][c].vector[1] * OBJPHYSNUM.width * OBJPHYSNUM.width * ( 0.05f ) );
            fastforce[2] += -( 1.3f * abs(OBJPHYSNUM.speed[a][b][c].vector[1]) * OBJPHYSNUM.speed[a][b][c].vector[1] * OBJPHYSNUM.width * OBJPHYSNUM.width * ( 0.05f ) );
            */
        }}}
    }
    
    
    for( calculate = 0; calculate < object.size(); calculate ++ )
    {
        OBJNUM.bpos = OBJNUM.pos;
        OBJNUM.pos += (Vector)( OBJNUM.speed * (float(frametime)/1000.0f) );
        
        CollisionAliveTriangle( calculate );
    }
    
    
    
    
    
    
}


#undef OBJNUM
#undef OBJPHYSNUM



