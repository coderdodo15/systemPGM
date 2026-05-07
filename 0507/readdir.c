#include <sys/types.h>
#include <dirent.h>
DIR *opendir (const char *path);
struct dirent *readdir(DIR *dp);
