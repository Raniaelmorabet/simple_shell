#include "main.h"

int _cd(char **env, int args)
{
	// todo:
	// 1. if no args, go to "cd $HOME"
	// 2. if args[1] == "-", go to "cd $OLDPWD"
	// 3. if args[1] == "~", go to "cd $HOME"
	// 4. Update $OLDPWD and $PWD

	return (0);
}

//void _cd(char *args[]) {
//    char *home_dir = getenv("HOME");
//    char *oldpwd_dir = getenv("OLDPWD");
//    char *cd_dir = args[1];
//    char pwd[1024];
//
//    // Case 1: No arguments provided, change to home directory
//    if (args[1] == NULL) {
//        chdir(home_dir);
//    }
//
//    // Case 2: Change to previous working directory
//    else if (strcmp(cd_dir, "-") == 0) {
//        if (oldpwd_dir == NULL) {
//            fprintf(stderr, "OLDPWD not set\n");
//            return;
//        }
//        chdir(oldpwd_dir);
//        printf("%s\n", oldpwd_dir);
//    }
//
//    // Case 3: Change to home directory
//    else if (strcmp(cd_dir, "~") == 0) {
//        chdir(home_dir);
//    }
//
//    // Case 4: Change to directory provided as argument
//    else {
//        if (chdir(cd_dir) == -1) {
//            fprintf(stderr, "cd: %s: No such file or directory\n", cd_dir);
//            return;
//        }
//    }
//
//    // Update $OLDPWD and $PWD
//    if (getcwd(pwd, sizeof(pwd)) != NULL) {
//        setenv("OLDPWD", getenv("PWD"), 1);
//        setenv("PWD", pwd, 1);
//    }
//}
