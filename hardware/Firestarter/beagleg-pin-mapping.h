// -*- mode: c; c-basic-offset: 2; indent-tabs-mode: nil; -*-
// (c) 2015 H Hartley Sweeten <hsweeten@visionengravers.com>
//
// This file is part of BeagleG. http://github.com/hzeller/beagleg
//
// BeagleG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// BeagleG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with BeagleG.  If not, see <http://www.gnu.org/licenses/>.
//
// see motor-interface-constants.h for available PINs

// Hexastorm Firestarter V2 Generic GPIO mapping

#define MOTOR_3_STEP_GPIO  PIN_P8_16  // Z_STEP

#define MOTOR_1_DIR_GPIO   PIN_P9_42  // X_DIR
#define MOTOR_2_DIR_GPIO   PIN_P8_15  // Y_DIR
#define MOTOR_3_DIR_GPIO   PIN_P8_17  // Z_DIR

#define MOTOR_ENABLE_GPIO  PIN_P9_16  // ENA (output)
#define MOTOR_ENABLE_IS_ACTIVE_HIGH 1 // 1 if EN, 0 if ~EN

#define AUX_1_GPIO         PIN_P8_19  // OUT0 - GPIO
#define AUX_2_GPIO         PIN_P8_13  // OUT1 - GPIO

#define PWM_1_GPIO         AUX_1_GPIO // OUT0 - TIMER PWM
#define PWM_2_GPIO         AUX_2_GPIO // OUT1 - TIMER PWM

#define IN_1_GPIO          PIN_P9_15  // IN0 - X home (min)
#define IN_2_GPIO          PIN_P9_14  // IN1 - Y home (max)
#define IN_3_GPIO          PIN_P9_16  // IN2 - Z home (max)
