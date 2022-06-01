#include "/sys/simul_efun.h"
#include <strings.h>

string *explode_file(string file)
{
    string *lines = ({ }) ;

    if(file_size(file) < 1) return lines ;

    lines = explode(read_file(file), "\n") ;
    lines = map(lines, (: trim($1, TRIM_BOTH) :) ) ;
    lines = filter(lines, (: $1[0] != "#" :) );

    return lines ;
}
