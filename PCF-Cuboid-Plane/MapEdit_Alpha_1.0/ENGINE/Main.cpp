#include"Libraries.h"



void Okno (int *argc, char** argv)
{
	   glutInit (argc, argv);
	   glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);

	   glutInitWindowSize (X_window, Y_window);

	   glutInitWindowPosition (X_position, Y_position);

	   glutCreateWindow ("Engine");//EngineName);

	   glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

//cout<<endl<<"dupsko0";

		glEnable( GL_TEXTURE_2D );
		
		unsigned int number = 0;
		//wczytywanie tekstur
		for( number = 0; number < map.texturefiles.size(); number++ )
		{
			map.bitmapData[ number ] = LoadBitmapFileRGBA( map.texturefiles[ number ].name , &map.bitmapInfoHeader[ number ] );

			glGenTextures( 1, &map.texture[ number ] );
			glBindTexture( GL_TEXTURE_2D, map.texture[ number ] );

			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );	//GL_NEAREST
			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );	//GL_NEAREST

			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
			glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );

			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, map.bitmapInfoHeader[ number ].biWidth,
						 map.bitmapInfoHeader[ number ].biHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, map.bitmapData[ number ]);
		}
		
		ScreenLoadTextures();
		
		for( number = 0; number < humanoid.size(); number++ )
		{
            humanoid[number].Init();
        }
		for( number = 0; number < cubes.size(); number++ )
		{
            cubes[number].Init();
        }

   if(FULLSCREEN_IS == true){
	   glutFullScreen();
   }
	
   glLineWidth(10.0);

   glClearColor (0.0f, 0.0f, 0.0f, 0.0f);

	glEnable( GL_DEPTH );
	
//   glEnable (GL_AUTO_NORMAL);
}



void Reshape (int w, int h)
{
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   GLint f=(GLint)w/(GLint)h;
//   gluPerspective(aspectshow/*90.0f*/, float(glutGet( GLUT_WINDOW_WIDTH ))/float(glutGet( GLUT_WINDOW_HEIGHT )), 0.01f, 100000000000.0f);
    gluPerspective(aspectshow/*90.0f*/, 16.0f/9.0f, 0.01f, 100000000000.0f);
}



void KeyboardDown (unsigned char key, int x, int y)
{
//    keys[key] = true;
    
}

void KeyboardUp( unsigned char key, int x, int y )
{
//    keys[key] = false;
}


void Bez_Zegara(int argument)
{





    Renderer();
    Reshape(glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ));


    glutTimerFunc ( 15, Bez_Zegara, 0);
    glutPostRedisplay();
}


 


int LoadEngine(int *argc, char** argv)
{
	srand(time(NULL));

		ShowCursor(FALSE);
//    cout<<endl<<"dupa0?";


	   Okno (argc, argv);
//    cout<<endl<<"dupa1?";
	   
	   glutReshapeFunc (Reshape);
//    cout<<endl<<"dupa2?";
	   glutKeyboardFunc (KeyboardDown);
//	   glutKeyboardUpFunc(KeyboardUp);
//    cout<<endl<<"dupa3?";
//	   glutSpecialFunc (Special);
	   glutDisplayFunc (Renderer);
//    cout<<endl<<"dupa4?";
		glutTimerFunc (/*TimePerGenerateMapIteration*/ 10, Bez_Zegara, 0);
		glutMainLoop();

	return 0;
}




