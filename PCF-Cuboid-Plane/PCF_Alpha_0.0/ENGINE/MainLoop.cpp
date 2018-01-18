

#define objnum object[calculate]

#define trg trigger[int(x/XSIZETRIGGER)][int(z/ZSIZETRIGGER)].tri[a]
#define trgobj trigger[int(x/XSIZETRIGGEROBJ)][int(z/ZSIZETRIGGEROBJ)].obj


void EngineMainLoop()
{
    
    unsigned int calculate=0;
    unsigned int beginntime=0;
    unsigned int endtime=100;
    unsigned int frametime=10;
    bool collisionlinetriangles_objectsis = 0;
    float changeobjectspossition_triangles_lines[3];
    
    
    while( full_game_and_map_loaded_to_memory == 0 )
    {
        Sleep(10);
    }
    

    while(true)
    {
        frametime = endtime - beginntime;
        beginntime = clock();
        
        
        if( frametime < 2 ){
            frametime = 2;
        }else if( frametime > 50 ){
            timefps[2] = 1.0f/(float(frametime)/1000.0f);
            frametime = 50;
        }else{
            timefps[2] = 1.0f/(float(frametime)/1000.0f);
        }
        /*
        if( PHISICCALCULATE == true )
        {
                for( calculate = 1; calculate < object.size(); calculate++ )
                {
                if( objnum.phisicmove == true )
                {
                    //update speeds:
                    objnum.speed[0] += objnum.force[0] * float(frametime/1000.0f) / objnum.mass;
                    objnum.speed[1] += objnum.force[1] * float(frametime/1000.0f) / objnum.mass;
                    objnum.speed[2] += objnum.force[2] * float(frametime/1000.0f) / objnum.mass;
                    //reset forces:
                    objnum.force[0] = 0.0f;
                    objnum.force[1] = 0.0f;
                    objnum.force[2] = 0.0f;
                }
                }
        }
        */
        //your update forces/speeds/possitions:
        ChangeForcesFunction(frametime);
        
        /*
        if( PHISICCALCULATE == true )
        {
            //gravitation:
            for( calculate = 1; calculate < object.size(); calculate++ )
            {
            if( objnum.phisicmove == true )
            {
                objnum.force[1] += objnum.gravitation * objnum.mass;
            }
            }
            
            for( calculate = 1; calculate < object.size(); calculate++ )
            {
            if( objnum.phisicmove == true )
            {
                //opor powietrza :
               if( objnum.speed[0] != 0.0f )     
                    objnum.force[0] -= objnum.density * objnum.speed[0] * objnum.speed[0] * objnum.speed[0] * const_PI * objnum.radian * objnum.radian / ( abs(objnum.speed[0]) * 0.05f );
               if( objnum.speed[1] != 0.0f )
                    objnum.force[1] -= objnum.density * objnum.speed[1] * objnum.speed[1] * objnum.speed[1] * const_PI * objnum.radian * objnum.radian / ( abs(objnum.speed[1]) * 0.5f );
               if( objnum.speed[2] != 0.0f )     
                    objnum.force[2] -= objnum.density * objnum.speed[2] * objnum.speed[2] * objnum.speed[2] * const_PI * objnum.radian * objnum.radian / ( abs(objnum.speed[2]) * 0.05f );
                    
                    
                    
                    
                    
                //sila wyporu:
                
          //      objnum.force[1] += objnum.density * objnum.gravitation * pow( objnum.radian, 3 ) * const_PI *  4.0f / 3.0f;    
                    
                
            }
            }
            
            for( calculate = 1; calculate < object.size(); calculate++ )
            {
            if( objnum.phisicmove == true )
            {

                objnum.bpos[0] = objnum.pos[0];
                objnum.bpos[1] = objnum.pos[1];
                objnum.bpos[2] = objnum.pos[2];

                objnum.pos[0] += objnum.speed[0] * float(frametime/1000.0f);
                objnum.pos[1] += objnum.speed[1] * float(frametime/1000.0f);
                objnum.pos[2] += objnum.speed[2] * float(frametime/1000.0f);

                //kolizja:

                //if( objnum.pos[0] - objnum.radian < 0.0f || objnum.pos[2] - objnum.radian < 0.0f )
                //{
                //
                //}
                //else
                {
                    objnum.collision = false;
//////////////////////
                    collisionlinetriangles_objectsis = false;
                    collisionlinetriangles_objectsis = __CollisionLineTriangles( calculate, objnum.bpos, objnum.pos, changeobjectspossition_triangles_lines );

                    if( collisionlinetriangles_objectsis == true )
                    {
                        objnum.pos[0] = changeobjectspossition_triangles_lines[0];
                        objnum.pos[1] = changeobjectspossition_triangles_lines[1];
                        objnum.pos[2] = changeobjectspossition_triangles_lines[2];
                    }
///////////////////////////

                    for( float x = objnum.pos[0] - objnum.radian; x <= objnum.pos[0] + objnum.radian; x+=float(XSIZETRIGGER) )
                    {
                    for( float z = objnum.pos[2] - objnum.radian; z <= objnum.pos[2] + objnum.radian; z+=float(ZSIZETRIGGER) )
                    {
                        if( x < 0.0f || z < 0.0f || z > ( float(ZTRIGGER) * ZSIZETRIGGER ) || x > ( float(XTRIGGER) * XSIZETRIGGER ) )
                        {
                            
                        }
                        else
                        {
                            CollisionObjectTriangle( calculate, x, z, frametime );
                        }
                    }
                    }
                }
            }   
            }
            
            for( calculate = 1; calculate < object.size(); calculate++ )
            {
            if( objnum.phisicmove == true && objnum.phisiccollision == true  )
            {
                    for( float x = objnum.pos[0] - objnum.radian; x <= objnum.pos[0] + objnum.radian; x+=float(XSIZETRIGGEROBJ) )
                    {
                    for( float z = objnum.pos[2] - objnum.radian; z <= objnum.pos[2] + objnum.radian; z+=float(ZSIZETRIGGEROBJ) )
                    {
                        if( x < 0.0f || z < 0.0f || z > ( float(ZTRIGGEROBJ) * ZSIZETRIGGEROBJ ) || x > ( float(XTRIGGEROBJ) * XSIZETRIGGEROBJ ) )
                        {
                            continue;
                        }
                        else
                        {
                        //    CollisionObjectTriangle( calculate, x, z, frametime );
                            for( unsigned int number = 0; number < trgobj.size(); number++ )
                            {
                            if( object[trgobj[number]].phisicmove == true && object[trgobj[number]].phisiccollision == true && trgobj[number] != calculate)
                            {
                                if( abs(sqrt( pow(objnum.pos[0]-object[trgobj[number]].pos[0],2) + pow(objnum.pos[1]-object[trgobj[number]].pos[1],2) + pow(objnum.pos[2]-object[trgobj[number]].pos[2],2) )) <= abs( objnum.radian + object[trgobj[number]].radian ) )
                                {
                                    
                                    objnum.collision = true;
                                    
                                    
                                    
                                    
                                    float radianobjects = sqrt( pow(objnum.pos[0]-object[trgobj[number]].pos[0],2) + pow(objnum.pos[1]-object[trgobj[number]].pos[1],2) + pow(objnum.pos[2]-object[trgobj[number]].pos[2],2) );
                                    float point0[3] = { objnum.pos[0] + ( objnum.force[0] * objnum.mass * float(frametime*frametime)/1000.0f), objnum.pos[1] + ( objnum.force[1] * objnum.mass * float(frametime*frametime)/1000.0f), objnum.pos[2] + ( objnum.force[2] * objnum.mass * float(frametime*frametime)/1000.0f) };
                                    
                                    if( sqrt( pow(point0[0]-object[trgobj[number]].pos[0],2) + pow(point0[1]-object[trgobj[number]].pos[1],2) + pow(point0[2]-object[trgobj[number]].pos[2],2) ) < radianobjects )
                                    {
                                        objnum.force[0] = 0.0f;
                                        objnum.force[1] = 0.0f;
                                        objnum.force[2] = 0.0f;
                                    }
                                    
                                    
                                    float point1[3] = { objnum.pos[0] + ( objnum.speed[0] * float(frametime)/1000.0f), objnum.pos[1] + ( objnum.speed[1] * float(frametime)/1000.0f), objnum.pos[2] + ( objnum.speed[2] * float(frametime)/1000.0f) };
                                    
                                    if( sqrt( pow(point1[0]-object[trgobj[number]].pos[0],2) + pow(point1[1]-object[trgobj[number]].pos[1],2) + pow(point1[2]-object[trgobj[number]].pos[2],2) ) < radianobjects )
                                    {
                                        objnum.speed[0] = 0.0f;
                                        objnum.speed[1] = 0.0f;
                                        objnum.speed[2] = 0.0f;
                                    }
                                    
                                    
                                    float object1[3];
                                    float elastic = ( objnum.elastic + object[trgobj[number]].elastic ) / 2.0f;
                                    float versor1[3] = { object[trgobj[number]].pos[0]-objnum.pos[0], object[trgobj[number]].pos[1]-objnum.pos[1], object[trgobj[number]].pos[2]-objnum.pos[2] };
                                    float versor0[3] = { objnum.pos[0]-object[trgobj[number]].pos[0], objnum.pos[1]-object[trgobj[number]].pos[1], objnum.pos[2]-object[trgobj[number]].pos[2] };
                                    if( radianobjects == 0.0f )
                                        radianobjects = 1.0f;
                                    versor0[0] /= radianobjects;
                                    versor0[1] /= radianobjects;
                                    versor0[2] /= radianobjects;
                                    versor1[0] /= radianobjects;
                                    versor1[1] /= radianobjects;
                                    versor1[2] /= radianobjects;
                                    
                                    
                                    object1[0] = abs(objnum.speed[0] * objnum.mass);// * elastic;
                                    object1[1] = abs(objnum.speed[1] * objnum.mass);// * elastic;
                                    object1[2] = abs(objnum.speed[2] * objnum.mass);// * elastic;
                                    
                                    object1[0] += abs(object[trgobj[number]].speed[0] * object[trgobj[number]].mass);// * elastic;
                                    object1[1] += abs(object[trgobj[number]].speed[1] * object[trgobj[number]].mass);// * elastic;
                                    object1[2] += abs(object[trgobj[number]].speed[2] * object[trgobj[number]].mass);// * elastic;
                                    
                                    objnum.speed[0] = 0.5f * object1[0] * versor0[0] / objnum.mass;
                                    objnum.speed[1] = 0.5f * object1[1] * versor0[1] / objnum.mass;
                                    objnum.speed[2] = 0.5f * object1[2] * versor0[2] / objnum.mass;
                                    
                                    object[trgobj[number]].speed[0] = 0.5f * object1[0] * versor1[0] / object[trgobj[number]].mass;
                                    object[trgobj[number]].speed[1] = 0.5f * object1[1] * versor1[1] / object[trgobj[number]].mass;
                                    object[trgobj[number]].speed[2] = 0.5f * object1[2] * versor1[2] / object[trgobj[number]].mass;
                                    
                                    
                                    versor0[0] *= (objnum.radian+object[trgobj[number]].radian-radianobjects);
                                    versor0[1] *= (objnum.radian+object[trgobj[number]].radian-radianobjects);
                                    versor0[2] *= (objnum.radian+object[trgobj[number]].radian-radianobjects);
                                    
                                    versor1[0] *= (object[trgobj[number]].radian+objnum.radian-radianobjects);
                                    versor1[1] *= (object[trgobj[number]].radian+objnum.radian-radianobjects);
                                    versor1[2] *= (object[trgobj[number]].radian+objnum.radian-radianobjects);
                                    

				float speed1 = sqrt( objnum.speed[0]*objnum.speed[0] + objnum.speed[1]*objnum.speed[1] + objnum.speed[2]*objnum.speed[2] );
				float speed2 = sqrt( object[trgobj[number]].speed[0]*object[trgobj[number]].speed[0] + object[trgobj[number]].speed[1]*object[trgobj[number]].speed[1] + object[trgobj[number]].speed[2]*object[trgobj[number]].speed[2] );


				if( speed1 == 0.0f && speed2 == 0.0f )
				{
                                    objnum.pos[0] += versor0[0]/2.0f;
                                    objnum.pos[1] += versor0[1]/2.0f;
                                    objnum.pos[2] += versor0[2]/2.0f;
                                    
                                    object[trgobj[number]].pos[0] += versor1[0]/2.0f;
                                    object[trgobj[number]].pos[1] += versor1[1]/2.0f;
                                    object[trgobj[number]].pos[2] += versor1[2]/2.0f;
				}
				else
				{
					float speed12 = 1.0f;//speed1 + speed2;
					objnum.pos[0] += versor0[0] * speed12;// / speed12;
					objnum.pos[0] += versor0[1] * speed12;// / speed12;
					objnum.pos[2] += versor0[2] * speed12;// / speed12;

					//object[trgobj[number]].pos[0] += versor1[2] * speed2 / speed12;
					//object[trgobj[number]].pos[1] += versor1[2] * speed2 / speed12;
					//object[trgobj[number]].pos[2] += versor1[2] * speed2 / speed12;
				}
                                    
                                    
                                    
                                    
                                    
                                    
                                }
                        
                        
                        
                            }
                            }
                        }
                    }
                    }
            }
            }


		for( unsigned int x = 0; x < XTRIGGEROBJ; x++){
		for( unsigned int z = 0; z < ZTRIGGEROBJ; z++){
			trigger[x][z].obj.clear();
		}}
		
            for( calculate = 1; calculate < object.size(); calculate++ )
            {
                if( int(objnum.pos[0]/XSIZETRIGGEROBJ) < 0.0f || int(objnum.pos[2]/ZSIZETRIGGEROBJ) < 0.0f || int(objnum.pos[2]/ZSIZETRIGGEROBJ) > ( float(ZTRIGGEROBJ) * ZSIZETRIGGEROBJ ) || int(objnum.pos[0]/XSIZETRIGGEROBJ) > ( float(XTRIGGEROBJ) * XSIZETRIGGEROBJ ) )
                {}
                else
                {
                    trigger[int(objnum.pos[0]/XSIZETRIGGEROBJ)][int(objnum.pos[2]/ZSIZETRIGGEROBJ)].obj.push_back( calculate );
                }
            }     
        }
        */













        if( clock() <= beginntime + 5 )
            Sleep(5);
        endtime = clock();
    }

}

#undef objnum
#undef trg
#undef trgobj



