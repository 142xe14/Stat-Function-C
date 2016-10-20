//
// Created by Julien Debroize on 20/10/2016.
// Un équivalent de la commande ls -li

#include "ex2.h"
int main(){
    struct passwd *user;
    struct group *groupe;
    struct tm * mtime;
    char timeString[80];
    DIR *repertoire = opendir ("."); //Répertoire courant
    if(repertoire == NULL){
        fprintf(stderr, "Erreur dans l'ouverture du repertoire");
        exit(EXIT_FAILURE);
    }
    struct stat info;

    struct dirent *fichierCourant;
    while ((fichierCourant = readdir(repertoire))){
        stat(fichierCourant->d_name, &info);
        user = getpwuid(info.st_uid);
        groupe = getgrgid(info.st_gid);
        time_t current_time= info.st_mtime;
        mtime = localtime(&current_time);
        strftime(timeString,80,"%d %H:%M", mtime);
        printf("%ld  -%3o %ld %s %s %ld oct. %s %s \n", info.st_ino, info.st_mode, info.st_nlink, user->pw_name, groupe->gr_name
                                                ,info.st_size, timeString, fichierCourant->d_name);
    }
    return EXIT_SUCCESS;
}
