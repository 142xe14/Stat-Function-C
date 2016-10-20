//
// Created by Julien Debroize on 20/10/2016.
// Donne des informations sur un fichier

#include "ex1.h"
int main(int argc, char *argv[]){
    char* c_time_string;
    struct passwd *user;
    struct group *groupe;

    if(argc != 2){
        fprintf(stderr, "Erreur d'usage entrer le Path d'un fichier!\n");
        exit(EXIT_FAILURE);
    }

    struct stat info;
    if (stat(argv[1], &info) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    //Affichage des infos
    printf("Numéro d-inode : %ld\n", info.st_ino);
    printf("Type de fichier et protection : %3o\n", info.st_mode);
    printf("Nombre de lien : %ld\n", info.st_nlink);
    user = getpwuid(info.st_uid);
    printf("Proprietaire : %s\n", user->pw_name);
    groupe = getgrgid(info.st_gid);
    printf("Groupe : %s\n", groupe->gr_name);
    printf("Taille du fichier : %ld\n", info.st_size);

    time_t current_time= info.st_mtime;
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        fprintf(stderr, "Erreur lors de la conversion de du temps!\n");
        exit(EXIT_FAILURE);
    }

    printf("Date de derniere modification : %s", c_time_string);
    printf("Nom de fichier : %s\n", argv[1]);
    return EXIT_SUCCESS;
}