#include "functions.h"

struct bg_process
{
    char processName[100];
    pid_t pid;
    int status; //1 if running, 0 if terminated
};

struct bg_process bg_processes[MAX_NUM_OF_BG_PROCESSES];

int numOfbgProcesses = 0;


void handler(int sig)
{
    pid_t pid;
    int status;

    pid = waitpid(-1, &status, WNOHANG);

    if (pid > 0)
    {
        for (int i = 0; i < numOfbgProcesses; i++)
        {
            //printf("%d: %s", i, bg_processes[i].processName);

            if (bg_processes[i].pid == pid && bg_processes[i].status == 1)
            {
                if (WIFEXITED(status))
                {
                    printf("\n%s with pid %d has exited normally", bg_processes[i].processName, bg_processes[i].pid);
                }
                else
                {
                    printf("\n%s with pid %d has exited abnormally\n", bg_processes[i].processName, bg_processes[i].pid);
                }
                bg_processes[i].status = 0;
                fflush(stdout);

                break;
            }
        }
    }

    return;
}

void backgroundProcess(char *token[])
{

    pid_t child_pid;
    int stats;

    pid_t back_pid;

    //fork returns the pid of the child process that was created
    child_pid = fork();

    if (child_pid < 0)
    {
        printf("Error: fork failed\n");
    }
    else if (child_pid == 0) //this will only be executed by the child process
    {
        setpgid(0, 0);

        int result;

        result = execvp(token[0], token);

        if (result < 0)
        {
            printf("Error exec failed: command does not exist\n");
            //fflush(stdout);
        }

        exit(0);
    }
    else //this will only be executed by the parent process
    {
        printf("%d\n", child_pid);

        strcpy(bg_processes[numOfbgProcesses].processName, token[0]);
        bg_processes[numOfbgProcesses].pid = child_pid;
        bg_processes[numOfbgProcesses].status = 1;


        numOfbgProcesses++;

        signal(SIGCHLD, handler);

    }
}