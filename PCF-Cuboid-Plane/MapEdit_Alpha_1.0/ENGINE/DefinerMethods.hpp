

void EnginePhisicModel::CalculateNormal()
{
	float Vector[2][3];
	Vector[0][0] = tri[0][0] - tri[1][0];
	Vector[0][1] = tri[0][1] - tri[1][1];
	Vector[0][2] = tri[0][2] - tri[1][2];
	Vector[1][0] = tri[1][0] - tri[2][0];
	Vector[1][1] = tri[1][1] - tri[2][1];
	Vector[1][2] = tri[1][2] - tri[2][2];

	normal[0] = Vector[0][1]*Vector[1][2] - Vector[0][2]*Vector[1][1];
	normal[1] = Vector[0][2]*Vector[1][0] - Vector[0][0]*Vector[1][2];
	normal[2] = Vector[0][0]*Vector[1][1] - Vector[0][1]*Vector[1][0];
}

void EnginePhisicModel::CalculateVectorMul( float * vector1, float * vector2, float * output )
{
	output[0] = vector1[1]*vector2[2] - vector1[2]*vector2[1];
	output[1] = vector1[2]*vector2[0] - vector1[0]*vector2[2];
	output[2] = vector1[0]*vector2[1] - vector1[1]*vector2[0];
}

void EnginePhisicModel::CalculateDet()
{
    det = - normal[0] * tri[0][0] - normal[1] * tri[0][1] - normal[2] * tri[0][2] ;
}

void EnginePhisicModel::CalculateRadian( unsigned int number )
{
    float cube[3][2];
    
    
    
	cube[0][0] = tri[0][0];
	if(tri[1][0] < cube[0][0])
	cube[0][0] = tri[1][0];
	if(tri[2][0] < cube[0][0])
	cube[0][0] = tri[2][0];

	cube[2][0] = tri[0][2];
	if(tri[1][2] < cube[2][0])
	cube[2][0] = tri[1][2];
	if(tri[2][2] < cube[2][0])
	cube[2][0] = tri[2][2];



	cube[0][1] = tri[0][0];
	if(tri[1][0] > cube[0][1])
	cube[0][1] = tri[1][0];
	if(tri[2][0] > cube[0][1])
	cube[0][1] = tri[2][0];

	cube[2][1] = tri[0][2];
	if(tri[1][2] > cube[2][1])
	cube[2][1] = tri[1][2];
	if(tri[2][2] > cube[2][1])
	cube[2][1] = tri[2][2];
    
    
    
    
    
    
    float pointpp[3];
    float vector1[3];
    float vector2[3];
    float vectorpp[3];
    
    
    
    
    
    for( unsigned int i = 0; i < 3; i++ )
    {
        pointpp[0] = ( tri[i][0] + tri[(i+1)%3][0] ) / 2.0f;
        pointpp[1] = ( tri[i][1] + tri[(i+1)%3][1] ) / 2.0f;
        pointpp[2] = ( tri[i][2] + tri[(i+1)%3][2] ) / 2.0f;
        
        vector1[0] = pointpp[0] - tri[i][0];
        vector1[1] = pointpp[1] - tri[i][1];
        vector1[2] = pointpp[2] - tri[i][2];
        
        vector2[0] = normal[0];
        vector2[1] = normal[1];
        vector2[2] = normal[2];
        
        CalculateVectorMul( vector1, vector2, vectorpp );
        
        
        if( sqrt(
                    pow( pointpp[0] + vectorpp[0] - tri[(i+2)%3][0], 2 ) +
                    pow( pointpp[1] + vectorpp[1] - tri[(i+2)%3][1], 2 ) +
                    pow( pointpp[2] + vectorpp[2] - tri[(i+2)%3][2], 2 )
                ) <
                sqrt(
                    pow( pointpp[0] - vectorpp[0] - tri[(i+2)%3][0], 2 ) +
                    pow( pointpp[1] - vectorpp[1] - tri[(i+2)%3][1], 2 ) +
                    pow( pointpp[2] - vectorpp[2] - tri[(i+2)%3][2], 2 )
                )
            )
        {
            sphere[i][0] = pointpp[0] + vectorpp[0]*1000.0f;
            sphere[i][1] = pointpp[1] + vectorpp[1]*1000.0f;
            sphere[i][2] = pointpp[2] + vectorpp[2]*1000.0f;
        }
        else
        {
            sphere[i][0] = pointpp[0] - vectorpp[0]*1000.0f;
            sphere[i][1] = pointpp[1] - vectorpp[1]*1000.0f;
            sphere[i][2] = pointpp[2] - vectorpp[2]*1000.0f;
        }
        
        
        /*
        sphere[i][0] /= 
                    sqrt(
                        pow( vectorpp[0], 2 ) +
                        pow( vectorpp[1], 2 ) +
                        pow( vectorpp[2], 2 )
                    );
        sphere[i][1] /= 
                    sqrt(
                        pow( vectorpp[0], 2 ) +
                        pow( vectorpp[1], 2 ) +
                        pow( vectorpp[2], 2 )
                    );
        sphere[i][2] /= 
                    sqrt(
                        pow( vectorpp[0], 2 ) +
                        pow( vectorpp[1], 2 ) +
                        pow( vectorpp[2], 2 )
                    );
        
        sphere[i][0] *= 10000.0f;
        sphere[i][1] *= 10000.0f;
        sphere[i][2] *= 10000.0f;
        
        
        radian[i] = 10000.0f; 
        
        */
                    /*
                    sqrt(
                        pow( pointpp[0] - vectorpp[0], 2 ) +
                        pow( pointpp[1] - vectorpp[1], 2 ) +
                        pow( pointpp[2] - vectorpp[2], 2 )
                    );
                    */
        radian[i] = 
                    sqrt(
                        pow( vectorpp[0]*1000.0f, 2 ) +
                        pow( vectorpp[1]*1000.0f, 2 ) +
                        pow( vectorpp[2]*1000.0f, 2 )
                    //    pow( tri[i][0]-sphere[i][0], 2 ) +
                    //    pow( tri[i][1]-sphere[i][1], 2 ) +
                    //    pow( tri[i][2]-sphere[i][2], 2 )
                    );
    }
    
    
    
    
    
    
    
    
    
    
        
    for( float x = cube[0][0] ; x <= cube[0][1]+XSIZETRIGGER ; x += XSIZETRIGGER )
    {
        for( float z = cube[2][0] ; z <= cube[2][1]+ZSIZETRIGGER ; z += ZSIZETRIGGER )
        {
            if( x < 0.0f || z < 0.0f || x > ( float(XTRIGGER) * XSIZETRIGGER ) || z > ( float(ZTRIGGER) * ZSIZETRIGGER ) ) 
            {
            }
            else if( x > 0.0f && z > 0.0f && x <= ( float(XTRIGGER) * XSIZETRIGGER ) && z <= ( float(ZTRIGGER) * ZSIZETRIGGER ) )
            {
                trigger[int(x/XSIZETRIGGER)][int(z/ZSIZETRIGGER)].tri.push_back( number );
            }
            else
            {
            }
        
        
        }
    }   
        
        
        
}



