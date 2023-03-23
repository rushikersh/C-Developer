/*******************************************************************************************
  Note :  Never call WriteLogForlibmwshare function in this function (due to recrsive call)
 ******************************************************************************************/



#include <string.h>
#include <unistd.h>
//#include "sfl.h"
#include <stdlib.h>
#include <stdio.h>
//#include "WriteLogForlibmwshare.h"

pthread_mutex_t sfl_mutex = PTHREAD_MUTEX_INITIALIZER;


int readConfiguration(const char *fileName, char *option, char *output)
{
        time_t sinceepoch = time(NULL);
        struct tm *rpt_time = localtime(&sinceepoch);
        char rtime[24];
        memset(rtime, 0, 24);
        strftime(rtime, 23, "[%d-%b-%Y@%H:%M:%S] ", rpt_time);

        if( fileName == NULL || option == NULL || output == NULL )
        {

                FILE *fp = fopen("/var/MicroWorld/var/log/libmwshare.log", "a");
                if(fp)
                {
                        fprintf(fp,"%s ", rtime );
                        fputs("Null arguments to read configuration\n", fp);
                        fclose(fp);
                }
                return -1;
        }
        pthread_mutex_lock(&sfl_mutex);
        SYMTAB *Table = NULL;
        char *cPtr;
        if (access(fileName, F_OK) != 0 )
        {
                FILE *fp = fopen("/var/MicroWorld/var/log/libmwshare.log", "a");
                if(fp)
                {
                        fprintf(fp,"%s ", rtime );
                        fprintf(fp, "No access to configuration file %s\n",fileName);
                        fclose(fp);
                }
                pthread_mutex_unlock(&sfl_mutex);
                return -1;
        }
        Table = sym_create_table();
        Table = ini_dyn_load (Table, fileName);
        if(Table == NULL)
        {
                FILE *fp = fopen("/var/MicroWorld/var/log/libmwshare.log", "a");
                if(fp)
                {
                        fprintf(fp,"%s ", rtime );
                        fprintf(fp, "Unable to load configuration form configuration file %s\n",fileName);
                        fclose(fp);
                }
                sym_delete_table (Table);
                pthread_mutex_unlock(&sfl_mutex);
                return -1;
        }
        cPtr = sym_get_value (Table, option, NULL);
        if(cPtr == NULL)
        {
                if(strcmp(option, "Config:DebugLevel") != 0 && strcmp(option, "Events:IgnoreEventIds") != 0)
                {
                        FILE *fp = fopen("/var/MicroWorld/var/log/libmwshare.log", "a");
                        if(fp)
                        {
                                fprintf(fp,"%s ", rtime );
                                fprintf(fp, "Unable to get value from configuration file %s:%s\n",fileName, option);
                                fclose(fp);
                        }

                }
                sym_delete_table (Table);
                pthread_mutex_unlock(&sfl_mutex);
                return -1;
        }
        strcpy(output, cPtr);
        sym_delete_table (Table);
        pthread_mutex_unlock(&sfl_mutex);
        if(strlen(output) < 1)
        {
                FILE *fp = fopen("/var/MicroWorld/var/log/libmwshare.log", "a");
                if(fp)
                {
                        fprintf(fp,"%s ", rtime );
                        fprintf(fp, "Uunspecified configuration : %s:%s\n",fileName, option);
                        fclose(fp);
                }
                return -1;
        }
        return 0;
}

