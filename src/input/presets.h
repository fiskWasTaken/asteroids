#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "KeyboardController.h"
#include "JoystickController.h"

namespace presets
{
    inline IController *defaultK0()
    {
        auto controller = new KeyboardController();
        controller->bind(InputAction::ACCELERATE, sf::Keyboard::W);
        controller->bind(InputAction::BRAKE, sf::Keyboard::S);
        controller->bind(InputAction::LEFT, sf::Keyboard::A);
        controller->bind(InputAction::RIGHT, sf::Keyboard::D);
        controller->bind(InputAction::FIRE, sf::Keyboard::LShift);
        controller->bind(InputAction::ALTFIRE, sf::Keyboard::Space);
        controller->bind(InputAction::PANIC, sf::Keyboard::K);
        controller->bind(InputAction::PAUSE, sf::Keyboard::P);

        return controller;
    }

    inline IController *defaultK1()
    {
        auto controller = new KeyboardController();
        controller->bind(InputAction::ACCELERATE, sf::Keyboard::Up);
        controller->bind(InputAction::BRAKE, sf::Keyboard::Down);
        controller->bind(InputAction::LEFT, sf::Keyboard::Left);
        controller->bind(InputAction::RIGHT, sf::Keyboard::Right);
        controller->bind(InputAction::FIRE, sf::Keyboard::RShift);

        return controller;
    }

    inline IController *defaultJoystick(unsigned int index = 0)
    {
        auto controller = new JoystickController(index);

        controller->assignAxisToActions(sf::Joystick::Axis::X, {InputAction::LEFT,
                                                                InputAction::RIGHT});

        controller->assignAxisToActions(sf::Joystick::Axis::Z, {InputAction::NIL,
                                                                InputAction::BRAKE});

        controller->assignAxisToActions(sf::Joystick::Axis::R, {InputAction::NIL,
                                                                InputAction::ACCELERATE});

        // Mappings are typical of an Xbox (360/One) controller
        // Button 0: A
        controller->assignButtonToAction(0, InputAction::FIRE);
        // Button 1: B
        // Button 2: X
        controller->assignButtonToAction(2, InputAction::ALTFIRE);
        // Button 3: Y
        controller->assignButtonToAction(3, InputAction::PANIC);
        // Button 4: LB
        controller->assignButtonToAction(4, InputAction::LEFT);
        // Button 5: RB
        controller->assignButtonToAction(5, InputAction::RIGHT);
        // Button 6: Back/Share/Menu/Select/etc
        // Button 7: Start
        controller->assignButtonToAction(7, InputAction::PAUSE);
        // Button 8: Unknown
        // Button 9: Left stick click
        // Button 10: Right stick click

        return controller;
    }
}; // namespace presets