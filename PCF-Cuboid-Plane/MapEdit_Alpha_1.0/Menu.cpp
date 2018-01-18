




int Menu()
{
	char command[64];
	char name[64];
	cout << "For help: help";
	while(1)
	{
		command[0] = 0;
		cout<<"\n map edit # ";
		cin >> command;

		if( strcmp( command, "help" ) == 0 )
		{
            cout<<"\n map %1     - loading map, %1 - map name";
            cout<<"\n exit       - close program";
            cout<<"\n continue   - continue making map";
            cout<<"\n save %1    - save map, %1 - map name";
            cout<<"\n texture %1 - load next texture, %1 -texture name";
            cout<<"\n";
		}
		else if( strcmp( command, "exit" ) == 0 )
		{
			exit( 0 );
		}
		else if( strcmp( command, "continue" ) == 0 )
		{
			return 0;
		}
		else if( strcmp( command, "map" ) == 0 )
		{
			name[0] = 0;
			cin >> name;
			map.LoadMap( name );
		}
		else if( strcmp( command, "texture" ) == 0 )
		{
			name[0] = 0;
			cin >> name;
			map.texturefiles.resize(map.texturefiles.size()+1);
			sprintf( map.texturefiles[map.texturefiles.size()-1].name, "%s", name );
			map.bitmapInfoHeader.resize(map.texturefiles.size()+1);
			map.bitmapData.resize(map.texturefiles.size()+1);
			map.texture.resize(map.texturefiles.size()+1);
		}
		else if( strcmp( command, "save" ) == 0 )
		{
			cin >> NameSaveMap;
			map.SaveMap( NameSaveMap );
		}






	}
	return 0;
}
