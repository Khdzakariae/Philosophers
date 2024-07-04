// #include <philo_bonus.h>

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void allo()
{
    puts("hey im here");
    exit(-1);
}

int main(int argc, char **argv)
{
    int status = 0;
    int pid = fork();
    
    if (pid == 0)
    {
        // Child process
        allo();
    }
    else if (pid > 0)
    {
        // Parent process
        waitpid(pid, &status, 0);
        
        if ( WEXITSTATUS(status) == -1)
        {
            printf("hello\n");
        }
        if (WIFEXITED(status))
        {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child terminated by signal: %d\n", WTERMSIG(status));
        }
    }
    else
    {
        // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}
