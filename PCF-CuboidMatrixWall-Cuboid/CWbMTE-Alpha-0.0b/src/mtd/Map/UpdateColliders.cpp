






inline void Map::UpdateColliders()
{
    AABB * fast = NULL;
    if( objAABB.size() > 1 )
    {
        objAABB[1].ColliderDownX = NULL;
        objAABB[1].ColliderUpX = NULL;
        for( unsigned int i = 2; i < objAABB.size(); i++ )
        {
            objAABB[i].ColliderDownX = NULL;
            objAABB[i].ColliderUpX = NULL;
            fast = &objAABB[1];
            while( fast != &objAABB[i] )
            {
                if( objAABB[i].pos[0] < fast -> pos[0] )
                {
                    if( fast -> ColliderDownX != NULL )
                    {
                        fast = (fast -> ColliderDownX);
                    }
                    else
                    {
                        fast = &objAABB[i];
                    }
                }
                else
                {
                    if( fast -> ColliderUpX != NULL )
                    {
                        fast = (fast -> ColliderUpX);
                    }
                    else
                    {
                        fast = &objAABB[i];
                    }
                }
            }
        }
    }
}



