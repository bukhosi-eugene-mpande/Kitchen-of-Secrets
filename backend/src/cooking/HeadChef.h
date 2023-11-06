/**
 * @file HeadChef.h
 * @brief Contains the declaration of the HeadChef class, derived from the Chef class.
 */

#ifndef HEAD_CHEF_H
#define HEAD_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

#include "../management/PlayerInteraction.h"

/**
 * @class HeadChef
 * @brief Represents the head chef overseeing kitchen operations.
 *
 * The HeadChef class is derived from the Chef class and represents the head chef responsible for overseeing
 * kitchen operations. The head chef collaborates with kitchen staff and interacts with management for
 * efficient kitchen management.
 */
class HeadChef : public Chef {
private:
    PlayerInteraction* management; /**< A pointer to the PlayerInteraction object for management interaction. */

    std::string name; /**< The name of the head chef. */

public:
    /**
     * @brief Constructor for the HeadChef class.
     * @param kitchen A pointer to the Kitchen where the HeadChef works.
     * @param management A pointer to the PlayerInteraction object for management interaction.
     */
    HeadChef(Kitchen* kitchen, PlayerInteraction* management);

    /**
     * @brief Destructor for the HeadChef class.
     */
    ~HeadChef();

    /**
     * @brief Get the name of the head chef.
     * @return A string containing the name of the head chef.
     */
    std::string getName() const;

    /**
     * @brief Get the Kitchen where the head chef works.
     * @return A pointer to the Kitchen where the head chef is stationed.
     */
    Kitchen* getKitchen() const;

    /**
     * @brief Perform rounds or checks in the kitchen to ensure smooth kitchen operations.
     */
    void goOnRounds();
};

#endif
