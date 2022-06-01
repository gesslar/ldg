#include "/sys/simul_efun.h"

void assure_directory(string path)
{
    string *parts, dir;
    int j;

    if( file_size(path) == -2 ) return ;

    parts = explode(path, "/");
    dir = "";
    for (j = 0; j < sizeof(parts); j++)
    {
        dir += parts[j] + "/";
        if( file_size(dir) == -2 ) continue ;
        
        mkdir(dir);
    }
}

varargs string player_path(mixed name, int no_create = 0)
{
    string path;

    if(objectp(name) && name->query_player_object()) name = name->query_real_name() ;
    if(!stringp(name)) raise_error("player_path: argument must be a player object or a name.\n") ;

    path = "/data/players/"+name[0..0]+"/"+name+"/";
    path = lower_case(path);
    if(no_create == 0) assure_directory(path);

    return path;
}
