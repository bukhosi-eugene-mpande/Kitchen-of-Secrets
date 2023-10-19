#ifndef COMMAND_H
#define COMMAND_H

class Command
{
    public:
        Command() {}
        virtual ~Command() {}
        virtual void execute() = 0;
};

#endif