#pragma once

/**
 * NIL is used as a null enum for things like joystick axis,
 * where maybe we only want one actual input on the axis
 */
enum InputAction {
  PAUSE, ACCELERATE, BRAKE, LEFT, RIGHT, FIRE, ALTFIRE, PANIC, NIL
};