


inline void StaticGraphicModel::Draw()
{
	int i;
	for( i = 0; i < VBO.size(); ++i )
	{
		VBO[i].Draw();
	}
}


