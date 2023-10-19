#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Interface for Command Pattern
 * 
 */
class Command
{
    public:
        /**
         * @brief Construct a new Command object
         * 
         */
        Command() {}

        /**
         * @brief Destroy the Command object
         * 
         */
        virtual ~Command() {}

        /**
         * @brief 
         * 
         */
        virtual void execute() = 0;
};

#endif