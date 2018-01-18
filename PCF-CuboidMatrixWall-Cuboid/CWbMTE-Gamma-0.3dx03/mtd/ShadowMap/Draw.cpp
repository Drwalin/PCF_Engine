


inline void ShadowMap::Draw()
{
	VMatrix matrix;
	matrix.InitEmpty();
	matrix.RotateY( engineInstance->Object(0)->see[0] + 90.0f );
	matrix.RotateX( -engineInstance->Object(0)->see[1] );
	Vector vecDir = matrix.GetVertex( SetVector( 0.0f, 0.0f, -0.1f ) );
//	glTranslatef( vecDir[0], vecDir[1], vecDir[2] );
	VBO.Generate();
	VBO.Draw();
	VBO.Delete();
//	glTranslatef( -vecDir[0], -vecDir[1], -vecDir[2] );
}


