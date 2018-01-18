

#define objnum object[calculate]
#define trg trigger[int(x/XSIZETRIGGER)][int(z/ZSIZETRIGGER)].tri[a]


void CollisionObjectTriangle( unsigned int calculate, float x, float z, unsigned int time )
{
    float drad = 0.0f;
    
    for( unsigned int a = 0; a < trigger[int(x/XSIZETRIGGER)][int(z/ZSIZETRIGGER)].tri.size(); a++ )
    {
        drad = 
                abs(
                map.tri[trg].normal[0]*(objnum.pos[0]-map.tri[trg].tri[0][0]) +
                map.tri[trg].normal[1]*(objnum.pos[1]-map.tri[trg].tri[0][1]) +
                map.tri[trg].normal[2]*(objnum.pos[2]-map.tri[trg].tri[0][2])// +
                ) // map.tri[trg].det )
                /
                sqrt(
                map.tri[trg].normal[0] * map.tri[trg].normal[0] +
                map.tri[trg].normal[1] * map.tri[trg].normal[1] +
                map.tri[trg].normal[2] * map.tri[trg].normal[2] );

        if( drad <= objnum.radian )
        {
            if( sqrt( pow(objnum.pos[0]-map.tri[trg].sphere[0],2)+pow(objnum.pos[1]-map.tri[trg].sphere[1],2)+pow(objnum.pos[2]-map.tri[trg].sphere[2],2) ) <= abs( objnum.radian + map.tri[trg].radian ) )
            {
                objnum.collision = true;
                if( drad == objnum.radian )
                {
                    //tylko sily, sily tarcia
                }
                else if ( drad < objnum.radian )
                {
                        objnum.collision = true;
                    //sily, predkosci, pozycje, sila tarcia
                    
                        object[calculate].pos[0] = object[calculate].bpos[0];
                        object[calculate].pos[1] = object[calculate].bpos[1];
                        object[calculate].pos[2] = object[calculate].bpos[2];

                   //     objnum.speed[0] = 0.0f;
                   //     objnum.speed[1] = 0.0f;
                   //     objnum.speed[2] = 0.0f;
                   
                   
                   
                   
                   
                   
                   
                   
                        
                        
                        float rnormal = sqrt( ( map.tri[trg].normal[0] * map.tri[trg].normal[0] ) + ( map.tri[trg].normal[1] * map.tri[trg].normal[1] ) + ( map.tri[trg].normal[2] * map.tri[trg].normal[2] ) );

                        float rflat = (
				                    	map.tri[trg].normal[0] * objnum.speed[0] +
				                       	map.tri[trg].normal[1] * objnum.speed[1] +
			                     		map.tri[trg].normal[2] * objnum.speed[2] )
			                     		/ rnormal; /*
			                     		sqrt(
			                 			map.tri[trg].normal[0] * map.tri[trg].normal[0] +
			                 			map.tri[trg].normal[1] * map.tri[trg].normal[1] +
				                		map.tri[trg].normal[2] * map.tri[trg].normal[2] );
				                		*/
				                		
                        float rforce = (
				                    	map.tri[trg].normal[0] * objnum.force[0] +
				                       	map.tri[trg].normal[1] * objnum.force[1] +
			                     		map.tri[trg].normal[2] * objnum.force[2] )
			                     		/ rnormal; /*
			                     		sqrt(
			                 			map.tri[trg].normal[0] * map.tri[trg].normal[0] +
			                 			map.tri[trg].normal[1] * map.tri[trg].normal[1] +
				                		map.tri[trg].normal[2] * map.tri[trg].normal[2] );
				                		*/
				                		
			            float pnormal[3] = { ( map.tri[trg].normal[0] / rnormal ) * rflat , ( map.tri[trg].normal[1] / rnormal ) * rflat , ( map.tri[trg].normal[2] / rnormal ) * rflat };
			            float pforce[3] = { ( map.tri[trg].normal[0] / rnormal ) * rforce , ( map.tri[trg].normal[1] / rnormal ) * rforce , ( map.tri[trg].normal[2] / rnormal ) * rforce };
			            //float speed[3] = { pnormal[0] - objnum.speed[0] , pnormal[1] - objnum.speed[1] , pnormal[2] - objnum.speed[2] };
			
			        
			             
			             //objnum.force[0] -= ( map.tri[trg].terrainresistance * speed[0] * objnum.mass / ((float(time)/1000.0f)+0.01f))/40.0f;
			             //objnum.force[1] -= ( map.tri[trg].terrainresistance * speed[1] * objnum.mass / ((float(time)/1000.0f)+0.01f))/40.0f;
			             //objnum.force[2] -= ( map.tri[trg].terrainresistance * speed[2] * objnum.mass / ((float(time)/1000.0f)+0.01f))/40.0f;
			        
			             //objnum.force[0] -= map.tri[trg].terrainresistance * objnum.speed[0] * objnum.mass / (float(time)/1000.0f);
			             //objnum.force[1] -= map.tri[trg].terrainresistance * objnum.speed[1] * objnum.mass / (float(time)/1000.0f);
			             //objnum.force[2] -= map.tri[trg].terrainresistance * objnum.speed[2] * objnum.mass / (float(time)/1000.0f);
		
		                if( ( drad < 0 && rflat > 0 ) || ( drad > 0 && rflat < 0 ) )
		                {
                            objnum.speed[0] -= pnormal[0] + ( pnormal[0] * objnum.elastic );
                            objnum.speed[1] -= pnormal[1] + ( pnormal[1] * objnum.elastic );
                            objnum.speed[2] -= pnormal[2] + ( pnormal[2] * objnum.elastic );
                            
                            //objnum.speed[0] -= pnormal[0] + ( pnormal[0] );
                            //objnum.speed[1] -= pnormal[1] + ( pnormal[1] );
                            //objnum.speed[2] -= pnormal[2] + ( pnormal[2] );
                            
                        //    objnum.speed[0] = 0 - objnum.speed[0];
                        //    objnum.speed[1] = 0 - objnum.speed[1];
                        //    objnum.speed[2] = 0 - objnum.speed[2];
                            
    			            float speed[3] = { pnormal[0] - objnum.speed[0] , pnormal[1] - objnum.speed[1] , pnormal[2] - objnum.speed[2] };
    			             
                            //objnum.speed[0] *= 0.5f; // map.tri[trg].terrainresistance;
                            //objnum.speed[1] *= 0.5f; // Smap.tri[trg].terrainresistance;
                            //objnum.speed[2] *= 0.5f; // map.tri[trg].terrainresistance;
    			             
    			             objnum.force[0] -= ( map.tri[trg].terrainresistance * speed[0] * objnum.mass / (float(time)/1000.0f));
    			             objnum.force[1] -= ( map.tri[trg].terrainresistance * speed[1] * objnum.mass / (float(time)/1000.0f));
    			             objnum.force[2] -= ( map.tri[trg].terrainresistance * speed[2] * objnum.mass / (float(time)/1000.0f));
                        }
                        
		                if( ( drad < 0 && rforce > 0 ) || ( drad > 0 && rforce < 0 ) )
		                {
    			             objnum.force[0] -= pforce[0] + ( pforce[0] * objnum.elastic );
    			             objnum.force[1] -= pforce[1] + ( pforce[1] * objnum.elastic );
    			             objnum.force[2] -= pforce[2] + ( pforce[2] * objnum.elastic );
    			             
			             //objnum.force[0] -= pforce[0] + pforce[0];
			             //objnum.force[1] -= pforce[1] + pforce[1];
			             //objnum.force[2] -= pforce[2] + pforce[2];
			             
			             //objnum.force[0] = 0.0f-objnum.force[0];
			             //objnum.force[1] = 0.0f-objnum.force[0];
			             //objnum.force[2] = 0.0f-objnum.force[0];
                        }
                        
                        
		                
                }
            }
        }
    }
}



#undef objnum
#undef trg






