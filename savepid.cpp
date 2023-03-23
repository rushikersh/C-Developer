#include <iostream>
#include <unistd.h>

using namespace std;
#define PIDFILE "/tmp/pidfile"

int savePidFile()
{
        /**
         * It deletes old PID file if exists. In case failed to delete, or open, it will return an error.
         */
        if (access(PIDFILE, F_OK) == 0)
                if (unlink(PIDFILE) < 0)
                        {
                                cout<<"Unlink Failed\n";
                                return -1;
                        }
        FILE *pf = fopen(PIDFILE, "a+");
        if (pf == NULL)
        {
                cout<<"File Descriptor Fail\n";
                return -1;
        }
        /**
         * Process ID will be saved in file. This is required to check if another instance is already running of same binary. Some tools like initctl requires PID file when it starts the daemon.
         */
        fprintf(pf, "%u", getpid());
        fclose(pf);
        return 0;
}
void removePidFile()
{
                /**
                 *          * It is required to remove PID file before terminating the process. In case of failed to remove PID file, ignored.
                 *                   */
                unlink(PIDFILE);
}

int main()
{
        if(savePidFile()==0)
        {
                char b[1024]="" ;
                sprintf(b,"cat %s",PIDFILE);
                system(b);
        }
        else
                cout<<"Not save\n";
        cout<<endl;

        sleep(2);
        removePidFile();
}