void EngineObject::SetObject( float * possition, float masa, float radius, unsigned int idmodel )
{
    pos[0] = possition[0];
    pos[1] = possition[1];
    pos[2] = possition[2];
    
    mass = masa;
    
    model = idmodel;
}

EngineObject::EngineObject()
{
    bpos[0] = 0.0f;
    bpos[1] = 0.0f;
    bpos[2] = 0.0f;
    
    pos[0] = 0.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    
    force[0] = 0.0f;
    force[1] = 0.0f;
    force[2] = 0.0f;
    
    speed[0] = 0.0f;
    speed[1] = 0.0f;
    speed[2] = 0.0f;
    
    radian = 0.85f;
        
    mass = 1.0f;
        
    lookxz = 0.0f;
    looky = 0.0f;
    
    density = 1000.0f;
    gravitation = -9.81f;
    
    elastic = 0.0625f;
    //elastic = 1.0f;
    
    model = 0;
        
    phisiccollision = true;
    phisicmove = true;
    phisicline = true;
    phisicsee = true;
}



float EngineObject::LookX()
{
    return sin( 90.0f - lookxz *const_PI/180) * 100.0f + pos[0];
}
float EngineObject::LookY()
{
    return tan( looky *const_PI/180) * 100.0f + pos[1];
}
float EngineObject::LookZ()
{
    return sin( lookxz *const_PI/180) * 100.0f + pos[2];
}

float EngineObject::LookXs()
{
    return sin( 90.0f - lookxz *const_PI/180);
}
float EngineObject::LookYs()
{
    return tan( looky *const_PI/180);
}
float EngineObject::LookZs()
{
    return sin( lookxz *const_PI/180);
}






