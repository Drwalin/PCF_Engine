class SettingsFile
{
    ifstream stfile;
    bool loaded;
public:
    SettingsFile() {loaded = 0;}
    ~SettingsFile() {if(loaded) stfile.close();}
    int LoadFile(const char* filename)
    {
        stfile.open(filename);
        if(!stfile.good())
    		return 0;
		loaded = 1;
		return 1;
    }
    int ReadSetting(string input)
    {
        stfile.clear();
        stfile.seekg(0);
    	char temp;
    	int output;
    	string filestr = "";
    	string sname = "";
    	while(!stfile.eof())
    	{
    		stfile.read(&temp, 1);
    		filestr += temp;
    		if(filestr[filestr.size()-1] == '=')
    			filestr[filestr.size()-1] = ' ';
    	}
    	stringstream ss;
    	ss.str(filestr);
    	while(ss)
    	{
    		ss>>sname;
    		if(sname == input)
    		{
    			ss>>output;
    			return output;
    		}
    		sname = "";
    	}
    	return -69;
    }
    
    string ReadSettingS(string input)
    {
        stfile.clear();
        stfile.seekg(0);
    	char temp;
    	string output;
    	string filestr = "";
    	string sname = "";
    	while(!stfile.eof())
    	{
    		stfile.read(&temp, 1);
    		filestr += temp;
    		if(filestr[filestr.size()-1] == '=')
    			filestr[filestr.size()-1] = ' ';
    	}
    	stringstream ss;
    	ss.str(filestr);
    	while(ss)
    	{
    		ss>>sname;
    		if(sname == input)
    		{
    			ss>>output;
    			return output;
    		}
    		sname = "";
    	}
    	return "";
    }
};
