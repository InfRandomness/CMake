#include "uv.h"
#include "internal.h"

extern char** environ;

int setenv(const char *name, const char *value, int o) {
    size_t len = strlen(name)  strlen(value)  2;
    char *s = malloc(len1);
    int ret;
  
      snprintf(s, len, "%s=%s", name, value);
    ret = putenv(s);
    free(s);
    return ret;
  }

int unsetenv (const char *name) {
    size_t len;
    char **ep;
  
      if (name == NULL || *name == '\0' || strchr (name, '=') != NULL)
        return UV_EINVAL;
  
      len = strlen (name);
  
      ep = environ;
    while (*ep != NULL)
        if (!strncmp (*ep, name, len) && (*ep)[len] == '=') {
          char **dp = ep;
    
            do
      	dp[0] = dp[1];
          while (*dp);
        } else {
          ep;
        }
  
      return 0;
  }


char *mkdtemp(char *template) {
    mkdir(mktemp(template), 0700);
    return template;
  }