void EngineMap::DrawMap()
{
    unsigned int numb = 0;
    for( numb = 0; numb < tri.size(); numb++ )
    {
    	glBindTexture( GL_TEXTURE_2D, texture[tri[numb].texture] );
    	
    	glColor3f( 1.0f, 1.0f, 1.0f );
    	
    	glBegin( GL_TRIANGLES );
    
//    	glColor3f( 1.0f, 0.0f, 0.0f );
        	glTexCoord2f( tri[numb].image[0][0], tri[numb].image[0][1] );
        		glVertex3f( tri[numb].tri[0][0], tri[numb].tri[0][1], tri[numb].tri[0][2] );
        
//    	glColor3f( 0.0f, 1.0f, 0.0f );
        	glTexCoord2f( tri[numb].image[1][0], tri[numb].image[1][1] );
        		glVertex3f( tri[numb].tri[1][0], tri[numb].tri[1][1], tri[numb].tri[1][2] );
        
//    	glColor3f( 0.0f, 0.0f, 1.0f );
        	glTexCoord2f( tri[numb].image[2][0], tri[numb].image[2][1] );
        		glVertex3f( tri[numb].tri[2][0], tri[numb].tri[2][1], tri[numb].tri[2][2] );
    
    	glEnd();
    	
    	if( DRAWNORMAL )
    	{
        	glBegin( GL_LINES );
        	
        	glColor3f( 0.0f, 0.0f, 0.0f );
        	
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].tri[0][0], tri[numb].tri[0][1], tri[numb].tri[0][2] );
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].tri[0][0] + tri[numb].normal[0], tri[numb].tri[0][1] + tri[numb].normal[1], tri[numb].tri[0][2] + tri[numb].normal[2] );
        	   
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].tri[1][0], tri[numb].tri[1][1], tri[numb].tri[1][2] );
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].tri[1][0] + tri[numb].normal[0], tri[numb].tri[1][1] + tri[numb].normal[1], tri[numb].tri[1][2] + tri[numb].normal[2] );
        	   
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].tri[2][0], tri[numb].tri[2][1], tri[numb].tri[2][2] );
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].tri[2][0] + tri[numb].normal[0], tri[numb].tri[2][1] + tri[numb].normal[1], tri[numb].tri[2][2] + tri[numb].normal[2] );
        	   
        	   /*
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].sphere[0], tri[numb].sphere[1], tri[numb].sphere[2] );
//        	glColor3f( 1.0f, 0.0f, 0.0f );
        	   glVertex3f( tri[numb].sphere[0] + tri[numb].normal[0], tri[numb].sphere[1] + tri[numb].normal[1], tri[numb].sphere[2] + tri[numb].normal[2] );
        	   */
        	   
        	glEnd();
        }
    }
    for( numb = 0; numb < environment.size(); numb++ )
    {
        objectmodel[environment[numb].model].Draw( environment[numb].position );
    }
}








