#include<windows.h>
#include<iostream>
#include<conio.h>
using namespace std;


typedef int( * MYPROC1 )( char * );
typedef unsigned int( * MYPROC2 )( unsigned int, int );
typedef unsigned int( * MYPROC3 )( char * );
typedef int( * MYPROC4 )( unsigned int );
typedef char * ( * MYPROC5 )( unsigned int, int );
typedef char * ( * MYPROC6 )( unsigned int );

MYPROC1 LoadScripts;
MYPROC2 GetNextDialogueIdAnswer;
MYPROC3 GetDialogueIdName;
MYPROC4 GetDialogueType;
MYPROC5 GetTextAnswers;
MYPROC6 GetTextNPC;

HINSTANCE hDll;

int InitScriptsFunctions()
{
    hDll = LoadLibrary( "ScriptDLL" );

    if( hDll != NULL )
    {
        LoadScripts =( MYPROC1 ) GetProcAddress( hDll, "_LoadScripts" );
        GetNextDialogueIdAnswer =( MYPROC2 ) GetProcAddress( hDll, "_GetNextDialogueIdAnswer" );
        GetDialogueIdName =( MYPROC3 ) GetProcAddress( hDll, "_GetDialogueIdName" );
        GetDialogueType =( MYPROC4 ) GetProcAddress( hDll, "_GetDialogueType" );
        GetTextAnswers =( MYPROC5 ) GetProcAddress( hDll, "_GetTextAnswers" );
        GetTextNPC =( MYPROC6 ) GetProcAddress( hDll, "_GetTextNPC" );
    
        if( LoadScripts == NULL ||
            GetNextDialogueIdAnswer == NULL ||
            GetDialogueIdName == NULL ||
            GetDialogueType == NULL ||
            GetTextAnswers == NULL ||
            GetTextNPC == NULL )
        {
            FreeLibrary( hDll );
            return -69;
        }
    
        return 1;
    }
    else
    {
        return -69;
    }
}

int DeInitScriptsFunctions()
{
    if( hDll ==NULL )
    {
        return -69;
    }
    else
    {
        FreeLibrary( hDll );
        return 1;
    }
    return -69;
}
