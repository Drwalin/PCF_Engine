

#define objnum object[calculate]
#define trg trigger[int(x/XSIZETRIGGER)][int(z/ZSIZETRIGGER)].tri[a]


bool CollisionObjectTriangle( unsigned int calculate, float x, float z, unsigned int time )
{
    float drad = 0.0f;
    float rnormal = 0.0f;
    
    for( unsigned int a = 0; a < trigger[int(x/XSIZETRIGGER)][int(z/ZSIZETRIGGER)].tri.size(); a++ )
    {
        
        
        
        
        rnormal = sqrt( ( map.tri[trg].normal[0] * map.tri[trg].normal[0] ) + ( map.tri[trg].normal[1] * map.tri[trg].normal[1] ) + ( map.tri[trg].normal[2] * map.tri[trg].normal[2] ) );
        if( rnormal == 0.0f )
            continue;
        drad = 
                ( //abs(
                map.tri[trg].normal[0]*(objnum.pos[0]-map.tri[trg].tri[0][0]) +
                map.tri[trg].normal[1]*(objnum.pos[1]-map.tri[trg].tri[0][1]) +
                map.tri[trg].normal[2]*(objnum.pos[2]-map.tri[trg].tri[0][2])// +
                ) // map.tri[trg].det )
                / rnormal;
                
        if( drad == 0.0f )
            continue;

        if( abs(drad) <= objnum.radian )
        {
            if( sqrt( pow(objnum.pos[0]-map.tri[trg].sphere[0][0],2)+pow(objnum.pos[1]-map.tri[trg].sphere[0][1],2)+pow(objnum.pos[2]-map.tri[trg].sphere[0][2],2) ) <= abs( objnum.radian + map.tri[trg].radian[0] ) )
            {
            if( sqrt( pow(objnum.pos[0]-map.tri[trg].sphere[1][0],2)+pow(objnum.pos[1]-map.tri[trg].sphere[1][1],2)+pow(objnum.pos[2]-map.tri[trg].sphere[1][2],2) ) <= abs( objnum.radian + map.tri[trg].radian[1] ) )
            {
            if( sqrt( pow(objnum.pos[0]-map.tri[trg].sphere[2][0],2)+pow(objnum.pos[1]-map.tri[trg].sphere[2][1],2)+pow(objnum.pos[2]-map.tri[trg].sphere[2][2],2) ) <= abs( objnum.radian + map.tri[trg].radian[2] ) )
            {
                objnum.collision = true;
                    if( drad != 0.0f && rnormal != 0.0f )
                    {
    			        float pobjmove[3] = { ( map.tri[trg].normal[0] * ((objnum.radian*drad/abs(drad))-drad) / rnormal ) , ( map.tri[trg].normal[1] * ((objnum.radian*drad/abs(drad))-drad) / rnormal ) , ( map.tri[trg].normal[2] * ((objnum.radian*drad/abs(drad))-drad) / rnormal ) };
    			        
 
    			        
                        objnum.pos[0] += pobjmove[0];
                        objnum.pos[1] += pobjmove[1];
                        objnum.pos[2] += pobjmove[2];
                    }else{
                        objnum.pos[0] = objnum.bpos[0];
                        objnum.pos[1] = objnum.bpos[1];
                        objnum.pos[2] = objnum.bpos[2];
                    }
                
                        float rflat = (
				                    	map.tri[trg].normal[0] * objnum.speed[0] +
				                       	map.tri[trg].normal[1] * objnum.speed[1] +
			                     		map.tri[trg].normal[2] * objnum.speed[2] )
			                     		/ rnormal;
				                		
				                		
				                		
                        float rforce = (
				                    	map.tri[trg].normal[0] * objnum.force[0] +
				                       	map.tri[trg].normal[1] * objnum.force[1] +
			                     		map.tri[trg].normal[2] * objnum.force[2] )
			                     		/ rnormal;
				                		
			            float pnormal[3] = { ( map.tri[trg].normal[0] * rflat / rnormal ) , ( map.tri[trg].normal[1] * rflat / rnormal ) , ( map.tri[trg].normal[2] * rflat / rnormal ) };
			            float pforce[3] = {  ( map.tri[trg].normal[0] * rforce / rnormal ) , ( map.tri[trg].normal[1] * rforce / rnormal ) , ( map.tri[trg].normal[2] * rforce / rnormal ) };
			          
			            
			            
			        
    			            float speed[3] = { pnormal[0] - objnum.speed[0] , pnormal[1] - objnum.speed[1] , pnormal[2] - objnum.speed[2] };
                        
		                if( ( (drad < 0.0f) && (rflat > 0.0f) ) || ( (drad > 0.0f) && (rflat < 0.0f) ) )
		                {
                             
                            
                            objnum.speed[0] -= pnormal[0] + ( pnormal[0] * objnum.elastic );
                            objnum.speed[1] -= pnormal[1] + ( pnormal[1] * objnum.elastic );
                            objnum.speed[2] -= pnormal[2] + ( pnormal[2] * objnum.elastic );
                            
                            
    			            
    			            
                        
                        }
                        
                            
			            
		                if( ( (drad < 0.0f) && (rforce > 0.0f) ) || ( (drad > 0.0f) && (rforce < 0.0f) ) )
		                {
                            
                            objnum.force[0] -= pforce[0] + ( pnormal[0] * objnum.elastic );
                            objnum.force[1] -= pforce[1] + ( pnormal[1] * objnum.elastic );
                            objnum.force[2] -= pforce[2] + ( pnormal[2] * objnum.elastic );
                        } 
    			            float resistanceforce = abs(rforce) * map.tri[trg].terrainresistance;
    			            
    			            float rspeed = sqrt( speed[0]*speed[0] + speed[1]*speed[1] + speed[2]*speed[2] );
    			            if( rspeed >= 5.0f )
    			            {
    			                     objnum.force[0] += 1.5f * resistanceforce * speed[0] / (rspeed*1.0f);
    			                     objnum.force[1] += 1.5f * resistanceforce * speed[1] / (rspeed*1.0f);
    			                     objnum.force[2] += 1.5f * resistanceforce * speed[2] / (rspeed*1.0f);
                            }
                            else if( rspeed >= 0.05f )
                            {
    			                     objnum.force[0] += 0.4f * resistanceforce * speed[0] / (rspeed*1.0f);
    			                     objnum.force[1] += 0.4f * resistanceforce * speed[1] / (rspeed*1.0f);
    			                     objnum.force[2] += 0.4f * resistanceforce * speed[2] / (rspeed*1.0f);
                            }
                            else
                            {
                                if( sqrt( objnum.force[0]*objnum.force[0] + objnum.force[1]*objnum.force[1] + objnum.force[2]*objnum.force[2] )/0.5f <= resistanceforce*0.5f )
        		                {
                                       objnum.force[0] = 0.0f;
                                       objnum.force[1] = 0.0f;
                                       objnum.force[2] = 0.0f;
                                       
                                       objnum.speed[0] = 0.0f;
                                       objnum.speed[1] = 0.0f;
                                       objnum.speed[2] = 0.0f;
                                }
                                else
                                {
                                       
                                }
                            }
			            
			            
                        
                objnum.collision = true;
            }}} //zamkniecie nawiasow od sfer trojkata
        }
    }
}



#undef objnum
#undef trg