bool EngineMap::LoadMap(char *name)
{
    char namefile[64];
    unsigned char argument=0;
    unsigned int argumentint = 0;
    EnginePhisicModel triangles;
    EngineObject objects;
	ifstream mappoint;
	mappoint.open(name, ios::in);
	if(mappoint.good())
	{

		while(1)
		{
            argument = 0;
			mappoint>>argument;

			switch(argument)
			{
			case 'm':        //dane mapy
                mappoint >> map.mapsize[0];
                mappoint >> map.mapsize[1];
                mappoint >> map.mapsize[2];
                mappoint >> map.mapmove[0];
                mappoint >> map.mapmove[1];
                break;
                
                

			case 'c':        //czyszczenie kontenera obiektow
				object.clear();
				object.resize(1);
				break;
				
			case 'd':        //gestosc otoczenia dla obiektu
                mappoint >> objects.density;
                break;

			case 'g':        //grawitacja dla obiektu
				mappoint >> objects.gravitation;
				break;

			case 'o':        //nowy obiekt
                mappoint >> objects.pos[0];
                mappoint >> objects.pos[1];
                mappoint >> objects.pos[2];
                mappoint >> objects.mass;
                mappoint >> objects.radian;
                mappoint >> objects.modeltype;
                mappoint >> objects.model;
                
                mappoint >> objects.phisiccollision;       //obliczac czy kolizja z nim wyst¹pi³a?
                mappoint >> objects.phisicmove;            //obliczac fizyke poruszania dla tego obiektu?
                mappoint >> objects.phisicline;            //obliczac kolizje tego obiektu z linia?
                mappoint >> objects.phisicsee;             //obliczac dla niego widzenie go?
                
                object.resize( object.size()+1 );
                object[object.size()-1] = objects;
				break;
				
				
        bool phisiccollision;       //obliczac czy kolizja z nim wyst¹pi³a?
        bool phisicmove;            //obliczac fizyke poruszania dla tego obiektu?
        bool phisicline;            //obliczac kolizje tego obiektu z linia?
        bool phisicsee;             //obliczac dla niego widzenie go?
				

			case 'r':        //opor terenu
				mappoint >> triangles.terrainresistance;
				break;

			case '3':        //trojkat
				mappoint >> triangles.tri[0][0];
				mappoint >> triangles.tri[0][1];
				mappoint >> triangles.tri[0][2];
				mappoint >> triangles.tri[1][0];
				mappoint >> triangles.tri[1][1];
				mappoint >> triangles.tri[1][2];
				mappoint >> triangles.tri[2][0];
				mappoint >> triangles.tri[2][1];
				mappoint >> triangles.tri[2][2];
				
				mappoint >> triangles.image[0][0];
				mappoint >> triangles.image[0][1];
				mappoint >> triangles.image[1][0];
				mappoint >> triangles.image[1][1];
				mappoint >> triangles.image[2][0];
				mappoint >> triangles.image[2][1];
				
				mappoint >> triangles.texture;
				
                triangles.CalculateNormal();
                triangles.CalculateRadian( tri.size() );
                triangles.CalculateDet();
                
				tri.push_back( triangles );
				break;
				
		    case 'T':        //nazwa tekstury
		        texturefiles.resize(map.texturefiles.size()+1);
                mappoint.getline( texturefiles[map.texturefiles.size()-1].name, 64 );
                
                bitmapInfoHeader.resize(map.texturefiles.size()+1);
                bitmapData.resize(map.texturefiles.size()+1);
                texture.resize(map.texturefiles.size()+1);
                break;
                
            case 'M':       //nazwa modelu
                mappoint >> argumentint;
                mappoint.getline( namefile, 64 );
                
                if( argumentint == HUMANMODEL )
                {
                        humanoid.resize( humanoid.size() + 1 );
                        humanoid[ humanoid.size() - 1 ].Load( namefile );
                }
                else if( argumentint == CUBEMODEL )
                {
                        cubes.resize( cubes.size() + 1 );
                        cubes[ cubes.size() - 1 ].Load( namefile );
                }
                
                /*
                switch(argument)
                {
                    case HUMANMODEL:
                        humanoid.resize( humanoid.size() + 1 );
                        humanoid[ humanoid.size() - 1 ].Load( namefile );
                        break;
                    case CUBEMODEL:
                        cubes.resize( cubes.size() + 1 );
                        cubes[ cubes.size() - 1 ].Load( namefile );
                        break;
                    case SPHEREMODEL:
                        break;
                    case BARRELHIGHMODEL:
                        break;
                    case BARRELWEIDMODEL:
                        break;
                    case DOORMODEL:
                        break;
                    default:
                        humanoid.resize( humanoid.size() + 1 );
                        humanoid[ humanoid.size() - 1 ].Load( namefile );
                }
                */
                break;

			case 's':        //koniec
			default:
				mappoint.close();
				return 1;
			}
		}

	}
	else{
		return 0;
	}
	mappoint.close();
	return 1;
    
    
}












void EngineMap::SaveMap(char *name)
{
    char namefile[64];
    unsigned char argument=0;
    unsigned int argumentint = 0;
    EnginePhisicModel triangles;
    EngineObject objects;
	ofstream mappoint;
	mappoint.open(name, ios::out);
	if(mappoint.good())
	{




	for( unsigned int k = 1; k < object.size(); k++ )
	{
		mappoint << "\no a " ;
		mappoint << object[k].pos[0];
		mappoint << " ";
		mappoint << object[k].pos[1];
		mappoint << " ";
		mappoint << object[k].pos[2];
		mappoint << "aa 0.6 aa 0.8 aa 0.52 aa 0.33 aa 75.0 aa 0 aa 0 aa 0 aa Dupa" ;
	}




	mappoint << "\n\n\n";
        
        for( unsigned int i = 0; i < tri.size(); i++ )
        {
            mappoint << "\nT v ";
            mappoint << tri[i].tri[0][0];
            mappoint << " ";
            mappoint << tri[i].tri[0][1];
            mappoint << " ";
            mappoint << tri[i].tri[0][2];
            mappoint << "  v  ";
            mappoint << tri[i].tri[1][0];
            mappoint << " ";
            mappoint << tri[i].tri[1][1];
            mappoint << " ";
            mappoint << tri[i].tri[1][2];
            mappoint << "  v  ";
            mappoint << tri[i].tri[2][0];
            mappoint << " ";
            mappoint << tri[i].tri[2][1];
            mappoint << " ";
            mappoint << tri[i].tri[2][2];
            mappoint << "  v  ";
            
			mappoint << tri[i].image[0][0];
            mappoint << " ";
			mappoint << tri[i].image[0][1];
            mappoint << "  v  ";
			mappoint << tri[i].image[1][0];
            mappoint << " ";
			mappoint << tri[i].image[1][1];
            mappoint << "  v  ";
			mappoint << tri[i].image[2][0];
            mappoint << " ";
			mappoint << tri[i].image[2][1];
            mappoint << "  aa 1";
            
            //mappoint << tri[i].texture;
        }
        
        mappoint <<"\ns";

	}
	else{
		return;
	}
	mappoint.close();
	return;
    
    
}











